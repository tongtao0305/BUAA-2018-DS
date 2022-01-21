#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
struct station{
	char name[50];
	int interchange;
}bjvertex[1000];
struct weight{
	int wei,id;
}bjweights[1000][1000];
int Vnum=0,path[1000];
//新建邻接表 
void creategraph(){
	FILE *fpin;
	int i,j,k,n,v1,v2,sum,id;
	struct station st;
	//对邻接表数组进行初始化 
	for(i=0;i<1000;i++){
		for(j=0;j<1000;j++){
			bjweights[i][j].id=0;
			bjweights[i][j].wei=INT_MAX;
		}
	}
    fpin=fopen("bgstations.txt","r");
    fscanf(fpin,"%d",&sum);
    for(i=0;i<sum;i++){
		fscanf(fpin,"%d %d",&id,&n);
		v1=-1;v2=-1;
		for(j=0;j<n;j++){
			fscanf(fpin,"%s %d",st.name,&st.interchange);
			for (v2=0;v2<Vnum;v2++)
				if (strcmp(bjvertex[v2].name,st.name)==0)
					break;
			if (v2==Vnum)
				bjvertex[Vnum++]=st;
			if(v1!=-1){
				bjweights[v1][v2].wei=bjweights[v2][v1].wei=1;
				bjweights[v1][v2].id=bjweights[v2][v1].id=id;
			}
			v1=v2;
	   }
	}
	fclose(fpin);
	return;
}

int selected[1000],minwei[1000]; 
void dijkstra(int v0,int v1){
	int i,j,v,minweight;
	minwei[v0]=0;
	selected[v0]=1;
	for(i=0;i<Vnum;i++){
		minwei[i]=bjweights[v0][i].wei;
		path[i]=v0;
	}
	for(i=0;i<Vnum-1;i++){
		minweight=INT_MAX;
		for(j=0;j<Vnum;j++){
			if(!selected[j]&&(minwei[j]<minweight)){
				v=j;
				minweight=minwei[v];
			}
		}   
		selected[v]=1;
		if(v==v1) return;
		for(j=0;j<Vnum;j++){
			if(!selected[j]&&(bjweights[v][j].id>0)&&(minweight+bjweights[v][j].wei<minwei[j])){
				minwei[j]=minweight+bjweights[v][j].wei;
		        path[j]=v;
			}	        
		}
	}
}
 
void printpath(int v0,int v1){
	int board[200],bcount=0,line=-1,scount=0,i;//bcount统计全部的站数，scount是统计某线路的站数 
	do{
		board[bcount++]=v1;
	}while((v1=path[v1])!=v0);
	board[bcount++]=v0;
	line=bjweights[board[bcount-1]][board[bcount-2]].id;
	printf("%s-%d(",bjvertex[board[bcount-1]].name,line);
	scount=1; 
	for(i=bcount-2;i>0;i--,scount++){
		if(bjweights[board[i]][board[i-1]].id!=line){
			line=bjweights[board[i]][board[i-1]].id;
			printf("%d)-%s-%d(",scount,bjvertex[board[i]].name,line);
			scount=0;
		}
	}
	printf("%d)-%s",scount,bjvertex[board[i]].name);
}

int main(void) {   
	char start[100],end[100]; 
	scanf("%s %s",start,end);
	creategraph();
	int i,j,k,v0,v1;
	for(v0=0;v0<Vnum;v0++)
		if(strcmp(bjvertex[v0].name,start)==0)
			break;
	for(v1=0;v1<Vnum;v1++)
		if(strcmp(bjvertex[v1].name,end)==0)
			break;
	dijkstra(v0,v1);
	printpath(v0,v1); 
	return 0;
}
