#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include "initTree.h"

//bool isVariable();
//bool isInteger();
//bool isString();
//bool IsBoolean();
//bool isFloat();
//bool isKeyword(struct lexeme* lex, char* arr, int right, int left);

//struct tokenTree* getNewNode (){};


/* Insert sNode sibling of fNode */
/* but not used yet */
void insertToNextNode(struct tokenTree * fNode, struct tokenTree * sNode){

	struct tokenTree* tmp= fNode->sibState;
	while(tmp){
		tmp = tmp -> sibState;
			// if we have sampe vale already assert
			//----- right..???
	}
    tmp = sNode;	
}


/*
void initKeyword(){



} 
*/

void initBoolean(){

	/* Start state for boolean tree */
	//oboHead ->ret = false;

	/* For level 1 */
	struct tokenTree fLevel1 ;
	//boHead ->childState = &fLevel1;		
	boHead  = &fLevel1;		
    fLevel1 . alpha = 't';
	fLevel1 . ret= false;

	struct tokenTree fLevel2; 
	fLevel1 .sibState = &fLevel2;	
    fLevel2 . alpha = 'f';
	fLevel2 . ret =false;

	struct tokenTree fLevel3 ; 
	fLevel2 .sibState = &fLevel3;		
    fLevel3 . alpha = 'T';
	fLevel3 . ret =false;
    
	struct tokenTree fLevel4; 
	fLevel3 .sibState =  &fLevel4;		
    fLevel4 . alpha = 'F';
	fLevel4 . ret =false;

	/* For level 2 */
	struct tokenTree sLevel1;
	fLevel1 .childState = &sLevel1 ;		
    sLevel1 .alpha = 'r';
	sLevel1 . ret =false;

	struct tokenTree sLevel2;
	fLevel2 .childState = &sLevel2 ;		
    sLevel2 . alpha = 'a';
	sLevel2 . ret =false;

	struct tokenTree sLevel3 ;
	fLevel3 .childState =  &sLevel3 ;		
    sLevel3 . alpha = 'R';
	sLevel3 . ret =false;
    
	struct tokenTree sLevel4 ;
	fLevel4 .childState =&sLevel4;		
    sLevel4 . alpha = 'A';
	sLevel4 . ret =false;

	/* For level 3 */
	struct tokenTree tLevel1 ;
	sLevel1 .childState = &tLevel1 ;		
    tLevel1 . alpha = 'u';
	tLevel1 . ret =false;
	tLevel1.childState= NULL;

	struct tokenTree tLevel2;
	sLevel2 .childState =  &tLevel2; 	
    tLevel2 . alpha = 'l';
	tLevel2 . ret =false;

	struct tokenTree tLevel3 ;
	sLevel3 .childState = &tLevel3;		
    tLevel3 . alpha = 'U';
	tLevel3 . ret =false;
    
	struct tokenTree tLevel4 ;
	sLevel4 .childState = &tLevel4;		
    tLevel4 . alpha = 'L';
	tLevel4 . ret =false;

	/* For level 4 */
	struct tokenTree frLevel1 ;
	tLevel1 .childState = &frLevel1;		
    frLevel1 . alpha = 'e';
	frLevel1 . ret= true;
	frLevel1.childState= NULL;

	struct tokenTree frLevel2;
	tLevel2 .childState =  &frLevel2; 		
    frLevel2 . alpha = 's';
	frLevel2 . ret= false;

	struct tokenTree frLevel3;
	tLevel3 .childState =  &frLevel3;		
    frLevel3 . alpha = 'E';
	frLevel3 . ret =true;
	frLevel3.childState= NULL;
	
	struct tokenTree frLevel4;
	tLevel4 .childState =  &frLevel4; 		
    frLevel4 . alpha = 'S';
	frLevel4 . ret =false;


	/* For level 5*/
	struct tokenTree fiLevel2 ;
	frLevel2 .childState = &fiLevel2;		
    fiLevel2 . alpha = 'e';
	fiLevel2 . ret =true;
	fiLevel2.childState= NULL;

	struct tokenTree fiLevel4;
	frLevel4 .childState =  &fiLevel4; 		
    fiLevel4 . alpha = 'E';
	fiLevel4 . ret =true;
	fiLevel4.childState= NULL;

}


