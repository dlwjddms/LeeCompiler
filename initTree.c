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


//Sangjin

void initIdentifier(){
	/* Start state for Identifier tree */

	/* first level */
	struct tokenTree *fLevel1 = (struct tokenTree*)malloc(sizeof(struct tokenTree));
	idHead  = fLevel1;
    	fLevel1 -> alpha = 'l';
	fLevel1 -> ret= true;
	fLevel1 -> childState = NULL;
	fLevel1 -> sibState = NULL;

	struct tokenTree *fLevel2 = (struct tokenTree*)malloc(sizeof(struct tokenTree));
	fLevel2 -> alpha = 'u';
	fLevel2 -> ret = true;
	fLevel2 -> childState = NULL;
	fLevel2 -> sibState = NULL;

	/* second level */
	struct tokenTree *sLevel1 = (struct tokenTree*)malloc(sizeof(struct tokenTree));
	sLevel1 -> alpha = 'l';
	sLevel1 -> ret = true;
	sLevel1 -> childState = NULL;
	sLevel1 -> sibState = NULL;

	struct tokenTree *sLevel2 = (struct tokenTree*)malloc(sizeof(struct tokenTree));
	sLevel2 -> alpha = 'd';
	sLevel2 -> ret = true;
	sLevel2 -> childState = NULL;
	sLevel2 -> sibState = NULL;

	struct tokenTree *sLevel3 = (struct tokenTree*)malloc(sizeof(struct tokenTree));
	sLevel3 -> alpha = 'd';
	sLevel3 -> ret = true;
	sLevel3 -> childState = NULL;
	sLevel3 -> sibState = NULL;

	/* link state transitions */
	fLevel1 -> childState = sLevel1;
	fLevel2 -> childState = sLevel1;
	sLevel1 -> childState = sLevel1;
	sLevel2 -> childState = sLevel1;
	sLevel3 -> childState = sLevel1;

	fLevel1 -> sibState = fLevel2;
	sLevel1 -> sibState = sLevel2;
	sLevel2 -> sibState = sLevel3;

}


void initBitwiseop(){
	/* Start state for Bitwise operator tree */

	/* first level */
	struct tokenTree *fLevel1 = (struct tokenTree*)malloc(sizeof(struct tokenTree));
	btHead  = fLevel1;
    	fLevel1 -> alpha = 'L';
	fLevel1 -> ret= false;
	fLevel1 -> childState = NULL;
	fLevel1 -> sibState = NULL;

	struct tokenTree *fLevel2 = (struct tokenTree*)malloc(sizeof(struct tokenTree));
	fLevel2 -> alpha = 'G';
	fLevel2 -> ret = false;
	fLevel2 -> childState = NULL;
	fLevel2 -> sibState = NULL;

	struct tokenTree *fLevel3 = (struct tokenTree*)malloc(sizeof(struct tokenTree));
	fLevel3 -> alpha = 'a';
	fLevel3 -> ret = true;
	fLevel3 -> childState = NULL;
	fLevel3 -> sibState = NULL;

	struct tokenTree *fLevel4 = (struct tokenTree*)malloc(sizeof(struct tokenTree));
	fLevel4 -> alpha = 'o';
	fLevel4 -> ret = true;
	fLevel4 -> childState = NULL;
	fLevel4 -> sibState = NULL;

	/* second level */
	struct tokenTree *sLevel1 = (struct tokenTree*)malloc(sizeof(struct tokenTree));
	sLevel1 -> alpha = 'L';
	sLevel1 -> ret = true;
	sLevel1 -> childState = NULL;
	sLevel1 -> sibState = NULL;

	struct tokenTree *sLevel2 = (struct tokenTree*)malloc(sizeof(struct tokenTree));
	sLevel2 -> alpha = 'G';
	sLevel2 -> ret = true;
	sLevel2 -> childState = NULL;
	sLevel2 -> sibState = NULL;

	/* link state transitions */
	fLevel1 -> childState = sLevel1;
	fLevel2 -> childState = sLevel2;

	fLevel1 -> sibState = fLevel2;
	fLevel2 -> sibState = fLevel3;
	fLevel3 -> sibState = fLevel4;
}

