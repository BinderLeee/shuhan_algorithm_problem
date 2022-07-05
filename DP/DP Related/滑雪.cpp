#include<bits/stdc++.h>
using namespace std;

const int N = 110;
int f[N][N], g[N][N];
const int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1};
int n, m;

int dp(int i, int j){
    if(f[i][j]) return f[i][j];
    f[i][j] = 1;

    for(int k = 0; k < 4; k ++ ){
        int a = dx[k]+i, b = dy[k]+j;
        if((a>=1&&a<=n&&b>=1&&b<=m) && g[a][b] < g[i][j])
            f[i][j] = max(f[i][j], dp(a,b)+1);
    }

    return f[i][j];
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++ )
        for(int j = 1; j <= m; j ++ )
            scanf("%d", &g[i][j]);

    int ans = 0;
    for(int i = 1; i <= n; i ++ )
        for(int j = 1; j <= m; j ++ )
            ans = max(ans, dp(i,j));
    
    cout << ans << endl;
}
