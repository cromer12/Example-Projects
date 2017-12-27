#ifndef _PROMPTTEMPLATE_H
#define _PROMPTTEMPLATE_H

/******************************************************************************/
/******************************************************************************/
/*                                                                            */
/*  prompttemplate.h  ---  Prompt Utilities,  Last Revised: November 17, 2000 */
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
/*                                                                            */
/******************************************************************************/
/******************************************************************************/
/*                                                                            */
/******** Make Sure All Functions and Procedures Have Been Prototyped. ********/
/*                                                                            */
/******************************************************************************/
/******************************************************************************/

template <class Type>
string RangePrompt(const string &prompt, const Type & low, const Type & high);

    /*  Purpose:        To assemble a prompt to be used with the various      */
    /*                  versions of PromptRange.  A single string is assembled*/
    /*                  by concatenating 'prompt', " between ", 'low', " and "*/
    /*                  'high'.

    /*  Precondition:   'prompt' is 1st part of prompt string, 'low' & 'high' */
    /*                  are same Type, with 'low' < 'high'.                   */

    /*  Postcondition:  A single string is returned as per above.             */

                          /**************************/
/* Equivalent to:                                                             */
/*                                                                            */
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

/******************************************************************************/

template <class Type>
void OutOfRange(const Type & low, const Type & high);       /* Type range err.*/

    /*  Purpose:        To generate an error message letting the user know    */
    /*                  they must enter a Type between 'low' and 'high'.      */

    /*  Precondition:   'low' and 'high' are the same Type.                   */

    /*  Postcondition:  String is created with the name of the Type prefaced  */
    /*                  by "a " or "an " to be grammatically correct, then    */
    /*                  string is passed on to complete the error message.    */

                          /**************************/
/* Equivalent to:                                                             */
/*                                                                            */
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

/******************************************************************************/
/******************************************************************************/

template <class Type>
bool GetNum(Type & value);                 /* Get str w/ cin, convert to Type.*/

    /*  Purpose:        To accept a string input from the user, attempt to    */
    /*                  convert it to a Type number, and provide feed back    */
    /*                  as to whether the string was converted to a valid     */
    /*                  Type number.                                          */

    /*  Precondition:   'value' is a defined Type.                            */

    /*  Postcondition:  Returns true iff user enters a valid num of type Type.*/
    /*                  'value' is converted num, or 0 if error occurred.     */

                          /**************************/
/* Equivalent to:                                                             */
/*                                                                            */
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
/*void GetNum(long double & value);        /* Get str, conv to long double.   */
/*void GetNum(double & value);             /* Get str w/ cin, conv to double. */
/*void GetNum(float & value);              /* Get str w/ cin, conv to float   */
/*void GetNum(long & value);               /* Get str w/ cin, conv to long.   */
/*void GetNum(int & value);                /* Get str w/ cin, conv to int.    */
/*void GetNum(short & value);              /* Get str w/ cin, conv to short.  */
/*void GetNum(char & value);               /* Get str w/ cin, conv to char.   */
/*void GetNum(unsigned long & value);      /* Get str, conv to unsigned long. */
/*void GetNum(unsigned int & value);       /* Get str, conv to unsigned int.  */
/*void GetNum(unsigned short & value);     /* Get str, conv to unsigned short.*/
/*void GetNum(unsigned char & value);      /* Get str, conv to unsigned char. */
/*void GetNum(signed char & value);        /* Get str, conv to signed char.   */
/*void GetNum(bool & value);               /* Get str w/ cin, conv to bool.   */

/******************************************************************************/

template <class Type>
Type GetNum(Type & value, bool & error);   /* Get str w/ cin, convert to Type.*/

    /*  Purpose:        To accept a string input from the user, attempt to    */
    /*                  convert it to a Type number, and provide feed back    */
    /*                  as to whether the string was converted to a valid     */
    /*                  Type number.                                          */

    /*  Precondition:   'value' is a defined Type.                            */

    /*  Postcondition:  Returns converted value of user entered string (also  */
    /*                  passed back in 'value') if string is valid Type, or   */
    /*                  0 if an error occurred.  'error' is true is error     */
    /*                  occurred, or false otherwise.                         */

                          /**************************/
