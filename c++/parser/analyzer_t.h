#ifndef ANALYZE_H
#define ANALYZE_H

#include <string>
#include <set>
#include <queue>
#include <stdio.h>
#include <fstream> 
#include <iostream>
#include <map> 

using namespace std;


class analyzer_t{
	public:
		~analyzer_t(){;}
		analyzer_t();
		void analyzer(queue<string>&);
		void tokenAnalyzer(const string& token);
		bool checkPlusMinus(const string& token);
		bool checkPreDefinedTypes(const string& token);
		void checkAfterPredfined(const string& token);
		bool validName(const string& token) const;
		bool checkBraces(const string& token, const string& open, const string& close);
		void endRun();

	private:
		unsigned int m_numLine;
		static set<string> m_predefinedTokens;
		static set<string> m_predefinedTypes;
		static set<string> m_keyWords;
		static set<string> m_operators;

		map<string,int> m_bracesCount;

		int plusCounter;
		int minusCounter;

		set<string> m_symbolTable;

		bool m_beginMain;
		bool m_predefined;
		analyzer_t(const analyzer_t&);
		analyzer_t& operator=(const analyzer_t&);
};



#endif