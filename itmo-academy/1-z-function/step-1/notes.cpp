#include <iostream>
#include <string>
#include <vector>

// Строка (String) - это конечная или пустая последовательность символов.
// Длина строки S обозначается как |s|.
// Символы будем считать пронумерованными от 0 дл |s| - 1. (Индексы)

// Примеры строк: "01010110", "abcabc", [31, 34, 41] (Символы целые числа), ""

// Подстрока - последовательность подряд идущих символов строки.
// Например, все подстроки строки "apple":
// "apple", "appl", "pple", "app", "ppl", "ple", "ap","pp", "pl", "le", "a", "p", "l", "e", ""

std::vector<std::string> example()
{
    std::vector<std::string> result;
    std::string w = "";
    std::cin >> w;
    int len = w.length();

    // 1. Внешний цикл задает ДЛИНУ подстроки (от len до 1)
    for (int sub_len = len; sub_len > 0; sub_len--)
    {
        // 2. Внутренний цикл задает ИНДЕКС НАЧАЛА подстроки
        for (int start = 0; start <= len - sub_len; start++)
        {
            std::string tmp_res = "";
            // 3. Выводим символы подстроки заданной длины
            for (int i = start; i < start + sub_len; i++)
            {
                tmp_res.push_back(w[i]);
            }
            result.push_back(tmp_res);
        }
    }

    result.push_back("");

    return result;
}

std::vector<std::string> example()
{
    std::vector<std::string> result;
    return result;
}

int main()
{
    std::vector<std::string> exa = example();
    for (auto i = exa.begin(); i != exa.end(); i++)
    {
        std::cout << "'" << *i << "', ";
    }
    std::cout << std::endl;

    return 0;
}
