#include<stdio.h>

//邻接表 
#define MaxV <最大顶点个数>
typedef struct  edge{ 
    int adjvex;
    int weight;
    struct edge *next;
}ELink;
typedef struct ver{
    vertype vertex;
    ELink *link;
}VLink;
VLink  G[MaxV];

//邻接矩阵 
#define MaxV    <最大顶点个数>
typedef struct  edge{ 
    int  weight;
    
}Edge;
Vertype  Vertex[MaxV];
Edge  G[MaxV][MaxV];
 
//边集数组
#define MaxV    <最大顶点个数>
#define MaxE   <最大边数>
typedef struct  edge{ 
    int v1, v2;
    int  weight;
}Edge;
Vertype  Vertex[MaxV];
Edge  G[MaxE];
 
 
//图的基本操作
createGraph()：	创建一个图
destoryGraph()：	删除一个图
insertVex(v)：	在图中插入一个顶点v
deleteVex(v)：	在图中删除一个顶点v
insertEdge(v,w)：	在图中插入一条边<v,w>
deleteEdge(v,w)：	在图中删除一条边<v,w>
traverseGraph()：	遍历一个图
 

//在链表尾插入一个节点
Elink  *insertEdge(ELink *head, int avex)
{
    ELink *e,*p;
    e =(ELink *)malloc(sizeof(ELink));
    e->adj= avex; e->wei=1; e->next = NULL;
    if(head == NULL)  { head=e; return head; }
    for(p=head; p->next != NULL; p=p->next)
    	;
    p->next = e;  
    return head;
}


//创建一个图 
void createGraph(VLink graph[]){ 
  int i,n,v1,v2;
  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d %d",&v1,&v2);
    while(v2 != -1){
      graph[v1].link=insertEdge(graph[v1].link, v2);
      graph[v2].link=insertEdge(graph[v2].link, v1);
      scanf("%d",&v2);
    }
  }
} 

//图的深度遍历
int  Visited[N]={0}; //标识顶点是否被访问过，N为顶点数
void  travelDFS(VLink  G[ ], int n)
{
    int i;
    for(i=0; i<n; i++) 
		Visited[i] = 0 ;
    for(i=0; i<n; i++)
        if(!Visited[i]) 
			DFS(G, i);
}
void DFS(VLink  G[ ], int v)
{
    ELink  *p;
    Visited[v] = 1; //标识某顶点被访问过
    VISIT(G, v); //访问某顶点
    for(p = G[v].link; p !=NULL;  p=p->next)
         if( !Visited[p->adjvex] )
             DFS(G, p->adjvex);
}


//图的广度遍历
int  Visited[N]={0}; //标识顶点是否被访问，N为顶点数
void  travelBFS(VLink  G[ ], int n)
{
    int i;
    for(i=0; i<n; i++) 
		Visited[i] = 0 ;
    for(i=0; i<n; i++)
        if( !Visited[i] ) 
			BFS(G, i);
}
void BFS(VLink  G[ ], int v)
{
    ELink  *p;
    VISIT(G, v); //访问当前顶点
    Visited[v] = 1; //标识某顶点被访问过
    enQueue(Q, v);//插入队列 
    while( !emptyQ(Q)){
        v = deQueue(Q);  //取出队头元素
        p = G[v].link;  //获取该顶点第一个邻接顶点
        for(; p != NULL ; p = p->next ) //访问该顶点下的每个邻接顶点
            if( !Visited[p->adjvex] ) {
                VISIT(G, v); //访问当前顶点
                Visited[v] = 1; //标识某顶点被访问过
                enQueue(G, p->adjvex);
            }
    }
}
 
//利用邻接表计算独立路径 
#define MAXSIZE  512
struct edge{	//边结点结构
       int  eno; 	//边序号
       int  adjvex;	//邻接顶点
       int  weight;	//边的权重（可为距离或时间），本文中为1
       struct edge  *next;
 };
struct ver {	 //顶点结构，邻接表下标即为顶点序号
       struct edge  *link;
} ; 
struct  ver  G[MAXSIZE]; //由邻接表构成的图
char  Visted[MAXSIZE] = {0}; //标识相应顶点是否被访问 
int paths[MAXSIZE]; 	//独立路径

//基于DFS的独立路径查找算法
void eDFS(int v, int level)
{
    struct edge  *p;
    if(v == V1)  { printPath(level); return; }
    for(p=Graph[v].link; p!= NULL; p=p->next)  
        if( !Visited[p->adjvex]){
	Paths[level] = p->eno;
	Visited[p->adjvex] = 1;
                  eDFS(p->adjvex,level+1);
                  Visited[p->adjvex] = 0;
        }
}
 


int main(void){
	return 0;
}
