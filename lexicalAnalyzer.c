#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdbool.h>
#include "initTree.h"

/* this funtion is for isFloat, isInterger ,isString
   DON'T use for recognizing  isVariable or isKeyword or isBool !!! 

 0-> zero
 1 | 2 | ..|9 -> natural_num
 - ->sign
 a|b|c|..|z|A|B|..|Z -> letter
 blank -> \t

*/
char convert(char* arr , int start, bool digit){
	char output;
	int i=start;
	char value = arr[i];
		 if(digit && (value =='0'||value=='1'||value=='2'||value=='3'||value=='4'||value=='5'||value=='6'||value=='7'||value=='8'||value=='9'))
			output='d';

		else if(!digit && value =='0')//zero
			output='z';
		
		else if(!digit && (value=='1'||value=='2'||value=='3'||value=='4'||value=='5'||value=='6'||value=='7'||value=='8'||value=='9'))
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
		
		else if (value=='+')
			output='P';	//Plus symbol

		else if (value=='*')
			output='M';	//Multiplication symbol

		else if (value=='/')
			output='V';	//diVide symbol

		else if (value=='_')
			output='u';	//underscore symbol

		else if(value=='<')
			output='L';	//Less symbol

		else if(value=='>')
			output='G';	//Greater symbol

		else if(value=='=')
			output='E';	//EQUAL symbol

		else if(value=='!')
			output='N';	//NOT symbol

		else if(value=='&')
			output='A';	//AND symbol

		else if(value=='|')
			output='O';	//OR symbol (capital alphabet O)

		else if(value==';')
			output='C';	//semiColon symbol

		else if(value=='{')
			output='F';	//left brace symbol

		else if(value=='}')
			output='T';	//right brace symbol

		else if(value=='(')
			output='f';	//left parentheses symbol

		else if(value==')')
			output='t';	//right parentheses symbol

		else if(value==',')
			output='p';	//seperator symbol
		else
			output='0';
		
	
	return output;
}

bool isFloat(struct lexeme * lex, char* arr, int right, int left){

	struct tokenTree *tmp = fHead;
	int count =0;
	int t_count = 0; //last true statement;
	lex->ret=false;
	lex->lex=NULL;
	lex->len=NULL;
	bool first = true;
	/* level*/ 
	while(tmp!=NULL){
			char converted = convert(arr,left+count,false);
				if(converted =='D'){
					char converted2 = convert(arr,left+count+1,false);
					if(converted2 != 'n'&& converted2 != 'z'){
							printf(" in the right of the . n or z has to be come \n");
							printf("the error is on line %d on  this part : ",lex->line);
							for(int i =0 ; i<=count ;i++)
								printf("%c",arr[left+i]);
							printf("\n\n");
									
							assert(0);
					}

				}
				while(tmp!=NULL){
					if(tmp->alpha==converted){
						if(tmp->ret== true){
							t_count =count;
						}
						/* Error handling part */
						if(first){
							if(converted == 'D'){
								printf("left side of . has to be non empty sequence of something not like .xxx \n");
								printf("the error is on line %d on  this part : ",lex->line);
									for(int i =0 ; i<=count ;i++)
										printf("%c",arr[left+i]);
									printf("\n\n");
									assert(0);
							}else
								first =false;
						}else 
							first =false;
					
						break;
					
					}else
						tmp=tmp->sibState;
				}
				count ++;
			/* There is no state for this array */
			if(tmp==NULL){
				 break;
			}
			/* Store things for lex */
			lex->len = count;
			lex->lex = NULL;
			lex->ret=tmp->ret;

			tmp = tmp->childState;
			
	}

	if(lex->ret){
		/* For proper float */
		lex->lex = "FLOAT";
		return lex;
	}
	else if(arr[left+count-2]=='0'&&t_count!=0){
		/* For float like xxx.x00000 */
		lex->len = t_count+1;
		lex->lex = "FLOAT";
		return lex;
	}
	else
		return NULL;

}

