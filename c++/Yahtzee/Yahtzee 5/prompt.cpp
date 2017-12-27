/******************************************************************************/
/******************************************************************************/
/*                                                                            */
/*  prompt.cpp  ---  Prompt Utilities        Last Revised: February 13, 2001  */
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

#define EMPTY ""                                /* Initialization constants.  */
#define SPACE_CHR ' '                           /*        "           "       */
#define NEWLINE '\n'                            /* Comparison constant.       */
#define Y 'y'                                   /*      "         "           */
#define RETURN "press return to continue ..."   /* Message constants.         */
#define COLON ": "                              /*    "        "              */
#define SORRY "\nI\'m sorry, "                  /*    "        "              */
#define TRY_AGAIN ".  Please try again.\n"      /*    "        "              */
#define NOT_VALID "that is not a valid "        /*    "        "              */
#define ENTRY " entry"                          /*    "        "              */
#define ENTER "you must enter "                 /*    "        "              */
#define YES_NO "\"yes\" or \"no\" (y/n)"        /*    "        "              */

/******************************************************************************/
/******************************************************************************/
/*                                                                            */
/*         ********** Define All Functions and Procedures. **********         */
/*                                                                            */
/******************************************************************************/
/******************************************************************************/

int GetCin()                               /* Get next chr in cin stream.     */
{
    /*  Precondition:   */
    /*  Postcondition:  */

                          /**************************/

    return cin.get();
}

/******************************************************************************/

int PeekCin()                              /* Look at next chr in cin stream. */
{
    /*  Precondition:   */
    /*  Postcondition:  */

                          /**************************/

    return cin.peek();
}

/******************************************************************************/

string CinStr(string & str)                /* Get string using cin.           */
{
    /*  Precondition:   */
    /*  Postcondition:  */

                          /**************************/

    cin >> str;
    return str;
}

/******************************************************************************/

void CoutStr(const string & str)           /* Output string w/ cout.          */
{
    /*  Precondition:   */
    /*  Postcondition:  */

                          /**************************/

    cout << str;
}

/******************************************************************************/

void WaitOnReturn()                        /* Prompt & wait for \n.           */
{
    /*  Precondition:   */
    /*  Postcondition:  */

                          /**************************/

    CoutStr(RETURN);
    EatLn();
}

/******************************************************************************/

void SkipPendingNewline()                  /* Remove "waiting" \n from stream.*/
{
    /*  Precondition:   */
    /*  Postcondition:  */

                          /**************************/

    while (isspace(PeekCin())) if(NEWLINE == GetCin()) break;
}

/******************************************************************************/

void WaitForReturn()                       /* Wait for \n & remove from stream*/
{
    /*  Precondition:   */
    /*  Postcondition:  */

                          /**************************/

    WaitOnReturn();
    SkipPendingNewline();
}

/******************************************************************************/

string AddGetLn(string & str)              /* Add input to str up to \n w/ cin*/
{
    /*  Precondition:   */
    /*  Postcondition:  */

                          /**************************/

    SkipPendingNewline();
    while (NEWLINE != PeekCin()) str += GetCin();
    return str;
}

/******************************************************************************/

string GetLn(string & str)                 /* AddGetLn, but clear str first.  */
{
    /*  Precondition:   */
    /*  Postcondition:  */

                          /**************************/

    str = EMPTY;
    return AddGetLn(str);
}

/******************************************************************************/

void EatLn()                               /* Trash cin stream up to next \n. */
{
    /*  Precondition:   */
    /*  Postcondition:  */

                /* Declare and initialize internal variable. */

    string dummy = EMPTY;                            /* Don't care about input*/

                          /**************************/

    GetLn(dummy);
}

/******************************************************************************/

void EatLine()                             /* EatLn iff not at \n already.    */
{
    /*  Precondition:   */
    /*  Postcondition:  */

                          /**************************/

    if (PeekCin() != NEWLINE) EatLn();
}

/******************************************************************************/

static void eatline()                      /* Trash line using system getline.*/
{
    /*  Precondition:   */
    /*  Postcondition:  */

                /* Declare and initialize internal variable. */

    string dummy = EMPTY;                            /* Don't care about input*/

                          /**************************/

    getline(cin,dummy);
}

