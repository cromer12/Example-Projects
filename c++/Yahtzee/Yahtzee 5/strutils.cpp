/******************************************************************************/
/******************************************************************************/
/*                                                                            */
/*  strutils.cpp  ---  String Utilities      Last Revised: February 13, 2001  */
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
/******************************************************************************/
/*                                                                            */
/*               ********** Pre-Processor Directives **********               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
/******************************************************************************/
/*                                                                            */
/*                   ***** Program Level Definitions. *****                   */
/*                                                                            */
/******************************************************************************/

#define EMPTY ""                          /* Initialization constants.        */
#define SPACE_CHR ' '                     /*        "           "             */
#define NOT_FOUND string::npos            /* Comparison constants.            */
#define Y 'y'                             /*      "        "                  */
#define N 'n'                             /*      "        "                  */
#define DOT '.'                           /*      "        "                  */
#define BIG_D 'D'                         /*      "        "                  */
#define LITTLE_D 'd'                      /*      "        "                  */
#define BIG_E 'E'                         /*      "        "                  */
#define LITTLE_E 'e'                      /*      "        "                  */
#define MINUS '-'                         /*      "        "                  */
#define PLUS '+'                          /*      "        "                  */
#define ZERO_CHR '0'                      /*      "        "                  */
#define NINE_CHR '9'                      /*      "        "                  */
#define SPACE " "                         /* Used in CompressSpace.           */
#define MAX_NUM 32767                     /* Used in IsNum.                   */
#define MIN_NUM -32768                    /*   "   "   "                      */
#define BASE 10                           /* Used in IsNum.                   */
#define TWO 2                             /*   "   "   "                      */
#define NEG -1                            /*   "   "   "                      */
#define POS +1                            /*   "   "   "                      */

/******************************************************************************/
/******************************************************************************/
/*                                                                            */
/*         ********** Define All Functions and Procedures. **********         */
/*                                                                            */
/******************************************************************************/
/******************************************************************************/

string ToLower(string & str)              /* str changed to all lowercase.    */
{
    /*  Precondition:   str == any string of characters.                      */
    /*  Postcondition:  All uppercase characters in 'str' are lowercase.      */

                /* Declare and initialize internal variables. */

    int len = str.length();
    int index = 0;

                          /**************************/

    for (; index < len; index++) str[index] = tolower(str[index]);
	return str;
}

/******************************************************************************/

string LowerString(const string & str)    /* Return lowercase str.            */
{
    /*  Precondition:   str == any string of characters.                      */
    /*  Postcondition:  Return string: uppercase characters changed to lower. */

                /* Declare and initialize internal variable. */

    string copy = str;                               /* Copy str for local use*/

                          /**************************/

    return ToLower(copy);
}

/******************************************************************************/

string ToUpper(string & str)              /* str changed to all uppercase.    */
{
    /*  Precondition:   str == any string of characters.                      */
    /*  Postcondition:  All lowercase characters in 'str' are uppercase.      */

                /* Declare and initialize internal variables. */

    int len = str.length();
    int index = 0;

                          /**************************/

    for (; index < len; index++) str[index] = toupper(str[index]);
	return str;
}

/******************************************************************************/

string UpperString(const string & str)    /* Return uppercase str.            */
{
    /*  Precondition:   str == any string of characters.                      */
    /*  Postcondition:  Return string: lowercase characters changed to upper. */

                /* Declare and initialize internal variable. */

    string copy = str;                               /* Copy str for local use*/

                          /**************************/

    return ToUpper(copy);
}

/******************************************************************************/

string ToSwitchCase(string & str)         /* str lowercase/uppercase switched.*/
{
    /*  Precondition:   str == any string of characters.                      */
    /*  Postcondition:  All lowercase and uppercase chars in 'str' switched.  */

                /* Declare and initialize internal variables. */

    int len = str.length();
    int index = 0;

                          /**************************/

    for (; index < len; index++)
    {
        if (islower(str[index])) str[index] = toupper(str[index]);
        else str[index] = tolower(str[index]);
    }
	return str;
}

/******************************************************************************/

