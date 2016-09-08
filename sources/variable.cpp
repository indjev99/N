#include<../headers/primitive_types.h>
#include<../headers/variable.h>

void Variable::set(const Variable& newVariable, ProgramStack& programStack)
{
    if (((type!=newVariable.type && (type>=NUMBER_OF_PRIMITIVE_TYPES ||
			newVariable.type>=NUMBER_OF_PRIMITIVE_TYPES))) || size!=newVariable.size())
	{
		//throw exception
		return;
	}

    if (size)
	{
		for (Num i=0;i<size;++i)
		{
            programStack.set_variable(members[0]+i*step,get_variable(newVariable.members[0]+i*newVariable.step));
		}
	}
	else if (type==newVariable.type)
	{
		for (size_t i=0;i<members.size();++i)
		{
			programStack.set_variable(members[i],newVariable.members[i]);
		}
	}
	else
	{
        set_value(newVariable.type,newVariable.get_value(programStack));
	}
}
void set_value(int otherType, ProgramStack::MemoryUnit newMemUnit)
{
	if (type==VOID_CODE) return;
	if (type==NUM_CODE)
	{
		Num newValue;
		switch (otherType)
		{
			case VOID_CODE: newValue=0;break;
			case NUM_CODE: newValue=newMemUnit.numField;break;
			case CHAR_CODE: newValue=newMemUnit.charField;break;
			case REAL_CODE: newValue=newMemUnit.realField;break;
			case BOOL_CODE: newValue=newMemUnit.boolField;break;
		}
		programStack.memory[members[0]].numField=newValue;
	}
	if (type==REAL_CODE)
	{
		Real newValue;
		switch (otherType)
		{
			case VOID_CODE: newValue=0;break;
			case NUM_CODE: newValue=newMemUnit.numField;break;
			case CHAR_CODE: newValue=newMemUnit.charField;break;
			case REAL_CODE: newValue=newMemUnit.realField;break;
			case BOOL_CODE: newValue=newMemUnit.boolField;break;
		}
		programStack.memory[members[0]].realField=newValue;
	}
	if (type==CHAR_CODE)
	{
		Char newValue;
		switch (otherType)
		{
			case VOID_CODE: newValue=0;break;
			case NUM_CODE: newValue=newMemUnit.numField;break;
			case CHAR_CODE: newValue=newMemUnit.charField;break;
			case REAL_CODE: newValue=newMemUnit.realField;break;
			case BOOL_CODE: newValue=newMemUnit.boolField;break;
		}
		programStack.memory[members[0]].charField=newValue;
	}
	if (type==BOOL_CODE)
	{
		Bool newValue;
		switch (otherType)
		{
			case VOID_CODE: newValue=0;break;
			case NUM_CODE: newValue=newMemUnit.numField;break;
			case CHAR_CODE: newValue=newMemUnit.charField;break;
			case REAL_CODE: newValue=newMemUnit.realField;break;
			case BOOL_CODE: newValue=newMemUnit.boolField;break;
		}
		programStack.memory[members[0]].boolField=newValue;
	}
}
ProgramStack::MemoryUnit get_value(const ProgramStack& programStack) const
{
	if (type==VOID_CODE)
	{
		//throw exception
		return MemoryUnit();
	}
	return programStack.memory[members[0]];
}

Variable::~Variable() =default;
