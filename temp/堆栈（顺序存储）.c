#include<stdio.h>
#define M 1000

SElemType STACK[M];
int top;

//��ʼ��һ����ջ 
void INITIALS(int &top){
	top=-1;
}

//���Զ�ջ�Ƿ�Ϊ��
int EMPTYS(int top){
	return top==-1;
} 

//���Զ�ջ�Ƿ�����
int FULLS(int top){
	return top==M-1;
} 

//ȡ����ǰջ����Ԫ��
int GETTOPS(SElemType STACK[],int top,SElemType &item){
	if(EMPTYS(top))
		return 0;	//��ջΪ�գ�����ʧ�� 
	else{
		item=STACK[top];
		return 1;	
	}	
} 

//�������ݣ���ջ�� 
int PUSH(SElemType STACK[],int &top,SElemType item){
	if(FULLS(top))
		return 0;
	else{
		STACK[++top]=item;
		return 1;
	}
} 

//ɾ������ ����ջ��
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


//����Ϊ�����ջ���������ռ�
//��item�����1/2����ջ 
int PUSH2(SElemType STACK[],int pop[],int i,SElemType item){
	if(top[0]==top[1]-1)
		return 0;	//��ջ����������ʧ�� 
	else{
		if(i==1)
			top[0]++;
		else
			top[1]--;
		STACK[top[i-1]]=item;
		return 1;
	}
}

//ɾ����1/2����ջ�е�item
int POP2(SElemType STACK[],int top[],int i,SElemType &item){
	if(i==1){
		if(top[0]==-1)
			return 0;	//��һ����ջΪ�գ�ɾ��ʧ��
		else{
			item=STACK[top[0]--];
			return 1;
		}
	}
	else{
		if(top[1]==M)
			return 0;	//�ڶ�����ջΪ�գ�ɾ��ʧ�� 
		else{
			item=STACK[top[1]++];
			return 1;
		}
	}
} 
	
}