string SwitchCase(const string & str)     /* Return switched case str.        */
{
    /*  Precondition:   str == any string of characters.                      */
    /*  Postcondition:  Return string: lowercase and uppercase chars switched.*/

                /* Declare and initialize internal variable. */

    string copy = str;                               /* Copy str for local use*/

                          /**************************/

    return ToSwitchCase(copy);
}

/******************************************************************************/

string ToReverse(string & str)            /* Reverse str.                     */
{
    /*  Precondition:   str == any string of characters.                      */
    /*  Postcondition:  Referenced string is reversed.                        */

                /* Declare and initialize internal variables. */

    int index = str.length() - 1;                    /* Last chr of string.   */
    int index2 = 0;                                  /* First chr of copy.    */
    string copy = EMPTY;

                          /**************************/

    for (; index >= 0; index--, index2++) copy[index2] = str[index];
	str = copy;
    return str;
}

/******************************************************************************/

string ReverseString(const string & str)            /* Return reverse str.    */
{
    /*  Precondition:   str == any string of characters.                      */
    /*  Postcondition:  Return string is a reversed copy of 'str'.            */

                /* Declare and initialize internal variable. */

    string copy = str;                               /* Copy str for local use*/

                          /**************************/

    return ToReverse(copy);
}

/******************************************************************************/

bool IsYesNo(const string & str, char & firstChar)  /* True iff 1st char = y/n*/
{
    /*  Precondition:   str == any string of characters.                      */
    /*  Postcondition:  Returns true iff first char in 'str' is "y" or "n".   */

                /* Declare and initialize internal variable. */

    string copy = str;                               /* Copy str for local use*/

                          /**************************/

    StripWhite(copy);                                /* Ignore leading white. */
    firstChar = tolower(copy[0]);                    /* Change 1st chr toLower*/
    return (Y == firstChar || N == firstChar);       /* y/n?                  */
}

/******************************************************************************/

bool IsYesNo(const string & str)                    /* True iff 1st char = y/n*/
{
    /*  Precondition:   str == any string of characters.                      */
    /*  Postcondition:  Returns true iff first char in 'str' is "y" or "n".   */

                /* Declare and initialize internal variable. */

    char dummy = SPACE_CHR;                          /* Don't care 1st chr.   */

                          /**************************/

    return IsYesNo(str, dummy);
}

/******************************************************************************/

string StripPunc(string & str)            /* Remove leading/trailing punct.   */
{
    /*  Precondition:   str == any string of characters.                      */
    /*  Postcondition:  All leading and trailing punctuation is removed.      */

                /* Declare and initialize internal variables. */

    int first = 0;                                   /* Pointer for 1st chr.  */
    int len = str.length();                          /* Length of str.        */
    int last = len - 1;                              /* Pointer for last char.*/

                          /**************************/

          /* Move pointer 'first' to point to first non-punctuation */
          /* character in 'str'.  Then move pointer 'last' to point */
          /* to last non-punctuation character in 'str'. New string */
          /* is between pointers, and is (last + 1 - first) long.   */

    while ( (first < len) && ispunct(str[first]) ) first++;
    while ( (last > 0) && ispunct(str[last]) ) last--;

    str = str.substr(first, last+1-first);
	return str;
}

/******************************************************************************/

string StripWhite(string & str)           /* Remove leading/trailing white.   */
{
    /*  Precondition:   str == any string of characters.                      */
    /*  Postcondition:  All leading and trailing whitespace is removed.       */

                /* Declare and initialize internal variables. */

    int first = 0;                                   /* Pointer for 1st chr.  */
    int len = str.length();                          /* Length of str.        */
    int last = len - 1;                              /* Pointer for last char.*/

                          /**************************/

          /* Move pointer 'first' to point to first non-whitespace  */
          /* character in 'str'.  Then move pointer 'last' to point */
          /* to last non-whitespace character in 'str'. New string  */
          /* is between pointers, and is (last + 1 - first) long.   */

    while ( (first < len) && isspace(str[first]) ) first++;
    while ( (last > 0) && isspace(str[last]) ) last--;

    str = str.substr(first, last+1-first);
	return str;
}

