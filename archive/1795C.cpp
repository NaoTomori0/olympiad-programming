#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()
#define fread(filename) freopen(filename, "r", stdin);
#define fwrite(filename) freopen(filename, "w", stdout);

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n), pref(n + 1, 0), cnt(n + 1, 0), add(n + 1, 0);
    for (auto &i : a)
        cin >> i;
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        pref[i + 1] = pref[i] + b[i];
    }

    for (int i = 0; i < n; i++)
    {
        int j = upper_bound(all(pref), a[i] + pref[i]) - pref.begin() - 1;
        cnt[i]++;
        cnt[j]--;
        add[j] += a[i] - (pref[j] - pref[i]);
    }
    int cur = 0;
    for (int i = 0; i < n; i++)
    {
        cout << cnt[i] * b[i] + add[i] << ' ';
        cnt[i + 1] += cnt[i];
    }
    cout << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
