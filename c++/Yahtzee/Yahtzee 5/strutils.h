#ifndef _STRUTILS_H
#define _STRUTILS_H

/******************************************************************************/
/******************************************************************************/
/*                                                                            */
/*  strutils.h  ---  String Utilities        Last Revised: February 13, 2001  */
/*                                                                            */
/*  Adapted by: John Welch  --- Southern Wesleyan University                  */
/*                                                                            */
/*  Based on utilities provided by Owen Astrachan in conjuntion with his book */
/*                                                                            */
/*                         Computer Science Tapestry                          */
/*                                                                            */
/*                                                                            */
/*  PLEASE NOTE: strutils is in three parts due to the use of templates:      */
/*                                                                            */
/*              strutils.h -- the header file                                 */
/*              strutilstemplate.cpp -- the code for the templated functions  */
/*              strutils.cpp -- the rest of the code                          */
/*                                                                            */
/*      Including strutils.h in your program will also include                */
/*      strutilstemplates.cpp -- make sure it's available.                    */
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
/*      manipulation of strings.                                              */
/*                                                                            */
/*      The major routines included here are:                                 */
/*                                                                            */
/*  ToLower:  used to convert a string to all lowercase.                      */
/*                                                                            */
/*  string ToLower(string & str)                                              */
/*                                                                            */
/*      Precondition:   str is a valid string                                 */
/*      Postcondition:  str is changed to all lowercase.  The new             */
/*                      string is returned AND replaces the original.         */
/*                      Only uppercase letters are changed.                   */
/*                                                                            */
/*      Examples:                                                             */
/*                                                                            */
/*          string str1 = "Yes";                                              */
/*          string str2 = "No";                                               */
/*          ToLower(str1);                                                    */
/*          if("yes" == str1)                                                 */
/*          {                                                                 */
/*              DoStuff();                                                    */
/*          }                                                                 */
/*          if("no" == ToLower(str2))                                         */
/*          {                                                                 */
/*              DoStuff();                                                    */
/*          }                                                                 */
/*                                                                            */
/*  ToUpper:  used to convert a string to all uppercase.                      */
/*                                                                            */
/*  string ToLower(string & str)                                              */
/*                                                                            */
/*      Precondition:   str is a valid string                                 */
/*      Postcondition:  str is changed to all uppercase.  The new             */
/*                      string is returned AND replaces the original.         */
/*                      Only lowercase letters are changed.                   */
/*                                                                            */
/*      Examples:                                                             */
/*                                                                            */
/*          string str1 = "Yes";                                              */
/*          string str2 = "No";                                               */
/*          ToUpper(str1);                                                    */
/*          if("YES" == str1)                                                 */
/*          {                                                                 */
/*              DoStuff();                                                    */
/*          }                                                                 */
/*          if("NO" == ToUpper(str2))                                         */
/*          {                                                                 */
/*              DoStuff();                                                    */
/*          }                                                                 */
/*                                                                            */
/*  IsYesNo:  used to determine if a string begins with either a 'y' or 'n'.  */
/*                                                                            */
/*  bool IsYesNo(const string & str, char & firstChar)                        */
/*                                                                            */
/*      Precondition:   str is a valid string                                 */
/*      Postcondition:  True is returned iff the first non-whitespace         */
/*                      character in 'str' is either a "y" or "n".            */
/*                      'firstchar' is a lowercase copy of that character.    */
/*                      'str' is unchanged.                                   */
/*                                                                            */
/*      Example:                                                              */
/*                                                                            */
/*          string str = "";                                                  */
/*          char chr = '_';                                                   */
/*          cout << "Would you like to continue?";                            */
/*          cin >> str;                                                       */
/*          if(IsYesNo(str,chr)                                               */
/*          {                                                                 */
/*              if('y' == chr)                                                */
/*              {                                                             */
/*                  DoStuff();                                                */
/*              }                                                             */
/*              else                                                          */
/*              {                                                             */
/*                  Exit();                                                   */
/*              }                                                             */
/*          }                                                                 */
/*          else                                                              */
/*          {                                                                 */
/*              Error();                                                      */
/*          }                                                                 */
/*                                                                            */
/*  StripWhite:  used to remove leading and trailing whitespace               */
/*                                                                            */
/*  string StripWhite(string & str)                                           */
/*                                                                            */
/*      Precondition:   str is a valid string                                 */
/*      Postcondition;  All leading and trailing whitespace is removed        */
/*                                                                            */
/*      Example:                                                              */
/*                                                                            */
/*          string str = "    Hi there.    ";                                 */
/*          cout << StripWhite(str);                                          */
/*                                                                            */
/*      would give exactly the same output as:                                */
/*                                                                            */
/*          string str = "Hi there.";                                         */
/*          cout << StripWhite(str);                                          */
/*                                                                            */
/*  tostring:  used to convert any Type to string                             */
/*                                                                            */
/*  string tostring(const Type & t)                                           */
/*                                                                            */
/*      Precondition:   t is any Type                                         */
/*      Postcondition:  The string equivalent of t is returned                */
/*                                                                            */
/*      Example:                                                              */
/*                                                                            */
/*          int num = 7;                                                      */
/*          string str = "There are " + tostring(num) + " days in the week";  */
/*          cout << str;                                                      */
/*                                                                            */
/*  ToNum:  used to convert a string to a number                              */
/*                                                                            */
/*  Type ToNum(const string & str, Type & value, bool & error)                */
/*                                                                            */
/*      Precondition:   str is a string of characters                         */
/*      Postcondition:  Returns Type equivalent of str and error = false      */
/*                      iff the string can be converted to a valid Type.      */
/*                      The value will also be returned in 'value'.  If an    */
/*                      error occurrs, 'value' and the returned value will    */
/*                      be 0.                                                 */
/*                                                                            */
/*      Example:                                                              */
/*                                                                            */
/*          string str = "";                                                  */
/*          int age = 0;                                                      */
/*          bool error = false;                                               */
/*          cout << "Please enter your age: ";                                */
/*          cin >> str;                                                       */
/*          ToNum(str, age, error);                                           */
/*          if(error)                                                         */
/*          {                                                                 */
/*              ErrorRoutine();                                               */
/*          }                                                                 */
/*          else                                                              */
/*          {                                                                 */
/*              cout << "I did not know you were " << age << " years old.";   */
/*          }                                                                 */
/*                                                                            */
/******************************************************************************/
/******************************************************************************/
/*                                                                            */
/*           **********  The History Of These Utilities. **********           */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*      These utilities were reworked to be more complete, robust,            */
/*      symetrical, and provide some amount of error checking for             */
/*      "string-to-number" routines such as "atof".  These utilities place    */
/*      no limitation of their own on parameters such as string length or     */
/*      number size.  Instead, any compiler or system level limits will be    */
/*      imposed and enforced and will be the controlling factor.  Also, to    */
/*      prevent entry rounding errors, only 'PRECISION' number of             */
/*      significant digits will be be passed thru the various string-to-      */
/*      number routines.  'PRECISION' is obtained by determining how many     */
/*      digits the system is able to uniquely resolve.                        */
/*                                                                            */
/*              [See the function:                                            */
/*               'bool IsNum(const string & str, biggestType & value)'        */
/*               for the details of how this is implemented.]                 */
/*                                                                            */
/*      The correct operation of the various string-to-number routines        */
/*      assume that the C++ compiler can correctly handle the type            */
/*      "long double", or at least handle it the same as "double".  If        */
/*      this is not the case for your compiler, change the 'typedef' for      */
/*      "biggestType", below, to "double" in the Pre-Processor Directives.    */
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