void initString(){

	/* Start state for varable tree */
	//strHead ->ret = false;
	
	/* For level 1 */
	struct tokenTree fLevel1;		
	//strHead ->childState = &fLevel1;		
	strHead  = &fLevel1;		
    fLevel1 . alpha = '"';
	fLevel1 . ret =false;

	/* For level 2 */
	struct tokenTree sLevel1;
	fLevel1 .childState = &sLevel1;		
    sLevel1 . alpha = 'd';
	sLevel1 . ret =false;

	struct tokenTree sLevel2;
	sLevel1 .sibState = &sLevel2 ;		
    sLevel2 . alpha = 'l';
	sLevel2 . ret =false;

	struct tokenTree sLevel3;
	sLevel2  .sibState=&sLevel3 ;		
    sLevel3  .alpha = 'b';
	sLevel3 . ret =false;
	
	/* For level 3 */
	struct tokenTree tLevel1;
	sLevel1 .childState = &tLevel1;		
	sLevel2 .childState = &tLevel1;
	sLevel3 .childState = &tLevel1;
    tLevel1 . alpha = 'd';
	tLevel1 . ret =false;

	struct tokenTree tLevel2;
	tLevel1 .sibState = &tLevel2 ;		
    tLevel2 . alpha = 'l';
	tLevel2 . ret =false;

	struct tokenTree tLevel3;
	tLevel2 . sibState =&tLevel3 ;		
    tLevel3 . alpha = 'b';
	tLevel3 . ret =false;
	
	struct tokenTree tLevel4;
	tLevel3 . sibState = &tLevel4;		
    tLevel4 . alpha = '"';
	tLevel4 . ret = true;
	
	tLevel1 .childState = fLevel1 .childState;		
	tLevel2 .childState = fLevel1 .childState;
	tLevel3 .childState = fLevel1 .childState;
	

	return ;
}

void initInteger(){
	//end of sibling

	struct tokenTree* eLevel= (struct tokenTree*)malloc(sizeof(struct tokenTree)) ;		
	eLevel->alpha ='e';
	
	/* Start state for varable tree */
	//intHead ->ret = false;
	

	/* ForLlevel 1 */
	struct tokenTree* fLevel1= (struct tokenTree*)malloc(sizeof(struct tokenTree)) ;		
	//intHead ->childState= fLevel1;		
	intHead = fLevel1;		
    fLevel1 ->alpha = 'z';
	fLevel1 -> ret =true;
	fLevel1->sibState = NULL;
	fLevel1->childState = NULL;


struct tokenTree *fLevel2 = (struct tokenTree*)malloc(sizeof(struct tokenTree)) ;		
	fLevel1 ->sibState = fLevel2;		
    fLevel2 -> alpha = 's';
	fLevel2 -> ret =false;
	fLevel2->sibState = NULL;
	fLevel2->childState = NULL;


	struct tokenTree* fLevel3= (struct tokenTree*)malloc(sizeof(struct tokenTree)) ;		
	fLevel2 ->sibState = fLevel3;		
    fLevel3 -> alpha = 'n';
	fLevel3 -> ret =true;
	fLevel3->sibState = eLevel;
	fLevel3->childState = NULL;

  	/* For level 2 */

	struct tokenTree *sLevel3  = (struct tokenTree*)malloc(sizeof(struct tokenTree)) ;		
	fLevel3 ->childState = sLevel3;		
    sLevel3 -> alpha = 'n';
	sLevel3 -> ret =true;
	sLevel3->sibState = NULL;
	sLevel3->childState = NULL;
 
	struct tokenTree *sLevel4 = (struct tokenTree*)malloc(sizeof(struct tokenTree)) ;		
	sLevel3 ->sibState = sLevel4;		
    sLevel4 -> alpha = 'z';
	sLevel4 -> ret =true;
	sLevel4->sibState = eLevel;
	sLevel4->childState = NULL;

	fLevel2 -> childState = fLevel3->childState;

	/* For level 3 */
	// is there any collision..??
	sLevel3 ->childState = fLevel3->childState;
	sLevel4 ->childState = fLevel3->childState;

	printf("\n111 --- %c\n",intHead->alpha);
	return ;
}



