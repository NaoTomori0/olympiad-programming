#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define int long long

void solve()
{
    string s;
    cin >> s;
    int n = s.size();

    if (n <= 2)
    {
        cout << 1 << '\n';
        return;
    }

    int base = 1;
    for (int i = 1; i < n; i++)
    {
        if (s[i] != s[i - 1])
            base++;
    }

    set<int> st;
    st.insert(base);

    for (int i = 1; i + 1 < n; i++)
    {
        int old_c = (s[i] != s[i - 1]) + (s[i + 1] != s[i]);
        char inv = (s[i] == '0' ? '1' : '0');
        int new_c = (inv != s[i - 1]) + (s[i + 1] != inv);
        st.insert(base - old_c + new_c);
    }

    cout << st.size() << '\n';
}

int32_t main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
