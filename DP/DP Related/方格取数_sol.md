* https://www.acwing.com/problem/content/1029/
* 难度：提高
* 标签：Dp
* 补充：两个人同时走模型 </br>
走两遍可以转化为两个人同时从起点开始走到终点为止。设两个人的坐标为(i1,j1),(i2,j2),于是状态就可以表示为f(i1,j1,i1,j2) </br>
可以将四维状态优化为三维状态:设k是两人同时走的步数，于是j1=k-i1, j2=k-i2.于是状态就可以表示为f(k,i1,i2) </br>
f(k,i1,i2)表示两人同时走k步同时第一人在(i1,k-i1),第二人在(i2,k-i2)的所有方案中数值总和最大 </br>
状态转移有四种情况
<img src = "https://github.com/BinderLeee/shuhan_algorithm_problem/blob/main/image/1.png">
到此还有最后一个问题，如果两个人同时走到同一个格子上，我们只能加一次格子上的数值。这里我们可以直接特判(i1==i2)判断是否在同一个格子上。

```cpp
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
```
