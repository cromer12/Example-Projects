#ifndef _PROMPT_H
#define _PROMPT_H

/******************************************************************************/
/******************************************************************************/
/*                                                                            */
/*  prompt.h  ---  Prompt Utilities          Last Revised: February 13, 2001  */
/*                                                                            */
/*  Adapted by: John Welch  --- Southern Wesleyan University                  */
/*                                                                            */
/*  Based on utilities provided by Owen Astrachan in conjuntion with his book */
/*                                                                            */
/*                         Computer Science Tapestry                          */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
/*  This code is freely distributable and modifiable providing you leave this */
/*      notice in it.                                                         */
/******************************************************************************/
/******************************************************************************/
/*                                                                            */
/*           **********  The Purpose Of These Utilities. **********           */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*      The primary purpose of these routines is to facilitate the            */
/*      prompting for, and entry of, numbers and strings.                     */
/*                                                                            */
/*      Each of the major routines has three equivalents:                     */
/*                                                                            */
/*          PromptXXX     - This version gets the required input from the     */
/*                          user EXACTLY as if the extraction operator >>     */
/*                          had been used, whitespace delimited.              */
/*                                                                            */
/*          PromptlnXXX   - This version also gets the required input from    */
/*                          the user in a whitespace delimited manner, then   */
/*                          throws away the rest of the user's input up to    */
/*                          the '\n'.  This version was maintained for        */
/*                          compatibility reasons.  (See the History          */
/*                          section, below, for further explanation).         */
/*                                                                            */
/*          PromptLineXXX - This version gets any required input from the     */
/*                          the user and evaluates the entire "line" of       */
/*                          input up to the '\n' as to whether it meets       */
/*                          the requested format.  This helps to trap         */
/*                          errors such as "30 0" when "300" was meant.       */
/*                                                                            */
/*                          Unlike the other two forms, this version allows   */
/*                          the entry of whitespace only, or even just '\n',  */
/*                          for any routine of this form.  This version also  */
/*                          "flushes" whatever might have been in the input   */
/*                          buffer so that a new "line" of text is evaluated  */
/*                          each time it is called.                           */
/*                                                                            */
/*      In all three versions, leading and trailing whitespace is ignored     */
/*      during number evaluations, "30", "  30", and "30  " are equivalent.   */
/*                                                                            */
/*                                                                            */
/*      The major routines included here are:                                 */
/*                                                                            */
/*  PromptNum:  used for number entry.                                        */
/*                                                                            */
/*  Type PromptNum(const string & prompt, Type & value)                       */
/*                                                                            */
/*          generates prompt == prompt + ": "                                 */
/*                                                                            */
/*              -- returns a value of type Type                               */
/*                                                                            */
/*                  All internal number Types are supported.  Error           */
/*                  checking is done and the user is reprompted until         */
/*                  a number of the requested Type is provided.  This         */
/*                  routine forms the basis for all other number entry        */
/*                  routines and its features are inherited by them.          */
/*                                                                            */
/*          Examples:                                                         */
/*                                                                            */
/*              int age;                                                      */
/*              double area;                                                  */
/*              PromptNum("Enter your age",age);                              */
/*              if (3.14 < PromptNum("Enter the area of the circle",area))    */
/*              {                                                             */
/*                  DoStuff();                                                */
/*              }                                                             */
/*                                                                            */
/*  PromptRange: used for number entry.                                       */
/*                                                                            */
/*  Type PromptRange(const string &prompt, const Type &low, const Type &high) */
/*                                                                            */
/*          generates prompt == prompt +" between "+ low +" and "+ high +": " */
/*                                                                            */
/*              -- returns a number of type Type in range low..high inclusive */
/*                                                                            */
/*                  All internal number Types are supported, but both         */
/*                  'low' and 'high' must be the same Type, and that will     */
/*                  be the Type returned.  The user will be reprompted        */
/*                  until a number of that Type, in the range low - high,     */
/*                  inclusive, is entered.                                    */
/*                                                                            */
/*          Examples:                                                         */
/*                                                                            */
/*              unsigned short month;                                         */
/*              float value;                                                  */
/*              value = PromptRange("Enter value", -0.5, 1.5);                */
/*              month = PromptRange("Enter the number of this month", 1, 12); */
/*                                                                            */
/*  PromptString: used for text entry.                                        */
/*                                                                            */
/*  Type PromptString(const string & prompt)                                  */
/*                                                                            */
/*          generates prompt == prompt + ": "                                 */
/*                                                                            */
/*              -- returns a string                                           */
/*                                                                            */
/*                  Any input string from the user is accepted.               */
/*                                                                            */
/*          Example:                                                          */
/*                                                                            */
/*              string filename;                                              */
/*              filename = PromptString("Enter file name");                   */
/*                                                                            */
/*  PromptYesNo: used for a "yes" or "no" response.                           */
/*                                                                            */
/*  bool PromptYesNo(const string & prompt)                                   */
/*                                                                            */
/*          generates prompt == prompt + ": "                                 */
/*                                                                            */
/*              -- returns true iff the user enters "yes"                     */
/*                                                                            */
/*                  (or any string beginning with "y", either case.)          */
/*                  The user will be reprompted until a string beginning      */
/*                  with either 'y' or 'n' is entered.  Case does not         */
/*                  matter.                                                   */
/*                                                                            */
/*          Example:                                                          */
/*                                                                            */
/*              if (PromptYesNo("Do you want to continue?"))                  */
/*              {                                                             */
/*                  DoStuff();                                                */
/*              }                                                             */
/*              else                                                          */
/*              {                                                             */
/*                  return;                                                   */
/*              }                                                             */
/*                                                                            */
/******************************************************************************/
/******************************************************************************/
/*                                                                            */
/*           **********  The History Of These Utilities. **********           */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*      These utilities were reworked to be more complete, robust,            */
/*      symetrical, and provide some amount of error checking for number      */
/*      entry routines such as "PromptNum" and "PromptRange".  These          */
/*      utilities place no limitation of their own on parameters such as      */
/*      string length or number size.  Instead, any compiler or system        */
/*      level limits will be imposed and enforced and will be the             */
/*      controlling factor.  Also, to prevent entry rounding errors, only     */
/*      'PRECISION' number of significant digits will be passed thru the      */
/*      various string-to-number routines.  'PRECISION' is obtained by        */
/*      determining how many digits the system is able to uniquely resolve.   */
/*                                                                            */
/*          [See 'strutils' for the details of how this is implemented.]      */
/*                                                                            */
/*      Other enhancements that were added include the ability of some of     */
/*      these routines to handle the entry of empty or whitespace only        */
/*      lines, and reprompting the user for correct input if necessary.       */
/*      I attempted to make all of these routines compatible with the         */
/*      extraction operator >> to allow their interchangeable use with        */
/*      the same stream.  The operation of most existing routines was         */
/*      maintained for compatibility with any other routines that depended    */
/*      upon their original incarnation.                                      */
/*                                                                            */
/*      Also, I took advantage of a type of implicit overloading that         */
/*      Microsoft's Visual C++ 6.0 allows.  This compiler allows you to       */
/*      define a function such as:                                            */
/*                                                                            */
/*                          type1 function(type2 & input, type1 & value);     */
/*                                                                            */
/*      so that the same value is both RETURNed and passed back in 'value'.   */
/*      You are then able to call this funtion as if it was overloaded with:  */
/*                                                                            */
/*                          void function(type2 & input, type1 & value);      */
/*                                                                            */
/*      This allows you to utilize the function by either:                    */
/*                                                                            */
/*                          function(input, value);                           */
/*              or          value2 = function(input, value);                  */
/*                                                                            */
/*      Note that 'value' is required in both instances, but the choice of    */
/*      formats sometimes allows for cleaner code implementations.  If your   */
/*      compiler is different, you will need to choose which implementation   */
/*      best meets your needs and make the appropriate changes.  You will     */
/*      not be able to explicitly overload the functions in this way, since   */
/*      the two implementations would differ only in whether to return a      */
/*      value or not, and the compiler is not able to resolve that without    */
/*      additional information.                                               */
/*                                                                            */
/******************************************************************************/
/******************************************************************************/
/*                                                                            */
/*               ********** Pre-Processor Directives **********               */
/*                                                                            */
/******************************************************************************/

