REM Drop Tables
drop table Category cascade constraint;
drop table Product cascade constraint;
drop table Sales cascade constraint;

REM Create Tables
CREATE TABLE Category(
 categoryId      number(5) Constraint categoryid_pk Primary Key, 
 caetgoryName    varchar2(40)
); 

CREATE TABLE Product(
 productId       number(5) Constraint productid_pk Primary Key, 
 name 			 varchar2(60),
 origin			 varchar2(20),
 weight			 decimal(6, 2),
 categoryId 	 number(5),
 CONSTRAINT product_category_fk1 FOREIGN KEY (categoryId) REFERENCES Category
);  

CREATE TABLE Sales(
 saleId          number(5) Constraint saleid_pk Primary Key,
 saledate		 date,
 quarter		 number(1),
 profit			 decimal(10, 2),
 state			 varchar2(2),
 productId 		 number(5),
 CONSTRAINT sales_product_fk1 FOREIGN KEY (productId) REFERENCES Product
); 


REM Load Tables
REM Insert Into Category
INSERT INTO Category VALUES (1, 'Outdoor');
INSERT INTO Category VALUES (2, 'Kitchen');
INSERT INTO Category VALUES (3, 'Arts/Crafts');
INSERT INTO Category VALUES (4, 'Pet Supplies');
INSERT INTO Category VALUES (5, 'Cups');
INSERT INTO Category VALUES (6, 'Electronics');


REM Insert Into Product
INSERT INTO Product VALUES (1, 'Hiking Pole', 'China', .02, 1);
INSERT INTO Product VALUES (2, 'Knife', 'USA', .01, 2);
INSERT INTO Product VALUES (3, 'Brush Set', 'Taiwan', .02, 3);
INSERT INTO Product VALUES (4, 'Cage', 'China', .5, 4);
INSERT INTO Product VALUES (5, 'Yeti', 'USA', .1, 5);
INSERT INTO Product VALUES (6, 'Iphone', 'China', .1, 6);


REM Insert Into Sales
INSERT INTO Sales VALUES (1, '1-JAN-2014', 1, 1000.00, 'SC', 1);
INSERT INTO Sales VALUES (2, '2-JAN-2014', 1, 9000.00, 'SC', 2);
INSERT INTO Sales VALUES (3, '3-MAY-2014', 2, 2999.00, 'DW', 3);
INSERT INTO Sales VALUES (4, '5-MAY-2014', 2, 1010.00, 'TX', 4);
INSERT INTO Sales VALUES (5, '6-MAY-2014', 3, 1000.11, 'TX', 5);
INSERT INTO Sales VALUES (6, '7-MAY-2014', 3, 2999.00, 'TX', 6);
INSERT INTO Sales VALUES (7, '1-NOV-2014', 4, 9990.00, 'SC', 6);
INSERT INTO Sales VALUES (8, '2-NOV-2014', 4, 9999.00, 'WY', 6);
INSERT INTO Sales VALUES (9, '3-NOV-2014', 4, 9990.00, 'SC', 6);
INSERT INTO Sales VALUES (10, '4-NOV-2014', 4, 9999.00, 'GA', 6);
INSERT INTO Sales VALUES (11, '5-NOV-2014', 4, 9990.00, 'SC', 6);
INSERT INTO Sales VALUES (12, '6-NOV-2014', 4, 9999.00, 'TX', 6);

REM Display Tables
SELECT * FROM Category;
SELECT * FROM Product;
SELECT * FROM Sales;
