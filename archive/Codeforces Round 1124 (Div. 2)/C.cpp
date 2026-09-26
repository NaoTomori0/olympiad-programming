#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int K = k - 1;
    int q = n - k + 1; // = n - K
    int ans = 0;

    if (n > 2 * K)
    {
        for (int i = K + 1; i <= n - K; i++)
        {
            ans += a[i];
        }
        for (int i = 1; i <= K; i++)
        {
            int left = K - i + 1;
            int right = n - K + i;
            ans += max(a[left], a[right]);
        }
    }
    else
    {
        for (int i = 1; i <= q; i++)
        {
            int left = K + i;
            int right = q - i + 1;
            ans += max(a[left], a[right]);
        }
    }

    cout << ans << '\n';
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