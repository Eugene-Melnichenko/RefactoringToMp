#include "include.h"

#include <algorithm> //��� transform
#include <cctype> //��� tolower

string set_name();

//���������� ����� �������(strings) � �� ������ � ����(file)
void save_file(vector<string>& strings)
{
    string file = set_name();

    ofstream fout;

    fout.open(file);
    for (int i = 0; i < strings.size(); i++) {
        fout << strings[i] << endl;
    }

    fout.close();
    cout << "���� ������� �������" << endl;
}

//��������� ����� ����� ��� ��������
string set_name()
{
    string name_file;
    string format;
    ifstream open_file;

    cout << "................................................................................" << endl;
    cout << "��������� ���� � ����������� .mp" << endl;
    do {
        name_file.clear();
        getline(cin, name_file);
        transform(name_file.begin(), name_file.end(), name_file.begin(), tolower); //�������������� ������ � ������� �������

        if (name_file.empty())
            cout << "���� �� ����� �� ����� �����! ������� ��� ����� � ����������� .mp" << endl;
        else if (name_file.size() < 4)
            cout << "���� ������ ����� ��� ������� � ����� �������� � ����������� .mp" << endl;
        else if (name_file.size() > 3) {

            format = name_file.substr(name_file.size() - 3);//����� ��������� ��� ������� � name_file

            if (format != ".mp")
                cout << "���� ������ ����� ���������� .mp" << endl;
            else
                break;
        }

    } while (true);

    return name_file;
}