#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

typedef long long ll;

const int MAXN = 150;

struct Entry
{
    int id, be, ee;

    Entry(int a, int b, int c) : id(a), be(b), ee(c)
    {

    }

    bool operator<(const Entry& other) const
    {
        if (id == other.id)
        {
            if (be == other.be)
            {
                return ee < other.ee;
            }
            else
            {
                return be < other.be;
            }
        }
        else
        {
            return id < other.id;
        }
    }
};

int N;
pair<int, int> task[MAXN + 1];
map<Entry, int> dp;

int sol(int id, int be, int ee)
{
    if (id > N || (be > task[N].first && ee > task[N].first))
    {
        return 0;
    }

    auto val = dp.find(Entry(id, be, ee));

    if (val != dp.end())
    {
        return val->second;
    }

    int ans = 0;

    if (be <= task[id].first)
    {
        ans = max(ans, sol(id + 1, task[id].second, ee) + 1);
    }
    else if (ee <= task[id].first)
    {
        ans = max(ans, sol(id + 1, be, task[id].second) + 1);
    }

    ans = max(ans, sol(id + 1, be, ee));

    dp[Entry(id, be, ee)] = ans;
    return ans;
}

int main()
{
    // freopen("in.txt", "r", stdin);

    cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        cin >> task[i].first >> task[i].second;
    }

    sort(task + 1, task + N + 1);

    cout << sol(1, 0, 0) << endl;
}
