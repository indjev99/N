#include "../headers/program_stack.h"

#include<iostream>

ProgramStack programStack;

int main()
{
	std::string s;
	int a,b,c;
	Num numVar;
	Char charVar;
	Real realVar;
	Bool boolVar;
	std::string textVar;
	std::vector<std::pair<int, Num>> members;
    while (1)
	{
		std::cin>>s;
		if (s=="var")
		{
			std::cin>>a>>b;
			std::cout<<programStack.add_variable(a,b)<<std::endl;
		}
		else if (s=="=")
		{
			std::cin>>a>>b;
			programStack.copy(a,b);
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
		else if (s=="size")
		{
			std::cin>>a;
			std::cout<<programStack.get_size(a)<<std::endl;
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
		else if (s=="push")
		{
			programStack.push_scope();
		}
		else if (s=="pop")
		{
			programStack.pop_scope();
		}
		else if (s=="struct")
		{
			std::cin>>a;
			members.resize(0);
			for (int i=0;i<a;++i)
			{
				std::cin>>b>>numVar;
				members.push_back(std::make_pair(b,c));
			}
			std::cout<<programStack.add_struct(members)<<std::endl;
		}
		//set_value and get_value are untestable at the moment
	}
	return 0;
}
