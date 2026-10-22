// D. Прибавление и сумма
// ограничение по времени на тест1 секунда
// ограничение по памяти на тест1024 мегабайта

// Есть массив из n элементов, изначально заполненный нулями. Вам нужно написать
// структуру данных, которая обрабатывает два вида запросов:

// - прибавить ко всем элементам от l до r−1 число v;
// - найти сумму элементов на отрезке от l до r−1.

// Входные данные
// Первая строка содержит два числа n и m (1 ≤ n, m ≤ 100000) — размер массива
// и число операций. Далее следует описание операций. Описание каждой операции
// имеет следующий вид:

// 1 l r v — прибавить ко всем элементам от l до r−1 число v
// (0 ≤ l < r ≤ n, 0 ≤ v ≤ 10^5).
// 2 l r — найти сумму элементов на отрезке от l до r−1 (0 ≤ l < r ≤ n).

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
// 14
// 18
// 4
// ======================================================================

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()

struct SegTree
{
public:
    SegTree(int n)
    {
        while (size < n)
            size <<= 1;
        tree.assign(2 * size - 1, NNULLNODE);
    }

    int get(int l, int r) { return get(l, r, 0, 0, size); }

    void modify(int l, int r, int v) { modify(l, r, v, 0, 0, size); }

private:
    struct Node
    {
        int val, modif;
    };
    const Node NNULLNODE = {0, 0};
    vector<Node> tree;
    int size = 1;

    int get(int l, int r, int x, int lx, int rx)
    {
        if (lx >= l && rx <= r)
            return tree[x].val;
        if (rx <= l || lx >= r)
            return 0;
        propogate(x, lx, rx);
        int m = (lx + rx) / 2;
        int rl = get(l, r, 2 * x + 1, lx, m), rr = get(l, r, 2 * x + 2, m, rx);
        return rl + rr;
    }

    void propogate(int x, int lx, int rx)
    {
        if (rx - lx == 1 || tree[x].modif == 0)
            return;

        int m = (rx + lx) / 2;
        tree[2 * x + 1].modif += tree[x].modif;
        tree[2 * x + 1].val += tree[x].modif * (m - lx);

        tree[2 * x + 2].modif += tree[x].modif;
        tree[2 * x + 2].val += tree[x].modif * (rx - m);
        tree[x].modif = 0;
    }

    void modify(int l, int r, int v, int x, int lx, int rx)
    {
        if (lx >= l && rx <= r)
        {
            tree[x].modif += v;
            tree[x].val += v * (rx - lx);

            return;
        }
        if (rx <= l || lx >= r)
            return;

        propogate(x, lx, rx);
        int m = (rx + lx) / 2;
        modify(l, r, v, 2 * x + 1, lx, m);
        modify(l, r, v, 2 * x + 2, m, rx);
        tree[x].val = tree[2 * x + 1].val + tree[2 * x + 2].val;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    SegTree st(n);
    while (m--)
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
            cout << st.get(l, r) << '\n';
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
