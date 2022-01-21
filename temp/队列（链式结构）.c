#include<stdio.h>
#include<stdlib.h>
//����һ������������� 
typedef struct node{
	QElemType data;
	struct node *link;
}QNode,*QLink;


//��ʼ�����Ӷ���
void INITIALQLINK(QLink &front,QLink &rear){
	front=rear=NULL;
} 

//�������Ӷ����Ƿ�Ϊ��
int EMPTYQLINK(QLink front){
	return front==NULL;
} 

//ȡ����ǰ��ͷԪ��
int GETLINKQ(QLink front,QElemType &item){
	if(EMPTYQLINK(front))
		return 0;	//����Ϊ�գ�����ʧ��
	item=front->data;
	return 1; 
} 

//���Ӷ��еĲ���
#define LEN sizeof(QNode)
int ADDLINKQ(QLink &front,Qlink &rear,QElenType item){
	Qlink p;
	if(!(p=(Qlink)malloc(LEN)))
		return 0;	//����ʧ��
 	p->data=item;
 	p->link=NULL;
 	if(front==NULL)
 		front=p;
 	else
 		rear->link=p;
 	rear=p;
 	return 1;
} 

//���Ӷ��е�ɾ�� 
init DELLINKQ(QLink &front,QElemType &item){
	QLink p;
	if(EMPTYQLINK(front))
		return 0;	//����Ϊ�գ�����ʧ��
	p=front;
	item=p->data;
	front=p->link;
	free(p);
	return 1; 
}

//���Ӷ��е�����
void DESLINKQ(QLink &front,QLink &rear){
	while(front){
		rear=front->link;
		free(front);
		front=rear;
	}
} 


int main(void){
	return 0;
}
