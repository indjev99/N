#ifndef PROGRAM_STACK_H_INCLUDED
#define PROGRAM_STACK_H_INCLUDED

#include "../headers/primitive_types.h"
#include "../headers/struct.h"

#include<stack>
#include<string>
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
	class Variable
	{
	public:
		int type;
		bool isArray;
		std::vector<int> members;

		void set(const Variable& newVariable, ProgramStack& programStack);
		void set_value(int type, ProgramStack::MemoryUnit memUnit, ProgramStack& programStack);
		MemoryUnit get_value(const ProgramStack& programStack) const;
        int get_at_index(Num index) const;
        int get_member(int member) const;
        Num get_size() const;

		~Variable();
	};

	std::vector<Variable> vars;
	std::vector<MemoryUnit> memory;

	std::stack<std::pair<int, int>> scopePosition;

	std::vector<Struct> structs;

public:
	int add_variable(int type, Num size);

	int add_num(Num value);
	int add_char(Char value);
	int add_real(Real value);
	int add_bool(Bool value);
	int add_text(std::string value);

	void copy(int address1, int address2);
	void set_value(int address, std::pair<int, MemoryUnit> newMemUnit);
	std::pair<int, MemoryUnit> get_value(int address) const;

	int get_at_index(int address, Num index) const;
	int get_member(int address, int member) const;
	Num get_size(int address) const;

    void push_scope();
    void pop_scope();

    int add_struct(std::vector<std::pair<int, Num>>& members);

    ~ProgramStack();
};

#endif // PROGRAM_STACK_H_INCLUDED
