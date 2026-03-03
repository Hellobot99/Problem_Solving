#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS


int main()
{
    int m = 0,n = 0,i;
    scanf("%d", &m);

       
    for (i = 0; i < m; i++)
    {
        n++;
        
        if (m == n + (n % 10000000 / 1000000) + (n % 1000000 / 100000) + (n % 100000 / 10000) + (n % 10000 / 1000) + (n % 1000 / 100) + (n % 100 / 10) + (n % 10))
        {
            break;
        }
        if (i == m - 1)
        {
            printf("0");
        }
        
    }

    

    if (n != m) { printf("%d", n); }
    
    
    return 0;
}
