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
/**************************************************************************
 Function:			createNode

 Description:		allocates spaces for a BSTNode and inserts the given data

 Parameters:		data - the char data that is stored in the created node
 	 	 	 	 	 	 	 	key  - the key probability that is assigned to the created
 	 	 	 	 	 	 	 				 node

 Returned:	 		a pointer to the created node
 *************************************************************************/
BSTNodePtr createNode(char data, double key)
{
	if (0 >= key)
	{
		processError ("createNode", ERROR_NONPOSITIVE_KEY);
	}
	BSTNodePtr psTemp = (BSTNodePtr) malloc(sizeof(BSTNode));
	psTemp->psLeftChild = psTemp->psRightChild = NULL;
	psTemp->key = key;
	psTemp->character = data;

	return psTemp;
}
/**************************************************************************
 Function:			combineNodes

 Description:		takes two nodes, creates a parent node for the two nodes,
  							and sets the left and right children of the new node to the
								nodes passed in

 Parameters:		psNode1 - a pointer to a node
 	 	 	 	 	 	 	 	psNode2 - a pointer to a node

 Returned:	 		a pointer to the created root
 *************************************************************************/
BSTNodePtr combineNodes(BSTNodePtr psNode1, BSTNodePtr psNode2)
{
	if (NULL == psNode1 || NULL == psNode2)
	{
		processError ("combineNodes", ERROR_NULL_NODE);
	}
	const char NULL_CHARACTER = '\0';
	double newKey = psNode1->key + psNode2->key;
	BSTNodePtr psRoot = createNode(NULL_CHARACTER, newKey);

	if (psNode1->key < psNode2->key)
	{
		psRoot->psLeftChild = psNode1;
		psRoot->psRightChild = psNode2;
	}
	else
	{
		psRoot->psLeftChild = psNode2;
		psRoot->psRightChild = psNode1;
	}
	return psRoot;
}
/**************************************************************************
 Function:			terminateTree

 Description:		frees all allocated data in the tree

 Parameters:		psRoot - a pointer to the root of the tree

 Returned:	 		None
 *************************************************************************/
void terminateTree(BSTNodePtr psRoot)
{
	if (NULL == psRoot)
	{
		processError ("terminateTree", ERROR_NULL_NODE);
	}
	if (NULL == psRoot)
	{
		return;
	}
	terminateTree(psRoot->psLeftChild);
	terminateTree(psRoot->psRightChild);

	free(psRoot);
}


