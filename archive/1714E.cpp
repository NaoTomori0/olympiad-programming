#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    bool f1 = false;
    for (auto &i : a)
    {
        cin >> i;
        if (i % 5 == 0)
        {
            i = i + (i % 10);
            f1 = 1;
        }
    }
    if (f1)
        cout << (*max_element(a.begin(), a.end()) == *min_element(a.begin(), a.end()) ? "YES\n" : "NO\n");
    else
    {
        bool f2 = 0, f12 = 0;
        for (auto &i : a)
        {
            while (i % 10 != 2)
                i = i + (i % 10);
            if (!f2)
                f2 = i % 20 == 2;
            if (!f12)
                f12 = i % 20 == 12;
        }
        cout << (f2 && f12 ? "NO\n" : "YES\n");
    }
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
