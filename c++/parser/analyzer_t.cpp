#include "analyzer_t.h"

set<string> analyzer_t::m_predefinedTypes=
	{"char", "short", "int", "long", "float", "double", "void"};
set<string> analyzer_t::m_keyWords=
	{"if", "else", "for" , "while", "class", 
		"private", "public", "protected", "main", "const", "virtual"};
set<string> analyzer_t::m_operators=
	{"++", "--", "==", "->" , "=", "+", "-", "*", "&", "<<", ">>"};
set<string> analyzer_t::m_predefinedTokens=
	{"(", ")", "[", "]" , "{" , "}", ";", "<", ">" , "=", "+", "-", "*", "&"};


void analyzer_t::endRun(){
	if(m_bracesCount["("]>0){
		cout<<"error, "<<m_bracesCount["("]<<" '(' not closed"<<endl;
	}
	if(m_bracesCount["["]>0){
		cout<<"error, "<<m_bracesCount["["]<<" '[' not closed"<<endl;
	}
	if(m_bracesCount["{"]>0){
		cout<<"error, "<<m_bracesCount["{"]<<" '{' not closed"<<endl;
	}

	m_beginMain=false;
	m_predefined=false;
	m_numLine=0;
	m_bracesCount["("] = 0;
	m_bracesCount["["] = 0;
	m_bracesCount["{"] = 0;	
	m_bracesCount["if"] = 0;
	plusCounter=0;
	minusCounter=0;
	m_symbolTable.clear();

}

analyzer_t::analyzer_t(){
	m_beginMain=false;
	m_predefined=false;
	m_numLine=0;
	m_bracesCount["("] = 0;
	m_bracesCount["["] = 0;
	m_bracesCount["{"] = 0;	
	m_bracesCount["if"] = 0;
	plusCounter=0;
	minusCounter=0;
}


void analyzer_t::analyzer(queue<string>& q){
	m_numLine++;
	string token = q.front();
	while (!q.empty()){
		tokenAnalyzer(token);
		q.pop();
		token=q.front();
	}
}

void analyzer_t::tokenAnalyzer(const string& token){
	if(!m_beginMain){
		if(token != "main"){
			cout<<"line "<<m_numLine<<": error - illegal-declaration before 'main'"<<endl;
		}
		m_beginMain = true;
	}

	if(checkPlusMinus(token)){
		return;
	}

	if (checkBraces(token,"(",")") ||
		checkBraces(token,"[","]") ||
		checkBraces(token,"{","}") ||
		checkBraces(token,"if","else")){
		plusCounter=0;
		minusCounter=0;
		return;
	}

	if(checkPreDefinedTypes(token)){
		plusCounter=0;
		minusCounter=0;
		return;
	}

	if(m_predefined){
		checkAfterPredfined(token);
	}
	else
	{
		if (!(m_keyWords.find(token) != m_keyWords.end() ||
			m_operators.find(token) != m_operators.end() ||
			m_predefinedTokens.find(token) != m_predefinedTokens.end()) &&
			validName(token) &&
			m_symbolTable.find(token) == m_symbolTable.end())
		{
			cout<<"line "<<m_numLine<<": error - "<<token<<" is not declared\n"<<endl;
		}
	}


}

bool analyzer_t::checkPlusMinus(const string& token){
	if(token=="+"){
		plusCounter++;
		minusCounter=0;
		if(plusCounter>2){
			cout<<"line "<<m_numLine<<": error - no operator ";
			cout<<token<<token<<token<<endl;
			plusCounter=0;
			return true;
		}
	}
	if(token=="-"){
		minusCounter++;
		plusCounter=0;
		if(minusCounter>2){
			cout<<"line "<<m_numLine<<": error - no operator ";
			cout<<token<<token<<token<<endl;
			plusCounter=0;
			return true;
		}
	}

	return false;
}

bool analyzer_t::checkPreDefinedTypes(const string& token){
	if (m_predefinedTypes.find(token) != m_predefinedTypes.end()){
		if(m_predefined)
		{
			cout<<"line "<<m_numLine<<": error, multiple type"<<endl;
			cout<<"line "<<m_numLine<<": error,'"<<token<<"' is not declared"<<endl;
			m_predefined = false;
		}else{
			m_predefined = true;
		}
		return true;
	}
}

void analyzer_t::checkAfterPredfined(const string& token){
	if (m_keyWords.find(token) != m_keyWords.end() ||
		m_predefinedTokens.find(token) != m_predefinedTokens.end()||
		m_operators.find(token) != m_operators.end()){
		cout<<"line "<<m_numLine<<": error, illegal variable name"<<endl;
	}
	else{
		if(m_symbolTable.find(token) != m_symbolTable.end()){
			cout<<"line "<<m_numLine<<": error, variable '"<<token<<"' already declared"<<endl;			
		}
		else{
			if(validName(token)){
				m_symbolTable.insert(token);
			}
			else{
				cout<<"line "<<m_numLine<<": error, illegal variable name\n"<<endl;
			}
		}
	}

	m_predefined = false;
}

bool analyzer_t::validName(const string& token) const{
	return (token[0] == '_'||isalpha(token[0]));
}

bool analyzer_t::checkBraces(const string& token, const string& open, const string& close){
	if(token == open){
		m_bracesCount[open]++;
		
		return true;
	}

	if(token ==close){
		if(0 < m_bracesCount[open]){
			m_bracesCount[open]--;
		}
		else{
			cout<<"line "<<m_numLine<<": error,"<<close<<" without "<<open<<"\n"<<endl;
		}
		return true;
	}
	
	return false;	
} 