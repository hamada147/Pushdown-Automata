#include <iostream>
#include <list>
#include "PDA.h"
#include "PDATransition.h"
using namespace std;

void main()
{
	string Q0 = "q0"; // start state
	string q[] = { "q0", "q1", "q2", "q3" }; // the exisiting state
	char s[] = { 'a', 'b', 'c', 'd' }; // the existing letters
	PDATransition t[] =
	{
		// startState, token, poped, pushed, endState
		PDATransition("q0", 'a', 'E', 'E', "q1"),
		PDATransition("q1", 'b', 'E', 'b', "q1"),
		PDATransition("q1", 'c', 'E', 'E', "q2"),
		PDATransition("q2", 'd', 'b', 'E', "q2"),
		PDATransition("q2", 'E', '$', '$', "q3"),
	}; // all exisint transitions
	string f[] = { "q3" }; // the final states

						   /*this part don't change no matter what*/
	list<string> Q; // list of the states
	list<char> Sigma; // list of the letters
	list<PDATransition> Delta; // list of all avilable transitions
	list<string> FinalState; // list of all final states

	list<string>::iterator it1 = Q.begin(); // an iterator to save the states from the array to the list
	for (int i = 0, arraySize = sizeof(q) / sizeof(q[0]); i < arraySize; i++)
	{
		Q.insert(it1, q[i]); // inserting it into the list
	}

	list<char>::iterator it2 = Sigma.begin(); // an iterator to save the letters from the array to the list
	for (int i = 0, arraySize = sizeof(s) / sizeof(s[0]); i < arraySize; i++)
	{
		Sigma.insert(it2, s[i]); // inserting it into the list
	}

	list<PDATransition>::iterator it3 = Delta.begin(); // an iterator to save the letters from the array to the list
	for (int i = 0, arraySize = sizeof(t) / sizeof(t[0]); i < arraySize; i++)
	{
		Delta.insert(it3, t[i]); // inserting it into the list
	}

	list<string>::iterator it4 = FinalState.begin();
	for (int i = 0, arraySize = sizeof(f) / sizeof(f[0]); i < arraySize; i++)
	{
		FinalState.insert(it4, f[i]); // inserting it into the list
	}

	PDA x = PDA(Q, Sigma, Delta, Q0, FinalState);

	x.Accepts("abbbcdd");
	x.Accepts("ac");
	x.Accepts("abcd");
	x.Accepts("acd");
	x.Accepts("E");

	system("PAUSE");
}