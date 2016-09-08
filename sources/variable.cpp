#include "../headers/primitive_types.h"
#include "../headers/program_stack.h"

void ProgramStack::Variable::set(const Variable& newVariable, ProgramStack& programStack)
{
    if ((type!=newVariable.type && (type>=NUMBER_OF_PRIMITIVE_TYPES ||
			newVariable.type>=NUMBER_OF_PRIMITIVE_TYPES)))
	{
		//throw exception
		return;
	}

    if (isArray)
	{
		int minMemCount=members[0];
		if (newVariable.members[0]<minMemCount) minMemCount=newVariable.members[0];
		for (Num i=0;i<minMemCount;++i)
		{
            programStack.copy(members[1]+i*members[2],newVariable.members[1]+i*newVariable.members[2]);
		}
	}
	else if (type==newVariable.type)
	{
		for (size_t i=0;i<members.size();++i)
		{
			programStack.copy(members[i],newVariable.members[i]);
		}
	}
	else
	{
        set_value(newVariable.type,newVariable.get_value(programStack),programStack);
	}
}
void ProgramStack::Variable::set_value(int otherType, ProgramStack::MemoryUnit newMemUnit, ProgramStack& programStack)
{
	if (type>=NUMBER_OF_PRIMITIVE_TYPES)
	{
		//throw exception
		return;
	}
	if (isArray)
	{
		//throw exception
		return;
	}
	if (type==VOID_CODE) return;
	if (type==NUM_CODE)
	{
		Num newValue;
		if (otherType==VOID_CODE) newValue=0;
		if (otherType==NUM_CODE) newValue=newMemUnit.numField;
		if (otherType==CHAR_CODE) newValue=newMemUnit.charField;
		if (otherType==REAL_CODE) newValue=newMemUnit.realField;
		if (otherType==BOOL_CODE) newValue=newMemUnit.boolField;
		programStack.memory[members[0]].numField=newValue;
	}
	if (type==REAL_CODE)
	{
		Real newValue;
		if (otherType==VOID_CODE) newValue=0;
		if (otherType==NUM_CODE) newValue=newMemUnit.numField;
		if (otherType==CHAR_CODE) newValue=newMemUnit.charField;
		if (otherType==REAL_CODE) newValue=newMemUnit.realField;
		if (otherType==BOOL_CODE) newValue=newMemUnit.boolField;
		programStack.memory[members[0]].realField=newValue;
	}
	if (type==CHAR_CODE)
	{
		Char newValue;
		if (otherType==VOID_CODE) newValue=0;
		if (otherType==NUM_CODE) newValue=newMemUnit.numField;
		if (otherType==CHAR_CODE) newValue=newMemUnit.charField;
		if (otherType==REAL_CODE) newValue=newMemUnit.realField;
		if (otherType==BOOL_CODE) newValue=newMemUnit.boolField;
		programStack.memory[members[0]].charField=newValue;
	}
	if (type==BOOL_CODE)
	{
		Bool newValue;
		if (otherType==VOID_CODE) newValue=0;
		if (otherType==NUM_CODE) newValue=newMemUnit.numField;
		if (otherType==CHAR_CODE) newValue=newMemUnit.charField;
		if (otherType==REAL_CODE) newValue=newMemUnit.realField;
		if (otherType==BOOL_CODE) newValue=newMemUnit.boolField;
		programStack.memory[members[0]].boolField=newValue;
	}
}
ProgramStack::MemoryUnit ProgramStack::Variable::get_value(const ProgramStack& programStack) const
{
	if (type>=NUMBER_OF_PRIMITIVE_TYPES)
	{
		//throw exception
		return MemoryUnit();
	}
	if (isArray)
	{
		//throw exception
		return MemoryUnit();
	}
	if (type==VOID_CODE)
	{
		//throw exception
		return MemoryUnit();
	}
	return programStack.memory[members[0]];
}
int ProgramStack::Variable::get_at_index(Num index) const
{
	if (!isArray || index>=members[0] || members[0]<0)
	{
		//throw exception
		return -1;
	}
	return members[1]+members[0]*members[2];
}
int ProgramStack::Variable::get_member(int member) const
{
    if (member>=members.size() || type<NUMBER_OF_PRIMITIVE_TYPES || isArray)
	{
		//throw exception
		return -1;
	}
	return members[member];
}
Num ProgramStack::Variable::get_size() const
{
    if (isArray)
	{
		return members[0];
	}
	return -1;
}

ProgramStack::Variable::~Variable() =default;