bool isVariable(struct lexeme * lex, char* arr, int right, int left){
	struct tokenTree *tmp = varHead;
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
		lex->len = count;
		lex->lex = NULL;
		lex->ret=tmp->ret;
		left++;
		tmp = tmp->childState;
	}

	/*in case of int123 this have to be identifier*/
	char converted= convert(arr,count+left-1,true);
	if(converted == 'd'||converted == 'u'|| converted == 'l'){
		return false;
	}
	if(lex->ret){
		lex->lex = "typeVar";
		return true;
	}else
		return false;

}

bool isInteger(struct lexeme* lex, char* arr, int right, int left){

	struct tokenTree *tmp = intHead;
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
				}
				while(tmp!=NULL){
					if(tmp->alpha==converted){
						if(first){
							if(converted =='z'){
								converted = convert(arr,left+count+1,false);
								if(converted == 'D'){
									isF = isFloat( lex, arr, right,left);
									goto iFloat;
									}else
									first =false;
							}else if(converted =='s'){
								converted = convert(arr,left+count+1,false);
								char findingdot = convert(arr,left+count+2,false);

								if(findingdot == 'D'){
									isF = isFloat( lex, arr, right,left);
									goto iFloat;
								}
							}else
								first =false;
						first= false;
					}
						break;
					}else tmp=tmp->sibState;
				}
				count ++;
			/* There is no state for this array */
			if(tmp==NULL){
				 break;
			}
			/* Store things for lex */
			lex->len = count;
			lex->lex = NULL;
			lex->ret=tmp->ret;

			tmp = tmp->childState;
	}

	if(lex->ret){
		lex->lex = "INT";
		return true;
	}else
		return false;

iFloat:
	if(isF){
		return true;
	}else
		return false;


}

