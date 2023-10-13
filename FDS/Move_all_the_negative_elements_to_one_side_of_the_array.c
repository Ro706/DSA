//Move all the negative elements to one side of the array
#include<stdio.h>
#define SIZE 5

int main(){
	int arr[SIZE];
	printf("Enter the element of the array: ");
	for (int i =0;i<SIZE;i++){
		scanf("%d",&arr[i]);
	}
	 for(int i=1;i<=SIZE;i++){
                int flag=0;
                for(int j=0;j<SIZE-i;j++){
                        if(arr[j]>arr[j+1]){
                                int t = arr[j];
                                arr[j]=arr[j+1];
                                arr[j+1] =t;
                                flag = 1;
                        }
                        if(flag == 0)
                                break;
                 }
        }
	for (int i =0;i<SIZE;i++){
		printf("%d ",arr[i]);
	}
	return 0 ;
}