#include <cctype>                         /* std sys char manipulation header.*/
#include <string>                         /* "string" class definition header.*/
using namespace std;

typedef long double biggestType;          /* Largest internally supported Type*/

/******************************************************************************/
/******************************************************************************/
/*                                                                            */
/*      ***** These Primary Functions Are Provided In This Program. *****     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*string ToLower(string & str);           /* str changed to all lowercase.    */
/*string ToUpper(string & str);           /* str changed to all uppercase.    */
/*string ToSwitchCase(string & str);      /* str lowercase/uppercase switched.*/
/*string ToReverse(string & str);         /* Reverse str.                     */
/*bool IsYesNo(const string & str, char &firstChar);/* True iff 1st char = y/n*/
/*string StripPunc(string & str);         /* Remove leading/trailing punct.   */
/*string StripWhite(string & str);        /* Remove leading/trailing white.   */
/*string CompressString(string & str);    /* Condense and strip whitespace.   */
/*string tostring(const Type & t);        /* Returns string equiv of Type.    */
/*bool IsNum(const string & str, Type & value);          /* T iff str val Type*/
/*Type ToNum(const string & str, Type & value, bool & error);/*Type ver of str*/
/*                                                                            */
/******************************************************************************/
/******************************************************************************/
/*                                                                            */
/****** These Basic Functions / Procedures Are Provided In This Program. ******/
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*string ToLower(string & str);           /* str changed to all lowercase.    */
/*string LowerString(const string & str); /* Return lowercase str.            */
/*string ToUpper(string & str);           /* str changed to all uppercase.    */
/*string UpperString(const string & str); /* Return uppercase str.            */
/*string ToSwitchCase(string & str);      /* str lowercase/uppercase switched.*/
/*string SwitchCase(const string & str);  /* Return switched case str.        */
/*string ToReverse(string & str);         /* Reverse str.                     */
/*string ReverseString(const string & str);         /* Return reverse str.    */
/*bool IsYesNo(const string & str, char &firstChar);/* True iff 1st char = y/n*/
/*string StripPunc(string & str);         /* Remove leading/trailing punct.   */
/*string StripWhite(string & str);        /* Remove leading/trailing white.   */
/*string CompressString(string & str);    /* Condense and strip whitespace.   */
/*string tostring(const Type & t);        /* Returns string equiv of Type.    */
/*string ftoa(const double & n);          /* Returns string equiv of double.  */
/*string ltoa(const long & n);            /* Returns string equiv of long.    */
/*string itoa(const int & n);	          /* Returns string equiv of int.     */
/*void GetLimits(const Type & t, string & min, string & max); /* Type min/max.*/
/*bool IsNum(const string & str, Type & value);          /* T iff str val Type*/
/*bool IsDouble(const string & str);            /* True iff str valid double. */
/*bool IsLong(const string & str);              /* True iff str valid long.   */
/*bool IsInt(const string & str);               /* True iff str valid int.    */
/*Type ToNum(const string & str, Type & value, bool & error);/*Type ver of str*/
/*double atof(const string & str, bool & error);/* Returns double w/ error.   */
/*long atol(const string & str, bool & error);  /* Returns long w/ error.     */
/*int atoi(const string & str, bool & error);   /* Returns int w/ error.      */
/*                                                                            */
/******************************************************************************/
/******************************************************************************/
/*                                                                            */
/***  These Equivalent Functions / Procedures Are Provided In This Program. ***/
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*string ToLower(string & str);           /* str changed to all lowercase.    */
/*void ToLower(string & str);             /* str changed to all lowercase.    */
/*string LowerString(const string & str); /* Return lowercase str.            */
/*string ToUpper(string & str);           /* str changed to all uppercase.    */
/*void ToUpper(string & str);             /* str changed to all uppercase.    */
/*string UpperString(const string & str); /* Return uppercase str.            */
/*string ToSwitchCase(string & str);      /* str lowercase/uppercase switched.*/
/*void ToSwitchCase(string & str);        /* str lowercase/uppercase switched.*/
/*string SwitchCase(const string & str);  /* Return switched case str.        */
/*string ToReverse(string & str);         /* Reverse str.                     */
/*void ToReverse(string & str);           /* Reverse str.                     */
/*string ReverseString(const string & str);         /* Return reverse str.    */
/*bool IsYesNo(const string & str, char &firstChar);/* True iff 1st char = y/n*/
/*bool IsYesNo(const string & str);                 /* True iff 1st char = y/n*/
/*string StripPunc(string & str);         /* Remove leading/trailing punct.   */
/*void StripPunc(string & str);           /* Remove leading/trailing punct.   */
/*string StripWhite(string & str);        /* Remove leading/trailing white.   */
/*void StripWhite(string & str);          /* Remove leading/trailing white.   */
/*string CompressString(string & str);    /* Condense and strip whitespace.   */
/*void CompressString(string & str);      /* Condense and strip whitespace.   */
/*string tostring(const long double & t);  /* Return str equiv of long double.*/
/*string tostring(const double & t);       /* Return string equiv of double.  */
/*string tostring(const float & t);        /* Return string equiv of float.   */
/*string tostring(const long & t);         /* Return string equiv of long.    */
/*string tostring(const int & t);          /* Return string equiv of int.     */
/*string tostring(const short & t);        /* Return string equiv of short.   */
/*string tostring(const char & t);         /* Return string equiv of char.    */
/*string tostring(const unsigned long & t);/* Return str eq of unsigned long. */
/*string tostring(const unsigned int & t); /* Return str equiv of unsigned int*/
/*string tostring(const unsigned short & t);/* Return str eq of unsigned short*/
/*string tostring(const unsigned char & t);/* Return str eq of unsigned char. */
/*string tostring(const signed char & t);  /* Return str equiv of signed char.*/
/*string tostring(const bool & t);         /* Return string equiv of bool.    */
/*string tostring(const string & t);       /* Return string equiv of string.  */
/*string ftoa(const double & n);          /* Returns string equiv of double.  */
/*string ltoa(const long & n);            /* Returns string equiv of long.    */
/*string itoa(const int & n);	          /* Returns string equiv of int.     */
/*void GetLimits(const long double & t, string & min, string & max);          */
/*void GetLimits(const double & t, string & min, string & max);               */
/*void GetLimits(const float & t, string & min, string & max);                */
/*void GetLimits(const long & t, string & min, string & max);                 */
/*void GetLimits(const int & t, string & min, string & max);                  */
/*void GetLimits(const short & t, string & min, string & max);                */
/*void GetLimits(const char & t, string & min, string & max);                 */
/*void GetLimits(const unsigned long & t, string & min, string & max);        */
/*void GetLimits(const unsigned int & t, string & min, string & max);         */
/*void GetLimits(const unsigned short & t, string & min, string & max);       */
/*void GetLimits(const unsigned char & t, string & min, string & max);        */
/*void GetLimits(const signed char & t, string & min, string & max);          */
/*void GetLimits(const bool & t, string & min, string & max);                 */
/*bool IsNum(const string & str, biggestType & value);   /* T iff str valid bT*/
/*bool IsNum(const string & str, double & value);        /* T iff str val dbl.*/
/*bool IsNum(const string & str, float & value);         /* T iff str val floa*/
/*bool IsNum(const string & str, long & value);          /* T iff str val long*/
/*bool IsNum(const string & str, int & value);           /* T iff str val int.*/
/*bool IsNum(const string & str, short & value);         /* T iff str val shor*/
/*bool IsNum(const string & str, char & value);          /* T iff str val char*/
/*bool IsNum(const string & str, unsigned long & value); /* T iff str val ulng*/
/*bool IsNum(const string & str, unsigned int & value);  /* T iff str val uint*/
/*bool IsNum(const string & str, unsigned short & value);/* T iff str val ushr*/
/*bool IsNum(const string & str, unsigned char & value); /* T iff str val uchr*/
/*bool IsNum(const string & str, signed char & value);   /* T iff str val schr*/
/*bool IsNum(const string & str, bool & value);          /* T iff str val bool*/
/*void IsNum(const string & str, biggestType & value);   /* str to bT = value.*/
/*void IsNum(const string & str, double & value);        /* str to dbl = value*/
/*void IsNum(const string & str, float & value);         /* str to floa= value*/
/*void IsNum(const string & str, long & value);          /* str to long= value*/
/*void IsNum(const string & str, int & value);           /* str to int = value*/
/*void IsNum(const string & str, short & value);         /* str to shor= value*/
/*void IsNum(const string & str, char & value);          /* str to char= value*/
/*void IsNum(const string & str, unsigned long & value); /* str to ulng= value*/
/*void IsNum(const string & str, unsigned int & value);  /* str to uint= value*/
/*void IsNum(const string & str, unsigned short & value);/* str to ushr= value*/
/*void IsNum(const string & str, unsigned char & value); /* str to uchr= value*/
/*void IsNum(const string & str, signed char & value);   /* str to schr= value*/
/*void IsNum(const string & str, bool & value);          /* str to bool= value*/
/*bool IsDouble(const string & str);            /* True iff str valid double. */
/*bool IsLong(const string & str);              /* True iff str valid long.   */
/*bool IsInt(const string & str);               /* True iff str valid int.    */
/*long double ToNum(const string & str, long double & value, bool & error);   */
/*double ToNum(const string & str, double & value, bool & error);             */
/*float ToNum(const string & str, float & value, bool & error);               */
/*long ToNum(const string & str, long & value, bool & error);                 */
/*int ToNum(const string & str, int & value, bool & error);                   */
/*short ToNum(const string & str, short & value, bool & error);               */
/*char ToNum(const string & str, char & value, bool & error);                 */
/*unsigned long ToNum(const string & str, unsigned long & value, bool &error);*/
/*unsigned int ToNum(const string & str, unsigned int & value, bool & error); */
/*unsigned short ToNum(const string &str, unsigned short &value, bool &error);*/
/*unsigned char ToNum(const string & str, unsigned char & value, bool &error);*/
/*signed char ToNum(const string & str, signed char & value, bool & error);   */
/*bool ToNum(const string & str, bool & value, bool & error);                 */
/*void ToNum(const string & str, long double & value, bool & error);          */
/*void ToNum(const string & str, double & value, bool & error);               */
/*void ToNum(const string & str, float & value, bool & error);                */
/*void ToNum(const string & str, long & value, bool & error);                 */
/*void ToNum(const string & str, int & value, bool & error);                  */
/*void ToNum(const string & str, short & value, bool & error);                */
/*void ToNum(const string & str, char & value, bool & error);                 */
/*void ToNum(const string & str, unsigned long & value, bool & error);        */
/*void ToNum(const string & str, unsigned int & value, bool & error);         */
/*void ToNum(const string & str, unsigned short & value, bool & error);       */
/*void ToNum(const string & str, unsigned char & value, bool & error);        */
/*void ToNum(const string & str, signed char & value, bool & error);          */
/*void ToNum(const string & str, bool & value, bool & error);                 */
/*double atof(const string & str, bool & error);/* Returns double w/ error.   */
/*long atol(const string & str, bool & error);  /* Returns long w/ error.     */
/*int atoi(const string & str, bool & error);   /* Returns int w/ error.      */
/*double atof(const string & str);        /* Returns double equivalent of str.*/
/*long atol(const string & str);          /* Returns long equivalent of str.  */
/*int atoi(const string & str);           /* Returns int equivalent of str.   */
/*                                                                            */
/******************************************************************************/
/******************************************************************************/
/*                                                                            */
/******** Make Sure All Functions and Procedures Have Been Prototyped. ********/
/*                                                                            */
/******************************************************************************/
/******************************************************************************/

