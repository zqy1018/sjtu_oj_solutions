#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int read(){
    int f = 1, x = 0;
    char c = getchar();
    while (c < '0' || c > '9'){if(c == '-') f = -f; c = getchar();}
    while (c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
    return f * x; 
}
int n, m, w, a[100005];
int b[100005], mini, maxi;
void init(){
    n = read(), m = read(), w = read();
    mini = 1000000005, maxi = -1;
    for (int i = 1; i <= n; ++i)
        a[i] = read(), mini = min(mini, a[i]), maxi = max(maxi, a[i]);
}
ll get(int x){
    memset(b, 0, sizeof(b));
    ll cnt = 0, cur = 0;
    for (int i = 1; i <= n; ++i){
        cur += b[i];
        int delta = max(0, x - a[i]);
        if (cur < delta)
            b[i] += delta - cur, b[min(i + w, n + 1)] -= delta - cur, 
            cnt += delta - cur, cur = delta;
    }
    return cnt;
}
void solve(){
    int l = mini, r = maxi + m;
    while (r > l){
        int mid = (l + r + 1) >> 1;
        if (get(mid) <= 1ll * m) l = mid;
        else r = mid - 1;
    } 
    printf("%d\n", l);
}
int main(){
    init();
    solve();
    return 0;
}