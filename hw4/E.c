#include<stdio.h>

int main(void){
	int i,j,k,count1=0,count2=0,windows=3,count=0;	//count1��¼�˿͵ĵ�����count2��¼�˿͵ķ���,windows��ʾ��˽�������� 
	int time,time_customer[100],customer_in[1000],customer_out[1000],sum_customer=0,wait_customer=0;
	
	//��ȡ�����Լ�ÿ��ʱ�����ڵĹ˿����� 
	scanf("%d",&time);
	for (i=1;i<=time;i++){
		scanf("%d",&time_customer[i]);
		sum_customer+=time_customer[i];
	}
	
	for (i=1;i<=time;i++){
		count++;	//��¼��ǰ��ʱ������ 
		
		//��¼�¹˿͵�����ʱ������ 
		for (j=1;j<=time_customer[i];j++)
			customer_in[count1+j]=i;
		count1+=time_customer[i];
		
		//�ȴ����������ӱ������µ��Ĺ˿� 
		wait_customer+=time_customer[i];
		//printf("%d %d %d\n",count,wait_customer,windows);		
		//�����¹˿͵���������ڰ��������Ӵ��� 
		if (time_customer[i]>0){
			if (windows==3&&21<=wait_customer)
				windows++;
			if (windows==4&&28<=wait_customer)
				windows++;
		}
		//printf("%d %d %d\n",count,wait_customer,windows);		
		//��¼�˿ͽ��ܷ����뿪������
		if (wait_customer>windows){
			for (j=1;j<=windows;j++)
				customer_out[count2+j]=i;
			count2+=windows;
			wait_customer-=windows;
			//printf("***%d : %d\n",count,count2);
		}
		else{
			for (j=1;j<=wait_customer;j++)
				customer_out[count2+j]=i;
			count2+=wait_customer;
			wait_customer=0;
			//printf("***%d : %d\n",count,count2);
		}

		
		//ÿ�������ڰ�������ٴ��� 
		if (windows==5&&wait_customer<35)
			windows--;
		if (windows==4&&wait_customer<28)
			windows--;		
	//	printf("%d %d %d\n",count,wait_customer,windows);
	}
	
	while (wait_customer>0){
		count++;
		
		//��¼�˿ͽ��ܷ����뿪������
		if (wait_customer>windows){
			for (j=1;j<=windows;j++)
				customer_out[count2+j]=count;
			count2+=windows;
			wait_customer-=windows;
			//printf("***%d : %d\n",count,count2);
		}
		else{
			for (j=1;j<=wait_customer;j++)
				customer_out[count2+j]=count;
			count2+=wait_customer;
			wait_customer=0;
			//printf("***%d : %d\n",count,count2);
		}
		//printf("%d %d %d\n",count,wait_customer,windows);
		
		//ÿ�������ڰ�������ٴ��� 
		if (windows==5&&wait_customer<35)
			windows--;
		if (windows==4&&wait_customer<28)
			windows--;
		//printf("%d %d %d\n",count,wait_customer,windows);			
	}
	
	for (i=1;i<=sum_customer;i++){
		printf("%d : %d\n",i,customer_out[i]-customer_in[i]);
	}
	
	return 0;
} 
