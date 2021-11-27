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
	BSTNodePtr psRoot = NULL;
	psRoot = (BSTNodePtr) malloc (sizeof(BSTNode));
	return psRoot;
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
	BSTNodePtr psTemp, psTemp2, psRoot;
	BSTNode sTemp, sTemp2, sRoot;

	while (pqueueSize(psPQueue) > 1)
	{
		pqueueDequeue(psPQueue, &sTemp, sizeof(BSTNode), &buf);
		psTemp = createNode();
		memcpy(psTemp, &sTemp, sizeof(BSTNode));

		pqueueDequeue(psPQueue, &sTemp2, sizeof(BSTNode), &buf);
		psTemp2 = createNode();
		memcpy(psTemp2, &sTemp2, sizeof(BSTNode));

		sRoot.character = INTERIOR_CHARACTER;
		sRoot.key = sTemp.key + sTemp2.key;

		if (sTemp.key < sTemp2.key)
		{
			sRoot.psLeftChild = psTemp;
			sRoot.psRightChild = psTemp2;
		}
		else
		{
			sRoot.psRightChild = psTemp;
			sRoot.psLeftChild = psTemp2;
		}
		pqueueEnqueue(psPQueue, &sRoot, sizeof(BSTNode), sRoot.key);
	}

	pqueueDequeue(psPQueue, &sTemp2, sizeof(BSTNode), &buf);
	psRoot = createNode();
	memcpy(psRoot, &sTemp2, sizeof(BSTNode));

	return psRoot;
}
/**************************************************************************
 Function:			freeTree

 Description:		frees all allocated data in the tree

 Parameters:		psRoot - a pointer to the root of the tree

 Returned:	 		None
 *************************************************************************/
void freeTree(BSTNodePtr psTree)
{
	if (NULL == psTree)
	{
		return;
	}
	freeTree (psTree->psLeftChild);
	freeTree (psTree->psRightChild);
	printf("\nFreeing: (%g,%c)", psTree->key, psTree->character);
	free (psTree);
}
/**************************************************************************
 Function: 	 		bstPrintInorder

 Description:   Prints the Binary Search Tree in order

 Parameters:		psNode - pointer to the node

 Returned:	 		None
 *************************************************************************/
void bstPrintInorder (BSTNodePtr psNode) {
	if (NULL == psNode)
	{
		return;
	}
	bstPrintInorder (psNode->psLeftChild);
	printf ("(%g,%c)-", psNode->key, psNode->character);
	fflush(stdout);
	bstPrintInorder (psNode->psRightChild);
}
