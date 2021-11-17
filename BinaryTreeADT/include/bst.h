/**************************************************************************
 File name:		bst.h
 Author:
 Date:
 Class:         CS300
 Assignment:
 Purpose:
 *************************************************************************/

#ifndef BST_H_
#define BST_H_

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "../../ListADT/include/list.h"
#include "../../PriorityQueueADT/include/pqueue.h"

//*************************************************************************
// Constants
//*************************************************************************
#define MAX_ERROR_BST_CHARS 64

enum {NO_BST_ERROR = 0,
			ERROR_NONPOSITIVE_KEY,
			ERROR_NULL_NODE,
		  ERROR_EMPTY_BST};
#define NUMBER_OF_BST_ERRORS ERROR_EMPTY_BST - NO_BST_ERROR + 1


//*************************************************************************
// Error Messages
//*************************************************************************
#define LOAD_BST_ERRORS strcpy (gszBSTErrors[NO_BST_ERROR], "No Error."); \
strcpy (gszBSTErrors[ERROR_NONPOSITIVE_KEY], "Key is non-positive"); \
strcpy (gszBSTErrors[ERROR_NULL_NODE], "Node is NULL"); \
strcpy (gszBSTErrors[ERROR_EMPTY_BST], "BST is empty.");

//*************************************************************************
// User-defined types
//*************************************************************************

typedef struct BSTNode *BSTNodePtr;
typedef struct BSTNode
{
	double key;
	char character;
	BSTNodePtr psLeftChild, psRightChild;
} BSTNode;

//*************************************************************************
// Allocation and Deallocation
//*************************************************************************

extern void BSTLoadErrorMessages ();

extern BSTNodePtr createNode(char, double);

extern BSTNodePtr combineNodes(BSTNodePtr, BSTNodePtr);

extern void terminateTree(BSTNodePtr psRoot);

#endif /* BST_H_ */

