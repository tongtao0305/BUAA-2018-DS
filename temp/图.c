#include<stdio.h>

//�ڽӱ� 
#define MaxV <��󶥵����>
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

//�ڽӾ��� 
#define MaxV    <��󶥵����>
typedef struct  edge{ 
    int  weight;
    
}Edge;
Vertype  Vertex[MaxV];
Edge  G[MaxV][MaxV];
 
//�߼�����
#define MaxV    <��󶥵����>
#define MaxE   <������>
typedef struct  edge{ 
    int v1, v2;
    int  weight;
}Edge;
Vertype  Vertex[MaxV];
Edge  G[MaxE];
 
 
//ͼ�Ļ�������
createGraph()��	����һ��ͼ
destoryGraph()��	ɾ��һ��ͼ
insertVex(v)��	��ͼ�в���һ������v
deleteVex(v)��	��ͼ��ɾ��һ������v
insertEdge(v,w)��	��ͼ�в���һ����<v,w>
deleteEdge(v,w)��	��ͼ��ɾ��һ����<v,w>
traverseGraph()��	����һ��ͼ
 

//������β����һ���ڵ�
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


//����һ��ͼ 
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

//ͼ����ȱ���
int  Visited[N]={0}; //��ʶ�����Ƿ񱻷��ʹ���NΪ������
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
    Visited[v] = 1; //��ʶĳ���㱻���ʹ�
    VISIT(G, v); //����ĳ����
    for(p = G[v].link; p !=NULL;  p=p->next)
         if( !Visited[p->adjvex] )
             DFS(G, p->adjvex);
}


//ͼ�Ĺ�ȱ���
int  Visited[N]={0}; //��ʶ�����Ƿ񱻷��ʣ�NΪ������
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
    VISIT(G, v); //���ʵ�ǰ����
    Visited[v] = 1; //��ʶĳ���㱻���ʹ�
    enQueue(Q, v);//������� 
    while( !emptyQ(Q)){
        v = deQueue(Q);  //ȡ����ͷԪ��
        p = G[v].link;  //��ȡ�ö����һ���ڽӶ���
        for(; p != NULL ; p = p->next ) //���ʸö����µ�ÿ���ڽӶ���
            if( !Visited[p->adjvex] ) {
                VISIT(G, v); //���ʵ�ǰ����
                Visited[v] = 1; //��ʶĳ���㱻���ʹ�
                enQueue(G, p->adjvex);
            }
    }
}
 
//�����ڽӱ�������·�� 
#define MAXSIZE  512
struct edge{	//�߽��ṹ
       int  eno; 	//�����
       int  adjvex;	//�ڽӶ���
       int  weight;	//�ߵ�Ȩ�أ���Ϊ�����ʱ�䣩��������Ϊ1
       struct edge  *next;
 };
struct ver {	 //����ṹ���ڽӱ��±꼴Ϊ�������
       struct edge  *link;
} ; 
struct  ver  G[MAXSIZE]; //���ڽӱ��ɵ�ͼ
char  Visted[MAXSIZE] = {0}; //��ʶ��Ӧ�����Ƿ񱻷��� 
int paths[MAXSIZE]; 	//����·��

//����DFS�Ķ���·�������㷨
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
