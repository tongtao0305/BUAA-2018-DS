#include<stdio.h>
#define M 1000

SElemType STACK[M];
int top;

//初始化一个堆栈 
void INITIALS(int &top){
	top=-1;
}

//测试堆栈是否为空
int EMPTYS(int top){
	return top==-1;
} 

//测试堆栈是否已满
int FULLS(int top){
	return top==M-1;
} 

//取出当前栈顶的元素
int GETTOPS(SElemType STACK[],int top,SElemType &item){
	if(EMPTYS(top))
		return 0;	//堆栈为空，操作失败 
	else{
		item=STACK[top];
		return 1;	
	}	
} 

//插入数据（进栈） 
int PUSH(SElemType STACK[],int &top,SElemType item){
	if(FULLS(top))
		return 0;
	else{
		STACK[++top]=item;
		return 1;
	}
} 

//删除数据 （退栈）
int POP(SElemType STACK[],int &top,SElemType &item){
	if(EMPTYS(top))
		return 0;
	else{
		item=STACK[top--];
		return 1;
	}
} 




int main(void){
	
	
	
	return 0;
}


//以下为多个堆栈共享连续空间
//将item插入第1/2个堆栈 
int PUSH2(SElemType STACK[],int pop[],int i,SElemType item){
	if(top[0]==top[1]-1)
		return 0;	//堆栈已满，插入失败 
	else{
		if(i==1)
			top[0]++;
		else
			top[1]--;
		STACK[top[i-1]]=item;
		return 1;
	}
}

//删除第1/2个堆栈中的item
int POP2(SElemType STACK[],int top[],int i,SElemType &item){
	if(i==1){
		if(top[0]==-1)
			return 0;	//第一个堆栈为空，删除失败
		else{
			item=STACK[top[0]--];
			return 1;
		}
	}
	else{
		if(top[1]==M)
			return 0;	//第二个堆栈为空，删除失败 
		else{
			item=STACK[top[1]++];
			return 1;
		}
	}
} 
	
}