/******************************************************************************/

string CompressString(string & str)       /* Condense and strip whitespace.   */
{
    /*  Precondition:   str == any string of characters.                      */
    /*  Postcondition:  Each occurrence of adjoining spaces is now one space, */
    /*                  and any leading or trailing spaces have been removed. */

                /* Declare and initialize internal variable. */

    int index = str.length() - 1;                    /* Last chr of string.   */

                          /**************************/

          /* Starting at the end of the string (so you'll have a    */
          /* fixed ending point -- the length of the string will be */
          /* changing) search for adjacent whitespace.  Each time   */
          /* it is found, erase the current character, and replace  */
          /* the next character with a single 'SPACE'.  Then, if    */
          /* necessary, erase the first and last character.         */

    for (; index > 0; index--)
    {
        if ((index != 0) && isspace(str[index]) && isspace(str[index-1]))
        {
            str.erase(index, 1);
            str.replace(index-1, 1, SPACE);
        }
    }
    if ((index>=0) && isspace(str[index])) str.erase(index, 1);  /* Check 1st.*/
    index = str.length() - 1;                                   /*Reset length*/
    if ((index>=0) && isspace(str[index])) str.erase(index, 1);  /* Check last*/
	return str;
}

/******************************************************************************/

string ftoa(const double & n)             /* Returns string equiv of double.  */
{
    /*  Precondition:   n == a valid double.                                  */
    /*  Postcondition:  Return string equivalent, number is unchanged.        */

                          /**************************/

    return tostring(n);
}

/******************************************************************************/

string ltoa(const long & n)               /* Returns string equiv of long.    */
{
    /*  Precondition:   n == a valid long.                                    */
    /*  Postcondition:  Return string equivalent, number is unchanged.        */

                          /**************************/

    return tostring(n);
}

/******************************************************************************/

string itoa(const int & n)                /* Returns string equiv of int.     */
{
    /*  Precondition:   n == a valid int.                                     */
    /*  Postcondition:  Return string equivalent, number is unchanged.        */

                          /**************************/

    return tostring(n);
}

/******************************************************************************/

