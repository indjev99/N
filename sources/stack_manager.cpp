#include<../headers/primitive_types.h>
#include<../headers/stack_manager.h>

int ProgramStack::add_variable(int type, Num size)
{
	if (size<0)
	{
		//throw exception
		return;
	}
    int address=vars.size();
	vars.push_back({type,size});
	if (size)
	{
		for (Num i=0;i<size;++i)
		{
            if (i==0)
			{
				vars[address].members.push_back(add_variable(type,0));
				vars[address].step=vars.size()-vars[address].members[0];
			}
			else
			{
				add_variable(type,0);
			}
		}
	}
	else if (type>=NUMBER_OF_PRIMITIVE_TYPES)
	{
		vars[address].step=0;
		std::vector<std::pair<int,int>>& members=structs[type-NUMBER_OF_PRIMITIVE_TYPES].members;
		for (size_t i=0;i<members.size();++i)
		{
            vars[address].members.push_back(add_variable(members[i].first,members[i].second));
		}
	}
	else
	{
		vars[address].step=0;
		vars[vars.size()-1].members.push_back(memory.size());
        ProgramStack::MemoryUnit currMemUnit;
        switch(type)
        {
        	case VOID_CODE: vars[vars.size()-1].members.resize(0);break;
        	case NUM_CODE: currMemUnit.numField=0;break;
        	case CHAR_CODE: currMemUnit.charField=0;break;
        	case REAL_CODE: currMemUnit.realField=0;break;
        	case BOOL_CODE: currMemUnit.boolField=0;break;
        }
		memory.push_back(currMemUnit);
	}
    return address;
}
void ProgramStack::set_variable(int address, const Variable& newVariable)
{
    vars[address].set(newVariable,*this);
}
const Variable& ProgramStack::get_variable(int address) const
{
    return vars[address];
}
void ProgramStack::push_scope()
{
    scopePosition.push(make_pair(vars.size(),memory.size()));
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
