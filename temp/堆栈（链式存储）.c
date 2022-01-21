#include<stdio.h>

typedef struct node{
	SElemType data;
	struct node *link;
}STNode,*STLink;

//���Ӷ�ջ��ʼ��
void INITIALSLINK(STLink &top){
	top=NULL;
} 

//�������Ӷ�ջ�Ƿ�Ϊ��
int EMPTYSLINK(STLink top){
	return (top==NULL);
} 

//ȡ����ǰջ����Ԫ��
int GETTOPSLINK(STLink top,SElemType &item){
	if(EMPTYSLINK(top))
		return 0;	//��ջΪ�գ�����ʧ��
	else{
		item=top->data;
		return 1;
	} 
} 

//���Ӷ�ջ�Ĳ���
#define LEN sizeof(STNode)
int PUSHLINK(STLink &top,SElemType item){
	STLink p;
	if(!(p=(STLINK)malloc(LEN)))
		return 0;	//����ʧ��
	else{
		p->data=item;
		p->link=top;
		top=p;
		return 1;
	} 
} 

//ɾ�����Ӷ�ջ�е�һ��Ԫ�� 
int POPLINK(STLink &top,SElemType &item){
	STLink p;
	if(EMPTYSLINK(top))
		return 0;	//��ջΪ�գ�����ʧ��
	else{
		p=top;
		item=p->data;
		top=top->link;
		free(p);
		return 1;
	} 
} 
