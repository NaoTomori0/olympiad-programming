#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), cnt(n + 1, 0);
    for (auto &i : a)
    {
        cin >> i;
        cnt[i]++;
    }

    sort(cnt.rbegin(), cnt.rend());

    int res = cnt[0];
    for (int i = 1; cnt[i - 1] > 0; i++)
    {
        if (cnt[i] >= cnt[i - 1])
            res += (cnt[i] = cnt[i - 1] - 1);
        else
            res += cnt[i];
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
