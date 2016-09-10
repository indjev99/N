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

		Variable();
		Variable(int newType, bool newIsArray);

		void set(const Variable& newValue, ProgramStack& programStack);
		void set_value(int type, ProgramStack::MemoryUnit memUnit, ProgramStack& programStack);
		MemoryUnit get_value(const ProgramStack& programStack) const;
		int get_at_index(Num index) const;
		int get_member(size_t member) const;
		Bool get_is_array() const;
		Num get_size() const;
		int get_type() const;

		~Variable();
	};

	std::vector<Variable> vars;
	std::vector<MemoryUnit> memory;

	std::vector<int> globalAddress;
	std::vector<std::stack<std::pair<int,int>>> scopeAddress;
	std::stack<int> restrictedScopes;
	std::stack<std::vector<int>> declaredAtScope;
	std::stack<int> returnAddress;

	std::stack<std::pair<int, int>> scopePosition;

	std::vector<Struct> structs;

	int size_of_type(int type, Num size) const;
	int primitive_size_of_type(int type, Num size) const;

public:
	ProgramStack();
	ProgramStack(int numOfVars);

	int add_variable(int id, int type, Num size=0);

	int add_num(Num value);
	int add_char(Char value);
	int add_real(Real value);
	int add_bool(Bool value);
	int add_text(std::string value);

	void copy(int address1, int address2);
	int perform_operation(int address1, std::pair<int, MemoryUnit>(*operation)(std::pair<int, MemoryUnit>));
	int perform_operation(int address1, int address2, std::pair<int, MemoryUnit>(*operation)(std::pair<int, MemoryUnit>, std::pair<int, MemoryUnit>));
	int modulus(int address1, int address2);
	void set_value(int address, std::pair<int, MemoryUnit> newMemUnit);
	std::pair<int, MemoryUnit> get_value(int address) const;

	int get_at_index(int address, Num index) const;
	int get_member(int address, int member) const;
	Bool get_is_array(int address) const;
	Num get_size(int address) const;
	int get_type(int address) const;

	void reset(int numOfVars);
    void push_scope(bool restricted=0, int type=0, Num size=0);
    int pop_scope(int address=-1);

private:
	int get_last_scope(int id) const;

public:
    int is_declared(int id) const;
    int get_address(int id) const;

    int add_struct(std::vector<std::pair<int, Num>>& members);

    ~ProgramStack();
};

#endif // PROGRAM_STACK_H_INCLUDED
