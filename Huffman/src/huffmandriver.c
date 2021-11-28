/**************************************************************************
 File name:		huffmandriver.c
 Author:			Cayden Wagner
 Date:				November 27 2021
 Class:				CS300 Data Structures
 Assignment:	Binary Tree
 Purpose:
 *************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include "../../ListADT/include/list.h"
#include "../../PriorityQueueADT/include/pqueue.h"
#include "../../BinaryTreeADT/include/binarytree.h"
#include "../include/huffman.h"

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
	HuffmanPtr psHuffman;
	puts("\nSUCCESS\n");
}
