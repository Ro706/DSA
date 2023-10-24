#include <stdio.h>

int main(void) {
	// your code goes here
	int n,x,y;
	scanf("%d",&n);
	for(int range=0;range<n;range++){
	    scanf("%d%d",&x,&y);
	    	if(x>=y){
    		    printf("%d",y);
    		}
    		else{
    		    printf("%d",2*y-x);
    		}
		printf("\n");
	}
	return 0;
}

