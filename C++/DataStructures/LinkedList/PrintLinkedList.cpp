//============================================================================
// Name        : SimpleLinkedList.cpp
// Author      : andresf24
// Version     :
// Copyright   : Your copyright notice
// Description : Simple Link List
//============================================================================

/* Include libraries */
#include <iostream>

/* Include namespaces */
using namespace std;


/* Data Structures Declarations */

/* Structure node */
struct node
{
	/* Data */
	int d;

	/* Link to next node */
	struct node *next;
};

/* Methods Definitions */
/* Print Linked List */
void printLinkedList(node *p)
{
	/* Check that root is not null */
	if(p == NULL)
	{
		cout << "Error: Root is null" << endl;
		return;
	}

	cout << "Printing linked list values:" << endl;

	/* Go through list and print all nodes' values */
	while (p != NULL)
	{
		/* Print current's node vale */
		cout << p->d << endl;

		/* Point to next node */
		p = p->next;
	}
}

/* Main method */
int main()
{
	/* Print debug message */
	cout << "Simple linked list" << endl;

	/* Declare root of linked list */
	node *root;

	/* Allocate and assign root node */
	root = new node();
	root->d = 0;

	/* Create second node */
	root->next = new node();
	root->next->d = 1;

	/* Print linked list */
	printLinkedList(root);

	/* Return success */
	return 0;
}