#include "strutils.h"                      /* String Utilities header.        */
#include <iostream>                        /* Std system input header.        */

/******************************************************************************/
/******************************************************************************/
/*                                                                            */
/**** These Functions / Procedures Functions Are Provided In This Program. ****/
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*string CinStr(string & str);             /* Get string using cin.           */
/*void WaitOnReturn();                     /* Prompt & wait for \n.           */
/*string AddGetLn(string & str);           /* Add input to str up to \n w/ cin*/
/*void EatLine();                          /* EatLn iff not at \n already.    */
/*string GetLine(string & str);            /* Get line of text using cin.     */
/*void Prompt(const string & str);         /* Output a string using cout.     */
/*void EntryPrompt(const string & prompt); /* Output prompt, space for entry. */
/*void TryAgain(const string & str);       /* Tell user to try again.         */
/*void MustPrompt(const string & str);     /* Tell user what they must enter. */
/*                                                                            */
/*bool GetNum(Type & value, bool & error); /* Get str w/ cin, conv to Type.   */
/*int GetInt(bool & error);                /* Get str w/ cin, convert to int. */
/*long GetLong(bool & error);              /* Get str w/ cin, convert to long.*/
/*double GetDouble(bool & error);          /* Get str w/ cin, convert to doubl*/
/*Type PromptNum(const string & prompt, Type & value);/*Prompt get Type-insist*/
/*Type PromptRange(const string &prompt, const Type & low, const Type & high);*/
/*string PromptString(const string & prompt);    /* Prompt, get string.       */
/*bool PromptYesNo(const string & prompt);       /* Prompt, get y/n - insist. */
/*                                                                            */
/*bool GetLineNum(Type & value, bool & error); /* Get str w/ cin, conv to Type*/
/*int GetLineInt(bool & error);            /* Get str w/ cin, convert to int. */
/*long GetLineLong(bool & error);          /* Get str w/ cin, convert to long.*/
/*double GetLineDouble(bool & error);      /* Get str w/ cin, convert to doubl*/
/*Type PromptLineNum(const string & prompt, Type & value);/*Prompt Type-insist*/
/*Type Pr..LineRange(const string &prompt, const Type &low, const Type &high);*/
/*string PromptLineString(const string & prompt);/* Prompt, get string.       */
/*bool PromptLineYesNo(const string & prompt);   /* Prompt, get y/n - insist. */
/*                                                                            */
/*bool GetlnNum(Type & value, bool & error);   /* Get str w/ cin, conv to Type*/
/*int GetlnInt(bool & error);              /* Get str w/ cin, convert to int. */
/*long GetlnLong(bool & error);            /* Get str w/ cin, convert to long.*/
/*double GetlnDouble(bool & error);        /* Get str w/ cin, convert to doubl*/
/*Type PromptlnNum(const string & prompt, Type & value);  /*Prompt Type-insist*/
/*Type Pr..lnRange(const string &prompt, const Type & low, const Type & high);*/
/*string PromptlnString(const string & prompt);  /* Prompt, get string.       */
/*bool PromptlnYesNo(const string & prompt);     /* Prompt, get y/n - insist. */
/*                                                                            */
/******************************************************************************/
/******************************************************************************/
/*                                                                            */
/****** These Basic Functions / Procedures Are Provided In This Program. ******/
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*int GetCin();                            /* Get next chr in cin stream.     */
/*int PeekCin();                           /* Look at next chr in cin stream. */
/*string CinStr(string & str);             /* Get string using cin.           */
/*void CoutStr(const string & str);        /* Output string w/ cout.          */
/*void WaitOnReturn();                     /* Prompt & wait for \n.           */
/*void SkipPendingNewline();               /* Remove "waiting" \n from stream.*/
/*void WaitForReturn();                    /* Wait for \n & remove from stream*/
/*string AddGetLn(string & str);           /* Add input to str up to \n w/ cin*/
/*string GetLn(string & str);              /* AddGetLn, but clear str first.  */
/*void EatLn();                            /* Trash cin stream up to next \n. */
/*void EatLine();                          /* EatLn iff not at \n already.    */
/*static void eatline();                   /* Trash line using system getline.*/
/*string GetLine(string & str);            /* Get line of text using cin.     */
/*string RangePrompt(const string &prompt, const Type &low, const Type &high);*/
/*void Prompt(const string & str);         /* Output a string using cout.     */
/*void EntryPrompt(const string & prompt); /* Output prompt, space for entry. */
/*void TryAgain(const string & str);       /* Tell user to try again.         */
/*void NumError(const string & str);       /* Numerical error msg.            */
/*void MustPrompt(const string & str);     /* Tell user what they must enter. */
/*void OutOfRange(const Type & low, const Type & high);      /* Type range err*/
/*void YesNoError();                                         /* Yes/no error. */
/*bool GetNum(Type & value);               /* Get str w/ cin, conv to Type.   */
/*bool GetNum(Type & value, bool & error); /* Get str w/ cin, conv to Type.   */
/*int GetInt(bool & error);                /* Get str w/ cin, convert to int. */
/*long GetLong(bool & error);              /* Get str w/ cin, convert to long.*/
/*double GetDouble(bool & error);          /* Get str w/ cin, convert to doubl*/
/*int GetInt();                            /* Get str w/ cin, convert to int. */
/*long GetLong();                          /* Get str w/ cin, convert to long.*/
/*double GetDouble();                      /* Get str w/ cin, convert to doubl*/
/*Type PromptNum(const string & prompt, Type & value);/*Prompt get Type-insist*/
/*Type PromptRange(const string &prompt, const Type & low, const Type & high);*/
/*string PromptString(const string & prompt);    /* Prompt, get string.       */
/*bool PromptYesNo(const string & prompt, string & response);/*Prompt, get y/n*/
/*bool PromptYesNo(const string & prompt);       /* Prompt, get y/n - insist. */
/*bool GetLineNum(Type & value);               /* Get str w/ cin, conv to Type*/
/*bool GetLineNum(Type & value, bool & error); /* Get str w/ cin, conv to Type*/
/*int GetLineInt(bool & error);            /* Get str w/ cin, convert to int. */
/*long GetLineLong(bool & error);          /* Get str w/ cin, convert to long.*/
/*double GetLineDouble(bool & error);      /* Get str w/ cin, convert to doubl*/
/*int GetLineInt();                        /* Get str w/ cin, convert to int. */
/*long GetLineLong();                      /* Get str w/ cin, convert to long.*/
/*double GetLineDouble();                  /* Get str w/ cin, convert to doubl*/
/*Type PromptLineNum(const string & prompt, Type & value);/*Prompt Type-insist*/
/*Type Pr..LineRange(const string &prompt, const Type &low, const Type &high);*/
/*string PromptLineString(const string & prompt);/* Prompt, get string.       */
/*bool PromptLineYesNo(const string & prompt, string & response);/*Prompt, y/n*/
/*bool PromptLineYesNo(const string & prompt);   /* Prompt, get y/n - insist. */
/*bool GetlnNum(Type & value);                 /* Get str w/ cin, conv to Type*/
/*bool GetlnNum(Type & value, bool & error);   /* Get str w/ cin, conv to Type*/
/*int GetlnInt(bool & error);              /* Get str w/ cin, convert to int. */
/*long GetlnLong(bool & error);            /* Get str w/ cin, convert to long.*/
/*double GetlnDouble(bool & error);        /* Get str w/ cin, convert to doubl*/
/*int GetlnInt();                          /* Get str w/ cin, convert to int. */
/*long GetlnLong();                        /* Get str w/ cin, convert to long.*/
/*double GetlnDouble();                    /* Get str w/ cin, convert to doubl*/
/*Type PromptlnNum(const string & prompt, Type & value);  /*Prompt Type-insist*/
/*Type Pr..lnRange(const string &prompt, const Type & low, const Type & high);*/
/*string PromptlnString(const string & prompt);  /* Prompt, get string.       */
/*bool PromptlnYesNo(const string & prompt, string &response);/*Prompt,get y/n*/
/*bool PromptlnYesNo(const string & prompt);     /* Prompt, get y/n - insist. */
/*                                                                            */
/******************************************************************************/
/******************************************************************************/
/*                                                                            */
/***  These Equivalent Functions / Procedures Are Provided In This Program. ***/
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*int GetCin();                            /* Get next chr in cin stream.     */
/*int PeekCin();                           /* Look at next chr in cin stream. */
/*string CinStr(string & str);             /* Get string using cin.           */
/*void CinStr(string & str);               /* Get string using cin.           */
/*void CoutStr(const string & str);        /* Output string w/ cout.          */
/*void WaitOnReturn();                     /* Prompt & wait for \n.           */
/*void SkipPendingNewline();               /* Remove "waiting" \n from stream.*/
/*void WaitForReturn();                    /* Wait for \n & remove from stream*/
/*string AddGetLn(string & str);           /* Add input to str up to \n w/ cin*/
/*void AddGetLn(string & str);             /* Add input to str up to \n w/ cin*/
/*string GetLn(string & str);              /* AddGetLn, but clear str first.  */
/*void GetLn(string & str);                /* AddGetLn, but clear str first.  */
/*void EatLn();                            /* Trash cin stream up to next \n. */
/*void EatLine();                          /* EatLn iff not at \n already.    */
/*static void eatline();                   /* Trash line using system getline.*/
/*string GetLine(string & str);            /* Get line of text using cin.     */
/*void GetLine(string & str);              /* Get line of text using cin.     */
/*string RangePrompt(string &prompt, long double &low, long double &high);    */
/*string RangePrompt(string &prompt, double &low, double &high);              */
/*string RangePrompt(string &prompt, float &low, float &high);                */
/*string RangePrompt(string &prompt, long &low, long &high);                  */
/*string RangePrompt(string &prompt, int &low, int &high);                    */
/*string RangePrompt(string &prompt, short &low, short &high);                */
/*string RangePrompt(string &prompt, char &low, char &high);                  */
/*string RangePrompt(string &prompt, unsigned long &low, unsigned long &high);*/
/*string RangePrompt(string &prompt, unsigned int &low, unsigned int &high);  */
/*string RangePr..(string &prompt, unsigned short &low, unsigned short &high);*/
/*string RangePrompt(string &prompt, unsigned char &low, unsigned char &high);*/
/*string RangePrompt(string &prompt, signed char &low, signed char &high);    */
/*string RangePrompt(string &prompt, bool &low, bool &high);                  */
/*void Prompt(const string & str);         /* Output a string using cout.     */
/*void EntryPrompt(const string & prompt); /* Output prompt, space for entry. */
/*void TryAgain(const string & str);       /* Tell user to try again.         */
/*void NumError(const string & str);       /* Numerical error msg.            */
/*void MustPrompt(const string & str);     /* Tell user what they must enter. */
/*void OutOfRange(const long double & low, const long double & high);  /* Err.*/
/*void OutOfRange(const double & low, const double & high);      /* Range err.*/
/*void OutOfRange(const float & low, const float & high);        /* Range err.*/
/*void OutOfRange(const long & low, const long & high);          /* Range err.*/
/*void OutOfRange(const int & low, const int & high);            /* Range err.*/
/*void OutOfRange(const short & low, const short & high);        /* Range err.*/
/*void OutOfRange(const char & low, const char & high);          /* Range err.*/
/*void OutOfRange(const unsigned long & low, const unsigned long & high);     */
/*void OutOfRange(const unsigned int & low, const unsigned int & high);       */
/*void OutOfRange(const unsigned short & low, const unsigned short & high);   */
/*void OutOfRange(const unsigned char & low, const unsigned char & high);     */
/*void OutOfRange(const signed char & low, const signed char & high);         */
/*void OutOfRange(const bool & low, const bool & high);          /* Range err.*/
/*void YesNoError();                                         /* Yes/no error. */
/*bool GetNum(long double & value);        /* Get str, conv to long double.   */
/*bool GetNum(double & value);             /* Get str w/ cin, conv to double. */
/*bool GetNum(float & value);              /* Get str w/ cin, conv to float   */
/*bool GetNum(long & value);               /* Get str w/ cin, conv to long.   */
/*bool GetNum(int & value);                /* Get str w/ cin, conv to int.    */
/*bool GetNum(short & value);              /* Get str w/ cin, conv to short.  */
/*bool GetNum(char & value);               /* Get str w/ cin, conv to char.   */
/*bool GetNum(unsigned long & value);      /* Get str, conv to unsigned long. */
/*bool GetNum(unsigned int & value);       /* Get str, conv to unsigned int.  */
/*bool GetNum(unsigned short & value);     /* Get str, conv to unsigned short.*/
/*bool GetNum(unsigned char & value);      /* Get str, conv to unsigned char. */
/*bool GetNum(signed char & value);        /* Get str, conv to signed char.   */
/*bool GetNum(bool & value);               /* Get str w/ cin, conv to bool.   */
/*bool GetNum(long double & value, bool & error);   /* Get long double.       */
/*bool GetNum(double & value, bool & error);        /* Get double.            */
/*bool GetNum(float & value, bool & error);         /* Get float              */
/*bool GetNum(long & value, bool & error);          /* Get long.              */
/*bool GetNum(int & value, bool & error);           /* Get int.               */
/*bool GetNum(short & value, bool & error);         /* Get short.             */
/*bool GetNum(char & value, bool & error);          /* Get char.              */
/*bool GetNum(unsigned long & value, bool & error); /* Get long.              */
/*bool GetNum(unsigned int & value, bool & error);  /* Get int.               */
/*bool GetNum(unsigned short & value, bool & error);/* Get short.             */
/*bool GetNum(unsigned char & value, bool & error); /* Get char.              */
/*bool GetNum(signed char & value, bool & error);   /* Get char.              */
/*bool GetNum(bool & value, bool & error);          /* Get bool.              */
/*int GetInt(bool & error);                /* Get str w/ cin, convert to int. */
/*long GetLong(bool & error);              /* Get str w/ cin, convert to long.*/
/*double GetDouble(bool & error);          /* Get str w/ cin, convert to doubl*/
/*int GetInt();                            /* Get str w/ cin, convert to int. */
/*long GetLong();                          /* Get str w/ cin, convert to long.*/
/*double GetDouble();                      /* Get str w/ cin, convert to doubl*/
/*long double PromptNum(const string & prompt, long double & value);          */
/*double PromptNum(const string & prompt, double & value);                    */
/*float PromptNum(const string & prompt, float & value);                      */
/*long PromptNum(const string & prompt, long & value);                        */
/*int PromptNum(const string & prompt, int & value);                          */
/*short PromptNum(const string & prompt, short & value);                      */
/*char PromptNum(const string & prompt, char & value);                        */
/*unsigned long PromptNum(const string & prompt, unsigned long & value);      */
/*unsigned int PromptNum(const string & prompt, unsigned int & value);        */
/*unsigned short PromptNum(const string & prompt, unsigned short & value);    */
/*unsigned char PromptNum(const string & prompt, unsigned char & value);      */
/*signed char PromptNum(const string & prompt, signed char & value);          */
/*bool PromptNum(const string & prompt, bool & value);                        */
/*void PromptNum(const string & prompt, long double & value);                 */
/*void PromptNum(const string & prompt, double & value);                      */
/*void PromptNum(const string & prompt, float & value);                       */
/*void PromptNum(const string & prompt, long & value);                        */
/*void PromptNum(const string & prompt, int & value);                         */
/*void PromptNum(const string & prompt, short & value);                       */
/*void PromptNum(const string & prompt, char & value);                        */
/*void PromptNum(const string & prompt, unsigned long & value);               */
/*void PromptNum(const string & prompt, unsigned int & value);                */
/*void PromptNum(const string & prompt, unsigned short & value);              */
/*void PromptNum(const string & prompt, unsigned char & value);               */
/*void PromptNum(const string & prompt, signed char & value);                 */
/*void PromptNum(const string & prompt, bool & value);                        */
/*long double Pro..Range(string &prompt, long double &low, long double &high);*/
/*double PromptRange(string &prompt, double &low, double &high);              */
/*float PromptRange(string &prompt, float &low, float &high);                 */
/*long PromptRange(string &prompt, long &low, long &high);                    */
/*int PromptRange(string &prompt, int &low, int &high);                       */
/*short PromptRange(string &prompt, short &low, short &high);                 */
/*char PromptRange(string &prompt, char &low, char &high);                    */
/*unsigned long Pro...(st.. &prompt, unsigned long &low, unsigned long &high);*/
/*unsigned int Prompt...(st.. &prompt, unsigned int &low, unsigned int &high);*/
/*unsigned short P..(st.. &prompt, unsigned short &low, unsigned short &high);*/
/*unsigned char Pro...(st.. &prompt, unsigned char &low, unsigned char &high);*/
/*signed char PromptRange(str.. &prompt, signed char &low, signed char &high);*/
/*bool PromptRange(string &prompt, bool &low, bool &high);                    */
/*string PromptString(const string & prompt);    /* Prompt, get string.       */
/*bool PromptYesNo(const string & prompt, string & response);/*Prompt, get y/n*/
/*bool PromptYesNo(const string & prompt);       /* Prompt, get y/n - insist. */
/*bool GetLineNum(long double & value);    /* Get str, conv to long double.   */
/*bool GetLineNum(double & value);         /* Get str w/ cin, conv to double. */
/*bool GetLineNum(float & value);          /* Get str w/ cin, conv to float   */
/*bool GetLineNum(long & value);           /* Get str w/ cin, conv to long.   */
/*bool GetLineNum(int & value);            /* Get str w/ cin, conv to int.    */
/*bool GetLineNum(short & value);          /* Get str w/ cin, conv to short.  */
/*bool GetLineNum(char & value);           /* Get str w/ cin, conv to char.   */
/*bool GetLineNum(unsigned long & value);  /* Get str, conv to unsigned long. */
/*bool GetLineNum(unsigned int & value);   /* Get str, conv to unsigned int.  */
/*bool GetLineNum(unsigned short & value); /* Get str, conv to unsigned short.*/
/*bool GetLineNum(unsigned char & value);  /* Get str, conv to unsigned char. */
/*bool GetLineNum(signed char & value);    /* Get str, conv to signed char.   */
/*bool GetLineNum(bool & value);           /* Get str w/ cin, conv to bool.   */
/*bool GetLineNum(long double & value, bool & error);   /* Get long double.   */
/*bool GetLineNum(double & value, bool & error);        /* Get double.        */
/*bool GetLineNum(float & value, bool & error);         /* Get float          */
/*bool GetLineNum(long & value, bool & error);          /* Get long.          */
/*bool GetLineNum(int & value, bool & error);           /* Get int.           */
/*bool GetLineNum(short & value, bool & error);         /* Get short.         */
/*bool GetLineNum(char & value, bool & error);          /* Get char.          */
/*bool GetLineNum(unsigned long & value, bool & error); /* Get long.          */
/*bool GetLineNum(unsigned int & value, bool & error);  /* Get int.           */
/*bool GetLineNum(unsigned short & value, bool & error);/* Get short.         */
/*bool GetLineNum(unsigned char & value, bool & error); /* Get char.          */
/*bool GetLineNum(signed char & value, bool & error);   /* Get char.          */
/*bool GetLineNum(bool & value, bool & error);          /* Get bool.          */
/*int GetLineInt(bool & error);            /* Get str w/ cin, convert to int. */
/*long GetLineLong(bool & error);          /* Get str w/ cin, convert to long.*/
/*double GetLineDouble(bool & error);      /* Get str w/ cin, convert to doubl*/
/*int GetLineInt();                        /* Get str w/ cin, convert to int. */
/*long GetLineLong();                      /* Get str w/ cin, convert to long.*/
/*double GetLineDouble();                  /* Get str w/ cin, convert to doubl*/
/*long double PromptLineNum(const string & prompt, long double & value);      */
/*double PromptLineNum(const string & prompt, double & value);                */
/*float PromptLineNum(const string & prompt, float & value);                  */
/*long PromptLineNum(const string & prompt, long & value);                    */
/*int PromptLineNum(const string & prompt, int & value);                      */
/*short PromptLineNum(const string & prompt, short & value);                  */
/*char PromptLineNum(const string & prompt, char & value);                    */
/*unsigned long PromptLineNum(const string & prompt, unsigned long & value);  */
/*unsigned int PromptLineNum(const string & prompt, unsigned int & value);    */
/*unsigned short PromptLineNum(const string & prompt, unsigned short & value);*/
/*unsigned char PromptLineNum(const string & prompt, unsigned char & value);  */
/*signed char PromptLineNum(const string & prompt, signed char & value);      */
/*bool PromptLineNum(const string & prompt, bool & value);                    */
/*void PromptLineNum(const string & prompt, long double & value);             */
/*void PromptLineNum(const string & prompt, double & value);                  */
/*void PromptLineNum(const string & prompt, float & value);                   */
/*void PromptLineNum(const string & prompt, long & value);                    */
/*void PromptLineNum(const string & prompt, int & value);                     */
/*void PromptLineNum(const string & prompt, short & value);                   */
/*void PromptLineNum(const string & prompt, char & value);                    */
/*void PromptLineNum(const string & prompt, unsigned long & value);           */
/*void PromptLineNum(const string & prompt, unsigned int & value);            */
/*void PromptLineNum(const string & prompt, unsigned short & value);          */
/*void PromptLineNum(const string & prompt, unsigned char & value);           */
/*void PromptLineNum(const string & prompt, signed char & value);             */
/*void PromptLineNum(const string & prompt, bool & value);                    */
/*long double P..LineRange(st.. &prompt, long double &low, long double &high);*/
/*double PromptLineRange(string &prompt, double &low, double &high);          */
/*float PromptLineRange(string &prompt, float &low, float &high);             */
/*long PromptLineRange(string &prompt, long &low, long &high);                */
/*int PromptLineRange(string &prompt, int &low, int &high);                   */
/*short PromptLineRange(string &prompt, short &low, short &high);             */
/*char PromptLineRange(string &prompt, char &low, char &high);                */
/*unsigned long Pro...(st.. &prompt, unsigned long &low, unsigned long &high);*/
/*unsigned int Prompt...(st.. &prompt, unsigned int &low, unsigned int &high);*/
/*unsigned short P..(st.. &prompt, unsigned short &low, unsigned short &high);*/
/*unsigned char Pro...(st.. &prompt, unsigned char &low, unsigned char &high);*/
/*signed char P..LineRange(st.. &prompt, signed char &low, signed char &high);*/
/*bool PromptLineRange(string &prompt, bool &low, bool &high);                */
/*string PromptLineString(const string & prompt);/* Prompt, get string.       */
/*bool PromptLineYesNo(const string & prompt, string & response);/*Prompt, y/n*/
/*bool PromptLineYesNo(const string & prompt);   /* Prompt, get y/n - insist. */
/*bool GetlnNum(long double & value);      /* Get str, conv to long double.   */
/*bool GetlnNum(double & value);           /* Get str w/ cin, conv to double. */
/*bool GetlnNum(float & value);            /* Get str w/ cin, conv to float   */
/*bool GetlnNum(long & value);             /* Get str w/ cin, conv to long.   */
/*bool GetlnNum(int & value);              /* Get str w/ cin, conv to int.    */
/*bool GetlnNum(short & value);            /* Get str w/ cin, conv to short.  */
/*bool GetlnNum(char & value);             /* Get str w/ cin, conv to char.   */
/*bool GetlnNum(unsigned long & value);    /* Get str, conv to unsigned long. */
/*bool GetlnNum(unsigned int & value);     /* Get str, conv to unsigned int.  */
/*bool GetlnNum(unsigned short & value);   /* Get str, conv to unsigned short.*/
/*bool GetlnNum(unsigned char & value);    /* Get str, conv to unsigned char. */
/*bool GetlnNum(signed char & value);      /* Get str, conv to signed char.   */
/*bool GetlnNum(bool & value);             /* Get str w/ cin, conv to bool.   */
/*bool GetlnNum(long double & value, bool & error);   /* Get long double.     */
/*bool GetlnNum(double & value, bool & error);        /* Get double.          */
/*bool GetlnNum(float & value, bool & error);         /* Get float            */
/*bool GetlnNum(long & value, bool & error);          /* Get long.            */
/*bool GetlnNum(int & value, bool & error);           /* Get int.             */
/*bool GetlnNum(short & value, bool & error);         /* Get short.           */
/*bool GetlnNum(char & value, bool & error);          /* Get char.            */
/*bool GetlnNum(unsigned long & value, bool & error); /* Get long.            */
/*bool GetlnNum(unsigned int & value, bool & error);  /* Get int.             */
/*bool GetlnNum(unsigned short & value, bool & error);/* Get short.           */
/*bool GetlnNum(unsigned char & value, bool & error); /* Get char.            */
/*bool GetlnNum(signed char & value, bool & error);   /* Get char.            */
/*bool GetlnNum(bool & value, bool & error);          /* Get bool.            */
/*int GetlnInt(bool & error);              /* Get str w/ cin, convert to int. */
/*long GetlnLong(bool & error);            /* Get str w/ cin, convert to long.*/
/*double GetlnDouble(bool & error);        /* Get str w/ cin, convert to doubl*/
/*int GetlnInt();                          /* Get str w/ cin, convert to int. */
/*long GetlnLong();                        /* Get str w/ cin, convert to long.*/
/*double GetlnDouble();                    /* Get str w/ cin, convert to doubl*/
/*long double PromptlnNum(const string & prompt, long double & value);        */
/*double PromptlnNum(const string & prompt, double & value);                  */
/*float PromptlnNum(const string & prompt, float & value);                    */
/*long PromptlnNum(const string & prompt, long & value);                      */
/*int PromptlnNum(const string & prompt, int & value);                        */
/*short PromptlnNum(const string & prompt, short & value);                    */
/*char PromptlnNum(const string & prompt, char & value);                      */
/*unsigned long PromptlnNum(const string & prompt, unsigned long & value);    */
/*unsigned int PromptlnNum(const string & prompt, unsigned int & value);      */
/*unsigned short PromptlnNum(const string & prompt, unsigned short & value);  */
/*unsigned char PromptlnNum(const string & prompt, unsigned char & value);    */
/*signed char PromptlnNum(const string & prompt, signed char & value);        */
/*bool PromptlnNum(const string & prompt, bool & value);                      */
/*void PromptlnNum(const string & prompt, long double & value);               */
/*void PromptlnNum(const string & prompt, double & value);                    */
/*void PromptlnNum(const string & prompt, float & value);                     */
/*void PromptlnNum(const string & prompt, long & value);                      */
/*void PromptlnNum(const string & prompt, int & value);                       */
/*void PromptlnNum(const string & prompt, short & value);                     */
/*void PromptlnNum(const string & prompt, char & value);                      */
/*void PromptlnNum(const string & prompt, unsigned long & value);             */
/*void PromptlnNum(const string & prompt, unsigned int & value);              */
/*void PromptlnNum(const string & prompt, unsigned short & value);            */
/*void PromptlnNum(const string & prompt, unsigned char & value);             */
/*void PromptlnNum(const string & prompt, signed char & value);               */
/*void PromptlnNum(const string & prompt, bool & value);                      */
/*long double Pr...lnRange(st.. &prompt, long double &low, long double &high);*/
/*double PromptlnRange(string &prompt, double &low, double &high);            */
/*float PromptlnRange(string &prompt, float &low, float &high);               */
/*long PromptlnRange(string &prompt, long &low, long &high);                  */
/*int PromptlnRange(string &prompt, int &low, int &high);                     */
/*short PromptlnRange(string &prompt, short &low, short &high);               */
/*char PromptlnRange(string &prompt, char &low, char &high);                  */
/*unsigned long Pro...(st.. &prompt, unsigned long &low, unsigned long &high);*/
/*unsigned int Prompt...(st.. &prompt, unsigned int &low, unsigned int &high);*/
/*unsigned short P..(st.. &prompt, unsigned short &low, unsigned short &high);*/
/*unsigned char Pro...(st.. &prompt, unsigned char &low, unsigned char &high);*/
/*signed char Pr...lnRange(st.. &prompt, signed char &low, signed char &high);*/
/*bool PromptlnRange(string &prompt, bool &low, bool &high);                  */
/*string PromptlnString(const string & prompt);  /* Prompt, get string.       */
/*bool PromptlnYesNo(const string & prompt, string &response);/*Prompt,get y/n*/
/*bool PromptlnYesNo(const string & prompt);     /* Prompt, get y/n - insist. */
/*                                                                            */
/******************************************************************************/
/******************************************************************************/
/*                                                                            */
/******** Make Sure All Functions and Procedures Have Been Prototyped. ********/
/*                                                                            */
/******************************************************************************/
/******************************************************************************/

