#include<stdio.h>
#include<string.h>
int main(void){
	char string[1001]; 
	int i,j,k,num[1001],count=0,temp=0,special=0;
	
	gets(string);
	
	for (i=0;string[i]!='=';i++){
		if (string[i]==' ')
			continue;
		else if (string[i]>='0'&&string[i]<='9')
			temp=temp*10+string[i]-'0';
		else if (string[i]=='-'){
			
			if (special!=0){
				if (special==1){
					num[count-1]=num[count-1]*temp;
					temp=0;
					special=0;
				}
				else{
					num[count-1]=num[count-1]/temp;
					temp=0;
					special=0;
				}
			}
			else{
				//�������� 
				num[count]=temp;
				temp=0;
				count++;				
			}
			
			//������� 
			num[count]=-1;
			count++;
		} 
		else if (string[i]=='+'){
			
			if (special!=0){
				if (special==1){
					num[count-1]=num[count-1]*temp;
					temp=0;
					special=0;
				}
				else{
					num[count-1]=num[count-1]/temp;
					temp=0;
					special=0;
				}
			}
			else{
				//�������� 
				num[count]=temp;
				temp=0;
				count++;				
			}
			
			//������� 			
			num[count]=-2;
			count++;
		}
		else if (string[i]=='*'){
			
			if (special!=0){
				if (special==1){
					num[count-1]=num[count-1]*temp;
					temp=0;
					special=0;
				}
				else{
					num[count-1]=num[count-1]/temp;
					temp=0;
					special=0;
				}
			}
			else{
				//�������� 
				num[count]=temp;
				temp=0;
				count++;				
			}
			
			//�������״̬ 
			special=1;
		}
		else if (string[i]=='/'){
			
			if (special!=0){
				if (special==1){
					num[count-1]=num[count-1]*temp;
					temp=0;
				}
				else{
					num[count-1]=num[count-1]/temp;
					temp=0;
				}
			}
			else{
				//�������� 
				num[count]=temp;
				temp=0;
				count++;				
			}
			
			//�������״̬ 
			special=2;
		}
	}
	
	//�ж����һ������״̬ 
	if (special!=0){
		if (special==1){
			num[count-1]=num[count-1]*temp;
			temp=0;
			special=0;
		}
		else{
			num[count-1]=num[count-1]/temp;
			temp=0;
			special=0;
		}
	}
	else{
		//�������� 
		num[count]=temp;
		temp=0;
		count++;				
	}
	
	i=1;
	temp=num[0];
	while(i<count){
		if (num[i]==-1)
			temp=temp-num[i+1];
		if (num[i]==-2)
			temp=temp+num[i+1];
		i++;
	}
	
	printf("%d",temp);
	
	return 0;
}
