#include "../headers/program_stack.h"
#include "../headers/operations.h"

#include<iostream>

ProgramStack programStack;

int main()
{
	std::string s;
	int a,b,c;
	bool r;
	Num numVar;
	Char charVar;
	Real realVar;
	Bool boolVar;
	std::string textVar;
	std::vector<std::pair<int, Num>> members;
	std::pair<int, ProgramStack::MemoryUnit> value;
    while (1)
	{
		std::cin>>s;
		if (s=="var")
		{
			std::cin>>a>>b>>c;
			std::cout<<programStack.add_variable(a,b,c)<<std::endl;
		}
		else if (s=="=")
		{
			std::cin>>a>>b;
			programStack.copy(a,b);
		}
		else if (s=="+")
		{
			std::cin>>a>>b;
			std::cout<<programStack.perform_operation(a,b,addition)<<std::endl;
		}
		else if (s=="-")
		{
			std::cin>>a>>b;
			std::cout<<programStack.perform_operation(a,b,subtraction)<<std::endl;
		}
		else if (s=="*")
		{
			std::cin>>a>>b;
			std::cout<<programStack.perform_operation(a,b,multiplication)<<std::endl;
		}
		else if (s=="/")
		{
			std::cin>>a>>b;
			std::cout<<programStack.perform_operation(a,b,division)<<std::endl;
		}
		else if (s=="%")
		{
			std::cin>>a>>b;
			std::cout<<programStack.perform_operation(a,b,modulus)<<std::endl;
		}
		else if (s=="==")
		{
			std::cin>>a>>b;
			std::cout<<programStack.perform_operation(a,b,cmp_equal)<<std::endl;
		}
		else if (s=="!=")
		{
			std::cin>>a>>b;
			std::cout<<programStack.perform_operation(a,b,cmp_not_equal)<<std::endl;
		}
		else if (s=="<")
		{
			std::cin>>a>>b;
			std::cout<<programStack.perform_operation(a,b,cmp_smaller)<<std::endl;
		}
		else if (s=="<=")
		{
			std::cin>>a>>b;
			std::cout<<programStack.perform_operation(a,b,cmp_not_bigger)<<std::endl;
		}
		else if (s==">")
		{
			std::cin>>a>>b;
			std::cout<<programStack.perform_operation(a,b,cmp_bigger)<<std::endl;
		}
		else if (s==">=")
		{
			std::cin>>a>>b;
			std::cout<<programStack.perform_operation(a,b,cmp_not_smaller)<<std::endl;
		}
		else if (s=="&&")
		{
			std::cin>>a>>b;
			std::cout<<programStack.perform_operation(a,b,logic_and)<<std::endl;
		}
		else if (s=="||")
		{
			std::cin>>a>>b;
			std::cout<<programStack.perform_operation(a,b,logic_or)<<std::endl;
		}
		else if (s=="!")
		{
			std::cin>>a;
			std::cout<<programStack.perform_operation(a,logic_not)<<std::endl;
		}
		else if (s=="[]")
		{
			std::cin>>a>>b;
			std::cout<<programStack.get_at_index(a,b)<<std::endl;
		}
		else if (s==".")
		{
			std::cin>>a>>b;
			std::cout<<programStack.get_member(a,b)<<std::endl;
		}
		else if (s=="is_array")
		{
			std::cin>>a;
			std::cout<<programStack.get_is_array(a)<<std::endl;
		}
		else if (s=="size")
		{
			std::cin>>a;
			std::cout<<programStack.get_size(a)<<std::endl;
		}
		else if (s=="type")
		{
			std::cin>>a;
			std::cout<<programStack.get_type(a)<<std::endl;
		}
		else if (s=="Num")
		{
			std::cin>>numVar;
			std::cout<<programStack.add_num(numVar)<<std::endl;
		}
		else if (s=="Char")
		{
			std::cin>>charVar;
			std::cout<<programStack.add_char(charVar)<<std::endl;
		}
		else if (s=="Real")
		{
			std::cin>>realVar;
			std::cout<<programStack.add_real(realVar)<<std::endl;
		}
		else if (s=="Bool")
		{
			std::cin>>boolVar;
			std::cout<<programStack.add_bool(boolVar)<<std::endl;
		}
		else if (s=="Text")
		{
			std::cin>>textVar;
			std::cout<<programStack.add_text(textVar)<<std::endl;
		}
		else if (s=="reset")
		{
			std::cin>>a;
			programStack.reset(a);
		}
		else if (s=="push")
		{
			std::cin>>r>>a>>b;
			programStack.push_scope(r,a,b);
		}
		else if (s=="pop")
		{
			std::cin>>a;
			std::cout<<programStack.pop_scope(a)<<std::endl;
		}

		else if (s=="declared")
		{
			std::cin>>a;
			std::cout<<programStack.is_declared(a)<<std::endl;
		}
		else if (s=="address")
		{
			std::cin>>a;
			std::cout<<programStack.get_address(a)<<std::endl;
		}
		else if (s=="struct")
		{
			std::cin>>a;
			members.resize(0);
			for (int i=0;i<a;++i)
			{
				std::cin>>b>>numVar;
				members.push_back(std::make_pair(b,numVar));
			}
			std::cout<<programStack.add_struct(members)<<std::endl;\
		}
		else if (s=="get")
		{
			std::cin>>a;
            value=programStack.get_value(a);
            if (value.first==VOID_CODE) std::cout<<"void "<<0<<std::endl;
            else if (value.first==NUM_CODE) std::cout<<"num "<<value.second.numField<<std::endl;
            else if (value.first==CHAR_CODE) std::cout<<"char "<<value.second.charField<<std::endl;
            else if (value.first==REAL_CODE) std::cout<<"real "<<value.second.realField<<std::endl;
            else if (value.first==BOOL_CODE) std::cout<<"bool "<<value.second.boolField<<std::endl;
            else std::cout<<"error "<<value.first<<std::endl;
		}
		else if (s=="set")
		{
			std::cin>>a>>s;
			if (s=="Void")
			{
				value.first=VOID_CODE;
			}
			else if (s=="Num")
			{
				value.first=NUM_CODE;
				std::cin>>value.second.numField;
			}
			else if (s=="Char")
			{
				value.first=CHAR_CODE;
				std::cin>>value.second.charField;
			}
			else if (s=="Real")
			{
				value.first=REAL_CODE;
				std::cin>>value.second.realField;
			}
			else if (s=="Bool")
			{
				value.first=BOOL_CODE;
				std::cin>>value.second.boolField;
			}
			else
			{
				continue;
			}
            programStack.set_value(a,value);
		}
	}
	return 0;
}

/*
struct 1 2 2
var 5 0
var 5 5
var 5 4
Char %
copy 3 42
copy 17 0
copy 25 4
get 41
*/
