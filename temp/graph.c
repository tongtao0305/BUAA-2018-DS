#include<stdio.h>

//建立邻接矩阵 
#define MaxValue Int_Max
#defien MaxVNum 100
void ADJMATRIX(int A[][MaxVNum],int n,int e){
	int i,j,k,weight;
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			A[i][j]=MaxValue;	//给邻接矩阵赋初值 
	for (k=0;k<e;k++){
		scanf("%d %d %d",&i,&j,&weight);
		A[i][j]=weight;
		A[j][i]=weight;
	} 
}

//定义邻接表中的边节点与顶点节点
typedef struct edge{
	int adjvex;
	int weight;
	struct edge *next;
}ELink;
typedef struct ver{
	vertype vertex;
	Elink*link;
}VLink; 

//建立邻接表
void ADJLIST(VLink G[],int n,int e){
	int k,vi,vj,weight;
	Elink *p,*q;
	for (k=0;k<n;k++){
		G[k].vertex=k+1;
		G[k].link=NULL; 
	}
	for (k=0;k<e;k++){
		scanf("%d %d %d",&vi,&vj,&weight);
		p=(ELink*)malloc(sizeof(ELink));
		p->adjvex=vj-1;
		p->weight=weight;
		p->next=NULL;
		if (!G[vi-1].link)
			G[vi-1].link=p;
		else{
			q=G[vi-1].link;
			while(q->link)
				q=q->next;
			q->next=p;
		}
	}
} 

//删除图中顶点数据为item的节点
void DELVER(VLink G[],int n,vertype item){
	int i,k=-1;
	ELink *p,*q,*r;
	for (i=0;i<n;i++){
		if (G[i].vertex==item){
			k=i;
			break;
		}
	}
	if (k!=-1){
		p=G[k].link;
		for (i=k+1;i<n;i++){
			G[i-1].vertex=G[i].vertex;
			G[i-1].link=G[i].link;
		}
		n--;
		while(p!=NULL){
			r=p;
			p=p->next;
			free(r);
		}
		for (i=0;i<n;i++){
			p=G[i].link;
			while(p!=NULL)
				if (p->adjvex==k){
					if (G[i].link==p)
						G[i].link=p->next;
					else 
						q->next=p->next;
					r=p;
					p=p->next;
					free(r);
				}
				else{
					if (p->adjvex>k)
						p->adjvex--;
					q=p;
					p=p->next
				}
		}
	}
} 


//Prim算法最小生成树
#define MAXVNum 100
void MINSPANT_PRIM(int GE[][MaxVNum],int n){
	int lowcost[n],teend[MaxVNum],i,j,k,mincost;
	lowcost[0]=0;
	teend[0]=0;
	for (j=1;j<n;j++){
		teend[j]=0;
		lowcost[j]=GE[0][j];
	}
	for (i=1;i<n;i++){
		mincost=MaxVNum;
		j=1;
		while(j<n){
			if (lowcost[j]>0&&mincost>lowcost[j]){
				mincost=lowcost[j];
				k=j;
			}
			j++;
		}
		printf("(%d,%d)",teend[k],k);
		loecost[k]=0;
		for (j=0;j<n;j++){
			if (GE[k][j]<lowcost[j]){
				lowcost[j]=GE[k][j];
				teend[j]=k;
			}
		}
	}
} 


