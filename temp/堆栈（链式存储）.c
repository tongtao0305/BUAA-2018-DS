#include<stdio.h>

typedef struct node{
	SElemType data;
	struct node *link;
}STNode,*STLink;

//Á´½Ó¶ÑÕ»³õÊ¼»¯
void INITIALSLINK(STLink &top){
	top=NULL;
} 

//²âÊÔÁ´½Ó¶ÑÕ»ÊÇ·ñÎª¿Õ
int EMPTYSLINK(STLink top){
	return (top==NULL);
} 

//È¡³öµ±Ç°Õ»¶¥µÄÔªËØ
int GETTOPSLINK(STLink top,SElemType &item){
	if(EMPTYSLINK(top))
		return 0;	//¶ÑÕ»Îª¿Õ£¬²Ù×÷Ê§°Ü
	else{
		item=top->data;
		return 1;
	} 
} 

//Á´½Ó¶ÑÕ»µÄ²åÈë
#define LEN sizeof(STNode)
int PUSHLINK(STLink &top,SElemType item){
	STLink p;
	if(!(p=(STLINK)malloc(LEN)))
		return 0;	//²åÈëÊ§°Ü
	else{
		p->data=item;
		p->link=top;
		top=p;
		return 1;
	} 
} 

//É¾³ıÁ´½Ó¶ÑÕ»ÖĞµÄÒ»¸öÔªËØ 
int POPLINK(STLink &top,SElemType &item){
	STLink p;
	if(EMPTYSLINK(top))
		return 0;	//¶ÑÕ»Îª¿Õ£¬²Ù×÷Ê§°Ü
	else{
		p=top;
		item=p->data;
		top=top->link;
		free(p);
		return 1;
	} 
} 
