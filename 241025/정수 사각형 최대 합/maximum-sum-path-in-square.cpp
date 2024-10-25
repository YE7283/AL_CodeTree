#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 100

// 1, 1에서 시작 => N, N으로 간다
// 오른쪽, 아래 로만 이동
// 이동하는 경로에 있는 숫자의 합의 최댓값을 구해라
int N;
int MAP[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];

void InitDP()
{
    // 0, 0 에서 시작
    dp[0][0] = MAP[0][0];

    // 0번째 열은 무조건 위에서만 올 수 있음
    for(int i = 1; i < N; ++i)
    {
        dp[i][0] = dp[i - 1][0] + MAP[i][0];
    }

    // 0번째 행은 무조건 왼쪽에서만 올 수 있음
    for(int i = 1; i < N; ++i)
    {
        dp[0][i] = dp[0][i - 1] + MAP[0][i];
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

    InitDP();

    for(int i = 1; i < N; ++i)
    {
        for(int j = 1; j < N; ++j)
        {
            dp[i][j] = max(dp[i - 1][j] + MAP[i][j], dp[i][j - 1] + MAP[i][j]);
        }
    }

    // N-1, N-1 의 최댓값
    cout << dp[N - 1][N - 1];

    return 0;
}