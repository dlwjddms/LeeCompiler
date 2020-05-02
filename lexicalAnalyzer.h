#include<stdio.h>
#include<string.h>

bool isVariable(struct lexeme* lex, char* arr, int right, int left);
bool isInteger(struct lexeme* lex, char* arr, int right, int left);
bool isString(struct lexeme* lex, char* arr, int right, int left);
bool IsBoolean(struct lexeme* lex, char* arr, int right, int left);
bool isFloat(struct lexeme* lex, char* arr, int right, int left);
bool isKeyword(struct lexeme* lex, char* arr, int right, int left);
bool isWhiteSpace(struct lexeme* lex, char* arr, int right, int left);

 
/*
struct lexeme {

	int len;
	char* lex;

};
struct lexeme {

	int len;
	char* lex;
	bool ret;

};

*/

//zero
//natural_num
//sign
//digit
//letter
//blank
// 등 묶어서 하는거 정해야하튼디 