void initComparisonop(){
	/* Start state for Arithmetic operator tree */

	/* first level */
	struct tokenTree *fLevel1 = (struct tokenTree*)malloc(sizeof(struct tokenTree));
	compHead  = fLevel1;
    	fLevel1 -> alpha = 'L';
	fLevel1 -> ret= true;
	fLevel1 -> childState = NULL;
	fLevel1 -> sibState = NULL;

	struct tokenTree *fLevel2 = (struct tokenTree*)malloc(sizeof(struct tokenTree));
	fLevel2 -> alpha = 'G';
	fLevel2 -> ret = true;
	fLevel2 -> childState = NULL;
	fLevel2 -> sibState = NULL;

	struct tokenTree *fLevel3 = (struct tokenTree*)malloc(sizeof(struct tokenTree));
	fLevel2 -> alpha = 'E';
	fLevel2 -> ret = false;
	fLevel2 -> childState = NULL;
	fLevel2 -> sibState = NULL;

	struct tokenTree *fLevel4 = (struct tokenTree*)malloc(sizeof(struct tokenTree));
	fLevel2 -> alpha = 'N';
	fLevel2 -> ret = false;
	fLevel2 -> childState = NULL;
	fLevel2 -> sibState = NULL;

	/* second level */
	struct tokenTree *sLevel1 = (struct tokenTree*)malloc(sizeof(struct tokenTree));
	sLevel1 -> alpha = 'E';
	sLevel1 -> ret = true;
	sLevel1 -> childState = NULL;
	sLevel1 -> sibState = NULL;

	struct tokenTree *sLevel2 = (struct tokenTree*)malloc(sizeof(struct tokenTree));
	sLevel1 -> alpha = 'E';
	sLevel1 -> ret = true;
	sLevel1 -> childState = NULL;
	sLevel1 -> sibState = NULL;

	struct tokenTree *sLevel3 = (struct tokenTree*)malloc(sizeof(struct tokenTree));
	sLevel1 -> alpha = 'E';
	sLevel1 -> ret = true;
	sLevel1 -> childState = NULL;
	sLevel1 -> sibState = NULL;

	struct tokenTree *sLevel4 = (struct tokenTree*)malloc(sizeof(struct tokenTree));
	sLevel1 -> alpha = 'E';
	sLevel1 -> ret = true;
	sLevel1 -> childState = NULL;
	sLevel1 -> sibState = NULL;

	/* link state transitions */
	fLevel1 -> childState = sLevel1;
	fLevel2 -> childState = sLevel2;
	fLevel3 -> childState = sLevel3;
	fLevel4 -> childState = sLevel4;
}

void initAssignop(){
	/* Start state for Assignment operator tree */

	/* first level */
	struct tokenTree *fLevel1 = (struct tokenTree*)malloc(sizeof(struct tokenTree));
	assiHead  = fLevel1;
    	fLevel1 -> alpha = 'E';
	fLevel1 -> ret= true;
	fLevel1 -> childState = NULL;
	fLevel1 -> sibState = NULL;
}

void initArithop(){
	/* Start state for Arithmetic operator tree */

	/* first level */
	struct tokenTree *fLevel1 = (struct tokenTree*)malloc(sizeof(struct tokenTree));
	aritHead  = fLevel1;
    	fLevel1 -> alpha = 'P';
	fLevel1 -> ret= true;
	fLevel1 -> childState = NULL;
	fLevel1 -> sibState = NULL;

	struct tokenTree *fLevel2 = (struct tokenTree*)malloc(sizeof(struct tokenTree));
	fLevel2 -> alpha = 'S';
	fLevel2 -> ret = true;
	fLevel2 -> childState = NULL;
	fLevel2 -> sibState = NULL;

	struct tokenTree *fLevel3 = (struct tokenTree*)malloc(sizeof(struct tokenTree));
	fLevel3 -> alpha = 'M';
	fLevel3 -> ret = true;
	fLevel3 -> childState = NULL;
	fLevel3 -> sibState = NULL;

	struct tokenTree *fLevel4 = (struct tokenTree*)malloc(sizeof(struct tokenTree));
	fLevel3 -> alpha = 'V';
	fLevel3 -> ret = true;
	fLevel3 -> childState = NULL;
	fLevel3 -> sibState = NULL;

	/* link state transitions */

	fLevel1 -> sibState = fLevel2;
	fLevel2 -> sibState = fLevel3;
	fLevel3 -> sibState = fLevel4;
}


void initTermin(){
	/* Start state for Termination tree */

	/* first level */
	struct tokenTree *fLevel1 = (struct tokenTree*)malloc(sizeof(struct tokenTree));
	terHead  = fLevel1;
    	fLevel1 -> alpha = 'C';
	fLevel1 -> ret= true;
	fLevel1 -> childState = NULL;
	fLevel1 -> sibState = NULL;
}


