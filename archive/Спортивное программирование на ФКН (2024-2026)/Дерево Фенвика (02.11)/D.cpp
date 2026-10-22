#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define int long long
#define all(a) a.begin(), a.end()
#define fore(i, end) for (int i = 0; i < end; i++)
#define forse(i, start, end) for (int i = start; i < end; i++)
#define fread(filename) freopen(filename, "r", stdin);
#define fwrite(filename) freopen(filename, "w", stdout);

class FenwickTree
{
public:
    FenwickTree(int n, vector<int> &a)
    {
        size = n;
        tree.resize(n + 1);
    }

private:
    vector<int> tree;
    int size;

    void build(int n, vector<int> &a)
    {
        vector<int> p;
        for (int i = 0; i < n; i++)
            p[i + 1] = p[i] + a[i];
        for (int i = 1; i <= n; i++)
            tree[i] = p[i] + p[i - (i & -i)];
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
}

int32_t main()
{
    fastio;

    solve();
    return 0;
}
