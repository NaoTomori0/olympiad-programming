#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()
#define fore(i, end) for (int i = 0; i < end; i++)
#define forse(i, start, end) for (int i = start; i < end; i++)

void solve()
{
    map<int, int> m;
    int n;
    cin >> n;
    vector<int> a(n), trippoint;
    int res = 0;
    for (auto &i : a)
        cin >> i;
    for (int i = 0; i < n - 4; i++)
        trippoint.push_back(a[i] + a[i + 2] - a[i + 4]);

    for (int i = 0; i < n - 4; i++)
    {
        int norm = i - 5;
        if (norm >= 0)
            m[trippoint[norm]]++;
        // if (m[trippoint[i]])
        res += m[trippoint[i]];
        if (i - 1 >= 0 && trippoint[i - 1] == trippoint[i])
            res++;
        if (i - 3 >= 0 && trippoint[i - 3] == trippoint[i])
            res++;
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
