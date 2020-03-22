#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, v[100005], r[100005], cnt[100005] = {0};
ll sum[100005], res[100005] = {0};
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &v[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &r[i]), sum[i] = sum[i - 1] + 1ll * r[i];
    for (int i = 1; i <= n; ++i){
        int dd = upper_bound(sum + 1, sum + n + 1, sum[i - 1] + v[i]) - sum;
        cnt[i]++, cnt[dd]--;
        res[dd] += (1ll * v[i] - sum[dd - 1] + sum[i - 1]);
    }
    int ss = 0;
    for (int i = 1; i < n; ++i){
        ss += cnt[i];
        printf("%lld ", 1ll * ss * r[i] + res[i]);
    }
    ss += cnt[n];
    printf("%lld\n", 1ll * ss * r[n] + res[n]);
    return 0;
}