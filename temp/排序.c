#include<stdio.h>

#define keytype 
//ѡ������ 
void insertSort(keytype k[ ],int n)
{
       int i, j;
       keytype  temp;
       for(i=1;i<n;i++){
             temp=k[i];
             for(j=i-1; j>=0 && temp<k[j]; j--) 
                    k[j+1]=k[j];
             k[j+1]=temp;
       }
}

//ϣ������ 
void  shellSort(keytype k[ ],int n){     
	int  i, j, flag, gap=n;
    keytype  temp; 
    while(gap>1){
        gap=gap/2;
        do{
            flag=0;                  /* ÿ������ǰ,��־flag��0 */ 
            for(i=0;i<n�Cgap;i++){
                j=i+gap;
                if(k[i]>k[j]){
                    temp=k[i];
                    k[i]=k[j];
                    k[j]=temp;
                    flag=1;  
                }
            }
        }while(flag!=0);
    }
}

void  shellSort(int v[ ], int n)  //from K & R
{
    int gap, i, j, temp;
    for( gap = n/2; gap >0; gap /= 2)
        for(i=gap; i<n; i++)
            for(j=i-gap; j>=0 && v[j]>v[j+gap]; j -= gap){
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
}

//�������adjust���� 
void adjust(keytype k[ ],int i,int n)
{
    int j;
    keytype temp;
    temp=k[i];
    j=2*i+1;
    while(j<n){
        if(j+1<n && k[j]<k[j+1])
            j++;
        if(temp<k[j]) {
        	//k[i]=k[j];
        	//k[j]=temp;
            k[j/2]=k[j];
            j=2*j+1;
        }
        else break; 
    }
    k[(j-1)/2]=temp;
}
//������ 
void heapSort(keytype k[ ],int n)
{
    int i,
    keytype  temp;
    //������ʼ�� 
    for(i=n/2-1;i>=0;i--)
        adjust(k,i,n);
    
    for(i=n-1;i>=1;i--){
        temp=k[i];
        k[i]=k[0];
        k[0]=temp;
        adjust(k,0,i);
    }
}

//�鲢���� 
void mergeSort(keytype k[ ],int n)
{
    keytype *tmp;
    tmp = (keytype *)malloc(sizeof(keytype) * n);
    if(tmp != NULL) {
        mSort(k, tmp, 0, n-1);
        free(tmp);
    } 
    else
        printf("No space for tmp array!!!\n");
}
void mSort(keytype k[], keytype tmp[], int left, int right)
{
    int center;
    if(left < right){
        center = (left+right)/2;
        mSort(k, tmp, left, center);
        mSort(k, tmp, center+1, right);
        merge(k, tmp, left,center, right);
    }
}
void merge(keytype x[ ],keytype tmp[ ],int left,int leftend,int rightend){     
    int i=left, j=leftend+1, q=left;
    while(i<=leftend && j<=rightend)
        if(x[i]<=x[j]) 
            tmp[q++]=x[i++];
        else
            tmp[q++]=x[j++];
	while(i<=leftend)
	    tmp[q++]=x[i++];
	while(j<=rightend)
	    tmp[q++]=x[j++];
	for(i=left; i<=rightend; i++)
	    x[i]=tmp[i];
}

//�������� 
void quickSort(keytype k[],int n)
{
    quick(K,0,n-1);
}
void swap(keytype v[ ],int i, int j)
{
    keytype tmp;
    tmp = v[i]; v[i] = v[j]; v[j]=tmp;
}
void quick(keytype k[ ],int left,int right){     
	int i, j;
    keytype pivot;
    if(left<right){
        i=left; j=right+1;
        pivot = k[left];
        while(1){ 
            while(k[++i]<pivot && i!=right) { }
            while(k[--j]>pivot && j!=left) { }
            if(i<j)
                swap(&k[i],&k[j]);  /*����K[i]��K[j]��λ��*/
            else
                break;
        }
        swap(&k[left],&k[j]);      /*����K[left]��K[j]��λ��*/
        quick(k,left,j-1);       /* ��ǰһ�������� */
        quick(k,j+1,right);       /* �Ժ�һ�������� */
    }
}

