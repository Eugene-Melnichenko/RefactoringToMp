#include "include.h"
#include "functions.h"

void sort_str_ByVectors(vector<string>& strings,
                        vector<vector<MyStruct>>& img_str,
                        vector<vector<MyStruct>>& poi_str,
                        vector<vector<MyStruct>>& polyline_str,
                        vector<vector<MyStruct>>& polygon_str
)
{

    bool save_ImgId = false;
    bool save_POI = false;
    bool save_POLYLINE = false;
    bool save_POLYGON = false;

    string buffer;
    vector<MyStruct> strOneBlock;//Структура одного блока, со значениями

    //Цикл перебирает каждую строку и распределяет по векторам
    for (int str = 0; str < strings.size(); str++) {

        buffer.clear();
        buffer = strings[str];

        //Чтения строк[IMG ID], запись подходящих значений у вектор "img_str"
        if (buffer == "[IMG ID]") { save_ImgId = true; strOneBlock.clear(); continue; }
        if (save_ImgId == true) {
            if (buffer == "[END-IMG ID]") {
                save_ImgId = false;
                img_str.push_back(strOneBlock);
                continue;
            }
            //у "strOneBlock".передаем(sortKeyValue(которая принимает строку, разбивает на key,value));
            strOneBlock.push_back(sortKeyValue(buffer));
        }

        //Чтения строк[POI], запись подходящих значений у вектор "poi_str"
        if (buffer == "[POI]") { save_POI = true; strOneBlock.clear(); continue; }
        if (save_POI == true) {
            if (buffer == "[END]") {
                save_POI = false;
                poi_str.push_back(strOneBlock);
                continue;
            }
            strOneBlock.push_back(sortKeyValue(buffer));
        }

        //Чтения строк[POLYLINE], запись подходящих значений у вектор "polyline_str"
        if (buffer == "[POLYLINE]") { save_POLYLINE = true; strOneBlock.clear(); continue; }
        if (save_POLYLINE == true) {
            if (buffer == "[END]") {
                save_POLYLINE = false;
                polyline_str.push_back(strOneBlock);
                continue;
            }
            strOneBlock.push_back(sortKeyValue(buffer));
        }

        //Чтения строк[POLYGON], запись подходящих значений у вектор "polygon_str"
        if (buffer == "[POLYGON]") { save_POLYGON = true; strOneBlock.clear(); continue; }
        if (save_POLYGON == true) {
            if (buffer == "[END]") {
                save_POLYGON = false;
                polygon_str.push_back(strOneBlock);
                continue;
            }
            strOneBlock.push_back(sortKeyValue(buffer));
        }
    }

    cout << "................................................................................" << endl;
}