int GetCin();                              /* Get next chr in cin stream.     */

    /*  Purpose:        */

    /*  Precondition:   */

    /*  Postcondition:  */

/******************************************************************************/

int PeekCin();                             /* Look at next chr in cin stream. */

    /*  Purpose:        */

    /*  Precondition:   */

    /*  Postcondition:  */

/******************************************************************************/

string CinStr(string & str);               /* Get string using cin.           */

    /*  Purpose:        */

    /*  Precondition:   */

    /*  Postcondition:  */

                          /**************************/
/* Equivalent to:                                                             */
/*                                                                            */
/*string CinStr(string & str);             /* Get string using cin.           */
/*void CinStr(string & str);               /* Get string using cin.           */

/******************************************************************************/

void CoutStr(const string & str);          /* Output string w/ cout.          */

    /*  Purpose:        */

    /*  Precondition:   */

    /*  Postcondition:  */

/******************************************************************************/

void WaitOnReturn();                       /* Prompt & wait for \n.           */

    /*  Purpose:        */

    /*  Precondition:   */

    /*  Postcondition:  */

/******************************************************************************/
/******************************************************************************/

#ifndef _UTILS_H
#define _UTILS_H

void SkipPendingNewline();                 /* Remove "waiting" \n from stream.*/

    /*  Purpose:        */

    /*  Precondition:   */

    /*  Postcondition:  */

