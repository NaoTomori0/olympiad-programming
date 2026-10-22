#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()
#define fore(i, end) for (int i = 0; i < end; i++)
#define forse(i, start, end) for (int i = start; i < end; i++)

void solve()
{
    int ax, ay, bx, by, fx, fy;
    cin >> ax >> ay >> bx >> by >> fx >> fy;
    int d = abs(ax - bx) + abs(ay - by);
    if ((ax == bx && ax == fx && ((ay < fy && fy < by) || (ay > fy && fy > by))) || (ay == by && ay == fy && ((ax < fx && fx < bx) || (ax > fx && fx > bx))))
        d += 2;
    cout << d << '\n';
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