string ToLower(string & str);             /* str changed to all lowercase.    */

    /*  Purpose:        To change a referenced string to all lowercase.       */
    /*                  Only uppercase letters are changed.                   */

    /*  Precondition:   str == any string of characters.                      */

    /*  Postcondition:  All uppercase characters in referenced string         */
    /*                  are lowercase.  The new str is returned AND replaces  */
    /*                  the original.                                         */

                          /**************************/
/* Equivalent to:                                                             */
/*                                                                            */
/*string ToLower(string & str);           /* str changed to all lowercase.    */
/*void ToLower(string & str);             /* str changed to all lowercase.    */

/******************************************************************************/

string LowerString(const string & str);   /* Return lowercase str.            */

    /*  Purpose:        To change a referenced string to all lowercase.       */
    /*                  Only uppercase letters are changed.                   */

    /*  Precondition:   str == any string of characters.                      */

    /*  Postcondition:  Return string has all uppercase characters converted  */
    /*                  to lowercase.  Original is unchanged.                 */

/******************************************************************************/

string ToUpper(string & str);             /* str changed to all uppercase.    */

    /*  Purpose:        To change a referenced string to all uppercase.       */
    /*                  Only lowercase letters are changed.                   */

    /*  Precondition:   str == any string of characters.                      */

    /*  Postcondition:  All lowercase characters in referenced string         */
    /*                  are uppercase.  The new str is returned AND replaces  */
    /*                  the original.                                         */

                          /**************************/
