#include<stdio.h>

int chess[21][21];

int main(void){
	int i,j,k,temp,count=0;
	
	//对棋盘进行初始化，-1表示界外 
	for (i=0;i<=20;i++)
		for (j=0;j<=20;j++)
			chess[i][j]=-1;
	
	for (i=1;i<=19;i++)
		for (j=1;j<=19;j++)
			scanf("%d",&chess[i][j]);
	
	for (i=1;i<=16;i++)
		for (j=1;j<=16;j++){
			if (chess[i][j]==0)
				continue;
			temp=chess[i][j];
			
			//列 
			if(temp==chess[i+1][j]&&temp==chess[i+2][j]&&temp==chess[i+3][j]&&(chess[i+4][j]==0||chess[i-1][j]==0)){
				printf("%d:%d,%d\n",temp,i,j);
				count=1; 
			} 
			//行
			if(temp==chess[i][j+1]&&temp==chess[i][j+2]&&temp==chess[i][j+3]&&(chess[i][j+4]==0||chess[i][j-1]==0)){
				printf("%d:%d,%d\n",temp,i,j);
				count=1;
			}
			//斜 
			if(temp==chess[i+1][j+1]&&temp==chess[i+2][j+2]&&temp==chess[i+3][j+3]&&(chess[i+4][j+4]==0||chess[i-1][j-1]==0)){
				printf("%d:%d,%d\n",temp,i,j);
				count=1;
			}
		}
		
	for (i=1;i<=16;i++)
		for (j=4;j<=19;j++){
			if (chess[i][j]==0)
				continue;
			temp=chess[i][j];
			//斜 
			if(temp==chess[i+1][j-1]&&temp==chess[i+2][j-2]&&temp==chess[i+3][j-3]&&(chess[i+4][j-4]==0||chess[i-1][j+1]==0)){
				printf("%d:%d,%d\n",temp,i,j);
				count=1;
			}
		}	
		
	for (i=17;i<=19;i++)
		for (j=1;j<=16;j++){
			if (chess[i][j]==0)
				continue;
			temp=chess[i][j];
			if(temp==chess[i][j+1]&&temp==chess[i][j+2]&&temp==chess[i][j+3]&&(chess[i][j+4]==0||chess[i][j-1]==0)){
				printf("%d:%d,%d\n",temp,i,j);
				count=1;
			}			
	}

	for (i=1;i<=16;i++)
		for (j=17;j<=19;j++){
			if (chess[i][j]==0)
				continue;
			temp=chess[i][j];
			if(temp==chess[i+1][j]&&temp==chess[i+2][j]&&temp==chess[i+3][j]&&(chess[i+4][j]==0||chess[i-1][j]==0)){
				printf("%d:%d,%d\n",temp,i,j);
				count=1; 
			} 
		}
				
	
	if(count==0)
		printf("No\n");
	
	return 0;
}
