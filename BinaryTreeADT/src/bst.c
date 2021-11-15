/**************************************************************************
 File name:		  bst.c
 Author:        Cayden Wagner
 Date:          11.15.2021
 Class:         CS300
 Assignment:    Binary Search Trees
 Purpose:
 *************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../include/bst.h"

char gszBSTErrors[NUMBER_OF_BST_ERRORS][MAX_ERROR_BST_CHARS];
/**************************************************************************
 Function: 	 		BSTLoadErrorMessages

 Description: 	Initializes the string of error messages. LOAD_BST_ERRORS is a
 	 	 	 					macro defined in the header file.

 Parameters:		None

 Returned:	 		None
 *************************************************************************/
void BSTLoadErrorMessages ()
{
	LOAD_BST_ERRORS
	pqueueLoadErrorMessages ();
	lstLoadErrorMessages ();

}

/**************************************************************************
 Function: 	 		processError

 Description:   Process the error code passed to this routine

 Parameters:		pszFunctionName - function causing the error
 	 	 	 					errorCode 	    - identifies the list error

 Returned:	 		None
 *************************************************************************/
static void processError (const char *pszFunctionName, int errorCode)
{
	printf ("Function: %s %s \n ", pszFunctionName,
			gszBSTErrors [errorCode]);
  exit (EXIT_FAILURE);
}
