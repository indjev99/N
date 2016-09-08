#ifndef VARIABLE_H_INCLUDED
#define VARIABLE_H_INCLUDED

#include<../headers/stack_manager.h>
#include<vector>

class Variable
{
public:
	int type;
	Num size;
	int step;
	std::vector<int> members;

	void set(Variable& newVariable, ProgramStack& programStack);
	void set_value(int type, MemoryUnit memUnit, ProgramStack& programStack);
	ProgramStack::MemoryUnit get_value(const ProgramStack& programStack) const;

	~Variable();
};

#endif // VARIABLE_H_INCLUDED