void initBrace(){
	/* Start state for Brace tree */

	/* first level */
	struct tokenTree *fLevel1 = (struct tokenTree*)malloc(sizeof(struct tokenTree));
	brcHead  = fLevel1;
    	fLevel1 -> alpha = 'F';
	fLevel1 -> ret= true;
	fLevel1 -> childState = NULL;
	fLevel1 -> sibState = NULL;

	struct tokenTree *fLevel2 = (struct tokenTree*)malloc(sizeof(struct tokenTree));
	fLevel2 -> alpha = 'T';
	fLevel2 -> ret = true;
	fLevel2 -> childState = NULL;
	fLevel2 -> sibState = NULL;

	/* link state transitions */
	fLevel1 -> sibState = fLevel2;
}

void initParentheses(){
	/* Start state for Parentheses tree */

	/* first level */
	struct tokenTree *fLevel1 = (struct tokenTree*)malloc(sizeof(struct tokenTree));
	parHead  = fLevel1;
    	fLevel1 -> alpha = 'f';
	fLevel1 -> ret= true;
	fLevel1 -> childState = NULL;
	fLevel1 -> sibState = NULL;

	struct tokenTree *fLevel2 = (struct tokenTree*)malloc(sizeof(struct tokenTree));
	fLevel2 -> alpha = 't';
	fLevel2 -> ret = true;
	fLevel2 -> childState = NULL;
	fLevel2 -> sibState = NULL;

	/* link state transitions */
	fLevel1 -> sibState = fLevel2;
}

void initSeperator(){
	/* Start state for Seperator tree */

	/* first level */
	struct tokenTree *fLevel1 = (struct tokenTree*)malloc(sizeof(struct tokenTree));
	sepHead  = fLevel1;
    	fLevel1 -> alpha = 'p';
	fLevel1 -> ret= true;
	fLevel1 -> childState = NULL;
	fLevel1 -> sibState = NULL;
}

void initFloat(){

	/* For level 1 */
	struct tokenTree *fLevel1 =(struct tokenTree*)malloc(sizeof(struct tokenTree));
	fHead  = fLevel1;		
    fLevel1 -> alpha = 'z';
	fLevel1 -> ret= false;

	struct tokenTree *fLevel2 =(struct tokenTree*)malloc(sizeof(struct tokenTree));
	fLevel1->sibState = fLevel2;		
    fLevel2 -> alpha = 's';
	fLevel2 -> ret= false;
	
	struct tokenTree *fLevel3 =(struct tokenTree*)malloc(sizeof(struct tokenTree));
	fLevel2->sibState = fLevel3;		
	fLevel3->sibState = NULL;		
    fLevel3 -> alpha = 'n';
	fLevel3 -> ret= false;
	
	/* For level 2 */
	struct tokenTree *sLevel2_1 =(struct tokenTree*)malloc(sizeof(struct tokenTree));
	fLevel2->childState = sLevel2_1;		
    sLevel2_1 -> alpha = 'z';
	sLevel2_1 -> ret= false;

	struct tokenTree *sLevel2_2 =(struct tokenTree*)malloc(sizeof(struct tokenTree));
	sLevel2_1->sibState = sLevel2_2;		
	sLevel2_2->sibState = NULL;		
    sLevel2_2 -> alpha = 'n';
	sLevel2_2 -> ret= false;
	
	/* For level 3 */
	struct tokenTree *tLevel3_1 =(struct tokenTree*)malloc(sizeof(struct tokenTree));
	sLevel2_2->childState = tLevel3_1;		
	fLevel3->childState = tLevel3_1;		
    tLevel3_1 -> alpha = 'n';
	tLevel3_1 -> ret= false;

	struct tokenTree *tLevel3_2 =(struct tokenTree*)malloc(sizeof(struct tokenTree));
	tLevel3_1->sibState = tLevel3_2;		
	tLevel3_2->sibState = NULL;		
    tLevel3_2 -> alpha = 'z';
	tLevel3_2 -> ret= false;
	
	/* For level 4 */
	struct tokenTree *frLevel4_1 =(struct tokenTree*)malloc(sizeof(struct tokenTree));
	tLevel3_1->childState = frLevel4_1;		
	tLevel3_2->childState = frLevel4_1;		
    frLevel4_1 -> alpha = 'n';
	frLevel4_1 -> ret= false;

	struct tokenTree *frLevel4_2 =(struct tokenTree*)malloc(sizeof(struct tokenTree));
	frLevel4_1->sibState = frLevel4_2;		
    frLevel4_2 -> alpha = 'z';
	frLevel4_2 -> ret= false;

	frLevel4_1->childState = frLevel4_1;		
	frLevel4_2->childState = frLevel4_1;		

	struct tokenTree *frLevel4_3 =(struct tokenTree*)malloc(sizeof(struct tokenTree));
	frLevel4_2->sibState = frLevel4_3;		
	frLevel4_3->sibState = NULL;		
    frLevel4_3 -> alpha = 'D';
	frLevel4_3 -> ret= false;
}