/* Equivalent to:                                                             */
/*                                                                            */
/*string ToUpper(string & str);           /* str changed to all uppercase.    */
/*void ToUpper(string & str);             /* str changed to all uppercase.    */

/******************************************************************************/

string UpperString(const string & str);   /* Return uppercase str.            */

    /*  Purpose:        To change a referenced string to all uppercase.       */
    /*                  Only lowercase letters are changed.                   */

    /*  Precondition:   str == any string of characters.                      */

    /*  Postcondition:  Return string has all lowercase characters converted  */
    /*                  to uppercase.  Original is unchanged.                 */

/******************************************************************************/

string ToSwitchCase(string & str);        /* str lowercase/uppercase switched.*/

    /*  Purpose:        To change all lowercase in referenced string to       */
    /*                  uppercase, and change all uppercase to lowercase.     */

    /*  Precondition:   str == any string of characters.                      */

    /*  Postcondition:  All lowercase characters in referenced string  are    */
    /*                  uppercase, and all uppercase characters are lowercase.*/
    /*                  The new str is returned AND replaces the original.    */

                          /**************************/
/* Equivalent to:                                                             */
/*                                                                            */
/*string ToSwitchCase(string & str);      /* str lowercase/uppercase switched.*/
/*void ToSwitchCase(string & str);        /* str lowercase/uppercase switched.*/

