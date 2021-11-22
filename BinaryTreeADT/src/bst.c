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
	pqueueLoadErrorMessages ();
	lstLoadErrorMessages ();
}
/**************************************************************************
 Function:			createLeafNode

 Description:		allocates spaces for a BSTNode and inserts the given data

 Parameters:

 Returned:	 		a pointer to the created node
 *************************************************************************/
BSTNodePtr createNode()
{
	BSTNodePtr psTmp = NULL;
	psTmp = (BSTNodePtr) malloc (sizeof(BSTNode));
	return psTmp;
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
BSTNodePtr generateTree(PriorityQueuePtr psPQueue)
{
	const char INTERIOR_CHARACTER = '$';
	double buf;
	BSTNodePtr psTemp, psTemp2, psTmp;
	BSTNode sTemp, sTemp2;

	while (pqueueSize(psPQueue) > 1)
	{
		pqueueDequeue(psPQueue, &sTemp, sizeof(BSTNode), &buf);
		psTemp = createNode();
		memcpy(psTemp, &sTemp, sizeof(BSTNode));

		psTemp2 = (BSTNodePtr) pqueueDequeue(psPQueue, &sTemp2, sizeof(BSTNode), &buf);
		psTemp2 = createNode();
		memcpy(psTemp2, &sTemp2, sizeof(BSTNode));

		psTmp = createNode();
		psTmp->character = INTERIOR_CHARACTER;
		psTmp->key = sTemp.key + sTemp2.key;

		if (sTemp.key < sTemp2.key)
		{
			psTmp->psLeftChild = psTemp;
			psTmp->psRightChild = psTemp2;
		}
		else
		{
			psTmp->psRightChild = psTemp;
			psTmp->psLeftChild = psTemp2;
		}
		pqueueEnqueue(psPQueue, psTmp, sizeof(BSTNode), psTmp->key);
	}
	return pqueueDequeue(psPQueue, &sTemp, sizeof(BSTNode), &buf);
}
/**************************************************************************
 Function:			terminateTree

 Description:		frees all allocated data in the tree

 Parameters:		psRoot - a pointer to the root of the tree

 Returned:	 		None
 *************************************************************************/
void freeTree(BSTNodePtr psTree)
{
    if (!psTree) return;
    freeTree (psTree->psLeftChild);
    freeTree (psTree->psRightChild);
    free (psTree);
}
/**************************************************************************
 Function: 	 		bstPrintInorder

 Description:   Prints the Binary Search Tree in order

 Parameters:		psNode - pointer to the node

 Returned:	 		None
 *************************************************************************/
void bstPrintInorder (BSTNodePtr psNode) {
	if (psNode == NULL) {
		return;
	}
	bstPrintInorder (psNode->psLeftChild);
	fprintf (stderr, "(%g,%c)-", psNode->key, psNode->character);
	bstPrintInorder (psNode->psRightChild);
}


