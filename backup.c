#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include "lexicalAnalyzer.h"
#include "initTree.h"
//jjeong
struct symbolTable{
	char* name; 
	char* value;
	struct symbolTable *prev;
	struct symbolTable *next;
}

int main(){

	struct symbolTable *head;
	struct symbolTable *oldNode = head;
	bool firstInsert = true;
	while(1 /* until buffer got empty*/ ){

		bool ret = false ;
		ret = isVariable();
		if(ret)
			goto insert;

		ret = isKeyword();
		if(ret)
			goto insert;

		ret = isBoolean();
		if(ret)
			goto insert;

		ret = isFloat();
		if(ret)
			goto insert;

		ret = isInteger();
		if(ret)
			goto insert;

		ret = isString();
		if(ret)
			goto insert;


		/* when you are here there is no more valid token error is needed  */
		break ;
insert : 
		struct symbolTable newNode;
		newNode-> prev = NULL;
		newNode-> prev = NULL;
		newNode-> name = ;
		newNode-> value= ;
		if(firstInsert){
			newNode->prev = head;		
			head-> next = newNode;
		}
		else{
			oldNode-> next = newNode;
			newNode -> prev = oldNode->prev->next;
		

		}
		oldNode = newNode;
	}


}


/*
bool isKeyword(struct lexeme* lex, char* arr, int right, int left){

	


}
*/