void initKeyword(){

	/* For level 1 */
	struct tokenTree *fLevel1 =(struct tokenTree*)malloc(sizeof(struct tokenTree));
	keyHead  = fLevel1;		
    fLevel1 -> alpha = 'i';
	fLevel1 -> ret= false;

	struct tokenTree *fLevel2 =(struct tokenTree*)malloc(sizeof(struct tokenTree));
	fLevel1->sibState = fLevel2;		
    fLevel2 -> alpha = 'e';
	fLevel2 -> ret= false;
	
	struct tokenTree *fLevel3 =(struct tokenTree*)malloc(sizeof(struct tokenTree));
	fLevel2->sibState = fLevel3;		
    fLevel3 -> alpha = 'w';
	fLevel3 -> ret= false;
	
	struct tokenTree *fLevel4 =(struct tokenTree*)malloc(sizeof(struct tokenTree));
	fLevel3->sibState = fLevel4;		
    fLevel4 -> alpha = 'f';
	fLevel4 -> ret= false;
	
	struct tokenTree *fLevel5 =(struct tokenTree*)malloc(sizeof(struct tokenTree));
	fLevel4->sibState = fLevel5;		
	fLevel5->sibState = NULL;		
    fLevel5 -> alpha = 'r';
	fLevel5 -> ret= false;

	/* For level2 */

	struct tokenTree *sLevel1 =(struct tokenTree*)malloc(sizeof(struct tokenTree));
	fLevel1->childState = sLevel1;		
	sLevel1->childState = NULL;		
    sLevel1 -> alpha = 'f';
	sLevel1 -> ret= true;

	struct tokenTree *sLevel2 =(struct tokenTree*)malloc(sizeof(struct tokenTree));
	fLevel2->childState = sLevel2;		
    sLevel2 -> alpha = 'l';
	sLevel2 -> ret= false;
	
	struct tokenTree *sLevel3 =(struct tokenTree*)malloc(sizeof(struct tokenTree));
	fLevel3->childState = sLevel3;		
    sLevel3 -> alpha = 'h';
	sLevel3 -> ret= false;
	
	struct tokenTree *sLevel4 =(struct tokenTree*)malloc(sizeof(struct tokenTree));
	fLevel4->childState = sLevel4;		
    sLevel4 -> alpha = 'o';
	sLevel4 -> ret= false;
	
	struct tokenTree *sLevel5 =(struct tokenTree*)malloc(sizeof(struct tokenTree));
	fLevel5->childState = sLevel5;		
    sLevel5 -> alpha = 'e';
	sLevel5 -> ret= false;

	/* For level3 */

	struct tokenTree *tLevel2 =(struct tokenTree*)malloc(sizeof(struct tokenTree));
	sLevel2->childState = tLevel2;		
    tLevel2 -> alpha = 's';
	tLevel2 -> ret= false;
	
	struct tokenTree *tLevel3 =(struct tokenTree*)malloc(sizeof(struct tokenTree));
	sLevel3->childState = tLevel3;		
    tLevel3 -> alpha = 'i';
	tLevel3 -> ret= false;
	
	struct tokenTree *tLevel4 =(struct tokenTree*)malloc(sizeof(struct tokenTree));
	sLevel4->childState = tLevel4;		
	tLevel4->childState = NULL;		
    tLevel4 -> alpha = 'r';
	tLevel4 -> ret= true;
	
	struct tokenTree *tLevel5 =(struct tokenTree*)malloc(sizeof(struct tokenTree));
	sLevel5->childState = tLevel5;		
    tLevel5 -> alpha = 't';
	tLevel5 -> ret= false;


	/* For level4 */

	struct tokenTree *frLevel2 =(struct tokenTree*)malloc(sizeof(struct tokenTree));
	tLevel2->childState = frLevel2;		
	frLevel2->childState = NULL;		
    frLevel2 -> alpha = 'e';
	frLevel2 -> ret= true;
	
	struct tokenTree *frLevel3 =(struct tokenTree*)malloc(sizeof(struct tokenTree));
	tLevel3->childState = frLevel3;		
    frLevel3 -> alpha = 'l';
	frLevel3 -> ret= false;
	
	struct tokenTree *frLevel5 =(struct tokenTree*)malloc(sizeof(struct tokenTree));
	tLevel5->childState = frLevel5;		
    frLevel5 -> alpha = 'u';
	frLevel5 -> ret= false;


	/* For level5 */

	struct tokenTree *fiLevel3 =(struct tokenTree*)malloc(sizeof(struct tokenTree));
	frLevel3->childState = fiLevel3;		
	fiLevel3->childState = NULL;		
    fiLevel3 -> alpha = 'e';
	fiLevel3 -> ret= true;
	
	struct tokenTree *fiLevel5 =(struct tokenTree*)malloc(sizeof(struct tokenTree));
	frLevel5->childState = fiLevel5;		
    fiLevel5 -> alpha = 'r';
	fiLevel5 -> ret= false;


	/* For level6 */

	struct tokenTree *siLevel5 =(struct tokenTree*)malloc(sizeof(struct tokenTree));
	fiLevel5->childState = siLevel5;		
	siLevel5->childState = NULL;		
    siLevel5 -> alpha = 'n';
	siLevel5 -> ret= true;
	
	return;




} 

