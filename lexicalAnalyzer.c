#include<stdio.h>
#include<string.h>

bool isVariable();
bool isInteger();
bool isString();
bool IsBoolean();
bool isFloat();
bool isKeyword(struct lexeme* lex, char* arr, int right, int left);

struct tokenTree* getNewNode (){};


/* Insert sNode sibling of fNode */
void insertToNextNode(struct tokenTree * fNode, struct tokenTree * sNode){

	struct tokenTrewe tmp= fNode->sibState;
	while(tmp){
		tmp = tmp -> sibState
			// if we have sampe vale already assert
			//----- right..???
	}
    tmp = sNode;	
}


/*Initialize  tree for every Token */
void initTree(){
  
	initVarTree();
	initInteger();
	initString();
	initBool();
	initFloat();
	initKeyword();
}

void initKeyword(){



} 


void initBoolean(){

	/* Start state for boolean tree */
	boHead ->ret = false;

	/* For level 1 */
	struct tokenTree fLevel1 ;
	boHead ->childState = fLevel1;		
    fLevel1 -> alpha = 't';
	fLevel1 -> ret false;

	struct tokenTree fLevel2; 
	flevel1 ->sibState = fLevel2;	
    fLevel2 -> alpha = 'f';
	fLevel2 -> ret false;

	struct tokenTree fLevel3 ; 
	flevel2 ->sibState = fLevel3;		
    fLevel3 -> alpha = 'T';
	fLevel3 -> ret false;
    
	struct tokenTree fLevel4; 
	flevel3 ->sibState =  fLevel4;		
    fLevel4 -> alpha = 'F';
	fLevel4 -> ret false;

	/* For level 2 */
	struct tokenTree sLevel1;
	flevel1 ->childState = sLevel1 ;		
    sLevel1 -> alpha = 'r';
	sLevel1 -> ret false;

	struct tokenTree sLeveli2;
	flevel2 ->childState = sLevel2 ;		
    sLevel2 -> alpha = 'a';
	sLevel2 -> ret false;

	struct tokenTree sLevel3 ;
	flevel3 ->childState =  sLevel3 ;		
    sLevel3 -> alpha = 'R';
	sLevel3 -> ret false;
    
	struct tokenTree sLevel4 ;
	flevel4 ->childState =sLevel4;		
    sLevel4 -> alpha = 'A';
	sLevel4 -> ret false;

	/* For level 3 */
	struct tokenTree tLevel1 ;
	slevel1 ->childState = tLevel1 ;		
    tLevel1 -> alpha = 'u';
	tLevel1 -> ret false;
	tLevel1->childState= NULL;

	struct tokenTree tLevel2;
	slevel2 ->childState =  tLevel2; 	
    tLevel2 -> alpha = 'l';
	tLevel2 -> ret false;

	struct tokenTree tLevel3 ;
	slevel3 ->childState = tLevel3;		
    tLevel3 -> alpha = 'U';
	tLevel3 -> ret false;
    
	struct tokenTree tLevel4 ;
	slevel4 ->childState =tLevel4;		
    tLevel4 -> alpha = 'L';
	tLevel4 -> ret false;

	/* For level 4 */
	struct tokenTree frLevel1 ;
	tlevel1 ->childState = frLevel1;		
    frLevel1 -> alpha = 'e';
	frLevel1 -> ret true;
	frLevel1->childState= NULL;

	struct tokenTree frLevel2;
	tlevel2 ->childState =  frLevel2; 		
    frLevel2 -> alpha = 's';
	frLevel2 -> ret false;

	struct tokenTree frLevel3;
	tlevel3 ->childState =  frLevel3;		
    frLevel3 -> alpha = 'E';
	frLevel3 -> ret true;
	frLevel3->childState= NULL;
	
	struct tokenTree frLevel2;
	tlevel2 ->childState =  frLevel2; 		
    frLevel2 -> alpha = 'S';
	frLevel2 -> ret false;


	/* For level 5*/
	struct tokenTree fiLevel2 ;
	frlevel2 ->childState = fiLevel2;		
    fiLevel2 -> alpha = 'e';
	fiLevel2 -> ret true;
	fiLevel2->childState= NULL;

	struct tokenTree fiLevel4;
	frlevel4 ->childState =  fiLevel4; 		
    fiLevel4 -> alpha = 'E';
	fiLevel4 -> ret true;
	fiLevel4->childState= NULL;

}


void initString(){

	/* Start state for varable tree */
	strHead ->ret = false;
	
	/* For level 1 */
	struct tokenTree fLevel1;		
	strHead ->childState = fLevel1;		
    fLevel1 -> alpha = '"';
	fLevel1 -> ret false;

	/* For level 2 */
	struct tokenTree sLevel1;
	fLevel1 ->childState = sLevel1;		
    sLevel1 -> alpha = 'digit';
	sLevel1 -> ret false;

	struct tokenTree sLevel2;
	sLevel1 ->sibState = sLevel2 ;		
    sLevel2 -> alpha = 'letter';
	sLevel2 -> ret false;

	struct tokenTree sLevel3;
	sLevel2 -> sibState ;		
    sLevel3 -> alpha = '"';
	sLevel3 -> ret false;
	
	sLevel1 ->childState = sLevel1;
	sLevel2 ->childState = sLevel2;
	sLevel3 ->childState = sLevel3;


	/* For level 3 */
	struct tokenTree tLevel1;
	fLevel1 -> alpha = '"';
	fLevel1 -> ret true;

	insertToNextNode(sLevel1 ->childState , tLevel1);		
	insertToNextNode(sLevel2 ->childState , tLevel1);		
	insertToNextNodes(Level3 ->childState , tLevel1);		
    

}

