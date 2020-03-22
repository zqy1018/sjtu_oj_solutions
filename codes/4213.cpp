/*
    Hint: use Fenwick tree after discretization
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
int n, a[300005] = {0}, b[300005];
ll ans = 0;
int c[300005] = {0};
inline int lowbit(int x){
    return x & (-x);
}
void add(int r, int v){
    while(r <= n)
        c[r] += v, r += lowbit(r);
}
int query(int r){
    int res = 0;
    while(r)
        res += c[r], r -= lowbit(r);
    return res;
}
void init(){
    n = read();
    for (int i = 1; i <= n; ++i)
        a[i] = b[i] = read();
    sort(b + 1, b + n + 1);
}
void solve(){
    for (int i = n; i >= 1; --i){
        int id = lower_bound(b + 1, b + n + 1, a[i]) - b;
        ans += query(id - 1);
        add(id, 1);
    }
    printf("%lld\n", ans);
}
int main(){
    init();
    solve();
    return 0;
}