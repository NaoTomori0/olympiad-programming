// A. Отрезок с максимальной суммой
// ограничение по времени на тест1 секунда
// ограничение по памяти на тест1024 мегабайта

// В этой задаче вам нужно написать дерево отрезков для нахождения подотрезка с максимальной суммой.

// Входные данные
// Первая строка содержит два числа n и m (1 ≤ n, m ≤ 100 000) — размер массива и число операций.
// Следующая строка содержит n чисел a_i — начальное состояние массива (−10^9 ≤ a_i ≤ 10^9).
// Далее следует m строк, каждая из которых содержит два целых числа i и v — присвоить элементу
// с индексом i значение v (0 ≤ i < n, −10^9 ≤ v ≤ 10^9).

// Выходные данные
// Выведите m + 1 строку: максимальную сумму чисел на некотором подотрезке массива до всех операций
// и после каждой операции. Отрезок может быть пустым (в этом случае сумма равна 0).

// ======================================================================
// Примеры
// ======================================================================
// Входные данные
// ======================================================================
// 5 2
// 5 -4 4 3 -5
// 4 3
// 3 -1
// ======================================================================
// Выходные данные
// ======================================================================
// 8
// 11
// 7

// ======================================================================
// Входные данные
// ======================================================================
// 4 2
// -2 -1 -5 -4
// 1 3
// 3 2
// ======================================================================
// Выходные данные
// ======================================================================
// 0
// 3
// 3
// ======================================================================

#include <bits/stdc++.h>
using namespace std;

#define int long long

struct segtree
{

    struct node
    {
        int seg, pref, suf, sum;
    };

    node one_element(int x)
    {
        return {
            max(x, 0LL),
            max(x, 0LL),
            max(x, 0LL),
            x};
    }

    vector<node> tree;
    int size = 1;

    node combine(node a, node b)
    {
        return {
            max(a.seg, max(b.seg, a.suf + b.pref)),
            max(a.pref, a.sum + b.pref),
            max(b.suf, b.sum + a.suf),
            a.sum + b.sum};
    }

    const node ZERO = {0, 0, 0, 0};

    void init(int x)
    {
        while (size < x)
            size *= 2;
        tree.assign(2 * size, ZERO);
    }

    void build(vector<int> &a, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            if (lx < a.size())
                tree[x] = one_element(a[lx]);
        }
        else
        {
            int m = (lx + rx) / 2;
            build(a, 2 * x + 1, lx, m);
            build(a, 2 * x + 2, m, rx);
            tree[x] = combine(tree[2 * x + 1], tree[2 * x + 2]);
        }
    }

    void build(vector<int> &a, int s)
    {
        init(s);
        build(a, 0, 0, size);
    }

    void set(int i, int v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            tree[x] = one_element(v);
            return;
        }
        int m = (rx + lx) / 2;
        if (i < m)
            set(i, v, 2 * x + 1, lx, m);
        else
            set(i, v, 2 * x + 2, m, rx);
        tree[x] = combine(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void set(int i, int v)
    {
        set(i, v, 0, 0, size);
    }

    node calc(int l, int r, int x, int lx, int rx)
    {
        if (l >= rx || r <= lx)
            return ZERO;
        if (lx >= l && rx <= r)
            return tree[x];
        int m = (lx + rx) / 2;
        node n1 = calc(l, r, 2 * x + 1, lx, m);
        node n2 = calc(l, r, 2 * x + 2, m, rx);
        return combine(n1, n2);
    }

    node calc(int l, int r)
    {
        return calc(l, r, 0, 0, size);
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n, 0);
    for (auto &i : a)
        cin >> i;

    segtree st;
    st.build(a, n);
    cout << st.tree[0].seg << '\n';
    while (m--)
    {
        int i, v;
        cin >> i >> v;
        st.set(i, v);
        cout << st.tree[0].seg << '\n';
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
