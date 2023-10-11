//right angle triangle right side
#include <stdio.h>
int main()
{
    int height = 5; 
    for (int i = 0; i < height; i++) 
    {
        for (int j = 0; j < height - i - 1; j++) 
        {
            printf("  "); 
        }
        for (int k = 0; k <= i; k++) 
        {
            printf("*");  
        }
        printf("\n");
    }
    return 0;
}

