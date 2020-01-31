#include <cstdlib> //Для system
#include "include.h"
#include "functions.h"

int main()
{
    setlocale(0, "");

    vector<string> get_StringsInFile;			//Все строки для открываемого файла
    vector<string> set_StringsInFile;			//Все строки для сохраняемого файла

    //блок<элемент блока(строка)<key,value>>
    vector<vector<MyStruct>> img_id;			//Блок  [IMG ID]	key=value 
    vector<vector<MyStruct>> all_POINTS;		//Блоки [POI]		key=value 
    vector<vector<MyStruct>> all_POLYLINES;		//Блоки [POLYLINE]	key=value	
    vector<vector<MyStruct>> all_POLYGON;		//Блоки [POLYGON]	key=value

    open_file(get_StringsInFile);	//Запись всех строк файла в get_StringsInFile

    //Сортировка всех строк вектора get_StringsInFile, по остальным векторам
    sort_str_ByVectors(get_StringsInFile, img_id, all_POINTS, all_POLYLINES, all_POLYGON);

    //Настройка параметов
    edit_img_block(img_id);
    info_message(img_id);
    //Изменения неопределенних value у Блоках
    edit_POLYGON_blocks(all_POLYGON);
    edit_POLYLINE_blocks(all_POLYLINES);
    edit_POI_blocks(all_POINTS);

    //Запись строк у set_StringsInFil для файла, из img_id, all_POINTS, all_POLYLINES, all_POLYGON
    sort_vectors_ForFile(set_StringsInFile, img_id, all_POINTS, all_POLYLINES, all_POLYGON);

    save_file(set_StringsInFile);//Из set_StringsInFile запись у файл всех строк

    system("pause");

    return 0;
}