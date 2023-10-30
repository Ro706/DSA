#include<stdio.h>
int main(){
	int n,value_1,value_2;
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		scanf("%d %d",&value_1,&value_2);
		int p = value_1 * value_2;
		if (p >= 10000 && p <= 99999)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
		
