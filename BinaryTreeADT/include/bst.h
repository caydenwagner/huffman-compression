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
#include "../../PriorityQueueADT/include/list.h"

//*************************************************************************
// Constants
//*************************************************************************
#define MAX_ERROR_LIST_CHARS 64

enum {NO_ERROR = 0,

	 };
#define NUMBER_OF_LIST_ERRORS ERROR_EMPTY_LIST - NO_ERROR + 1


//*************************************************************************
// Error Messages
//*************************************************************************
#define LOAD_LIST_ERRORS strcpy (gszListErrors[NO_ERROR], "No Error.");

//*************************************************************************
// User-defined types
//*************************************************************************

typedef struct BSTNode *BSTNode;
typedef struct BSTNode;
{

} BSTNode;

//*************************************************************************
// Allocation and Deallocation
//*************************************************************************


//*************************************************************************
// Checking number of elements in list
//*************************************************************************


//*************************************************************************
//												List Testing
//*************************************************************************


//*************************************************************************
//													Peek Operations
//*************************************************************************


//*************************************************************************
//							Updating current
//*************************************************************************


//*************************************************************************
//									Insertion, Deletion, and Updating
//*************************************************************************



#endif /* BST_H_ */
