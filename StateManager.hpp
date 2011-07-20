#ifndef STATEMANAGER_HPP
#define STATEMANAGER_HPP
#include "state.hpp"
#include <vector>

class StateManager
{
public:
	static StateManager& Instance()
	{
		// lazy initialization
		if (instance_ == NULL) instance_ = new StateManager();
		
		return *instance_;
	}
	~StateManager()
	{
		delete instance_;
	}
	void addState(State* s);
	void removeState(int index);
	void removeState(State* s);
	void clearAll();
	State* getCurrentState();
	std::vector<State*> states;
private:
	StateManager() { } // private constructor; singleton class
	static StateManager* instance_;
	State* current;
};
#endif