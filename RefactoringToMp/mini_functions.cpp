#include "include.h"

//Принимает строку, разбивает на key,value и возвращает структуру
MyStruct sortKeyValue(string buffer)
{			MyStruct MpBlock;								
			int index_pos = buffer.find_first_of("=");		//Ищем индекс позиции где стоит символ '='
			MpBlock.key = buffer.substr(0, index_pos);		//Все что до символа '=' пишем в key
			MpBlock.value = buffer.substr(index_pos+1);		//Все что после символа '=' пишем в value						
			return MpBlock;
}

//Удаления пробелов из строки
void deleteSpacesInString(string& string)
{
    size_t strBegin=string.find_first_not_of(" \r\n");
    size_t strEnd=string.find_last_not_of(" \r\n");
    string.erase(strEnd+1, string.size() - strEnd);
    string.erase(0, strBegin);
}

//Добавляем у элемент вектора структуру(key,value)
void vector_add_KeyLabel_and_Value(vector<vector<MyStruct>>& my_vector, int index, string my_value)
{
			MyStruct KeyValue;
			KeyValue.key = "Label";
			KeyValue.value = my_value;
			my_vector[index].push_back(KeyValue);
}

void InfoOfTypesData(int all_points, int true_points, string type )
{
	int false_points = all_points - true_points;
    cout << "\t- " << all_points << " " << type << ": " << true_points << " обработано, " << false_points << " нет" << endl;
}

void info_message(vector<vector<MyStruct>>& img_str)
{
    string name;
    for (int i = 0; i < img_str[0].size();i++) {
        if (img_str[0][i].key == "Name") {
            name = img_str[0][i].value;
            break;
        }
    }
    if (name != "")
        cout << "Во время чтения файла .mp с именем " + name + ", было найдено:" << endl;
    else
        cout << "Во время чтения файла .mp было найдено:" << endl;
}