/******************************************************************************/

string SwitchCase(const string & str);    /* Return switched case str.        */

    /*  Purpose:        To change all lowercase in referenced string to       */
    /*                  uppercase, and change all uppercase to lowercase.     */

    /*  Precondition:   str == any string of characters.                      */

    /*  Postcondition:  Return string has case of all lowercase and uppercase */
    /*                  characters switched.  Original is unchanged.          */

/******************************************************************************/

string ToReverse(string & str);           /* Reverse str.                     */

    /*  Purpose:        To reverse a referenced string.                       */

    /*  Precondition:   str == any string of characters.                      */

    /*  Postcondition:  Referenced string is reversed AND is returned.        */

                          /**************************/
/* Equivalent to:                                                             */
/*                                                                            */
/*string ToReverse(string & str);         /* Reverse str.                     */
/*void ToReverse(string & str);           /* Reverse str.                     */

/******************************************************************************/

string ReverseString(const string & str);           /* Return reverse str.    */

    /*  Purpose:        To reverse a referenced string.                       */

    /*  Precondition:   str == any string of characters.                      */

    /*  Postcondition:  Return string is a reversed copy of the referenced    */
    /*                  string. Original is unchanged.                        */

/******************************************************************************/

bool IsYesNo(const string & str, char & firstChar); /* True iff 1st char = y/n*/

    /*  Purpose:        To determine if the first non-whitespace character in */
    /*                  a referenced string is either a "y" or "n", or not.   */
    /*                  Case is ignored.                                      */

    /*  Precondition:   str == any string of characters.                      */
    /*                  firstChar == location to store 1st non-whitespace chr.*/

    /*  Postcondition:  Returns true iff the first non-whitespace character   */
    /*                  in 'str' is either a "y" or "n".  'firstChar' is a    */
    /*                  lowercase copy of that character.  'str' is unchanged.*/

/******************************************************************************/

bool IsYesNo(const string & str);                   /* True iff 1st char = y/n*/

    /*  Purpose:        To determine if the first non-whitespace character in */
    /*                  a referenced string is either a "y" or "n", or not.   */
    /*                  Case is ignored.                                      */

    /*  Precondition:   str == any string of characters.                      */

    /*  Postcondition:  Returns true iff the first non-whitespace character   */
    /*                  in 'str' is either a "y" or "n".  'str' is unchanged. */

/******************************************************************************/

string StripPunc(string & str);           /* Remove leading/trailing punct.   */

    /*  Purpose:        To remove all leading and trailing punctuation from   */
    /*                  a referenced string.                                  */

    /*  Precondition:   str == any string of characters.                      */

    /*  Postcondition:  All leading and trailing punctuation is removed from  */
    /*                  referenced string.  Special case: if the string is    */
    /*                  either empty, or has only punctuation, the resulting  */
    /*                  string will be empty. 'str' is changed AND returned.  */

                          /**************************/
/* Equivalent to:                                                             */
/*                                                                            */
/*string StripPunc(string & str);         /* Remove leading/trailing punct.   */
/*void StripPunc(string & str);           /* Remove leading/trailing punct.   */

/******************************************************************************/

string StripWhite(string & str);          /* Remove leading/trailing white.   */

    /*  Purpose:        To remove all leading and trailing whitespace from    */
    /*                  a referenced string.                                  */

    /*  Precondition:   str == any string of characters.                      */

    /*  Postcondition:  All leading and trailing whitespace is removed from   */
    /*                  referenced string.  Special case: if the string is    */
    /*                  either empty, or has only whitespace, the resulting   */
    /*                  string will be empty. 'str' is changed AND returned.  */

                          /**************************/
/* Equivalent to:                                                             */
/*                                                                            */
/*string StripWhite(string & str);        /* Remove leading/trailing white.   */
/*void StripWhite(string & str);          /* Remove leading/trailing white.   */

/******************************************************************************/

string CompressString(string & str);      /* Condense and strip whitespace.   */

    /*  Purpose:        To reduce each occurrence of adjacent whitespaces in  */
    /*                  a referenced string to a single space character, and  */
    /*                  remove any remaining whitespace from either end.      */

    /*  Precondition:   str == any string of characters.                      */

    /*  Postcondition:  Each occurrence of adjoining spaces is now one space, */
    /*                  and any leading or trailing spaces have been removed. */
    /*                  'str' is changed AND returned.                        */

                          /**************************/
/* Equivalent to:                                                             */
/*                                                                            */
/*string CompressString(string & str);    /* Condense and strip whitespace.   */
/*void CompressString(string & str);      /* Condense and strip whitespace.   */

/******************************************************************************/

template <class Type>
string tostring(const Type & t);          /* Returns string equiv of a Type.  */

    /*  Purpose:        To convert a supplied Type to its string equivalent.  */

    /*  Precondition:   t == any Type.                                        */

    /*  Postcondition:  The string equivalent of t is returned, t is unchanged*/

                          /**************************/
