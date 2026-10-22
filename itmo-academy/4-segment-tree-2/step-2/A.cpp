// A. Прибавление и минимум
// ограничение по времени на тест1 секунда
// ограничение по памяти на тест1024 мегабайта

// Есть массив из n элементов, изначально заполненный нулями. Вам нужно написать
// структуру данных, которая обрабатывает два вида запросов:

// - прибавить к отрезку от l до r−1 число v;
// - узнать минимум на отрезке от l до r−1.

// Входные данные
// Первая строка содержит два числа n и m (1 ≤ n, m ≤ 100000) — размер массива
// и число операций. Далее следует описание операций. Описание каждой операции
// имеет следующий вид:

// 1 l r v — прибавить значение v к отрезку от l до r−1 (0 ≤ l < r ≤ n, 0 ≤ v ≤ 10^9).
// 2 l r — узнать минимум на отрезке от l до r−1 (0 ≤ l < r ≤ n).

// Выходные данные
// Для каждой операции второго типа выведите соответствующее значение.

// ======================================================================
// Пример
// ======================================================================
// Входные данные
// ======================================================================
// 5 6
// 1 0 3 3
// 2 1 2
// 1 1 4 4
// 2 1 3
// 2 1 4
// 2 3 5
// ======================================================================
// Выходные данные
// ======================================================================
// 3
// 7
// 4
// 0
// ======================================================================

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()
#define forr(i, n) for (int i = 0; i < n; i++)

struct SegTree
{
public:
    SegTree(int n)
    {
        while (size < n)
            size *= 2;
        tree.assign(2 * size - 1, NULLNODE);
    }

    int get(int l, int r) { return get(l, r, 0, 0, size); }

    void modify(int l, int r, int v) { modify(l, r, v, 0, 0, size); }

private:
    struct Node
    {
        int min, add;
    };
    const Node NULLNODE = {0, 0};
    vector<Node> tree;
    int size = 1;

    int get(int l, int r, int x, int lx, int rx)
    {
        if (lx >= l && rx <= r)
            return tree[x].min;
        if (rx <= l || lx >= r)
            return 1e18;
        int m = (lx + rx) / 2;
        int r1 = get(l, r, 2 * x + 1, lx, m), r2 = get(l, r, 2 * x + 2, m, rx);
        return min(r1, r2) + tree[x].add;
    }

    void modify(int l, int r, int v, int x, int lx, int rx)
    {
        if (lx >= l && rx <= r)
        {
            tree[x].min += v;
            tree[x].add += v;
            return;
        }
        if (rx <= l || lx >= r)
            return;
        int m = (lx + rx) / 2;
        modify(l, r, v, 2 * x + 1, lx, m);
        modify(l, r, v, 2 * x + 2, m, rx);
        tree[x].min = min(tree[2 * x + 1].min, tree[2 * x + 2].min) + tree[x].add;
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    SegTree st(n);
    while (q--)
    {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1)
        {
            int v;
            cin >> v;
            st.modify(l, r, v);
        }
        else
        {
            cout << st.get(l, r) << '\n';
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
