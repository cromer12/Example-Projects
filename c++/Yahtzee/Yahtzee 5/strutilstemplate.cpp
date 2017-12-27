/******************************************************************************/
/******************************************************************************/
/*                                                                            */
/*  strutilstemplate.cpp --- String Utilities,Last Revised: November 20, 2000 */
/*                                                                            */
/*                                                                            */
/*  PLEASE NOTE: strutils is in three parts due to the use of templates:      */
/*                                                                            */
/*              strutils.h -- the header file                                 */
/*              strutilstemplate.cpp -- the code for the templated functions  */
/*              strutils.cpp -- the rest of the code                          */
/*                                                                            */
/*      Including strutils.h in your program will also include                */
/*      strutilstemplates.cpp -- make sure it's available.  Compiling         */
/*      strutils.cpp will include strutils.h and strutilstemplates.cpp.       */
/*                                                                            */
/******************************************************************************/
/******************************************************************************/
/*                                                                            */
/*               ********** Pre-Processor Directives **********               */
/*                                                                            */
/******************************************************************************/

#include <sstream>                        /* Used by "tostring" type functions*/
#include <limits>                         /* System numeric limits header.    */
using namespace std;

/******************************************************************************/
/******************************************************************************/
/*                                                                            */
/*         ********** Define All Functions and Procedures. **********         */
/*                                                                            */
/******************************************************************************/
/******************************************************************************/

template <class Type>
string tostring(const Type & t)           /* Returns string equiv of a Type.  */
{
    /*  Precondition:   t == any Type.                                        */
    /*  Postcondition:  Return string equivalent of t, t is unchanged.        */

                /* Declare and initialize internal variable. */

    ostringstream output;                            /* 'output' = stream type*/

                          /**************************/

    output << t;                                     /* Direct 't' to 'output'*/   
    return output.str();                             /* Return constructed str*/
}

/******************************************************************************/

template <class Type>
void GetLimits(const Type & t, string & min, string & max)  /* Class min/max. */
{
    /*  Precondition:   t == a const of Type for which you want numeric limits*/
    /*  Postcondition:  String equiv of Type min / max num limits passed back.*/

                /* Declare and initialize internal variables. */

    ostringstream tempStream1;                       /* Output stream type.   */
    ostringstream tempStream2;                       /* Output stream type.   */

                          /**************************/

    tempStream1 << numeric_limits<Type>::min();      /* Direct min to stream. */
    min = tempStream1.str();                         /* Constructed str to min*/
    tempStream2 << numeric_limits<Type>::max();      /* Direct max to stream. */
    max = tempStream2.str();                         /* Constructed str to max*/
}

/******************************************************************************/

template <class Type>
bool IsNum(const string & str, Type & value)    /* True iff str valid Type.   */
{
    /*  Precondition:   str == any string of characters.                      */
    /*  Postcondition:  True is returned iff the string is valid Type number. */
    /*                  Number or 0 in 'value'.  The original string unchanged*/

                /* Declare and initialize internal variables. */

    biggestType bigValue = 0.0;                      /* Convert to biggest 1st*/
    bool valid = false;                              /* Error flag.           */

                          /**************************/

    valid = IsNum(str, bigValue);                    /* Convert to biggestType*/
    value = bigValue;                                /* Convert to number.    */
    if (bigValue != biggestType(value))
    {
        valid = false;                               /* Not same? Then str not*/
        value = 0;                                   /* valid Type, 2big/small*/
    }
    return valid;
}

/******************************************************************************/

template <class Type>
Type ToNum(const string & str, Type & value, bool & error) /*Type equiv of str*/
{
    /*  Precondition:   str == any string of characters.                      */
    /*  Postcondition:  Value is returned iff str is valid Type, else 0.      */
    /*                  Error is false iff str is valid Type.                 */

                          /**************************/

    error = ! IsNum(str, value);                     /* Convert to number.    */
    return value;                                    /* Return value.         */
}

/******************************************************************************/
/******************************************************************************/