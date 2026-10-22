#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()
#define fore(i, end) for (int i = 0; i < end; i++)
#define forse(i, start, end) for (int i = start; i < end; i++)

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt0 = 0;
    for (auto &i : s)
        cnt0 += i == 'z';
    int cnt1 = (n - (4 * cnt0)) / 3;
    while (cnt1--)
        cout << "1 ";
    while (cnt0--)
        cout << "0 ";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
