#include<stdio.h>

int main(void){
	int i,j,k,count1=0,count2=0,windows=3,count=0;	//count1记录顾客的到来，count2记录顾客的服务,windows表示对私窗口数量 
	int time,time_customer[100],customer_in[1000],customer_out[1000],sum_customer=0,wait_customer=0;
	
	//读取周期以及每个时间周期的顾客数量 
	scanf("%d",&time);
	for (i=1;i<=time;i++){
		scanf("%d",&time_customer[i]);
		sum_customer+=time_customer[i];
	}
	
	for (i=1;i<=time;i++){
		count++;	//记录当前的时间周期 
		
		//记录新顾客到来的时间周期 
		for (j=1;j<=time_customer[i];j++)
			customer_in[count1+j]=i;
		count1+=time_customer[i];
		
		//等待序列中增加本周期新到的顾客 
		wait_customer+=time_customer[i];
		//printf("%d %d %d\n",count,wait_customer,windows);		
		//在有新顾客到达的周期内按需求增加窗口 
		if (time_customer[i]>0){
			if (windows==3&&21<=wait_customer)
				windows++;
			if (windows==4&&28<=wait_customer)
				windows++;
		}
		//printf("%d %d %d\n",count,wait_customer,windows);		
		//记录顾客接受服务即离开的周期
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

		
		//每个周期内按需求减少窗口 
		if (windows==5&&wait_customer<35)
			windows--;
		if (windows==4&&wait_customer<28)
			windows--;		
	//	printf("%d %d %d\n",count,wait_customer,windows);
	}
	
	while (wait_customer>0){
		count++;
		
		//记录顾客接受服务即离开的周期
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
		
		//每个周期内按需求减少窗口 
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
