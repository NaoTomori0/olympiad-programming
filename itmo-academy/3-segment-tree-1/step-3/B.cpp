// B. Инверсии 2
// ограничение по времени на тест1 секунда
// ограничение по памяти на тест1024 мегабайта

// Это задача, обратная предыдущей. Была перестановка p_i из n элементов, для каждого i
// записали число a_i — число таких j, что j < i и p_j > p_i. Восстановите по заданным a_i
// исходную перестановку.

// Входные данные
// Первая строка содержит число n (1 ≤ n ≤ 10^5), вторая строка содержит n чисел a_i.
// Гарантируется, что a_i были получены из какой-то перестановки с помощью процедуры,
// описанной в условии.

// Выходные данные
// Выведите n чисел — исходную перестановку.

// ======================================================================
// Пример
// ======================================================================
// Входные данные
// ======================================================================
// 5
// 0 1 1 0 3
// ======================================================================
// Выходные данные
// ======================================================================
// 4 1 3 5 2
// ======================================================================

#include <bits/stdc++.h>
using namespace std;

#define int long long

struct segtree
{
    vector<int> tree;
    int size = 1;

    void init(int x)
    {
        while (size < x)
            size *= 2;
        tree.assign(2 * size, 0);
    }

    void build(int n, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            if (lx < n)
                tree[x] = 1;
        }
        else
        {
            int m = (lx + rx) / 2;
            build(n, 2 * x + 1, lx, m);
            build(n, 2 * x + 2, m, rx);
            tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
        }
    }

    void build(int x)
    {
        init(x);
        build(x, 0, 0, size);
    }

    void minus(int i, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            tree[x] = 0;
            return;
        }
        int m = (rx + lx) / 2;
        if (i < m)
            minus(i, 2 * x + 1, lx, m);
        else
            minus(i, 2 * x + 2, m, rx);

        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }

    void minus(int i) { minus(i, 0, 0, size); }

    int find(int k, int x, int lx, int rx)
    {
        if (rx - lx == 1)
            return lx;
        int m = (rx + lx) / 2;
        if (k < tree[2 * x + 2])
            return find(k, 2 * x + 2, m, rx);
        else
            return find(k - tree[2 * x + 2], 2 * x + 1, lx, m);
    }

    int find(int k)
    {
        return find(k, 0, 0, size);
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;

    segtree st;
    st.build(n);

    list<int> ans;

    for (auto i = a.rbegin(); i != a.rend(); i++)
    {
        int val = st.find(*i);
        ans.push_front(val + 1);
        st.minus(val);
    }

    for (auto i : ans)
        cout << i << " ";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
