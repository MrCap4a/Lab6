#include <iostream>
#include <stack>
#include <fstream>
#include <string>

using namespace std;

stack <int> train;
stack <int> type_one;
stack <int> type_two;


void Keyboard() {
    cout << "Вводите 1 или 2 для обозначения типа вагона. Для прекращения ввода наишите любое другое число." << endl;
    int type = 3;
    cin >> type;
    while ((type == 1) or (type == 2)) {
        train.push(type);
        cin >> type;
    }
}

void File() {
    cout << "Будет открыт файл train.txt, в котором на каждой новой строке располагается цифра 1 или 2, соответствующая типу вагона.";
    ifstream file("train.txt");
    string line;
    while (getline(file, line)) {
        try {
            int type = stoi(line);
            if ((type == 1) or (type == 2)) {
                train.push(type);
            }
        }
        catch (const invalid_argument& e) {
            cerr << "Ошибка преобразования строки в число" << endl;
        }
    }
    file.close();
}

void print_stack(stack <int> to_print) {
    stack <int> copy = to_print;
    int s = to_print.size();
    string res = "";
    for (int el = 1; el <= s; el++) {
        res += to_string(copy.top());
        copy.pop();
    }
    cout << res << endl;
}


int main()
{
    setlocale(LC_ALL, "Russian");
    int variable = 0;
    cout << "Исходные данные будут введены с клавиатуры (1) или считаны из файла (2):";
    cin >> variable;
    cout << endl;

    switch (variable)
    {
    case 1:
        Keyboard();
        break;
    case 2:
        File();
        break;
    default:
        cout << "Введен неверный номер. Нужно ввести 1 или 2." << endl;
        break;
    }

    while (train.size() != 0) {
        int van = train.top();
        if (van == 1) {
            type_one.push(van);
        }
        else {
            type_two.push(van);
        }
        train.pop();
    }

    cout << "Группа 1: ";
    print_stack(type_one);
    cout << "Группа 2: ";
    print_stack(type_two);
}
