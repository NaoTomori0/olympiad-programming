#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()
#define fore(i, end) for (int i = 0; i < end; i++)
#define forse(i, start, end) for (int i = start; i < end; i++)

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    vector<bool> ok(n, 0);
    stack<int> st;
    fore(i, n)
    {
        if (s[i] == '1')
            st.push(i);
        else if (s[i] == '2')
        {
            if (!st.empty())
            {
                ok[st.top()] = 1;
                st.pop();
            }
            else
                ok[i] = 1;
        }
        else
        {
            ok[i] = 1;
        }
    }
    vector<int> res;
    for (int i = 0; i < n; i++)
        if (!ok[i])
            res.push_back(i + 1);
    sort(all(res));
    cout << res.size() << '\n';
    for (auto &i : res)
        cout << i << ' ';
    cout << '\n';
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