/* Equivalent to:                                                             */
/*                                                                            */
/*string tostring(const long double & t);  /* Return str equiv of long double.*/
/*string tostring(const double & t);       /* Return string equiv of double.  */
/*string tostring(const float & t);        /* Return string equiv of float.   */
/*string tostring(const long & t);         /* Return string equiv of long.    */
/*string tostring(const int & t);          /* Return string equiv of int.     */
/*string tostring(const short & t);        /* Return string equiv of short.   */
/*string tostring(const char & t);         /* Return string equiv of char.    */
/*string tostring(const unsigned long & t);/* Return str eq of unsigned long. */
/*string tostring(const unsigned int & t); /* Return str equiv of unsigned int*/
/*string tostring(const unsigned short & t);/* Return str eq of unsigned short*/
/*string tostring(const unsigned char & t);/* Return str eq of unsigned char. */
/*string tostring(const signed char & t);  /* Return str equiv of signed char.*/
/*string tostring(const bool & t);         /* Return string equiv of bool.    */
/*string tostring(const string & t);       /* Return string equiv of string.  */

/******************************************************************************/

string ftoa(const double & n);            /* Returns string equiv of double.  */

    /*  Purpose:        To convert a supplied double to its string equivalent.*/

    /*  Precondition:   n == a valid double.                                  */

    /*  Postcondition:  The string equivalent is returned.                    */
    /*                  The number is unchanged.                              */

/******************************************************************************/

string ltoa(const long & n);              /* Returns string equiv of long.    */

    /*  Purpose:        To convert a supplied long to its string equivalent.  */

    /*  Precondition:   n == a valid long.                                    */

    /*  Postcondition:  The string equivalent is returned.                    */
    /*                  The number is unchanged.                              */

/******************************************************************************/

string itoa(const int & n);               /* Returns string equiv of int.     */

    /*  Purpose:        To convert a supplied int to its string equivalent.   */

    /*  Precondition:   n == a valid int.                                     */

    /*  Postcondition:  The string equivalent is returned.                    */
    /*                  The number is unchanged.                              */

/******************************************************************************/

template <class Type>
void GetLimits(const Type & t, string & min, string & max); /* Class min/max. */

    /*  Purpose:        To obtain the system numeric limits of a Type         */
    /*                  selected by the user.                                 */

    /*  Precondition:   t == a const of Type for which you want numeric limits*/

    /*  Postcondition:  The string equivalent of the numeric minimum and      */
    /*                  maximum for Type is passed back in 'min' and 'max'.   */

                          /**************************/
/* Equivalent to:                                                             */
/*                                                                            */
/*void GetLimits(const long double & t, string & min, string & max);          */
/*void GetLimits(const double & t, string & min, string & max);               */
/*void GetLimits(const float & t, string & min, string & max);                */
/*void GetLimits(const long & t, string & min, string & max);                 */
/*void GetLimits(const int & t, string & min, string & max);                  */
/*void GetLimits(const short & t, string & min, string & max);                */
/*void GetLimits(const char & t, string & min, string & max);                 */
/*void GetLimits(const unsigned long & t, string & min, string & max);        */
/*void GetLimits(const unsigned int & t, string & min, string & max);         */
/*void GetLimits(const unsigned short & t, string & min, string & max);       */
/*void GetLimits(const unsigned char & t, string & min, string & max);        */
/*void GetLimits(const signed char & t, string & min, string & max);          */
/*void GetLimits(const bool & t, string & min, string & max);                 */

/******************************************************************************/

bool IsNum(const string & str, biggestType & value);     /* T iff str valid bT*/

    /*  Purpose:        To verify that a referenced string can be converted   */
    /*                  to a valid number of the biggest internally available */
    /*                  Type in the system.  Error checking is performed to   */
    /*                  confirm syntax and size is consistant with this Type. */
    /*                  Maximum and minimum system limits are imposed.  They  */
    /*                  are obtained thru the system header file <limits>     */
    /*                  using 'GetLimits'.  These limits are then used for    */
    /*                  comparison error checking.  Leading and trailing      */
    /*                  whitespace is ignored.                                */
    /*                  Since the converted value is returned in 'value', you */
    /*                  can use the void version of this function like        */
    /*                  "ToNum" with no error indication -- a valid "0" and   */
    /*                  an invalid str will give the same 0 value.            */

    /*  Precondition:   str == any string of characters.                      */

    /*  Postcondition:  True is returned iff the string can be converted to a */
    /*                  valid number of the biggest internally available Type */
    /*                  in the system.  The converted number is in 'value'.   */
    /*                  If the number isn't a valid number, false is returned */
    /*                  and 'value' is 0.0.  The original string is unchanged.*/

                          /**************************/
/* Equivalent to:                                                             */
/*                                                                            */
/*bool IsNum(const string & str, biggestType & value);   /* T iff str valid bT*/
/*void IsNum(const string & str, biggestType & value);   /* str to bT = value.*/

/******************************************************************************/

template <class Type>
bool IsNum(const string & str, Type & value);   /* True iff str valid number. */

    /*  Purpose:        To verify that a referenced string can be converted   */
    /*                  to a valid number.  Error checking is performed to    */
    /*                  confirm syntax and size is consistant with the type   */
    /*                  Type.  Leading and trailing whitespace is ignored.    */
    /*                  Since the converted value is returned in 'value', you */
    /*                  can use the void version of this function like        */
    /*                  "ToNum" with no error indication -- a valid "0" and   */
    /*                  an invalid str will give the same 0 value.            */

    /*  Precondition:   str == any string of characters.                      */

    /*  Postcondition:  True is returned iff the string can be converted to a */
    /*                  valid number.  The converted number is in 'value'.    */
    /*                  If the number isn't a valid number, false is returned */
    /*                  and 'value' is 0.  The original string is unchanged.  */

                          /**************************/