/* initialzation of variable type */
void initVarTree(){
	
	/* Start state for varable tree */
	//varHead ->ret = false;

	/* For level 1 */
	struct tokenTree fLevel1 ;
	varHead  = &fLevel1;		
	//varHead ->childState = &fLevel1;		
    fLevel1 . alpha = 'i';
	fLevel1 . ret =false;
	fLevel1.childState=NULL;
	fLevel1.sibState=NULL;
	struct tokenTree fLevel2; 
	fLevel1 .sibState = &fLevel2;	
    fLevel2 . alpha = 'c';
	fLevel2 . ret =false;
	fLevel2.childState=NULL;
	fLevel2.sibState=NULL;

	struct tokenTree fLevel3 ; 
	fLevel2 .sibState = &fLevel3;		
    fLevel3 . alpha = 'b';
	fLevel3 . ret =false;
    fLevel3.childState=NULL;
	fLevel3.sibState=NULL;

	struct tokenTree fLevel4; 
	fLevel3 .sibState =  &fLevel4;		
    fLevel4 . alpha = 'f';
	fLevel4 . ret =false;
	fLevel4.childState=NULL;
	fLevel4.sibState=NULL;


	/* For level 2 */
	struct tokenTree sLevel1;
	fLevel1 .childState = &sLevel1 ;		
    sLevel1 . alpha = 'n';
	sLevel1 . ret =false;
	sLevel1.childState=NULL;
	sLevel1.sibState=NULL;

	struct tokenTree sLevel2;
	fLevel2 .childState = &sLevel2 ;		
    sLevel2 . alpha = 'h';
	sLevel2 . ret =false;
	sLevel2.childState=NULL;
	sLevel2.sibState=NULL;

	struct tokenTree sLevel3 ;
	fLevel3 .childState =  &sLevel3 ;		
    sLevel3 . alpha = 'o';
	sLevel3 . ret =false;
    sLevel3.childState=NULL;
	sLevel3.sibState=NULL;


	struct tokenTree sLevel4 ;
	fLevel4 .childState = &sLevel4;		
    sLevel4 . alpha = 'l';
	sLevel4 . ret =false;
	sLevel4.childState=NULL;
	sLevel4.sibState=NULL;


	/* For level 3 */
	struct tokenTree tLevel1 ;
	sLevel1 .childState = &tLevel1 ;		
    tLevel1 . alpha = 't';
	tLevel1 . ret= true;
	tLevel1.childState= NULL;
	tLevel1.childState=NULL;
	tLevel1.sibState=NULL;

	
	struct tokenTree tLevel2;
	sLevel2 .childState = &tLevel2; 	
    tLevel2 . alpha = 'a';
	tLevel2 . ret =false;
	tLevel2.childState=NULL;
	tLevel2.sibState=NULL;


	struct tokenTree tLevel3 ;
	sLevel3 .childState = &tLevel3;		
    tLevel3 . alpha = 'o';
	tLevel3 . ret =false;
	tLevel3.childState=NULL;
	tLevel3.sibState=NULL;
 
	struct tokenTree tLevel4 ;
	sLevel4 .childState =&tLevel4;		
    tLevel4 . alpha = 'o';
	tLevel4 . ret =false;
	tLevel4.childState=NULL;
	tLevel4.sibState=NULL;

	/* For level 4 */
	struct tokenTree frLevel2 ;
	tLevel2 .childState = &frLevel2;		
    frLevel2 . alpha = 'r';
	frLevel2 . ret =true;
	frLevel2.childState= NULL;
	frLevel2.childState=NULL;
	frLevel2.sibState=NULL;

	struct tokenTree frLevel3;
	tLevel3 .childState =  &frLevel3; 		
    frLevel3 . alpha = 'l';
	frLevel3 . ret =true;
	frLevel3.childState= NULL;
	frLevel3.childState=NULL;
	frLevel3.sibState=NULL;


	struct tokenTree frLevel4;
	tLevel4 .childState =  &frLevel4;		
    frLevel4 . alpha = 'a';
	frLevel4 . ret =false;
    frLevel4.childState=NULL;
	frLevel4.sibState=NULL;


	/* For level 4*/
	struct tokenTree fiLevel4;		
	frLevel4 .childState = &fiLevel4;		
    fiLevel4 . alpha = 't';
	fiLevel4 . ret =true;
	fiLevel4.childState= NULL;
	fiLevel4.childState=NULL;
	fiLevel4.sibState=NULL;


}

/*Initialize  tree for every Token */
void initTree(){
	initVarTree();
	initInteger();
	initString();
	initBoolean();
//	initFloat();
//	initKeyword();

	return ;
}

void freeTree(){

	free(varHead) ;
	free(intHead) ;
	free(strHead) ;
	free(boHead) ;
	free(fHead) ;
	free(keyHead) ;

	return ;
}

