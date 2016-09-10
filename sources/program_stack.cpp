#include "../headers/primitive_types.h"
#include "../headers/program_stack.h"

#include<cstdint>

ProgramStack::ProgramStack() {}
ProgramStack::ProgramStack(int numOfVars)
{
	reset(numOfVars);
}
int ProgramStack::add_variable(int id, int type, Num size)
{
	if (size<0)
	{
		//throw exception
		return -1;
	}
    int address=vars.size();
    if (id!=-1)
	{
		if (is_declared(id)==2)
		{
			//throw exception
			return -1;
		}
		declaredAtScope.top().push_back(id);
		if (scopePosition.empty()) globalAddress[id]=address;
		else scopeAddress[id].push(std::make_pair(scopePosition.size(),address));
	}
	vars.push_back(*new Variable(type,size));
	if (size)
	{
		vars[address].members.push_back(size);
		for (Num i=0;i<size;++i)
		{
            if (i==0)
			{
				vars[address].members.push_back(add_variable(-1,type,0));
				continue;
			}
			add_variable(-1,type,0);
		}
		if (size<0) vars[address].members.push_back(-1);
		vars[address].members.push_back(size_of_type(type,0));
	}
	else if (type==REF_CODE) {}
	else if (type>=NUMBER_OF_PRIMITIVE_TYPES)
	{
		std::vector<std::pair<int, Num>>& members=structs[type-NUMBER_OF_PRIMITIVE_TYPES].members;
		for (std::size_t i=0;i<members.size();++i)
		{
            vars[address].members.push_back(add_variable(-1,members[i].first,members[i].second));
		}
	}
	else
	{
		vars[vars.size()-1].members.push_back(memory.size());
        ProgramStack::MemoryUnit currMemUnit;
        if (type==VOID_CODE) vars[vars.size()-1].members.resize(0);
        else
		{
			if (type==NUM_CODE) currMemUnit.numField=0;
			else if (type==CHAR_CODE) currMemUnit.charField=0;
			else if (type==REAL_CODE) currMemUnit.realField=0;
			else if (type==BOOL_CODE) currMemUnit.boolField=0;
			memory.push_back(currMemUnit);
		}
	}
    return address;
}
int ProgramStack::add_num(Num value)
{
	int address=add_variable(-1,NUM_CODE,0);
	MemoryUnit newMemUnit;
	newMemUnit.numField=value;
	set_value(address,std::make_pair(NUM_CODE,newMemUnit));
	return address;
}
int ProgramStack::add_char(Char value)
{
	int address=add_variable(-1,CHAR_CODE,0);
	MemoryUnit newMemUnit;
	newMemUnit.charField=value;
	set_value(address,std::make_pair(CHAR_CODE,newMemUnit));
	return address;
}
int ProgramStack::add_real(Real value)
{
	int address=add_variable(-1,REAL_CODE,0);
	MemoryUnit newMemUnit;
	newMemUnit.realField=value;
	set_value(address,std::make_pair(REAL_CODE,newMemUnit));
	return address;
}
int ProgramStack::add_bool(Bool value)
{
	int address=add_variable(BOOL_CODE,0);
	MemoryUnit newMemUnit;
	newMemUnit.boolField=value;
	set_value(address,std::make_pair(BOOL_CODE,newMemUnit));
	return address;
}
int ProgramStack::add_text(std::string value)
{
	int address=add_variable(-1,CHAR_CODE,value.size());
	MemoryUnit newMemUnit;
	for (size_t i=0;i<value.size();++i)
	{
		newMemUnit.charField=value[i];
		set_value(get_at_index(address,i),std::make_pair(CHAR_CODE,newMemUnit));
	}
	return address;
}
void ProgramStack::copy(int address1, int address2)
{
	vars[address1].set(vars[address2],*this);
}
int ProgramStack::perform_operation(int address1, std::pair<int, ProgramStack::MemoryUnit> (*operation)(std::pair<int, ProgramStack::MemoryUnit>))
{
	int address;
    std::pair<int, MemoryUnit> result;
    result=(*operation)(get_value(address1));
    address=add_variable(-1,result.first,0);
    set_value(address,result);
    return address;
}
int ProgramStack::perform_operation(int address1, int address2, std::pair<int, ProgramStack::MemoryUnit> (*operation)(std::pair<int, ProgramStack::MemoryUnit>, std::pair<int, ProgramStack::MemoryUnit>))
{
	int address;
    std::pair<int, MemoryUnit> result;
    result=(*operation)(get_value(address1),get_value(address2));
    address=add_variable(-1,result.first,0);
    set_value(address,result);
    return address;
}
void ProgramStack::set_value(int address, std::pair<int, MemoryUnit> newMemUnit)
{
    vars[address].set_value(newMemUnit.first,newMemUnit.second,*this);
}
std::pair<int, ProgramStack::MemoryUnit> ProgramStack::get_value(int address) const
{
    return std::make_pair(vars[address].type<NUMBER_OF_PRIMITIVE_TYPES && !vars[address].isArray?vars[address].type:-1,vars[address].get_value(*this));
}
int ProgramStack::get_at_index(int address, Num index) const
{
	return vars[address].get_at_index(index);
}
int ProgramStack::get_member(int address, int member) const
{
	return vars[address].get_member(member);
}
Bool ProgramStack::get_is_array(int address) const
{
    return vars[address].get_is_array();
}
Num ProgramStack::get_size(int address) const
{
    return vars[address].get_size();
}
int ProgramStack::get_type(int address) const
{
    return vars[address].get_type();
}
void ProgramStack::reset(int numOfVars)
{
    structs.resize(0);
	while (!scopePosition.empty()) scopePosition.pop();
	while (!restrictedScopes.empty()) restrictedScopes.pop();
	scopeAddress.resize(numOfVars);
	globalAddress.resize(numOfVars);
	while (!declaredAtScope.empty()) declaredAtScope.pop();
	declaredAtScope.push({});
	for (int i=0;i<numOfVars;++i)
	{
        globalAddress[i]=-1;
        while (!scopeAddress[i].empty()) scopeAddress[i].pop();
	}
	while (!returnAddress.empty()) returnAddress.pop();
}
void ProgramStack::push_scope(bool restricted, int type, Num size)
{
	returnAddress.push(vars.size());
	add_variable(-1,type,size);
    scopePosition.push(std::make_pair(vars.size(),memory.size()));
    restrictedScopes.push(scopePosition.size());
    declaredAtScope.push({});
}
int ProgramStack::pop_scope(int address)
{
	int retAddress=returnAddress.top();
	returnAddress.pop();
	if (address!=-1) copy(retAddress,address);
	if (size_t(restrictedScopes.top())==scopePosition.size()) restrictedScopes.pop();
	std::vector<int> declared=declaredAtScope.top();
	declaredAtScope.pop();
	for (size_t i=0;i<declared.size();++i)
	{
        scopeAddress[declared[i]].pop();
	}
	vars.resize(scopePosition.top().first);
	memory.resize(scopePosition.top().second);
	scopePosition.pop();
	return retAddress;
}
int ProgramStack::get_last_scope(int id) const
{
	int scope=-1;
    int lastRestricted=0;
    if (!restrictedScopes.empty()) lastRestricted=restrictedScopes.top();
    if (globalAddress[id]!=-1) scope=0;
    if (!scopeAddress[id].empty() && scopeAddress[id].top().first>=lastRestricted) scope=scopeAddress[id].top().first;
    return scope;
}
int ProgramStack::is_declared(int id) const
{
	int scope=get_last_scope(id);
    if (scope==-1) return 0;
    if (scopePosition.size()>size_t(scope)) return 1;
	return 2;
}
int ProgramStack::get_address(int id) const
{
	int scope=get_last_scope(id);
	if (scope==-1)
	{
		//throw exception
		return -1;
	}
	if (scope==0) return globalAddress[id];
	return scopeAddress[id].top().second;
}
int ProgramStack::size_of_type(int type, Num size) const
{
	int ans=type<NUMBER_OF_PRIMITIVE_TYPES?1:structs[type-NUMBER_OF_PRIMITIVE_TYPES].size;
	if (size) ans=ans*size+1;
	return ans;
}
int ProgramStack::primitive_size_of_type(int type, Num size) const
{
	int ans=type<NUMBER_OF_PRIMITIVE_TYPES && type!=VOID_CODE?1:structs[type-NUMBER_OF_PRIMITIVE_TYPES].primitiveSize;
	if (size) ans=ans*size;
	return ans;
}
int ProgramStack::add_struct(std::vector<std::pair<int, Num>>& members)
{
	Struct newStruct;
	newStruct.members=members;
	newStruct.size=1;
	newStruct.primitiveSize=0;
	for (size_t i=0;i<members.size();++i)
	{
		newStruct.size+=size_of_type(members[i].first,members[i].second);
		newStruct.primitiveSize+=primitive_size_of_type(members[i].first,members[i].second);
	}
	structs.push_back(newStruct);
	return NUMBER_OF_PRIMITIVE_TYPES+structs.size()-1;
}
ProgramStack::~ProgramStack() =default;
