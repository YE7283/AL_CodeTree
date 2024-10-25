#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 100

// N*N 행렬
// 1,N에서 시작 => N, 1 도착
// 왼쪽, 아래로만 이동
// 최소합을 알아내라

int N;
int MAP[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];

void init()
{
    // 1,N 에서 시작
    dp[0][N - 1] = MAP[0][N - 1];

    // 0번째 행은 왼쪽으로만 이동할 수 있음
    for(int i = N - 2; i >= 0; --i)
    {
        dp[0][i] = dp[0][i + 1] + MAP[0][i];
    }

    // N-1번째 열은 아래쪽으로만 이동할 수 있음
    for(int i = 1; i < N; ++i)
    {
        dp[i][N - 1] = dp[i - 1][N - 1] + MAP[i][N - 1];
    }
}

int main() 
{
    cin >> N;
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            cin >> MAP[i][j];
        }
    }

    init();

    for(int i = 1; i < N; ++i)
    {
        for(int j = N - 2; j >= 0; --j)
        {
            dp[i][j] = min(dp[i - 1][j] + MAP[i][j], dp[i][j + 1] + MAP[i][j]);
        }
    }

    cout << dp[N - 1][0];

    return 0;
}