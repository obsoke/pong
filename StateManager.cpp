#include "StateManager.hpp"

// declare static variables
StateManager* StateManager::instance_;

void StateManager::addState(State* s)
{
	states.push_back(s);
	current = s;
}
void StateManager::removeState(int index)
{
}

void StateManager::removeState(State* s)
{
	std::vector<State*>::iterator it;
	for (it = states.begin(); it < states.end(); ++it) {
		if (*it == s) delete *it;
	}
}

State* StateManager::getCurrentState()
{
	return current;
}

void StateManager::end()
{
    current = 0;
}

void StateManager::clearAll()
{
	std::vector<State*>::iterator it;
	for (it = states.begin(); it < states.end(); ++it) {
		delete *it;
	}
    current = 0;
}