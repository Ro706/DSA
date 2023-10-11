#include<stdio.h>
int SIZE = 5;
void descending(int *arr,int x){
      printf("%d", arr[SIZE-(x+1)]);
}
void ascending(int *arr,int x){
      printf("%d", arr[x]);
}
int main(){
	int arr[SIZE],k;
	printf("Enter arr element: ");
	for(int i =0 ;i<SIZE;i++)
		scanf("%d",&arr[i]);
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
	printf("Enter kth tearm:");
        scanf("%d",&k);
	int a;
	printf("ascending(1)/descending(2): ");
	scanf("%d",&a);
	if (a == 1)
		ascending(arr,k);
	else
		descending(arr,k);	
	return 0;
}
