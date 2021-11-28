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
void terminateHuffman(HuffmanPtr psHuffman)
{
	pqueueTerminate(&(psHuffman->sPQueue));
	freeTree(psHuffman->psTree);
}
