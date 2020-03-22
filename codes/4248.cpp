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
int n;
pair<int, int> a[100005], b[100005];
int lst[100005], tot = 0;
void init(){
    n = read();
    for (int i = 1; i <= n; ++i)
        a[i].first = -read(), a[i].second = i;
    for (int i = 1; i <= n; ++i)
        b[i].first = read(), b[i].second = i;
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; ++i){
        if (a[i].first != a[1].first)   
            break;
        lst[++tot] = a[i].second;
    }
}
void solve(){
    int ans = n + 1, cur = 1;
    lst[0] = 0, lst[tot + 1] = n + 1;
    for (int i = 1; i <= n; ++i){
        if (b[i].first != b[1].first)   
            break;
        while (b[i].second > lst[cur])
            ++cur;
        if (cur - 1 != 0) ans = min(ans, b[i].second - lst[cur - 1]);
        if (cur != tot + 1) ans = min(ans, lst[cur] - b[i].second);
    }
    printf("%d\n", ans + 1);
}
int main(){
    init();
    solve();
    return 0;
}