void initBoolean(){

	/* Start state for boolean tree */
	//oboHead ->ret = false;

	/* For level 1 */
	struct tokenTree *fLevel1 =(struct tokenTree*)malloc(sizeof(struct tokenTree));
	//boHead ->childState = fLevel1;		
	boHead  = fLevel1;		
    fLevel1 -> alpha = 't';
	fLevel1 -> ret= false;

	struct tokenTree *fLevel2=(struct tokenTree*)malloc(sizeof(struct tokenTree)); 
	fLevel1 ->sibState = fLevel2;	
    fLevel2 -> alpha = 'f';
	fLevel2 -> ret =false;

	struct tokenTree *fLevel3 =(struct tokenTree*)malloc(sizeof(struct tokenTree)); 
	fLevel2 ->sibState = fLevel3;		
    fLevel3 -> alpha = 'T';
	fLevel3 -> ret =false;
    
	struct tokenTree *fLevel4=(struct tokenTree*)malloc(sizeof(struct tokenTree)); 
	fLevel3 ->sibState =  fLevel4;		
	fLevel4 ->sibState =  NULL;		
    fLevel4 -> alpha = 'F';
	fLevel4 -> ret =false;

	/* For level 2 */
	struct tokenTree *sLevel1=(struct tokenTree*)malloc(sizeof(struct tokenTree));
	fLevel1 ->childState = sLevel1 ;		
    sLevel1 ->alpha = 'r';
	sLevel1 -> ret =false;

	struct tokenTree *sLevel2=(struct tokenTree*)malloc(sizeof(struct tokenTree));
	fLevel2 ->childState = sLevel2 ;		
    sLevel2 -> alpha = 'a';
	sLevel2 -> ret =false;

	struct tokenTree *sLevel3 =(struct tokenTree*)malloc(sizeof(struct tokenTree));
	fLevel3 ->childState =  sLevel3 ;		
    sLevel3 -> alpha = 'R';
	sLevel3 -> ret =false;
    
	struct tokenTree *sLevel4 =(struct tokenTree*)malloc(sizeof(struct tokenTree));
	fLevel4 ->childState =sLevel4;		
    sLevel4 -> alpha = 'A';
	sLevel4 -> ret =false;

	/* For level 3 */
	struct tokenTree *tLevel1 =(struct tokenTree*)malloc(sizeof(struct tokenTree));
	sLevel1 ->childState = tLevel1 ;		
    tLevel1 -> alpha = 'u';
	tLevel1 -> ret =false;
	tLevel1->childState= NULL;

	struct tokenTree *tLevel2=(struct tokenTree*)malloc(sizeof(struct tokenTree));
	sLevel2 ->childState =  tLevel2; 	
    tLevel2 -> alpha = 'l';
	tLevel2 -> ret =false;

	struct tokenTree *tLevel3 =(struct tokenTree*)malloc(sizeof(struct tokenTree));
	sLevel3 ->childState = tLevel3;		
    tLevel3 -> alpha = 'U';
	tLevel3 -> ret =false;
    
	struct tokenTree *tLevel4=(struct tokenTree*)malloc(sizeof(struct tokenTree)) ;
	sLevel4 ->childState = tLevel4;		
    tLevel4 -> alpha = 'L';
	tLevel4 -> ret =false;

	/* For level 4 */
	struct tokenTree *frLevel1 =(struct tokenTree*)malloc(sizeof(struct tokenTree));
	tLevel1 ->childState = frLevel1;		
    frLevel1 -> alpha = 'e';
	frLevel1 -> ret= true;
	frLevel1->childState= NULL;

	struct tokenTree *frLevel2=(struct tokenTree*)malloc(sizeof(struct tokenTree));
	tLevel2 ->childState = frLevel2; 		
    frLevel2 -> alpha = 's';
	frLevel2 -> ret= false;

	struct tokenTree *frLevel3=(struct tokenTree*)malloc(sizeof(struct tokenTree));
	tLevel3 ->childState = frLevel3;		
    frLevel3 -> alpha = 'E';
	frLevel3 -> ret =true;
	frLevel3->childState= NULL;
	
	struct tokenTree *frLevel4=(struct tokenTree*)malloc(sizeof(struct tokenTree));
	tLevel4 ->childState =  frLevel4; 		
    frLevel4 -> alpha = 'S';
	frLevel4 -> ret =false;


	/* For level 5*/
	struct tokenTree *fiLevel2 =(struct tokenTree*)malloc(sizeof(struct tokenTree));
	frLevel2 ->childState = fiLevel2;		
    fiLevel2 -> alpha = 'e';
	fiLevel2 -> ret =true;
	fiLevel2->childState= NULL;

	struct tokenTree *fiLevel4=(struct tokenTree*)malloc(sizeof(struct tokenTree));
	frLevel4 ->childState =  fiLevel4; 		
    fiLevel4 -> alpha = 'E';
	fiLevel4 -> ret =true;
	fiLevel4->childState= NULL;

}


