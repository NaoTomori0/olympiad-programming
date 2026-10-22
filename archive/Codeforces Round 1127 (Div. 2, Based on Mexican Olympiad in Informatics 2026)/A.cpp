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
    int ans = 0;
    int s = 1;
    fore(i, n)
    {
        int x;
        cin >> x;
        ans += s * x;
        s = -s;
    }
    cout << ans << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
