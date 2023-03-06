#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> adjMat[1001];
bool vis[1001] = {};
int c[1001] = {};

int dfs(int src)
{
    if (vis[src])
    {
        return 0;
    }

    vis[src] = true;

    int t = c[src];

    for (int i : adjMat[src])
    {
        t += dfs(i);
    }

    return t;
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        cin >> c[i];
    }

    for (int i = 0; i < M; ++i)
    {
        int a, b; cin >> a >> b; --a; --b;
        adjMat[a].push_back(b);
        adjMat[b].push_back(a); 
    }

    int mx = 0;
    for (int i = 0; i < N; ++i)
    {
        mx = max(mx, dfs(i));
    }

    cout << mx << endl;
}