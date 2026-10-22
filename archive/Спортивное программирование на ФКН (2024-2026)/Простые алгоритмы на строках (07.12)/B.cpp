#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()
#define fread(filename) freopen(filename, "r", stdin);
#define fwrite(filename) freopen(filename, "w", stdout);

vector<int> Zf(string &s)
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
    fread("search.in");
    fwrite("search.out");
    string a, b;
    cin >> a >> b;
    string n = b + '#' + a;
    vector<int> res, z = Zf(n);
    int target = b.size();
    for (int i = b.size() + 1; i < n.size(); i++)
        if (z[i] == target)
            res.push_back(i - target);

    cout << res.size() << '\n';
    for (auto &i : res)
        cout << i << ' ';
}

void solve2()
{
    fread("search.in");
    fwrite("search.out");
    string a, b;
    cin >> a >> b;

    int j = 0;
    vector<int> res, p = prefFunc(b);
    for (int i = 0; i < a.size(); i++)
    {
        while (j > 0 && a[i] != b[j])
            j = p[j - 1];

        if (a[i] == b[j])
            j++;
        if (j == b.size())
        {
            res.push_back(i - j + 2);
            j = p[j - 1];
        }
    }
    cout << res.size() << '\n';
    for (auto &i : res)
        cout << i << ' ';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // solve();
    solve2();
    return 0;
}
