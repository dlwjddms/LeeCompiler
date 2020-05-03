#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdbool.h>
#include "initTree.h"

struct lexeme {

	int len;
	char* lex;
	bool ret;
	bool val;

};
/* this funtion is for isFloat, isInterger ,isString
   DON'T use for isVariable or isKeyword or isBool !!! 

 0-> zero
 1 | 2 | ..|9 -> natural_num
 - ->sign
 a|b|c|..|z|A|B|..|Z -> letter
 blank -> \t

*/
char convert(char* arr , int start, bool Str){
	
	//char*input = arr;
	char output;
	int i=start;
	//while(arr[i]!=NULL){
	char value = arr[i];

		 if(Str && (value =='0'||value=='1'||value=='2'||value=='3'||value=='4'||value=='5'||value=='6'||value=='7'||value=='8'||value=='9'))
			output='d';

		else if(!Str && value =='0')//zero
			output='z';
		
		else if(!Str && (value=='1'||value=='2'||value=='3'||value=='4'||value=='5'||value=='6'||value=='7'||value=='8'||value=='9'))
			output='n';

		else if(value=='q'||value=='w'||value=='e'||value=='r'||value=='t'||value=='y'||value=='u'||value=='i'||value=='o'||value=='p'||value=='a'||value=='s'||value=='d'||value=='f'||value=='g'||value=='h'||value=='j'||value=='k'||value=='l'||value=='z'||value=='x'||value=='c'||value=='v'||value=='b'||value=='n'||value=='m'||value=='Q'||value=='W'||value=='E'||value=='R'||value=='T'||value=='Y'||value=='U'||value=='I'||value=='O'||value=='P'||value=='A'||value=='S'||value=='D'||value=='F'||value=='G'||value=='H'||value=='J'||value=='K'||value=='L'||value=='Z'||value=='X'||value=='C'||value=='V'||value=='B'||value=='N'||value=='M')	
			output='l';

		else if(value=='-')
			output='s';
	
		else if(value=='.')
			output='D';	

		else if(value=='"')
			output='"';	


		else if (value==' '||value=='\n'||value =='\t')
			output='b';
		else
			output='0';
		
	
	return output;
}

bool isFloat(struct lexeme * lex, char* arr, int right, int left){

}

bool isVariable(struct lexeme * lex, char* arr, int right, int left){

	//char* converted = convert(arr,left);
	struct tokenTree *tmp = varHead;
	bool tmp_ret = false;
	int count =0;
	lex->ret=false;
	/* level*/ 
	while(tmp!=NULL){
		while(tmp!=NULL){
			if(tmp->alpha==arr[left])
				break;
			else
				tmp=tmp->sibState;
		}
		count ++;
		/* There is no state for this array */
		if(tmp==NULL){
			break;
		}
		/* Store things for lex */
		// I'm not sure this position is right
		lex->len = count;
		lex->lex = NULL;
		lex->ret=tmp->ret;
		//
		left++;
		tmp = tmp->childState;
	}

	if(lex->ret){
		lex->lex = "typeVar";
		return true;
	}

	else
		return false;

}

bool isInteger(struct lexeme* lex, char* arr, int right, int left){

	struct tokenTree *tmp = intHead;
	bool tmp_ret = false;
	int count =0;
	lex->ret=false;
	bool first = true;
	bool isF =false;
	/* level*/ 
	while(tmp!=NULL){
			char converted = convert(arr,left+count,false);

				if(converted =='D'){

						isF = isFloat( lex, arr, right,left);			
						goto iFloat;
	//					break;
				}

				while(tmp!=NULL){
				if(tmp->alpha==converted){
					if(first){
						if(converted =='z'){
							converted = convert(arr,left+count+1,false);
							//char findingdot = convert(arr,left+count+2);
							//this should be outside or not ..? of first think more

							if(converted == 'D'){
								isF = isFloat( lex, arr, right,left);
								goto iFloat;
								//break;->return
								}
							else{	
								printf("zero doesn't come first in noninteger\n");
								assert(converted !='z'&&converted!='n');
								}
							}

						else if(converted =='s'){
							converted = convert(arr,left+count+1,false);
						//	 this should be outside or not .. ? of first think more
							char findingdot = convert(arr,left+count+2,false);
								if(findingdot == 'D'){
										isF = isFloat( lex, arr, right,left);
										goto iFloat;
									//	break;->return
								}
								else{
									printf("there is no zero with - \n");
									assert(converted !='z');
								}
							}

						else
							first =false;
						first =false;
						}

					break;
					}
				else
					tmp=tmp->sibState;
			}
			count ++;
			/* There is no state for this array */
			if(tmp==NULL){
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
		lex->lex = "INT";
		return true;
	}

	else
		return false;
iFloat:
		if(lex->ret){
		lex->lex = "FOAT";
		return true;
		}
	else
		return false;


}

bool isString(struct lexeme* lex, char* arr, int right, int left){


	struct tokenTree *tmp = strHead;
	bool tmp_ret = false;
	int count =0;
	lex->ret=false;
	/* level*/ 
	while(tmp!=NULL){
			char converted = convert(arr,left+count,true);

				while(tmp!=NULL){
				if(tmp->alpha==converted){
						break;
					}
				else
					tmp=tmp->sibState;
			}
			count ++;

			/* There is no state for this array */
			if(tmp==NULL){
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
		lex->lex = "STRING";
		return true;
	}

	else
		return false;

}



bool isBoolean(struct lexeme* lex, char* arr, int right, int left){

	struct tokenTree *tmp = boHead;
	bool tmp_ret = false;
	int count =0;
	lex->ret=false;
	/* level*/ 
	while(tmp!=NULL){
		while(tmp!=NULL){
			if(tmp->alpha==arr[left])
				break;
			else
				tmp=tmp->sibState;
		}
		count ++;
		/* There is no state for this array */
		if(tmp==NULL){
			break;
		}
		/* Store things for lex */
		// I'm not sure this position is right
		lex->len = count;
		lex->lex = NULL;
		lex->ret=tmp->ret;
		//
		left++;
		tmp = tmp->childState;
	}

	if(lex->ret){
		lex->lex = "BOOL";
		return true;
	}

	else
		return false;

}



bool isKeyword(struct lexeme* lex, char* arr, int right, int left){


	struct tokenTree *tmp = keyHead;
	bool tmp_ret = false;
	int count =0;
	lex->ret=false;
	/* level*/ 
	while(tmp!=NULL){
		while(tmp!=NULL){
			if(tmp->alpha==arr[left])
				break;
			else
				tmp=tmp->sibState;
		}
		count ++;
		/* There is no state for this array */
		if(tmp==NULL){
			break;
		}
		/* Store things for lex */
		// I'm not sure this position is right
		lex->len = count;
		lex->lex = NULL;
		lex->ret=tmp->ret;
		//
		left++;
		tmp = tmp->childState;
	}

	if(lex->ret){
		lex->lex = "KeyWord";
		return true;
	}

	else
		
		return false;

}


bool isWhiteSpace(struct lexeme* lex, char* arr, int right, int left){

	struct tokenTree *tmp ;//= strHead;
	bool tmp_ret = false;
	int count =0;
	lex->ret=false;
	/* level*/ 
	while(1){
			char converted = convert(arr,left+count,false);

				if('b'==converted){
						/* Store things for lex */
						// I'm not sure this position is right
						count ++;
						lex->len = count;
						lex->lex = NULL;
						lex->ret = true;
				}
				else
				 break;
				
	}
	if(lex->ret){
		lex->lex = "WS";
		return true;
	}

	else
		return false;
}



