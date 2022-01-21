#include<stdio.h>

int num[1001]; 
int count[1001];
int sum;

void array(int n){
	int i;
	
	if (n==1){
		for (i=1;i<=sum;i++){
			if (count[i]==1){
				num[sum-n+1]=i;
				break;
			}
		}
		for (i=1;i<=sum;i++)
			printf("%d ",num[i]);
		printf("\n");
	}
	else{
		for (i=1;i<=sum;i++){
			if (count[i]==1){
				num[sum-n+1]=i;
				count[i]=0;
				array(n-1);				
				count[i]=1;		
			}
		}
	}
}

int main(void){
	int n,i;

	scanf("%d",&n);
	sum=n;
	
	for (i=1;i<=n;i++)
		count[i]=1;		
	array(n);
		
	return 0;
}
 
