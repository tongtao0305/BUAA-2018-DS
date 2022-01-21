#include<stdio.h>
#include<string.h>
#define tolower(c) (c>='A'&&c<='Z'?'a'-'A'+c:c)
int main(void){
	int i,j,k,count=0;
	char in[100],out[100],line[1000],*p;
	FILE *fpin,*fpout;
	
	scanf("%s",in);
	scanf("%s",out);
	
	if((fpin=fopen("filein.txt","r"))==NULL)
		return 1;	//无法打开filein.txt
	if((fpout=fopen("fileout.txt","w"))==NULL)
		return 1;	//无法打开fileout.txt		

	while(fgets(line,BUFSIZ,fpin)!=NULL){
		for (i=0;line[i]!='\0';){
			count=0;
			for (j=0;j<strlen(in);j++){
				if(tolower(line[i+j])!=tolower(in[j])){
					count=1;
					break;
				}
			}
			if(count==1){
				fprintf(fpout,"%c",line[i]);
				i++;
			}
			else{
				fprintf(fpout,"%s",out);
				i=i+strlen(in);
			}
		}
	}
	
	return 0;
}
