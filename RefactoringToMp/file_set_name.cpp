#include "include.h"

string file_set_name()
{
	string name_file;
	string format;
	ifstream open_file;

	cout << "�������� ���� � ����������� .mp" << endl;
	do {
		name_file.clear();
		getline(cin,name_file);

		if (name_file.empty())
			cout << "���� �� ����� �� ����� �����! ������� ��� ����� � ����������� .mp" << endl;
		else if (name_file.size() < 4)
			cout << "���� ������ ����� ��� ������� � ����� �������� � ����������� .mp" << endl;
		else if (name_file.size() > 3 )
		{
			format = name_file.substr(name_file.size()-3);//����� ��������� ��� ������� � name_file
			if(format != ".mp")
				cout << "���� ������ ����� ���������� .mp" << endl;
			else
				break;
		}

	} while(true);

	return name_file;
}