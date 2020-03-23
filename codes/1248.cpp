#include <bits/stdc++.h>
using namespace std;
char ori[12][12], now[12][12], to[12][12];
int n, tmp;
int m1(){ 
    for(int i = 0; i < n; ++i)
        for(int j = n - 1; j >= 0; --j)
            now[i][n - 1 - j] = ori[j][i];
}
int m2(){
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            now[i][j] = ori[n - 1 - i][n - 1 - j];
}
int m3(){
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            now[i][j] = ori[j][n - 1 - i];
}
int m4(){
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            now[i][j] = ori[i][n - 1 - j];
}
bool judge(){
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (now[i][j] != to[i][j])
                return false;
    return true;
}
int main(){
	scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%s", ori[i]);
    for (int i = 0; i < n; ++i)
        scanf("%s", to[i]);
	int (*fun[])() = {m1, m2, m3, m4};
	for (int i = 0; i < 6; ++i){
		if (i < 4){
			fun[i]();
            if (judge()) {
                printf("%d\n", i + 1);
                return 0;
            }
		}else if (i == 4){
            for (int k = 0; k < n; ++k)
                for (int j = 0; j < (n / 2); ++j)
                    swap(ori[k][n-j-1], ori[k][j]);
			for (int k = 0; k < 4; ++k){
				fun[k]();
				if (judge()) {
                    printf("%d\n", 5);
                    return 0;
                }
			}
            for (int k = 0; k < n; ++k)
                for (int j = 0; j < (n / 2); ++j)
                    swap(ori[k][n-j-1], ori[k][j]);
		}else {
			for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    now[i][j] = ori[i][j];
            if (judge()) {
                printf("%d\n", 6);
                return 0;
            }
		}
	}
    printf("7\n");
	return 0;  
} 