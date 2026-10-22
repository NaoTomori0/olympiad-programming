#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()
#define fore(i, end) for (int i = 0; i < end; i++)
#define forse(i, start, end) for (int i = start; i < end; i++)

void solve()
{
    int n, k;
    cin >> n >> k;
    int i = 1, cur = n;
    for (; cur; cur--, i++)
    {
        if (i % k == 0)
            cur++;
    }
    cout << i - 1 << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
