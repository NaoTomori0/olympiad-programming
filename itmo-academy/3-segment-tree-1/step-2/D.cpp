// D. Первый элемент не меньше X - 2
// ограничение по времени на тест1 секунда
// ограничение по памяти на тест1024 мегабайта

// В этой задаче вам нужно добавить в дерево отрезков операцию нахождения по данным x и l
// минимального индекса j, для которого j ≥ l и a[j] ≥ x.

// Входные данные
// Первая строка содержит два числа n и m (1 ≤ n, m ≤ 100 000) — размер массива
// и число операций. Следующая строка содержит n чисел a_i — начальное состояние
// массива (0 ≤ a_i ≤ 10^9). Далее следует описание операций. Описание каждой операции
// имеет следующий вид:

// 1 i v — изменить элемент с индексом i на v (0 ≤ i < n, 0 ≤ v ≤ 10^9).
// 2 x l — найти минимальный индекс j, для которого j ≥ l и a[j] ≥ x
// (0 ≤ x ≤ 10^9, 0 ≤ l < n). Если такого элемента нет, выведите −1.
// Индексы начинаются с 0.

// Выходные данные
// Для каждой операции второго типа выведите ответ на запрос.

// ======================================================================
// Пример
// ======================================================================
// Входные данные
// ======================================================================
// 5 7
// 1 3 2 4 3
// 2 3 0
// 2 3 2
// 1 2 5
// 2 4 1
// 2 5 4
// 1 3 7
// 2 6 1
// ======================================================================
// Выходные данные
// ======================================================================
// 1
// 3
// 2
// -1
// 3
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
        tree.assign(2 * size - 1, 0);
    }

    void set(int i, int v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            tree[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m)
            set(i, v, 2 * x + 1, lx, m);
        else
            set(i, v, 2 * x + 2, m, rx);

        tree[x] = max(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void set(int i, int v) { set(i, v, 0, 0, size); }

    void build(vector<int> &a, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            if (lx < a.size())
                tree[x] = a[lx];
        }
        else
        {
            int m = (lx + rx) / 2;
            build(a, 2 * x + 1, lx, m);
            build(a, 2 * x + 2, m, rx);
            tree[x] = max(tree[2 * x + 1], tree[2 * x + 2]);
        }
    }

    void build(vector<int> &a, int x)
    {
        init(x);
        build(a, 0, 0, size);
    }

    int find_L(int v, int l, int x, int lx, int rx)
    {
        if (tree[x] < v || l >= rx)
            return -1;
        if (rx - lx == 1)
            return lx;

        int m = (lx + rx) / 2, res = -1;

        res = find_L(v, l, 2 * x + 1, lx, m);
        if (res == -1)
            res = find_L(v, l, 2 * x + 2, m, rx);
        return res;
    }

    int find_L(int v, int l) { return find_L(v, l, 0, 0, size); }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;

    segtree st;
    st.build(a, n);

    while (m--)
    {
        int c, a, b;
        cin >> c;
        if (c == 1)
        {
            cin >> a >> b;
            st.set(a, b);
        }
        else
        {
            cin >> a >> b;
            cout << st.find_L(a, b) << '\n';
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
