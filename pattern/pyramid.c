//pyramid
#include<stdio.h>
int main(){
        int row = 5,col = 5;
        for (int row =0;row <= 5;row++){
                for (int col = 0;col<(5-row);col++){
                        printf(" ");
                }
                for(int k = 5-row;k<5;k++){
                        printf("* ");
                }

                printf("\n");
        }
        return 0;
}
