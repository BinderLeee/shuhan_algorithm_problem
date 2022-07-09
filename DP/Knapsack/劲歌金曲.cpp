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