/******************************************************************************/

void WaitForReturn();                      /* Wait for \n & remove from stream*/

    /*  Purpose:        */

    /*  Precondition:   */

    /*  Postcondition:  */

#endif

/******************************************************************************/
/******************************************************************************/

string AddGetLn(string & str);             /* Add input to str up to \n w/ cin*/

    /*  Purpose:        */

    /*  Precondition:   */

    /*  Postcondition:  */

                          /**************************/
/* Equivalent to:                                                             */
/*                                                                            */
/*string AddGetLn(string & str);           /* Add input to str up to \n w/ cin*/
/*void AddGetLn(string & str);             /* Add input to str up to \n w/ cin*/

/******************************************************************************/

string GetLn(string & str);                /* AddGetLn, but clear str first.  */

    /*  Purpose:        */

    /*  Precondition:   */

    /*  Postcondition:  */

                          /**************************/
/* Equivalent to:                                                             */
/*                                                                            */
/*string GetLn(string & str);              /* AddGetLn, but clear str first.  */
/*void GetLn(string & str);                /* AddGetLn, but clear str first.  */

/******************************************************************************/

void EatLn();                              /* Trash cin stream up to next \n. */

    /*  Purpose:        */

    /*  Precondition:   */

    /*  Postcondition:  */

/******************************************************************************/

