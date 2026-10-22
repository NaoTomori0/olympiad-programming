#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()
#define fore(i, end) for (int i = 0; i < end; i++)
#define forse(i, start, end) for (int i = start; i < end; i++)

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), valid_a;
    fore(i, n)
    {
        cin >> a[i];
        if (a[i] < i + 1)
            valid_a.push_back(i + 1);
    }

    int res = 0;
    for (int j = 0; j < valid_a.size(); j++)
    {
        auto it = lower_bound(all(valid_a), a[valid_a[j] - 1]);
        res += (it - valid_a.begin());
    }
    cout << res << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

// #include <algorithm>
// #include <iostream>
// #include <vector>

// using namespace std;

// struct SegmentTree
// {
//     int n;
//     vector<int> tree;

//     SegmentTree(int size)
//     {
//         n = size;
//         tree.assign(4 * n, 0);
//     }

//     void update(int node, int l, int r, int idx, int val)
//     {
//         if (l == r)
//         {
//             tree[node] += val;
//             return;
//         }
//         int mid = (l + r) / 2;
//         if (idx <= mid)
//             update(2 * node, l, mid, idx, val);
//         else
//             update(2 * node + 1, mid + 1, r, idx, val);
//         tree[node] = tree[2 * node] + tree[2 * node + 1];
//     }

//     int query(int node, int l, int r, int ql, int qr)
//     {
//         if (ql > r || qr < l)
//             return 0;
//         if (ql <= l && r <= qr)
//             return tree[node];
//         int mid = (l + r) / 2;
//         return query(2 * node, l, mid, ql, qr) +
//                query(2 * node + 1, mid + 1, r, ql, qr);
//     }

//     void update(int idx, int val) { update(1, 1, n, idx, val); }

//     int query(int l, int r)
//     {
//         if (l > r)
//             return 0;
//         return query(1, 1, n, l, r);
//     }
// };

// void solve()
// {
//     int n;
//     cin >> n;
//     vector<int> a(n + 1);
//     for (int i = 1; i <= n; ++i)
//     {
//         cin >> a[i];
//     }

//     SegmentTree st(n);
//     long long ans = 0;

//     for (int j = 1; j <= n; ++j)
//     {
//         if (a[j] < j)
//         {
//             int limit = min(a[j] - 1, n);
//             if (limit >= 1)
//             {
//                 ans += st.query(1, limit);
//             }
//             st.update(j, 1);
//         }
//     }

//     cout << ans << "\n";
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin >> t;
//     while (t--)
//     {
//         solve();
//     }

//     return 0;
// }
