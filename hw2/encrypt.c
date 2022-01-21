#include<stdio.h>
#include<string.h>

int main(void){
	char in[60],out[30],line[1000];
	int i,j,k=1,count[30];
	
	FILE *fpin,*fpout;	
	if((fpin=fopen("encrypt.txt","r"))==NULL)
		return 1;	//无法打开filein.txt
	if((fpout=fopen("output.txt","w"))==NULL)
		return 1;	//无法打开fileout.txt	
	
	for (i=0;i<30;i++)
		count[i]=0;
	
	scanf("%s",in);
	for(i=0;in[i]!='\0';i++){
		if(count[in[i]-'a'+1]==0){
			out[k++]=in[i];
			count[in[i]-'a'+1]=1;
		}
	}
	
	for (i=26;i>=1;i--){
		if(count[i]==0)
			out[k++]=i-1+'a';	
	}

	for (i=1;i<=26;i++){
		printf("%c",out[i]);
	}
	printf("\n");

	while(fgets(line,BUFSIZ,fpin)!=NULL){
		for (i=0;line[i]!='\0';i++){
			if(line[i]>='a'&&line[i]<='z')
				line[i]=out[line[i]-'a'+1];
		}
		fprintf(fpout,"%s",line);
	}
	
	return 0;
}
