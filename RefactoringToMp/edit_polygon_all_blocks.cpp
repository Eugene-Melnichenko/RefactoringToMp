#include "include.h"
#include "functions.h"

void edit_POLYGON_blocks(vector<vector<MyStruct>>& polygon_str)
{
    int AllUnkAreaType = 0;          //Загальное количество найденных полигонов типа(Unknown Area Type)
    int UnkAreaType_true = 0;        //Количество обработаных полигонов типа(Unknown Area Type)
    int UnkAreaType_false = 0;       //Количество не обработаных полигонов типа(Unknown Area Type)

    int All_MarineInfoArea_Type = 0; //Загальное количество найденных полигонов типа(Marine Info Area(Морская информационная зона))
    int MarineInfoArea_true = 0;     //Количество обработаных полигонов типа(Marine Info Area(Морская информационная зона))
    int MarineInfoArea_false = 0;    //Количество не обработаных полигонов типа(Marine Info Area(Морская информационная зона))

    int All_Polygon_0x54_Type = 0;   //Загальное количество найденных полигонов типа(0x54(Неизвестный тип))
    int Polygon_0x54_true = 0;       //Количество обработаных полигонов типа(0x54(Неизвестный тип))
    int Polygon_0x54_false = 0;      //Количество не обработаных полигонов типа(0x54(Неизвестный тип))

    int All_Polygon_0x00_Type = 0;   //Загальное количество найденных полигонов типа(0x54(Неизвестный тип))
    int Polygon_0x00_true = 0;       //Количество обработаных полигонов типа(0x54(Неизвестный тип))
    int Polygon_0x00_false = 0;      //Количество не обработаных полигонов типа(0x54(Неизвестный тип))

    for (int ind = 0; ind < polygon_str.size(); ind++) {
        for (int prm = 0; prm < polygon_str[ind].size(); prm++) {

            //1.Переобразование полигонов типов = Unknown Area Type(Неизвестный тип области)
            if (polygon_str[ind][prm].key == "Type" && polygon_str[ind][prm].value == "Unknown Area Type") {
                AllUnkAreaType++;
                edit_polygon_U_A_T_blocks(polygon_str, ind, prm, UnkAreaType_true);
            }

            //2.Переобразование полигонов типов = Marine Info Area(Морская информационная зона)
            if (polygon_str[ind][prm].key == "Type" && polygon_str[ind][prm].value == "Marine Info Area") {
                All_MarineInfoArea_Type++;
                edit_polygon_M_I_A_blocks(polygon_str, ind, prm, MarineInfoArea_true);
            }

            //3.Переобразование полигонов типов = 0x54(Неизвестный тип)
            if (polygon_str[ind][prm].key == "Type" && polygon_str[ind][prm].value == "0x54") {
                All_Polygon_0x54_Type++;
                edit_polygon_0x54_blocks(polygon_str, ind, prm, Polygon_0x54_true);
            }

            //4.Переобразование полигонов типов = 0x00(Неизвестный тип)
            if (polygon_str[ind][prm].key == "Type" && polygon_str[ind][prm].value == "0x00") {
                All_Polygon_0x00_Type++;
                edit_polygon_0x00_blocks(polygon_str, ind, prm, Polygon_0x00_true);
            }
        }
    }
    InfoOfTypesData(AllUnkAreaType, UnkAreaType_true, "полигонов типа Unknown Area Type");
    InfoOfTypesData(All_MarineInfoArea_Type, MarineInfoArea_true, "полигонов типа Marine Info Area");
    InfoOfTypesData(All_Polygon_0x54_Type, Polygon_0x54_true, "полигонов типа 0x54");
    InfoOfTypesData(All_Polygon_0x00_Type, Polygon_0x00_true, "полигонов типа 0x00");
}