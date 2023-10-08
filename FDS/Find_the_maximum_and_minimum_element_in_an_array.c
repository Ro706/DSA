//Find the maximum and minimum element in an array
#include<stdio.h>
int main(){
	int a[5]={1,7,2,6,8};
	int min = a[0];
	for (int i =0;i<5;i++){
		if (a[i]<min)
			min=a[i];
	}
	int max = a[0];
	for(int i = 0 ;i <5;i++){
		if (a[i]>max){
			max = a[i];
		}
	}
	printf("min :%d and max :%d ",min,max);
	}
   	