bool IsNum(const string & str, biggestType & value)      /* T iff str valid bT*/
{
    /*  Precondition:   str == any string of characters.                      */
    /*  Postcondition:  True is returned iff the string is valid biggestType. */
    /*                  Number in 'value'.  The original string is unchanged. */

                /* Declare and initialize internal variables. */

    static int FIRST_TIME = 0;                       /* Flag - 1st time thru. */
    static int PRECISION  = MAX_NUM;                 /* Significant digits.   */
    static int MAX_EXP = MAX_NUM;                    /* Limits From System.   */
    static int MIN_EXP = MIN_NUM;                    /*    "     "     "      */
    static biggestType MAX_MANT = MAX_NUM;           /*    "     "     "      */
    static biggestType MIN_MANT = MIN_NUM;           /*    "     "     "      */
    string max = EMPTY;                              /*    "     "     "      */
    string min = EMPTY;                              /*    "     "     "      */

    char chr = SPACE_CHR;                            /* Current chr under exam*/
    int len = 0;                                     /* Length of string.     */
    int first = 0;                                   /* Pointer for 1st chr.  */
    int last = 0;                                    /* Pointer for last char.*/
    int index = 0;                                   /* String search index.  */
    int digit = 0;                                   /* Digit version of chr. */
    int mantDigits = 1;                              /* Num of mant digits.   */
    int mantSign = POS;                              /* Sign of mantissa.     */
    int expSign = POS;                               /* Sign of exponent.     */
    int exp = 0;                                     /* "Working" exponent.   */
    int mantExp =0;                                  /* For normalized mant.  */
    biggestType mant = 0.0;                          /* "Working" mantissa.   */
    biggestType divisor = 1.0;                       /* For mant right of DOT.*/
    biggestType expPart = 1.0;                       /* Final "working" exp.  */
    biggestType base = BASE;                         /* Used 4 exp & mant calc*/
    bool dotFound = false;                           /* Special chr flags.    */
    bool expFound = false;                           /*    "     "    "       */
    bool expDigitFound = false;                      /*    "   digit  "       */
    bool nonZeroExpDigitFound = false;               /*    "     "    "       */
    bool mantDigitFound = false;                     /*    "     "    "       */

                          /**************************/

          /* The first time this program is executed, string        */
          /* versions of the system limits for biggestType (see     */
          /* Program Level Definitions) are obtained.  The exponent */
          /* and mantissa parts of each limit are extracted and     */
          /* these are used as limits for the rest of the program's */
          /* life to verify that a string is within the system's    */
          /* limits for the largest internally supported Type.  The */
          /* exponent and mantissa parts of the string are compared */
          /* to these limits before final conversion to insure      */
          /* accuracy.  Also at this time, 'PRECISION' is           */
          /* determined by actually seeing how many digits the      */
          /* system can resolve.                                    */

    if (0 == FIRST_TIME)
    {
        FIRST_TIME = 1;

        GetLimits(mant, min, max);
        for (index = 0; index < max.length(); index++)
            if (BIG_E == max[index] || LITTLE_E == max[index])
            {
                MAX_EXP = atoi(max.substr(index+1, max.length()-index-1));
                MAX_MANT = atof(max.substr(0, index));
            }
        for (index = 0; index < min.length(); index++)
            if (BIG_E == min[index] || LITTLE_E == min[index])
            {
                MIN_EXP = atoi(min.substr(index+1, min.length()-index-1));
                MIN_MANT = atof(min.substr(0, index));
            }

        max = DOT;
        index = NEG;
        do
        {
            index++;
            min = max;
            max += NINE_CHR;
        }while (atof(min) != atof(max));
        PRECISION = index;
    }

                          /**************************/

          /* Move pointer 'first' to point to first non-whitespace  */
          /* character in 'str'.  Then move pointer 'last' to point */
          /* to last non-whitespace character in 'str'. Valid       */
          /* string is between pointers.                            */

    len = str.length();
    last = len - 1;
    while ((first < len) && ((chr = str[first]) == ' ' || chr == '\t'
        || chr == '\n' || chr == '\v' || chr == '\r' || chr == '\f')) first++;
    while ((last > 0) && ((chr = str[last]) == ' ' || chr == '\t'
        || chr == '\n' || chr == '\v' || chr == '\r' || chr == '\f')) last--;

          /* The valid portion of the referenced string is now      */
          /* scanned.  During scanning, all special characters are  */
          /* noted and digits are assembled into a mantissa and     */
          /* exponent.  If any invalid characters are found, or     */
          /* valid ones are found in an invalid location, the       */
          /* routine aborts.                                        */

    for (value = 0.0, index = first; index <= last; index++)
    {
        chr = str[index];

          /* If a DOT is found, there can only be one, and it must  */
          /* not be after the exponent symbol.                      */

        if (DOT == chr)
            if(dotFound) return false;
            else if (expFound) return false;
            else dotFound = true;

          /* If there is an EXP, there can only be one.             */

        else if (BIG_E == chr || LITTLE_E == chr ||
                 BIG_D == chr || LITTLE_D == chr)
            if (expFound) return false;
            else expFound = true;

          /* If there is a PLUS or MINUS sign, it must be either    */
          /* the first character, or immediately follow the EXP,    */
          /* or both.                                               */

        else if (MINUS == chr || PLUS == chr)
            if (first == index)
            {
                if (MINUS == chr) mantSign = NEG;
            }
            else if (BIG_E == str[index-1] || LITTLE_E == str[index-1] ||
                     BIG_D == str[index-1] || LITTLE_D == str[index-1])
            {
                if (MINUS == chr) expSign = NEG;
            }
            else return false;

          /* For digits, assemble them into a mantissa and exponent */
          /* as appropriate, to be able to more accurately complete */
          /* error checking, eg the exponent can be changed by the  */
          /* mantissa, depending on how it's entered.  10e1 == 1e10 */
          /* Pay close attention to exponent sign.                  */

        else if (ZERO_CHR <= chr && NINE_CHR >= chr)
        {
            digit = chr - ZERO_CHR;                      /* Change to number. */

            if (expFound)
            {
                if(!nonZeroExpDigitFound)
                {
                    expDigitFound = true;                /* Note leading 0's  */
                    if (0 != digit)                      /* of exp, but ignore*/
                    {
                        exp = digit;                     /* 1st non 0 this way*/
                        nonZeroExpDigitFound = true;     /* Rest, normal.     */
                    }
                }
                else exp = (exp * BASE) + digit;
            }

            else if (0 == mant)
            {
                if (dotFound) mantExp--;                 /* Note leading 0's  */
                mantDigitFound = true;                   /* of mant but ignore*/
                mant = digit;
            }
            else
            {
                if (!dotFound) mantExp++;                /* Ignore digits ... */
                if (mantDigits < PRECISION)              /* ... > resolution. */
                {
                    mant = (mant * BASE) + digit;        /* mantExp mantDigits*/
                    divisor *= BASE;                     /* & divisor used to */
                    mantDigits++;                        /* normalize later.  */
                }
            }
        }

        else return false;                               /* Invalid digit.    */
    }

          /* Now treat special cases.                               */
          /*     Without exp, you need at least 1 mant digit.       */
          /*     With exp, you need at least 1 exp digit.           */
          /*     With exp, 0 mant digits OK.  -e-1 == -1e-1 == -0.1 */
          /*     If mant still 0 now, value is 0 -- you're done!    */
          /*     If exp still 0 now, you haven't found a DOT, and   */
          /*         the number of digits is <= PRECISSION,         */
          /*         value = mant -- you're done!                   */

    if (!expFound)
    {
        if (!mantDigitFound) return false;
    }
    else
    {
        if (!expDigitFound) return false;
        if (!mantDigitFound) mant = 1;
    }

    if (0 == mant) return true;

    value = mantSign * mant;
    if (0 == exp && !dotFound && mantDigits < PRECISION) return true;
    else value = 0.0;

          /* Assemble corrected exponent with mantissa influence.   */

    exp = (expSign * exp) + mantExp;
    mant /= divisor;

          /* Now have normalized number to accurately compare to    */
          /* system limits.                                         */

    if (MIN_EXP > exp || MAX_EXP < exp) return false;
    if (MIN_EXP == exp && MIN_MANT > mant) return false;
    if (MAX_EXP == exp && MAX_MANT < mant) return false;

          /* If you get this far, you have to compute the exponent  */
          /* value.  As usual, the tricky part is to watch the sign!*/
          /* The trick - save it, compute power of a positive exp   */
          /* then invert 'expPart' if the sign was NEG.             */

    if (0 > exp)
    {
        expSign = NEG;
        exp *= NEG;                                      /* Make exp POS.     */
    }
    else expSign = POS;

    while (exp > 0)                      /* Invariant: expPart*(base^exp)=ans */
    {
        if ( exp % TWO != 0) expPart *= base;           /* exp is odd.        */
        exp /= TWO;                                     /* 4/2 == 2, 5/2 == 2 */
        base *= base;                                   /* (a*a)^(b/2) == a^b */
    }
    if (NEG == expSign) expPart = 1 / expPart;

    value = mantSign * mant * expPart;

    return true;                                         /* Actual number!    */
}

