#include <iostream>
#include <string>
#include <list>
#include "PDA.h"
#include "PDATransition.h"
#include "Stack.h"
using namespace std;

PDA::PDA(list<string> q, list<char> sigma, list<PDATransition> delta, string q0, list<string> finalstate)
{
	// setting the main data
	Q0 = q0;
	Q = list<string>(q);
	Sigma = list<char>(sigma);
	Delta = list<PDATransition>(delta);
	FinalState = list<string>(finalstate);
	PDAStack = CharStack();
	PDAStack.push('$');
}

PDA::~PDA()
{
	// clearing all the variables after finishing with each one of them
	// memory managment
	Q0.clear();
	Q.clear();
	Sigma.clear();
	Delta.clear();
	FinalState.clear();
}

void PDA::Accepts(string input)
{
	// prepare the input last item
	cout << "Input: " << input << endl;
	input = input + e;
	string currentState = Q0; // setting at the begging the start state
	string steps = ""; // contain all the steps taken so far
					   // the first loop go through the input string
	for (int i = 0, inputSize = input.length(); i < inputSize; i++)
	{
		// get the letter
		char letter = input.at(i);
		bool found = false; // use to know if we found a transition or not duing the for loop
							// search all transitions for a one that have the same 
							// start state, same letter, same pop result
		for (list<PDATransition>::iterator it = Delta.begin(); it != Delta.end(); it++)
		{
			if (it->getStartState() == currentState && it->getToken() == letter)
			{
				// letter, E => E
				if (it->getPoped() == e && it->getPushed() == e)
				{
					currentState = it->getEndState();
					steps += it->toString();
					found = true;
					break;
				}
				// letter, E => letter
				else if (it->getPoped() == e && it->getPushed() != e)
				{
					currentState = it->getEndState();
					PDAStack.push(it->getPushed());
					steps += it->toString();
					found = true;
					break;
				}
				// letter, letter => E
				else if (it->getPoped() != e && it->getPushed() == e)
				{
					// pop the letter first
					char popedChar;
					PDAStack.pop(popedChar);
					// if it is the same as the one in that transition
					if (it->getPoped() == popedChar)
					{
						currentState = it->getEndState();
						steps += it->toString();
						found = true;
						break;
					}
					// if it was something else; end the program
					else
					{
						// if there was no transition at all print the following instead
						if (steps.length() == 0)
						{
							steps = "This was the first transition and it failed\n";
						}
						// print that the input is wrong regarding this states
						// then print the steps taken so far if there was any
						cout << steps << "No transitions for current state and letter" << endl;
						return;
					}
				}
				// letter, letter => letter
				else if (it->getPoped() != e && it->getPushed() != e)
				{
					// pop the letter first
					char popedChar;
					PDAStack.pop(popedChar);
					// if it is the same as the one in that transition
					if (it->getPoped() == popedChar)
					{
						currentState = it->getEndState();
						PDAStack.push(it->getPushed());
						steps += it->toString();
						found = true;
						break;
					}
					// if it was something else; end the program
					else
					{
						// if there was no transition at all print the following instead
						if (steps.length() == 0)
						{
							steps = "This was the first transition and it failed\n";
						}
						// print that the input is wrong regarding this states
						// then print the steps taken so far if there was any
						cout << "FAILED" << endl;
						cout << steps << "No transitions for current state and letter" << endl;
						return;
					}
				}
			}
		}
		if (!found)
		{
			// if there was no transition at all print the following instead
			if (steps.length() == 0)
			{
				steps = "This was the first transition and it failed\n";
			}
			// print that the input is wrong regarding this states
			// then print the steps taken so far if there was any
			cout << "FAILED" << endl;
			cout << steps << "No transitions for current state and letter" << endl;
			return; // in order to exist the program
		}
	}
	// now check and see if the current state is one of the final states
	bool correct = false;
	for (list<string>::iterator it = FinalState.begin(); it != FinalState.end(); it++)
	{
		if (currentState == *it)
		{
			correct = true;
			break;
		}
	}
	if (correct)
	{
		cout << "CORRECT" << endl << steps;
	}
	else
	{
		cout << "FAILED" << endl << steps;
	}
}