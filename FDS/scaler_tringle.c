#include <stdio.h>

int main(void) {
	// your code goes here
	int a,b,c;
	int range;
	scanf("%d",&range);
	for (int i =0;i<range;i++){
	    scanf("%d %d %d",&a,&b,&c);
	    if ((a!=b)&&(b!=c)&&(a!=c))
	        printf("YES");
	   else
	        printf("NO");
	   printf("\n");
	}
	return 0;
}

