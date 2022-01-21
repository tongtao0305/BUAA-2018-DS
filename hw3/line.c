#include<stdio.h>
int line[105][5];
int main(void) {
	int n, a, b, c, d, i, j, k, count=0, check,len,max = 0,maxx,maxy;
	scanf("%d", &n);
	for (i=0;i<n;i++)
		scanf("%d %d %d %d", &line[i][1], &line[i][2], &line[i][3], &line[i][4]);
	
	for (i=0;i<n;i++){
		a=line[i][1];
		b=line[i][2];
		c=line[i][3];
		d=line[i][4];
		len=1;
		check=1;
		
		
		while(check==1){
			for (j=0;j<n;j++){
				if (a == line[j][3] && b == line[j][4]) {
					a = line[j][1];
					b = line[j][2];
					len++;
					check=1;
					break;
				}
				else if (c == line[j][1] && d == line[j][2]) {
					c = line[j][3];
					d = line[j][4];
					len++;
					check=1;
					break;
				}
			}
			if(j==n)
				check=0;
		}
		
		if(len>max){
			max=len;
			maxx=a;
			maxy=b;
		}
	}
	
	printf("%d %d %d",max,maxx,maxy);
	
	return 0;
}
