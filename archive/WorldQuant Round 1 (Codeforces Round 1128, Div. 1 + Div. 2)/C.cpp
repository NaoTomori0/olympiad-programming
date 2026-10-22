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
    cin >> n;
    int chet = 0, nechet = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x % 2 == 0)
            chet++;
        else
            nechet++;
    }

    if ((nechet == 0 && chet == 0) ||
        (nechet == 1 && chet == 1) ||
        (nechet == 3 && chet == 0))
        cout << "Larpity\n";
    else
        cout << "Moggity\n";
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
