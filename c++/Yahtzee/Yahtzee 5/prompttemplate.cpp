/******************************************************************************/
/******************************************************************************/
/*                                                                            */
/*  prompttemplate.cpp --- Prompt Utilities,  Last Revised: November 20, 2000 */
/*                                                                            */
/*  PLEASE NOTE: prompt is in three parts due to the use of templates:        */
/*                                                                            */
/*              prompt.h -- the header file                                   */
/*              prompttemplate.cpp -- the code for the templated functions    */
/*              prompt.cpp -- the rest of the code                            */
/*                                                                            */
/*      Including prompt.h in your program will also include                  */
/*      prompttemplates.cpp -- make sure it's available.  Compiling           */
/*      prompt.cpp will include prompt.h and prompttemplates.cpp.             */
/*                                                                            */
/******************************************************************************/
/******************************************************************************/
/*                                                                            */
/*               ********** Pre-Processor Directives **********               */
/*                                                                            */
/******************************************************************************/

#include <typeinfo>                        /* Sys header provide std Type info*/

/******************************************************************************/
/******************************************************************************/
/*                                                                            */
/*                   ***** Program Level Definitions. *****                   */
/*                                                                            */
/******************************************************************************/

#define EMPTY ""                            /* Initialization constants.      */
#define BETWEEN " between "                 /* Message constants.             */
#define AND " and "                         /*    "         "                 */
#define I 'i'                               /*    "         "                 */
#define U 'u'                               /*    "         "                 */
#define AN "an "                            /*    "         "                 */
#define A "a "                              /*    "         "                 */

/******************************************************************************/
/******************************************************************************/
/*                                                                            */
/*         ********** Define All Functions and Procedures. **********         */
/*                                                                            */
/******************************************************************************/
/******************************************************************************/

template <class Type>
string RangePrompt(const string & prompt, const Type & low, const Type & high)
{
    /*  Precondition:   'prompt' is 1st part of prompt string, 'low' & 'high' */
    /*                  are same Type, with 'low' < 'high'.                   */
    /*  Postcondition:  Single string is returned combining 'prompt', between,*/
    /*                  'low', and, 'high'.                                   */

                          /**************************/

    return (prompt + BETWEEN + tostring(low) + AND + tostring(high));
}

/******************************************************************************/

template <class Type>
void OutOfRange(const Type & low, const Type & high)        /* Type range err.*/
{
    /*  Precondition:   'low' and 'high' are the same Type.                   */
    /*  Postcondition:  String 'typeName' is created with the name of the Type*/
    /*                  prefaced by "a " or "an " to be grammatically correct,*/
    /*                  then string is passed on to complete error message.   */

                /* Declare and initialize internal variable. */

    string typeName = typeid(low).name();            /* Get name of Type.     */

                          /**************************/

    if (I == typeName[0] || U == typeName[0]) typeName = AN + typeName;
    else typeName = A + typeName;                    /* Correct grammar, then */
    MustPrompt(RangePrompt(typeName, low, high));    /* ... pass it on.       */
}

/******************************************************************************/
/******************************************************************************/

template <class Type>
bool GetNum(Type & value)                  /* Get str w/ cin, convert to Type.*/
{
    /*  Precondition:   'value' is a defined Type.                            */
    /*  Postcondition:  Returns true iff user enters a valid num of type Type.*/
    /*                  'value' is converted num, or 0 if error occurred.     */

                /* Declare and initialize internal variable. */

    string str = EMPTY;                              /* Local str to get input*/

                          /**************************/

    return IsNum(CinStr(str), value);                /* Get str, convert, ret.*/
}

/******************************************************************************/

template <class Type>
Type GetNum(Type & value, bool & error)    /* Get str w/ cin, convert to Type.*/
{
    /*  Precondition:   'value' is a defined Type.                            */
    /*  Postcondition:  Returns converted value of user entered string if str */
    /*                  is valid Type, or 0 if error occurred (also = 'value')*/

                          /**************************/

    error = !GetNum(value);                          /* Get str, convert, OK? */
    return value;                                    /* Return value, too.    */
}

/******************************************************************************/

template <class Type>
Type PromptNum(const string & prompt, Type & value)/* Prompt, get Type -insist*/
{
    /*  Precondition:   prompt is string to present user, value = desired Type*/
    /*  Postcondition:  value is valid Type num, also returned.               */

                          /**************************/

    while (true)
    {
        EntryPrompt(prompt);                         /* Prompt user.          */
        if (GetNum(value)) return value;             /* If valid Type, return.*/
        NumError(typeid(value).name());              /* Else, error and repeat*/
    }
}

/******************************************************************************/

template <class Type>
Type PromptRange(const string & prompt, const Type & low, const Type & high)
{
    /*  Precondition:   prompt is string to present; low<=high = desired Type.*/
    /*  Postcondition:  Returns a Type value between low and high inclusive.  */

                /* Declare and initialize internal variable. */

    Type value = 0;                                /* Local numbr to get input*/

                          /**************************/

    while (true)
    {
        PromptNum(RangePrompt(prompt, low, high), value); /* Prompt user.     */
        if (low <= value && high >= value) return value;  /* If valid, return.*/
        OutOfRange(low, high);                            /* Else,error repeat*/
    }
}

