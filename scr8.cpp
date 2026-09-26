#include <bits/stdc++.h>
using namespace std;

#define int long long

struct DSU
{
    vector<int> parent, sum, size, virtid;
    int next_virt_node;
    DSU(int n, int m)
    {
        int s = n + m + 9;
        parent.resize(s);
        sum.resize(s);
        virtid.resize(n + 1);
        size.assign(s, 1);

        next_virt_node = n + 1;
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
            sum[i] = i;
            virtid[i] = i;
        }
    }

    int get(int x) { return parent[x] = (x == parent[x] ? x : get(parent[x])); }

    void united(int p, int q)
    {
        int pap = get(virtid[p]), paq = get(virtid[q]);
        if (pap != paq)
        {
            parent[pap] = paq;
            size[paq] += size[pap];
            sum[paq] += sum[pap];
        }
    }

    void replace_to(int val, int to)
    {
        int paval = get(virtid[val]), pato = get(virtid[to]);
        if (paval != pato)
        {
            size[paval]--;
            sum[paval] -= val;

            int next = next_virt_node++;
            virtid[val] = next;

            parent[next] = pato;
            size[pato]++;
            sum[pato] += val;
        }
    }
};

void solve()
{
    int n, m;
    while (cin >> n >> m)
    {
        DSU d(n, m);
        while (m--)
        {
            int typ;
            cin >> typ;
            if (typ == 1)
            {
                int p, q;
                cin >> p >> q;
                d.united(p, q);
            }
            else if (typ == 2)
            {
                int p, q;
                cin >> p >> q;
                d.replace_to(p, q);
            }
            else
            {
                int x;
                cin >> x;
                int vid = d.get(d.virtid[x]);
                cout << d.size[vid] << ' ' << d.sum[vid] << '\n';
            }
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
