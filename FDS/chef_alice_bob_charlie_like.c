#include <stdio.h>

int main(void) {
	// your code goes here
	int n,value;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
	    scanf("%d",&value);
	    if(value%2 ==0 && value%7==0)
	        printf("Alice\n");
	    else if (value%2 ==1 && value%9 ==0)
	        printf("Bob\n");
	    else
	        printf("Charlie\n");
	}
	return 0;
}


