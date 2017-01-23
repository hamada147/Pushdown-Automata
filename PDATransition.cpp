#include "PDATransition.h"
#include <string>
#include <iostream>
using namespace std;
// constractor
PDATransition::PDATransition(string startState, char token, char poped, char pushed, string endState)
{
	// setting the data
	StartState = startState;
	Token = token;
	Poped = poped;
	Pushed = pushed;
	EndState = endState;
}
// destructor
PDATransition::~PDATransition()
{
	// clearing all the variables after finishing with each one of them
	// memory managment
	StartState.clear();
	Token = (char)0;
	Poped = (char)0;
	Pushed = (char)0;
	EndState.clear();
}

void PDATransition::setStartState(string startState)
{
	StartState = startState;
}

void PDATransition::setEndState(string endState)
{
	EndState = endState;
}

void PDATransition::setPoped(char poped)
{
	Poped = poped;
}

void PDATransition::setPushed(char pushed)
{
	Pushed = pushed;
}

void PDATransition::setToken(char token)
{
	Token = token;
}

string PDATransition::getStartState()
{
	return StartState;
}

string PDATransition::getEndState()
{
	return EndState;
}

char PDATransition::getToken()
{
	return Token;
}

char PDATransition::getPoped()
{
	return Poped;
}

char PDATransition::getPushed()
{
	return Pushed;
}

string PDATransition::toString()
{
	return "{(" + StartState + ")-(" + Token + ", " + Poped + ")->(" + Pushed + ")=>(" + EndState + ")}\n";
}
// the overloading cout operator 
ostream & operator<<(ostream & strm, const PDATransition & obj)
{
	strm << "{(" + obj.StartState + ")-(" + obj.Token + ", " + obj.Poped + ")->(" + obj.Pushed + ")=>(" + obj.EndState + ")}\n";
	return strm;
}