void initInteger(){
		
	/* Start state for varable tree */
	intHead ->ret = false;
	

	/* For level 1 */
	struct tokenTree fLevel1 ;		
	intHead ->childState= fLevel1;		
    fLevel1 -> alpha = 'zero';
	fLevel1 -> ret true;

	struct tokenTree fLevel2 ;		
	flevel1 ->sibState = fLevel2;		
    fLevel2 -> alpha = 'sign';
	fLevel2 -> ret false;

	struct tokenTree fLevel3 ;		
	flevel2 ->sibState = fLevel3;		
    fLevel3 -> alpha = 'natural_num';
	fLevel3 -> ret true;

  	/* For level 2 */
	flevel2 -> childState = fLevel3;

	struct tokenTree sLevel3 ;		
	flevel3 ->childState sLevel3;		
    sLevel3 -> alpha = 'natural_num';
	sLevel3 -> ret true;
    
	struct tokenTree sLevel4;		
	slevel3 ->sibState = sLevel4;		
    sLevel4 -> alpha = 'zero';
	sLevel4 -> ret true;

	/* For level 3 */
	// is there any collision..??
	sLevel3 ->childState = sLevel3;
	sLevel3 ->childState -> sibState  = sLevel4;
	sLevel4 ->childState = sLevel3;
	sLevel4 ->childState -> sibState  = sLevel4;

}

/* initialzation of variable type */
void initVarTree(){
	
	/* Start state for varable tree */
	varHead ->ret = false;

	/* For level 1 */
	struct tokenTree fLevel1 ;
	varHead ->childState = fLevel1;		
    fLevel1 -> alpha = 'i';
	fLevel1 -> ret false;

	struct tokenTree fLevel2; 
	flevel1 ->sibState = fLevel2;	
    fLevel2 -> alpha = 'c';
	fLevel2 -> ret false;

	struct tokenTree fLevel3 ; 
	flevel2 ->sibState = fLevel3;		
    fLevel3 -> alpha = 'b';
	fLevel3 -> ret false;
    
	struct tokenTree fLevel4; 
	flevel3 ->sibState =  fLevel4;		
    fLevel4 -> alpha = 'f';
	fLevel4 -> ret false;

	/* For level 2 */
	struct tokenTree sLevel1;
	flevel1 ->childState = sLevel1 ;		
    sLevel1 -> alpha = 'n';
	sLevel1 -> ret false;

	struct tokenTree sLeveli2;
	flevel2 ->childState = sLevel2 ;		
    sLevel2 -> alpha = 'h';
	sLevel2 -> ret false;

	struct tokenTree sLevel3 ;
	flevel3 ->childState =  sLevel3 ;		
    sLevel3 -> alpha = 'o';
	sLevel3 -> ret false;
    
	struct tokenTree sLevel4 ;
	flevel4 ->childState =sLevel4;		
    sLevel4 -> alpha = 'l';
	sLevel4 -> ret false;

	/* For level 3 */
	struct tokenTree tLevel1 ;
	slevel1 ->childState = tLevel1 ;		
    tLevel1 -> alpha = 't';
	tLevel1 -> ret true;
	tLevel1->childState= NULL;

	struct tokenTree tLevel2;
	slevel2 ->childState =  tLevel2; 	
    tLevel2 -> alpha = 'a';
	tLevel2 -> ret false;

	struct tokenTree tLevel3 ;
	slevel3 ->childState = tLevel3;		
    tLevel3 -> alpha = 'o';
	tLevel3 -> ret false;
    
	struct tokenTree tLevel4 ;
	slevel4 ->childState =tLevel4;		
    tLevel4 -> alpha = 'o';
	tLevel4 -> ret false;

	/* For level 4 */
	struct tokenTree frLevel2 ;
	tlevel2 ->childState = frLevel2;		
    frLevel2 -> alpha = 'r';
	frLevel2 -> ret true;
	frLevel2->childState= NULL;

	struct tokenTree frLevel3;
	tlevel3 ->childState =  frLevel3; 		
    frLevel3 -> alpha = 'l';
	frLevel3 -> ret true;
	frLevel3->childState= NULL;

	struct tokenTree frLevel4;
	tlevel4 ->childState =  frLevel4;		
    frLevel4 -> alpha = 'a';
	frLevel4 -> ret false;
    
	/* For level 4*/
	struct tokenTree fiLevel4;		
	frlevel4 ->childState = fiLevel4;		
    fiLevel4 -> alpha = 't';
	fiLevel4 -> ret true;
	fiLevel4->childState= NULL;

}


