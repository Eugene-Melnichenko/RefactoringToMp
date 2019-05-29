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