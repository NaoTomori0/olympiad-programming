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
    FenwickTree(int n)
    {
        size = n;
        tree.assign(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, 0)));
    }

    void add(int x, int y, int z, int delta)
    {
        for (int i = x + 1; i <= size; i += i & -i)
            for (int j = y + 1; j <= size; j += j & -j)
                for (int k = z + 1; k <= size; k += k & -k)
                    tree[i][j][k] += delta;
    }
    int sum(int x1, int y1, int z1, int x2, int y2, int z2)
    {
        return (
            sum(x2, y2, z2) - sum(x1 - 1, y2, z2) - sum(x2, y1 - 1, z2) - sum(x2, y2, z1 - 1) + sum(x1 - 1, y2, z1 - 1) + sum(x1 - 1, y1 - 1, z2) + sum(x2, y1 - 1, z1 - 1) - sum(x1 - 1, y1 - 1, z1 - 1));
    }

private:
    vector<vector<vector<int>>> tree;
    int size;

    int sum(int x, int y, int z)
    {
        int res = 0;
        for (int i = x + 1; i > 0; i -= i & -i)
            for (int j = y + 1; j > 0; j -= j & -j)
                for (int k = z + 1; k > 0; k -= k & -k)
                    res += tree[i][j][k];
        return res;
    }
};

void solve()
{
    fread("stars.in");
    fwrite("stars.out");
    int n;
    cin >> n;
    FenwickTree ft(n);
    int t;
    cin >> t;
    while (t != 3)
    {
        int x, y, z;
        cin >> x >> y >> z;
        if (t == 1)
        {
            int delta;
            cin >> delta;
            ft.add(x, y, z, delta);
        }
        else
        {
            int x2, y2, z2;
            cin >> x2 >> y2 >> z2;
            cout << ft.sum(x, y, z, x2, y2, z2) << '\n';
        }
        cin >> t;
    }
}

int32_t main()
{
    fastio;

    solve();
    return 0;
}
