// C. Число инверсий на отрезке
// ограничение по времени на тест4 секунды
// ограничение по памяти на тест1024 мегабайта

// Дан массив a, состоящий из небольших целых чисел (1 ≤ a_i ≤ 40). Нужно построить
// структуру данных, которая обрабатывает два вида запросов:

// - найти число инверсий на отрезке массива;
// - изменить элемент массива.

// Входные данные
// В первой строке два целых числа n и q — длина массива и число запросов соответственно
// (1 ≤ n, q ≤ 10^5).

// Во второй строке через пробел записано n чисел a1, a2, …, a_n, где a_i — начальное
// состояние массива (1 ≤ a_i ≤ 40).

// Следующие q строк описывают запросы. Каждая из этих строк имеет формат
// «type_i x_i y_i».

// - Если type_i = 1, то в i-м запросе требуется определить число инверсий на отрезке
//   от x_i до y_i включительно (в этом случае 1 ≤ x_i ≤ y_i ≤ n).

// - Если type_i = 2, то элемент с индексом x_i заменяется на y_i (в этом случае
//   1 ≤ x_i ≤ n, 1 ≤ y_i ≤ 40).

// Выходные данные
// Для каждого запроса типа 1 выведите ответ на этот запрос на отдельной строке.

// ======================================================================
// Пример
// ======================================================================
// Входные данные
// ======================================================================
// 7 6
// 1 2 3 6 5 4 19
// 1 1 3
// 1 2 5
// 1 2 4
// 2 2 8
// 1 1 6
// 1 1 3
// ======================================================================
// Выходные данные
// ======================================================================
// 0
// 1
// 0
// 7
// 1
// ======================================================================

#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Node
{
    int invert = 0;
    int cnt[41]{0};
};

struct SegTree
{

    void build(vector<int> &a, int s)
    {
        init(s);
        build(a, 0, 0, size);
    }

    void set(int i, int v)
    {
        set(i, v, 0, 0, size);
    }

    int get_inv_on_seg(int l, int r)
    {
        return get_inv_on_seg(l, r, 0, 0, size).invert;
    }

private:
    vector<Node> tree;
    int size = 1;

    Node one_element(int x)
    {
        Node res;
        res.invert = 0;
        for (int i = 1; i < 41; i++)
            res.cnt[i] = 0;
        res.cnt[x] = 1;
        return res;
    }

    Node neutral_node()
    {
        Node res;
        res.invert = 0;
        for (int i = 0; i <= 40; i++)
            res.cnt[i] = 0;
        return res;
    }

    Node combine(Node l, Node r)
    {
        Node res;
        res.invert = l.invert + r.invert;

        int cross_inv = 0, r_sum = 0;

        for (int i = 1; i < 41; i++)
        {
            cross_inv += l.cnt[i] * r_sum;
            r_sum += r.cnt[i];
        }
        res.invert += cross_inv;

        for (int i = 1; i < 41; i++)
            res.cnt[i] += l.cnt[i] + r.cnt[i];

        return res;
    }

    void init(int x)
    {
        size = 1;
        while (size < x)
            size *= 2;
        tree.assign(2 * size - 1, neutral_node());
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
            int m = (rx + lx) / 2;
            build(a, 2 * x + 1, lx, m);
            build(a, 2 * x + 2, m, rx);
            tree[x] = combine(tree[2 * x + 1], tree[2 * x + 2]);
        }
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

    Node get_inv_on_seg(int l, int r, int x, int lx, int rx)
    {
        if (lx >= l && rx <= r)
            return tree[x];
        if (lx >= r || rx <= l)
            return neutral_node();

        int m = (rx + lx) / 2;
        Node n1 = get_inv_on_seg(l, r, 2 * x + 1, lx, m), n2 = get_inv_on_seg(l, r, 2 * x + 2, m, rx);
        return combine(n1, n2);
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;

    SegTree st;
    st.build(a, n);

    while (q--)
    {
        int ty, x, y;
        cin >> ty >> x >> y;
        if (ty == 2)
            st.set(x - 1, y);
        else
            cout << st.get_inv_on_seg(x - 1, y) << '\n';
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
