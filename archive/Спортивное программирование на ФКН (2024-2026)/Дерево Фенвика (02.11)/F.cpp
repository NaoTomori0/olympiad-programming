// #include <bits/stdc++.h>
#include <vector>
#include <iostream>

using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
// #define int long long
#define all(a) a.begin(), a.end()
#define fore(i, end) for (int i = 0; i < end; i++)
#define forse(i, start, end) for (int i = start; i < end; i++)
#define fread(filename) freopen(filename, "r", stdin);
#define fwrite(filename) freopen(filename, "w", stdout);

struct FenwickTree
{
    int n;
    vector<int> tree;
    FenwickTree(int s)
    {
        n = s;
        tree.assign(s + 1, 0);
    }

    void add(int x, int v)
    {
        for (int i = x; i <= n; i += i & -i)
            tree[i] += v;
    }

    int sum(int r)
    {
        int res = 0;
        for (int i = r; i > 0; i -= i & -i)
            res += tree[i];
        return res;
    }

    int find(int k)
    {
        int resinx = 0;
        for (int i = 1 << 20; i > 0; i >>= 1)
        {
            if (resinx + i <= n && tree[resinx + i] < k)
            {
                resinx += i;
                k -= tree[resinx];
            }
        }
        return resinx + 1;
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    FenwickTree ft(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ft.add(x, 1);
    }

    while (q--)
    {
        int k;
        cin >> k;
        int l = 0, r = n;

        if (k < 0)
        {
            ft.add(ft.find(abs(k)), -1);
        }
        else
        {
            ft.add(k, 1);
        }
    }
    if (!ft.sum(n))
    {
        cout << 0;
        return;
    }
    cout << ft.find(1);

    // int l = 0, r = n;
    // while (r > l + 1)
    // {
    //     int m = (l + r) / 2;
    //     if (ft.sum(m) >= 1)
    //         r = m;
    //     else
    //         l = m;
    // }
    // cout << r;
}

int main()
{
    fastio;

    solve();
    return 0;
}
