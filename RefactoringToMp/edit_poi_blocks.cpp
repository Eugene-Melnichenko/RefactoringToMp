#include "include.h"
#include "functions.h"
void edit_POI_blocks(vector<vector<MyStruct>>& poi_str)
{

    int AllUnkPoint = 0;   //Загальное количество найденных точек типа(Unknown Point Feature)
    int UnkPoint_true = 0; //Количество обработаных точек типа(Unknown Point Feature)
    int UnkPoint_false;    //Количество не обработаных точек типа(Unknown Point Feature)

    int All0x00_point = 0; //Загальное количество найденных точек типа(0x00(Тип не опредёлен))
    int P_0x00_true = 0;   //Количество обработаных точек типа(0x00(Тип не опредёлен))
    int P_0x00_false;      //Количество не обработаных точек типа(0x00(Тип не опредёлен))

    for (int ind = 0; ind < poi_str.size(); ind++) {
        for (int prm = 0; prm < poi_str[ind].size(); prm++) {

            //1.Переобразование точек типов = Unknown Point Feature(Неизвестная точка)
            if (poi_str[ind][prm].key == "Type" && poi_str[ind][prm].value == "Unknown Point Feature") {
                AllUnkPoint++;
                int ind_label;
                bool key_label = false;
                string buffer_label;

                bool key_1_1 = false;                      //FEATURE_DESCRIPTION(Описание особенности)
                bool key_1_3 = false;                      //Water level effect(Эффект уровня воды)
                bool key_1_4 = false;                      //Object name
                bool key_1_5 = false; string buffer_1_5;   //Category of slope(Категория склона)
                bool key_1_6 = false; string buffer_1_6;   //Category of landmark(Категория ориентира)
                bool key_1_7 = false; string buffer_1_7;   //Function
                bool key_1_8 = false; string buffer_1_8;   //Reference year for magnetic variation(Базовый год для магнитных вариаций)
                bool key_1_9 = false;                      //Value of annual change in magnetic variation(Значение годового изменения магнитного отклонения)
                bool key_1_10 = false; string buffer_1_10; //Value of magnetic variation(Значение магнитного отклонения)
                bool key_1_11 = false; string buffer_1_11; //Category of offshore platform(Категория морской платформы)
                bool key_1_12 = false; string buffer_1_12; //Category of silo/tank(Категория бункер/бак)
                bool key_1_13 = false; string buffer_1_13; //Topmark/daymark shape(Верхняя отметка/daymark shape)
                bool key_1_14 = false; string buffer_1_14; //Category of pilot boarding place(Категория места посадки пилота)
                bool key_1_15 = false; string buffer_1_15; //Category of mooring/warping facility(Категория причала)
                bool key_1_16 = false;                     //Status
                bool key_1_17 = false; string buffer_1_17; //Category of fog signal(Категория туманного сигнала)
                bool key_1_18 = false; string buffer_1_18; //Value of local magnetic anomaly(Значение локальной магнитной аномалии)
                bool key_1_19 = false; string buffer_1_19; //Information(Информация)
                bool key_1_20 = false; string buffer_1_20; //Category of dumping ground(Категория свалки)
                bool key_1_21 = false;                     //Source indication(Индикатор источника)
                bool key_1_22 = false;                     //Source date(Дата источника) 
                bool key_1_23 = false; string buffer_1_23; //Orientation(Ориентация)
                bool key_1_24 = false; string buffer_1_24; //Traffic flow(Транспортный поток)
                bool key_1_25 = false; string buffer_1_25; //Elevation(Высота)

                bool value_1_1 = false; //F_D=Land region(Земельный участок)
                bool value_1_2 = false; //F_D=Land area(Площадь земельного участка)
                bool value_1_3 = false; //F_D=Sloping ground(Наклонная площадь)
                bool value_1_4 = false; //hill(холм)
                bool value_1_5 = false; //F_D=Landmark(ориентир)
                bool value_1_6 = false; //tower(башня)
                bool value_1_7 = false; //mast(мачта)
                bool value_1_8 = false; //F_D=Magnetic variation(магнитная вариация)
                bool value_1_9 = false; //F_D=Offshore platform(морская платформа)
                bool value_1_10 = false; //F_D=Silo / tank(бункер/бак)				
                bool value_1_11 = false; //F_D=Obstruction(непроходимость)
                bool value_1_12 = false; //always under water/submerged(всегда под водой / погруженный)
                bool value_1_13 = false; //F_D=Top mark(Верхняя отметка)
                bool value_1_14 = false; //F_D=Pilot boarding place(Место посадки пилота)
                bool value_1_15 = false; //F_D=Mooring/warping facility(Причал / деформирование)
                bool value_1_16 = false; //F_D=Fog signal(Туманный сигнал)
                bool value_1_17 = false; //F_D=Weed/Kelp(Водоросли)
                bool value_1_18 = false; //F_D=Pile(Груда)
                bool value_1_19 = false; //F_D=Signal station, warning(Сигнальная станция, предупреждение)
                bool value_1_20 = false; //F_D=Signal station, traffic(Сигнальная станция, трафик)
                bool value_1_21 = false; //F_D=Local magnetic anomaly(Местная магнитная аномалия)
                bool value_1_22 = false; //F_D=The Dumping ground(Свалка)
                bool value_1_23 = false; //F_D=Radio calling-in point(Точка радиосвязи)
                bool value_1_24 = false; //F_D=Control point(Контрольная точка)
                bool value_1_25 = false; //F_D=Sea area/named water area(Морская зона / названная акватория)
                bool value_1_26 = false; //F_D=Rescue station(Спасательная станция)
                bool value_1_27 = false; //F_D=Caution area(Область предостережения)

                for (int x_1 = 0; x_1 < poi_str[ind].size(); x_1++) {
                    //buffer_label
                    if (poi_str[ind][x_1].key == "Label") {
                        ind_label = x_1;
                        key_label = true;
                        buffer_label = poi_str[ind][x_1].value;
                    }
                    //key = trye, false?
                    if (poi_str[ind][x_1].key == "FEATURE_DESCRIPTION")
                        key_1_1 = true;
                    if (poi_str[ind][x_1].key == "WATLEV - Water level effect")
                        key_1_3 = true;
                    if (poi_str[ind][x_1].key == "OBJNAM - Object name")
                        key_1_4 = true;
                    if (poi_str[ind][x_1].key == "CATSLO - Category of slope")
                        key_1_5 = true;
                    if (poi_str[ind][x_1].key == "CATLMK - Category of landmark") {
                        buffer_1_6 = poi_str[ind][x_1].value;
                        key_1_6 = true;
                    }
                    if (poi_str[ind][x_1].key == "FUNCTN - Function") {
                        buffer_1_7 = poi_str[ind][x_1].value;
                        key_1_7 = true;
                    }
                    if (poi_str[ind][x_1].key == "RYRMGV - Reference year for magnetic variation") {
                        buffer_1_8 = "year:" + poi_str[ind][x_1].value;
                        key_1_8 = true;
                    }
                    if (poi_str[ind][x_1].key == "VALACM - Value of annual change in magnetic variation")
                        key_1_9 = true;
                    if (poi_str[ind][x_1].key == "VALMAG - Value of magnetic variation") {
                        buffer_1_10 = "value:" + poi_str[ind][x_1].value;
                        key_1_10 = true;
                    }
                    if (poi_str[ind][x_1].key == "CATOFP - Category of offshore platform") {
                        buffer_1_11 = poi_str[ind][x_1].value;
                        key_1_11 = true;
                    }
                    if (poi_str[ind][x_1].key == "CATSIL - Category of silo/tank") {
                        buffer_1_12 = poi_str[ind][x_1].value;
                        key_1_12 = true;
                    }
                    if (poi_str[ind][x_1].key == "TOPSHP - Topmark/daymark shape") {
                        buffer_1_13 = poi_str[ind][x_1].value;
                        key_1_13 = true;
                    }
                    if (poi_str[ind][x_1].key == "CATPIL - Category of pilot boarding place") {
                        buffer_1_14 = poi_str[ind][x_1].value;
                        key_1_14 = true;
                    }
                    if (poi_str[ind][x_1].key == "CATMOR - Category of mooring/warping facility") {
                        buffer_1_15 = poi_str[ind][x_1].value;
                        key_1_15 = true;
                    }
                    if (poi_str[ind][x_1].key == "STATUS - Status")
                        key_1_16 = true;
                    if (poi_str[ind][x_1].key == "CATFOG - Category of fog signal") {
                        buffer_1_17 = poi_str[ind][x_1].value;
                        key_1_17 = true;
                    }
                    if (poi_str[ind][x_1].key == "VALLMA - Value of local magnetic anomaly") {
                        buffer_1_18 = poi_str[ind][x_1].value;
                        key_1_18 = true;
                    }
                    if (poi_str[ind][x_1].key == "INFORM - Information") {
                        buffer_1_19 = poi_str[ind][x_1].value;
                        key_1_19 = true;
                    }

                    if (poi_str[ind][x_1].key == "CATDPG - Category of dumping ground") {
                        buffer_1_20 = poi_str[ind][x_1].value;
                        key_1_20 = true;
                    }

                    if (poi_str[ind][x_1].key == "SORIND - Source indication")
                        key_1_21 = true;

                    if (poi_str[ind][x_1].key == "SORDAT - Source date")
                        key_1_22 = true;

                    if (poi_str[ind][x_1].key == "ORIENT - Orientation") {
                        buffer_1_23 = "Orien:" + poi_str[ind][x_1].value;
                        key_1_23 = true;
                    }
                    if (poi_str[ind][x_1].key == "TRAFIC - Traffic flow") {
                        buffer_1_24 = "Traffic flow:" + poi_str[ind][x_1].value;
                        key_1_24 = true;
                    }
                    if (poi_str[ind][x_1].key == "ELEVAT - Elevation") {
                        buffer_1_25 = "Elevation:" + poi_str[ind][x_1].value;
                        key_1_25 = true;
                    }
                    //value = trye, false?
                    if (poi_str[ind][x_1].value == "Land region")
                        value_1_1 = true;
                    if (poi_str[ind][x_1].value == "Land area")
                        value_1_2 = true;
                    if (poi_str[ind][x_1].value == "Sloping ground")
                        value_1_3 = true;
                    if (poi_str[ind][x_1].value.find("(hill)") != string::npos)
                        value_1_4 = true;
                    if (poi_str[ind][x_1].value == "Landmark")
                        value_1_5 = true;
                    if (poi_str[ind][x_1].value.find("(tower)") != string::npos)
                        value_1_6 = true;
                    if (poi_str[ind][x_1].value.find("(mast)") != string::npos)
                        value_1_7 = true;
                    if (poi_str[ind][x_1].value == "Magnetic variation")
                        value_1_8 = true;
                    if (poi_str[ind][x_1].value == "Offshore platform")
                        value_1_9 = true;
                    if (poi_str[ind][x_1].value == "Silo / tank")
                        value_1_10 = true;
                    if (poi_str[ind][x_1].value == "Obstruction")
                        value_1_11 = true;
                    if (poi_str[ind][x_1].value.find("(always under water/submerged)") != string::npos)
                        value_1_12 = true;
                    if (poi_str[ind][x_1].value == "Top mark")
                        value_1_13 = true;
                    if (poi_str[ind][x_1].value == "Pilot boarding place")
                        value_1_14 = true;
                    if (poi_str[ind][x_1].value == "Mooring/warping facility")
                        value_1_15 = true;
                    if (poi_str[ind][x_1].value == "Fog signal")
                        value_1_16 = true;
                    if (poi_str[ind][x_1].value == "Weed/Kelp")
                        value_1_17 = true;
                    if (poi_str[ind][x_1].value == "Pile")
                        value_1_18 = true;
                    if (poi_str[ind][x_1].value == "Signal station, warning")
                        value_1_19 = true;
                    if (poi_str[ind][x_1].value == "Signal station, traffic")
                        value_1_20 = true;
                    if (poi_str[ind][x_1].value == "Local magnetic anomaly")
                        value_1_21 = true;
                    if (poi_str[ind][x_1].value == "Dumping ground")
                        value_1_22 = true;
                    if (poi_str[ind][x_1].value == "Radio calling-in point")
                        value_1_23 = true;
                    if (poi_str[ind][x_1].value == "Control point")
                        value_1_24 = true;
                    if (poi_str[ind][x_1].value == "Sea area/named water area")
                        value_1_25 = true;
                    if (poi_str[ind][x_1].value == "Rescue station")
                        value_1_26 = true;
                    if (poi_str[ind][x_1].value == "Caution area")
                        value_1_27 = true;

                    //1. if(Unknown Point Feature/Label,Land region = Земельный участок)
                    if (key_label && key_1_1 && key_1_4 && value_1_1 && !value_1_2) {
                        poi_str[ind][prm].value = "0x0400";//Город 
                        key_label = false;
                        key_1_1 = false;
                        key_1_4 = false;
                        value_1_1 = false;
                        UnkPoint_true++;
                        continue;
                    }
                    //2. if(U.P.F./land area = Площадь земельного участка)
                    if (key_1_1 && value_1_2) {
                        if (key_label)
                            poi_str[ind][ind_label].value = "Land area(" + buffer_label + ")";
                        else if (!key_label) {
                            string value = "Land area(Rock)";//Площадь земельного участка(скала)
                            vector_add_KeyLabel_and_Value(poi_str, ind, value);
                        }
                        poi_str[ind][prm].value = "0x6614";//Скала
                        key_label = false;
                        key_1_1 = false;
                        value_1_2 = false;
                        UnkPoint_true++;
                        continue;
                    }
                    //3. if(U.P.F./Sloping ground,hill = Холм)
                    if (key_1_1 && key_1_5 && value_1_3 && value_1_4) {
                        if (key_label)
                            poi_str[ind][ind_label].value = "Hill, " + buffer_label;//Наклонная площадь(холм)
                        else if (!key_label) {
                            string value = "Sloping ground(hill)";//Наклонная площадь(холм)
                            vector_add_KeyLabel_and_Value(poi_str, ind, value);
                        }
                        poi_str[ind][prm].value = "0x6616";//Холм
                        key_label = false;
                        key_1_1 = false;
                        key_1_5 = false;
                        value_1_3 = false;
                        value_1_4 = false;
                        UnkPoint_true++;
                        continue;
                    }
                    //4. if(U.P.F./Category of landmark,Landmark = Ориентир)
                    if (key_1_1 && key_1_6 && value_1_5) {
                        string value;
                        if (key_1_7) {
                            if (key_label && key_1_4 && value_1_6)
                                poi_str[ind][ind_label].value = "Tower, " + buffer_label;
                            else if (!key_label && !key_1_4 && value_1_6) {
                                value = "Tower";
                                vector_add_KeyLabel_and_Value(poi_str, ind, value);
                            }
                            else if (key_label &&  key_1_4 && value_1_7)
                                poi_str[ind][ind_label].value = "Mast, " + buffer_label;
                            else if (!key_label && !key_1_4 && value_1_7) {
                                value = "Mast";
                                vector_add_KeyLabel_and_Value(poi_str, ind, value);
                            }
                            poi_str[ind][prm].value = "0x6411";//Башня, вышка
                        }
                        else if (!key_1_7) {
                            value = "Landmark(" + buffer_1_6 + ")";
                            vector_add_KeyLabel_and_Value(poi_str, ind, value);
                            poi_str[ind][prm].value = "0x160E";//Маяки
                        }
                        key_label = false;
                        key_1_1 = false;
                        key_1_4 = false;
                        key_1_6 = false;
                        value_1_5 = false;
                        value_1_6 = false;
                        value_1_7 = false;
                        UnkPoint_true++;
                        continue;
                    }
                    //5. if(U.P.F./Magnetic variation = Магнитная вариация)
                    if (key_1_1 && key_1_8 && key_1_9 && key_1_10 && value_1_8) {
                        string value;
                        if (!key_label) {
                            value = "Magnetic variation(" + buffer_1_8 + "," + buffer_1_10 + ")";
                            vector_add_KeyLabel_and_Value(poi_str, ind, value);
                        }
                        else if (key_label)
                            poi_str[ind][ind_label].value = buffer_label + "(" + buffer_1_8 + "," + buffer_1_10 + ")";

                        poi_str[ind][prm].value = "0x6500"; //TODO: Объект гидрографии, но нужно Магнитная вариация
                        key_label = false;
                        key_1_1 = false;
                        key_1_8 = false;
                        key_1_9 = false;
                        key_1_10 = false;
                        value_1_8 = false;
                        UnkPoint_true++;
                        continue;
                    }
                    //6. if(U.P.F./Offshore platform = морская платформа)
                    if (key_1_1 && value_1_9) {
                        string value;
                        if (key_label && key_1_11)
                            poi_str[ind][ind_label].value = buffer_label + "(" + buffer_1_11 + ")";
                        else if (!key_label && key_1_11) {
                            value = "Offshore platform(" + buffer_1_11 + ")";
                            vector_add_KeyLabel_and_Value(poi_str, ind, value);
                        }
                        else if (key_label && !key_1_11)
                            poi_str[ind][ind_label].value = "Offshore platform(" + buffer_label + ")";
                        else {
                            value = "Offshore platform";
                            vector_add_KeyLabel_and_Value(poi_str, ind, value);
                        }
                        poi_str[ind][prm].value = "0x6400";//Искусственное сооружение
                        key_label = false;
                        key_1_1 = false;
                        key_1_11 = false;
                        value_1_9 = false;
                        UnkPoint_true++;
                        continue;
                    }
                    //7. if(U.P.F./Category of silo/tank = Бункер/бак)
                    if (key_1_1 && key_1_12 && value_1_10) {
                        if (!key_label) {
                            string value = "Silo/tank. Category=" + buffer_1_12;
                            vector_add_KeyLabel_and_Value(poi_str, ind, value);
                        }
                        if (key_label) {
                            poi_str[ind][ind_label].value = "Silo/tank(" + buffer_label + ")";
                        }
                        poi_str[ind][prm].value = "0x4400";//Отдельные цистерны
                        key_label = false;
                        key_1_1 = false;
                        key_1_12 = false;
                        value_1_10 = false;
                        UnkPoint_true++;
                        continue;
                    }
                    //8. if(U.P.F./Obstruction = непроходимость)
                    if (key_1_1 && key_1_3 && value_1_11) {
                        string value;
                        if (value_1_12) {
                            if (key_label)
                                poi_str[ind][ind_label].value = "Obstruction(" + buffer_label + ")";
                            else if (!key_label) {
                                if (key_1_19) {
                                    value = "Obstruction(" + buffer_1_19 + ",submerged)";
                                }
                                else {
                                    value = "Obstruction(submerged)";
                                }
                                vector_add_KeyLabel_and_Value(poi_str, ind, value);
                            }
                            poi_str[ind][prm].value = "0x1c07";//препятствие, ниже уровня воды
                        }
                        else {
                            if (key_label)
                                poi_str[ind][ind_label].value = "Obstruction(" + buffer_label + ")";
                            else if (!key_label) {
                                value = "Obstruction";
                                vector_add_KeyLabel_and_Value(poi_str, ind, value);
                            }
                            poi_str[ind][prm].value = "0x1c06";//Препятствие на уровне воды
                        }
                        key_label = false;
                        key_1_1 = false;
                        key_1_3 = false;
                        value_1_11 = false;
                        value_1_12 = false;
                        UnkPoint_true++;
                        continue;
                    }
                    //9. if(U.P.F./Top mark = верхняя отметка)
                    if (key_1_1 && key_1_13 && value_1_13) {
                        if (!key_label) {
                            string value = "Top mark";
                            vector_add_KeyLabel_and_Value(poi_str, ind, value);
                        }
                        poi_str[ind][prm].value = "0x6300";//Отметки высот
                        key_label = false;
                        key_1_1 = false;
                        key_1_13 = false;
                        value_1_13 = false;
                        UnkPoint_true++;
                        continue;
                    }
                    //10. if(U.P.F./Pilot boarding place = место посадки пилота)
                    if (key_1_1 && value_1_14) {
                        string value;//Додтелать
                        if (!key_label) {
                            if (key_1_14)
                                value = buffer_1_14;
                            else if (!key_1_14)
                                value = buffer_1_14;
                            vector_add_KeyLabel_and_Value(poi_str, ind, value);
                        }
                        else if (key_label) {
                            poi_str[ind][ind_label].value = "Pilot boarding place(" + buffer_label + ")";
                        }
                        poi_str[ind][prm].value = "0x2800";//TODO: Надпись, но нужно место посадки пилота
                        key_label = false;
                        key_1_1 = false;
                        key_1_14 = false;
                        value_1_14 = false;
                        UnkPoint_true++;
                        continue;
                    }
                    //11. if(U.P.F./Category of mooring/warping facility = причала,категория причала)
                    if (key_1_1 && key_1_15 && value_1_15) {
                        if (!key_label) {
                            string value = "Mooring(" + buffer_1_15 + ")";
                            vector_add_KeyLabel_and_Value(poi_str, ind, value);
                        }
                        else if (key_label) {
                            poi_str[ind][ind_label].value = "Mooring(" + buffer_label + ")";
                        }
                        poi_str[ind][prm].value = "0x4700";//Якорные стоянки и пристани
                        key_label = false;
                        key_1_1 = false;
                        key_1_15 = false;
                        value_1_15 = false;
                        UnkPoint_true++;
                        continue;
                    }
                    //12. if(U.P.F./Category of fog signal = сигнал)
                    if (key_1_1 && key_1_17 && value_1_16) {
                        if (key_label) {
                            poi_str[ind][ind_label].value = "Fog signal(" + buffer_label + ")";
                        }
                        else if (!key_label) {
                            string value = "Fog signal(" + buffer_1_17 + ")";
                            vector_add_KeyLabel_and_Value(poi_str, ind, value);
                        }
                        poi_str[ind][prm].value = "0xF304";//Радиомачты,телевизионные и радиорелейные мачты
                        key_label = false;
                        key_1_1 = false;
                        key_1_17 = false;
                        value_1_16 = false;
                        UnkPoint_true++;
                        continue;
                    }
                    //13. if(U.P.F./Weed/Kelp = водоросли)
                    if (!key_label && key_1_1 && value_1_17) {
                        string value = "Weed/Kelp";
                        vector_add_KeyLabel_and_Value(poi_str, ind, value);
                        poi_str[ind][prm].value = "0x6513";//Заболоченость
                        key_1_1 = false;
                        value_1_17 = false;
                        UnkPoint_true++;
                        continue;
                    }
                    //14. if(U.P.F./Pile = Груда)
                    if (key_1_1 && value_1_18) {
                        if (key_label)
                            poi_str[ind][ind_label].value = "Pile(" + buffer_label + ")";
                        else if (!key_label) {
                            string value = "Pile";
                            vector_add_KeyLabel_and_Value(poi_str, ind, value);
                        }
                        poi_str[ind][prm].value = "0xF30a";//Скопление камней
                        key_label = false;
                        key_1_1 = false;
                        value_1_18 = false;
                        UnkPoint_true++;
                        continue;
                    }
                    //15. if(U.P.F,Signal station, warning||traffi = Сигнальная станция предупреждение || трафик)
                    if (key_1_1 && (value_1_19 || value_1_20)) {
                        string value;
                        if (!key_label) {
                            if (value_1_19)
                                value = "Signal station, warning";
                            else if (value_1_20)
                                value = "Signal station, traffic";
                            vector_add_KeyLabel_and_Value(poi_str, ind, value);
                        }
                        else if (key_label) {
                            if (value_1_19)
                                poi_str[ind][ind_label].value = "Signal station, warning" + buffer_label + ")";
                            else if (value_1_20)
                                poi_str[ind][ind_label].value = "Signal station, traffic" + buffer_label + ")";
                        }
                        poi_str[ind][prm].value = "0xF304";//Радиомачты,телевизионные и радиорелейные мачты
                        key_label = false;
                        key_1_1 = false;
                        value_1_19 = false;
                        value_1_20 = false;
                        UnkPoint_true++;
                        continue;
                    }
                    //16. if(U.P.F./Local magnetic anomaly = Местная магнитная аномалия)
                    if (key_1_1 && value_1_21) {
                        string value;
                        if (key_1_18) {
                            if (!key_label) {
                                if (key_1_19)
                                    value = "Local magnetic anomaly(Value: " + buffer_1_18 + ";Inform:" + buffer_1_19 + ";)";
                                else if (!key_1_19)
                                    value = "Local magnetic anomaly(Value: " + buffer_1_18 + ")";
                                vector_add_KeyLabel_and_Value(poi_str, ind, value);
                            }
                            else if (key_label) {
                                poi_str[ind][ind_label].value = "Local magnetic anomaly(" + buffer_label + ")";
                            }
                        }
                        else if (!key_1_18) {
                            if (key_label)
                                value = "Local magnetic anomaly(" + buffer_label + ")";
                            else if (!key_label)
                                value = "Local magnetic anomaly";
                        }

                        poi_str[ind][prm].value = "0x6500";//TODO: Объект гидрографии, но нужна местная магнитная аномалия
                        key_label = false;
                        key_1_1 = false;
                        key_1_18 = false;
                        key_1_19 = false;
                        value_1_21 = false;
                        UnkPoint_true++;
                        continue;
                    }
                    //17. if(U.P.F./The dumping ground = Свалка)
                    if (key_1_1 && key_1_20 && value_1_22) {
                        if (!key_label) {
                            string value = "The dumping ground(" + buffer_1_20 + ")";
                            vector_add_KeyLabel_and_Value(poi_str, ind, value);
                        }
                        else if (key_label) {
                            poi_str[ind][ind_label].value = "The dumping ground(" + buffer_label + ")";
                        }
                        poi_str[ind][prm].value = "0x6500";//Отстойники
                        key_label = false;
                        key_1_1 = false;
                        key_1_20 = false;
                        value_1_22 = false;
                        UnkPoint_true++;
                        continue;
                    }
                    //18. if(U.P.F./Land area(Какая то "Площадь земельного участка")
                    if (!key_label && !key_1_4 && !key_1_7 && !key_1_16 && !key_1_19 &&
                        key_1_1 && value_1_2) {
                        string value;
                        if (key_1_21 && key_1_22)
                            value = "Land area";
                        else if (!key_1_21 && !key_1_22)
                            value = "Land area";
                        vector_add_KeyLabel_and_Value(poi_str, ind, value);
                        poi_str[ind][prm].value = "0x1100";//Поселок(менее 100)
                        key_1_1 = false;
                        key_1_21 = false;
                        key_1_22 = false;
                        value_1_2 = false;
                        UnkPoint_true++;
                        continue;
                    }
                    //19. if(U.P.F./Radio calling-in poin = Точка радиосвязи)
                    if (key_1_1 && value_1_23) {
                        if (!key_label && key_1_23 && key_1_24) {
                            string value = "Radio calling-in point(" + buffer_1_23 + "," + buffer_1_24 + ")";
                            vector_add_KeyLabel_and_Value(poi_str, ind, value);
                        }
                        else if (key_label) {
                            poi_str[ind][ind_label].value = "Radio calling-in point(" + buffer_label + ")";
                        }
                        poi_str[ind][prm].value = "0xF304";//Радиомачты,телевизионные и радиорелейные мачты
                        key_label = false;
                        key_1_1 = false;
                        key_1_23 = false;
                        key_1_24 = false;
                        value_1_23 = false;
                        UnkPoint_true++;
                        continue;
                    }
                    //20. if(U.P.F./Control point = Контрольная точка)
                    if (key_1_1 && value_1_24) {
                        string value;
                        if (key_label && key_1_25)
                            poi_str[ind][ind_label].value = buffer_label + "(" + buffer_1_25 + ")";
                        else if (!key_label && key_1_25) {
                            value = "Control point (" + buffer_1_25 + ")";
                            vector_add_KeyLabel_and_Value(poi_str, ind, value);
                        }
                        else if (key_label && !key_1_25) {/*просто отсавояем label;*/
                        }
                        else if (!key_label && !key_1_25) {
                            value = "Control point";
                            vector_add_KeyLabel_and_Value(poi_str, ind, value);
                        }
                        poi_str[ind][prm].value = "0x6300";//Отметка высоты
                        key_label = false;
                        key_1_1 = false;
                        key_1_25 = false;
                        value_1_24 = false;
                        UnkPoint_true++;
                        continue;
                    }
                    //21. if(U.P.F./Sea area/named water area = Морская зона/названная акватория)
                    if (key_1_1 && value_1_25) {
                        if (!key_label) {
                            string value = "Sea area/named water area";
                            vector_add_KeyLabel_and_Value(poi_str, ind, value);
                        }
                        else if (key_label) {
                            poi_str[ind][ind_label].value = "Sea area/named water area(" + buffer_label + ")";
                        }
                        poi_str[ind][prm].value = "0x650b";//Гавань
                        key_label = false;
                        key_1_1 = false;
                        value_1_25 = false;
                        UnkPoint_true++;
                        continue;
                    }
                    //22. if(U.P.F./Rescue station = Спасательная станция)
                    if (key_1_1 && value_1_26) {
                        if (key_label)
                            poi_str[ind][ind_label].value = "Rescue station(" + buffer_label + ")";
                        else if (!key_label) {
                            string value = "Rescue station";
                            vector_add_KeyLabel_and_Value(poi_str, ind, value);
                        }
                        poi_str[ind][prm].value = "0x6408";//Больница
                        key_label = false;
                        key_1_1 = false;
                        value_1_26 = false;
                        UnkPoint_true++;
                        continue;
                    }
                    //23. if(U.P.F,Caution area = Ообласть предостережения)
                    if (key_1_1 && value_1_27) {
                        if (key_label)
                            poi_str[ind][ind_label].value = "Caution area(" + buffer_label + ")";
                        else if (!key_label) {
                            string value = "Caution area";
                            vector_add_KeyLabel_and_Value(poi_str, ind, value);
                        }
                        poi_str[ind][prm].value = "0x2800";//TODO: надпись, но возможно нужно область предостережени
                        key_label = false;
                        key_1_1 = false;
                        value_1_27 = false;
                        UnkPoint_true++;
                        continue;
                    }

                }
            }


            //2.Переобразование точек типов = 0x00(Тип не определен)
            if (poi_str[ind][prm].key == "Type" && poi_str[ind][prm].value == "0x00") {
                All0x00_point++;
                int ind_label;
                bool key_label = false;
                string buffer_label;

                bool key_2_1 = false;                    //FEATURE_DESCRIPTION(Описание особенности)
                bool key_2_2 = false; string buffer_2_2; //Nature of surface(Природа поверхности)
                bool key_2_3 = false;                    //Scale minimum(Минимальный масштаб)
                bool key_2_4 = false; string buffer_2_4; //Information(Информация)
                bool key_2_5 = false; string buffer_2_5; //Water level effect(Эффект уровня воды)

                bool value_2_1 = false; //F_D=Seabed area(Площадь морского дна)
                bool value_2_2 = false; //F_D=Anchor berth(Якорный причал)
                bool value_2_3 = false; //F_D=Anchorage area(Якорная зона)

                for (int x_2 = 0; x_2 < poi_str[ind].size(); x_2++) {
                    //buffer_label
                    if (poi_str[ind][x_2].key == "Label") {
                        ind_label = x_2;
                        key_label = true;
                        buffer_label = poi_str[ind][x_2].value;
                    }
                    //key = trye, false?
                    if (poi_str[ind][x_2].key == "FEATURE_DESCRIPTION")
                        key_2_1 = true;
                    if (poi_str[ind][x_2].key == "NATSUR - Nature of surface") {
                        key_2_2 = true;
                        buffer_2_2 = poi_str[ind][x_2].value;
                    }
                    if (poi_str[ind][x_2].key == "SCAMIN - Scale minimum")
                        key_2_3 = true;
                    if (poi_str[ind][x_2].key == "INFORM - Information") {
                        key_2_4 = true;
                        buffer_2_4 = poi_str[ind][x_2].value;
                    }
                    if (poi_str[ind][x_2].key == "WATLEV - Water level effect") {
                        key_2_5 = true;
                        buffer_2_5 = poi_str[ind][x_2].value;//Эффект уровня воды
                    }
                    //value = trye, false?
                    if (poi_str[ind][x_2].value == "Seabed area")
                        value_2_1 = true;
                    if (poi_str[ind][x_2].value == "Anchor berth") {
                        value_2_2 = true;
                        buffer_label = " Anchor berth";
                    }
                    if (poi_str[ind][x_2].value == "Anchorage area")
                        value_2_3 = true;

                    //1. if(0x00/Seabed area = Площадь морского дна)
                    if (!key_label && key_2_1 && value_2_1 && (key_2_2 || key_2_4)) {
                        string value;
                        if (key_2_2)
                            value = "Seabed area(" + buffer_2_2 + ")";
                        else if (key_2_4)
                            value = "Seabed area(" + buffer_2_4 + ")";
                        vector_add_KeyLabel_and_Value(poi_str, ind, value);
                        poi_str[ind][prm].value = "0x1c07";//Препятствие, ниже уровня воды
                        key_2_1 = false;
                        key_2_2 = false;
                        key_2_4 = false;
                        value_2_1 = false;
                        P_0x00_true++;
                        continue;
                    }
                    //2. if(0x00/Seabed area = Площадь морского дна)
                    if (!key_label && key_2_1 && key_2_2 && key_2_5 && value_2_1) {
                        string value = "Seabed area(" + buffer_2_5 + ")";
                        vector_add_KeyLabel_and_Value(poi_str, ind, value);
                        poi_str[ind][prm].value = "0x1c07";//Препятствие, ниже уровня воды
                        key_2_1 = false;
                        key_2_2 = false;
                        key_2_5 = false;
                        value_2_1 = false;
                        P_0x00_true++;
                        continue;
                    }
                    //3. if(0x00/Category of anchorage,Anchor berth = Якорный причал)
                    if (key_2_1 && key_2_3 && value_2_2) {
                        if (key_label)
                            poi_str[ind][ind_label].value = buffer_label;
                        else if (!key_label) {
                            string value = "Anchor berth";
                            vector_add_KeyLabel_and_Value(poi_str, ind, value);
                        }
                        poi_str[ind][prm].value = "0x4700";//Якорные стоянки и пристани
                        key_label = false;
                        key_2_1 = false;
                        key_2_3 = false;
                        value_2_2 = false;
                        P_0x00_true++;
                        continue;
                    }
                    //4. if(0x00/Anchorage area = Якорная зона)
                    if (key_2_1 && value_2_3) {
                        if (key_label)
                            poi_str[ind][ind_label].value = "Anchorage area(" + (buffer_label)+")";
                        if (!key_label) {
                            string value = "Anchorage area";
                            vector_add_KeyLabel_and_Value(poi_str, ind, value);
                        }
                        poi_str[ind][prm].value = "0x4700";//Якорные стоянки и пристани
                        key_label = false;
                        key_2_1 = false;
                        value_2_3 = false;
                        P_0x00_true++;
                        continue;
                    }

                }
            }
            //Конец переобразование точек
        }
    }
    InfoOfTypesData(AllUnkPoint, UnkPoint_true, "точек типа Unknown Point Feature");
    InfoOfTypesData(All0x00_point, P_0x00_true, "точек типа 0x00");
}