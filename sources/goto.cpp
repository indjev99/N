#include "../headers/goto.h"
#include "../headers/ProgramStack.h"

Goto::Goto(Statement *pNextStatement): nextStatement(pNextStatement) {} 

Statement *Goto::execute(ProgramStack &memory)
{
	return nextStatement;
}