/* Equivalent to:                                                             */
/*                                                                            */
/*long double GetNum(long double & value, bool & error);    /* Get long double*/
/*double GetNum(double & value, bool & error);              /* Get double.    */
/*float GetNum(float & value, bool & error);                /* Get float      */
/*long GetNum(long & value, bool & error);                  /* Get long.      */
/*int GetNum(int & value, bool & error);                    /* Get int.       */
/*short GetNum(short & value, bool & error);                /* Get short.     */
/*char GetNum(char & value, bool & error);                  /* Get char.      */
/*unsigned long GetNum(unsigned long & value, bool & error);/* Get uns..d long*/
/*unsigned int GetNum(unsigned int & value, bool & error);  /* Get uns..d int.*/
/*unsigned short GetNum(unsigned short & value, bool & error);/* Get u..d shor*/
/*unsigned char GetNum(unsigned char & value, bool & error); /* Get uns..d chr*/
/*signed char GetNum(signed char & value, bool & error);     /* Get si..d char*/
/*bool GetNum(bool & value, bool & error);                   /* Get bool.     */
/*void GetNum(long double & value, bool & error);       /* Get long double.   */
/*void GetNum(double & value, bool & error);            /* Get double.        */
/*void GetNum(float & value, bool & error);             /* Get float          */
/*void GetNum(long & value, bool & error);              /* Get long.          */
/*void GetNum(int & value, bool & error);               /* Get int.           */
/*void GetNum(short & value, bool & error);             /* Get short.         */
/*void GetNum(char & value, bool & error);              /* Get char.          */
/*void GetNum(unsigned long & value, bool & error);     /* Get unsigned long. */
/*void GetNum(unsigned int & value, bool & error);      /* Get unsigned int.  */
/*void GetNum(unsigned short & value, bool & error);`   /* Get unsigned short.*/
/*void GetNum(unsigned char & value, bool & error);     /* Get unsigned char. */
/*void GetNum(signed char & value, bool & error);       /* Get signed char.   */
/*void GetNum(bool & value, bool & error);              /* Get bool.          */

/******************************************************************************/

template <class Type>
Type PromptNum(const string & prompt, Type & value);/* Prompt, get Type-insist*/

    /*  Purpose:        To prompt the user to input a number, and ensure that */
    /*                  the number input is of the type Type.  This routine   */
    /*                  will not return until a valid number is entered.      */

    /*  Precondition:   'prompt' is the string to present to the user, 'value'*/
    /*                  is the desired input Type.                            */

    /*  Postcondition:  A valid Type num is both returned and passed back     */
    /*                  in 'value'.                                           */

                          /**************************/
/* Equivalent to:                                                             */
/*                                                                            */
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

/******************************************************************************/

template <class Type>
Type PromptRange(const string & prompt, const Type & low, const Type & high);

    /*  Purpose:        To prompt the user to input a number, and ensure that */
    /*                  the number input is of the type Type, and is between  */
    /*                  'low' and 'high'.  This routine will not return until */
    /*                  a valid number is entered.                            */

    /*  Precondition:   'prompt' is the string to present to the user,        */
    /*                  'low' <= 'high' and are both the desired input Type.  */

    /*  Postcondition:  A valid Type num is both returned and passed back     */
    /*                  in 'value' that is between 'low' and 'high' inclusive.*/

                          /**************************/
/* Equivalent to:                                                             */
/*                                                                            */
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

/******************************************************************************/
/******************************************************************************/

