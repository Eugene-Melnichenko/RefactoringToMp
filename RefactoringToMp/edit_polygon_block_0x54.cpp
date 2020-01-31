#include "include.h"
#include "functions.h"

//Переобразование полигонов типов = 0x54(Неизвестный тип)
void edit_polygon_0x54_blocks(vector<vector<MyStruct>>& polygon_str, int ind, int prm, int& Polygon_0x54_true)
{
    int ind_label;
    bool key_label = false;
    string buffer_label;

    bool key_3_1 = false;  string buffer_3_1; //FEATURE_DESCRIPTION
    bool key_3_3 = false;  string buffer_3_3; //CATLND - Category of land region(Категория земельного участка)
    bool key_3_4 = false;  string buffer_3_4; //NATSUR - Nature of surface(Природа поверхности)

    bool value_3_1 = false; //F_D=Land region(Земельный участок)
    bool value_3_2 = false; //F_D=Land area(Площадь земельного участка)

    for (int x_3 = 0; x_3 < polygon_str[ind].size(); x_3++) {
        if (polygon_str[ind][x_3].key == "Label") {
            ind_label = x_3;
            key_label = true;
            buffer_label = polygon_str[ind][x_3].value;
        }
        //key = trye, false?
        if (polygon_str[ind][x_3].key == "FEATURE_DESCRIPTION") {
            buffer_3_1 = polygon_str[ind][x_3].value;
            key_3_1 = true;
        }
        if (polygon_str[ind][x_3].key == "CATLND - Category of land region") {
            buffer_3_3 = polygon_str[ind][x_3].value;
            key_3_3 = true;
        }
        if (polygon_str[ind][x_3].key == "NATSUR - Nature of surface") {
            buffer_3_4 = polygon_str[ind][x_3].value;
            key_3_4 = true;
        }
        //value = trye, false?
        if (polygon_str[ind][x_3].value == "Land region")
            value_3_1 = true;
        if (polygon_str[ind][x_3].value == "Land area")
            value_3_2 = true;

        //1. if(0x54/Land region = земельный участок)
        if (key_3_1 && !key_3_3 && !key_3_4 && value_3_1) {
            if (!key_label) {
                string value = "Land region";
                vector_add_KeyLabel_and_Value(polygon_str, ind, value);
            }
            polygon_str[ind][prm].value = "0x0002";//Населений пункт < 200К
            key_3_1 = false;
            value_3_1 = false;
            Polygon_0x54_true++;
            continue;
        }
        //2. if(0x54/Land region = Какой то земельный участок)
        if (key_3_1 && key_3_3 && value_3_1) {
            string value;
            bool lowlands = buffer_3_3.find("(lowlands)") != string::npos;//Долина, равнина
            bool marsh = buffer_3_3.find("(marsh)") != string::npos; //Болото
            bool swamp = buffer_3_3.find("(swamp)") != string::npos; //Болото
            bool fen = buffer_3_3.find("(fen)") != string::npos; //Болото
            if (!key_label) {
                if (lowlands) {
                    value = "Land region(" + buffer_3_3 + ")";
                    vector_add_KeyLabel_and_Value(polygon_str, ind, value);
                    polygon_str[ind][prm].value = "0x004f"; //Поросль леса
                    Polygon_0x54_true++;
                }
                else if (marsh || swamp || fen) {
                    value = buffer_3_3; //Болото
                    vector_add_KeyLabel_and_Value(polygon_str, ind, value);
                    polygon_str[ind][prm].value = "0x0051";//Болото
                    Polygon_0x54_true++;
                }
                else
                {
                    value = "Land region";
                    vector_add_KeyLabel_and_Value(polygon_str, ind, value);
                    polygon_str[ind][prm].value = "0x0002"; //Населений пункт < 200К
                    Polygon_0x54_true++;
                }
            }
            else if (key_label) {
                polygon_str[ind][prm].value = "0x0002"; //Населений пункт < 200К
                Polygon_0x54_true++;
            }
            key_3_1 = false;
            key_3_3 = false;
            value_3_1 = false;
            continue;
        }
        //3. if(0x54/Land region = Какой то земельный участок)
        if (!key_label && key_3_1 && !key_3_3 && key_3_4 && value_3_1) {
            string value;
            bool sand = buffer_3_4.find("(sand)") != string::npos;//песок
            bool stone = buffer_3_4.find("(stone)") != string::npos;//камень
            bool sand_and_stone = (buffer_3_4.find("(sand)") != string::npos) && (buffer_3_4.find("(stone)") != string::npos); //песок и камень
            bool pebbles = buffer_3_4.find("(pebbles)") != string::npos; //булыжники, камешки

            if (sand_and_stone) {
                value = "Land region(" + buffer_3_4 + ")"; //песок и камень
                vector_add_KeyLabel_and_Value(polygon_str, ind, value);
                polygon_str[ind][prm].value = "0x0003";//TODO: Застройка сельского типа, но нужен песок и камень.
                Polygon_0x54_true++;
            }
            else if (sand && !stone) { //песок
                value = "Land region(" + buffer_3_4 + ")";
                vector_add_KeyLabel_and_Value(polygon_str, ind, value);
                polygon_str[ind][prm].value = "0x0003";//TODO: Застройка сельского типа, но нужен песок.
                Polygon_0x54_true++;
            }
            else if (stone && !sand) { //камень
                value = "Land region(" + buffer_3_4 + ")";
                vector_add_KeyLabel_and_Value(polygon_str, ind, value);
                polygon_str[ind][prm].value = "0x0003";//TODO: Застройка сельского типа, но нужен камень.
                Polygon_0x54_true++;
            }
            else if (pebbles) { //булыжники, камешки
                value = "Land region(" + buffer_3_4 + ")";
                vector_add_KeyLabel_and_Value(polygon_str, ind, value);
                polygon_str[ind][prm].value = "0x0003";//TODO: Застройка сельского типа, но нужено булыжники, камешки.
                Polygon_0x54_true++;
            }

            key_3_1 = false;
            key_3_4 = false;
            value_3_1 = false;
            continue;
        }
        //4. if(0x54/Land area = Площадь земельного участка)
        if (key_3_1 && value_3_2 && !key_3_3 && !key_3_4) {
            if (!key_label)
                polygon_str[ind][prm].value = "0x004a"; //Область выделения карты
            else if (key_label)
                polygon_str[ind][prm].value = "0x0002"; //Населений пункт < 200К
            key_3_1 = false;
            value_3_2 = false;
            key_label = false;
            Polygon_0x54_true++;
            continue;
        }
    }
}