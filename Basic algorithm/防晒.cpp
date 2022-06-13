#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
vector<PII> segs;
vector<int> pt;
bool st[1000010]; //表示st[j]这一瓶已经用过

bool cmp1(PII a, PII b){
    if(a.first == b.first) return a.second > b.second;
    return a.first > b.first;
}
bool cmp2(int a, int b){
    return a > b;
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i ++ ){
        int x, y; scanf("%d%d", &x, &y);
        segs.push_back({x,y});
    }
    for(int i = 0; i < m; i ++ ){
        int x,y; scanf("%d%d", &x, &y);
        for(int j = 0; j < y; j ++ ) pt.push_back(x);
    }

    sort(segs.begin(), segs.end(), cmp1);
    sort(pt.begin(), pt.end(), cmp2);

    long long ans = 0;
    for(int i = 0; i < n; i ++ )
        for(int j = 0; j < pt.size(); j ++ )
            if(pt[j]>=segs[i].first && pt[j]<=segs[i].second && !st[j]){
                ans ++ ;
                st[j] = 1;
                break;
            }

    cout << ans << endl;

    return 0;
}