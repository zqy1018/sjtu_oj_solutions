#include <bits/stdc++.h>
#define INF 2000000000
#define M 19301
using namespace std;
typedef long long ll;
int read(){
    int f = 1, x = 0;
    char c = getchar();
    while(c < '0' || c > '9'){if(c == '-') f = -f; c = getchar();}
    while(c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
    return f * x; 
}
int n, f[3335][2000] = {0};
void init(){
    cin >> n;
}
void solve(){
    f[0][0] = 1;
    int hf = (n >> 1);
    for (int i = 1; i <= n; ++i){
        f[i][0] = (f[i - 1][0] + f[i - 1][1]) % M;
        for (int j = 1; j < hf; ++j)
            f[i][j] = (f[i - 1][j - 1] + f[i - 1][j] + f[i - 1][j + 1]) % M;
        f[i][hf] = (f[i - 1][hf - 1] + f[i - 1][hf]) % M;
    }
    cout << f[n][0] << endl;
}
int main(){
    init();
    solve();
    return 0;
}