/******************************************************************************/
/******************************************************************************/

template <class Type>
bool GetLineNum(Type & value)              /* Get str w/ get, convert to Type.*/
{
    /*  Precondition:   'value' is a defined Type.                            */
    /*  Postcondition:  Returns true iff user enters a valid num of type Type.*/
    /*                  'value' is converted num, or 0 if error occurred.     */

                /* Declare and initialize internal variable. */

    string str = EMPTY;                              /* Local str to get input*/

                          /**************************/

    return IsNum(GetLine(str), value);               /* Get str, convert, ret.*/
}

/******************************************************************************/

template <class Type>
Type GetLineNum(Type & value, bool & error)/* Get str w/ cin, convert to Type.*/
{
    /*  Precondition:   'value' is a defined Type.                            */
    /*  Postcondition:  Returns converted value of user entered string if str */
    /*                  is valid Type, or 0 if error occurred (also = 'value')*/

                          /**************************/

    error = !GetLineNum(value);                      /* Get str, convert, OK? */
    return value;                                    /* Return value, too.    */
}

/******************************************************************************/

template <class Type>
Type PromptLineNum(const string & prompt, Type & value)/* Prompt, Type -insist*/
{
    /*  Precondition:   prompt is string to present user, value = desired Type*/
    /*  Postcondition:  value is valid Type num, also returned.               */

                          /**************************/

    while (true)
    {
        EntryPrompt(prompt);                         /* Prompt user.          */
        if (GetLineNum(value)) return value;         /* If valid Type, return.*/
        NumError(typeid(value).name());              /* Else, error and repeat*/
    }
}

/******************************************************************************/

template <class Type>
Type PromptLineRange(const string & prompt, const Type &low, const Type &high)
{
    /*  Precondition:   prompt is string to present; low<=high = desired Type.*/
    /*  Postcondition:  Returns a Type value between low and high inclusive.  */

                /* Declare and initialize internal variable. */

    Type value = 0;                                /* Local numbr to get input*/

                          /**************************/

    while (true)
    {
        PromptLineNum(RangePrompt(prompt, low, high), value); /* Prompt user. */
        if (low <= value && high >= value) return value;    /*If valid, return*/
        OutOfRange(low, high);                            /* Else,error repeat*/
    }
}

/******************************************************************************/
/******************************************************************************/

template <class Type>
bool GetlnNum(Type & value)                /* Get str w/ cin, convert to Type.*/
{
    /*  Precondition:   'value' is a defined Type.                            */
    /*  Postcondition:  Returns true iff user enters a valid num of type Type.*/
    /*                  'value' is converted num, or 0 if error occurred.     */

                /* Declare and initialize internal variable. */

    string str = EMPTY;                              /* Local str to get input*/

                          /**************************/

    CinStr(str);                                     /* Get input from user.  */
    EatLine();                                       /* Trash rest of line.   */
    return IsNum(str, value);                        /* Convert, is valid?    */
}

/******************************************************************************/

template <class Type>
Type GetlnNum(Type & value, bool & error)  /* Get str w/ cin, convert to Type.*/
{
    /*  Precondition:   'value' is a defined Type.                            */
    /*  Postcondition:  Returns converted value of user entered string if str */
    /*                  is valid Type, or 0 if error occurred (also = 'value')*/

                          /**************************/

    error = !GetlnNum(value);                        /* Get str, convert, OK? */
    return value;                                    /* Return value, too.    */
}

/******************************************************************************/

template <class Type>
Type PromptlnNum(const string & prompt, Type & value)/* Prompt, Type - insist.*/
{
    /*  Precondition:   prompt is string to present user, value = desired Type*/
    /*  Postcondition:  value is valid Type num, also returned.               */

                          /**************************/

    while (true)
    {
        EntryPrompt(prompt);                         /* Prompt user.          */
        if (GetlnNum(value)) return value;           /* If valid Type, return.*/
        NumError(typeid(value).name());              /* Else, error and repeat*/
    }
}

/******************************************************************************/

template <class Type>
Type PromptlnRange(const string & prompt, const Type & low, const Type & high)
{
    /*  Precondition:   prompt is string to present; low<=high = desired Type.*/
    /*  Postcondition:  Returns a Type value between low and high inclusive.  */

                /* Declare and initialize internal variable. */

    Type value = 0;                                /* Local numbr to get input*/

                          /**************************/

    while (true)
    {
        PromptlnNum(RangePrompt(prompt, low, high), value);   /* Prompt user. */
        if (low <= value && high >= value) return value;    /*If valid, return*/
        OutOfRange(low, high);                            /* Else,error repeat*/
    }
}

/******************************************************************************/
/******************************************************************************/
/*                                                                            */
/*               *************** Final Cleanup. ***************               */
/*                                                                            */
/******************************************************************************/

#undef EMPTY                                /* Initialization constants.      */
#undef BETWEEN                              /* Message constants.             */
#undef AND                                  /*    "         "                 */
#undef I                                    /*    "         "                 */
#undef U                                    /*    "         "                 */
#undef AN                                   /*    "         "                 */
#undef A                                    /*    "         "                 */

/******************************************************************************/
/******************************************************************************/