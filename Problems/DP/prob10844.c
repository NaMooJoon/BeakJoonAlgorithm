#include <stdio.h>

#define MOD     1000000000

 int main(void) {
    int N;
    int DP[101][10];
    long long answer = 0;

    scanf("%d", &N);
    DP[1][0] = 0;
    for(int i = 1; i < 10; i++) 
        DP[1][i] = 1;
    

    for(int i = 2; i <= N; i++){ 
        for(int j = 0; j < 10; j++) {
            if(j == 0)
                DP[i][j] = DP[i-1][1];
            else if(j == 9) 
                DP[i][j] = DP[i-1][8];
            else
                DP[i][j] = DP[i-1][j-1] + DP[i-1][j+1];
            DP[i][j] %= MOD;
        }
    }
    

    for(int i = 0; i < 10; i++) 
        answer += DP[N][i];

    printf("%lld\n", answer % MOD);


     return 0;
 }