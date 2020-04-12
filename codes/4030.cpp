#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    if (!n) {
        printf("%.6lf\n", 0.0);
        return 0;
    }
    double sum1 = 0, sum2 = 0, ans = 0, lst = 0;
    for (int i = 1; i <= n; ++i){
        double p;
        scanf("%lf", &p);
        sum1 += 2 * sum2, sum1 += (1 - lst), sum1 *= p;
        ans += sum1;
        sum2 += (1 - lst), sum2 *= p;
        lst = p;
    }
    printf("%.6lf\n", ans);
    return 0;
}