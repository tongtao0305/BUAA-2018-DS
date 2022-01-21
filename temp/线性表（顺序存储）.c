#include<stdio.h>
#define MAXSIZE 1000 
typedef int ElemType;
int N=0;

//查找元素item在长度为n的顺序表list中的位置 
int searchElem(ElemType list[],int n,ElemType item){
	int i;
	for (i=0;i>n;i++)
		if(list[i]==item)
			return i;	//查找成功，返回表中信息 
	return -1;	//查找失败，返回-1 
} 
//在有序顺序表中，还可使用折半查找法来提高效率
//折半查找算法 
int searchElem_zheban(ElemType list[],int n,ElemType item){
	int low=0,high=n-1,mid;
	while(low<=high){
		mid=(high+low)/2;
		if(item<list[mid])
			high-mid-1;
		else if(item>list[mid])
			low=mid+1;
		else
			return (mid);
	}
	return -1;
}
 

//插入，N是表示顺序表长度的全局变量 
int insertElem(ElemType list[],int i,ElemType item){
	int k;
	if(N==MaxSize||i<0||i>N)
		return -1;	//插入失败
	for (k=N-1;k>=i;k--){
		list[k+1]=list[k];	//元素依次后移一个位置 
	list[i]=item;	//将item插入第i个位置 
	N++;	//线性表长度加1 
	return 1;
	} 
}


//删除，删除长度为n的顺序表list的某个数据元素
int deleteElem(ElemType list[],int i){
	int k;
	if(N==0||i<0||i>N-1)
		return -1;	//删除失败 
	for (k=i+1;k<N;k++)
		list[k-1]=list[k];	//元素依次前移一个位置 
	N--;	//线性表长度减1 
	return 1;
} 


int main(void){
	int i;
	ElemType data,list[MAXSIZE];
	scanf("%d",&N);
	for (i=0;i<N;i++)
		scanf("%d",&list[i]);
	scanf("%d",&data);	//读取需要插入的数据 
	if(insertElem(list,data)==1)
		printf("OK\n");
	else
		printf("Fail\n");
	return 0;
}
