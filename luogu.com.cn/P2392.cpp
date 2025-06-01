#include<bits/stdc++.h>
using namespace std;
int s[5],a[5][21],tot,ALL,dp[100010];
int main()
{
    for(int i=1; i<=4; i++) scanf("%d",&s[i]);
    for(int i=1; i<=4; i++) {//采用二维数组的方式对代码进行精简 
        for(int j=1; j<=s[i]; j++){
            scanf("%d",&a[i][j]);
            ALL+=a[i][j];//统计总重 
        }
        for(int p=1;p<=s[i];p++) {//装箱问题 
            for(int q=ALL>>1;q>=a[i][p];q--) {//a>>1即a/2 
                dp[q]=max(dp[q],dp[q-a[i][p]]+a[i][p]);
            }
        }//累加最接近ALL/2的值 
        tot+=ALL-dp[ALL>>1],ALL=0;
        if(i!=4) memset(dp,0,sizeof dp);
    }
    printf("%d\n",tot);
}