/******************************************************************************/

string GetLine(string & str)               /* Get line of text using cin.     */
{
    /*  Precondition:   */
    /*  Postcondition:  */

                          /**************************/

    cin.seekg(0);                                    /* "Reset" cin buffer.   */
    cin.putback(NEWLINE);                            /* Put '\n' in buffer.   */

    return GetLn(str);
}

/******************************************************************************/
/******************************************************************************/

void Prompt(const string & str)            /* Output a string using cout.     */
{
    /*  Precondition:   */
    /*  Postcondition:  */

                          /**************************/

    CoutStr(str);
}

/******************************************************************************/

void EntryPrompt(const string & prompt)    /* Output prompt, space for entry. */
{
    /*  Precondition:   */
    /*  Postcondition:  */

                          /**************************/

    Prompt(prompt + COLON);
}

/******************************************************************************/

void TryAgain(const string & str)          /* Tell user to try again.         */
{
    /*  Precondition:   */
    /*  Postcondition:  */

                          /**************************/

    Prompt(SORRY + str + TRY_AGAIN);
}

/******************************************************************************/

void NumError(const string & str)          /* Numerical error msg.            */
{
    /*  Precondition:   */
    /*  Postcondition:  */

                           /**************************/

    TryAgain(NOT_VALID + str + ENTRY);
}

/******************************************************************************/

void MustPrompt(const string & str)        /* Tell user what they must enter. */
{
    /*  Precondition:   */
    /*  Postcondition:  */

                          /**************************/

    TryAgain(ENTER + str);
}

/******************************************************************************/

void YesNoError()                                            /* Yes/no error. */
{
    /*  Precondition:   */
    /*  Postcondition:  */

                          /**************************/

    MustPrompt(YES_NO);
}

/******************************************************************************/
/******************************************************************************/

int GetInt(bool & error)                   /* Get str w/ cin, convert to int. */
{
    /*  Precondition:   */
    /*  Postcondition:  */

                /* Declare and initialize internal variable. */

    int value = 0;                                   /* Local var to get numbr*/

                          /**************************/

    return GetNum(value, error);
}

/******************************************************************************/

long GetLong(bool & error)                 /* Get str w/ cin, convert to long.*/
{
    /*  Precondition:   */
    /*  Postcondition:  */

                /* Declare and initialize internal variable. */

    long value = 0;                                  /* Local var to get numbr*/

                          /**************************/

    return GetNum(value, error);
}

/******************************************************************************/

double GetDouble(bool & error)             /* Get str w/ cin, convert to doubl*/
{
    /*  Precondition:   */
    /*  Postcondition:  */

                /* Declare and initialize internal variable. */

    double value = 0;                                /* Local var to get numbr*/

                          /**************************/

    return GetNum(value, error);
}

/******************************************************************************/

int GetInt()                               /* Get str w/ cin, convert to int. */
{
    /*  Precondition:   */
    /*  Postcondition:  */

                /* Declare and initialize internal variable. */

    bool dummy = false;                              /* Don't care about error*/

                          /**************************/

    return GetInt(dummy);
}

/******************************************************************************/

long GetLong()                             /* Get str w/ cin, convert to long.*/
{
    /*  Precondition:   */
    /*  Postcondition:  */

                /* Declare and initialize internal variable. */

    bool dummy = false;                              /* Don't care about error*/

                          /**************************/

    return GetLong(dummy);
}

/******************************************************************************/

double GetDouble()                         /* Get str w/ cin, convert to doubl*/
{
    /*  Precondition:   */
    /*  Postcondition:  */

                /* Declare and initialize internal variable. */

    bool dummy = false;                              /* Don't care about error*/

                          /**************************/

    return GetDouble(dummy);
}

/******************************************************************************/

string PromptString(const string & prompt)       /* Prompt, get string.       */
// postcondition: returns string entered by user
{
    /*  Precondition:   */
    /*  Postcondition:  */

                /* Declare and initialize internal variable. */

    string str = EMPTY;                            /* Local str to get input. */

                          /**************************/

    EntryPrompt(prompt);
    return CinStr(str);
}

/******************************************************************************/

