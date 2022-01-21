#include<stdio.h>
#include<string.h>
typedef struct Sign{
	char symbol;
	int line;
}sign;

sign mark1[250],mark2[250];	//mark2������¼���еķ��� 

int main(void){
	int i,j,k,len,top1=-1,top2=-1,flag=0,count_line=0;
	FILE *fpin;
	char temp[200]; 
	
	if ((fpin=fopen("example.c","r"))==NULL){
		printf("CANNOT OPEN THE FILE!");
		return 1;	//�޷����ļ����˳����� 
	}
	
	while((fgets(temp,200,fpin))!=NULL){
		
		count_line++;
		len=strlen(temp);	//��¼���е��ַ����� 
		
		for (i=0;i<len;i++){
			
			if (flag==1){
				//����ڶ���ע�͵ķ�Χ�� 
				if (i>=1&&temp[i]=='/'&&temp[i-1]=='*'){
					flag=0;
				}
				continue;
			}
			else if (flag==2){
				if (temp[i]!='"')
					continue;
				else
					flag=0;
			}
			else{
				if (i>=1&&temp[i]=='*'&&temp[i-1]=='/')
					flag=1;	//���ֶ���ע�ͷ��� 
				if (temp[i]=='"')
					flag=2;	//����˫���Ż��ߵ����� 
				if (i>=1&&temp[i]=='/'&&temp[i-1]=='/')
					break;
				if(temp[i]=='{'){
					if (mark1[top1].symbol=='('){
						printf("without maching '%c' at line %d\n",mark1[top1].symbol,mark1[top1].line);
						return 0;
					}
					mark1[++top1].symbol=temp[i];
					mark1[top1].line=count_line;
					mark2[++top2].symbol=temp[i];
					mark2[top2].line=count_line;
				}
				else if(temp[i]=='('){
					mark1[++top1].symbol=temp[i];
					mark1[top1].line=count_line;
					mark2[++top2].symbol=temp[i];
					mark2[top2].line=count_line;
				}
				else if(temp[i]=='}'){
					mark2[++top2].symbol=temp[i];
					mark2[top2].line=count_line;
					if (mark1[top1].symbol=='{')
						top1--;
					else if (top1>=1&&mark1[top1-1].symbol=='{'){
						printf("without maching '%c' at line %d\n",mark1[top1].symbol,mark1[top1].line);
						return 0;
					}
					else{
						printf("without maching '}' at line %d\n",count_line);
						return 0;
					}
				}
				else if(temp[i]==')'){
					mark2[++top2].symbol=temp[i];
					mark2[top2].line=count_line;
					if (mark1[top1].symbol=='(')
						top1--;
					else if (mark1[top1-1].symbol=='('){
						printf("without maching '%c' at line %d\n",mark1[top1].symbol,mark1[top1].line);
						return 0;
					}	
					else{
						printf("without maching ')' at line %d\n",count_line);
						return 0;
					}
				}
			}
		}
	}
	
	if (top1==0){
		printf("without maching '%c' at line %d\n",mark1[top1].symbol,mark1[top1].line);
	}
	else{
		//������з��Ŷ���ԣ���������з��� 
		for (i=0;i<=top2;i++){
			printf("%c",mark2[i].symbol);
		} 
	}
		
	return 0;
}
