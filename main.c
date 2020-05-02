#define _CRT_SECURE_NO_WARNINGS    // fopen 보안 경고로 인한 컴파일 에러 방지
#include<stdio.h>
#include<string.h>
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

struct lexeme {

	int len;
	char* lex;
	bool ret;
};

struct symbolTable* lexicalAnaylzer(char* arr){

	struct symbolTable *head;
	struct symbolTable *tail;
	struct symbolTable *oldNode = head;
	bool firstInsert = true;

	/*
	 * left node is for start position for checking token,
	 * right node is for end position of checken token
	 */
	int left =0, right= 0;

	initTree();

	while(1 /* until buffer got empty*/ ){
		struct lexeme *lex = (struct lexeme*)malloc(sizeof(struct lexeme));

		bool ret = false ;
		/*
		ret = isVariable(lex,arr,right,left);
		if(ret)
			goto insert;

		ret = isKeyword(lex,arr,right,left);
		if(ret)
			goto insert;

		ret = isBoolean(lex,arr,right,left);
		if(ret)
			goto insert;

		ret = isFloat(lex,arr,right,left);
		if(ret)
			goto insert;
*/
		ret = isInteger(lex,arr,right,left);
		if(ret)
			goto insert;

		ret = isString(lex,arr,right,left);
		if(ret)
			goto insert;


		/* when you are here there is no more valid token error is needed  */
		free(lex);
		break ;

insert : 
		right = left+ lex->len;
		struct symbolTable* newNode = (struct symbolTable*)malloc(sizeof(struct symbolTable));
		newNode-> prev = NULL;
		newNode-> prev = NULL;
		newNode-> name = lex->lex;

		char*tmp = &arr[left] ;
		for(int i= left+1; i>right ; i++){
			strcat(tmp,&arr[i]);
		}
		newNode-> value= tmp;

		if(firstInsert){
			head = newNode;
			tail = newNode;

			firstInsert=false;
		}
		else{
			oldNode-> next = newNode;
			newNode -> prev = oldNode;
			tail = newNode;

		}
		oldNode = newNode;
		left = right;
		free(lex);
	}

	freeTree();

	return  head;

}


int main(){

	char *buffer;
    int size;
    int count;

    FILE *fp = fopen("hello.txt", "r");    // hello.txt 파일을 읽기 모드(r)로 열기.
                                           // 파일 포인터를 반환

    fseek(fp, 0, SEEK_END);    // 파일 포인터를 파일의 끝으로 이동시킴
    size = ftell(fp);          // 파일 포인터의 현재 위치를 얻음

    buffer = malloc(size + 1);    // 파일 크기 + 1바이트(문자열 마지막의 NULL)만큼 동적 메모리 할당
    memset(buffer, 0, size + 1);  // 파일 크기 + 1바이트만큼 메모리를 0으로 초기화

    fseek(fp, 0, SEEK_SET);                // 파일 포인터를 파일의 처음으로 이동시킴
    count = fread(buffer, size, 1, fp);    // hello.txt에서 파일 크기만큼 값을 읽음

	struct symbolTable *head;
	head = lexicalAnaylzer(buffer);

    printf("%s size: %d, count: %d\n", buffer, size, count);
                    // Hello world! size: 13, count: 1: 파일의 내용, 파일 크기, 읽은 횟수 출력

    fclose(fp);     // 파일 포인터 닫기

    free(buffer);   // 동적 메모리 해제

		return 0;
}