void EatLine();                            /* EatLn iff not at \n already.    */

    /*  Purpose:        */

    /*  Precondition:   */

    /*  Postcondition:  */

/******************************************************************************/

static void eatline();                     /* Trash line using system getline.*/

    /*  Purpose:        */

    /*  Precondition:   */

    /*  Postcondition:  */

/******************************************************************************/

string GetLine(string & str);              /* Get line of text using cin.     */

    /*  Purpose:        */

    /*  Precondition:   */

    /*  Postcondition:  */

                          /**************************/
/* Equivalent to:                                                             */
/*                                                                            */
/*string GetLine(string & str);            /* Get line of text using cin.     */
/*void GetLine(string & str);              /* Get line of text using cin.     */

/******************************************************************************/
/******************************************************************************/

void Prompt(const string & str);           /* Output a string using cout.     */

    /*  Purpose:        */

    /*  Precondition:   */

    /*  Postcondition:  */

/******************************************************************************/

void EntryPrompt(const string & prompt);   /* Output prompt, space for entry. */

    /*  Purpose:        */

    /*  Precondition:   */

    /*  Postcondition:  */

/******************************************************************************/

void TryAgain(const string & str);         /* Tell user to try again.         */

    /*  Purpose:        */

    /*  Precondition:   */

    /*  Postcondition:  */

