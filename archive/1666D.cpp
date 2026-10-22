#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()
#define fore(i, end) for (int i = 0; i < end; i++)
#define forse(i, start, end) for (int i = start; i < end; i++)

void solve()
{
    string s, t;
    cin >> s >> t;
    vector<int> nado(26, 0);
    for (auto &i : t)
        nado[i - 'A']++;
    string res = "";
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (nado[s[i] - 'A'] > 0)
        {
            res += s[i];
            nado[s[i] - 'A']--;
        }
    }

    reverse(all(res));
    if (res == t)
        cout << "YES\n";
    else
        cout << "NO\n";
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
