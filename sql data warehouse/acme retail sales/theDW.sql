REM Drop table
REM ============================================
REM ADD the DROP TABLES after the following 
REM   DROP statement 
REM ============================================
drop table dummy cascade constraint;
drop table Time_Dim cascade constraint;
drop table Sales_Dim cascade constraint;
drop table States_Fact cascade constraint;


REM ============================================
REM ADD the DROP SEQUENCE after the following
REM     DROP statement
REM ============================================
drop sequence Time_Dim_seq;
drop sequence Sales_Dim_seq;


REM   DO NOT CHANGE!!!!!
REM ============================================
CREATE TABLE DUMMY(DUMMY NUMBER);
INSERT INTO DUMMY VALUES (0);
REM ============================================


REM Create Tables
REM ============================================
REM ADD the CREATE TABLE STATEMENT for 
REM    all Dim and Fact Tables After Here!!!!
REM ============================================
CREATE TABLE Time_Dim(
 TimeNum          number(5) Constraint timeid_pk Primary Key, 
 Quarter          number(1),
 saledate         date
); 

CREATE TABLE Sales_Dim(
 SalesNum          number(5) Constraint salesdim_pk Primary Key, 
 SalesId           number(2),
 State             VarChar2(2)
); 

CREATE TABLE States_Fact(
 TimeNum           number(5),
 SalesNum          number(5),
 CONSTRAINT states_Fact_fk1 FOREIGN KEY (TimeNum) REFERENCES Time_Dim,
 CONSTRAINT states_Fact_fk2 FOREIGN KEY (SalesNum) REFERENCES Sales_Dim
); 



REM ============================================
REM Add the SEQUENCE Code after the 
REM   create sequence time_dim_seq!!!
REM ============================================
create sequence Time_Dim_seq;
create sequence Sales_Dim_seq;

REM ============================================
REM Add the Trigger Code for each Dim table 
REM   after this trigger. 
REM ============================================
CREATE OR REPLACE TRIGGER time_dim_trgA
    BEFORE INSERT ON time_dim
    FOR EACH ROW
  BEGIN

    SELECT time_dim_seq.nextval INTO :new.TimeNum FROM dummy;

  END;
/

CREATE OR REPLACE TRIGGER sales_Dim_trgA
    BEFORE INSERT ON Sales_Dim
    FOR EACH ROW
  BEGIN

    SELECT Sales_Dim_seq.nextval INTO :new.SalesNum FROM dummy;

  END;
/


REM ============================================
REM Add the Function Code for each Dim table
REM  after this function. 
REM ============================================
CREATE OR REPLACE FUNCTION GetTimeId (inDate IN date)

     Return Number

 IS

    Timeid_Num  Number(5);

BEGIN


   SELECT TimeNum INTO TimeId_Num
     From Time_Dim
     WHERE saledate = inDate;
     

   RETURN TimeId_Num; 

End;
/

CREATE OR REPLACE FUNCTION GetSalesId (inNo IN Number)

     Return Number

 IS

    DeptId_Num  Number(5);

BEGIN


   SELECT SalesNum INTO DeptId_Num
     From Sales_Dim
     WHERE SalesId = inNo;
     

   RETURN DeptId_Num; 

End;
/




REM INSERT . . . SELECT
REM ============================================
REM Add the INSERT . . . SELECT Code here. 
REM ============================================
INSERT INTO Time_Dim(Quarter, saledate) 
  SELECT Quarter, saledate
  from Sales;

INSERT INTO Sales_Dim(SalesId, State) 
  SELECT  saleId, state
  from Sales;

INSERT INTO States_Fact(TimeNum, SalesNum) 
  SELECT  GetTimeId(saledate), GetSalesId(saleId)
  from Sales
  Group by Quarter, saledate, saleId;




REM Formatting Statements
REM ============================================

REM ============================================

REM SELECT
REM ============================================
REM Add SELECT with ROLLUP from Data Warehouse 
REM ============================================

SELECT Quarter, state, count(state) as "Number of Orders"
   FROM Time_Dim t, Sales_Dim s, States_Fact st
   WHERE (t.TimeNum = st.TimeNum) AND (s.SalesNum = st.SalesNum) 
   GROUP BY ROLLUP (Quarter, state)
   Order by Quarter, State;



REM SELECT
REM ============================================
REM Add SELECT with DENSE_Rank  from Data Warehouse 
REM ============================================

SELECT Quarter, state, count(state) as "Number of Orders", DENSE_RANK() OVER (ORDER BY count(state) DESC) as "Ranking"
   FROM Time_Dim t, Sales_Dim s, States_Fact st
   WHERE (t.TimeNum = st.TimeNum) AND (s.SalesNum = st.SalesNum) 
   GROUP BY Quarter, state
   Order by Quarter, State;




