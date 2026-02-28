#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
int main()
{
    //숫자를 문자열(아스키코드)로 받자

    int n = 0,sum=0;
    char a[101];
    scanf("%d", &n);
    scanf("%s", &a);

    for (int i = 0; i < n; i++) {
        sum = sum + a[i] - '0';
    }

    printf("%d", sum);

    return 0;
}