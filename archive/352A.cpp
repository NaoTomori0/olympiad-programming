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
    int cnt5 = 0, cnt0 = 0;
    fore(i, n)
    {
        int x;
        cin >> x;
        cnt5 += x == 5;
        cnt0 += x != 5;
    }

    if (!cnt0)
    {
        cout << "-1\n";
        return;
    }
    string s = "";
    fore(i, cnt5 - (cnt5 % 9))
        s += '5';
    fore(i, cnt0)
    {
        if (s.empty() || s[0] != '0')
            s += '0';
    }
    cout << s;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
