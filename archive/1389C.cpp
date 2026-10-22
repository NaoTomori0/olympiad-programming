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

int f(string s, int a, int b)
{
    int res = 0;
    for (auto &c : s)
    {
        if (c - '0' == a)
        {
            swap(a, b);
            res++;
        }
    }
    res -= (a != b && res % 2 != 0);
    return res;
}

void solve()
{
    string s;
    cin >> s;
    int maxln = 0;
    for (int a = 0; a < 10; a++)
        for (int b = 0; b < 10; b++)
            maxln = max(maxln, f(s, a, b));
    cout << s.size() - maxln << '\n';
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
