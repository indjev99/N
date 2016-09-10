#include "../headers/variable_declaration.cpp"
#include "../headers/program_stack.h"

VariableDeclaration::VariableDeclaration(uint32_t pType, uint32_t pId, 
		Statement *pNext): Goto(pNext), type(pType), varId(pId) {} 

Statemen *VariableDeclaration::execute(ProgramStack &memory)
{
	//allocate memory in programstack
	return Goto::execute(memory);
}
