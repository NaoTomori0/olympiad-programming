// B. Дерево отрезков на минимум
// ограничение по времени на тест1 секунда
// ограничение по памяти на тест1024 мегабайта

// Теперь измените код дерева отрезков, чтобы вместо суммы считался минимум на отрезке.

// Входные данные
// Первая строка содержит два числа n и m (1 ≤ n, m ≤ 100 000) — размер массива
// и число операций. Следующая строка содержит n чисел a_i — начальное состояние
// массива (0 ≤ a_i ≤ 10^9). Далее следует описание операций. Описание каждой операции
// имеет следующий вид:

// 1 i v — присвоить элементу с индексом i значение v (0 ≤ i < n, 0 ≤ v ≤ 10^9).
// 2 l r — вычислить минимум среди элементов с индексами от l до r−1 (0 ≤ l < r ≤ n).

// Выходные данные
// Для каждой операции второго типа выведите соответствующий минимум.

// ======================================================================
// Пример
// ======================================================================
// Входные данные
// ======================================================================
// 5 5
// 5 4 2 3 5
// 2 0 3
// 1 2 6
// 2 0 3
// 1 3 1
// 2 0 5
// ======================================================================
// Выходные данные
// ======================================================================
// 2
// 4
// 1
// ======================================================================

#include <bits/stdc++.h>
using namespace std;

#define int long long

struct segtree
{
    vector<int> tree;
    int size = 1;

    void init(int s)
    {
        while (size < s)
            size *= 2;
        tree.assign(2 * size - 1, 4e18);
    }

    void set(int i, int v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            tree[x] = v;
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid)
            set(i, v, 2 * x + 1, lx, mid);
        else
            set(i, v, 2 * x + 2, mid, rx);

        tree[x] = min(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void set(int i, int v) { set(i, v, 0, 0, size); }

    int getmin(int l, int r, int x, int lx, int rx)
    {
        if (l >= rx || lx >= r)
            return 4e18;
        if (lx >= l && rx <= r)
            return tree[x];

        int mid = (lx + rx) / 2;
        int m1 = getmin(l, r, 2 * x + 1, lx, mid);
        int m2 = getmin(l, r, 2 * x + 2, mid, rx);
        return min(m1, m2);
    }

    int getmin(int l, int r) { return getmin(l, r, 0, 0, size); }
};

void solve()
{
    segtree st;
    int n, m;
    cin >> n >> m;
    st.init(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.set(i, x);
    }

    for (int t = 0; t < m; t++)
    {
        int j;
        cin >> j;
        if (j == 1)
        {
            int i, v;
            cin >> i >> v;
            st.set(i, v);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << st.getmin(l, r) << "\n";
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