/******************************************************************************/

void NumError(const string & str);         /* Numerical error msg.            */

    /*  Purpose:        */

    /*  Precondition:   */

    /*  Postcondition:  */

/******************************************************************************/

void MustPrompt(const string & str);       /* Tell user what they must enter. */

    /*  Purpose:        */

    /*  Precondition:   */

    /*  Postcondition:  */

/******************************************************************************/

void YesNoError();                                           /* Yes/no error. */

    /*  Purpose:        */

    /*  Precondition:   */

    /*  Postcondition:  */

/******************************************************************************/
/******************************************************************************/

int GetInt(bool & error);                  /* Get str w/ cin, convert to int. */

    /*  Purpose:        */

    /*  Precondition:   */

    /*  Postcondition:  */

/******************************************************************************/

long GetLong(bool & error);                /* Get str w/ cin, convert to long.*/

    /*  Purpose:        */

    /*  Precondition:   */

    /*  Postcondition:  */

/******************************************************************************/

double GetDouble(bool & error);            /* Get str w/ cin, convert to doubl*/

    /*  Purpose:        */

    /*  Precondition:   */

    /*  Postcondition:  */

/******************************************************************************/

int GetInt();                              /* Get str w/ cin, convert to int. */

    /*  Purpose:        */

    /*  Precondition:   */

    /*  Postcondition:  */

