/*
    Hint: use sparse table
*/
#include <bits/stdc++.h>
using namespace std;
int n, m, logg;
int f[200005][20], a[200005];
void build_ST(){
    for(int i = 1; i <= n; ++i)
        f[i][0] = a[i];
    logg = 1;
    while((1 << logg) < n) logg++;
    for(int i = 1; i < logg; ++i){
        int p = (1 << i);
        for(int j = 1; j + p - 1 <= n; ++j)
            f[j][i] = max(f[j][i - 1], f[j + (p >> 1)][i - 1]);
    }
    f[1][logg] = max(f[1][logg - 1], f[1 << (logg - 1)][logg - 1]);
}
int getLog(int x){
    if(x <= 2) return 0;
    if(x <= 4) return 1;
    if(x <= 8) return 2;
    if(x <= 16) return 3;
    if(x <= 32) return 4;
    if(x <= 64) return 5;
    if(x <= 128) return 6;
    if(x <= 256) return 7;
    if(x <= 512) return 8;
    if(x <= 1024) return 9;
    if(x <= 2048) return 10;
    if(x <= 4096) return 11;
    if(x <= 8192) return 12;
    if(x <= 16384) return 13;
    if(x <= 32768) return 14;
    if(x <= 65536) return 15;
    if(x <= 131072) return 16;
}
int query(int l, int r){
    int od = getLog(r - l + 1);
    return max(f[l][od], f[r - (1 << od) + 1][od]);
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    build_ST();
    int l, r;
    while(m--)
        scanf("%d%d", &l, &r),
        printf("%d\n", query(l, r));
    return 0;
}