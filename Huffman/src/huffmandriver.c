/**************************************************************************
 File name:		huffmandriver.c
 Author:			Cayden Wagner
 Date:				November 27 2021
 Class:				CS300 Data Structures
 Assignment:	Binary Tree
 Purpose:			To guide the user through the process of using the Huffman tree
  						for printing, decoding, and encoding
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
		printf("Error, expected command line arguments\n\n");
		return EXIT_FAILURE;
	}

	psTree = createTree(&sHuffman);

	if (strcmp(PRINT_OPTION, argv[1]) == 0)
	{
		BTPrintLeftSide(psTree, 0);
	}
	else if (strcmp(DECODE_OPTION, argv[1]) == 0)
	{
		if (argc > 2)
		{
			fPtr = fopen(argv[2], "r");
			decodeText(&sHuffman, fPtr);
			printf("Success: inputted data has been decoded.\n\n");
			fclose(fPtr);
		}
		else
		{
			printf("Error! Expected an input file in the command line\n\n");
		}
	}
	else if (strcmp(ENCODE_OPTION, argv[1]) == 0 && argc > 2)
	{
		if (argc > 2)
		{
			fPtr = fopen(argv[2], "r");
			encodeText(&sHuffman, fPtr);
			printf("Success: inputted data has been encoded.\n\n");
			fclose(fPtr);
		}
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
