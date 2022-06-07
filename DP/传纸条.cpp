#include<bits/stdc++.h>
using namespace std;

const int N = 110;
int m, n;
int g[N][N], f[N][N][N];

int main(){
    scanf("%d%d", &m, &n);
    for(int i = 1; i <= m; i ++ )
        for(int j = 1; j <= n; j ++ )
            scanf("%d", &g[i][j]);
    
    for(int k = 2; k<=n+m; k ++ ){
        for(int i1 = 1; i1 <= m; i1 ++ ){
            for(int i2 = 1; i2 <= m; i2 ++ ){
                int j1=k-i1, j2=k-i2;
                if(j1>=1&&j1<=n&&j2>=1&&j2<=n && (i1 != i2 || k==2 || k==n+m)){ //不越界且不能走到同一格(终点起点除外)
                    int t = g[i1][j1]+g[i2][j2];
                    int &x = f[k][i1][i2];
                    //四种情况
                    x = max(x, f[k-1][i1-1][i2]+t);
                    x = max(x, f[k-1][i1][i2-1]+t);
                    x = max(x, f[k-1][i1][i2]+t);
                    x = max(x, f[k-1][i1-1][i2-1]+t);
                }
            }
        }
    }

    cout << f[n+m][m][m] << endl;
}