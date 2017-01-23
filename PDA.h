#ifndef PDA_H
#define PDA_H
#include <string>
#include <list>
#include "Stack.h"
#include "PDATransition.h"
using namespace std;

class PDA
{
	public:
		// constractor
		/**
		* @list<string> Q: is a list of all the states {Q0, Q1, Q2, Q3, ...}
		* @list<char> Sigma: is a list of all the allowed letters in it
		* @list<PDATransition> Delta: is a list of all the transitions made in it
		* @list<string> FinalState: is a list of all the final states in it
		* @string Q0: is the name of the start state in it
		*
		*/
		PDA(list<string> q, list<char> sigma, list<PDATransition> delta, string q0, list<string> finalstate);
		// destructor
		~PDA();
		// check if the input was accepted or not
		void Accepts(string input);
	private:
		CharStack PDAStack; // the stack
		list<string> Q; // is a list of all the states {Q0, Q1, Q2, Q3, ...}
		list<char> Sigma; // is a list of all the allowed letters in it
		list<PDATransition> Delta; // is a list of all the transitions made in it
		list<string> FinalState; // is a list of all the final states in it
		string Q0; // is the name of the start state in it
		const char e = 'E';
};

#endif // !PDA_H#pragma once
