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

struct symbolTable*  lexicalAnaylzer(char* arr){

	
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

	while(right<end/* until buffer got empty*/ ){
		struct lexeme *lex = (struct lexeme*)malloc(sizeof(struct lexeme));

		bool ret = false ;
//	임시임;;;
		ret = isWhiteSpace(lex,arr,right,left);
		if(ret)
			goto insert;

		ret = isVariable(lex,arr,right,left);
		if(ret)
			goto insert;

		ret = isKeyword(lex,arr,right,left);
		if(ret)
			goto insert;

		ret = isBoolean(lex,arr,right,left);
		if(ret)
			goto insert;

/*
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
		break;

	insert : 
		right = left+ lex->len;
		struct symbolTable* newNode = (struct symbolTable*)malloc(sizeof(struct symbolTable));
		newNode-> prev = NULL;
		newNode-> prev = NULL;
		newNode-> name = lex->lex;

		printf("55: %s \n",newNode->name);
		char*tmp =(char*)malloc(sizeof(char)*(lex->len)) ;
		for(int i=0; i<lex->len ;i++){
			//strcat(tmp,&arr[i]);
			tmp[i]=arr[left+i];
		}
		printf("\n 66: %s \n",tmp);
		printf("count: %d left: %d, right:%d \n\n",lex->len,left,right);
		newNode-> value= tmp;

		if(firstInsert){
			head = newNode;
			//tail = newNode;

			firstInsert=false;
		}
		else{
			oldNode-> next = newNode;
			newNode -> prev = oldNode;
			//tail = newNode;

		}
		oldNode = newNode;
		left = right;
		free(lex);
	}

//	freeTree();
/*
	struct symbolTable *tail=(struct symbolTable*)malloc(sizeof(struct symbolTable));
	tail ->value = "end";
	oldNode ->next =tail;
	tail ->prev = oldNode;
*/
	return  head;

}


int main(){

	struct symbolTable *head =(struct symbolTable*)malloc(sizeof(struct symbolTable));

	struct symbolTable *tail=(struct symbolTable*)malloc(sizeof(struct symbolTable));


    int size;
    int count=1;

    FILE *r_fp = fopen("hello.txt", "r");    // hello.txt 파일을 읽기 모드(r)로 열기.
                                           // 파일 포인터를 반환

    fseek(r_fp, 0, SEEK_END);    // 파일 포인터를 파일의 끝으로 이동시킴
    size = ftell(r_fp);          // 파일 포인터의 현재 위치를 얻음

	char *lineBuf;
    lineBuf = malloc(size + 1);    // 파일 크기 + 1바이트(문자열 마지막의 NULL)만큼 동적 메모리 할당
    memset(lineBuf, 0, size + 1);  // 파일 크기 + 1바이트만큼 메모리를 0으로 초기화
    fseek(r_fp, 0, SEEK_SET);                // 파일 포인터를 파일의 처음으로 이동시킴
   // count = fread(buffer, size, 1, r_fp);    // hello.txt에서 파일 크기만큼 값을 읽음
	char*buffer =malloc(size+1);
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

    free(lineBuf);   // 동적 메모리 해제
	printf("%s\n",buffer);
	head = lexicalAnaylzer(buffer);


	 fclose(r_fp);     // 파일 포인터 닫기

    free(buffer);   // 동적 메모리 해제



	FILE *w_fp = fopen("output.out", "w+"); 
      // hello.txt 파일을 쓰기 모드(w)로 열기.


	//	some modify is needed
	struct symbolTable *tmp = head;
	if(tmp !=NULL){
		for( ;tmp != NULL ; tmp = tmp->next){
			fputs( tmp->name, w_fp);   // 파일에 문자열 저장
			fputs( " : ", w_fp);   // 파일에 문자열 저장
			fputs( tmp->value, w_fp);   // 파일에 문자열 저장
			fputs( "\n", w_fp);   // 파일에 문자열 저장
		}

		
	}
    fclose(w_fp); 
	//symbolTables free is need... right..?

		return 0;
}


