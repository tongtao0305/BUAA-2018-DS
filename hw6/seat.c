#include<stdio.h>

struct person{
	int num,seat;
	char name[20];
}student1[100],student2[100];

int main(void){
	int i,j,k,n,count_seat[100],max_seat=0;
	FILE *fpin,*fpout;
	struct person temp;
	
	if ((fpin=fopen("in.txt","r"))==NULL){
		printf("Cannot open the file!\n");
		return 1;
	}
	if ((fpout=fopen("out.txt","w"))==NULL){
		printf("Cannot open the file!\n");
		return 1;
	}	
		
	//读取并且记录学生原始数据	
	scanf("%d",&n);
	for (i=0;i<100;i++)
		count_seat[i]=0;
	for (i=1;i<=n;i++){
		fscanf(fpin,"%d %s %d",&student1[i].num,student1[i].name,&student1[i].seat);
		count_seat[student1[i].seat]++;
	}
	
	/*
	for (i=1;i<=n;i++){
		printf("%d %s %d\n",student1[i].num,student1[i].name,student1[i].seat);
	}
	printf("\n");
	*/
	
	for (i=1;i<=n;i++){
		for (j=n;j>i;j--){
			if ((student1[j].seat<student1[j-1].seat)||(student1[j].seat==student1[j-1].seat&&student1[j].num<student1[j-1].num)){
				temp=student1[j];
				student1[j]=student1[j-1];
				student1[j-1]=temp;
			}
		}
	}
	
	/*
	for (i=1;i<=n;i++){
		printf("%d %s %d\n",student1[i].num,student1[i].name,student1[i].seat);
	}
	printf("\n");
	*/
	
	for (i=1;i<=n;i++){
		if (i==1){
			//如果第一个人的座位号不是1
			if (student1[1].seat!=1){
				temp=student1[n];
				temp.seat=1;
				for (j=n-1;j>=1;j--)
					student1[j+1]=student1[j];
				student1[1]=temp;
			}
			continue;
		}
		if (student1[i].seat-student1[i-1].seat==2){
			temp=student1[n];
			temp.seat=student1[i-1].seat+1;
			for (j=n-1;j>=i;j--)
					student1[j+1]=student1[j];
			student1[i]=temp;
		}
	}
	
	max_seat=student1[n].seat;
	for (i=2;i<=n;i++){
		if (student1[i].seat==student1[i-1].seat){
			student1[i].seat=(++max_seat);
		}
	}
	
	for (i=1;i<=n;i++){
		for (j=n;j>i;j--){
			if (student1[j].num<student1[j-1].num){
				temp=student1[j];
				student1[j]=student1[j-1];
				student1[j-1]=temp;
			}
		}
	}
	
	for (i=1;i<=n;i++){
		fprintf(fpout,"%d %s %d\n",student1[i].num,student1[i].name,student1[i].seat);
	}
	
	return 0;
}
