#include <iostream>
#include <fstream>

using namespace std;

int N, M, K, dp[100001] = {};

int main()
{
    cin >> N >> M >> K;

    for (int i = 0; i <= M; ++i)
    {
        dp[i] = i + 1;
    }

    for (int i = M + 1; i <= N; ++i)
    {
        dp[i] = (dp[i - 1] + dp[i - M - 1]) % 1000000007;
    }

    cout << dp[N] << endl;
}