#include<bits/stdc++.h>
using namespace std;

const int N = 110, INF = 1e8;
int n, m, f[N][N], g[N][N], ne[N][N];

void print(){
   int ans = INF, st = 0, j = 1;
        for(int i = 1; i <= n; i ++ )
            if(f[i][1] < ans){
                ans = f[i][1];
                st = i;
            }
        cout << st; st = ne[st][j]; j ++ ;
        while(j <= m){
            cout << " " << st;
            st = ne[st][j];
            j ++ ;
        }
        puts("");
        cout << ans << endl; 
}

int main(){
    while(cin >> n >> m){
        for(int i = 1; i <= n; i ++ )
            for(int j = 1; j <= m; j ++ )
                scanf("%d", &g[i][j]);

        for(int j = m; j >= 1; j -- ) //因为f[i][j]表示从(i,j)走到终点的最小值所以要逆推
            for(int i = 1; i <= n; i ++ ){
                if(j == m) f[i][j] = g[i][j];
                else{
                    f[i][j] = INF;
                    int row[3] = {i-1, i, i+1}; //方便处理字典序从小到大
                    if(i == 1) row[0] = n;
                    if(i == n) row[2] = 1;
                    sort(row, row + 3);

                    for(int k = 0; k < 3; k ++ )
                        if(f[row[k]][j+1]+g[i][j] < f[i][j]){
                            f[i][j] = f[row[k]][j+1]+g[i][j];
                            ne[i][j] = row[k]; //因为f[i][j]是在做完决策后是确定的所以可以用用(i,j)保存其他信息
                        }
                }
            }
    
        print();
    }
    
    return 0;
}
