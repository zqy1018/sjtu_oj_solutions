/*
    Hint: use monotonic stack
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
pair<int, int> pp[100005];
int n, a[100005], ans[100005] = {0}, pos[100005];
void init(){
    n = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read(), pp[i].first = a[i], pp[i].second = i;
    sort(pp + 1, pp + n + 1);
    for (int i = 1; i <= n; ++i)
        pos[pp[i].second] = i;
}
void solve(){
    int cur = n;
    for (int i = n; i >= 1; --i){
        while(cur >= 1 && pp[cur].first > a[i]){
            if(pp[cur].second < i)
                ans[pp[cur].second] = i;
            cur--;
        }
        if(cur < 1) break;
    }
    for (int i = 1; i <= n; ++i)
        printf("%d ", ans[i] ? ans[i] - i - 1: -1);
}
int main(){
    init();
    solve();
    return 0;
}