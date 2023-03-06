#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

class Cow
{
    public:
        int x, id;

        Cow(int x_ = 0, int id_ = 0) : x(x_), id(id_) {}

        bool operator<(const Cow& b)
        {
            return x < b.x;
        }
};

int N, idCount, l = 0, r = 0, minSize = INT_MAX;
Cow cows[50000];

unordered_set<int> ids;
unordered_map<int, int> counts;

int main()
{
    // freopen("in.txt", "r", stdin);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int a, b; cin >> a >> b;
        cows[i] = Cow(a, b);

        ids.insert(b);
    }
    sort(cows, cows + N);

    idCount = ids.size();
    counts[cows[0].id] = 1;

    for (int i = 0; i < N; ++i)
    {
        l = i;

        while (r < N && counts.size() < idCount)
        {
            ++r;

            if (counts.find(cows[r].id) == counts.end())
            {
                counts[cows[r].id] = 0;
            }

            ++counts[cows[r].id];
        }

        if (r == N)
        {
            break;
        }

        minSize = min(minSize, cows[r].x - cows[l].x);

        --counts[cows[l].id];
        if (counts[cows[l].id] == 0)
        {
            counts.erase(cows[l].id);
        }
    }

    cout << minSize << endl;
}