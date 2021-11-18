/**************************************************************************
 File name:
 Author:
 Date:
 Class:
 Assignment:
 Purpose:
 *************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include "../include/bst.h"
#include "../../ListADT/include/list.h"
#include "../../PriorityQueueADT/include/pqueue.h"

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

 Description:

 Parameters:	none

 Returned:	 	none
 *************************************************************************/

int main ()
{
	const int NUM_CHARS = 10;
	const double FREQUENCIES[] = {.20, .25, .15, .08, .07, .06, .05, .05, .05, .04};
	char firstChar = '0';
	BSTNodePtr psTemp, psRoot;
	BSTNode sTemp, sTemp2;
	PriorityQueue sThePQueue;
	double buf;

	BSTLoadErrorMessages ();

	pqueueCreate(&sThePQueue);

	for (int i = 0; i < NUM_CHARS; i++)
	{
		psTemp = createNode(firstChar, FREQUENCIES[i]);
		pqueueEnqueue(&sThePQueue, psTemp, sizeof(BSTNode), psTemp->key);
		firstChar++;
	}

	while (pqueueSize(&sThePQueue) > 1)
	{
		pqueueDequeue(&sThePQueue, &sTemp, sizeof(BSTNode), &buf);
		pqueueDequeue(&sThePQueue, &sTemp2, sizeof(BSTNode), &buf);

		psRoot = combineNodes(&sTemp, &sTemp2);

		pqueueEnqueue(&sThePQueue, psRoot, sizeof(BSTNode), psRoot->key);
	}

	pqueueDequeue(&sThePQueue, psRoot, sizeof(BSTNode), &buf);

	bstPrintInorder(psRoot);

	terminateTree(psRoot);

	assert((1 == 1), "True", "False");

	printf("Success\n\n");
}
