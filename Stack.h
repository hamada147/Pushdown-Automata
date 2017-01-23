#ifndef CHARSTACK_H
#define CHARSTACK_H
using namespace std;

class CharStack
{
	private:
		// structre for the stack node
		struct StackNode
		{
			char value; // value in the node
			StackNode *next; // pointer to the next node
		};
		StackNode *top; // pointer to the stack top
	public:
		CharStack(); // Constructor
		~CharStack();
		void push(char); // Push element on stack
		bool pop(char &); // Pop element from stack
		bool isEmpty(void); // check if stack is empty
		char getTop();
};
#endif // !CHARSTACK_H