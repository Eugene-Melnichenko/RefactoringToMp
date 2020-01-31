#include "include.h"

#include <algorithm> //для transform
#include <cctype> //для tolower

string set_name();

//Считывания строк вектора(strings) и их запист в файл(file)
void save_file(vector<string>& strings)
{
    string file = set_name();

    ofstream fout;

    fout.open(file);
    for (int i = 0; i < strings.size(); i++) {
        fout << strings[i] << endl;
    }

    fout.close();
    cout << "Файл успешно записан" << endl;
}

//Установка имени файла для открытия
string set_name()
{
    string name_file;
    string format;
    ifstream open_file;

    cout << "................................................................................" << endl;
    cout << "Сохраните файл с разрешением .mp" << endl;
    do {
        name_file.clear();
        getline(cin, name_file);
        transform(name_file.begin(), name_file.end(), name_file.begin(), tolower); //Преобразование строки в верхний регистр

        if (name_file.empty())
            cout << "Файл не может не иметь имени! Введите имя файла с расширением .mp" << endl;
        else if (name_file.size() < 4)
            cout << "Файл должна иметь имя минимум с одним символом и расширениям .mp" << endl;
        else if (name_file.size() > 3) {

            format = name_file.substr(name_file.size() - 3);//берем последние три символа с name_file

            if (format != ".mp")
                cout << "Файл должен иметь расширения .mp" << endl;
            else
                break;
        }

    } while (true);

    return name_file;
}