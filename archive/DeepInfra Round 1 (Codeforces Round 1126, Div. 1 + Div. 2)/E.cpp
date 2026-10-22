#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()
#define fore(i, end) for (int i = 0; i < end; i++)
#define forse(i, start, end) for (int i = start; i < end; i++)

void solve()
{
    int n, k;
    cin >> n >> k;
    if (k < 0)
    {
        cout << -1 << '\n';
        return;
    }
    vector<int> a(n);
    fore(i, n) cin >> a[i];
    sort(all(a));

    int res = 0;
    vector<int> q;
    int i = 0;

    while (i < n || !q.empty())
    {
        if (!q.empty() && q.back() <= k)
        {
            res++;
            k++;
            q.pop_back();
        }
        else if (i < n && a[i] <= k)
        {
            res++;
            k++;
            i++;
        }
        else
        {
            res++;
            k++;
            int cur;
            if (i < n && (q.empty() || a[i] < q.back()))
            {
                cur = a[i];
                i++;
            }
            else
            {
                cur = q.back();
                q.pop_back();
            }
            int nxt = (cur + 1) / 2;
            q.push_back(nxt);
            q.push_back(nxt);
        }
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