/******************************************************************************/

bool IsDouble(const string & str)               /* True iff str valid double. */
{
    /*  Precondition:   str == any string of characters.                      */
    /*  Postcondition:  True is returned iff the string is valid double.      */

                /* Declare and initialize internal variable. */

    double dummy = 0.0;                              /* Don't need value.     */

                          /**************************/

    return IsNum(str, dummy);
}

/******************************************************************************/

bool IsLong(const string & str)                 /* True iff str valid long.   */
{
    /*  Precondition:   str == any string of characters.                      */
    /*  Postcondition:  True is returned iff the string is valid long.        */

                /* Declare and initialize internal variable. */

    long dummy = 0;                                  /* Don't need value.     */

                          /**************************/

    return IsNum(str, dummy);
}

/******************************************************************************/

bool IsInt(const string & str)                  /* True iff str valid int.    */
{
    /*  Precondition:   str == any string of characters.                      */
    /*  Postcondition:  True is returned iff the string is valid int.         */

                /* Declare and initialize internal variable. */

    int dummy = 0;                                   /* Don't need value.     */

                          /**************************/

    return IsNum(str, dummy);
}

/******************************************************************************/

double atof(const string & str, bool & error)   /* Returns double w/ error.   */
{
    /*  Precondition:   str == any string of characters.                      */
    /*  Postcondition:  Returns double of 'str' and 'error' = false iff       */
    /*                  string is valid double.  Original string is unchanged.*/

                /* Declare and initialize internal variable. */

    double value = 0.0;

                          /**************************/

    return ToNum(str,value,error);
}