bool PromptYesNo(const string & prompt, string & response)  /* Prompt, get y/n*/
// postcondition: returns true iff user enters yes    
{
    /*  Precondition:   */
    /*  Postcondition:  */

                /* Declare and initialize internal variable. */

    char first = SPACE_CHR;                        /* Local chr to check input*/

                          /**************************/

    while(true)
    {
        response = PromptString(prompt);
        if (IsYesNo(response, first)) return (first == Y);
        YesNoError();
    }
}

/******************************************************************************/

bool PromptYesNo(const string & prompt)          /* Prompt, get y/n - insist. */
// postcondition: returns true iff user enters yes    
{
    /*  Precondition:   */
    /*  Postcondition:  */

                /* Declare and initialize internal variable. */

    string dummy = EMPTY;                          /* Local str to get input. */

                          /**************************/

    return PromptYesNo(prompt, dummy);
}

/******************************************************************************/
/******************************************************************************/

int GetLineInt(bool & error)               /* Get str w/ cin, convert to int. */
{
    /*  Precondition:   */
    /*  Postcondition:  */

                /* Declare and initialize internal variable. */

    int value = 0;                                   /* Local var to get numbr*/

                          /**************************/

    return GetLineNum(value, error);
}

/******************************************************************************/

long GetLineLong(bool & error)             /* Get str w/ cin, convert to long.*/
{
    /*  Precondition:   */
    /*  Postcondition:  */

                /* Declare and initialize internal variable. */

    long value = 0;                                  /* Local var to get numbr*/

                          /**************************/

    return GetLineNum(value, error);
}

/******************************************************************************/

double GetLineDouble(bool & error)         /* Get str w/ cin, convert to doubl*/
{
    /*  Precondition:   */
    /*  Postcondition:  */

                /* Declare and initialize internal variable. */

    double value = 0;                                /* Local var to get numbr*/

                          /**************************/

    return GetLineNum(value, error);
}

/******************************************************************************/

int GetLineInt()                           /* Get str w/ cin, convert to int. */
{
    /*  Precondition:   */
    /*  Postcondition:  */

                /* Declare and initialize internal variable. */

    bool dummy = false;                              /* Don't care about error*/

                          /**************************/

    return GetLineInt(dummy);
}

/******************************************************************************/

long GetLineLong()                         /* Get str w/ cin, convert to long.*/
{
    /*  Precondition:   */
    /*  Postcondition:  */

                /* Declare and initialize internal variable. */

    bool dummy = false;                              /* Don't care about error*/

                          /**************************/

    return GetLineLong(dummy);
}

/******************************************************************************/

double GetLineDouble()                     /* Get str w/ cin, convert to doubl*/
{
    /*  Precondition:   */
    /*  Postcondition:  */

                /* Declare and initialize internal variable. */

    bool dummy = false;                              /* Don't care about error*/

                          /**************************/

    return GetLineDouble(dummy);
}

/******************************************************************************/

string PromptLineString(const string & prompt)   /* Prompt, get string.       */
// postcondition: returns string entered by user
{
    /*  Precondition:   */
    /*  Postcondition:  */

                /* Declare and initialize internal variable. */

    string str = EMPTY;                            /* Local str to get input. */

                          /**************************/

    EntryPrompt(prompt);
    return GetLine(str);
}

/******************************************************************************/

bool PromptLineYesNo(const string & prompt, string & response)/* Prompt, y/n  */
// postcondition: returns true iff user enters yes    
{
    /*  Precondition:   */
    /*  Postcondition:  */

                /* Declare and initialize internal variable. */

    char first = SPACE_CHR;                        /* Local chr to check input*/

                          /**************************/

    while(true)
    {
        response = PromptLineString(prompt);
        if (IsYesNo(response, first)) return (first == Y);
        YesNoError();
    }
}

/******************************************************************************/

bool PromptLineYesNo(const string & prompt)      /* Prompt, get y/n - insist. */
// postcondition: returns true iff user enters yes    
{
    /*  Precondition:   */
    /*  Postcondition:  */

                /* Declare and initialize internal variable. */

    string dummy = EMPTY;                          /* Local str to get input. */

                          /**************************/

    return PromptLineYesNo(prompt, dummy);
}

