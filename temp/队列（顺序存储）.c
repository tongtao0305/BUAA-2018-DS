#include<stdio.h>

#define M 1000
QElemType QUEUE[M];
int front,rear;


//初始化队列
void INITIALQ(int &front,int &rear){
	front=-1;
	rear=-1;
} 

//测试队列是否为空
int EMPTYQ(int front,int rear){
	return front==rear;
} 

//取出当前队头的元素 
int GETQ(QElemType QUEUE[],int front,int rear,QElemType &item){
	if(EMPTYQ(front,rear))
		return 0;	//队列为空，操作失败
	else{
		item=QUEUE[front+1];
		return 1;
	} 
}

//队列的插入（进队）
int ADDQ(QElemType QUEUE[],int &rear,QElemType item){
	if(rear==M-1)
		return 0;	//队列已满，操作失败
	else{
		QUEUE[++rear]=item;
		return 1;
	} 
} 

//队列的删除（出队）
int DELQ(QElemType QUEUE[],int &front,inr rear,QElemType &item){
	if(EMPTYQ(front,rear))
		return 0;	//队列为空，操作失败 
	else{
		item=QUEUE[++front];
		return 1;	
	}
} 


int main(void){
	
	
	
	return 0;
}

//以下为循环列表的代码
//循环队列的插入 
int ADDCQ(QElemType QUEUE[],int front,int &rear,QElemType item){
	if((rear+1)%M==front)
		return 0;
	else{
		QUEUE[++rear%M]=item;
		return 1;
	}
} 

//循环队列的删除
int DELCQ(QElenType QUEUE[],int &front,int rear,QElemType &item){
	if(front==rear)
		return 0;
	else{
		front=(front+1)%M;
		item=QUEUE[front];
		return 1;
	}
} 
