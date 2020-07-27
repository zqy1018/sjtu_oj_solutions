#include <cstdio>
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
int n, m;
int a[1005], b[1005];
void init(){
    n = read(), m = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    for (int i = 1; i <= m; ++i)    
        b[i] = read();
}
void solve(){
    for (int i = 1; i <= n; ++i)    {
        bool flag = true;
        for (int j = 1; j <= m; ++j){
            if (i + j - 1 > n || a[i + j - 1] != b[j]) {
                flag = false;
                break;
            }
        }
        if (!flag) printf("%d ", a[i]);
        else i += m - 1;
    }
}
int main(){
    init();
    solve();
    return 0;
}