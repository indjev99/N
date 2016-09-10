#include "../headers/primitive_types.h"
#include "../headers/program_stack.h"

ProgramStack::Variable::Variable() {}
ProgramStack::Variable::Variable(int newType, bool newIsArray)
{
	type=newType;
	isArray=newIsArray;
}
void ProgramStack::Variable::set(const Variable& newValue, ProgramStack& programStack)
{
    if (newValue.type==REF_CODE || (type==REF_CODE && isArray) || (type!=REF_CODE &&
			(((type!=newValue.type && (type>=NUMBER_OF_PRIMITIVE_TYPES ||
			newValue.type>=NUMBER_OF_PRIMITIVE_TYPES))) || isArray!=newValue.isArray)))
	{
		//throw exception
		return;
	}

	if (type==REF_CODE)
	{
		*this=newValue;
	}
    else if (isArray)
	{
		int minMemCount=members[0];
		if (newValue.members[0]<minMemCount) minMemCount=newValue.members[0];
		for (Num i=0;i<minMemCount;++i)
		{
            programStack.copy(members[1]+i*members[2],newValue.members[1]+i*newValue.members[2]);
		}
	}
	else if (type>=NUMBER_OF_PRIMITIVE_TYPES && type==newValue.type)
	{
		for (size_t i=0;i<members.size();++i)
		{
			programStack.copy(members[i],newValue.members[i]);
		}
	}
	else
	{
        set_value(newValue.type,newValue.get_value(programStack),programStack);
	}
}
void ProgramStack::Variable::set_value(int otherType, ProgramStack::MemoryUnit newMemUnit, ProgramStack& programStack)
{
	if (type==REF_CODE)
	{
		//throw exception
		return;
	}
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
	if (type==REF_CODE)
	{
		//throw exception
		return MemoryUnit();
	}
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
	return members[1]+index*members[2];
}
int ProgramStack::Variable::get_member(size_t member) const
{
    if (member>=members.size() || type==REF_CODE || type<NUMBER_OF_PRIMITIVE_TYPES || isArray)
	{
		//throw exception
		return -1;
	}
	return members[member];
}
Bool ProgramStack::Variable::get_is_array() const
{
	return isArray;
}
Num ProgramStack::Variable::get_size() const
{
    if (!isArray)
	{
		//throw exception
		return -1;
	}
	return members[0];
}
int ProgramStack::Variable::get_type() const
{
    return type;
}

ProgramStack::Variable::~Variable() =default;
