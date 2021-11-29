/**************************************************************************
 File name:		  huffman.c
 Author:        Cayden Wagner
 Date:          11.27.2021
 Class:         CS300
 Assignment:    Binary Trees
 Purpose:
 *************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../include/huffman.h"
/**************************************************************************
 Function: 	 	createTree

 Description: Creates the tree that represents the alphabet and its frequencies

 Parameters:	psHuffman - a pointer to the user-defined Huffman struct

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

 Parameters:	psHuffman - a pointer to the user-defined Huffman struct

 Returned:	 	none
 *************************************************************************/
void terminateHuffman (HuffmanPtr psHuffman)
{
	pqueueTerminate(&(psHuffman->sPQueue));
	freeTree(psHuffman->psTree);
}
/**************************************************************************
 Function:

 Description:

 Parameters:

 Returned:
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
 Function:

 Description:

 Parameters:

 Returned:
 *************************************************************************/
void findBinary(BTNodePtr psRoot, char character, int arr[], int top, FILE* fPtr)
{
	if (psRoot->psLeftChild) {
		arr[top] = 0;
		findBinary(psRoot->psLeftChild, character, arr, top + 1, fPtr);
	}

	if (psRoot->psRightChild) {
		arr[top] = 1;
		findBinary(psRoot->psRightChild, character, arr, top + 1, fPtr);
	}

	if (isLeaf(psRoot))
	{
		if (psRoot->character == character)
		{
			printArray(arr, top, fPtr);
		}
	}
}
/**************************************************************************
 Function:

 Description:

 Parameters:

 Returned:
 *************************************************************************/
void printArray(int arr[], int numElem, FILE* fPtr)
{
	for (int i = 0; i < numElem; ++i)
	{
		fprintf(fPtr, "%d", arr[i]);
	}
}
/**************************************************************************
 Function:

 Description:

 Parameters:

 Returned:
 *************************************************************************/
bool isLeaf(BTNodePtr psRoot)
{
  return !(psRoot->psLeftChild) && !(psRoot->psRightChild);
}
/**************************************************************************
 Function:

 Description:

 Parameters:

 Returned:
 *************************************************************************/
void encodeText (HuffmanPtr psHuffman, FILE* fPtr)
{
	const char NEW_LINE = '\n';
	const int MAX_LEN = 11;
	int array[MAX_LEN];
	char temp;
	FILE *fOutput;

	fOutput = fopen("data/output.txt", "w");

	while (!feof(fPtr))
	{
		fscanf(fPtr, "%c", &temp);
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
