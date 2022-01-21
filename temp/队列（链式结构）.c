#include<stdio.h>
#include<stdlib.h>
//定义一个链表队列类型 
typedef struct node{
	QElemType data;
	struct node *link;
}QNode,*QLink;


//初始化链接队列
void INITIALQLINK(QLink &front,QLink &rear){
	front=rear=NULL;
} 

//测试链接队列是否为空
int EMPTYQLINK(QLink front){
	return front==NULL;
} 

//取出当前队头元素
int GETLINKQ(QLink front,QElemType &item){
	if(EMPTYQLINK(front))
		return 0;	//队列为空，操作失败
	item=front->data;
	return 1; 
} 

//链接队列的插入
#define LEN sizeof(QNode)
int ADDLINKQ(QLink &front,Qlink &rear,QElenType item){
	Qlink p;
	if(!(p=(Qlink)malloc(LEN)))
		return 0;	//插入失败
 	p->data=item;
 	p->link=NULL;
 	if(front==NULL)
 		front=p;
 	else
 		rear->link=p;
 	rear=p;
 	return 1;
} 

//链接队列的删除 
init DELLINKQ(QLink &front,QElemType &item){
	QLink p;
	if(EMPTYQLINK(front))
		return 0;	//链表为空，操作失败
	p=front;
	item=p->data;
	front=p->link;
	free(p);
	return 1; 
}

//链接队列的销毁
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