bool isString(struct lexeme* lex, char* arr, int right, int left){
	struct tokenTree *tmp = strHead;
	int count =0;
	lex->ret=false;
	bool eHandler= false;
	int numQ= 0;
	/* level*/ 
	while(tmp!=NULL){
			char converted = convert(arr,left+count,true);
			while(tmp!=NULL){
				if(numQ==1){// we are in String
					if(converted!='"'&&converted!='d'&&converted!='l'&&converted!='b'){
						printf("ERROR!!! String is consist of only by digit or english letter or blank !!! \n ");
						printf("the error is on line %d on  this part : ",lex->line);
						for(int i =0 ; i<=count ;i++){
							printf("%c",arr[left+i]);
						}
						printf("\n\n");
						assert(eHandler);
					}
				}
				if(tmp->alpha==converted){
					/* Error handling part */
					if(arr[left+count]=='"'){
						if((!eHandler)&&(arr[left]==arr[left+1])){ //for "" error handling
							printf("ERROR!!! String must have at least one digit or english letter or blank !!! \n ");
							printf("the error is on line %d on  this part : ",lex->line);
							for(int i =0 ; i<=count ;i++)
								printf("%c",arr[left+i]);
							printf("\n\n");
							assert(eHandler);
						}
						eHandler =true;//" exists so, num of " has to be 2 if String is normal 
						numQ++;
					}
					break;
				}else tmp=tmp->sibState;
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

	/* Error handling part */
	if(eHandler && numQ!=2){
		// for num of " is odd
		printf("ERROR!!!! The number of Double quotes are odd, so String doesn't stop!!! \n");
		printf("the error is on line %d on  this part : ",lex->line);
		for(int i =0 ; i<=count ;i++){
			printf("%c",arr[left+i]);
		}
		printf("\n\n");

		assert(numQ==2);
	}

	if(lex->ret){
		lex->lex = "STRING";
		return true;
	}else
		return false;

}


bool isBoolean(struct lexeme* lex, char* arr, int right, int left){
	struct tokenTree *tmp = boHead;
	int count =0;
	lex->ret=false;
	/* level*/ 
	while(tmp!=NULL){
		while(tmp!=NULL){
			if(tmp->alpha==arr[left+count])
				break;
			else tmp=tmp->sibState;
		}
		count ++;

		/* There is no state for this array */
		if(tmp==NULL){
			break;
		}
		/* Store things for lex */
		lex->len = count;
		lex->lex = NULL;
		lex->ret=tmp->ret;

		tmp = tmp->childState;
	}

	char converted= convert(arr,count+left-1,true);
	if(converted == 'd'||converted == 'u'|| converted == 'l'){
		return false;
	}
	if(lex->ret){
		lex->lex = "BOOL";
		return true;
	}else
		return false;
}



bool isKeyword(struct lexeme* lex, char* arr, int right, int left){

	struct tokenTree *tmp = keyHead;
	int count =0;
	lex->ret=false;
	/* level*/ 
	while(tmp!=NULL){
		while(tmp!=NULL){
			if(tmp->alpha==arr[left + count])
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
		lex->len = count;
		lex->lex = NULL;
		lex->ret=tmp->ret;

		tmp = tmp->childState;
	}
	char converted= convert(arr,count+left-1,true);

	if(converted == 'd'||converted == 'u'|| converted == 'l'){
		return false;
	}		
	if(lex->ret){
		lex->lex = "KeyWord";
		return true;
	}else
		return false;

}


bool isWhiteSpace(struct lexeme* lex, char* arr, int right, int left){
	struct tokenTree *tmp ;//= strHead;
	int count = 0;
	lex->ret=false;
	/* level*/ 
	while(1){
		char converted = convert(arr,left+count,false);
		if('b' == converted){
			/* Store things for lex */
			count ++;
			lex->len = count;
			lex->lex = NULL;
			lex->ret = true;
		}else
			break;
	}
	if(lex->ret){
		lex->lex = "WS";
		return true;
	}else
		return false;
}

//sangjin
//identifier first implement
//error handling needed
bool isIdentifier(struct lexeme* lex, char* arr, int right, int left){
	struct tokenTree *searchTree = idHead;
	int count = 0;
	lex->ret = false;
		while(searchTree != NULL){	//level1
			char converted = convert(arr, left + count, true);	//identifier는 0포함하는 digit사용(3번째 flag true)
			while(searchTree != NULL){
				if(searchTree->alpha == converted) break; //matching character나오면 break
				else searchTree = searchTree->sibState;	//sibling 조사
			}
			count++;
			if(searchTree == NULL)	//there is no state for this array
				break;
			/* Store things for lex (임시저장) */
			lex->len = count;
			lex->lex = NULL;
			lex->ret = searchTree->ret;
			searchTree = searchTree->childState; //child조사
		}
		if(lex->ret){
			lex->lex = "IDENTIFIER";
			return true;
		}else
			return false;
}

//sangjin
//Bitwiseop first implement
//error handling needed (KEEP IN MIND OF PRIORITY!)
bool isBitwiseop(struct lexeme* lex, char* arr, int right, int left){
	struct tokenTree *searchTree = btHead;
	int count = 0;
	lex->ret = false;
	while(searchTree != NULL){
		char converted = convert(arr, left+count, false);
		while(searchTree != NULL){
			if(searchTree->alpha == converted) break;
			else searchTree = searchTree->sibState; //sibling 조사
		}
		count++;
		if(searchTree == NULL)
			break;
		/* Store things for lex */
		lex->len = count;
		lex->lex = NULL;
		lex->ret = searchTree->ret;
		searchTree = searchTree->childState; //child 조사
	}
	if(lex->ret){
		lex->lex = "Bitwise";
		return true;
	}else
		return false;
}

//sangjin
//Bitwiseop first implement
//error handling needed
bool isArithmeticop(struct lexeme* lex, char* arr, int right, int left){
	struct tokenTree *searchTree = aritHead;
	int count = 0;
	lex->ret = false;
	while(searchTree != NULL){
		char converted = convert(arr, left+count, false);
		while(searchTree != NULL){
			if(searchTree->alpha == converted) break;
			else searchTree = searchTree->sibState; //sibling 조사
		}
		count++;
		if(searchTree == NULL)
			break;
		/* Store things for lex */
		lex->len = count;
		lex->lex = NULL;
		lex->ret = searchTree->ret;
		searchTree = searchTree->childState; //child 조사
	}
	if(lex->ret){
		lex->lex = "Arithmatic";
		return true;
	}else
		return false;
}

//sangjin
//Assignop first implement
//error handling needed (KEEP IN MIND OF PRIORITY!)
bool isAssignop(struct lexeme* lex, char* arr, int right, int left){
	struct tokenTree *searchTree = assiHead;
	int count = 0;
	lex->ret = false;
	char converted;
	if(searchTree != NULL)
		converted = convert(arr, left+count, false);
	if(searchTree->alpha == converted) {
		count++;
		/* Store things for lex */
		lex->len = count;
		lex->lex = "Assignment";
		lex->ret = searchTree->ret;
		return true;
	}else
		return false;
}

//sangjin
//Comparisonop first implement
//error handling needed (KEEP IN MIND OF PRIORITY!)
bool isComparisonop(struct lexeme* lex, char* arr, int right, int left){
	struct tokenTree *searchTree = compHead;
	int count = 0;
	lex->ret = false;
	while(searchTree != NULL){
		char converted = convert(arr, left+count, false);
		while(searchTree != NULL){
			if(searchTree->alpha == converted)
				break;
			else searchTree = searchTree->sibState; //sibling 조사
		}
		count++;
		if(searchTree == NULL)
			break;
		/* Store things for lex */
		lex->len = count;
		lex->lex = NULL;
		lex->ret = searchTree->ret;

		searchTree = searchTree->childState; //child 조사
	}

	if(lex->ret){
		lex->lex = "Comparison";
		return true;
	}else
		return false;
}

//sangjin
//termination symbol first implement
//error handling needed
bool isTermin(struct lexeme* lex, char* arr, int right, int left){
	struct tokenTree *searchTree = terHead;
	int count = 0;
	lex->ret = false;
	char converted;
	if(searchTree != NULL)
		converted = convert(arr, left+count, false);
	if(searchTree->alpha == converted) {
		count++;
		/* Store things for lex */
		lex->len = count;
		lex->lex = "Termination";
		lex->ret = searchTree->ret;
		return true;
	}else
		return false;
}

//sangjin
//seperator symbol first implement
//error handling needed
bool isSeperator(struct lexeme* lex, char* arr, int right, int left){
	struct tokenTree *searchTree = sepHead;
	int count = 0;
	lex->ret = false;
	char converted;
	if(searchTree != NULL)
		converted = convert(arr, left+count, false);
	if(searchTree->alpha == converted) {
		count++;
		/* Store things for lex */
		lex->len = count;
		lex->lex = "Seperator";
		lex->ret = searchTree->ret;
		return true;
	}else
		return false;
}


//sangjin
//Brace symbol first implement
//error handling needed
bool isBrace(struct lexeme* lex, char* arr, int right, int left){
	struct tokenTree *searchTree = brcHead;
	int count = 0;
	lex->ret = false;
	char converted;
	while(searchTree != NULL){
		converted = convert(arr, left+count, false);
		while(searchTree != NULL){
			if(searchTree->alpha == converted) break;
			else searchTree = searchTree->sibState; //sibling 조사
		}
		count++;
		if(searchTree == NULL)
			break;
		/* Store things for lex */
		lex->len = count;
		lex->lex = NULL;
		lex->ret = searchTree->ret;
		searchTree = searchTree->childState; //child 조사
	}
	if(converted == 'F'){
		lex->lex = "LBRAC";
	}else if (converted == 'T')
		lex->lex = "RBRAC";

	if(lex->ret) return true;
	else return false;
}

//sangjin
//Parentheses symbol first implement
//error handling needed
bool isParentheses(struct lexeme* lex, char* arr, int right, int left){
	struct tokenTree *searchTree = parHead;
	int count = 0;
	lex->ret = false;
	char converted;
	while(searchTree != NULL){
		converted = convert(arr, left+count, false);
		while(searchTree != NULL){
			if(searchTree->alpha == converted) break;
			else searchTree = searchTree->sibState; //sibling 조사
		}
		count++;
		if(searchTree == NULL)
			break;
		/* Store things for lex */
		lex->len = count;
		lex->lex = NULL;
		lex->ret = searchTree->ret;
		searchTree = searchTree->childState; //child 조사
	}
	if(converted == 'f'){
		lex->lex = "LPAREN";
	}else if (converted == 't')
		lex->lex = "RPAREN";

	if(lex->ret) return true;
	else return false;
}
