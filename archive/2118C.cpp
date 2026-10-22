#include <bits/stdc++.h>
using namespace std;

#define int long long
#define uint unsigned long long
#define all(a) a.begin(), a.end()
#define fore(i, end) for (int i = 0; i < end; i++)
#define forse(i, start, end) for (int i = start; i < end; i++)

void solve()
{
    int n, res = 0;
    uint k;
    cin >> n >> k;
    vector<uint> a(n);
    for (auto &i : a)
        cin >> i;
    for (uint i = 0; i <= 60 && k > 0; i++)
    {
        for (auto &j : a)
        {
            if (k >= (1ULL << i) && (j & (1ULL << i)) == 0)
            {
                k -= (1ULL << i);
                j |= (1ULL << i);
            }
        }
    }
    for (auto &i : a)
        res += popcount(i);

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
