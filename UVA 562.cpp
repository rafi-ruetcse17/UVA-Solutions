#include<bits/stdc++.h>
using namespace std;
int sum, a[105], n, mn ;
int dp[105][50005];
int solve(int pos, int s){
    if(pos>n) return abs(s-sum+s);
    if(dp[pos][s]!=-1) return dp[pos][s];
    int p = solve(pos+1, s+a[pos]);
    int q = solve(pos+1, s);

    return dp[pos][s] = min(p, q);

}
int main()
{
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        sum =0;
        mn = 1e9;
        memset(dp, -1, sizeof dp);
        for(int i=1;i<=n;i++){
            cin >> a[i];
            sum+=a[i];
        }
        mn = solve(1, 0);
        cout << mn << "\n";
    }
}