void initString(){

	/* Start state for varable tree */
	//strHead ->ret = false;
	
	/* For level 1 */
	struct tokenTree *fLevel1 =(struct tokenTree*)malloc(sizeof(struct tokenTree)) ;		
	//strHead ->childState = fLevel1;		
	strHead  = fLevel1;		
	fLevel1 ->sibState = NULL;		
    fLevel1 -> alpha = '"';
	fLevel1 -> ret =false;

	/* For level 2 */
	struct tokenTree *sLevel1 =(struct tokenTree*)malloc(sizeof(struct tokenTree)) ;
	fLevel1 ->childState =sLevel1;		
    sLevel1 -> alpha = 'd';
	sLevel1 -> ret =false;

	struct tokenTree *sLevel2 =(struct tokenTree*)malloc(sizeof(struct tokenTree)) ;
	sLevel1 ->sibState = sLevel2 ;		
    sLevel2 -> alpha = 'l';
	sLevel2 -> ret =false;

	struct tokenTree *sLevel3 =(struct tokenTree*)malloc(sizeof(struct tokenTree)) ;
	sLevel2  ->sibState=sLevel3 ;		
	sLevel3  ->sibState=NULL ;		
    sLevel3  ->alpha = 'b';
	sLevel3 ->ret =false;
	
	/* For level 3 */
	struct tokenTree *tLevel1 =(struct tokenTree*)malloc(sizeof(struct tokenTree)) ;
	sLevel1 ->childState = tLevel1;		
	sLevel2 ->childState = tLevel1;
	sLevel3 ->childState = tLevel1;
    tLevel1 -> alpha = 'd';
	tLevel1 -> ret =false;

	struct tokenTree *tLevel2 =(struct tokenTree*)malloc(sizeof(struct tokenTree)) ;
	tLevel1 ->sibState =tLevel2 ;		
    tLevel2 -> alpha = 'l';
	tLevel2 -> ret =false;

	struct tokenTree *tLevel3 =(struct tokenTree*)malloc(sizeof(struct tokenTree)) ;
	tLevel2 -> sibState =tLevel3 ;		
    tLevel3 ->alpha = 'b';
	tLevel3 -> ret =false;
	
	struct tokenTree *tLevel4 =(struct tokenTree*)malloc(sizeof(struct tokenTree)) ;
	tLevel3 -> sibState = tLevel4;		
	tLevel4 -> sibState = NULL;		
	tLevel4 ->childState = NULL;
    tLevel4 -> alpha = '"';
	tLevel4 -> ret = true;
	
	tLevel1 ->childState = sLevel1 ->childState;		
	tLevel2 ->childState = sLevel1 ->childState;
	tLevel3 ->childState = sLevel1 ->childState;
	

	return ;
}