template <class Type>
bool GetLineNum(Type & value);             /* Get str w/ cin, convert to Type.*/

    /*  Purpose:        To accept a string input from the user, attempt to    */
    /*                  convert it to a Type number, and provide feed back    */
    /*                  as to whether the string was converted to a valid     */
    /*                  Type number.                                          */

    /*  Precondition:   'value' is a defined Type.                            */

    /*  Postcondition:  Returns true iff user enters a valid num of type Type.*/
    /*                  'value' is converted num, or 0 if error occurred.     */

                          /**************************/
/* Equivalent to:                                                             */
/*                                                                            */
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
/*void GetLineNum(long double & value);    /* Get str, conv to long double.   */
/*void GetLineNum(double & value);         /* Get str w/ cin, conv to double. */
/*void GetLineNum(float & value);          /* Get str w/ cin, conv to float   */
/*void GetLineNum(long & value);           /* Get str w/ cin, conv to long.   */
/*void GetLineNum(int & value);            /* Get str w/ cin, conv to int.    */
/*void GetLineNum(short & value);          /* Get str w/ cin, conv to short.  */
/*void GetLineNum(char & value);           /* Get str w/ cin, conv to char.   */
/*void GetLineNum(unsigned long & value);  /* Get str, conv to unsigned long. */
/*void GetLineNum(unsigned int & value);   /* Get str, conv to unsigned int.  */
/*void GetLineNum(unsigned short & value); /* Get str, conv to unsigned short.*/
/*void GetLineNum(unsigned char & value);  /* Get str, conv to unsigned char. */
/*void GetLineNum(signed char & value);    /* Get str, conv to signed char.   */
/*void GetLineNum(bool & value);           /* Get str w/ cin, conv to bool.   */

/******************************************************************************/

template <class Type>
Type GetLineNum(Type & value, bool & error);/* Get str w/ cin, convert to Type*/

    /*  Purpose:        To accept a string input from the user, attempt to    */
    /*                  convert it to a Type number, and provide feed back    */
    /*                  as to whether the string was converted to a valid     */
    /*                  Type number.                                          */

    /*  Precondition:   'value' is a defined Type.                            */

    /*  Postcondition:  Returns converted value of user entered string (also  */
    /*                  passed back in 'value') if string is valid Type, or   */
    /*                  0 if an error occurred.  'error' is true is error     */
    /*                  occurred, or false otherwise.                         */

                          /**************************/
/* Equivalent to:                                                             */
/*                                                                            */
/*long double GetLineNum(long double & value, bool & error);   /* Get long dbl*/
/*double GetLineNum(double & value, bool & error);             /* Get double. */
/*float GetLineNum(float & value, bool & error);               /* Get float   */
/*long GetLineNum(long & value, bool & error);                 /* Get long.   */
/*int GetLineNum(int & value, bool & error);                   /* Get int.    */
/*short GetLineNum(short & value, bool & error);               /* Get short.  */
/*char GetLineNum(char & value, bool & error);                 /* Get char.   */
/*unsigned long GetLineNum(unsigned long & value, bool & error);/* Get u..d lg*/
/*unsigned int GetLineNum(unsigned int & value, bool & error); /* Get u..d int*/
/*unsigned short GetLineNum(unsigned short & value, bool & error);/* u..d shrt*/
/*unsigned char GetLineNum(unsigned char & value, bool & error);/* Get u..d ch*/
/*signed char GetLineNum(signed char & value, bool & error);   /* Get s..d chr*/
/*bool GetLineNum(bool & value, bool & error);                 /* Get bool.   */
/*void GetLineNum(long double & value, bool & error);   /* Get long double.   */
/*void GetLineNum(double & value, bool & error);        /* Get double.        */
/*void GetLineNum(float & value, bool & error);         /* Get float          */
/*void GetLineNum(long & value, bool & error);          /* Get long.          */
/*void GetLineNum(int & value, bool & error);           /* Get int.           */
/*void GetLineNum(short & value, bool & error);         /* Get short.         */
/*void GetLineNum(char & value, bool & error);          /* Get char.          */
/*void GetLineNum(unsigned long & value, bool & error); /* Get unsigned long. */
/*void GetLineNum(unsigned int & value, bool & error);  /* Get unsigned int.  */
/*void GetLineNum(unsigned short & value, bool & error);/* Get unsigned short.*/
/*void GetLineNum(unsigned char & value, bool & error); /* Get unsigned char. */
/*void GetLineNum(signed char & value, bool & error);   /* Get signed char.   */
/*void GetLineNum(bool & value, bool & error);          /* Get bool.          */

