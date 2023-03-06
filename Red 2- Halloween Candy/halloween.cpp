#include <iostream>

using namespace std;

const int MAXP = 5000000;

int P, A, B, dp[MAXP + 1] = {}, ans = 0;
bool c[MAXP + 1] = {};

int main()
{
    // freopen("in.txt", "r", stdin);

    cin >> P >> A >> B;

    for (int i = P; i >= 0; --i)
    {
        dp[i] = i;

        if (i + A <= P)
        {
            dp[i] = max(dp[i], dp[i + A]);
        }
        
        if (i + B <= P)
        {
            dp[i] = max(dp[i], dp[i + B]);
        }
    }

    c[0] = true;
    for (int i = 0; i <= P; ++i)
    {
        if (c[i])
        {
            if (i + A <= P) c[i + A] = true;
            if (i + B <= P) c[i + B] = true;
        }
    }

    for (int i = 0; i < P; ++i)
    {
        if (c[i])
        {
            ans = max(ans, i);
            ans = max(ans, dp[i / 2]);
        }
    }

    cout << ans << endl;
}