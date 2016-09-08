#ifndef STACK_MANAGER_H_INCLUDED
#define STACK_MANAGER_H_INCLUDED

#include "../headers/primitive_types.h"
#include "../headers/struct.h"
#include "../headers/variable.h"

#include<stack>
#include<vector>

class ProgramStack
{
public:
	union MemoryUnit
	{
		Num numField;
		Char charField;
		Real realField;
		Bool boolField;
	};

private:
	std::vector<Variable> vars;
	std::vector<MemoryUnit> memory;

	std::stack<std::pair<int, int>> scopePosition;

	std::vector<Struct> structs;

public:
	int add_variable(int type, Num size);
    void set_variable(int address, const Variable& newVariable);
    const Variable& get_variable(int address) const;
    void push_scope();
    void pop_scope();

    int add_struct(std::vector<std::pair<int, Num>>& members);

    ~ProgramStack();
};

#endif // STACK_MANAGER_H_INCLUDED
