/*
    Hint: use Stein algorithm
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
char s1[505], s2[505];
int ss1[2005], ss2[2005];
int tmp[2005];
int rightshift(int* num){
    int x = 0;
    for (int i = num[0]; i >= 1; --i){
        x = num[i] + 10 * x;
        num[i] = x >> 1, x %= 2;
    }
    if (num[0] > 1 && !num[num[0]]) --num[0];
    return x;
}
void mminus(int* num1, int* num2){
    int x = 0;
    for (int i = 1; i <= num2[0]; ++i){
        x = 10 + num1[i] - num2[i] + x;
        num1[i] = x % 10;
        x = x / 10 - 1;
    } 
    for (int i = num2[0] + 1; i <= num1[0]; ++i){
        x = 10 + num1[i] + x;
        num1[i] = x % 10;
        x = x / 10 - 1;
    }
    while (num1[0] > 1 && num1[num1[0]] == 0) --num1[0];
}
int cmp(int* num1, int* num2){
    if (num1[0] != num2[0]) 
        return (num1[0] < num2[0] ? -1: 1);
    for (int i = num1[0]; i >= 1; --i)
        if (num1[i] != num2[i])
            return (num1[i] < num2[i] ? -1: 1);
    return 0;
}
void output(int* num){
    for (int i = num[0]; i >= 1; --i)
        cout << num[i];
    cout << endl;
}
void stein(int* num1, int* num2, int& acc){
    bool f1 = (num1[1] % 2 == 0), f2 = (num2[1] % 2 == 0);
    // output(num1);
    // output(num2);
    if (f1 && f2){
        rightshift(num1), rightshift(num2), ++acc;
        stein(num1, num2, acc);
    }else if (!f1 && !f2){
        mminus(num1, num2);
        rightshift(num1);
        int res = cmp(num1, num2);
        if (res > 0) stein(num1, num2, acc);
        else if (res < 0) stein(num2, num1, acc);
    }else {
        if (f1) rightshift(num1);
        else rightshift(num2);
        int res = cmp(num1, num2);
        if (res > 0) stein(num1, num2, acc);
        else if (res < 0) stein(num2, num1, acc);
    }
}

void init(){
    cin >> s1 >> s2;
    int l1 = strlen(s1), l2 = strlen(s2);
    for (int i = 0; i < l1; ++i)
        ss1[i + 1] = s1[l1 - i - 1] - '0';
    for (int i = 0; i < l2; ++i)
        ss2[i + 1] = s2[l2 - i - 1] - '0';
    ss1[0] = l1, ss2[0] = l2;
    while (ss1[0] > 1 && ss1[ss1[0]] == 0) --ss1[0];
    while (ss2[0] > 1 && ss2[ss2[0]] == 0) --ss2[0];
}
void solve(){
    int acc = 0, res = cmp(ss1, ss2);
    if (res > 0) stein(ss1, ss2, acc);      // the former is larger
    else if (res < 0) stein(ss2, ss1, acc);
    
    int ans_len = 0;
    while (ss1[0] > 1 || ss1[1] != 0){
        tmp[ans_len++] = rightshift(ss1);
    }
    for (int i = ans_len - 1; i >= 0; --i)
        cout << tmp[i];
    for (int i = 0; i < acc; ++i)
        cout << '0';
    cout << endl;
}
int main(){
    init();
    solve();
    return 0;
}