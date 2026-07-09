// C. Число минимумов на отрезке
// ограничение по времени на тест1 секунда
// ограничение по памяти на тест1024 мегабайта

// Теперь измените код дерева отрезков, чтобы кроме минимума на отрезке считалось
// также и число элементов, равных минимуму.

// Входные данные
// Первая строка содержит два числа n и m (1 ≤ n, m ≤ 100 000) — размер массива
// и число операций. Следующая строка содержит n чисел a_i — начальное состояние
// массива (0 ≤ a_i ≤ 10^9). Далее следует описание операций. Описание каждой операции
// имеет следующий вид:

// 1 i v — присвоить элементу с индексом i значение v (0 ≤ i < n, 0 ≤ v ≤ 10^9).
// 2 l r — найти минимум и число элементов, равных минимуму, среди элементов
// с индексами от l до r−1 (0 ≤ l < r ≤ n).

// Выходные данные
// Для каждой операции второго типа выведите два числа — минимум на заданном отрезке
// и число элементов, равных этому минимуму.

// ======================================================================
// Пример
// ======================================================================
// Входные данные
// ======================================================================
// 5 5
// 3 4 3 5 2
// 2 0 3
// 1 1 2
// 2 0 3
// 1 0 2
// 2 0 5
// ======================================================================
// Выходные данные
// ======================================================================
// 3 2
// 2 1
// 2 3
// ======================================================================

#include <bits/stdc++.h>
using namespace std;

#define int long long

struct node
{
    int min_val, count;
};

struct segtree
{
    vector<node> tree;
    int size = 1;

    const node ne{(int)4e18, 0};

    void init(int x)
    {
        while (size < x)
            size *= 2;

        tree.assign(2 * size - 1, ne);
    }

    node min(node a, node b)
    {
        if (a.min_val > b.min_val)
            return b;
        if (a.min_val < b.min_val)
            return a;
        return {a.min_val, a.count + b.count};
    }

    void set(int i, int v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            tree[x] = {v, 1};
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

    node getmin(int l, int r, int x, int lx, int rx)
    {
        if (lx >= l && rx <= r)
            return tree[x];
        if (lx >= r || rx <= l)
            return ne;

        int mid = (lx + rx) / 2;
        node m1 = getmin(l, r, 2 * x + 1, lx, mid);
        node m2 = getmin(l, r, 2 * x + 2, mid, rx);
        return min(m1, m2);
    }

    node getmin(int l, int r) { return getmin(l, r, 0, 0, size); }
};

void solve()
{
    int n, m;
    segtree st;
    cin >> n >> m;
    st.init(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.set(i, x);
    }

    for (int j = 0; j < m; j++)
    {
        int cd;
        cin >> cd;
        if (cd == 1)
        {
            int i, v;
            cin >> i >> v;
            st.set(i, v);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            node result = st.getmin(l, r);
            cout << result.min_val << " " << result.count << "\n";
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
