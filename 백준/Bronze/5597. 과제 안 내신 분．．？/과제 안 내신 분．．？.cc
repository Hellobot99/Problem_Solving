#include <stdio.h>
int main(void)
{
    int a,i,b,c,d,m,n,e,j;
    int num[31]={0};
	
	for(i=0;i<28;i++)
	{
		scanf("%d",&a);
		num[a]=1;
	}
	
	for(i=1;i<31;i++)
	{
		if(num[i]==0)
		{
			printf("%d\n",i);
		}
	}

    return 0;
}