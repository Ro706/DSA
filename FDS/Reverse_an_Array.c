//Reverse an Array
#include<stdio.h>
int main(){
	int a[5]={1,2,3,4,5},b[5];
	for(int i =4 ;i>=0;i--){
		static int j = 0;
			b[j]=a[i];
			j++;
		}
		for (int i =0 ;i<5;i++){
		printf(" %d",b[i]);
	}
}
