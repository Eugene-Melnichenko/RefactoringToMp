#include "include.h"

void destroy_KeyValue(string key, vector<vector<MyStruct>>& img_str);
void create_KeyValue(string key, string value, vector<vector<MyStruct>>& img_str);

void edit_img_block(vector<vector<MyStruct>>& img_str)
{
	//Удаляем из блока img_str не нужные параметры
    destroy_KeyValue("Elevation", img_str);
	destroy_KeyValue("Level", img_str);
	destroy_KeyValue("Zoom", img_str);
	//Добавления в блок img_str нужные параметры
    create_KeyValue("Elevation", "M", img_str);

	create_KeyValue("Levels","2",img_str);
	create_KeyValue("Level0","22",img_str);
	create_KeyValue("Level1","20",img_str);

	create_KeyValue("Zoom0","0",img_str);
	create_KeyValue("Zoom1","1",img_str);
}

void destroy_KeyValue(string key, vector<vector<MyStruct>>& img_str)
{
	for(int i = 0; i < img_str[0].size();){
		int key_index = img_str[0][i].key.find(key);
		//Если значения(Не Не) найдено
		if (key_index != -1)
		{
			i = img_str[0].erase(img_str[0].begin()+i)- img_str[0].begin(); //Удаления елемента из вектора
		}
		else 
			i++;
	}
}

void create_KeyValue(string key, string value, vector<vector<MyStruct>>& img_str)
{
    MyStruct MpStrImg;
    MpStrImg.key = key;
    MpStrImg.value = value;
    img_str[0].push_back(MpStrImg);
}
