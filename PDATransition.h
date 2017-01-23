#ifndef PDATRANSITION_H
#define PDATRANSITION_H
#include <string>
using namespace std;

class PDATransition
{
	public:
		// constractor
		/**
		* @string StartState: the start state of this transition
		* @char Token: the letter that is being taken from state to another
		* @char Poped: the letter that is being cheked inside the stack and getting out
		* @char Pushed: the letter that is being written to the stack
		* @string EndState: the end state of this transition
		*
		*/
		PDATransition(string startState, char token, char poped, char pushed, string endState);
		// destructor
		~PDATransition();
		// the same as toString function
		string toString();
		// get functions
		string getStartState();
		string getEndState();
		char getToken();
		char getPoped();
		char getPushed();
		// overloading the cout << operator to work as toString() function
		// and since it has been identified as a friend it will have access
		// to private members
		friend ostream &operator << (ostream &strm, const PDATransition &obj);
	private:
		// setting the main variables as private so no one would have access to them
		// except from the get functions
		string StartState; // the start state of this transition
		char Token; // the letter that is being taken from state to another
		char Poped; // the letter that is being cheked inside the stack and getting out
		char Pushed; // the letter that is being written to the stack
		string EndState; // the end state of this transition
						 // the set function are also private because we don't want to change any of them
						 // except inside the class functions
		void setStartState(string);
		void setEndState(string);
		void setToken(char);
		void setPoped(char);
		void setPushed(char);
};
#endif // !PDATRANSITION_H