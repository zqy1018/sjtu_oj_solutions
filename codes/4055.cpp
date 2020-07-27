/*
    Hint: use greedy algorithm
*/
#include <bits/stdc++.h>
#define REP(temp, init_val, end_val) for (int temp = init_val; temp <= end_val; ++temp)
#define REPR(temp, init_val, end_val) for (int temp = init_val; temp >= end_val; --temp)
using namespace std;
typedef long long ll;
int read(){
    int f = 1, x = 0;
    char c = getchar();
    while (c < '0' || c > '9'){if(c == '-') f = -f; c = getchar();}
    while (c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
    return f * x; 
}
int n;
ll a[55];
priority_queue<ll> pq;
void init(){
    n = read();
    while (!pq.empty()) pq.pop();
    REP(i, 1, n)
        scanf("%lld", &a[i]), pq.push(a[i]);
}
void solve(){
    ll ans = 0;
    for (; ; ){
        ll tp = pq.top();
        pq.pop();
        if (tp + ans < 1ll * n) break;
        ll t = (tp + ans) / n;
        ans += t;
        tp -= t * (n + 1);
        pq.push(tp);
    }
    printf("%lld\n", ans);
}
int main(){
    int T = read();
    while (T--){
        init();
        solve();
    }
    return 0;
}