#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
int main()
{
    char s[1000000];
    scanf("%s", s);
    int num[] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
    char ans='A';
    int max;
     
    for (int i = 0; s[i]!=0; i++)
    {
        if (s[i] - 'A' > 31) num[s[i] - 'A' - 32]++;
        else num[s[i] - 'A']++;
    }
   
    max = num[0];

    for (int k = 0; k < 26; k++)
    {
        if (max < num[k + 1]) { ans = k + 1 + 'A'; max = num[k + 1]; }
        else if (max == num[k + 1]) { ans = '?'; }
    }
   
    printf("%c", ans);
    
    return 0;
}
