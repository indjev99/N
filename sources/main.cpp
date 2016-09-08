#include "../headers/entity.h"

#include <iostream>
#include <string>

std::string read_stdin()
{
	std::string ans;
	std::string line;
	while (std::getline(std::cin, line))
	{
		ans += line + '\n';
	}
	return ans;
}

int main() 
{
	std::string source = read_stdin();
	std::cout << source << "\n";
	std::vector<Entity> processed = Entity::generate_from_text(source);

	for (Entity e : processed) 
	{
		std::cout << (unsigned int) e.type << " " << e.text << "\n";
	}
}
