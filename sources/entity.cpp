#include "../headers/entity.h"

#include <cctype>
#include <vector>

const char Entity::COMMENT_CHARACTER = '#';
const char Entity::DECIMAL_POINT = '.';

const size_t Entity::BOOL_LITERALS_SIZE = 2;
const size_t Entity::SEPARATORS_SIZE = 2;
const size_t Entity::BRACKETS_SIZE = 6;
const size_t Entity::DECLARATIONS_SIZE = 2;
const size_t Entity::FLOW_CONTROLS_SIZE = 9;

const std::string Entity::BOOL_LITERALS[] = {"true", "false"};
const char Entity::SEPARATORS[] = {';', ','};
const char Entity::BRACKETS[] = {'(', ')', '{', '}', '[', ']'};
const std::string Entity::DECLARATIONS[] = {"var", "fun", "struct"};
const std::string Entity::FLOW_CONTROLS[] = {"if", "else", "elif", "while", 
		"do", "for", "return", "break", "continue"};

Entity::Entity() 
{
	type = Type::VARIABLE;
	text = "";
}

Entity::Entity(Type pType, const std::string &pText): type(pType), 
		text(pText) {}

bool Entity::empty()
{
	return ((text.empty()) && (type == Type::VARIABLE));
}

bool Entity::isBoolLiteral(const std::string &s)
{ 
	for (size_t i = 0;i < BOOL_LITERALS_SIZE;i++) {
		if (s == BOOL_LITERALS[i]) {
			return true;
		}
	}
	return false;
}
bool Entity::isSeparator(char c)
{
	for (size_t i = 0;i < SEPARATORS_SIZE;i++) 
	{
		if (c == SEPARATORS[i]) 
		{
			return true;
		}
	}
	return false;
}
bool Entity::isBracket(char c)
{
	for (size_t i = 0;i < BRACKETS_SIZE;i++) 
	{
		if (c == BRACKETS[i]) 
		{
			return true;
		}
	}
	return false;
}
bool Entity::isDeclaration(const std::string &s) 
{
	for (size_t i = 0;i < DECLARATIONS_SIZE;i++) 
	{
		if (s == DECLARATIONS[i]) 
		{
			return true;
		}
	}
	return false;
}
bool Entity::isFlowControl(const std::string &s)
{
	for (size_t i = 0;i < FLOW_CONTROLS_SIZE;i++) 
	{
		if (s == FLOW_CONTROLS[i]) 
		{
			return true;
		}
	}
	return false;
}
const size_t Entity::ESCAPE_SEQUENCES_SIZE = 11;
const char Entity::ESCAPE_SEQUENCES[] = {'\'', '\"', '\\', '?', 'a', 'b', 
		'f', 'n', 'r', 't', 'v'};
const char Entity::ESCAPE_CHARACTERS[] = {'\'', '\"', '\\', '\?', '\a', '\b', 
		'\f', '\n', '\r', '\t', '\v'};

char Entity::escapeCharacter(char c) 
{
	for (size_t i = 0;i < ESCAPE_SEQUENCES_SIZE;i++)
	{
		if (c == ESCAPE_SEQUENCES[i]) {
			return ESCAPE_CHARACTERS[i];
		}
	}
	//Unknown character escape sequence
	//Should trow an exception
	//Negative acknowledge
	return '\025';
}

