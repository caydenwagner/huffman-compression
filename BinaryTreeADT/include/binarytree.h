/**************************************************************************
 File name:			binarytree.h
 Author:				Cayden Wagner
 Date:					11.28.2021
 Class:         CS300
 Assignment:		Binary Trees
 Purpose:				To provide user-defined structs and functions that represents
  							the Binary Tree abstract data type
 *************************************************************************/

#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "../../ListADT/include/list.h"
#include "../../PriorityQueueADT/include/pqueue.h"

//*************************************************************************
// User-defined types
//*************************************************************************

typedef struct BTNode *BTNodePtr;
typedef struct BTNode
{
	double key;
	char character;
	BTNodePtr psLeftChild, psRightChild;
} BTNode;

extern void BTLoadErrorMessages ();

extern BTNodePtr createNode();

extern void freeTree(BTNodePtr);

extern BTNodePtr generateTree(PriorityQueuePtr psPQueue);

extern void BTPrintInorder (BTNodePtr);

void BTPrintLeftSide(BTNodePtr, int);

#endif /* BINARYTREE_H_ */

