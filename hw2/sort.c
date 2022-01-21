#include<stdio.h>
#include<string.h>

typedef struct node{
	char name[100];
	char number[20];
}Node; 

Node people[10000];

int main(void){
	int i,j,k,n,count=0,is_double=0;
	char name[100],number[20],temp[100];

	scanf("%d\n",&n);

	for (i=0;i<n;i++)
		scanf("%s %s",people[i].name,people[i].number);
	
	for (i=0;i<n;i++){
		for (j=n;j>i;j--){
			if (strcmp(people[j-1].name,people[j].name)>0){
				strcpy(temp,people[j-1].name);
				strcpy(people[j-1].name,people[j].name);
				strcpy(people[j].name,temp);
				
				strcpy(temp,people[j-1].number);
				strcpy(people[j-1].number,people[j].number);
				strcpy(people[j].number,temp);
			}
		}
	}
	
	for (i=1;i<=n;i++){
		
		if(strcmp(people[i].name,people[i-1].name)!=0)
			count=0;
		
		if(count==0){
			if(strcmp(people[i].name,people[i+1].name)!=0)
				printf("%s %s\n",people[i].name,people[i].number);			
			else{
				count++;
				printf("%s %s\n",people[i].name,people[i].number);	
			}
		}
		else{
			for (j=1;j<=count;j++)
				if (strcmp(people[i].name,people[i-j].name)==0&&strcmp(people[i].number,people[i-j].number)==0){
					is_double=1;
					break;
				}
			
			if(is_double==1){
				is_double=0;
				continue;
			}	
			
			if(strcmp(people[i].name,people[i+1].name)==0){
				printf("%s_%d %s\n",people[i].name,count,people[i].number);		
				count++;				
			}
			else{
				printf("%s_%d %s\n",people[i].name,count,people[i].number);					
				count=0;
			}
		}
	}
	
	return 0;
}
