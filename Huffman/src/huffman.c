/**************************************************************************
 File name:		  huffman.c
 Author:        Cayden Wagner
 Date:          11.27.2021
 Class:         CS300
 Assignment:    Binary Trees
 *************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../include/huffman.h"
/**************************************************************************
 Function: 	 	createTree

 Description: Creates the tree that represents the alphabet and its frequencies

 Parameters:	psHuffman - a pointer to a user-defined Huffman struct element

 Returned:	 	a pointer to the root node of the created tree
 *************************************************************************/
BTNodePtr createTree(HuffmanPtr psHuffman)
{
	const char SPACE_CHAR = '_';
	const int LETTERS_IN_ALPHABET = 26;
	const double FREQUENCIES[] = {.0622, .0132, .0311, .0297, .1053, .0168, .0165,
																.0363, .0614, .0007, .0031, .0307, .0248, .0573,
																.0606, .0189, .0010, .0587, .0581, .0768, .0227,
																.0070, .0113, .0025, .0107, .0005, .1821};

	char letter = 'a';
	BTNode sTemp;

	pqueueCreate(&(psHuffman->sPQueue));

	for (int i = 0; i < LETTERS_IN_ALPHABET; i++)
	{
		sTemp.character = letter;
		sTemp.key = FREQUENCIES[i];
		sTemp.psRightChild = sTemp.psLeftChild = NULL;
		pqueueEnqueue(&(psHuffman->sPQueue), &sTemp, sizeof(BTNode), sTemp.key);
		letter++;
	}

	sTemp.character = SPACE_CHAR;
	sTemp.key = FREQUENCIES[LETTERS_IN_ALPHABET];
	sTemp.psRightChild = sTemp.psLeftChild = NULL;
	pqueueEnqueue(&(psHuffman->sPQueue), &sTemp, sizeof(BTNode), sTemp.key);

	return psHuffman->psTree = generateTree(&(psHuffman->sPQueue));
}
/**************************************************************************
 Function: 	 	terminateHuffman

 Description: terminates all allocated data inside of the Huffman struct by
  						calling pqueueTerminate and freeTree

 Parameters:	psHuffman - a pointer to a user-defined Huffman struct element

 Returned:	 	none
 *************************************************************************/
void terminateHuffman (HuffmanPtr psHuffman)
{
	pqueueTerminate(&(psHuffman->sPQueue));
	freeTree(psHuffman->psTree);
}
/**************************************************************************
 Function:			decodeText

 Description:		decodes binary text from a text file into plain text using
 	 	 	 	 	 	 	 	the Huffman tree

 Parameters:		psHuffman - a pointer to a Huffman struct element
 	 	 	 	 	 	 	 	fPtr 			- a pointer to the input file

 Returned:			None
 *************************************************************************/
void decodeText (HuffmanPtr psHuffman, FILE *fPtr)
{
	const char NEW_LINE = '\n';
	char temp;
	BTNodePtr psTemp = psHuffman->psTree;
	FILE *fOutput;
	bool bError = false;

	fOutput = fopen("data/output.txt", "w");

	while (!feof(fPtr) && !bError)
	{
		fscanf(fPtr, "%c", &temp);

		if (NEW_LINE != temp)
		{
			if ('1' == temp)
			{
				psTemp = psTemp->psRightChild;
			}
			else if ('0' == temp)
			{
				psTemp = psTemp->psLeftChild;
			}
			else
			{
				printf("Error: Unknown character in the encoded file\n\n");
				bError = true;
			}

			if (isLeaf(psTemp))
			{
				if ('_' == psTemp->character)
				{
					fprintf(fOutput, "%c", ' ');
				}
				else
				{
					fprintf(fOutput, "%c", psTemp->character);
				}
				psTemp = psHuffman->psTree;
			}
		}
		else
		{
			fprintf(fOutput, "%c", NEW_LINE);
		}
	}
	fclose(fOutput);
}
/**************************************************************************
 Function:			findBinary

 Description:  	Searches the tree for a specified character and prints the
  							corresponding binary number to a file

 Parameters:		psRoot 		- a pointer to the root of the binary tree
 	 	 	 	 	 	 	 	character - the char variable that is searched for
 	 	 	 	 	 	 	 	arr 			- an array of integers that contains the final binary
 	 	 	 	 	 	 	 							result
 	 	 	 	 	 	 	 	fPtr      - a pointer to the input file

 Returned:			none
 *************************************************************************/
void findBinary(BTNodePtr psRoot, char character, int aBinary[], int top,
								FILE* fPtr)
{
	if (psRoot->psLeftChild) {
		aBinary[top] = 0;
		findBinary(psRoot->psLeftChild, character, aBinary, top + 1, fPtr);
	}

	if (psRoot->psRightChild) {
		aBinary[top] = 1;
		findBinary(psRoot->psRightChild, character, aBinary, top + 1, fPtr);
	}

	if (isLeaf(psRoot))
	{
		if (psRoot->character == character)
		{
			printArray(aBinary, top, fPtr);
		}
	}
}
/**************************************************************************
 Function:			printArray

 Description:		prints an array to the designated file

 Parameters:		arr - an array of integers that are printed
 	 	 	 	 	 	 	 	numElem - number of elements in the array
 	 	 	 	 	 	 	 	fPtr 		- a pointer to the input file

 Returned:			none
 *************************************************************************/
void printArray(int aBinary[], int numElem, FILE* fPtr)
{
	for (int i = 0; i < numElem; ++i)
	{
		fprintf(fPtr, "%d", aBinary[i]);
	}
}
/**************************************************************************
 Function:		isLeaf

 Description:	checks if a binary tree node is a leaf node or not

 Parameters:	psNode - the binary tree node that is checked

 Returned:		true if the node is a leaf node, else false
 *************************************************************************/
bool isLeaf(BTNodePtr psNode)
{
  return !(psNode->psLeftChild) && !(psNode->psRightChild);
}
/**************************************************************************
 Function:			encodeText

 Description:		encodes plain text data from the input file into compressed
  							binary form using the Huffman tree and prints it to the output
  							file

 Parameters:		psHuffman - a pointer to a user-defined Huffman struct element
 	 	 	 	 	 	 	 	fPtr 			- a pointer to the input file

 Returned:			none
 *************************************************************************/
void encodeText (HuffmanPtr psHuffman, FILE* fPtr)
{
	const char NEW_LINE = '\n';
	const int MAX_LEN = 11;
	int array[MAX_LEN];
	char temp;
	FILE *fOutput;

	fOutput = fopen("data/output.txt", "w");

	while (1)
	{
		fscanf(fPtr, "%c", &temp);
		if (feof(fPtr))
		{
			break;
		}
		if (temp == ' ')
		{
			temp = '_';
		}
		if (NEW_LINE == temp)
		{
			fprintf(fOutput, "%c", NEW_LINE);
		}
		else
		{
			findBinary(psHuffman->psTree, temp, array, 0, fOutput);
		}
	}
	fclose(fOutput);
}
