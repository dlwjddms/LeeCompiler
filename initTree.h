#include<stdio.h>
#include<string.h>


struct tokenTree{
		char alpha ;
		bool ret ;
		struct tokenTree *childState;
		struct tokenTree *sibState;
};

struct tokenTree* varHead ;
struct tokenTree* intHead ;
struct tokenTree* strHead ;
struct tokenTree* boHead ;
struct tokenTree* fHead ;
struct tokenTree* keyHead ;

void initTree();
void freeTree();
//void initKeyword(); 
void initBoolean();
void initString();
void initInteger();
void initVarTree();
	
