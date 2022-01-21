#include<stdio.h>

#define M 1000
QElemType QUEUE[M];
int front,rear;


//��ʼ������
void INITIALQ(int &front,int &rear){
	front=-1;
	rear=-1;
} 

//���Զ����Ƿ�Ϊ��
int EMPTYQ(int front,int rear){
	return front==rear;
} 

//ȡ����ǰ��ͷ��Ԫ�� 
int GETQ(QElemType QUEUE[],int front,int rear,QElemType &item){
	if(EMPTYQ(front,rear))
		return 0;	//����Ϊ�գ�����ʧ��
	else{
		item=QUEUE[front+1];
		return 1;
	} 
}

//���еĲ��루���ӣ�
int ADDQ(QElemType QUEUE[],int &rear,QElemType item){
	if(rear==M-1)
		return 0;	//��������������ʧ��
	else{
		QUEUE[++rear]=item;
		return 1;
	} 
} 

//���е�ɾ�������ӣ�
int DELQ(QElemType QUEUE[],int &front,inr rear,QElemType &item){
	if(EMPTYQ(front,rear))
		return 0;	//����Ϊ�գ�����ʧ�� 
	else{
		item=QUEUE[++front];
		return 1;	
	}
} 


int main(void){
	
	
	
	return 0;
}

//����Ϊѭ���б�Ĵ���
//ѭ�����еĲ��� 
int ADDCQ(QElemType QUEUE[],int front,int &rear,QElemType item){
	if((rear+1)%M==front)
		return 0;
	else{
		QUEUE[++rear%M]=item;
		return 1;
	}
} 

//ѭ�����е�ɾ��
int DELCQ(QElenType QUEUE[],int &front,int rear,QElemType &item){
	if(front==rear)
		return 0;
	else{
		front=(front+1)%M;
		item=QUEUE[front];
		return 1;
	}
} 
