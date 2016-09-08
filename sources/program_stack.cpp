#include "../headers/primitive_types.h"
#include "../headers/program_stack.h"

#include<cstdint>

int ProgramStack::add_variable(int type, Num size)
{
	if (size<0)
	{
		//throw exception
		return -1;
	}
    int address=vars.size();
	vars.push_back({type,size});
	if (size)
	{
		vars[address].members.push_back(size);
		for (Num i=0;i<size;++i)
		{
            if (i==0)
			{
				vars[address].members.push_back(add_variable(type,0));
				vars[address].members.push_back(vars.size()-vars[address].members[0]);
			}
			else
			{
				add_variable(type,0);
			}
		}
	}
	else if (type>=NUMBER_OF_PRIMITIVE_TYPES)
	{
		std::vector<std::pair<int, Num>>& members=structs[type-NUMBER_OF_PRIMITIVE_TYPES].members;
		for (std::size_t i=0;i<members.size();++i)
		{
			//error somewhere around here
            vars[address].members.push_back(add_variable(members[i].first,members[i].second));
		}
	}
	else
	{
		vars[vars.size()-1].members.push_back(memory.size());
        ProgramStack::MemoryUnit currMemUnit;
        if (type==VOID_CODE) vars[vars.size()-1].members.resize(0);
        else
		{
			if (type==NUM_CODE) currMemUnit.numField=0;
			else if (type==CHAR_CODE) currMemUnit.charField=0;
			else if (type==REAL_CODE) currMemUnit.realField=0;
			else if (type==BOOL_CODE) currMemUnit.boolField=0;
			memory.push_back(currMemUnit);
		}
	}
    return address;
}
int ProgramStack::add_num(Num value)
{
	int address=add_variable(NUM_CODE,0);
	MemoryUnit newMemUnit;
	newMemUnit.numField=value;
	set_value(address,std::make_pair(NUM_CODE,newMemUnit));
	return address;
}
int ProgramStack::add_char(Char value)
{
	int address=add_variable(CHAR_CODE,0);
	MemoryUnit newMemUnit;
	newMemUnit.charField=value;
	set_value(address,std::make_pair(CHAR_CODE,newMemUnit));
	return address;
}
int ProgramStack::add_real(Real value)
{
	int address=add_variable(REAL_CODE,0);
	MemoryUnit newMemUnit;
	newMemUnit.realField=value;
	set_value(address,std::make_pair(REAL_CODE,newMemUnit));
	return address;
}
int ProgramStack::add_bool(Bool value)
{
	int address=add_variable(BOOL_CODE,0);
	MemoryUnit newMemUnit;
	newMemUnit.boolField=value;
	set_value(address,std::make_pair(BOOL_CODE,newMemUnit));
	return address;
}
int ProgramStack::add_text(std::string value)
{
	int address=add_variable(CHAR_CODE,value.size());
	MemoryUnit newMemUnit;
	for (int i=0;i<value.size();++i)
	{
		newMemUnit.charField=value[i];
		set_value(get_at_index(address,i),std::make_pair(CHAR_CODE,newMemUnit));
	}
	return address;
}
void ProgramStack::copy(int address1, int address2)
{
	vars[address1].set(vars[address2],*this);
}
void ProgramStack::set_value(int address, std::pair<int, MemoryUnit> newMemUnit)
{
    vars[address].set_value(newMemUnit.first,newMemUnit.second,*this);
}
std::pair<int, ProgramStack::MemoryUnit> ProgramStack::get_value(int address) const
{
    return std::make_pair(vars[address].type,vars[address].get_value(*this));
}
int ProgramStack::get_at_index(int address, Num index) const
{
	return vars[address].get_at_index(index);
}
int ProgramStack::get_member(int address, int member) const
{
	return vars[address].get_member(member);
}
Num ProgramStack::get_size(int address) const
{
    return vars[address].get_size();
}
void ProgramStack::push_scope()
{
    scopePosition.push(std::make_pair(vars.size(),memory.size()));
}
void ProgramStack::pop_scope()
{
	vars.resize(scopePosition.top().first);
	memory.resize(scopePosition.top().second);
	scopePosition.pop();
}
int ProgramStack::add_struct(std::vector<std::pair<int, Num>>& members)
{
	Struct newStruct;
	newStruct.members=members;
	structs.push_back(newStruct);
	return structs.size()-1;
}
ProgramStack::~ProgramStack() =default;
