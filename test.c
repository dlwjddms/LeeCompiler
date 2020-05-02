#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include "lexicalAnalyzer.h"
#include "initTree.h"
//jjeong

struct lexeme {

	int len;
	char* lex;
	bool ret;
};

struct symbolTable{
	char* name; 
	char* value;
	struct symbolTable *prev;
	struct symbolTable *next;
};

int main(){
	struct lexeme *lex = (struct lexeme*)malloc(sizeof(struct lexeme));
	char *input = "11120;";
	printf("%d\n",strlen(input));
	initTree()	;
	isInteger(lex,input,6,0);
	printf("%s \n",lex->lex);
	return 0;
}
