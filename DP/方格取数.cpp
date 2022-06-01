#include<bits/stdc++.h>
using namespace std;

const int N = 110;
int n, g[N][N], f[N][N][N];

int main(){
    scanf("%d", &n);
    
    int a, b, c;
    while(cin>>a>>b>>c && (a!=0 && b!=0 && c!=0)) g[a][b] = c;
    
    //f[k][i1][i2], (i1,j1),(i2,j2)
    for(int k = 2; k <= 2*n; k ++ ){
        for(int i1 = 1; i1 <= n; i1 ++ ){
            for(int i2 = 1; i2 <= n; i2 ++ ){
                int j1 = k-i1, j2 = k-i2;
                if(j1>=1&&j1<=n&&j2>=1&&j2<=n){ //不越界
                    int t = g[i1][j1];
                    if(i1 != i2) t += g[i2][j2]; //不在同一格子
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

    cout << f[2*n][n][n] << endl;

    return 0;
}