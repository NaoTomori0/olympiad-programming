#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin >> n;
    int t = n * (n - 1) * (n - 2) * (n - 3) * (n - 4);
    cout << (t / 120) * t;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}

// # # # # #
// # # # # #
// # # # # #
// # # # # #
// # # # # #
