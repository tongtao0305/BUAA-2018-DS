#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
#defien keytype int

//�ǵݹ���ֲ��ҷ�,��δ�ҵ����������λ�� 
int  binsearch(keytype key[ ], int n, keytype k){
    int low=0, high=n-1, mid;
    while(low<=high){
        mid=(low+high)/2;
        if(k==key[mid])
            return mid;             /*  ���ҳɹ�  */
        if(k>key[mid])
            low=mid+1;            /*  ׼�����Һ�벿�� */
        else
            high=mid�C1;           /* ׼������ǰ�벿�� */
        }
        return low;                             /*   �������λ��  */
}

//�ݹ���ֲ��ҷ� 
int binsearch2(keytype key[ ], int low, int high, keytype k){
    int mid;
    if(low>high)
        return -1;
    else{ 
    	mid=(low+high)/2;
        if(k==key[mid])
            return mid;
        else
            if(k<key[mid])
                return  binsearch2(key,low,mid-1,k);
            else
            	return  binsearch2(key,mid+1,high,k);
    }
 }
 
//쳲���������


//��������� 
BTNodeptr  searchBST(BTNodeptr p, Datatype item)
{
    if(p == NULL){
        p = (BTNodeptr)malloc(sizeof(BTNode));
        p->data = item;
        p->lchild = p->rchild = NULL;
    } 
    else if( item < p->data)
        p->lchild = insertBST(p->lchild, item);
    else if( item > p->data)
       p->rchild = insertBST(p->rchild,item);
    else   
       do-something; //�ҵ���Ԫ��
    return p;
} 

