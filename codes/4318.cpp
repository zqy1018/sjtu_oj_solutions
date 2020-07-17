#include <bits/stdc++.h>
#define REP(temp, init_val, end_val) for (int temp = init_val; temp <= end_val; ++temp)
using namespace std;
typedef long long ll;
int read(){
    int f = 1, x = 0;
    char c = getchar();
    while (c < '0' || c > '9'){if(c == '-') f = -f; c = getchar();}
    while (c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
    return f * x; 
}
int n, a[1000005], maxi;
void init(){
    n = read();
    maxi = 0;
    REP(i, 1, n)
        a[i] = read(), maxi = max(maxi, a[i]);
}
ll get(int x){
    ll mini = 0;
    ll ans = -10000000000000000ll, sm = 0;
    REP(i, 1, n){
        sm += a[i] - x;
        ans = max(ans, sm - mini);
        mini = min(mini, sm);
    }
    return ans;
}
void solve(){
    int l = 0, r = maxi;
    while (r > l){
        int mid = (r + l + 1) >> 1;
        if (get(mid) >= 0ll)
            l = mid;
        else r = mid - 1;
    }
    printf("%d\n", l);
}
int main(){
    init();
    solve();
    return 0;
}