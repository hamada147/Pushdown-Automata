#include <iostream>
#include "Stack.h"
using namespace std;

CharStack::CharStack()
{
	top = NULL;
}

CharStack::~CharStack()
{
	StackNode *nodePtr, *nextNode;
	// position nodePtr at the top of the stack
	nodePtr = top;
	// traverse the list deleting each node
	while (nodePtr != NULL)
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
}

void CharStack::push(char item)
{
	StackNode *newNode; // pointer to a new node
						// allocate a new node and store num there.
	newNode = new StackNode;
	newNode->value = item;
	// if there are no nodes in the list
	// make newNode the first node.
	if (isEmpty())
	{
		top = newNode;
		newNode->next = NULL;
	}
	else // otherwise, insert NewNode before top
	{
		newNode->next = top;
		top = newNode;
	}
}

bool CharStack::pop(char &item)
{
	StackNode *temp; // temporary pointer
					 // first make sure the stack isn't empty
	if (isEmpty())
	{
		return false;
	}
	else // pop value off top of the stack
	{
		item = top->value;
		temp = top->next;
		delete top;
		top = temp;
		return true;
	}
}

bool CharStack::isEmpty(void)
{
	bool status;
	if (!top)
	{
		status = true;
	}
	else
	{
		status = false;
	}
	return status;
}

char CharStack::getTop()
{
	return top->value;
}