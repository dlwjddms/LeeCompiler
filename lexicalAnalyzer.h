#include<stdio.h>
#include<string.h>

bool isVariable();
bool isInteger(struct lexeme* lex, char* arr, int right, int left);
bool isString();
bool IsBoolean();
bool isFloat();
bool isKeyword(struct lexeme* lex, char* arr, int right, int left);

 
/*
struct lexeme {

	int len;
	char* lex;

};
*/

//zero
//natural_num
//sign
//digit
//letter
//blank
// 등 묶어서 하는거 정해야하튼디 