/******************************************************************************/

template <class Type>
Type PromptLineNum(const string & prompt, Type & value);/* Prompt, Type-insist*/

    /*  Purpose:        To prompt the user to input a number, and ensure that */
    /*                  the number input is of the type Type.  This routine   */
    /*                  will not return until a valid number is entered.      */

    /*  Precondition:   'prompt' is the string to present to the user, 'value'*/
    /*                  is the desired input Type.                            */

    /*  Postcondition:  A valid Type num is both returned and passed back     */
    /*                  in 'value'.                                           */

                          /**************************/
/* Equivalent to:                                                             */
/*                                                                            */
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

/******************************************************************************/

template <class Type>
Type PromptLineRange(const string &prompt, const Type &low, const Type &high);

    /*  Purpose:        To prompt the user to input a number, and ensure that */
    /*                  the number input is of the type Type, and is between  */
    /*                  'low' and 'high'.  This routine will not return until */
    /*                  a valid number is entered.                            */

    /*  Precondition:   'prompt' is the string to present to the user,        */
    /*                  'low' <= 'high' and are both the desired input Type.  */

    /*  Postcondition:  A valid Type num is both returned and passed back     */
    /*                  in 'value' that is between 'low' and 'high' inclusive.*/

                          /**************************/
/* Equivalent to:                                                             */
/*                                                                            */
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

/******************************************************************************/
/******************************************************************************/

template <class Type>
bool GetlnNum(Type & value);               /* Get str w/ cin, convert to Type.*/

    /*  Purpose:        To accept a string input from the user, attempt to    */
    /*                  convert it to a Type number, and provide feed back    */
    /*                  as to whether the string was converted to a valid     */
    /*                  Type number.                                          */

    /*  Precondition:   'value' is a defined Type.                            */

    /*  Postcondition:  Returns true iff user enters a valid num of type Type.*/
    /*                  'value' is converted num, or 0 if error occurred.     */

                          /**************************/
/* Equivalent to:                                                             */
/*                                                                            */
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
/*void GetlnNum(long double & value);      /* Get str, conv to long double.   */
/*void GetlnNum(double & value);           /* Get str w/ cin, conv to double. */
/*void GetlnNum(float & value);            /* Get str w/ cin, conv to float   */
/*void GetlnNum(long & value);             /* Get str w/ cin, conv to long.   */
/*void GetlnNum(int & value);              /* Get str w/ cin, conv to int.    */
/*void GetlnNum(short & value);            /* Get str w/ cin, conv to short.  */
/*void GetlnNum(char & value);             /* Get str w/ cin, conv to char.   */
/*void GetlnNum(unsigned long & value);    /* Get str, conv to unsigned long. */
/*void GetlnNum(unsigned int & value);     /* Get str, conv to unsigned int.  */
/*void GetlnNum(unsigned short & value);   /* Get str, conv to unsigned short.*/
/*void GetlnNum(unsigned char & value);    /* Get str, conv to unsigned char. */
/*void GetlnNum(signed char & value);      /* Get str, conv to signed char.   */
/*void GetlnNum(bool & value);             /* Get str w/ cin, conv to bool.   */

/******************************************************************************/

template <class Type>
Type GetlnNum(Type & value, bool & error); /* Get str w/ cin, convert to Type.*/

    /*  Purpose:        To accept a string input from the user, attempt to    */
    /*                  convert it to a Type number, and provide feed back    */
    /*                  as to whether the string was converted to a valid     */
    /*                  Type number.                                          */

    /*  Precondition:   'value' is a defined Type.                            */

    /*  Postcondition:  Returns converted value of user entered string (also  */
    /*                  passed back in 'value') if string is valid Type, or   */
    /*                  0 if an error occurred.  'error' is true is error     */
    /*                  occurred, or false otherwise.                         */

                          /**************************/
