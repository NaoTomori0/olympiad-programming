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
    vector<char> c(51, '#');
    for (auto &i : a)
        cin >> i;
    string s;
    cin >> s;
    fore(i, n)
    {
        if (c[a[i]] == '#')
            c[a[i]] = s[i];
        else if (c[a[i]] != s[i])
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
