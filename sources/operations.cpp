#include "../headers/operations.h"

std::pair<int,ProgramStack::MemoryUnit> addition(std::pair<int,ProgramStack::MemoryUnit> operand1, std::pair<int,ProgramStack::MemoryUnit> operand2)
{
	std::pair<int,ProgramStack::MemoryUnit> res;
    if (operand1.first==REF_CODE || operand1.first==VOID_CODE || operand1.first>=NUMBER_OF_PRIMITIVE_TYPES
			|| operand2.first==REF_CODE || operand2.first==VOID_CODE || operand2.first>=NUMBER_OF_PRIMITIVE_TYPES)
	{
		//throw exception
		return res;
	}
	if (operand1.first==NUM_CODE)
	{
		res.first=NUM_CODE;
		res.second.numField=operand1.second.numField;
		if (operand2.first==NUM_CODE) res.second.numField+=operand2.second.numField;
		if (operand2.first==CHAR_CODE) res.second.numField+=operand2.second.charField;
		if (operand2.first==REAL_CODE) res.second.numField+=operand2.second.realField;
		if (operand2.first==BOOL_CODE) res.second.numField+=operand2.second.boolField;
	}
	if (operand1.first==REAL_CODE)
	{
		res.first=REAL_CODE;
		res.second.realField=operand1.second.realField;
		if (operand2.first==NUM_CODE) res.second.realField+=operand2.second.numField;
		if (operand2.first==CHAR_CODE) res.second.realField+=operand2.second.charField;
		if (operand2.first==REAL_CODE) res.second.realField+=operand2.second.realField;
		if (operand2.first==BOOL_CODE) res.second.realField+=operand2.second.boolField;
	}
	if (operand1.first==CHAR_CODE)
	{
		res.first=CHAR_CODE;
		res.second.charField=operand1.second.charField;
		if (operand2.first==NUM_CODE) res.second.charField+=operand2.second.numField;
		if (operand2.first==CHAR_CODE) res.second.charField+=operand2.second.charField;
		if (operand2.first==REAL_CODE) res.second.charField+=operand2.second.realField;
		if (operand2.first==BOOL_CODE) res.second.charField+=operand2.second.boolField;
	}
	if (operand1.first==BOOL_CODE)
	{
		res.first=BOOL_CODE;
		res.second.boolField=operand1.second.boolField;
		if (operand2.first==NUM_CODE) res.second.boolField+=operand2.second.numField;
		if (operand2.first==CHAR_CODE) res.second.boolField+=operand2.second.charField;
		if (operand2.first==REAL_CODE) res.second.boolField+=operand2.second.realField;
		if (operand2.first==BOOL_CODE) res.second.boolField+=operand2.second.boolField;
	}
	return res;
}
std::pair<int,ProgramStack::MemoryUnit> subtraction(std::pair<int,ProgramStack::MemoryUnit> operand1, std::pair<int,ProgramStack::MemoryUnit> operand2)
{
	std::pair<int,ProgramStack::MemoryUnit> res;
    if (operand1.first==REF_CODE || operand1.first==VOID_CODE || operand1.first>=NUMBER_OF_PRIMITIVE_TYPES
			|| operand2.first==REF_CODE || operand2.first==VOID_CODE || operand2.first>=NUMBER_OF_PRIMITIVE_TYPES)
	{
		//throw exception
		return res;
	}
	if (operand1.first==NUM_CODE)
	{
		res.first=NUM_CODE;
		res.second.numField=operand1.second.numField;
		if (operand2.first==NUM_CODE) res.second.numField-=operand2.second.numField;
		if (operand2.first==CHAR_CODE) res.second.numField-=operand2.second.charField;
		if (operand2.first==REAL_CODE) res.second.numField-=operand2.second.realField;
		if (operand2.first==BOOL_CODE) res.second.numField-=operand2.second.boolField;
	}
	if (operand1.first==REAL_CODE)
	{
		res.first=REAL_CODE;
		res.second.realField=operand1.second.realField;
		if (operand2.first==NUM_CODE) res.second.realField-=operand2.second.numField;
		if (operand2.first==CHAR_CODE) res.second.realField-=operand2.second.charField;
		if (operand2.first==REAL_CODE) res.second.realField-=operand2.second.realField;
		if (operand2.first==BOOL_CODE) res.second.realField-=operand2.second.boolField;
	}
	if (operand1.first==CHAR_CODE)
	{
		res.first=CHAR_CODE;
		res.second.charField=operand1.second.charField;
		if (operand2.first==NUM_CODE) res.second.charField-=operand2.second.numField;
		if (operand2.first==CHAR_CODE) res.second.charField-=operand2.second.charField;
		if (operand2.first==REAL_CODE) res.second.charField-=operand2.second.realField;
		if (operand2.first==BOOL_CODE) res.second.charField-=operand2.second.boolField;
	}
	if (operand1.first==BOOL_CODE)
	{
		res.first=BOOL_CODE;
		res.second.boolField=operand1.second.boolField;
		if (operand2.first==NUM_CODE) res.second.boolField-=operand2.second.numField;
		if (operand2.first==CHAR_CODE) res.second.boolField-=operand2.second.charField;
		if (operand2.first==REAL_CODE) res.second.boolField-=operand2.second.realField;
		if (operand2.first==BOOL_CODE) res.second.boolField-=operand2.second.boolField;
	}
	return res;
}
std::pair<int,ProgramStack::MemoryUnit> multiplication(std::pair<int,ProgramStack::MemoryUnit> operand1, std::pair<int,ProgramStack::MemoryUnit> operand2)
{
	std::pair<int,ProgramStack::MemoryUnit> res;
    if (operand1.first==REF_CODE || operand1.first==VOID_CODE || operand1.first>=NUMBER_OF_PRIMITIVE_TYPES
			|| operand2.first==REF_CODE || operand2.first==VOID_CODE || operand2.first>=NUMBER_OF_PRIMITIVE_TYPES)
	{
		//throw exception
		return res;
	}
	if (operand1.first==NUM_CODE)
	{
		res.first=NUM_CODE;
		res.second.numField=operand1.second.numField;
		if (operand2.first==NUM_CODE) res.second.numField*=operand2.second.numField;
		if (operand2.first==CHAR_CODE) res.second.numField*=operand2.second.charField;
		if (operand2.first==REAL_CODE) res.second.numField*=operand2.second.realField;
		if (operand2.first==BOOL_CODE) res.second.numField*=operand2.second.boolField;
	}
	if (operand1.first==REAL_CODE)
	{
		res.first=REAL_CODE;
		res.second.realField=operand1.second.realField;
		if (operand2.first==NUM_CODE) res.second.realField*=operand2.second.numField;
		if (operand2.first==CHAR_CODE) res.second.realField*=operand2.second.charField;
		if (operand2.first==REAL_CODE) res.second.realField*=operand2.second.realField;
		if (operand2.first==BOOL_CODE) res.second.realField*=operand2.second.boolField;
	}
	if (operand1.first==CHAR_CODE)
	{
		res.first=CHAR_CODE;
		res.second.charField=operand1.second.charField;
		if (operand2.first==NUM_CODE) res.second.charField*=operand2.second.numField;
		if (operand2.first==CHAR_CODE) res.second.charField*=operand2.second.charField;
		if (operand2.first==REAL_CODE) res.second.charField*=operand2.second.realField;
		if (operand2.first==BOOL_CODE) res.second.charField*=operand2.second.boolField;
	}
	if (operand1.first==BOOL_CODE)
	{
		res.first=BOOL_CODE;
		res.second.boolField=operand1.second.boolField;
		if (operand2.first==NUM_CODE) res.second.boolField*=operand2.second.numField;
		if (operand2.first==CHAR_CODE) res.second.boolField*=operand2.second.charField;
		if (operand2.first==REAL_CODE) res.second.boolField*=operand2.second.realField;
		if (operand2.first==BOOL_CODE) res.second.boolField*=operand2.second.boolField;
	}
	return res;
}
std::pair<int,ProgramStack::MemoryUnit> division(std::pair<int,ProgramStack::MemoryUnit> operand1, std::pair<int,ProgramStack::MemoryUnit> operand2)
{
	std::pair<int,ProgramStack::MemoryUnit> res;
    if (operand1.first==REF_CODE || operand1.first==VOID_CODE || operand1.first>=NUMBER_OF_PRIMITIVE_TYPES
			|| operand2.first==REF_CODE || operand2.first==VOID_CODE || operand2.first>=NUMBER_OF_PRIMITIVE_TYPES)
	{
		//throw exception
		return res;
	}
	if (operand1.first==NUM_CODE)
	{
		res.first=NUM_CODE;
		res.second.numField=operand1.second.numField;
		if (operand2.first==NUM_CODE) res.second.numField/=operand2.second.numField;
		if (operand2.first==CHAR_CODE) res.second.numField/=operand2.second.charField;
		if (operand2.first==REAL_CODE) res.second.numField/=operand2.second.realField;
		if (operand2.first==BOOL_CODE) res.second.numField/=operand2.second.boolField;
	}
	if (operand1.first==REAL_CODE)
	{
		res.first=REAL_CODE;
		res.second.realField=operand1.second.realField;
		if (operand2.first==NUM_CODE) res.second.realField/=operand2.second.numField;
		if (operand2.first==CHAR_CODE) res.second.realField/=operand2.second.charField;
		if (operand2.first==REAL_CODE) res.second.realField/=operand2.second.realField;
		if (operand2.first==BOOL_CODE) res.second.realField/=operand2.second.boolField;
	}
	if (operand1.first==CHAR_CODE)
	{
		res.first=CHAR_CODE;
		res.second.charField=operand1.second.charField;
		if (operand2.first==NUM_CODE) res.second.charField/=operand2.second.numField;
		if (operand2.first==CHAR_CODE) res.second.charField/=operand2.second.charField;
		if (operand2.first==REAL_CODE) res.second.charField/=operand2.second.realField;
		if (operand2.first==BOOL_CODE) res.second.charField/=operand2.second.boolField;
	}
	if (operand1.first==BOOL_CODE)
	{
		res.first=BOOL_CODE;
		res.second.boolField=operand1.second.boolField;
		if (operand2.first==NUM_CODE) res.second.boolField/=operand2.second.numField;
		if (operand2.first==CHAR_CODE) res.second.boolField/=operand2.second.charField;
		if (operand2.first==REAL_CODE) res.second.boolField/=operand2.second.realField;
		if (operand2.first==BOOL_CODE) res.second.boolField/=operand2.second.boolField;
	}
	return res;
}
Real real_modulus(Real a, Real b)
{
	return a-int(a/b)*b;
}
std::pair<int,ProgramStack::MemoryUnit> modulus(std::pair<int,ProgramStack::MemoryUnit> operand1, std::pair<int,ProgramStack::MemoryUnit> operand2)
{
	std::pair<int,ProgramStack::MemoryUnit> res;
    if (operand1.first==REF_CODE || operand1.first==VOID_CODE || operand1.first>=NUMBER_OF_PRIMITIVE_TYPES
			|| operand2.first==REF_CODE || operand2.first==VOID_CODE || operand2.first>=NUMBER_OF_PRIMITIVE_TYPES)
	{
		//throw exception
		return res;
	}
	if (operand1.first==NUM_CODE)
	{
		res.first=NUM_CODE;
		res.second.numField=operand1.second.numField;
		if (operand2.first==NUM_CODE) res.second.numField%=operand2.second.numField;
		if (operand2.first==CHAR_CODE) res.second.numField%=operand2.second.charField;
		if (operand2.first==REAL_CODE) res.second.numField=real_modulus(res.second.numField,operand2.second.realField);
		if (operand2.first==BOOL_CODE) res.second.numField%=operand2.second.boolField;
	}
	if (operand1.first==REAL_CODE)
	{
		res.first=REAL_CODE;
		res.second.realField=operand1.second.realField;
		if (operand2.first==NUM_CODE) res.second.realField=real_modulus(res.second.realField,operand2.second.numField);
		if (operand2.first==CHAR_CODE) res.second.realField=real_modulus(res.second.realField,operand2.second.charField);
		if (operand2.first==REAL_CODE) res.second.realField=real_modulus(res.second.realField,operand2.second.realField);
		if (operand2.first==BOOL_CODE) res.second.realField=real_modulus(res.second.realField,operand2.second.boolField);
	}
	if (operand1.first==CHAR_CODE)
	{
		res.first=CHAR_CODE;
		res.second.charField=operand1.second.charField;
		if (operand2.first==NUM_CODE) res.second.charField%=operand2.second.numField;
		if (operand2.first==CHAR_CODE) res.second.charField%=operand2.second.charField;
		if (operand2.first==REAL_CODE) res.second.charField=real_modulus(res.second.charField,operand2.second.realField);
		if (operand2.first==BOOL_CODE) res.second.charField%=operand2.second.boolField;
	}
	if (operand1.first==BOOL_CODE)
	{
		res.first=BOOL_CODE;
		res.second.boolField=operand1.second.boolField;
		if (operand2.first==NUM_CODE) res.second.boolField%=operand2.second.numField;
		if (operand2.first==CHAR_CODE) res.second.boolField%=operand2.second.charField;
		if (operand2.first==REAL_CODE) res.second.boolField=real_modulus(res.second.boolField,operand2.second.realField);
		if (operand2.first==BOOL_CODE) res.second.boolField%=operand2.second.boolField;
	}
	return res;
}
std::pair<int,ProgramStack::MemoryUnit> cmp_equal(std::pair<int,ProgramStack::MemoryUnit> operand1, std::pair<int,ProgramStack::MemoryUnit> operand2)
{
	std::pair<int,ProgramStack::MemoryUnit> res;
    if (operand1.first==REF_CODE || operand1.first==VOID_CODE || operand1.first>=NUMBER_OF_PRIMITIVE_TYPES
			|| operand2.first==REF_CODE || operand2.first==VOID_CODE || operand2.first>=NUMBER_OF_PRIMITIVE_TYPES)
	{
		//throw exception
		return res;
	}
	res.first=BOOL_CODE;
	if (operand1.first==NUM_CODE)
	{
		if (operand2.first==NUM_CODE) res.second.boolField=operand1.second.numField==operand2.second.numField;
		if (operand2.first==CHAR_CODE) res.second.boolField=operand1.second.numField==operand2.second.charField;
		if (operand2.first==REAL_CODE) res.second.boolField=operand1.second.numField==operand2.second.realField;
		if (operand2.first==BOOL_CODE) res.second.boolField=operand1.second.numField==operand2.second.boolField;
	}
	if (operand1.first==REAL_CODE)
	{
		if (operand2.first==NUM_CODE) res.second.boolField=operand1.second.realField==operand2.second.numField;
		if (operand2.first==CHAR_CODE) res.second.boolField=operand1.second.realField==operand2.second.charField;
		if (operand2.first==REAL_CODE) res.second.boolField=operand1.second.realField==operand2.second.realField;
		if (operand2.first==BOOL_CODE) res.second.boolField=operand1.second.realField==operand2.second.boolField;
	}
	if (operand1.first==CHAR_CODE)
	{
		if (operand2.first==NUM_CODE) res.second.boolField=operand1.second.charField==operand2.second.numField;
		if (operand2.first==CHAR_CODE) res.second.boolField=operand1.second.charField==operand2.second.charField;
		if (operand2.first==REAL_CODE) res.second.boolField=operand1.second.charField==operand2.second.realField;
		if (operand2.first==BOOL_CODE) res.second.boolField=operand1.second.charField==operand2.second.boolField;
	}
	if (operand1.first==BOOL_CODE)
	{
		if (operand2.first==NUM_CODE) res.second.boolField=operand1.second.boolField==operand2.second.numField;
		if (operand2.first==CHAR_CODE) res.second.boolField=operand1.second.boolField==operand2.second.charField;
		if (operand2.first==REAL_CODE) res.second.boolField=operand1.second.boolField==operand2.second.realField;
		if (operand2.first==BOOL_CODE) res.second.boolField=operand1.second.boolField==operand2.second.boolField;
	}
	return res;
}
std::pair<int,ProgramStack::MemoryUnit> cmp_not_equal(std::pair<int,ProgramStack::MemoryUnit> operand1, std::pair<int,ProgramStack::MemoryUnit> operand2)
{
	std::pair<int,ProgramStack::MemoryUnit> res;
    if (operand1.first==REF_CODE || operand1.first==VOID_CODE || operand1.first>=NUMBER_OF_PRIMITIVE_TYPES
			|| operand2.first==REF_CODE || operand2.first==VOID_CODE || operand2.first>=NUMBER_OF_PRIMITIVE_TYPES)
	{
		//throw exception
		return res;
	}
	res.first=BOOL_CODE;
	if (operand1.first==NUM_CODE)
	{
		if (operand2.first==NUM_CODE) res.second.boolField=operand1.second.numField!=operand2.second.numField;
		if (operand2.first==CHAR_CODE) res.second.boolField=operand1.second.numField!=operand2.second.charField;
		if (operand2.first==REAL_CODE) res.second.boolField=operand1.second.numField!=operand2.second.realField;
		if (operand2.first==BOOL_CODE) res.second.boolField=operand1.second.numField!=operand2.second.boolField;
	}
	if (operand1.first==REAL_CODE)
	{
		if (operand2.first==NUM_CODE) res.second.boolField=operand1.second.realField!=operand2.second.numField;
		if (operand2.first==CHAR_CODE) res.second.boolField=operand1.second.realField!=operand2.second.charField;
		if (operand2.first==REAL_CODE) res.second.boolField=operand1.second.realField!=operand2.second.realField;
		if (operand2.first==BOOL_CODE) res.second.boolField=operand1.second.realField!=operand2.second.boolField;
	}
	if (operand1.first==CHAR_CODE)
	{
		if (operand2.first==NUM_CODE) res.second.boolField=operand1.second.charField!=operand2.second.numField;
		if (operand2.first==CHAR_CODE) res.second.boolField=operand1.second.charField!=operand2.second.charField;
		if (operand2.first==REAL_CODE) res.second.boolField=operand1.second.charField!=operand2.second.realField;
		if (operand2.first==BOOL_CODE) res.second.boolField=operand1.second.charField!=operand2.second.boolField;
	}
	if (operand1.first==BOOL_CODE)
	{
		if (operand2.first==NUM_CODE) res.second.boolField=operand1.second.boolField!=operand2.second.numField;
		if (operand2.first==CHAR_CODE) res.second.boolField=operand1.second.boolField!=operand2.second.charField;
		if (operand2.first==REAL_CODE) res.second.boolField=operand1.second.boolField!=operand2.second.realField;
		if (operand2.first==BOOL_CODE) res.second.boolField=operand1.second.boolField!=operand2.second.boolField;
	}
	return res;
}
std::pair<int,ProgramStack::MemoryUnit> cmp_smaller(std::pair<int,ProgramStack::MemoryUnit> operand1, std::pair<int,ProgramStack::MemoryUnit> operand2)
{
	std::pair<int,ProgramStack::MemoryUnit> res;
    if (operand1.first==REF_CODE || operand1.first==VOID_CODE || operand1.first>=NUMBER_OF_PRIMITIVE_TYPES
			|| operand2.first==REF_CODE || operand2.first==VOID_CODE || operand2.first>=NUMBER_OF_PRIMITIVE_TYPES)
	{
		//throw exception
		return res;
	}
	res.first=BOOL_CODE;
	if (operand1.first==NUM_CODE)
	{
		if (operand2.first==NUM_CODE) res.second.boolField=operand1.second.numField<operand2.second.numField;
		if (operand2.first==CHAR_CODE) res.second.boolField=operand1.second.numField<operand2.second.charField;
		if (operand2.first==REAL_CODE) res.second.boolField=operand1.second.numField<operand2.second.realField;
		if (operand2.first==BOOL_CODE) res.second.boolField=operand1.second.numField<operand2.second.boolField;
	}
	if (operand1.first==REAL_CODE)
	{
		if (operand2.first==NUM_CODE) res.second.boolField=operand1.second.realField<operand2.second.numField;
		if (operand2.first==CHAR_CODE) res.second.boolField=operand1.second.realField<operand2.second.charField;
		if (operand2.first==REAL_CODE) res.second.boolField=operand1.second.realField<operand2.second.realField;
		if (operand2.first==BOOL_CODE) res.second.boolField=operand1.second.realField<operand2.second.boolField;
	}
	if (operand1.first==CHAR_CODE)
	{
		if (operand2.first==NUM_CODE) res.second.boolField=operand1.second.charField<operand2.second.numField;
		if (operand2.first==CHAR_CODE) res.second.boolField=operand1.second.charField<operand2.second.charField;
		if (operand2.first==REAL_CODE) res.second.boolField=operand1.second.charField<operand2.second.realField;
		if (operand2.first==BOOL_CODE) res.second.boolField=operand1.second.charField<operand2.second.boolField;
	}
	if (operand1.first==BOOL_CODE)
	{
		if (operand2.first==NUM_CODE) res.second.boolField=operand1.second.boolField<operand2.second.numField;
		if (operand2.first==CHAR_CODE) res.second.boolField=operand1.second.boolField<operand2.second.charField;
		if (operand2.first==REAL_CODE) res.second.boolField=operand1.second.boolField<operand2.second.realField;
		if (operand2.first==BOOL_CODE) res.second.boolField=operand1.second.boolField<operand2.second.boolField;
	}
	return res;
}
std::pair<int,ProgramStack::MemoryUnit> cmp_not_bigger(std::pair<int,ProgramStack::MemoryUnit> operand1, std::pair<int,ProgramStack::MemoryUnit> operand2)
{
	std::pair<int,ProgramStack::MemoryUnit> res;
    if (operand1.first==REF_CODE || operand1.first==VOID_CODE || operand1.first>=NUMBER_OF_PRIMITIVE_TYPES
			|| operand2.first==REF_CODE || operand2.first==VOID_CODE || operand2.first>=NUMBER_OF_PRIMITIVE_TYPES)
	{
		//throw exception
		return res;
	}
	res.first=BOOL_CODE;
	if (operand1.first==NUM_CODE)
	{
		if (operand2.first==NUM_CODE) res.second.boolField=operand1.second.numField<=operand2.second.numField;
		if (operand2.first==CHAR_CODE) res.second.boolField=operand1.second.numField<=operand2.second.charField;
		if (operand2.first==REAL_CODE) res.second.boolField=operand1.second.numField<=operand2.second.realField;
		if (operand2.first==BOOL_CODE) res.second.boolField=operand1.second.numField<=operand2.second.boolField;
	}
	if (operand1.first==REAL_CODE)
	{
		if (operand2.first==NUM_CODE) res.second.boolField=operand1.second.realField<=operand2.second.numField;
		if (operand2.first==CHAR_CODE) res.second.boolField=operand1.second.realField<=operand2.second.charField;
		if (operand2.first==REAL_CODE) res.second.boolField=operand1.second.realField<=operand2.second.realField;
		if (operand2.first==BOOL_CODE) res.second.boolField=operand1.second.realField<=operand2.second.boolField;
	}
	if (operand1.first==CHAR_CODE)
	{
		if (operand2.first==NUM_CODE) res.second.boolField=operand1.second.charField<=operand2.second.numField;
		if (operand2.first==CHAR_CODE) res.second.boolField=operand1.second.charField<=operand2.second.charField;
		if (operand2.first==REAL_CODE) res.second.boolField=operand1.second.charField<=operand2.second.realField;
		if (operand2.first==BOOL_CODE) res.second.boolField=operand1.second.charField<=operand2.second.boolField;
	}
	if (operand1.first==BOOL_CODE)
	{
		if (operand2.first==NUM_CODE) res.second.boolField=operand1.second.boolField<=operand2.second.numField;
		if (operand2.first==CHAR_CODE) res.second.boolField=operand1.second.boolField<=operand2.second.charField;
		if (operand2.first==REAL_CODE) res.second.boolField=operand1.second.boolField<=operand2.second.realField;
		if (operand2.first==BOOL_CODE) res.second.boolField=operand1.second.boolField<=operand2.second.boolField;
	}
	return res;
}
std::pair<int,ProgramStack::MemoryUnit> cmp_bigger(std::pair<int,ProgramStack::MemoryUnit> operand1, std::pair<int,ProgramStack::MemoryUnit> operand2)
{
	std::pair<int,ProgramStack::MemoryUnit> res;
    if (operand1.first==REF_CODE || operand1.first==VOID_CODE || operand1.first>=NUMBER_OF_PRIMITIVE_TYPES
			|| operand2.first==REF_CODE || operand2.first==VOID_CODE || operand2.first>=NUMBER_OF_PRIMITIVE_TYPES)
	{
		//throw exception
		return res;
	}
	res.first=BOOL_CODE;
	if (operand1.first==NUM_CODE)
	{
		if (operand2.first==NUM_CODE) res.second.boolField=operand1.second.numField>operand2.second.numField;
		if (operand2.first==CHAR_CODE) res.second.boolField=operand1.second.numField>operand2.second.charField;
		if (operand2.first==REAL_CODE) res.second.boolField=operand1.second.numField>operand2.second.realField;
		if (operand2.first==BOOL_CODE) res.second.boolField=operand1.second.numField>operand2.second.boolField;
	}
	if (operand1.first==REAL_CODE)
	{
		if (operand2.first==NUM_CODE) res.second.boolField=operand1.second.realField>operand2.second.numField;
		if (operand2.first==CHAR_CODE) res.second.boolField=operand1.second.realField>operand2.second.charField;
		if (operand2.first==REAL_CODE) res.second.boolField=operand1.second.realField>operand2.second.realField;
		if (operand2.first==BOOL_CODE) res.second.boolField=operand1.second.realField>operand2.second.boolField;
	}
	if (operand1.first==CHAR_CODE)
	{
		if (operand2.first==NUM_CODE) res.second.boolField=operand1.second.charField>operand2.second.numField;
		if (operand2.first==CHAR_CODE) res.second.boolField=operand1.second.charField>operand2.second.charField;
		if (operand2.first==REAL_CODE) res.second.boolField=operand1.second.charField>operand2.second.realField;
		if (operand2.first==BOOL_CODE) res.second.boolField=operand1.second.charField>operand2.second.boolField;
	}
	if (operand1.first==BOOL_CODE)
	{
		if (operand2.first==NUM_CODE) res.second.boolField=operand1.second.boolField>operand2.second.numField;
		if (operand2.first==CHAR_CODE) res.second.boolField=operand1.second.boolField>operand2.second.charField;
		if (operand2.first==REAL_CODE) res.second.boolField=operand1.second.boolField>operand2.second.realField;
		if (operand2.first==BOOL_CODE) res.second.boolField=operand1.second.boolField>operand2.second.boolField;
	}
	return res;
}
std::pair<int,ProgramStack::MemoryUnit> cmp_not_smaller(std::pair<int,ProgramStack::MemoryUnit> operand1, std::pair<int,ProgramStack::MemoryUnit> operand2)
{
	std::pair<int,ProgramStack::MemoryUnit> res;
    if (operand1.first==REF_CODE || operand1.first==VOID_CODE || operand1.first>=NUMBER_OF_PRIMITIVE_TYPES
			|| operand2.first==REF_CODE || operand2.first==VOID_CODE || operand2.first>=NUMBER_OF_PRIMITIVE_TYPES)
	{
		//throw exception
		return res;
	}
	res.first=BOOL_CODE;
	if (operand1.first==NUM_CODE)
	{
		if (operand2.first==NUM_CODE) res.second.boolField=operand1.second.numField>=operand2.second.numField;
		if (operand2.first==CHAR_CODE) res.second.boolField=operand1.second.numField>=operand2.second.charField;
		if (operand2.first==REAL_CODE) res.second.boolField=operand1.second.numField>=operand2.second.realField;
		if (operand2.first==BOOL_CODE) res.second.boolField=operand1.second.numField>=operand2.second.boolField;
	}
	if (operand1.first==REAL_CODE)
	{
		if (operand2.first==NUM_CODE) res.second.boolField=operand1.second.realField>=operand2.second.numField;
		if (operand2.first==CHAR_CODE) res.second.boolField=operand1.second.realField>=operand2.second.charField;
		if (operand2.first==REAL_CODE) res.second.boolField=operand1.second.realField>=operand2.second.realField;
		if (operand2.first==BOOL_CODE) res.second.boolField=operand1.second.realField>=operand2.second.boolField;
	}
	if (operand1.first==CHAR_CODE)
	{
		if (operand2.first==NUM_CODE) res.second.boolField=operand1.second.charField>=operand2.second.numField;
		if (operand2.first==CHAR_CODE) res.second.boolField=operand1.second.charField>=operand2.second.charField;
		if (operand2.first==REAL_CODE) res.second.boolField=operand1.second.charField>=operand2.second.realField;
		if (operand2.first==BOOL_CODE) res.second.boolField=operand1.second.charField>=operand2.second.boolField;
	}
	if (operand1.first==BOOL_CODE)
	{
		if (operand2.first==NUM_CODE) res.second.boolField=operand1.second.boolField>=operand2.second.numField;
		if (operand2.first==CHAR_CODE) res.second.boolField=operand1.second.boolField>=operand2.second.charField;
		if (operand2.first==REAL_CODE) res.second.boolField=operand1.second.boolField>=operand2.second.realField;
		if (operand2.first==BOOL_CODE) res.second.boolField=operand1.second.boolField>=operand2.second.boolField;
	}
	return res;
}
std::pair<int,ProgramStack::MemoryUnit> logic_and(std::pair<int,ProgramStack::MemoryUnit> operand1, std::pair<int,ProgramStack::MemoryUnit> operand2)
{
	std::pair<int,ProgramStack::MemoryUnit> res;
    if (operand1.first==REF_CODE || operand1.first==VOID_CODE || operand1.first>=NUMBER_OF_PRIMITIVE_TYPES
			|| operand2.first==REF_CODE || operand2.first==VOID_CODE || operand2.first>=NUMBER_OF_PRIMITIVE_TYPES)
	{
		//throw exception
		return res;
	}
	res.first=BOOL_CODE;
	if (operand1.first==NUM_CODE)
	{
		if (operand2.first==NUM_CODE) res.second.boolField=operand1.second.numField && operand2.second.numField;
		if (operand2.first==CHAR_CODE) res.second.boolField=operand1.second.numField && operand2.second.charField;
		if (operand2.first==REAL_CODE) res.second.boolField=operand1.second.numField && operand2.second.realField;
		if (operand2.first==BOOL_CODE) res.second.boolField=operand1.second.numField && operand2.second.boolField;
	}
	if (operand1.first==REAL_CODE)
	{
		if (operand2.first==NUM_CODE) res.second.boolField=operand1.second.realField && operand2.second.numField;
		if (operand2.first==CHAR_CODE) res.second.boolField=operand1.second.realField && operand2.second.charField;
		if (operand2.first==REAL_CODE) res.second.boolField=operand1.second.realField && operand2.second.realField;
		if (operand2.first==BOOL_CODE) res.second.boolField=operand1.second.realField && operand2.second.boolField;
	}
	if (operand1.first==CHAR_CODE)
	{
		if (operand2.first==NUM_CODE) res.second.boolField=operand1.second.charField && operand2.second.numField;
		if (operand2.first==CHAR_CODE) res.second.boolField=operand1.second.charField && operand2.second.charField;
		if (operand2.first==REAL_CODE) res.second.boolField=operand1.second.charField && operand2.second.realField;
		if (operand2.first==BOOL_CODE) res.second.boolField=operand1.second.charField && operand2.second.boolField;
	}
	if (operand1.first==BOOL_CODE)
	{
		if (operand2.first==NUM_CODE) res.second.boolField=operand1.second.boolField && operand2.second.numField;
		if (operand2.first==CHAR_CODE) res.second.boolField=operand1.second.boolField && operand2.second.charField;
		if (operand2.first==REAL_CODE) res.second.boolField=operand1.second.boolField && operand2.second.realField;
		if (operand2.first==BOOL_CODE) res.second.boolField=operand1.second.boolField && operand2.second.boolField;
	}
	return res;
}
std::pair<int,ProgramStack::MemoryUnit> logic_or(std::pair<int,ProgramStack::MemoryUnit> operand1, std::pair<int,ProgramStack::MemoryUnit> operand2)
{
	std::pair<int,ProgramStack::MemoryUnit> res;
    if (operand1.first==REF_CODE || operand1.first==VOID_CODE || operand1.first>=NUMBER_OF_PRIMITIVE_TYPES
			|| operand2.first==REF_CODE || operand2.first==VOID_CODE || operand2.first>=NUMBER_OF_PRIMITIVE_TYPES)
	{
		//throw exception
		return res;
	}
	res.first=BOOL_CODE;
	if (operand1.first==NUM_CODE)
	{
		if (operand2.first==NUM_CODE) res.second.boolField=operand1.second.numField || operand2.second.numField;
		if (operand2.first==CHAR_CODE) res.second.boolField=operand1.second.numField || operand2.second.charField;
		if (operand2.first==REAL_CODE) res.second.boolField=operand1.second.numField || operand2.second.realField;
		if (operand2.first==BOOL_CODE) res.second.boolField=operand1.second.numField || operand2.second.boolField;
	}
	if (operand1.first==REAL_CODE)
	{
		if (operand2.first==NUM_CODE) res.second.boolField=operand1.second.realField || operand2.second.numField;
		if (operand2.first==CHAR_CODE) res.second.boolField=operand1.second.realField || operand2.second.charField;
		if (operand2.first==REAL_CODE) res.second.boolField=operand1.second.realField || operand2.second.realField;
		if (operand2.first==BOOL_CODE) res.second.boolField=operand1.second.realField || operand2.second.boolField;
	}
	if (operand1.first==CHAR_CODE)
	{
		if (operand2.first==NUM_CODE) res.second.boolField=operand1.second.charField || operand2.second.numField;
		if (operand2.first==CHAR_CODE) res.second.boolField=operand1.second.charField || operand2.second.charField;
		if (operand2.first==REAL_CODE) res.second.boolField=operand1.second.charField || operand2.second.realField;
		if (operand2.first==BOOL_CODE) res.second.boolField=operand1.second.charField || operand2.second.boolField;
	}
	if (operand1.first==BOOL_CODE)
	{
		if (operand2.first==NUM_CODE) res.second.boolField=operand1.second.boolField || operand2.second.numField;
		if (operand2.first==CHAR_CODE) res.second.boolField=operand1.second.boolField || operand2.second.charField;
		if (operand2.first==REAL_CODE) res.second.boolField=operand1.second.boolField || operand2.second.realField;
		if (operand2.first==BOOL_CODE) res.second.boolField=operand1.second.boolField || operand2.second.boolField;
	}
	return res;
}
std::pair<int,ProgramStack::MemoryUnit> logic_not(std::pair<int,ProgramStack::MemoryUnit> operand1)
{
	std::pair<int,ProgramStack::MemoryUnit> res;
    if (operand1.first==REF_CODE || operand1.first==VOID_CODE || operand1.first>=NUMBER_OF_PRIMITIVE_TYPES)
	{
		//throw exception
		return res;
	}
	res.first=BOOL_CODE;
	if (operand1.first==NUM_CODE) res.second.boolField=!operand1.second.numField;
	if (operand1.first==CHAR_CODE) res.second.boolField=!operand1.second.charField;
	if (operand1.first==REAL_CODE) res.second.boolField=!operand1.second.realField;
	if (operand1.first==BOOL_CODE) res.second.boolField=!operand1.second.boolField;
	return res;
}
