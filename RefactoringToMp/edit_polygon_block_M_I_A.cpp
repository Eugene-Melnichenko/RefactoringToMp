#include "include.h"
#include "functions.h"

//Переобразование полигонов типов = Marine Info Area(Морская информационная зона)
void edit_polygon_M_I_A_blocks(vector<vector<MyStruct>>& polygon_str, int ind, int prm, int& MarineInfoArea_true)
{

    int ind_label;
    bool key_label = false;
    string buffer_label;

    bool key_2_1 = false;  string buffer_2_1; //FEATURE_DESCRIPTION
    bool key_2_2 = false;  string buffer_2_2; //Category of restricted area(Категория запретной зоны)
    bool key_2_3 = false;  string buffer_2_3; //Status
    bool key_2_4 = false;  string buffer_2_4; //Information
    bool key_2_5 = false;  string buffer_2_5; //Category of dumping ground(Категория свалки)
    bool key_2_6 = false;  string buffer_2_6; //Water level effect(Эффект уровня воды)
    bool key_2_7 = false;  string buffer_2_7; //Category of wreck(Категория крушения)

    bool value_2_1 = false; //F_D=Restricted area(Запретная зона)
    bool value_2_2 = false; //F_D=Military practice area(Военно-тренировочная площадка)
    bool value_2_3 = false; //F_D=Caution area(Область предостережения)
    bool value_2_4 = false; //F_D=Dumping ground(Место свалки)
    bool value_2_5 = false; //F_D=Obstruction(Препятствие)
    bool value_2_6 = false; //F_D=Unsurveyed area(Необследованная территория)
    bool value_2_7 = false; //F_D=Precautionary area(Предупредительная зона)
    bool value_2_8 = false; //F_D=Fishing ground(Рыболовная площадка)
    bool value_2_9 = false; //F_D=Wreck(Развалина)

    for (int x_2 = 0; x_2 < polygon_str[ind].size(); x_2++) {
        if (polygon_str[ind][x_2].key == "Label") {
            ind_label = x_2;
            key_label = true;
            buffer_label = polygon_str[ind][x_2].value;
        }
        //key = trye, false?
        if (polygon_str[ind][x_2].key == "FEATURE_DESCRIPTION") {
            buffer_2_1 = polygon_str[ind][x_2].value;
            key_2_1 = true;
        }
        if (polygon_str[ind][x_2].key == "CATREA - Category of restricted area") {
            buffer_2_2 = polygon_str[ind][x_2].value;
            key_2_2 = true;
        }
        if (polygon_str[ind][x_2].key == "STATUS - Status") {
            buffer_2_3 = polygon_str[ind][x_2].value;
            key_2_3 = true;
        }
        if (polygon_str[ind][x_2].key == "INFORM - Information") {
            buffer_2_4 = polygon_str[ind][x_2].value;
            key_2_4 = true;
        }
        if (polygon_str[ind][x_2].key == "CATDPG - Category of dumping ground") {
            buffer_2_5 = polygon_str[ind][x_2].value;
            key_2_5 = true;
        }
        if (polygon_str[ind][x_2].key == "WATLEV - Water level effect") {
            buffer_2_6 = polygon_str[ind][x_2].value;
            key_2_6 = true;
        }
        if (polygon_str[ind][x_2].key == "CATWRK - Category of wreck") {
            buffer_2_7 = polygon_str[ind][x_2].value;
            key_2_7 = true;
        }
        //value = trye, false?
        if (polygon_str[ind][x_2].value == "Restricted area")
            value_2_1 = true;
        if (polygon_str[ind][x_2].value == "Military practice area")
            value_2_2 = true;
        if (polygon_str[ind][x_2].value == "Caution area")
            value_2_3 = true;
        if (polygon_str[ind][x_2].value == "Dumping ground")
            value_2_4 = true;
        if (polygon_str[ind][x_2].value == "Obstruction")
            value_2_5 = true;
        if (polygon_str[ind][x_2].value == "Unsurveyed area")
            value_2_6 = true;
        if (polygon_str[ind][x_2].value == "Precautionary area")
            value_2_7 = true;
        if (polygon_str[ind][x_2].value == "Fishing ground")
            value_2_8 = true;
        if (polygon_str[ind][x_2].value == "Wreck")
            value_2_9 = true;

        //1. if(Marine Info Area/Restricted area = запретная зона)
        if (key_2_1 && value_2_1) {
            string value;
            if (!key_label) {
                if (key_2_2 && key_2_3)
                    value = "Restricted area(Category:" + buffer_2_2 + ",Status:" + buffer_2_3 + ")";
                else if (!key_2_2 && key_2_3)
                    value = "Restricted area(Status:" + buffer_2_3 + ")";
                else if (key_2_2 && !key_2_3)
                    value = "Restricted area(Category:" + buffer_2_2 + ")";
                else if (!key_2_2 && !key_2_3)
                    value = "Restricted area";
                vector_add_KeyLabel_and_Value(polygon_str, ind, value);
            }
            else if (key_label) {
                if (key_2_2 && key_2_3)
                    polygon_str[ind][ind_label].value = "Restricted area(" + buffer_label + ",Category:" + buffer_2_2 + ",Status:" + buffer_2_3 + ")";
                else if (!key_2_2 && key_2_3)
                    polygon_str[ind][ind_label].value = "Restricted area(" + buffer_label + ",Status:" + buffer_2_3 + ")";
                else if (key_2_2 && !key_2_3)
                    polygon_str[ind][ind_label].value = "Restricted area(" + buffer_label + ",Category:" + buffer_2_2 + ")";
                else if (!key_2_2 && !key_2_3)
                    polygon_str[ind][ind_label].value = "Restricted area";
            }
            polygon_str[ind][prm].value = "0x0053";//TODO: Мель, но обязательно нужно, запретная зона
            key_2_1 = false;
            key_2_2 = false;
            key_2_3 = false;
            value_2_1 = false;
            MarineInfoArea_true++;
            continue;
        }
        //2. if(M.I.A./Military practice area = военно-тренировочная площадка)
        if (key_2_1 && value_2_2) {
            if (!key_label) {
                string value = "Military practice area";
                vector_add_KeyLabel_and_Value(polygon_str, ind, value);
            }
            polygon_str[ind][prm].value = "0x0053";//TODO: Мель, но обязательно нужно, военно-тренировочная площадка
            key_2_1 = false;
            value_2_2 = false;
            MarineInfoArea_true++;
            continue;

        }
        //3. if(M.I.A./Caution area = область предостережения)
        if (key_2_1 && value_2_3) {
            string value;
            if (!key_label) {
                if (key_2_4)
                    value = "Caution area(Information:" + buffer_2_4 + ")";
                else if (!key_2_4)
                    value = "Caution area";
                vector_add_KeyLabel_and_Value(polygon_str, ind, value);
            }
            else if (key_label) {
                if (key_2_4)
                    polygon_str[ind][ind_label].value = "Caution area(" + buffer_label + ",Information:" + buffer_2_4 + ")";
                else if (!key_2_4)
                    polygon_str[ind][ind_label].value = "Caution area(" + buffer_label + ")";
            }
            polygon_str[ind][prm].value = "0x0053";//TODO: Мель, но обязательно нужно, область предостережения
            key_2_1 = false;
            key_2_4 = false;
            value_2_3 = false;
            MarineInfoArea_true++;
            continue;
        }
        //4. if(M.I.A./Dumping ground = Место свалки)
        if (key_2_1 && value_2_4) {
            string value;
            if (!key_label) {
                if (key_2_5 && key_2_3)
                    value = "Dumping ground(Category:" + buffer_2_5 + ",Status:" + buffer_2_3 + ")";
                else if (!key_2_5 && key_2_3)
                    value = "Dumping ground(Status:" + buffer_2_5 + ")";
                else if (key_2_5 && !key_2_3)
                    value = "Dumping ground(Category:" + buffer_2_2 + ")";
                else if (!key_2_5 && !key_2_3 && key_2_4)
                    value = "Dumping ground(Category:" + buffer_2_4 + ")";
                else
                    value = "Dumping ground";
                vector_add_KeyLabel_and_Value(polygon_str, ind, value);
            }
            polygon_str[ind][prm].value = "0x0053";//TODO: Мель, но обязательно нужно, Место свалки
            key_2_3 = false;
            key_2_4 = false;
            key_2_5 = false;
            value_2_4 = false;
            MarineInfoArea_true++;
            continue;
        }
        //5. if(M.I.A./Obstruction = Препятствие)
        if (key_2_1 && value_2_5) {
            string value;
            if (!key_label) {
                if (!key_2_6)
                    value = "Obstruction(" + buffer_2_6 + ")";
                else
                    value = "Obstruction";
                vector_add_KeyLabel_and_Value(polygon_str, ind, value);
            }
            polygon_str[ind][prm].value = "0x0053";//TODO: Мель, но обязательно нужно, Препятствие
            key_2_1 = false;
            key_2_6 = false;
            value_2_5 = false;
            MarineInfoArea_true++;
            continue;
        }
        //6. if(M.I.A./Unsurveyed area = Необследованная территория)
        if (key_2_1 && value_2_6) {
            if (!key_label) {
                string value = "Unsurveyed area";
                vector_add_KeyLabel_and_Value(polygon_str, ind, value);
            }
            polygon_str[ind][prm].value = "0x0053";//TODO: Мель, но обязательно нужно, Необследованная территория
            key_2_1 = false;
            value_2_6 = false;
            MarineInfoArea_true++;
            continue;
        }
        //7. if(M.I.A./Precautionary area = Предупредительная зона)
        if (key_2_1 && value_2_7) {
            string value;
            if (!key_label) {
                if (key_2_3 && key_2_4)
                    value = "Precautionary area(Status:" + buffer_2_3 + ", Information:" + buffer_2_4 + ")";
                else if (!key_2_3 && key_2_4)
                    value = "Precautionary area(Information:" + buffer_2_4 + ")";
                else if (key_2_3 && !key_2_4)
                    value = "Precautionary area(Status:" + buffer_2_3 + ")";
                else
                    value = "Precautionary area";
                vector_add_KeyLabel_and_Value(polygon_str, ind, value);
            }
            else if (key_label) {
                polygon_str[ind][ind_label].value = "Precautionary area(" + buffer_label + ")";
            }
            polygon_str[ind][prm].value = "0x0053";//TODO: Мель, но обязательно нужно, Предупредительная зона
            key_2_1 = false;
            key_2_3 = false;
            key_2_4 = false;
            value_2_7 = false;
            MarineInfoArea_true++;
            continue;
        }
        //8. if(M.I.A./Fishing ground = Рыболовная площадка)
        if (key_2_1 && value_2_8) {
            string value;
            if (!key_label) {
                if (key_2_3 && key_2_4)
                    value = "Fishing ground(Status:" + buffer_2_3 + ", Information:" + buffer_2_4 + ")";
                else if (!key_2_3 && key_2_4)
                    value = "Fishing ground(Information:" + buffer_2_4 + ")";
                else if (key_2_3 && !key_2_4)
                    value = "Fishing ground(Status:" + buffer_2_3 + ")";
                else
                    value = "Fishing ground";
                vector_add_KeyLabel_and_Value(polygon_str, ind, value);
            }
            else if (key_label) {
                polygon_str[ind][ind_label].value = "Fishing ground(" + buffer_label + ")";
            }
            polygon_str[ind][prm].value = "0x0053";//TODO: Мель, но обязательно нужно, Рыболовная площадка
            key_2_1 = false;
            key_2_3 = false;
            key_2_4 = false;
            value_2_8 = false;
            MarineInfoArea_true++;
            continue;
        }
        //9. if(M.I.A./Wreck = Развалина)
        if (key_2_1 && value_2_9) {
            string value;
            if (!key_label) {
                if (key_2_6 && key_2_7)
                    value = "Wreck(Water level:" + buffer_2_6 + "; Category:" + buffer_2_7 + ")";
                else if (key_2_6 && !key_2_7)
                    value = "Wreck(Water level:" + buffer_2_6 + ")";
                else if (!key_2_6 && key_2_7)
                    value = "Wreck(Category:" + buffer_2_7 + ")";
                else
                    value = "Wreck";
                vector_add_KeyLabel_and_Value(polygon_str, ind, value);
            }
            else if (key_label) {
                polygon_str[ind][ind_label].value = "Wreck(" + buffer_label + ")";
            }
            polygon_str[ind][prm].value = "0x0053";//TODO: Мель, но обязательно нужно, Развалина
            key_2_1 = false;
            key_2_6 = false;
            key_2_7 = false;
            value_2_9 = false;
            MarineInfoArea_true++;
            continue;
        }
    }
}//Конец переобразование полигонов типов = Marine Info Area(Морская информационная зона)