/* Equivalent to:                                                             */
/*                                                                            */
/*bool IsNum(const string & str, double & value);        /* T iff str val dbl.*/
/*bool IsNum(const string & str, float & value);         /* T iff str val floa*/
/*bool IsNum(const string & str, long & value);          /* T iff str val long*/
/*bool IsNum(const string & str, int & value);           /* T iff str val int.*/
/*bool IsNum(const string & str, short & value);         /* T iff str val shor*/
/*bool IsNum(const string & str, char & value);          /* T iff str val char*/
/*bool IsNum(const string & str, unsigned long & value); /* T iff str val ulng*/
/*bool IsNum(const string & str, unsigned int & value);  /* T iff str val uint*/
/*bool IsNum(const string & str, unsigned short & value);/* T iff str val ushr*/
/*bool IsNum(const string & str, unsigned char & value); /* T iff str val uchr*/
/*bool IsNum(const string & str, signed char & value);   /* T iff str val schr*/
/*bool IsNum(const string & str, bool & value);          /* T iff str val bool*/
/*void IsNum(const string & str, double & value);        /* str to dbl = value*/
/*void IsNum(const string & str, float & value);         /* str to floa= value*/
/*void IsNum(const string & str, long & value);          /* str to long= value*/
/*void IsNum(const string & str, int & value);           /* str to int = value*/
/*void IsNum(const string & str, short & value);         /* str to shor= value*/
/*void IsNum(const string & str, char & value);          /* str to char= value*/
/*void IsNum(const string & str, unsigned long & value); /* str to ulng= value*/
/*void IsNum(const string & str, unsigned int & value);  /* str to uint= value*/
/*void IsNum(const string & str, unsigned short & value);/* str to ushr= value*/
/*void IsNum(const string & str, unsigned char & value); /* str to uchr= value*/
/*void IsNum(const string & str, signed char & value);   /* str to schr= value*/
/*void IsNum(const string & str, bool & value);          /* str to bool= value*/

/******************************************************************************/

bool IsDouble(const string & str);              /* True iff str valid double. */

    /*  Purpose:        To verify that a referenced string can be converted   */
    /*                  to a valid double.  Error checking is performed to    */
    /*                  confirm syntax and size is consistant with the type   */
    /*                  double.  Leading and trailing whitespace is ignored.  */

    /*  Precondition:   str == any string of characters.                      */

    /*  Postcondition:  True is returned iff the string can be converted to a */
    /*                  valid double.  The original string is unchanged.      */

/******************************************************************************/

bool IsLong(const string & str);                /* True iff str valid long.   */

    /*  Purpose:        To verify that a referenced string can be converted   */
    /*                  to a valid long.  Error checking is performed to      */
    /*                  confirm syntax and size is consistant with the type   */
    /*                  long.  Leading and trailing whitespace is ignored.    */

    /*  Precondition:   str == any string of characters.                      */

    /*  Postcondition:  True is returned iff the string can be converted to a */
    /*                  valid long.  The original string is unchanged.        */

/******************************************************************************/

bool IsInt(const string & str);                 /* True iff str valid int.    */

    /*  Purpose:        To verify that a referenced string can be converted   */
    /*                  to a valid int.  Error checking is performed to       */
    /*                  confirm syntax and size is consistant with the type   */
    /*                  int.  Leading and trailing whitespace is ignored.     */

    /*  Precondition:   str == any string of characters.                      */

    /*  Postcondition:  True is returned iff the string can be converted to a */
    /*                  valid int.  The original string is unchanged.         */

/******************************************************************************/

template <class Type>
Type ToNum(const string & str, Type & value, bool & error);/*Type equiv of str*/

    /*  Purpose:        To convert a referenced string to a 'Type' number.    */
    /*                  Error checking is performed to confirm syntax and     */
    /*                  size is consistant with Type.  Leading and trailing   */
    /*                  whitespace is ignored.                                */

    /*  Precondition:   str == any string of characters.                      */

    /*  Postcondition:  Returns Type equivalent of 'str', and 'error' = false */
    /*                  iff the string can be converted to a valid Type.  The */
    /*                  value will also be returned in 'value'.  If the       */
    /*                  number isn't a valid Type, 0 is returned and in value,*/
    /*                  and 'error' is true.  The original str is unchanged.  */

                          /**************************/
