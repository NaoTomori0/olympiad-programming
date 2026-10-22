#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()
#define fread(filename) freopen(filename, "r", stdin);
#define fwrite(filename) freopen(filename, "w", stdout);

void solve()
{
    int n, k;
    string a, b;
    cin >> n >> k >> a >> b;
    array<int, 27> have{}, need{};
    for (auto &i : a)
        have[i - 'a']++;
    for (auto &i : b)
        need[i - 'a']++;

    for (int i = 0; i < 26; i++)
    {
        if (have[i] < need[i] || (have[i] - need[i]) % k)
        {
            cout << "No\n";
            return;
        }
        have[i + 1] += have[i] - need[i];
    }
    cout << "Yes\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
