#include "include.h"

string file_set_name()
{
	string name_file;
	string format;
	ifstream open_file;

	cout << "Откройте файл с разрешением .mp" << endl;
	do {
		name_file.clear();
		getline(cin,name_file);

		if (name_file.empty())
			cout << "Файл не может не иметь имени! Введите имя файла с расширением .mp" << endl;
		else if (name_file.size() < 4)
			cout << "Файл должна иметь имя минимум с одним символом и расширениям .mp" << endl;
		else if (name_file.size() > 3 )
		{
			format = name_file.substr(name_file.size()-3);//берем последние три символа с name_file
			if(format != ".mp")
				cout << "Файл должен иметь расширения .mp" << endl;
			else
				break;
		}

	} while(true);

	return name_file;
}