/******************************************************************************/
/******************************************************************************/

int GetlnInt(bool & error)                 /* Get str w/ cin, convert to int. */
{
    /*  Precondition:   */
    /*  Postcondition:  */

                /* Declare and initialize internal variable. */

    int value = 0;                                   /* Local var to get numbr*/

                          /**************************/

    return GetlnNum(value, error);
}

/******************************************************************************/

long GetlnLong(bool & error)               /* Get str w/ cin, convert to long.*/
{
    /*  Precondition:   */
    /*  Postcondition:  */

                /* Declare and initialize internal variable. */

    long value = 0;                                  /* Local var to get numbr*/

                          /**************************/

    return GetlnNum(value, error);
}

/******************************************************************************/

double GetlnDouble(bool & error)           /* Get str w/ cin, convert to doubl*/
{
    /*  Precondition:   */
    /*  Postcondition:  */

                /* Declare and initialize internal variable. */

    double value = 0;                                /* Local var to get numbr*/

                          /**************************/

    return GetlnNum(value, error);
}

/******************************************************************************/

int GetlnInt()                             /* Get str w/ cin, convert to int. */
{
    /*  Precondition:   */
    /*  Postcondition:  */

                /* Declare and initialize internal variable. */

    bool dummy = false;                              /* Don't care about error*/

                          /**************************/

    return GetlnInt(dummy);
}

/******************************************************************************/

long GetlnLong()                           /* Get str w/ cin, convert to long.*/
{
    /*  Precondition:   */
    /*  Postcondition:  */

                /* Declare and initialize internal variable. */

    bool dummy = false;                              /* Don't care about error*/

                          /**************************/

    return GetlnLong(dummy);
}

/******************************************************************************/

double GetlnDouble()                       /* Get str w/ cin, convert to doubl*/
{
    /*  Precondition:   */
    /*  Postcondition:  */

                /* Declare and initialize internal variable. */

    bool dummy = false;                              /* Don't care about error*/

                          /**************************/

    return GetlnDouble(dummy);
}

/******************************************************************************/

string PromptlnString(const string & prompt)     /* Prompt, get string.       */
// postcondition: returns string entered by user
{
    /*  Precondition:   */
    /*  Postcondition:  */

                /* Declare and initialize internal variable. */

    string str = EMPTY;                            /* Local str to get input. */

                          /**************************/

    EntryPrompt(prompt);
    CinStr(str);
    EatLine();
    return str;
}

/******************************************************************************/

bool PromptlnYesNo(const string & prompt, string & response)/* Prompt, get y/n*/
// postcondition: returns true iff user enters yes    
{
    /*  Precondition:   */
    /*  Postcondition:  */

                /* Declare and initialize internal variable. */

    char first = SPACE_CHR;                        /* Local chr to check input*/

                          /**************************/

    while(true)
    {
        response = PromptlnString(prompt);
        if (IsYesNo(response, first)) return (first == Y);
        YesNoError();
    }
}

/******************************************************************************/

bool PromptlnYesNo(const string & prompt)        /* Prompt, get y/n - insist. */
// postcondition: returns true iff user enters yes    
{
    /*  Precondition:   */
    /*  Postcondition:  */

                /* Declare and initialize internal variable. */

    string dummy = EMPTY;                          /* Local str to get input. */

                          /**************************/

    return PromptlnYesNo(prompt, dummy);
}

/******************************************************************************/
/******************************************************************************/
/*                                                                            */
/*               *************** Final Cleanup. ***************               */
/*                                                                            */
/******************************************************************************/

#undef EMPTY                                    /* Initialization constants.  */
#undef SPACE_CHR                                /*        "           "       */
#undef NEWLINE                                  /* Comparison constant.       */
#undef Y                                        /*      "        "            */
#undef RETURN                                   /* Message constants.         */
#undef COLON                                    /*    "        "              */
#undef SORRY                                    /*    "        "              */
#undef TRY_AGAIN                                /*    "        "              */
#undef NOT_VALID                                /*    "        "              */
#undef ENTRY                                    /*    "        "              */
#undef ENTER                                    /*    "        "              */
#undef YES_NO                                   /*    "        "              */

/******************************************************************************/
/******************************************************************************/