#include<stdio.h>
#include<stdlib.h>
int count = 0;

void swap(int v[150], int i, int j)
{
	int tmp;
	tmp = v[i]; v[i] = v[j]; v[j] = tmp;
}

void selectsort(int k[150], int n) {
	int l, r, min;
	for (l = 0; l < n; l++) {
		min = l;
		for (r = l + 1; r < n; r++) {
			count++;
			if (k[r] < k[min]) {
				min = r;
			}
		}
		swap(k, l, min);
	}
}

//冒泡排序,注意必须是最大元素向上冒泡 
void bubblesort(int k[150], int n) {
	int i,l, r, flag;
	for (l = n-1; l >=0; l--) {
		flag = 0;
		for (r = 0; r < l; r++) {
			count++;
			if (k[r] > k[r + 1]) {
				swap(k, r, r + 1);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}



//堆排序 
void adjust(int k[150],int i,int n){
    int j,temp;
    temp=k[i];
    j=2*i+1;
    while(j<n){
    	count++;
        if(j<n-1 && k[j]<k[j+1])
            j++;
        if(temp>=k[j]) {
			break;
		}
        k[(j-1)/2]=k[j];
        j=2*j+1;
    }
    k[(j-1)/2]=temp;
}

void heapsort(int k[150], int n){
	int i, temp;
	//建立初始堆 
	for (i = n / 2 - 1; i >= 0; i--)
		adjust(k, i, n);

	for (i = n - 1; i >= 1; i--) {
		temp = k[i];
		k[i] = k[0];
		k[0] = temp;
		adjust(k, 0, i);
	}
}

//二路归并排序 
void merge(int x[150], int tmp[150], int left, int leftend, int rightend) {
	int i = left, j = leftend + 1, q = left;
	while (i <= leftend && j <= rightend){
		count++;
		if (x[i] <= x[j]) {
			tmp[q++] = x[i++];
		}
		else
			tmp[q++] = x[j++];
	}
	while (i <= leftend)
		tmp[q++] = x[i++];
	while (j <= rightend)
		tmp[q++] = x[j++];
	for (i = left; i <= rightend; i++)
		x[i] = tmp[i];
}
void mSort(int k[150], int tmp[150], int left, int right){
	int center;
	if (left < right) {
		center = (left + right) / 2;
		mSort(k, tmp, left, center);
		mSort(k, tmp, center + 1, right);
		merge(k, tmp, left, center, right);
	}
}
void mergesort(int k[150], int n)
{
	int* tmp;
	tmp = (int*)malloc(sizeof(int) * n);
	if (tmp != NULL) {
		mSort(k, tmp, 0, n - 1);
		free(tmp);
	}
	else
		printf("No space for tmp array!!!\n");
}



//快速排序 
void quicksort(int k[150], int left, int right) {
	int i, last;
	if (left < right) {
		last = left;
		for (i = left + 1; i <= right; i++){
			count++;
			if (k[i] < k[left]) {
				swap(k, ++last, i);
			}
		}
		swap(k, left, last);
		quicksort(k, left, last - 1);
		quicksort(k, last + 1, right);
	}
}

int main(void) {
	int n, i, j, type, num[150];

	scanf("%d %d", &n, &type);
	for (i = 0; i < n; i++)
		scanf("%d", &num[i]);

	switch (type) {
	case 1:selectsort(num, n); break;
	case 2:bubblesort(num, n); break;
	case 3:heapsort(num, n); break;
	case 4:mergesort(num, n); break;
	case 5:quicksort(num, 0, n - 1); break;
	}

	for (i = 0; i < n; i++)
		printf("%d ", num[i]);
	printf("\n%d", count);

	return 0;
}
