#include <iostream>
#include <cstdio>
#include <vector>
#include <map>

#define pb push_back

using namespace std;

const int MAXN = 1000;

pair<int, int> c[MAXN];
int N, g[MAXN][MAXN] = {};

int dpul[MAXN + 2][MAXN + 2] = {}, dpll[MAXN + 2][MAXN + 2] = {}, dplr[MAXN + 2][MAXN + 2] = {}, dpur[MAXN + 2][MAXN + 2] = {};

void compress()
{
    map<int, vector<int>> x, y;

    for (int i = 0; i < N; ++i)
    {
        if (x.find(c[i].first) == x.end())
        {
            x[c[i].first] = vector<int>();
        }

        if (y.find(c[i].second) == y.end())
        {
            y[c[i].second] = vector<int>();
        }

        x[c[i].first].pb(i);
        y[c[i].second].pb(i);
    }

    int xi = 1, yi = 1;

    for (auto i : x)
    {
        for (auto j : i.second)
        {
            c[j].first = xi;
        }
        
        ++xi;
    }

    for (auto i : y)
    {
        for (auto j : i.second)
        {
            c[j].second = yi;
        }
        
        ++yi;
    }

    for (int i = 0; i < N; ++i)
    {
        ++g[c[i].first][c[i].second];
    }
}

int main()
{
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        scanf("%i + %ii", &c[i].first, &c[i].second);
    }

    compress();

    for (int i = 1; i <= N; ++i)
    {
        int cur = 0;
        for (int j = 1; j <= N; ++j)
        {
            cur += g[i][j];
            dpul[i][j] = dpul[i - 1][j] + cur;
        }
    }

    for (int i = N; i >= 1; --i)
    {
        int cur = 0;
        for (int j = 1; j <= N; ++j)
        {
            cur += g[i][j];
            dpll[i][j] = dpll[i + 1][j] + cur;
        }
    }

    for (int i = N; i >= 1; --i)
    {
        int cur = 0;
        for (int j = N; j >= 1; --j)
        {
            cur += g[i][j];
            dplr[i][j] = dplr[i + 1][j] + cur;
        }
    }

    for (int i = 1; i <= N; ++i)
    {
        int cur = 0;
        for (int j = N; j >= 1; --j)
        {
            cur += g[i][j];
            dpur[i][j] = dpur[i - 1][j] + cur;
        }
    }

    int ans = N;
    for (int i = 1; i <= N - 1; ++i)
    {
        for (int j = 1; j <= N - 1; ++j)
        {
            ans = min(ans, max(max(dpul[i][j], dpur[i][j + 1]), max(dpll[i + 1][j], dplr[i + 1][j + 1])));
        }
    }

    cout << ans << endl;
}