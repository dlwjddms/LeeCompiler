#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include "initTree.h"

struct lexeme {

	int len;
	char* lex;
	bool ret;

};


/* this funtion is for isFloat, isInterger ,isString
   DON'T use for isVariable or isKeyword or isBool !!! 

 0-> zero
 1 | 2 | ..|9 -> natural_num
 - ->sign
 a|b|c|..|z|A|B|..|Z -> letter
 blank -> \t

*/
char convert(char* arr , int start){
	
	//char*input = arr;
	char output;
	int i=start;
	//while(arr[i]!=NULL){
	char value = arr[i];
		if(value =='0')//zero
			output='z';
		
		else if(value=='1'||value=='2'||value=='3'||value=='4'||value=='5'||value=='6'||value=='7'||value=='8'||value=='9')
			output='n';

		else if(value=='q'||value=='w'||value=='e'||value=='r'||value=='t'||value=='y'||value=='u'||value=='i'||value=='o'||value=='p'||value=='a'||value=='s'||value=='d'||value=='f'||value=='g'||value=='h'||value=='j'||value=='k'||value=='l'||value=='z'||value=='x'||value=='c'||value=='v'||value=='b'||value=='n'||value=='m'||value=='Q'||value=='W'||value=='E'||value=='R'||value=='T'||value=='Y'||value=='U'||value=='I'||value=='O'||value=='P'||value=='A'||value=='S'||value=='D'||value=='F'||value=='G'||value=='H'||value=='J'||value=='K'||value=='L'||value=='Z'||value=='X'||value=='C'||value=='V'||value=='B'||value=='N'||value=='M')	
			output='l';

		else if(value=='-')
			output='s';
		
		else if (value==' ')
			output='b';
		else
			output='0';
		
	
	return output;
}

bool isVariable(struct lexeme * lex, char* arr, int right, int left){

	//char* converted = convert(arr,left);

}

bool isInteger(struct lexeme* lex, char* arr, int right, int left){

	struct tokenTree *tmp = intHead;
	bool tmp_ret = false;
	int count =0;
	lex->ret=false;
	/* level*/ 
	while(tmp!=NULL){
			char converted = convert(arr,left+count);

				while(tmp->alpha!='e'){
				if(tmp->alpha==converted)
						break;
				else
					tmp=tmp->sibState;
			}
			count ++;
			/* There is no state for this array */
			if(tmp->alpha=='e'){
				 break;
			}
			/* Store things for lex */
			// I'm not sure this position is right
			lex->len = count;
			lex->lex = NULL;
			lex->ret=tmp->ret;

			tmp = tmp->childState;
			
	}
	if(lex->ret){
		lex->lex = "integer";
		return true;
	}

	else
		return false;
}

bool isString(struct lexeme* lex, char* arr, int right, int left){

	char converted = convert(arr,left);

}

