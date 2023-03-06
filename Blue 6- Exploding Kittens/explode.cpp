#include <iostream>

using namespace std;

int N, priv[1000], cnt[4] = {}, rng[4][2] = {}, T = 0;

int main()
{
    // freopen("in.txt", "r", stdin);

    cin >> N;
    
    for (int i = 0; i < N; ++i)
    {
        char c; cin >> c;

        switch (c)
        {
            case 'D':
                priv[i] = 1;
                break;
            case 'E':
                priv[i] = 2;
                break;
            case 'R':
                priv[i] = 3;
                break;
        }
        
        ++cnt[priv[i]];
    }

    rng[1][0] = 0;
    rng[1][1] = cnt[1];
    rng[2][0] = cnt[1];
    rng[2][1] = cnt[1] + cnt[2];
    rng[3][0] = cnt[1] + cnt[2];
    rng[3][1] = cnt[1] + cnt[2] + cnt[3];

    T = 0;

    for (int i = 1; i <= 3; ++i)
    {
        for (int j = i + 1; j <= 3; ++j)
        {
            for (int x = rng[i][0]; x < rng[i][1]; ++x)
            {
                for (int y = rng[j][0]; y < rng[j][1]; ++y)
                {
                    if (priv[x] == j && priv[y] == i)
                    {
                        swap(priv[x], priv[y]);
                        ++T;
                    }
                }
            }
        }
    }

    for (int i = 1; i <= 2; ++i)
    {
        for (int x = rng[i][0]; x < rng[i][1]; ++x)
        {
            for (int y = rng[i][1]; y < N; ++y)
            {
                if (priv[x] != i && priv[y] == i)
                {
                    swap(priv[x], priv[y]);
                    ++T;
                }
            }
        }
    }

    cout << T << endl;
}