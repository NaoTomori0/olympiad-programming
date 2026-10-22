#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()
#define fore(i, end) for (int i = 0; i < end; i++)
#define forse(i, start, end) for (int i = start; i < end; i++)

void solve()
{
    int a, b, x1, x2, y1, y2;
    cin >> a >> b >> x1 >> y1 >> x2 >> y2;
    int xmove[]{1, 1, -1, -1};
    int ymove[]{1, -1, 1, -1};
    //  ru  rd  lu ld

    int res = 0;
    for (int i = 0; i < (a != b ? 8 : 4); i++)
    {
        int npx = x1 + (i >= 4 ? b : a) * xmove[i % 4], npy = y1 + (i >= 4 ? a : b) * ymove[i % 4];
        int ok = 0;
        for (int j = 0; j < (a != b ? 8 : 4); j++)
        {
            int nnx = npx + (j >= 4 ? b : a) * xmove[j % 4], nny = npy + (j >= 4 ? a : b) * ymove[j % 4];
            ok += ((nnx == x1 && nny == y1) || (nnx == x2 && nny == y2));
        }
        res += ok == 2;
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
