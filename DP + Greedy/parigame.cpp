#include<bits/stdc++.h>
using namespace std;
int t,n,a[505][505],dp[505][505],r[505][505],c[505][505];
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>a[i][j];
                a[i][j] %= 2;
            }
        }
        memset(dp,0,sizeof(dp));
        memset(r,0,sizeof(r));
        memset(c,0,sizeof(c));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                c[j][i]=(c[j][i-1]+a[i][j])%2;
                r[i][j]=(r[i][j-1]+a[i][j])%2;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dp[i][j] = (!c[j][i] && !dp[i][j-1]) | (!r[i][j] && !dp[i-1][j]);
            }
        }
        if(dp[n][n]==1) cout<<"YES\n";
        else cout<<"NO\n";
        /*bool ans=false;
        for(int i=1;i<=n;i++){
            if(dp[1][i]==dp[n][n]||dp[i][1]==dp[n][n]){
                ans=true;
                break;
            }
        }
        if(ans) cout<<"YES\n";
        else cout<<"NO\n";*/
    }
}
