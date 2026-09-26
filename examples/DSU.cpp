#include <bits/stdc++.h>
using namespace std;

#define int long long

struct DSU
{
    vector<int> parents;

    DSU(int s)
    {
        parents.resize(s);
        for (int i = 0; i < s; i++)
            parents[i] = i;
    }

    int get(int x)
    {
        return parents[x] = (x == parents[x] ? x : get(parents[x]));
    }

    void unite(int l, int r)
    {
        int par_l = get(l), par_r = get(r);
        if (par_l != par_r)
            parents[par_l] = par_r;
    }
};

void solve()
{
    // code
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
