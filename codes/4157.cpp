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
double h1;
ll a[1005], b[1005], c[1005];
void init(){
    n = read();
    cin >> h1;
    a[1] = c[1] = 0, b[1] = 1;
    a[2] = 1, b[2] = c[2] = 0;
}
void solve(){
    double h2 = 0;
    for (int i = 3; i <= n; ++i){
        a[i] = 2 * a[i - 1] - a[i - 2], 
        b[i] = 2 * b[i - 1] - b[i - 2], 
        c[i] = 2 * c[i - 1] - c[i - 2] + 2;
        h2 = max(h2, (-b[i] * h1 - c[i]) / a[i]);
    }
    double res = a[n] * h2 + b[n] * h1 + c[n];
    printf("%.2lf\n", res);                     // warning
}
int main(){
    init();
    solve();
    return 0;
}