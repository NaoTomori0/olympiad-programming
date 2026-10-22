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
    int n, m, k;
    string prefix, direction, game;
    if (!(cin >> n >> m >> k >> prefix >> direction >> game))
        return;

    int mv = (direction == "head" ? -1 : 1);

    for (int i = 0; i < game.length(); i++)
    {
        if (k == 1)
            mv = 1;
        else if (k == n)
            mv = -1;

        if (game[i] - '0' == 1)
        {
            k += mv;
            if (mv == 1)
                m = 1;
            else
                m = n;

            if (m == k)
            {
                cout << "Controller " << i + 1 << "\n";
                return;
            }
        }
        else
        {
            if (k > m)
            {
                if (m > 1)
                    m--;
            }
            else if (k < m)
            {
                if (m < n)
                    m++;
            }

            if (m == k)
            {
                cout << "Controller " << i + 1 << "\n";
                return;
            }

            k += mv;

            if (m == k)
            {
                cout << "Controller " << i + 1 << "\n";
                return;
            }
        }
    }
    cout << "Stowaway\n";
}

int32_t main()
{
    fastio;

    solve();
    return 0;
}
