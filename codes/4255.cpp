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
int n, b[105], a[105];
void init(){
    n = read();
    for (int i = 1; i < n; ++i)
        b[i] = read();
    a[1] = a[2] = b[1];
}
void solve(){
    for (int i = 2; i < n; ++i){
        a[i + 1] = b[i];
        if (b[i] < b[i - 1])
            a[i] = b[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += a[i];
    printf("%d\n", ans);
}
int main(){
    init();
    solve();
    return 0;
}