//inteder error 011 or -0 or -01212
void initInteger(){

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
	fLevel3->sibState = NULL;
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
	sLevel4->sibState = NULL;
	sLevel4->childState = NULL;

	fLevel2 -> childState = fLevel3->childState;

	/* For level 3 */
	// is there any collision..??
	sLevel3 ->childState = fLevel3->childState;
	sLevel4 ->childState = fLevel3->childState;

	return ;
}



/* initialzation of variable type */
void initVarTree(){
	
	/* Start state for varable tree */
	//varHead ->ret = false;

	/* For level 1 */
	struct tokenTree *fLevel1  = (struct tokenTree*)malloc(sizeof(struct tokenTree)) ;
	varHead  = fLevel1;		
	//varHead ->childState = fLevel1;		
    fLevel1 -> alpha = 'i';
	fLevel1 -> ret =false;
	fLevel1->childState=NULL;
	fLevel1->sibState=NULL;
	struct tokenTree *fLevel2 = (struct tokenTree*)malloc(sizeof(struct tokenTree)) ; 
	fLevel1 ->sibState = fLevel2;	
    fLevel2 -> alpha = 'c';
	fLevel2 -> ret =false;
	fLevel2->childState=NULL;
	fLevel2->sibState=NULL;

	struct tokenTree *fLevel3  = (struct tokenTree*)malloc(sizeof(struct tokenTree)) ; 
	fLevel2 ->sibState = fLevel3;		
    fLevel3 -> alpha = 'b';
	fLevel3 -> ret =false;
    fLevel3->childState=NULL;
	fLevel3->sibState=NULL;

	struct tokenTree *fLevel4 = (struct tokenTree*)malloc(sizeof(struct tokenTree)) ; 
	fLevel3 ->sibState =  fLevel4;		
    fLevel4 ->alpha = 'f';
	fLevel4 ->ret =false;
	fLevel4->childState=NULL;
	fLevel4->sibState=NULL;


	/* For level 2 */
	struct tokenTree *sLevel1 = (struct tokenTree*)malloc(sizeof(struct tokenTree)) ;
	fLevel1 ->childState = sLevel1 ;		
    sLevel1 -> alpha = 'n';
	sLevel1 -> ret =false;
	sLevel1->childState=NULL;
	sLevel1->sibState=NULL;

	struct tokenTree *sLevel2 = (struct tokenTree*)malloc(sizeof(struct tokenTree)) ;
	fLevel2->childState = sLevel2 ;		
    sLevel2 ->alpha = 'h';
	sLevel2 -> ret =false;
	sLevel2->childState=NULL;
	sLevel2->sibState=NULL;

	struct tokenTree *sLevel3 = (struct tokenTree*)malloc(sizeof(struct tokenTree)) ; 
	fLevel3->childState = sLevel3 ;		
    sLevel3 -> alpha = 'o';
	sLevel3 -> ret =false;
    sLevel3->childState=NULL;
	sLevel3->sibState=NULL;


	struct tokenTree *sLevel4 = (struct tokenTree*)malloc(sizeof(struct tokenTree)) ; 
	fLevel4 ->childState = sLevel4;		
    sLevel4 -> alpha = 'l';
	sLevel4 -> ret =false;
	sLevel4->childState=NULL;
	sLevel4->sibState=NULL;


	/* For level 3 */
	struct tokenTree *tLevel1 = (struct tokenTree*)malloc(sizeof(struct tokenTree)) ;
	sLevel1 ->childState = tLevel1 ;		
    tLevel1 -> alpha = 't';
	tLevel1 -> ret= true;
	tLevel1->childState= NULL;
	tLevel1->childState=NULL;
	tLevel1->sibState=NULL;

	
	struct tokenTree *tLevel2 = (struct tokenTree*)malloc(sizeof(struct tokenTree)) ;
	sLevel2 ->childState = tLevel2; 	
    tLevel2 -> alpha = 'a';
	tLevel2 -> ret =false;
	tLevel2->childState=NULL;
	tLevel2->sibState=NULL;


	struct tokenTree *tLevel3 = (struct tokenTree*)malloc(sizeof(struct tokenTree)) ; 
	sLevel3 ->childState = tLevel3;		
    tLevel3 -> alpha = 'o';
	tLevel3 -> ret =false;
	tLevel3->childState=NULL;
	tLevel3->sibState=NULL;
 
	struct tokenTree *tLevel4 = (struct tokenTree*)malloc(sizeof(struct tokenTree)) ;
	sLevel4 ->childState =tLevel4;		
    tLevel4 ->alpha = 'o';
	tLevel4 -> ret =false;
	tLevel4->childState=NULL;
	tLevel4->sibState=NULL;

	/* For level 4 */
	struct tokenTree *frLevel2 = (struct tokenTree*)malloc(sizeof(struct tokenTree)) ; 
	tLevel2 ->childState = frLevel2;		
    frLevel2 -> alpha = 'r';
	frLevel2 -> ret =true;
	frLevel2->childState= NULL;
	frLevel2->childState=NULL;
	frLevel2->sibState=NULL;

	struct tokenTree *frLevel3 = (struct tokenTree*)malloc(sizeof(struct tokenTree)) ;
	tLevel3 ->childState =  frLevel3; 		
    frLevel3 -> alpha = 'l';
	frLevel3 -> ret =true;
	frLevel3->childState= NULL;
	frLevel3->childState=NULL;
	frLevel3->sibState=NULL;


	struct tokenTree *frLevel4 = (struct tokenTree*)malloc(sizeof(struct tokenTree)) ;
	tLevel4 ->childState =  frLevel4;		
    frLevel4 -> alpha = 'a';
	frLevel4 -> ret =false;
    frLevel4->childState=NULL;
	frLevel4->sibState=NULL;


	/* For level 4*/
	struct tokenTree* fiLevel4 = (struct tokenTree*)malloc(sizeof(struct tokenTree)) ;		
	frLevel4 ->childState = fiLevel4;		
    fiLevel4 ->alpha = 't';
	fiLevel4 -> ret =true;
	fiLevel4->childState= NULL;
	fiLevel4->childState=NULL;
	fiLevel4->sibState=NULL;


}

