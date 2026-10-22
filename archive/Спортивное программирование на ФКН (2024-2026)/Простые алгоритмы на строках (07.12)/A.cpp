#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()
#define fread(filename) freopen(filename, "r", stdin);
#define fwrite(filename) freopen(filename, "w", stdout);

vector<int> Zfunc(string &s)
{
    int n = s.size();
    vector<int> z(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++)
    {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[z[i] + i])
            z[i]++;
        if (r < z[i] + i - 1)
        {
            l = i;
            r = z[i] + i - 1;
        }
    }
    return z;
}

vector<int> prefFunc(string &s)
{
    int n = s.size();
    vector<int> p(n, 0);

    for (int i = 1; i < n; i++)
    {
        int j = p[i - 1];
        while (j > 0 && s[i] != s[j])
            j = p[j - 1];
        if (s[i] == s[j])
            j++;
        p[i] = j;
    }
    return p;
}

void solve()
{
    string s;
    cin >> s;
    for (auto &i : Zfunc(s))
        cout << i << ' ';
    cout << '\n';

    for (auto &i : prefFunc(s))
        cout << i << ' ';
    cout << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}