/******************************************************************************/

long GetLong();                            /* Get str w/ cin, convert to long.*/

    /*  Purpose:        */

    /*  Precondition:   */

    /*  Postcondition:  */

/******************************************************************************/

double GetDouble();                        /* Get str w/ cin, convert to doubl*/

    /*  Purpose:        */

    /*  Precondition:   */

    /*  Postcondition:  */

/******************************************************************************/

string PromptString(const string & prompt);      /* Prompt, get string.       */
// postcondition: returns string entered by user

    /*  Purpose:        */

    /*  Precondition:   */

    /*  Postcondition:  */

/******************************************************************************/

bool PromptYesNo(const string & prompt, string & response); /* Prompt, get y/n*/
// postcondition: returns true iff user enters yes    

    /*  Purpose:        */

    /*  Precondition:   */

    /*  Postcondition:  */

/******************************************************************************/

bool PromptYesNo(const string & prompt);         /* Prompt, get y/n - insist. */
// postcondition: returns true iff user enters yes    

    /*  Purpose:        */

    /*  Precondition:   */

    /*  Postcondition:  */

/******************************************************************************/
/******************************************************************************/

int GetLineInt(bool & error);              /* Get str w/ cin, convert to int. */

    /*  Purpose:        */

    /*  Precondition:   */

    /*  Postcondition:  */

