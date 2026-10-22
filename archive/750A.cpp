#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()
#define fore(i, end) for (int i = 0; i < end; i++)
#define forse(i, start, end) for (int i = start; i < end; i++)

void solve()
{
    int rem = 240;
    int n, k;
    cin >> n >> k;
    int d = rem - k;
    d = d - (d % 5);
    d *= 2;
    int l = 0, r = n + 1;
    while (r > l + 1)
    {
        int m = (l + r) / 2;
        if ((5 + 5 * m) * m > d)
            r = m;
        else
            l = m;
    }
    cout << l;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
