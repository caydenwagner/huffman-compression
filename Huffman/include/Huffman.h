/**************************************************************************
 File name:			Huffman.h
 Author:				Cayden Wagner
 Date:					11.27.2021
 Class:         CS300
 Assignment:		Binary Tree
 Purpose:
 *************************************************************************/

#ifndef HUFFMAN_H_
#define HUFFMAN_H_

//*************************************************************************
// User-defined types
//*************************************************************************

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "../../ListADT/include/list.h"
#include "../../PriorityQueueADT/include/pqueue.h"
#include "../../BinaryTreeADT/include/binarytree.h"

typedef struct Huffman *HuffmanPtr;
typedef struct Huffman
{
		BTNodePtr psTree;
		PriorityQueuePtr psPQueue;
} Huffman;

#endif /* HUFFMAN_H_ */
