#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
int main()
{
    int n = 0,a,res=0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        if (a == 2) { res++; }
        for (int k = 2; k < a; k++)
        {
            if (k == a - 1) { res++; }
            if (a % k == 0) { break; }
        }
    }

    printf("%d", res);

    return 0;
}