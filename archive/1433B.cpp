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
    vector<int> a(n);
    int res = 0;
    int l = -1, r = -1;
    fore(i, n)
    {
        cin >> a[i];
        if (a[i])
        {
            if (l == -1)
                l = i;
            r = i;
        }
    }
    if (l == -1 || l == r)
    {
        cout << "0\n";
        return;
    }
    for (int i = l + 1; i < r; i++)
        res += !a[i];
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
