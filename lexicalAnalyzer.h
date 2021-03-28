/*
* function prototypes
* Is*() functions run DFAs
*/

#include<stdio.h>
#include<string.h>

bool isVariable(struct lexeme* lex, char* arr, int right, int left);
bool isInteger(struct lexeme* lex, char* arr, int right, int left);
bool isString(struct lexeme* lex, char* arr, int right, int left);
bool IsBoolean(struct lexeme* lex, char* arr, int right, int left);
bool isFloat(struct lexeme* lex, char* arr, int right, int left);
bool isKeyword(struct lexeme* lex, char* arr, int right, int left);
bool isWhiteSpace(struct lexeme* lex, char* arr, int right, int left);
bool isIdentifier(struct lexeme* lex, char* arr, int right, int left);
bool isBitwiseop(struct lexeme* lex, char* arr, int right, int left);
bool isComparisonop(struct lexeme* lex, char* arr, int right, int left);
bool isAssignop(struct lexeme* lex, char* arr, int right, int left);
bool isArithmeticop(struct lexeme* lex, char* arr, int right, int left);
bool isTermin(struct lexeme* lex, char* arr, int right, int left);
bool isBrace(struct lexeme* lex, char* arr, int right, int left);
bool isParentheses(struct lexeme* lex, char* arr, int right, int left);
bool isSeperator(struct lexeme* lex, char* arr, int right, int left);
