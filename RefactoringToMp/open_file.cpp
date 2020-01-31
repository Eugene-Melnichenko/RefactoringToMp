#include "include.h"
#include "functions.h"

#include <algorithm> //для transform
#include <cctype> //для tolower

string get_name();

//Считывания файла(file) и запись строк в вектор(str)
void open_file(vector<string>& strings)
{
    string file = get_name();

    ifstream fin;

    fin.open(file, std::iostream::binary);
    string buffer;

    while (!fin.eof()) {
        buffer.clear();
        getline(fin, buffer);
        deleteSpacesInString(buffer);
        if (buffer == "[RGN10]") { buffer = "[POI]"; }
        strings.push_back(buffer);
    }

    fin.close();
}

//Получения имени файла для открытия
string get_name()
{
    string name_file;
    string format;
    ifstream open_file;

    cout << "Откройте файл с разрешением .mp" << endl;
    do {
        name_file.clear();
        getline(cin, name_file);

        if (name_file.empty())
            cout << "Файл не может не иметь имени! Введите имя файла с расширением .mp" << endl;
        else if (name_file.size() < 4)
            cout << "Файл должна иметь имя минимум с одним символом и расширениям .mp" << endl;
        else if (name_file.size() > 3) {
            format = name_file.substr(name_file.size() - 3);//берем последние три символа с name_file

            transform(format.begin(), format.end(), format.begin(), tolower); //Преобразование строки в верхний регистр

            if (format != ".mp")
                cout << "Файл должен иметь расширения .mp" << endl;
            else {
                open_file.open(name_file);
                if (!open_file.is_open())
                    cout << "При открытии файла возникла ошибка. Файла не существует либо он поврежден" << endl;
                else {
                    open_file.close();
                    break;
                }
            }
        }

    } while (true);

    return name_file;
}