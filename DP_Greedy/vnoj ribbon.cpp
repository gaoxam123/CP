#include<bits/stdc++.h>
using namespace std;
long long t,n,k,a[200005],sum[200005],dp[200005][3];
int main(){
    cin>>t;
    while(t--){
        cin>>n>>k;
        memset(sum,0,sizeof(sum));
        for(int i=1;i<=n;i++){
            cin>>a[i];
            sum[i]=sum[i-1]+a[i];
        }
        memset(dp,0,sizeof(dp));
        for(int i=k;i<=n;i++){
            dp[i][0]=max(0ll,max(dp[i-1][0],dp[i-k][1]-sum[i]+sum[i-k]));
            dp[i][1]=max(0ll,max(dp[i-1][1],dp[i-k][0]+sum[i]-sum[i-k]));
        }
        cout<<max(dp[n][0],dp[n][1])<<endl;
    }
}
