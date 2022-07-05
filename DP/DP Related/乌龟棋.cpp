#include<bits/stdc++.h>
using namespace std;
int f[45][45][45][45], g[355];
int cnt[5];
int n, m;
int dp(int i1, int i2, int i3, int i4){
    if(f[i1][i2][i3][i4]) return f[i1][i2][i3][i4]; //记忆化搜索
    int now = i1+i2*2+i3*3+i4*4+1;
    if(now == n) return 0; //到终点，按照规则不会超过
    
    int &res = f[i1][i2][i3][i4];
    if(i1 < cnt[1]) res = max(res, dp(i1+1,i2,i3,i4)+g[now+1]);
    if(i2 < cnt[2]) res = max(res, dp(i1,i2+1,i3,i4)+g[now+2]);
    if(i3 < cnt[3]) res = max(res, dp(i1,i2,i3+1,i4)+g[now+3]);
    if(i4 < cnt[4]) res = max(res, dp(i1,i2,i3,i4+1)+g[now+4]);
    
    return res;
}
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ ) scanf("%d", &g[i]);
    for(int i = 1; i <= m; i ++ ){
        int x; cin >> x;
        cnt[x] ++ ;
    }
    
    cout << dp(0,0,0,0)+g[1] << endl;
}
