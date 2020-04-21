#include <bits/stdc++.h>
using namespace std;
int a[105], n, g[105];
int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    memset(g, 0x3f, sizeof(g));
    g[n] = 0;
    for(int i = n; i >= 3; --i){
        g[i - 2] = min(g[i - 2], g[i] + 2 * a[2] + a[1] + a[i]);
        g[i - 1] = min(g[i - 1], g[i] + a[1] + a[i]);
    }
    g[0] = min(g[2] + a[2], g[1] + a[1]);
    cout << g[0] << endl;
    return 0;
}