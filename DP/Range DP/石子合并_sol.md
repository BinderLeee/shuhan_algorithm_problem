* https://www.acwing.com/problem/content/description/284/
* 难度：普及
* 标签：区间DP
* 补充：模板题 </br>
f[i][j]表示合并[i,j]这一区间的石子最小代价。状态转移方程：f(i,j) = min(f[i][k]+f[k+1][j])+s[j]-s[i-1] </br>
合并[i,j]这一区间石子当前只一次操作不管怎么区分都是[i,j]区间和，导致答案不同的原因是合并区间的顺序 </br>
注意枚举时不能写 </br>
```cpp
for(int i = 1; i <= n-1; i ++ )
    for(int j = i+1; j <= n; j ++ )
```
因为假如我们要合并[1,3]，那其中一种分发是[1,1], [2,3]但是按照顺序来说我们还没有确定[2,3]的值所以要按下面的做法或者倒序也可以(如图所示) </br>
<img src = "https://github.com/BinderLeee/shuhan_algorithm_problem/blob/main/image/%E5%80%92%E5%BA%8F.png" width="370" height ="321">
如果嫌麻烦的话也可以用右边的记忆化搜索，不需要担心要使用的状态还没有确定下来。但是要注意判断边界如果要写return 0 的话要放到记忆化前面因为当[i,i]要被再次使用时，会直接返回0x3f3f3f3f 因为f[i][i]并没有被存下来。
```cpp
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
```
*记忆化搜索*
```cpp
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
```
