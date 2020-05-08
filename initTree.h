#include<stdio.h>
#include<string.h>


struct tokenTree{
		char alpha ;
		bool ret ;
		struct tokenTree *childState;
		struct tokenTree *sibState;
};

struct lexeme {
	int len;
	char* lex;
	bool ret;
};

struct tokenTree* varHead ;
struct tokenTree* intHead ;
struct tokenTree* strHead ;
struct tokenTree* boHead ;
struct tokenTree* fHead ;
struct tokenTree* keyHead ;
struct tokenTree* idHead ;
struct tokenTree* btHead ;
struct tokenTree* compHead ;
struct tokenTree* assiHead ;
struct tokenTree* aritHead ;
struct tokenTree* terHead ;
struct tokenTree* brcHead ;
struct tokenTree* parHead ;
struct tokenTree* sepHead ;

void initTree();
void freeTree();
void initKeyword(); 
void initBoolean();
void initString();
void initInteger();
void initFloat();
void initVarTree();
void initIdentifier();
void initBitwiseop();
void initComparisonop();
void initAssignop();
void initArithop();
void initTermin();
void initBrace();
void initParentheses();
void initSeperator();
	
