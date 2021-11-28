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

 Description:	A driver that guides the user through the process of using
 	 	 	 	 	 	 	the Huffman tree for printing, decoding, and encoding

 Parameters:	argc - the number of command line arguments
 	 	 	 	 	 	 	argv - the command line arguments

 Returned:	 	exit status
 *************************************************************************/
int main (int argc, char** argv)
{
	const char PRINT_OPTION[] = "-p";
	const char DECODE_OPTION[] = "-d";
	const char ENCODE_OPTION[] = "-e";
	FILE *fPtr;
	BTNodePtr psTree;
	Huffman sHuffman;

	BTLoadErrorMessages ();

	if (!(argc > 1))
	{
		printf("Error, expected data file in command line\n\n");
		return EXIT_FAILURE;
	}

	psTree = createTree(&sHuffman);

	if (strcmp(PRINT_OPTION, argv[1]) == 0)
	{
		BTPrintLeftSide(psTree, 0);
	}
	else if (strcmp(DECODE_OPTION, argv[1]) == 0)
	{
		printf("TODO:Decode option is not yet implemented\n");
	}
	else if (strcmp(ENCODE_OPTION, argv[1]) == 0)
	{
		printf("TODO:Encode option is not yet implemented\n");
	}
	else
	{
		printf("Invalid flag specified. You chose: %s.\n", argv[1]);
		printf("Known flags are:\n%s: Prints the Huffman tree on its side\n",
						PRINT_OPTION);
		printf("%s: Decodes the datafile containing the encoded message\n",
						DECODE_OPTION);
		printf("%s: Encodes the datafile containing the decoded message\n",
						ENCODE_OPTION);
	}

	terminateHuffman(&sHuffman);

	return EXIT_SUCCESS;
}