/* Equivalent to:                                                             */
/*                                                                            */
/*long double GetlnNum(long double & value, bool & error);     /* Get long dbl*/
/*double GetlnNum(double & value, bool & error);               /* Get double. */
/*float GetlnNum(float & value, bool & error);                 /* Get float   */
/*long GetlnNum(long & value, bool & error);                   /* Get long.   */
/*int GetlnNum(int & value, bool & error);                     /* Get int.    */
/*short GetlnNum(short & value, bool & error);                 /* Get short.  */
/*char GetlnNum(char & value, bool & error);                   /* Get char.   */
/*unsigned long GetlnNum(unsigned long & value, bool & error); /* Get u..d lng*/
/*unsigned int GetlnNum(unsigned int & value, bool & error);   /* Get u..d int*/
/*unsigned short GetlnNum(unsigned short & value, bool & error);/* un..d short*/
/*unsigned char GetlnNum(unsigned char & value, bool & error); /* Get u..d chr*/
/*signed char GetlnNum(signed char & value, bool & error);     /* Get s..d chr*/
/*bool GetlnNum(bool & value, bool & error);                   /* Get bool.   */
/*void GetlnNum(long double & value, bool & error);     /* Get long double.   */
/*void GetlnNum(double & value, bool & error);          /* Get double.        */
/*void GetlnNum(float & value, bool & error);           /* Get float          */
/*void GetlnNum(long & value, bool & error);            /* Get long.          */
/*void GetlnNum(int & value, bool & error);             /* Get int.           */
/*void GetlnNum(short & value, bool & error);           /* Get short.         */
/*void GetlnNum(char & value, bool & error);            /* Get char.          */
/*void GetlnNum(unsigned long & value, bool & error);   /* Get unsigned long. */
/*void GetlnNum(unsigned int & value, bool & error);    /* Get unsigned int.  */
/*void GetlnNum(unsigned short & value, bool & error);  /* Get unsigned short.*/
/*void GetlnNum(unsigned char & value, bool & error);   /* Get unsigned char. */
/*void GetlnNum(signed char & value, bool & error);     /* Get signed char.   */
/*void GetlnNum(bool & value, bool & error);            /* Get bool.          */

/******************************************************************************/

template <class Type>
Type PromptlnNum(const string & prompt, Type & value);/* Prompt, Type - insist*/

    /*  Purpose:        To prompt the user to input a number, and ensure that */
    /*                  the number input is of the type Type.  This routine   */
    /*                  will not return until a valid number is entered.      */

    /*  Precondition:   'prompt' is the string to present to the user, 'value'*/
    /*                  is the desired input Type.                            */

    /*  Postcondition:  A valid Type num is both returned and passed back     */
    /*                  in 'value'.                                           */

                          /**************************/
/* Equivalent to:                                                             */
/*                                                                            */
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

/******************************************************************************/

template <class Type>
Type PromptlnRange(const string &prompt, const Type & low, const Type & high);

    /*  Purpose:        To prompt the user to input a number, and ensure that */
    /*                  the number input is of the type Type, and is between  */
    /*                  'low' and 'high'.  This routine will not return until */
    /*                  a valid number is entered.                            */

    /*  Precondition:   'prompt' is the string to present to the user,        */
    /*                  'low' <= 'high' and are both the desired input Type.  */

    /*  Postcondition:  A valid Type num is both returned and passed back     */
    /*                  in 'value' that is between 'low' and 'high' inclusive.*/

                          /**************************/
/* Equivalent to:                                                             */
/*                                                                            */
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

/******************************************************************************/
/******************************************************************************/

#include "prompttemplate.cpp"
#endif