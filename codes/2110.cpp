/*
    Hint: meet in the middle
*/
#include <bits/stdc++.h>
#define INF 2000000000
using namespace std;
typedef long long ll;
int read(){
    int f = 1, x = 0;
    char c = getchar();
    while(c < '0' || c > '9'){if(c == '-') f = -f; c = getchar();}
    while(c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
    return f * x; 
}
int a[10], lim;
unordered_map<int, int> mp;
inline int cub(int x){
    return x * x * x;
}
void init(){
    for (int i = 1; i <= 5; ++i)
        a[i] = read();
    lim = read();
    for (int i = -lim; i <= lim; ++i){
        if (!i) continue;
        int r1 = a[1] * cub(i);
        for (int j = -lim; j <= lim; ++j){
            if (!j) continue;
            int r2 = a[2] * cub(j);
            for (int k = -lim; k <= lim; ++k){
                if (!k) continue;
                int r3 = a[3] * cub(k);
                if (!mp.count(r1 + r2 + r3))
                    mp[r1 + r2 + r3] = 0;
                ++mp[r1 + r2 + r3];
            }
        }
    }
}
void solve(){
    ll ans = 0;
    for (int i = -lim; i <= lim; ++i){
        if (!i) continue;
        int r1 = -a[4] * cub(i);
        for (int j = -lim; j <= lim; ++j){
            if (!j) continue;
            int r2 = -a[5] * cub(j);
            if (mp.count(r1 + r2))
                ans += mp[r1 + r2];
        }
    }
    printf("%lld\n", ans);
}
int main(){
    init();
    solve();
    return 0;
}