/******************************************************************************/

long atol(const string & str, bool & error)     /* Returns long w/ error.     */
{
    /*  Precondition:   str == any string of characters.                      */
    /*  Postcondition:  Returns long of 'str' and 'error' = false iff         */
    /*                  string is valid long.  Original string is unchanged.  */

                /* Declare and initialize internal variable. */

    long value = 0;

                          /**************************/

    return ToNum(str,value,error);
}

/******************************************************************************/

int atoi(const string & str, bool & error)      /* Returns int w/ error.      */
{
    /*  Precondition:   str == any string of characters.                      */
    /*  Postcondition:  Returns int of 'str' and 'error' = false iff          */
    /*                  string is valid int.  Original string is unchanged.   */

                /* Declare and initialize internal variable. */

    int value = 0;

                          /**************************/

    return ToNum(str,value,error);
}

/******************************************************************************/

double atof(const string & str)           /* Returns double equivalent of str.*/
{
    /*  Precondition:   str == any string of characters.                      */
    /*  Postcondition:  Returns double of 'str', original string is unchanged.*/

                /* Declare and initialize internal variable. */

    bool dummy = false;                              /* No error flag returned*/

                          /**************************/

    return atof(str, dummy);
}

/******************************************************************************/

long atol(const string & str)             /* Returns long equivalent of str.  */
{
    /*  Precondition:   str == any string of characters.                      */
    /*  Postcondition:  Returns long of 'str', original string is unchanged.  */

                /* Declare and initialize internal variable. */

    bool dummy = false;                              /* No error flag returned*/

                          /**************************/

    return atol(str, dummy);
}

/******************************************************************************/

int atoi(const string & str)              /* Returns int equivalent of str.   */
{
    /*  Precondition:   str == any string of characters.                      */
    /*  Postcondition:  Returns int of 'str', original string is unchanged.   */

                /* Declare and initialize internal variable. */

    bool dummy = false;                              /* No error flag returned*/

                          /**************************/

    return atoi(str, dummy);
}

/******************************************************************************/
/******************************************************************************/
/*                                                                            */
/*               *************** Final Cleanup. ***************               */
/*                                                                            */
/******************************************************************************/

#undef EMPTY                              /* Initialization constants.        */
#undef SPACE_CHR                          /*        "           "             */
#undef NOT_FOUND                          /* Comparison constants.            */
#undef Y                                  /*      "        "                  */
#undef N                                  /*      "        "                  */
#undef DOT                                /*      "        "                  */
#undef BIG_D                              /*      "        "                  */
#undef LITTLE_D                           /*      "        "                  */
#undef BIG_E                              /*      "        "                  */
#undef LITTLE_E                           /*      "        "                  */
#undef MINUS                              /*      "        "                  */
#undef PLUS                               /*      "        "                  */
#undef ZERO_CHR                           /*      "        "                  */
#undef NINE_CHR                           /*      "        "                  */
#undef SPACE                              /* Used in CompressSpace.           */
#undef MAX_NUM                            /* Used in IsNum.                   */
#undef MIN_NUM                            /*   "   "   "                      */
#undef BASE                               /* Used in IsNum.                   */
#undef TWO                                /*   "   "   "                      */
#undef NEG                                /*   "   "   "                      */
#undef POS                                /*   "   "   "                      */

/******************************************************************************/
/******************************************************************************/