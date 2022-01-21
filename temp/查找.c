#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
#defien keytype int

//非递归二分查找法,如未找到则输出插入位置 
int  binsearch(keytype key[ ], int n, keytype k){
    int low=0, high=n-1, mid;
    while(low<=high){
        mid=(low+high)/2;
        if(k==key[mid])
            return mid;             /*  查找成功  */
        if(k>key[mid])
            low=mid+1;            /*  准备查找后半部分 */
        else
            high=mid–1;           /* 准备查找前半部分 */
        }
        return low;                             /*   输出插入位置  */
}

//递归二分查找法 
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
 
//斐波那契查找


//二叉查找树 
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
       do-something; //找到该元素
    return p;
} 

