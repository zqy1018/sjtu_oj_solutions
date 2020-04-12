/*
    Hint: try brute force
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
int n, a[100005], lis[100005], tot;
ll c[100005] = {0};
set<int> st;
inline int lowbit(int x){
    return x & (-x);
}
void add(int r, int k){
    while (r <= n)
        c[r] += k, r += lowbit(r);
}
ll query(int r){
    ll res = 0;
    while (r > 0)
        res += c[r], r -= lowbit(r);
    return res;
}
int calc(int x){
    int res = 1;
    while (x > 0)   
        res *= (x % 10 + 1), x /= 10;
    --res;
    return res;
}
void init(){
    n = read();
    for (int i = 1; i <= n; ++i){
        a[i] = read();
        add(i, a[i]);
        if (calc(a[i]) != a[i]) st.insert(i);
    }
}
void solve(){
    int q = read();
    while (q--){
        int opt = read(), x = read(), y = read();
        if (opt == 0){
            tot = 0;
            auto iter = st.lower_bound(x);
            while (iter != st.end()){
                if (*iter > y) break;
                int pos = *iter, t = a[pos];
                int to = calc(t);
                if (t == to) lis[++tot] = pos;
                else add(pos, to - t), a[pos] = to;
                ++iter;
            }
            for (int i = 1; i <= tot; ++i)
                st.erase(lis[i]);
        }else {
            printf("%lld\n", query(y) - query(x - 1));
        }
    }
}
int main(){
    init();
    solve();
    return 0;
}