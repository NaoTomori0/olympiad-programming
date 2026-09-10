#include <bits/stdc++.h>
using namespace std;

#define int long double

void solve()
{
    int n;
    cin >> n;
    int res = 0;
    for (int i = 1; i <= n; i++)
        res += pow(2, i);
    cout << setprecision(20) << res;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
