/**************************************************************************
 File name:		  binarytree.c
 Author:        Cayden Wagner
 Date:          11.15.2021
 Class:         CS300
 Assignment:    Binary Trees
 Purpose:
 *************************************************************************/

#include "../include/binarytree.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/**************************************************************************
 Function: 	 		BTLoadErrorMessages

 Description: 	Initializes the string of error messages

 Parameters:		None

 Returned:	 		None
 *************************************************************************/
void BTLoadErrorMessages ()
{
	pqueueLoadErrorMessages ();
	lstLoadErrorMessages ();
}
/**************************************************************************
 Function:			createLeafNode

 Description:		allocates spaces for a BTNode and inserts the given data

 Parameters:

 Returned:	 		a pointer to the created node
 *************************************************************************/
BTNodePtr createNode()
{
	BTNodePtr psRoot = NULL;
	psRoot = (BTNodePtr) malloc (sizeof(BTNode));
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
BTNodePtr generateTree(PriorityQueuePtr psPQueue)
{
	const char INTERIOR_CHARACTER = '$';
	double buf;
	BTNodePtr psTemp, psTemp2, psRoot;
	BTNode sTemp, sTemp2, sRoot;

	while (pqueueSize(psPQueue) > 1)
	{
		pqueueDequeue(psPQueue, &sTemp, sizeof(BTNode), &buf);
		psTemp = createNode();
		memcpy(psTemp, &sTemp, sizeof(BTNode));

		pqueueDequeue(psPQueue, &sTemp2, sizeof(BTNode), &buf);
		psTemp2 = createNode();
		memcpy(psTemp2, &sTemp2, sizeof(BTNode));

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
		pqueueEnqueue(psPQueue, &sRoot, sizeof(BTNode), sRoot.key);
	}

	pqueueDequeue(psPQueue, &sTemp2, sizeof(BTNode), &buf);
	psRoot = createNode();
	memcpy(psRoot, &sTemp2, sizeof(BTNode));

	return psRoot;
}
/**************************************************************************
 Function:			freeTree

 Description:		frees all allocated data in the tree

 Parameters:		psRoot - a pointer to the root of the tree

 Returned:	 		None
 *************************************************************************/
void freeTree(BTNodePtr psTree)
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
 Function: 	 		BTPrintInorder

 Description:   Prints the Binary Search Tree in order

 Parameters:		psNode - pointer to the node

 Returned:	 		None
 *************************************************************************/
void BTPrintInorder (BTNodePtr psNode) {
	if (NULL == psNode)
	{
		return;
	}
	BTPrintInorder (psNode->psLeftChild);
	printf ("(%g,%c)-", psNode->key, psNode->character);
	fflush(stdout);
	BTPrintInorder (psNode->psRightChild);
}
