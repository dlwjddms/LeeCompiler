#define _CRT_SECURE_NO_WARNINGS    // fopen 보안 경고로 인한 컴파일 에러 방지
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdbool.h>
#include<stdlib.h>
#include "lexicalAnalyzer.h"
#include "initTree.h"

//jjeong
struct symbolTable{
	char* name; 
	char* value;
	struct symbolTable *prev;
	struct symbolTable *next;
};

/* variable for total assert*/
bool success = true;

struct symbolTable*  lexicalAnalyze(char* arr){

	/*this is used for printing the position of worng code */
	int line =0;

	/*The head of the symboltable group*/
	struct symbolTable *head =(struct symbolTable*)malloc(sizeof(struct symbolTable));
	struct symbolTable *oldNode = head;
	bool firstInsert = true;

	/*
	 * left node is for start position for checking token,
	 * right node is for end position of checken token
	 */
	int left =0, right= 0;
	int end = strlen(arr);
	initTree();

	/* -- priority --
	 *  Float >> Signed integer >> Arith
	 *  Id >> integer
	 *  Bool,varable,keyword >> Id
	 *  Compare(==) >> assign(=)
	 */
	while(right<end/* until buffer got empty*/ ){
		struct lexeme *lex = (struct lexeme*)malloc(sizeof(struct lexeme));
		lex ->line = line +1;
		bool ret = false ;

		int test =0;
		ret = isWhiteSpace(lex,arr,right,left);
		if(ret)
			goto insert;

		ret = isBoolean(lex,arr,right,left);
		if(ret)
			goto insert;
		
		ret = isVariable(lex,arr,right,left);
		if(ret)
			goto insert;

		ret = isKeyword(lex,arr,right,left);
		if(ret)
			goto insert;

		ret = isIdentifier(lex,arr,right,left);
		if(ret)
			goto insert;

		ret = isInteger(lex,arr,right,left);
		if(ret)
			goto insert;

		ret = isString(lex,arr,right,left);
		if(ret)
			goto insert;
			
			
		ret = isArithmeticop(lex,arr,right,left);
		if(ret)
			goto insert;

		ret = isBitwiseop(lex,arr,right,left);
		if(ret)
			goto insert;
		
		ret = isComparisonop(lex,arr,right,left);
		if(ret)
			goto insert;
		
		ret = isAssignop(lex,arr,right,left);
		if(ret)
			goto insert;

		ret = isTermin(lex,arr,right,left);
		if(ret)
			goto insert;
		
		ret = isBrace(lex,arr,right,left);
		if(ret)
			goto insert;
		
		ret = isParentheses(lex,arr,right,left);
		if(ret)
			goto insert;

		ret = isSeperator(lex,arr,right,left);
		if(ret)
			goto insert;

		/* when you are here there is no more valid token error is needed  */
		free(lex);
		success = false;
		break;	

	insert : 
		right = left+ lex->len;
		struct symbolTable* newNode = (struct symbolTable*)malloc(sizeof(struct symbolTable));
		newNode-> prev = NULL;
		newNode-> name = lex->lex;

		char*tmp =(char*)malloc(sizeof(char)*(lex->len)) ;
			for(int j=0,i=0; i<lex->len ;i++){
				if(arr[left+i] != '"'){
					tmp[j]=arr[left+i];
					j++;
				}
				if(arr[left+i]=='\n')
					line++;

			}
			newNode-> value= tmp;
		
		if(firstInsert){
			head = newNode;

			firstInsert=false;
		}
		else{
			oldNode-> next = newNode;
			newNode -> prev = oldNode;

		}
		oldNode = newNode;
		left = right;
		free(lex);
	}

//	freeTree();

	return  head;

}


int main(int argc, char* argv[]){

	struct symbolTable *head =(struct symbolTable*)malloc(sizeof(struct symbolTable));


    int size;
    int count=1;

	/* Input file open error handling */
	if(argv[1] == NULL){
		printf("file is not valid");
		assert(argv[1] !=NULL);

	}

	/* Input file open */
    FILE *r_fp = fopen(argv[1], "r");   
	fseek(r_fp, 0, SEEK_END);  
	size = ftell(r_fp);
    fseek(r_fp, 0, SEEK_SET);                

	char *lineBuf= malloc(size + 1);    
    memset(lineBuf, 0, size + 1); 

	/*Buffer for storing evet data*/
	char*buffer =malloc(size+1);
  

	/* Read every thing until the file meets the end */
	while(fgets(lineBuf,size,r_fp)!=NULL){
		count++;
		char*Tmp ;
		Tmp = malloc(size*count + 1);  
		strcpy(Tmp ,buffer);
		realloc(buffer,size*count + 1);  
		strcat(Tmp,lineBuf);	
		buffer=Tmp;
		Tmp=NULL;
	}

    free(lineBuf);   

	/* Send buffer to lexicalAnaylzer to make symbol table  */
	head = lexicalAnalyze(buffer);

	fclose(r_fp);   
	free(buffer);   



	/* Make output .out file which has same name with input file */
	/* The input file type must be hello.c not ./hello.c */
	char*nameTmp = strtok(argv[1],".");
	char *fileName =malloc(sizeof(char)*(strlen(nameTmp)+4));
	strcpy(fileName, nameTmp);
	strcat(fileName,".out");
	FILE *w_fp = fopen(fileName, "w"); 

	/*File open error handling*/
	if(!w_fp)
		return 0;

	struct symbolTable *tmp = head;

	/*If symbol table exists store them into outputfile unless it is WS*/
	if(tmp !=NULL){
		for( ;tmp != NULL ; tmp = tmp->next){
			if(strcmp(tmp->name, "WS")){
			fputs( tmp->name, w_fp);   // 파일에 문자열 저장
			fputs( ":", w_fp);   // 파일에 문자열 저장
			fputs( tmp->value, w_fp);   // 파일에 문자열 저장
			fputs( "\n", w_fp);   // 파일에 문자열 저장
			}
		}

		
	}
    fclose(w_fp); 

	if(!success)
		printf("ERROR!!!! : some code which is not allowed of using is used!!! \n\n");
	assert(success);
	//symbolTables free is need... right..?

		return 0;
}


