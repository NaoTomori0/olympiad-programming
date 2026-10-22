#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()
#define fread(filename) freopen(filename, "r", stdin);
#define fwrite(filename) freopen(filename, "w", stdout);

void solve()
{
    int n;
    string s;
    cin >> n >> s;

    vector<int> res, pos0, pos1;
    int cur = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            if (pos1.empty())
            {
                cur++;
                res.push_back(cur);
                pos0.push_back(cur);
            }
            else
            {
                int cmp = pos1.back();
                pos1.pop_back();
                pos0.push_back(cmp);
                res.push_back(cmp);
            }
        }
        else
        {
            if (pos0.empty())
            {
                cur++;
                res.push_back(cur);
                pos1.push_back(cur);
            }
            else
            {
                int cmp = pos0.back();
                pos0.pop_back();
                pos1.push_back(cmp);
                res.push_back(cmp);
            }
        }
    }
    cout << cur << '\n';
    for (auto &i : res)
        cout << i << ' ';
    cout << '\n';
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
