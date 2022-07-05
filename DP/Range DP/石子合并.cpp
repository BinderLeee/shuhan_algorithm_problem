// ----------------------------------------------------------------------------------------------------------------------------------
#include<bits/stdc++.h>
using namespace std;
const int N = 350;
int f[N][N];
int s[N];
int main(){
    memset(f, 0x3f, sizeof f);
    int n; cin >> n;
    for(int i = 1; i <= n; i ++ ){
        int x; cin >> x;
        s[i] = s[i-1] + x;
    }
    
    //区间dp模板
    for(int len = 1; len <= n; len ++ ){ //[i,j]
        for(int i = 1; i+len-1 <= n; i ++ ){
            int j = i+len-1;
            if(len == 1){
                f[i][j] = 0;
                continue;
            }
            
            for(int k = i; k <= j-1; k ++ ) //[i,k], [k+1,j]
                f[i][j] = min(f[i][j], f[i][k]+f[k+1][j]+s[j]-s[i-1]);
        }
    }
    
    cout << f[1][n] << endl;
}
// --------------------------------------------------------------------------------------------------------------------------------
#include<bits/stdc++.h>
using namespace std;
const int N = 350;
int f[N][N], s[N];
bool vis[N][N];
int dp(int i, int j){
    if(vis[i][j]) return f[i][j];   //记忆化搜索
    vis[i][j] = 1;
    
    if(i == j) f[i][j] = 0; //判断边界
    
    for(int k = i; k <= j-1; k ++ )
        f[i][j] = min(f[i][j], dp(i,k)+dp(k+1,j)+s[j]-s[i-1]);
    
    return f[i][j];
}
int main(){
    memset(f, 0x3f, sizeof f);
    int n; cin >> n;
    for(int i = 1; i <= n; i ++ ){
        int x; cin >> x;
        s[i] = s[i-1] + x;
    }
    
    cout << dp(1,n) << endl;
    
    return 0;
}
