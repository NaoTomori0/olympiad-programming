#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define int long long
#define all(a) a.begin(), a.end()
#define fore(i, end) for (int i = 0; i < end; i++)
#define forse(i, start, end) for (int i = start; i < end; i++)
#define fread(filename) freopen(filename, "r", stdin);
#define fwrite(filename) freopen(filename, "w", stdout);

void solve()
{
    int n;
    string s;
    cin >> n >> s;

    int fe = -1, se = -1, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            cnt++;
            if (fe == -1)
                fe = i + 1;
            se = i + 1;
        }
    }

    if (cnt == 1)
        cout << "0\n";
    else if (cnt == 2)
        cout << "1\n";
    else
        cout << se - fe << '\n';
}

int32_t main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
