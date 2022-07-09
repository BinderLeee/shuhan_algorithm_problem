* https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4008
* 难度：提高
* 标签：01背包
* 补充：无 </br>
每一首歌是01背包中的物品,时长是体积,价值权重是1.背包体积是总时长t. </br>
f[j]表示不超过时长为j最多能唱的歌，但是这样做有一个问题：无法确保总时长是最长的。因此f[j]改为*恰好*为时长j最多能唱的歌，这样可以维护两个限制条件。</br>
更改之后的区别就是要将f初始化为-1来表示当前时长无法到达 </br>
```cpp
#include<bits/stdc++.h>
using namespace std;

int v[55], f[10010];
int num, len;

void solve(){
    memset(f, -1, sizeof f);

    int n, t; cin >>n>>t;
    for(int i = 1; i <= n; i ++ ) scanf("%d", &v[i]);

    f[0] = 0;
    for(int i = 1; i <= n; i ++ )
        for(int j = t; j >= v[i]; j -- )
            f[j] = max(f[j], f[j-v[i]]+1);

    num = 0, len = 0;
    for(int i = t-1; i >= 0; i -- )
        if(f[i] > num){
            num = f[i];
            len = i;
        }
    len += 678;
    num += 1;
}

int main(){
    int T; cin >> T;
    for(int cases = 1; cases <= T; cases ++ ){
        solve();
        printf("Case %d: %d %d\n", cases, num, len);
    }

    return 0;
}
```
