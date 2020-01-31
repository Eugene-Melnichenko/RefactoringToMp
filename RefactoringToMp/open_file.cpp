#include "include.h"
#include "functions.h"

#include <algorithm> //��� transform
#include <cctype> //��� tolower

string get_name();

//���������� �����(file) � ������ ����� � ������(str)
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

//��������� ����� ����� ��� ��������
string get_name()
{
    string name_file;
    string format;
    ifstream open_file;

    cout << "�������� ���� � ����������� .mp" << endl;
    do {
        name_file.clear();
        getline(cin, name_file);

        if (name_file.empty())
            cout << "���� �� ����� �� ����� �����! ������� ��� ����� � ����������� .mp" << endl;
        else if (name_file.size() < 4)
            cout << "���� ������ ����� ��� ������� � ����� �������� � ����������� .mp" << endl;
        else if (name_file.size() > 3) {
            format = name_file.substr(name_file.size() - 3);//����� ��������� ��� ������� � name_file

            transform(format.begin(), format.end(), format.begin(), tolower); //�������������� ������ � ������� �������

            if (format != ".mp")
                cout << "���� ������ ����� ���������� .mp" << endl;
            else {
                open_file.open(name_file);
                if (!open_file.is_open())
                    cout << "��� �������� ����� �������� ������. ����� �� ���������� ���� �� ���������" << endl;
                else {
                    open_file.close();
                    break;
                }
            }
        }

    } while (true);

    return name_file;
}