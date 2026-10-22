#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()
#define fore(i, end) for (int i = 0; i < end; i++)
#define forse(i, start, end) for (int i = start; i < end; i++)
#define fread(filename) freopen(filename, "r", stdin);
#define fwrite(filename) freopen(filename, "w", stdout);

void solve()
{
    // fread("slalom.in");
    // fwrite("slalom.out");

    int n;
    cin >> n;
    vector<int> cur(n, 0), prev(n, 0);
    cin >> prev[0];
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cin >> cur[j];
            cur[j] = max((j > 0 ? cur[j] + prev[j - 1] : (int)-1e18), (j == i - 1 ? (int)-1e18 : cur[j] + prev[j]));
        }
        prev = cur;
    }
    cout << *max_element(all(prev)) << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