/******************************************************************************/

long GetLineLong(bool & error);            /* Get str w/ cin, convert to long.*/

    /*  Purpose:        */

    /*  Precondition:   */

    /*  Postcondition:  */

/******************************************************************************/

double GetLineDouble(bool & error);        /* Get str w/ cin, convert to doubl*/

    /*  Purpose:        */

    /*  Precondition:   */

    /*  Postcondition:  */

/******************************************************************************/

int GetLineInt();                          /* Get str w/ cin, convert to int. */

    /*  Purpose:        */

    /*  Precondition:   */

    /*  Postcondition:  */

/******************************************************************************/

long GetLineLong();                        /* Get str w/ cin, convert to long.*/

    /*  Purpose:        */

    /*  Precondition:   */

    /*  Postcondition:  */

/******************************************************************************/

double GetLineDouble();                    /* Get str w/ cin, convert to doubl*/

    /*  Purpose:        */

    /*  Precondition:   */

    /*  Postcondition:  */

/******************************************************************************/

string PromptLineString(const string & prompt);  /* Prompt, get string.       */
// postcondition: returns string entered by user

    /*  Purpose:        */

    /*  Precondition:   */

    /*  Postcondition:  */

/******************************************************************************/

bool PromptLineYesNo(const string & prompt, string & response);/* Prompt, y/n */
// postcondition: returns true iff user enters yes    

    /*  Purpose:        */

    /*  Precondition:   */

    /*  Postcondition:  */

/******************************************************************************/

bool PromptLineYesNo(const string & prompt);     /* Prompt, get y/n - insist. */
// postcondition: returns true iff user enters yes    

    /*  Purpose:        */

    /*  Precondition:   */

    /*  Postcondition:  */

/******************************************************************************/
/******************************************************************************/

int GetlnInt(bool & error);                /* Get str w/ cin, convert to int. */

    /*  Purpose:        */

    /*  Precondition:   */

    /*  Postcondition:  */

/******************************************************************************/

long GetlnLong(bool & error);              /* Get str w/ cin, convert to long.*/

    /*  Purpose:        */

    /*  Precondition:   */

    /*  Postcondition:  */

/******************************************************************************/

double GetlnDouble(bool & error);          /* Get str w/ cin, convert to doubl*/

    /*  Purpose:        */

    /*  Precondition:   */

    /*  Postcondition:  */

/******************************************************************************/

int GetlnInt();                            /* Get str w/ cin, convert to int. */

    /*  Purpose:        */

    /*  Precondition:   */

    /*  Postcondition:  */

/******************************************************************************/

long GetlnLong();                          /* Get str w/ cin, convert to long.*/

    /*  Purpose:        */

    /*  Precondition:   */

    /*  Postcondition:  */

/******************************************************************************/

double GetlnDouble();                      /* Get str w/ cin, convert to doubl*/

    /*  Purpose:        */

    /*  Precondition:   */

    /*  Postcondition:  */

/******************************************************************************/

string PromptlnString(const string & prompt);    /* Prompt, get string.       */
// postcondition: returns string entered by user

    /*  Purpose:        */

    /*  Precondition:   */

    /*  Postcondition:  */

/******************************************************************************/

bool PromptlnYesNo(const string & prompt, string &response);/* Prompt, get y/n*/
// postcondition: returns true iff user enters yes    

    /*  Purpose:        */

    /*  Precondition:   */

    /*  Postcondition:  */

/******************************************************************************/

bool PromptlnYesNo(const string & prompt);       /* Prompt, get y/n - insist. */
// postcondition: returns true iff user enters yes    

    /*  Purpose:        */

    /*  Precondition:   */

    /*  Postcondition:  */

/******************************************************************************/
/******************************************************************************/

#include "prompttemplate.h"
#include "prompt.cpp"
#endif