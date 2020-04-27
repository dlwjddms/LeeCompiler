#include<stdio.h>
#include<string.h>

bool isVariable();
bool isInteger();
bool isString();
bool IsBoolean();
bool isFloat();
bool isKeyword(struct lexeme* lex, char* arr, int right, int left);

struct tokenTree{
		char alpha ;
		bool ret ;
		struct tokenTree *childState;
		struct tokenTree *sibState;
}

struct tokenTree* varHead ;
struct tokenTree* intHead ;
struct tokenTree* strHead ;
struct tokenTree* boHead ;
struct tokenTree* fHead ;
struct tokenTree* keyHead ;

struct symbolTable{
	char* name; 
	char* value;
	struct symbolTable *prev;
	struct symbolTable *next;
} 

struct lexeme {

	int len;
	char* lex;

}

void initTree(){};
void initKeyword(){}; 
void initBoolean(){};
void initString(){};
void initInterger(){};
void initVarTree(){};
	
//zero
//natural_num
//sign
//digit
//letter
//blank
// 등 묶어서 하는거 정해야하튼디 