/* Equivalent to:                                                             */
/*                                                                            */
/*long double ToNum(const string & str, long double & value, bool & error);   */
/*double ToNum(const string & str, double & value, bool & error);             */
/*float ToNum(const string & str, float & value, bool & error);               */
/*long ToNum(const string & str, long & value, bool & error);                 */
/*int ToNum(const string & str, int & value, bool & error);                   */
/*short ToNum(const string & str, short & value, bool & error);               */
/*char ToNum(const string & str, char & value, bool & error);                 */
/*unsigned long ToNum(const string & str, unsigned long & value, bool &error);*/
/*unsigned int ToNum(const string & str, unsigned int & value, bool & error); */
/*unsigned short ToNum(const string &str, unsigned short &value, bool &error);*/
/*unsigned char ToNum(const string & str, unsigned char & value, bool &error);*/
/*signed char ToNum(const string & str, signed char & value, bool & error);   */
/*bool ToNum(const string & str, bool & value, bool & error);                 */
/*void ToNum(const string & str, long double & value, bool & error);          */
/*void ToNum(const string & str, double & value, bool & error);               */
/*void ToNum(const string & str, float & value, bool & error);                */
/*void ToNum(const string & str, long & value, bool & error);                 */
/*void ToNum(const string & str, int & value, bool & error);                  */
/*void ToNum(const string & str, short & value, bool & error);                */
/*void ToNum(const string & str, char & value, bool & error);                 */
/*void ToNum(const string & str, unsigned long & value, bool & error);        */
/*void ToNum(const string & str, unsigned int & value, bool & error);         */
/*void ToNum(const string & str, unsigned short & value, bool & error);       */
/*void ToNum(const string & str, unsigned char & value, bool & error);        */
/*void ToNum(const string & str, signed char & value, bool & error);          */
/*void ToNum(const string & str, bool & value, bool & error);                 */

/******************************************************************************/

double atof(const string & str, bool & error);  /* Returns double w/ error.   */

    /*  Purpose:        To convert a referenced string to a double.  Error    */
    /*                  checking is performed to confirm syntax and size is   */
    /*                  consistant with the type double.  Leading and trailing*/
    /*                  whitespace is ignored.                                */

    /*  Precondition:   str == any string of characters.                      */

    /*  Postcondition:  Returns double equivalent of 'str' and 'error' = false*/
    /*                  iff the string can be converted to a valid double.  If*/
    /*                  the number isn't a valid double, 0.0 is returned and  */
    /*                  'error' is true.  The original string is unchanged.   */

/******************************************************************************/

long atol(const string & str, bool & error);    /* Returns long w/ error.     */

    /*  Purpose:        To convert a referenced string to a long.  Error      */
    /*                  checking is performed to confirm syntax and size is   */
    /*                  consistant with the type long.  Leading and trailing  */
    /*                  whitespace is ignored.                                */

    /*  Precondition:   str == any string of characters.                      */

    /*  Postcondition:  Returns long equivalent of 'str' and 'error' = false  */
    /*                  iff the string can be converted to a valid long.  If  */
    /*                  the number isn't a valid long, 0 is returned and      */
    /*                  'error' is true.  The original string is unchanged.   */

/******************************************************************************/

int atoi(const string & str, bool & error);     /* Returns int w/ error.      */

    /*  Purpose:        To convert a referenced string to an int.  Error      */
    /*                  checking is performed to confirm syntax and size is   */
    /*                  consistant with the type int.  Leading and trailing   */
    /*                  whitespace is ignored.                                */

    /*  Precondition:   str == any string of characters.                      */

    /*  Postcondition:  Returns int equivalent of 'str' and 'error' = false   */
    /*                  iff the string can be converted to a valid int.  If   */
    /*                  the number isn't a valid int, 0 is returned and       */
    /*                  'error' is true.  The original string is unchanged.   */

/******************************************************************************/

double atof(const string & str);          /* Returns double equivalent of str.*/

    /*  Purpose:        To convert a referenced string to a double.  Error    */
    /*                  checking is performed to confirm syntax and size is   */
    /*                  consistant with the type double.  Leading and trailing*/
    /*                  whitespace is ignored.                                */

    /*  Precondition:   str == any string of characters.                      */

    /*  Postcondition:  Returns double equivalent of 'str' iff the string can */
    /*                  be converted to a valid double.  If the number isn't  */
    /*                  a valid double, 0.0 is returned.  No other error      */
    /*                  indication is provided.  This routine is provided to  */
    /*                  be compatible with the original "atof".  The original */
    /*                  string is unchanged.                                  */

/******************************************************************************/

long atol(const string & str);            /* Returns long equivalent of str.  */

    /*  Purpose:        To convert a referenced string to a long.  Error      */
    /*                  checking is performed to confirm syntax and size is   */
    /*                  consistant with the type long.  Leading and trailing  */
    /*                  whitespace is ignored.                                */

    /*  Precondition:   str == any string of characters.                      */

    /*  Postcondition:  Returns long equivalent of 'str' iff the string can   */
    /*                  be converted to a valid long.  If the number isn't    */
    /*                  a valid long, 0 is returned.  No other error          */
    /*                  indication is provided.  This routine is provided to  */
    /*                  be compatible with the original "atol".  The original */
    /*                  string is unchanged.                                  */

/******************************************************************************/

int atoi(const string & str);             /* Returns int equivalent of str.   */

    /*  Purpose:        To convert a referenced string to an int.  Error      */
    /*                  checking is performed to confirm syntax and size is   */
    /*                  consistant with the type int.  Leading and trailing   */
    /*                  whitespace is ignored.                                */

    /*  Precondition:   str == any string of characters.                      */

    /*  Postcondition:  Returns long equivalent of 'str' iff the string can   */
    /*                  be converted to a valid int.  If the number isn't     */
    /*                  a valid int, 0 is returned.  No other error           */
    /*                  indication is provided.  This routine is provided to  */
    /*                  be compatible with the original "atoi".  The original */
    /*                  string is unchanged.                                  */


/******************************************************************************/
/******************************************************************************/

#include "strutilstemplate.cpp"           /* Function Templates.              */
#include "strutils.cpp"                   /* Main Code.                       */
#endif