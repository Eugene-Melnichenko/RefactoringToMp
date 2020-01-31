#include "include.h"
#include "functions.h"

//Переобразование полигонов типов = 0x00(Неизвестный тип)
void edit_polygon_0x00_blocks(vector<vector<MyStruct>>& polygon_str, int ind, int prm, int& Polygon_0x00_true)
{
    int ind_label;
    bool key_label = false;
    string buffer_label;

    bool key_4_1 = false;  string buffer_4_1; //FEATURE_DESCRIPTION(Описание особенности)
    bool key_4_2 = false;  string buffer_4_2; //Status
    bool key_4_3 = false;  string buffer_4_3; //Category of Traffic Separation Scheme(Категория схемы разделения трафика)
    bool key_4_4 = false;  string buffer_4_4; //Orientation(Ориентировка)
    bool key_4_5 = false;  string buffer_4_5; //Information
    bool key_4_6 = false;  string buffer_4_6; //Category of anchorage(Категория якорной стоянки)

    bool value_4_1 = false; //F_D=Traffic Separation Scheme Roundabout(Схема развязки дорожного движения)
    bool value_4_2 = false; //F_D=Traffic Separation Scheme Lane part(Часть переулка Схема разделения движения)
    bool value_4_3 = false; //F_D=Traffic Separation Zone(Зона разделения движения)
    bool value_4_4 = false; //F_D=Fairway(Судовой ход)
    bool value_4_5 = false; //F_D=Anchorage area(Якорная зона)

    for (int x_4 = 0; x_4 < polygon_str[ind].size(); x_4++) {
        //buffer_label
        if (polygon_str[ind][x_4].key == "Label") {
            ind_label = x_4;
            key_label = true;
            buffer_label = polygon_str[ind][x_4].value;
        }
        //key = trye, false?
        if (polygon_str[ind][x_4].key == "FEATURE_DESCRIPTION") {
            buffer_4_1 = polygon_str[ind][x_4].value;
            key_4_1 = true;
        }
        if (polygon_str[ind][x_4].key == "STATUS - Status") {
            buffer_4_2 = polygon_str[ind][x_4].value;
            key_4_2 = true;
        }
        if (polygon_str[ind][x_4].key == "CATTSS - Category of Traffic Separation Scheme") {
            buffer_4_3 = polygon_str[ind][x_4].value;
            key_4_3 = true;
        }
        if (polygon_str[ind][x_4].key == "ORIENT - Orientation") {
            buffer_4_4 = polygon_str[ind][x_4].value;
            key_4_4 = true;
        }
        if (polygon_str[ind][x_4].key == "INFORM - Information") {
            buffer_4_5 = polygon_str[ind][x_4].value;
            key_4_5 = true;
        }
        if (polygon_str[ind][x_4].key == "CATACH - Category of anchorage") {
            buffer_4_6 = polygon_str[ind][x_4].value;
            key_4_6 = true;
        }
        //value = trye, false?
        if (polygon_str[ind][x_4].value == "Traffic Separation Scheme Roundabout")
            value_4_1 = true;
        if (polygon_str[ind][x_4].value == "Traffic Separation Scheme Lane part")
            value_4_2 = true;
        if (polygon_str[ind][x_4].value == "Traffic Separation Zone")
            value_4_3 = true;
        if (polygon_str[ind][x_4].value == "Fairway")
            value_4_4 = true;
        if (polygon_str[ind][x_4].value == "Anchorage area")
            value_4_5 = true;


        //1. if(0x54/Traffic Separation Scheme Roundabout = Схема развязки дорожного движения)
        if (key_4_1 && value_4_1) {
            string value;
            if (!key_label) {
                if (key_4_2 && key_4_3)
                    value = "Traffic Separation Scheme Roundabout(Status:" + buffer_4_2 + "; Category:" + buffer_4_3 + ")";
                else if (key_4_2 && !key_4_3)
                    value = "Traffic Separation Scheme Roundabout(Status:" + buffer_4_2 + ")";
                else if (!key_4_2 && key_4_3)
                    value = "Traffic Separation Scheme Roundabout(Category:" + buffer_4_3 + ")";
                else
                    value = "Traffic Separation Scheme Roundabout";
                vector_add_KeyLabel_and_Value(polygon_str, ind, value);
            }
            else if (key_label) {
                if (key_4_2 && key_4_3)
                    polygon_str[ind][ind_label].value = buffer_label + "(Status:" + buffer_4_2 + "; Category:" + buffer_4_3 + ")";
                else if (key_4_2 && !key_4_3)
                    polygon_str[ind][ind_label].value = buffer_label + "(Status:" + buffer_4_2 + ")";
                else if (!key_4_2 && key_4_3)
                    polygon_str[ind][ind_label].value = buffer_label + "(Category:" + buffer_4_3 + ")";
            }
            polygon_str[ind][prm].value = "0x0051";//TODO: Болото, но обязательно нужно, Схема развязки дорожного движения
            key_4_1 = false;
            key_4_2 = false;
            key_4_3 = false;
            value_4_1 = false;
            key_label = false;
            Polygon_0x00_true++;
            continue;
        }
        //2. if(0x00/Traffic Separation Scheme Lane part = Часть переулка Схема разделения движения)
        if (key_4_1 && value_4_2) {
            string value;
            if (!key_label) {
                if (key_4_2 && key_4_4)
                    value = "Traffic Separation Scheme Lane part(Status:" + buffer_4_2 + "; Orientation:" + buffer_4_4 + ")";
                else if (key_4_2 && !key_4_4)
                    value = "Traffic Separation Scheme Lane part(Status:" + buffer_4_2 + ")";
                else if (!key_4_2 && key_4_4)
                    value = "Traffic Separation Scheme Lane part(Orientation:" + buffer_4_4 + ")";
                else
                    value = "Traffic Separation Scheme Lane part";
                vector_add_KeyLabel_and_Value(polygon_str, ind, value);
            }
            else if (key_label) {
                if (key_4_2 && key_4_4)
                    polygon_str[ind][ind_label].value = buffer_label + "(Status:" + buffer_4_2 + "; Orientation: " + buffer_4_4 + ")";
                else if (key_4_2 && !key_4_4)
                    polygon_str[ind][ind_label].value = buffer_label + "(Status:" + buffer_4_2 + ")";
                else if (!key_4_2 && key_4_4)
                    polygon_str[ind][ind_label].value = buffer_label + "Orientation: " + buffer_4_4 + ")";
            }
            polygon_str[ind][prm].value = "0x0051";//TODO: Болото, но обязательно нужно, Схема развязки дорожного движения
            key_4_1 = false;
            key_4_2 = false;
            key_4_4 = false;
            value_4_2 = false;
            key_label = false;
            Polygon_0x00_true++;
            continue;
        }
        //3. if(0x00/Traffic Separation Zone = Зона разделения движения)
        if (key_4_1 && value_4_3) {
            string value;
            if (!key_label) {
                if (key_4_2 && key_4_3)
                    value = "Traffic Separation Scheme Lane part(Status:" + buffer_4_2 + "; Category:" + buffer_4_3 + ")";
                else if (key_4_2 && !key_4_3)
                    value = "Traffic Separation Scheme Lane part(Status:" + buffer_4_2 + ")";
                else if (!key_4_2 && key_4_3)
                    value = "Traffic Separation Scheme Lane part(Category:" + buffer_4_3 + ")";
                else
                    value = "Traffic Separation Scheme Lane part";
                vector_add_KeyLabel_and_Value(polygon_str, ind, value);
            }
            else if (key_label) {
                if (key_4_2 && key_4_3)
                    polygon_str[ind][ind_label].value = buffer_label + "(Status:" + buffer_4_2 + "; Category: " + buffer_4_3 + ")";
                else if (key_4_2 && !key_4_3)
                    polygon_str[ind][ind_label].value = buffer_label + "(Status:" + buffer_4_2 + ")";
                else if (!key_4_2 && key_4_3)
                    polygon_str[ind][ind_label].value = buffer_label + "(Category: " + buffer_4_3 + ")";
            }
            polygon_str[ind][prm].value = "0x0051";//TODO: Болото, но обязательно нужно, Часть переулка, Схема разделения движения
            key_4_1 = false;
            key_4_2 = false;
            key_4_3 = false;
            value_4_3 = false;
            key_label = false;
            Polygon_0x00_true++;
            continue;
        }
        //4. if(0x00/Fairway = Судовой ход)
        if (key_4_1 && value_4_4) {
            string value;
            if (!key_label) {
                if (key_4_2 && key_4_5)
                    value = "Fairway(Status:" + buffer_4_2 + ", Information:" + buffer_4_5 + ")";
                else if (!key_4_2 && key_4_5)
                    value = "Fairway(Information:" + buffer_4_5 + ")";
                else if (key_4_2 && !key_4_5)
                    value = "Fairway(Status:" + buffer_4_2 + ")";
                else
                    value = "Fairway";
                vector_add_KeyLabel_and_Value(polygon_str, ind, value);
            }
            else if (key_label) {
                if (key_4_2 && key_4_5)
                    polygon_str[ind][ind_label].value = "Fairway(" + buffer_label + ", Status:" + buffer_4_2 + ", Information:" + buffer_4_5 + ")";
                else if (!key_4_2 && key_4_5)
                    polygon_str[ind][ind_label].value = "Fairway(" + buffer_label + ", Information:" + buffer_4_5 + ")";
                else if (key_4_2 && !key_4_5)
                    polygon_str[ind][ind_label].value = "Fairway(" + buffer_label + ", Status:" + buffer_4_2 + ")";
                else
                    polygon_str[ind][ind_label].value = "Fairway(" + buffer_label + ")";
            }
            polygon_str[ind][prm].value = "0x0051";//TODO: Болото, но обязательно нужно, Судовой ход
            key_4_1 = false;
            key_4_2 = false;
            key_4_5 = false;
            value_4_4 = false;
            key_label = false;
            Polygon_0x00_true++;
            continue;
        }
        //5. if(0x00/Anchorage area = Якорная зона)
        if (key_4_1 && value_4_5) {
            string value;
            if (!key_label) {
                if (key_4_2 && key_4_6)
                    value = "Anchorage area(Status:" + buffer_4_2 + ", Category :" + buffer_4_6 + ")";
                else if (!key_4_2 && key_4_6)
                    value = "Anchorage area(Category:" + buffer_4_6 + ")";
                else if (key_4_2 && !key_4_6)
                    value = "Anchorage area(Status:" + buffer_4_2 + ")";
                else
                    value = "Fairway";
                vector_add_KeyLabel_and_Value(polygon_str, ind, value);
            }
            else if (key_label) {
                if (key_4_2 && key_4_6)
                    polygon_str[ind][ind_label].value = "Anchorage area(" + buffer_label + ", Status:" + buffer_4_2 + ", Category:" + buffer_4_6 + ")";
                else if (!key_4_2 && key_4_6)
                    polygon_str[ind][ind_label].value = "Anchorage area(" + buffer_label + ", Category:" + buffer_4_6 + ")";
                else if (key_4_2 && !key_4_6)
                    polygon_str[ind][ind_label].value = "Anchorage area(" + buffer_label + ", Status:" + buffer_4_2 + ")";
                else
                    polygon_str[ind][ind_label].value = "Anchorage area(" + buffer_label + ")";
            }
            polygon_str[ind][prm].value = "0x0051";//TODO: Болото, но обязательно нужно, Якорная зона
            key_4_1 = false;
            key_4_2 = false;
            key_4_6 = false;
            value_4_5 = false;
            key_label = false;
            Polygon_0x00_true++;
            continue;
        }

    }
}//Конце Переобразование полигонов типов = 0x00(Неизвестный тип)