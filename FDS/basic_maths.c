//Chef wants to become fit for which he decided to walk to the office and return home by walking. It is known that Chef's office is 
//X km away from his home.
//If his office is open on 5
//5 days in a week, find the number of kilometers Chef travels through office trips in a week.
//Input Format
//First line will contain 
//T, number of test cases. Then the test cases follow.
//Each test case contains of a single line consisting of single integer X.
//Output Format
//For each test case, output the number of kilometers Chef travels through office trips in a week.
//Input
//4
//1
//3
//7
//10
//output
//10
//30
//70
//100
//
#include <stdio.h>

int main(void) {
    int n,x;
	scanf("%d",&n);
	for(int range=0;range<n;range++){
	    scanf("%d",&x);
	    printf("%d\n",x*10);
	}
	return 0;
}


