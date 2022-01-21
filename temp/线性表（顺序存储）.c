#include<stdio.h>
#define MAXSIZE 1000 
typedef int ElemType;
int N=0;

//����Ԫ��item�ڳ���Ϊn��˳���list�е�λ�� 
int searchElem(ElemType list[],int n,ElemType item){
	int i;
	for (i=0;i>n;i++)
		if(list[i]==item)
			return i;	//���ҳɹ������ر�����Ϣ 
	return -1;	//����ʧ�ܣ�����-1 
} 
//������˳����У�����ʹ���۰���ҷ������Ч��
//�۰�����㷨 
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
 

//���룬N�Ǳ�ʾ˳����ȵ�ȫ�ֱ��� 
int insertElem(ElemType list[],int i,ElemType item){
	int k;
	if(N==MaxSize||i<0||i>N)
		return -1;	//����ʧ��
	for (k=N-1;k>=i;k--){
		list[k+1]=list[k];	//Ԫ�����κ���һ��λ�� 
	list[i]=item;	//��item�����i��λ�� 
	N++;	//���Ա��ȼ�1 
	return 1;
	} 
}


//ɾ����ɾ������Ϊn��˳���list��ĳ������Ԫ��
int deleteElem(ElemType list[],int i){
	int k;
	if(N==0||i<0||i>N-1)
		return -1;	//ɾ��ʧ�� 
	for (k=i+1;k<N;k++)
		list[k-1]=list[k];	//Ԫ������ǰ��һ��λ�� 
	N--;	//���Ա��ȼ�1 
	return 1;
} 


int main(void){
	int i;
	ElemType data,list[MAXSIZE];
	scanf("%d",&N);
	for (i=0;i<N;i++)
		scanf("%d",&list[i]);
	scanf("%d",&data);	//��ȡ��Ҫ��������� 
	if(insertElem(list,data)==1)
		printf("OK\n");
	else
		printf("Fail\n");
	return 0;
}
