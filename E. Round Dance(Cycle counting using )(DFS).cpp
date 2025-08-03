#include<bits/stdc++.h>
using namespace std;
int const mx = 1e6;
int x,c[5],dp[1000005];
int sol(int num){
    if(num == 0) return 0;
    if(dp[num] != -1) return dp[num];
    int ans = -1e9;
    for(int i =0;i<3;i++){
        if(num-c[i] >= 0) ans = max(ans,1+sol(num-c[i]));
    }

    dp[num]  =ans;

    return ans;
}
void naf(){
   cin >>x;
   for(int i =0;i<3;i++) cin >> c[i];

   memset(dp,-1,sizeof dp);

   cout << sol(x);

}

int main(){
    // int t; cin >> t;
    // while(t--)
        naf();
}