void Entity::process_by_character_type(const std::string &source, 
		 std::vector<Entity>& entityList)
{
	Entity cur;
	char prevCh = '\0';
	bool processingComment = false;

	for (char c : source) 
	{
		if ((iscntrl(c)) && (!isspace(c)))
		{
			continue;
		}

		if (processingComment)
		{
			if (c == COMMENT_CHARACTER) {
				processingComment = !processingComment;
			}
			continue;
		}

		bool endCur = false;
		bool addCharToNext = true;
		if ((cur.type == Type::TEXT_LITERAL) || 
				(cur.type == Type::CHAR_LITERAL)) 
		{
			if (prevCh == '\\') 
			{
				char escaped = escapeCharacter(c);
				cur.text.push_back(escaped);
			}
			else if ((c == '\"') && 
					(cur.type == Type::TEXT_LITERAL))
			{
				endCur = true;
				addCharToNext = false;
			}
			else if ((c == '\'') &&
					(cur.type == Type::CHAR_LITERAL))
			{
				endCur = true;
				addCharToNext = false;
			}
			else if ((c != '\n') && (c != '\\'))
			{
				cur.text.push_back(c);
			}
		}
		else if (c == COMMENT_CHARACTER) 
		{
			processingComment = !processingComment;
			continue;
		}
		else if (isspace(c))
		{
			endCur = true;
			addCharToNext = false;
		}
		else if ((isBracket(c)) || (isSeparator(c)) || (c == '\'') ||
				(c == '\"'))
		{
			endCur = true;
		}
		else if (cur.type == Type::NUM_LITERAL)
		{
			if (isdigit(c))
			{
				cur.text.push_back(c);
			}
			else if (c == DECIMAL_POINT)
			{
				cur.text.push_back(c);
				cur.type = Type::REAL_LITERAL;
			}
			else
			{
				endCur = true;
			}
		}
		else if (cur.type == Type::REAL_LITERAL)
		{
			if (isdigit(c))
			{
				cur.text.push_back(c);
			}
			else 
			{
				endCur = true;
			}
		}
		//When the text is empty, cur isn't actually a variable
		else if ((cur.type == Type::VARIABLE) && (not cur.text.empty()))
		{
			if ((isalnum(c)) || (c == '_'))
			{
				cur.text.push_back(c);
			}
			else
			{
				endCur = true;
			}
		}
		else if (cur.type == Type::OPERATOR)
		{
			if ((!isalnum(c)) && (c != '_'))
			{
				cur.text.push_back(c);
			}
			else
			{
				endCur = true;
			}
		}

		if ((endCur) && (not cur.empty()))
		{
			entityList.push_back(cur);
			cur = Entity();
		}

		if ((addCharToNext) && (cur.empty()))
		{
			if (c == '\"')
			{
				cur.type = Type::TEXT_LITERAL;
			}
			else if (c == '\'')
			{
				cur.type = Type::CHAR_LITERAL;
			}
			else if ((isSeparator(c)) || (isBracket(c)))
			{
				if (isSeparator(c))
				{
					cur.type = Type::SEPARATOR;
				}
				else
				{
					cur.type = Type::BRACKET;
				}

				cur.text.push_back(c);

				entityList.push_back(cur);
				cur = Entity();
			}
			else if (isdigit(c))
			{
				cur.type = Type::NUM_LITERAL;
				cur.text.push_back(c);
			}
			else if ((isalpha(c)) || (c == '_'))
			{
				cur.type = Type::VARIABLE;
				cur.text.push_back(c);
			}
			else 
			{
				cur.type = Type::OPERATOR;
				cur.text.push_back(c);
			}
		}
		prevCh = c;
	}
	if (not cur.empty())
	{
		entityList.push_back(cur);
	}
}
void Entity::process_by_keywords(std::vector<Entity> &entityList)
{
	for (size_t i = 0;i < entityList.size();i++)
	{
		Entity &e = entityList[i];
		if (e.type == Type::VARIABLE)
		{
			if (isFlowControl(e.text))
			{
				e.type = Type::FLOW_CONTROL;
			}
			else if (isDeclaration(e.text))
			{
				e.type = Type::DECLARATION;
			}
			else if (isBoolLiteral(e.text))
			{
				e.type = Type::BOOL_LITERAL;
			}
		}
		if (i + 1 < entityList.size())
		{
			Entity &next = entityList[i + 1];
			if (e.type == Type::DECLARATION)
			{
				if (next.type == Type::VARIABLE)
				{
					next.type = Type::TYPE;
				}
			}
			else if ((next.type == Type::BRACKET) && (next.text == "("))
			{
				e.type = Type::FUNCTION;
			}
		}
	}
}

std::vector<Entity> Entity::generate_from_text(const std::string& source) 
{
	std::vector<Entity> entityList;

	process_by_character_type(source, entityList);
	process_by_keywords(entityList);

	return entityList;

}
