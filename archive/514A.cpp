#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()
#define fore(i, end) for (int i = 0; i < end; i++)
#define forse(i, start, end) for (int i = start; i < end; i++)

void solve()
{
    string s, res;
    cin >> s;
    res = s;
    fore(i, s.size())
    {
        if (s[i] - '0' >= 5)
        {
            if (s[i] - '0' == 9 && i == 0)
                continue;
            else
                res[i] = (char)(9 - (s[i] - '0') + '0');
        }
    }
    cout << res;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
