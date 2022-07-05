#include<bits/stdc++.h>
using namespace std;

const int N = 110;
int n;
struct node{
    int a, b, c;
    bool operator < (const node &x) const{
        if(a == x.a) return b < x.b;
        else return a < x.a;
    }
}pt[N];
int g[N][N];
bool vis[N];
int f[N];

void build(){
    int tot = 3*n;
    sort(pt, pt+tot);

    for(int i = 0; i < tot; i ++ )
        for(int j = i + 1; j < tot; j ++ )
            if(pt[i].a < pt[j].a && pt[i].b < pt[j].b)
                g[i][j] = 1;
}

int dp(int i){
    if(vis[i]) return f[i];
    vis[i] = 1;
    
    for(int j = 0; j < 3*n; j ++ )
        if(g[i][j])
            f[i] = max(f[i], dp(j));
    f[i] += pt[i].c;
    return f[i];
}

int solve(){
    memset(g, 0, sizeof g);
    memset(f, 0, sizeof f);
    memset(vis, 0, sizeof vis);
    
    for(int i = 0; i < n; i ++ ){
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        pt[i*3].a=(a>b?b:a); pt[i*3].b=(a>b?a:b); pt[i*3].c=c; 
        pt[i*3+1].a=(a>c?c:a); pt[i*3+1].b=(a>c?a:c); pt[i*3+1].c=b;
        pt[i*3+2].a=(b>c?c:b); pt[i*3+2].b=(b>c?b:c); pt[i*3+2].c=a;
    }

    build();
    
    int ans = 0;
    for(int i = 0; i < 3*n; i ++ )
        ans = max(ans, dp(i));
        
    return ans;
}

int main(){
    int cases = 0;
    while(scanf("%d", &n)==1 && n != 0){
        cases ++ ;
        printf("Case %d: maximum height = %d\n", cases, solve());
    }

    return 0;
}
