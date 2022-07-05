#include<bits/stdc++.h>
using namespace std;

const int N = 1010;
int f[N][N], g[N][N];
int id, res, n;
const int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1};

int dp(int i, int j){
    if(f[i][j]) return f[i][j];
    f[i][j] = 1;    //占的第一个格子也算
    
    for(int k = 0; k < 4; k ++ ){
        int a = i+dx[k], b = j+dy[k];
        if((a>=0&&a<n&&b>=0&&b<n) && g[a][b] == g[i][j] + 1)
            f[i][j] = max(f[i][j], dp(a,b)+1);
    }
    
    return f[i][j];
}

void solve(){
    memset(f, 0, sizeof f);
    
    cin >> n;
    for(int i = 0; i < n; i ++ )
        for(int j = 0; j < n; j ++ )
            scanf("%d", &g[i][j]);
    
    id = n*n, res = 0;
    for(int i = 0; i < n; i ++ )
        for(int j = 0; j < n; j ++ )
            if(dp(i,j) > res || (dp(i,j)==res && g[i][j] < id)){
                res = dp(i,j);
                id = g[i][j];
            }
}

int main(){
    int T; cin >> T;
    for(int cases = 1; cases <= T; cases ++ ){
        solve();
        printf("Case #%d: %d %d\n", cases, id, res);
    }
}
