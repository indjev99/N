#include <string>
#include <vector>

#ifndef ENTITY_H
#define ENTITY_H
/*
 * Splits the source into meaningful bits
 */
class Entity 
{
public:
	enum Type 
	{
/*
 *		Numbers, characters and text
 *		- Character is a character between ''
 *		- Text is anything between ""
 *		- Both characters and text can escape symbols with '\'
 *		- Numbers can contain digits and at most one decimal point (.)
 *		- Boolean values (true and false)
 */
		TEXT_LITERAL,
		CHAR_LITERAL,
		NUM_LITERAL,
		REAL_LITERAL,
		BOOL_LITERAL,
		
/*
 *		Contains characters, which aren't whitespace, alphanumeric, 
 *		a separator, or contain symbols, used in Literals ('"\.)
 */		
		OPERATOR,
/*
 *		(){}[];,
 */
		SEPARATOR,
/*		
 *		Used when a variable is declared or used.
 *		Aplhanumeric and underscores, but doesn't start with a digit.
 */
		VARIABLE,

/*
 *		Used when a function is declared or called.
 *		Aplhanumeric and underscores, but doesn't start with a digit.
 *
 *		<FUNCTION_NAME> ([ARG_EXPRESS])
 */
		FUNCTION,
/*
 *		Used in variable or function declarations
 *		E.g. Num, Char, Real, Bool 
 */
		TYPE,
/*		
 *		The identificator for declaration of a variable, function or
 *		struct:
 *		- var <TYPE> 
 *		- fun <TYPE> <NAME> ([<PARAM_TYPE> <PARAM_NAME>, ...]) 
 *		- struct ???
 */
		DECLARATION,
/*
 *		Used for flow control statemets: if, else, elif, while, for
 */
		FLOW_CONTROL
	};

private:

/*
 *	The symbol, used to denote comments. They should both start and end with
 *	it.
 */
	static const char COMMENT_CHARACTER;
/*
 *	The symbol used to represent decimal numbers. Shouldn't be a coma (,),
 *	because it's used as a SEPERATOR
 */
	static const char DECIMAL_POINT;

	static const size_t BOOL_LITERALS_SIZE;
	static const size_t SEPARATORS_SIZE;
	static const size_t DECLARATIONS_SIZE;
	static const size_t FLOW_CONTROLS_SIZE;

	static const std::string BOOL_LITERALS[];
	static const char SEPARATORS[];
	static const std::string DECLARATIONS[];
	static const std::string FLOW_CONTROLS[];

	static bool isBoolLiteral(const std::string &s);
	static bool isSeparator(char c);
	static bool isDeclaration(const std::string &s);
	static bool isFlowControl(const std::string &s);

	
	static const size_t ESCAPE_SEQUENCES_SIZE;
	static const char ESCAPE_SEQUENCES[];
	static const char ESCAPE_CHARACTERS[]; 

/*
 *	Return the ASCI code of the character \c, based on the lookup table.
 *	If the symbol is in ESCAPE_SEQUENCES, it is mapped to the coresponding 
 *	one from ESCAPE_CHARACTERS. Doesn't support numeric character 
 *	references.
 */
	static char escapeCharacter(char c); 
	
	static void process_by_character_type(const std::string &source,
			std::vector<Entity> &entityList);
	static void process_by_keywords(std::vector<Entity> &entityList);


public:
	Type type;
	std::string text;

	Entity();
	Entity(Type pType, const std::string &pText);


	static std::vector<Entity> generate_from_text(const std::string &s);
};
#endif /* ENTITY_H */
