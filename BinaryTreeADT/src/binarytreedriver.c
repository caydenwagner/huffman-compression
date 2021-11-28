/**************************************************************************
 File name:		binarytreedriver.c
 Author:			Cayden Wagner
 Date:				November 27 2021
 Class:				CS300 Data Structures
 Assignment:	Binary Tree
 Purpose:			To test the functionality of the Binary Tree ADT
 *************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include "../../ListADT/include/list.h"
#include "../../PriorityQueueADT/include/pqueue.h"
#include "../include/binarytree.h"

/**************************************************************************
 Function: 	 	success

 Description: print a success message

 Parameters:	szStr - the message to print
 Returned:	 	none
 *************************************************************************/
static void success (char * szStr)
{
	printf ("SUCCESS: %s\n", szStr);
}

/**************************************************************************
 Function: 	 	failure

 Description: print a failure message

 Parameters:	szStr - the message to print
 Returned:	 	none
 *************************************************************************/
static void failure (char * szStr)
{
	printf ("FAILURE: %s\n", szStr);
	exit (EXIT_FAILURE);
}

/****************************************************************************
 Function: 	 	assert

 Description: if the expression is true, assert success; otherwise, assert
 	 	 	 	 	 	 	failure

 Parameters:	szStr - the message to print

 Returned:	 	none
 ****************************************************************************/
static void assert (bool bExpression, char *pTrue, char *pFalse)
{
	if (bExpression)
	{
		success (pTrue);
	}
	else
	{
		failure (pFalse);
	}
}
/**************************************************************************
 Function: 	 	main

 Description:	Tests the functionality of the Binary Tree ADT

 Parameters:	none

 Returned:	 	none
 *************************************************************************/

int main ()
{
	const int NUM_CHARS = 10;
	const double FREQUENCIES[] = {.20, .25, .15, .08, .07, .06, .05, .05, .05, .04};
	char firstChar = '0';
	BTNode sTemp;
	BTNodePtr psRoot;
	PriorityQueue sThePQueue;

	BTLoadErrorMessages ();

	pqueueCreate(&sThePQueue);

	for (int i = 0; i < NUM_CHARS; i++)
	{
		sTemp.character = firstChar;
		sTemp.key = FREQUENCIES[i];
		sTemp.psRightChild = sTemp.psLeftChild = NULL;
		pqueueEnqueue(&sThePQueue, &sTemp, sizeof(BTNode), sTemp.key);
		firstChar++;
	}

	psRoot = generateTree(&sThePQueue);
	assert(pqueueIsEmpty(&sThePQueue), "PQ is Empty", "PQ is NOT empty");

	BTPrintInorder(psRoot);

	printf("\n\n");

	BTPrintLeftSide(psRoot, 0);

	freeTree(psRoot);

	printf("Success\n\n");

	return 0;
}