/*Initialize  tree for every Token */
void initTree(){
	initVarTree();
	initInteger();
	initString();
	initBoolean();
	initFloat();
	initKeyword();
	initIdentifier();
	initBitwiseop();
	initComparisonop();
	initAssignop();
	initArithop();
	initTermin();
	initBrace();
	initParentheses();
	initSeperator();
	return ;
}

void freeTree(){

	//free(varHead) ;
		struct tokenTree * ctmp ;//=varHead;
		struct tokenTree * stmp;// =ctmp;
		while (varHead != NULL) {
			ctmp = varHead;
			varHead = varHead->childState;
			while(ctmp !=NULL){
				stmp =ctmp;
				ctmp = ctmp->sibState;
				free(stmp);
				stmp = NULL;
			}
			ctmp=NULL;
		}
	//free(intHead) ;
		while (intHead != NULL) {
			ctmp = intHead;
			intHead = intHead->childState;
			while(ctmp !=NULL){
				stmp =ctmp;
				ctmp = ctmp->sibState;
				free(stmp);
				stmp = NULL;
			}
			ctmp=NULL;
		}
	//	free(strHead) ;
		while (strHead != NULL) {
			ctmp = strHead;
			strHead = strHead->childState;
			while(ctmp !=NULL){
				stmp =ctmp;
				ctmp = ctmp->sibState;
				free(stmp);
				stmp = NULL;
			}
			ctmp=NULL;
		}

	//	free(boHead) ;
		while (boHead != NULL) {
			ctmp = boHead;
			boHead = boHead->childState;
			while(ctmp !=NULL){
				stmp =ctmp;
				ctmp = ctmp->sibState;
				free(stmp);
				stmp = NULL;
			}
			ctmp=NULL;
		}

	//	free(fHead) ;
	//	free(keyHead) ;
//free(idHead) ;
//free(btHead) ;
//free(compHead) ;
//free(assiHead) ;
//free(aritHead) ;
//free(terHead) ;
//free(brcHead) ;
//free(parHead) ;
//free(sepHead) ;
	return ;
}

