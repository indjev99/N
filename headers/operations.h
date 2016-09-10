#ifndef OPERATIONS_H_INCLUDED
#define OPERATIONS_H_INCLUDED

#include "../headers/primitive_types.h"
#include "../headers/program_stack.h"

std::pair<int,ProgramStack::MemoryUnit> addition(std::pair<int,ProgramStack::MemoryUnit> operand1, std::pair<int,ProgramStack::MemoryUnit> operand2);
std::pair<int,ProgramStack::MemoryUnit> subtraction(std::pair<int,ProgramStack::MemoryUnit> operand1, std::pair<int,ProgramStack::MemoryUnit> operand2);
std::pair<int,ProgramStack::MemoryUnit> multiplication(std::pair<int,ProgramStack::MemoryUnit> operand1, std::pair<int,ProgramStack::MemoryUnit> operand2);
std::pair<int,ProgramStack::MemoryUnit> division(std::pair<int,ProgramStack::MemoryUnit> operand1, std::pair<int,ProgramStack::MemoryUnit> operand2);
std::pair<int,ProgramStack::MemoryUnit> modulus(std::pair<int,ProgramStack::MemoryUnit> operand1, std::pair<int,ProgramStack::MemoryUnit> operand2);
std::pair<int,ProgramStack::MemoryUnit> cmp_equal(std::pair<int,ProgramStack::MemoryUnit> operand1, std::pair<int,ProgramStack::MemoryUnit> operand2);
std::pair<int,ProgramStack::MemoryUnit> cmp_not_equal(std::pair<int,ProgramStack::MemoryUnit> operand1, std::pair<int,ProgramStack::MemoryUnit> operand2);
std::pair<int,ProgramStack::MemoryUnit> cmp_smaller(std::pair<int,ProgramStack::MemoryUnit> operand1, std::pair<int,ProgramStack::MemoryUnit> operand2);
std::pair<int,ProgramStack::MemoryUnit> cmp_not_bigger(std::pair<int,ProgramStack::MemoryUnit> operand1, std::pair<int,ProgramStack::MemoryUnit> operand2);
std::pair<int,ProgramStack::MemoryUnit> cmp_bigger(std::pair<int,ProgramStack::MemoryUnit> operand1, std::pair<int,ProgramStack::MemoryUnit> operand2);
std::pair<int,ProgramStack::MemoryUnit> cmp_not_smaller(std::pair<int,ProgramStack::MemoryUnit> operand1, std::pair<int,ProgramStack::MemoryUnit> operand2);
std::pair<int,ProgramStack::MemoryUnit> logic_and(std::pair<int,ProgramStack::MemoryUnit> operand1, std::pair<int,ProgramStack::MemoryUnit> operand2);
std::pair<int,ProgramStack::MemoryUnit> logic_or(std::pair<int,ProgramStack::MemoryUnit> operand1, std::pair<int,ProgramStack::MemoryUnit> operand2);
std::pair<int,ProgramStack::MemoryUnit> logic_not(std::pair<int,ProgramStack::MemoryUnit> operand1);

#endif // OPERATIONS_H_INCLUDED
