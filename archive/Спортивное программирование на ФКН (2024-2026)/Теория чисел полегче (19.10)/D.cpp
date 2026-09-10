#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, k, cur = 1;
    cin >> n >> k;

    set<int> res;
    while (cur * cur <= n)
    {
        if (n % cur == 0)
        {
            res.insert(cur);
            res.insert(n / cur);
        }
        cur++;
    }
    // sort(res.begin(), res.end());
    if (res.size() >= k)
        cout << *next(res.begin(), k - 1);
    else
        cout << "-1";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
