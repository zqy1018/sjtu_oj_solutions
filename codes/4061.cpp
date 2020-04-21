/*
    Hint: use extgcd
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
int a, b;
int exgcd(int a, int b, int &x, int &y) {
    if (b == 0){
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
}
void init(){
    a = read(), b = read();
}
void solve(){
    int x, y, xx, yy;
    int d = exgcd(a, b, x, y);
    if (x > 0) x -= b / d, y += a / d;
    printf("%d\n%d %d\n", d, -x, y);
}
int main(){
    init();
    solve();
    return 0;
}