#include<stdio.h>
long fac(int k)
{
    int i;
    long j = 1;
    for(i=1;i<=k;i++)
        j=j*i;
    return(j);
}

int main()
{
    int i;
    int k;
    printf("请输入一个k值:");
    scanf("%d",&k);
        int sum;
        sum =0;
    for(i=1;i<=k;i++)
    {
        sum=sum+fac(i);
    }
    printf("1!+2!+...+k!",sum);
    return 0;
}