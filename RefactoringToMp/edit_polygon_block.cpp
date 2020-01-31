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
                int ind_label;
                bool key_label = false;
                string buffer_label;

                bool key_1_1 = false; string buffer_1_1;  //FEATURE_DESCRIPTION(Описание особенности)
                bool key_1_2 = false; string buffer_1_2;  //NATION - Nationality(НАЦИЯ - Национальность)
                bool key_1_3 = false; string buffer_1_3;  //Category of shoreline construction(Категория строительства береговой линии)
                bool key_1_4 = false; string buffer_1_4;  //Horizontal datum(Горизонтальные данные)
                bool key_1_5 = false; string buffer_1_5;  //Shift parameters(Параметры сдвига)
                bool key_1_6 = false; string buffer_1_6;  //Category of slope(Категория склона)
                bool key_1_7 = false; string buffer_1_7;  //Nature of surface(Природа поверхности)
                bool key_1_8 = false; string buffer_1_8;  //Value of local magnetic anomaly(Значение локальной магнитной аномалии)
                bool key_1_9 = false; string buffer_1_9;  //Information(Информация)
                bool key_1_10 = false; string buffer_1_10; //Water level effect(Эффект уровня воды)
                bool key_1_11 = false; string buffer_1_11; //Depth range value(Значение диапазона глубины)
                bool key_1_12 = false; string buffer_1_12; //Category of road(Категория дороги)
                bool key_1_13 = false; string buffer_1_13; //Nature of construction(Природа строительства)


                bool value_1_1 = false; //F_D=Coverage(Покрытие)
                bool value_1_2 = false; //F_D=Administration area(Администрация области))
                bool value_1_3 = false; //F_D=Harbour area (administrative) = Портовый район(административный)
                bool value_1_4 = false; //F_D=Quality of data(Качество данных, занимает весь участок на карте)
                bool value_1_5 = false; //F_D=Navigational system of marks(Навигационная система знаков, занимает весь участок на карте)
                bool value_1_6 = false; //F_D=Nautical publication information(Информация о морских публикациях, занимает весь участок на карте)
                bool value_1_7 = false; //F_D=Magnetic variation(Магнитная вариация, занимает весь участок на карте)
                bool value_1_8 = false; //F_D=Shoreline Construction(Береговая линия, Пристань)
                bool value_1_9 = false; //F_D=Continental shelf area(Континентальная площадь шельфа)
                bool value_1_10 = false; //F_D=Horizontal datum shift parameters(Параметры горизонтального сдвига)
                bool value_1_11 = false; //F_D=Sloping ground(Наклонная площадка)
                bool value_1_12 = false; //F_D=Local magnetic anomaly(Местная магнитная аномалия)
                bool value_1_13 = false; //F_D=Exclusive Economic Zone(Эксклюзивная экономическая зона)
                bool value_1_14 = false; //F_D=Seabed area(Площадь морского дна)
                bool value_1_15 = false; //F_D=Dredged area(Драгированная площадь ,дноуглубительные работы)
                bool value_1_16 = false; //F_D=Dam(Дамба)
                bool value_1_17 = false; //F_D=Road(Дорога)
                bool value_1_18 = false; //F_D=Territorial sea area(Территориальный морской район)
                bool value_1_19 = false; //F_D=Causeway(Мост, Дамба)
                bool value_1_20 = false; //F_D=Dyke(Дамба)
                bool value_1_21 = false; //F_D=Vegetation(растительность)


                for (int x_1 = 0; x_1 < polygon_str[ind].size(); x_1++) {
                    //buffer_label
                    if (polygon_str[ind][x_1].key == "Label") {
                        ind_label = x_1;
                        key_label = true;
                        buffer_label = polygon_str[ind][x_1].value;
                    }
                    //key = trye, false?
                    if (polygon_str[ind][x_1].key == "FEATURE_DESCRIPTION") {
                        buffer_1_1 = polygon_str[ind][x_1].value;
                        key_1_1 = true;
                    }
                    if (polygon_str[ind][x_1].key == "NATION - Nationality") {
                        buffer_1_2 = polygon_str[ind][x_1].value;
                        key_1_2 = true;
                    }
                    if (polygon_str[ind][x_1].key == "CATSLC - Category of shoreline construction") {
                        buffer_1_3 = polygon_str[ind][x_1].value;
                        key_1_3 = true;
                    }
                    if (polygon_str[ind][x_1].key == "HORDAT - Horizontal datum") {
                        buffer_1_4 = polygon_str[ind][x_1].value;
                        key_1_4 = true;
                    }
                    if (polygon_str[ind][x_1].key == "SHIPAM - Shift parameters") {
                        buffer_1_5 = polygon_str[ind][x_1].value;
                        key_1_5 = true;
                    }
                    if (polygon_str[ind][x_1].key == "CATSLO - Category of slope") {
                        buffer_1_6 = polygon_str[ind][x_1].value;
                        key_1_6 = true;
                    }
                    if (polygon_str[ind][x_1].key == "NATSUR - Nature of surface") {
                        buffer_1_7 = polygon_str[ind][x_1].value;
                        key_1_7 = true;
                    }
                    if (polygon_str[ind][x_1].key == "VALLMA - Value of local magnetic anomaly") {
                        buffer_1_8 = polygon_str[ind][x_1].value;
                        key_1_8 = true;
                    }
                    if (polygon_str[ind][x_1].key == "INFORM - Information") {
                        buffer_1_9 = polygon_str[ind][x_1].value;
                        key_1_9 = true;
                    }
                    if (polygon_str[ind][x_1].key == "WATLEV - Water level effect") {
                        buffer_1_10 = polygon_str[ind][x_1].value;
                        key_1_10 = true;
                    }
                    if (polygon_str[ind][x_1].key.find("Depth range value") != string::npos) {
                        buffer_1_11 = polygon_str[ind][x_1].value;
                        key_1_11 = true;
                    }
                    if (polygon_str[ind][x_1].key.find("CATROD - Category of road") != string::npos) {
                        buffer_1_12 = polygon_str[ind][x_1].value;
                        key_1_12 = true;
                    }
                    if (polygon_str[ind][x_1].key.find("NATCON - Nature of construction") != string::npos) {
                        buffer_1_13 = polygon_str[ind][x_1].value;
                        key_1_13 = true;
                    }
                    //value = trye, false?
                    if (polygon_str[ind][x_1].value == "Coverage")
                        value_1_1 = true;
                    if (polygon_str[ind][x_1].value == "Administration area (Named)")
                        value_1_2 = true;
                    if (polygon_str[ind][x_1].value == "Harbour area (administrative)")
                        value_1_3 = true;
                    if (polygon_str[ind][x_1].value == "Quality of data")
                        value_1_4 = true;
                    if (polygon_str[ind][x_1].value == "Navigational system of marks")
                        value_1_5 = true;
                    if (polygon_str[ind][x_1].value == "Nautical publication information")
                        value_1_6 = true;
                    if (polygon_str[ind][x_1].value == "Magnetic variation")
                        value_1_7 = true;
                    if (polygon_str[ind][x_1].value == "Shoreline Construction")
                        value_1_8 = true;
                    if (polygon_str[ind][x_1].value == "Continental shelf area")
                        value_1_9 = true;
                    if (polygon_str[ind][x_1].value == "Horizontal datum shift parameters")
                        value_1_10 = true;
                    if (polygon_str[ind][x_1].value == "Sloping ground")
                        value_1_11 = true;
                    if (polygon_str[ind][x_1].value == "Local magnetic anomaly")
                        value_1_12 = true;
                    if (polygon_str[ind][x_1].value == "Exclusive Economic Zone")
                        value_1_13 = true;
                    if (polygon_str[ind][x_1].value == "Seabed area")
                        value_1_14 = true;
                    if (polygon_str[ind][x_1].value == "Dredged area")
                        value_1_15 = true;
                    if (polygon_str[ind][x_1].value == "Dam")
                        value_1_16 = true;
                    if (polygon_str[ind][x_1].value == "Road")
                        value_1_17 = true;
                    if (polygon_str[ind][x_1].value == "Territorial sea area")
                        value_1_18 = true;
                    if (polygon_str[ind][x_1].value == "Causeway")
                        value_1_19 = true;
                    if (polygon_str[ind][x_1].value == "Dyke")
                        value_1_20 = true;
                    if (polygon_str[ind][x_1].value == "Vegetation")
                        value_1_21 = true;

                    //if(Unknown Area Type,Coverage) = 0x0001(Населений пункт > 200К)
                    if (key_1_1 && value_1_1) {
                        if (!key_label) {
                            string value = buffer_1_1;
                            vector_add_KeyLabel_and_Value(polygon_str, ind, value);
                        }
                        polygon_str[ind][prm].value = "0x0001";//Населений пункт > 200К
                        key_1_1 = false;
                        value_1_1 = false;
                        UnkAreaType_true++;
                        continue;
                    }
                    //if(U.A.T./Administration area=Администрация области)
                    if (key_1_1 && value_1_2)//Label?Nationality?
                    {
                        if (key_label && key_1_2)
                            polygon_str[ind][ind_label].value = buffer_label + "(" + buffer_1_2 + ")";
                        else {
                            string value;
                            if (key_1_2)
                                value = "NATION:" + buffer_1_2 + "";
                            else if (!key_1_2 && key_1_9)
                                value = buffer_1_9;
                            else
                                value = "Administration area";
                            vector_add_KeyLabel_and_Value(polygon_str, ind, value);
                        }
                        polygon_str[ind][prm].value = "0x0001";//Населений пункт > 200К
                        key_1_1 = false;
                        key_1_2 = false;
                        key_1_9 = false;
                        value_1_2 = false;
                        UnkAreaType_true++;
                        continue;
                    }
                    //if(U.A.T./Harbour area(administrative)=Портовый район(административный)
                    if (key_1_1 && value_1_3) {
                        if (!key_label) {
                            string value = "Harbour area (administrative)";
                            vector_add_KeyLabel_and_Value(polygon_str, ind, value);
                        }
                        polygon_str[ind][prm].value = "0x4a";//TODO: Область выделения карты, совершенно неверно, нужно исправить.
                        key_1_1 = false;
                        value_1_3 = false;
                        UnkAreaType_true++;
                        continue;
                    }
                    //if(U.A.T./Quality of data=Качество данных, занимает весь участок на карте)
                    if (key_1_1 && value_1_4) {
                        if (!key_label) {
                            string value = "Quality of data";
                            vector_add_KeyLabel_and_Value(polygon_str, ind, value);
                        }
                        polygon_str[ind][prm].value = "0x4a";//TODO: Область выделения карты, возможно нужно исправить.
                        key_1_1 = false;
                        value_1_4 = false;
                        UnkAreaType_true++;
                        continue;
                    }
                    //if(U.A.T./Navigational system of marks=Навигационная система знаков)
                    if (key_1_1 && value_1_5) {
                        if (!key_label) {
                            string value = "Navigational system of marks";
                            vector_add_KeyLabel_and_Value(polygon_str, ind, value);
                        }
                        polygon_str[ind][prm].value = "0x4a";//TODO: Область выделения карты, возможно нужно исправить.
                        key_1_1 = false;
                        value_1_5 = false;
                        UnkAreaType_true++;
                        continue;
                    }
                    //if(U.A.T./Nautical publication information = Информация о морских публикациях,занимает весь участок на карте)
                    if (key_1_1 && value_1_6) {
                        if (!key_label) {
                            string value = "Nautical publication information";
                            vector_add_KeyLabel_and_Value(polygon_str, ind, value);
                        }
                        polygon_str[ind][prm].value = "0x4a";//TODO: Область выделения карты, возможно нужно исправить.
                        key_1_1 = false;
                        value_1_6 = false;
                        UnkAreaType_true++;
                        continue;
                    }
                    //if(U.A.T/Magnetic variation = Магнитная вариация,занимает весь участок на карте)
                    if (key_1_1 && value_1_7) {
                        if (!key_label) {
                            string value = "Magnetic variation";
                            vector_add_KeyLabel_and_Value(polygon_str, ind, value);
                        }
                        polygon_str[ind][prm].value = "0x4a";//TODO: Область выделения карты, возможно нужно исправить.
                        key_1_1 = false;
                        value_1_7 = false;
                        UnkAreaType_true++;
                        continue;
                    }
                    //if(U.A.T./Shoreline Construction=Береговая линия, Пристань)
                    if (key_1_1 && value_1_8) {
                        if (!key_label) {
                            string value;
                            if (key_1_3)
                                value = "Shoreline Construction(" + buffer_1_3 + ")";
                            else if (!key_1_3)
                                value = "Shoreline Construction";
                            vector_add_KeyLabel_and_Value(polygon_str, ind, value);
                        }
                        polygon_str[ind][prm].value = "0x0009";//Пристань
                        key_1_1 = false;
                        value_1_8 = false;
                        UnkAreaType_true++;
                        continue;
                    }
                    //if(U.A.T./Continental shelf area=континентальная площадь шельфа)
                    if (key_1_1 && value_1_9) {
                        if (!key_label) {
                            string value;
                            if (key_1_2)
                                value = "Continental shelf area(" + buffer_1_2 + ")";
                            else if (!key_1_2)
                                string value = "Continental shelf area";
                            vector_add_KeyLabel_and_Value(polygon_str, ind, value);
                        }
                        polygon_str[ind][prm].value = "0x4a";//TODO: Область выделения карты, возможно нужно исправить.
                        key_1_1 = false;
                        value_1_9 = false;
                        UnkAreaType_true++;
                        continue;
                    }
                    //if(U.A.T./Horizontal datum shift parameters=Параметры горизонтального сдвига)
                    if (key_1_1 && value_1_10) {
                        string value;
                        if (!key_label) {
                            if (key_1_4 && key_1_5)
                                value = "Horizontal datum shift parameters(Horizontal datum:" + buffer_1_4 + ", Shift parameters:" + buffer_1_5 + ")";
                            if (key_1_4 && !key_1_5)
                                value = "Horizontal datum shift parameters(Horizontal datum:" + buffer_1_4 + ")";
                            if (!key_1_4 && key_1_5)
                                value = "Horizontal datum shift parameters(Shift parameters:" + buffer_1_5 + ")";
                            if (!key_1_4 && !key_1_5)
                                value = "Horizontal datum shift parameters";
                            vector_add_KeyLabel_and_Value(polygon_str, ind, value);
                        }
                        polygon_str[ind][prm].value = "0x4a";//TODO: Область выделения карты, возможно нужно исправить.
                        key_1_1 = false;
                        key_1_4 = false;
                        key_1_5 = false;
                        value_1_10 = false;
                        UnkAreaType_true++;
                        continue;
                    }
                    //if(U.A.T./Sloping ground=Наклонная площадка)
                    if (key_1_1 && value_1_11) {
                        string value;
                        if (!key_label) {
                            //(cliff || rock = утес || камень)
                            if (buffer_1_6.find("(cliff)") != string::npos || buffer_1_7.find("(rock)") != string::npos) {
                                value = "Sloping ground(" + buffer_1_6 + " " + buffer_1_7 + ")";
                                vector_add_KeyLabel_and_Value(polygon_str, ind, value);
                                polygon_str[ind][prm].value = "0x0002";//TODO: Населений пункт < 200К, но нужно утес или камень
                                UnkAreaType_true++;
                            }
                        }
                        else if (key_label) {
                            polygon_str[ind][prm].value = "0x0002";//Населений пункт < 200К
                            UnkAreaType_true++;
                        }
                        key_1_1 = false;
                        key_1_6 = false;
                        key_1_7 = false;
                        value_1_11 = false;
                        continue;
                    }
                    //if(U.A.T./Local magnetic anomaly=Местная магнитная аномалия)
                    if (key_1_1 && value_1_12) {
                        if (!key_label) {
                            string value;
                            if (key_1_8 && key_1_9)
                                value = "Local magnetic anomaly(Value:" + buffer_1_8 + ", Information:" + buffer_1_9 + ")";
                            else if (key_1_8 && !key_1_9)
                                value = "Local magnetic anomaly(Value:" + buffer_1_8 + ")";
                            else if (!key_1_8 && key_1_9)
                                value = "Local magnetic anomaly(Value:" + buffer_1_8 + ")";
                            else
                                value = "Local magnetic anomaly";
                            vector_add_KeyLabel_and_Value(polygon_str, ind, value);
                        }
                        polygon_str[ind][prm].value = "0x4a";//TODO: Область выделения карты, обязательно нужно исправить.
                        key_1_1 = false;
                        key_1_8 = false;
                        key_1_9 = false;
                        value_1_12 = false;
                        UnkAreaType_true++;
                        continue;
                    }
                    //if(U.A.T./Exclusive Economic Zone=Эксклюзивная экономическая зона)
                    if (key_1_1 && value_1_13) {
                        if (!key_label) {
                            string value;
                            if (key_1_9)
                                value = "Exclusive Economic Zone(Information:" + buffer_1_9 + ")";
                            else
                                value = "Exclusive Economic Zone";
                            vector_add_KeyLabel_and_Value(polygon_str, ind, value);
                        }
                        polygon_str[ind][prm].value = "0x4a";//TODO: Область выделения карты, обязательно нужно исправить.
                        key_1_1 = false;
                        key_1_9 = false;
                        value_1_13 = false;
                        UnkAreaType_true++;
                        continue;
                    }
                    //if(U.A.T./Seabed area = Площадь морского дна)
                    if (key_1_1 && value_1_14) {
                        if (!key_label) {
                            string value;
                            if (key_1_7 && key_1_10)
                                value = "Seabed area(" + buffer_1_7 + "," + buffer_1_10 + ")";
                            else if (key_1_7 && !key_1_10)
                                value = "Seabed area(" + buffer_1_7 + ")";
                            else if (!key_1_7 && key_1_10)
                                value = "Seabed area(" + buffer_1_10 + ")";
                            else
                                value = "Seabed area";
                            vector_add_KeyLabel_and_Value(polygon_str, ind, value);
                        }
                        polygon_str[ind][prm].value = "0x0053";//TODO: мель,возможно нужно площадь морского дна.
                        key_1_1 = false;
                        key_1_7 = false;
                        key_1_10 = false;
                        value_1_14 = false;
                        UnkAreaType_true++;
                        continue;
                    }
                    //if(U.A.T./Dredged area = Драгированная площадь, Дноуглубительные работы)
                    if (key_1_1 && value_1_15) {
                        if (!key_label) {
                            string value;
                            if (key_1_9 && key_1_11)
                                value = "Dredged area(Depth range value:" + buffer_1_11 + ",Information:" + buffer_1_9 + ")";
                            else if (key_1_9 && !key_1_11)
                                value = "Dredged area(Information:" + buffer_1_9 + ")";
                            else if (!key_1_9 && key_1_11)
                                value = "Dredged area(Depth range value:" + buffer_1_11 + ")";
                            else
                                value = "Dredged area";
                            vector_add_KeyLabel_and_Value(polygon_str, ind, value);
                        }
                        polygon_str[ind][prm].value = "0x4a";//TODO: Область выделения карты,возможно нужно драгированная площадь.
                        key_1_1 = false;
                        key_1_9 = false;
                        key_1_11 = false;
                        value_1_15 = false;
                        UnkAreaType_true++;
                        continue;
                    }
                    //if(U.A.T./Dam = Дамба)
                    if (key_1_1 && value_1_16) {
                        if (!key_label) {
                            string value = "Dam";
                            vector_add_KeyLabel_and_Value(polygon_str, ind, value);
                        }
                        else
                            polygon_str[ind][ind_label].value = "Dam(" + buffer_label + ")";
                        polygon_str[ind][prm].value = "0x0013";//TODO: Здания, искусственные сооружения, нужно дамба.
                        key_1_1 = false;
                        value_1_16 = false;
                        UnkAreaType_true++;
                        continue;
                    }
                    //if(U.A.T./Road = Дорога)
                    if (key_1_1 && value_1_17) {
                        if (!key_label) {
                            string value;
                            if (key_1_12)
                                value = "Road(" + buffer_1_12 + ")";
                            else
                                value = "Road";
                            vector_add_KeyLabel_and_Value(polygon_str, ind, value);
                        }
                        else { polygon_str[ind][ind_label].value = "Road(" + buffer_label + ")"; }
                        polygon_str[ind][prm].value = "0x0003";//TODO: Застройка сельского типа, обязательно нужна дорога.
                        key_1_1 = false;
                        key_1_12 = false;
                        value_1_17 = false;
                        UnkAreaType_true++;
                        continue;
                    }
                    //if(U.A.T./Territorial sea area = территориальный морской район)
                    if (key_1_1 && value_1_18) {
                        if (!key_label) {
                            string value;
                            if (key_1_2)
                                value = "Territorial sea area(Nationality" + buffer_1_2 + ")";
                            else
                                value = "Territorial sea area";
                            vector_add_KeyLabel_and_Value(polygon_str, ind, value);
                        }
                        else { polygon_str[ind][ind_label].value = "Territorial sea area(" + buffer_label + ")"; }
                        polygon_str[ind][prm].value = "0x4a";//TODO: Область выделения карты, нужно территориальный морской район.
                        key_1_1 = false;
                        key_1_2 = false;
                        value_1_18 = false;
                        UnkAreaType_true++;
                        continue;
                    }
                    //if(U.A.T./Causeway = мост или дамба)
                    if (key_1_1 && value_1_19) {
                        if (!key_label) {
                            string value;
                            if (key_1_13)
                                value = "Causeway(Nationality" + buffer_1_13 + ")";
                            else
                                value = "Causeway";
                            vector_add_KeyLabel_and_Value(polygon_str, ind, value);
                        }
                        else
                            polygon_str[ind][ind_label].value = "Causeway(" + buffer_label + ")";
                        polygon_str[ind][prm].value = "0x0013";//TODO: Здания, искусственные сооружения, нужно мост или дамба.
                        key_1_1 = false;
                        key_1_13 = false;
                        value_1_19 = false;
                        UnkAreaType_true++;
                        continue;
                    }
                    //if(U.A.T./Dyke = Дамба)
                    if (key_1_1 && value_1_20) {
                        if (!key_label) {
                            string value = "Dyke";
                            vector_add_KeyLabel_and_Value(polygon_str, ind, value);
                        }
                        else
                            polygon_str[ind][ind_label].value = "Dyke(" + buffer_label + ")";
                        polygon_str[ind][prm].value = "0x0013";//TODO: Здания, искусственные сооружения, нужна дамба.
                        key_1_1 = false;
                        value_1_20 = false;
                        UnkAreaType_true++;
                        continue;
                    }
                    //if(U.A.T./Vegetation = растительность)
                    if (key_1_1 && value_1_21) {
                        if (!key_label) {
                            string value = "Vegetation";
                            vector_add_KeyLabel_and_Value(polygon_str, ind, value);
                        }
                        else
                            polygon_str[ind][ind_label].value = "Vegetation(" + buffer_label + ")";
                        polygon_str[ind][prm].value = "0x004f";//TODO: Кустарник, нужно растительность.
                        key_1_1 = false;
                        value_1_21 = false;
                        UnkAreaType_true++;
                        continue;
                    }
                }
            }//Конец переобразование полигонов типов = Unknown Area Type(Неизвестный тип области)


            //2.Переобразование полигонов типов = Marine Info Area(Морская информационная зона)
            if (polygon_str[ind][prm].key == "Type" && polygon_str[ind][prm].value == "Marine Info Area") {
                All_MarineInfoArea_Type++;
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

                    //if(Marine Info Area/Restricted area = запретная зона)
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
                    //if(M.I.A./Military practice area = военно-тренировочная площадка)
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
                    //if(M.I.A./Caution area = область предостережения)
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
                    //if(M.I.A./Dumping ground = Место свалки)
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
                    //if(M.I.A./Obstruction = Препятствие)
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
                    //if(M.I.A./Unsurveyed area = Необследованная территория)
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
                    //if(M.I.A./Precautionary area = Предупредительная зона)
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
                    //if(M.I.A./Fishing ground = Рыболовная площадка)
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
                    //if(M.I.A./Wreck = Развалина)
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


            //3.Переобразование полигонов типов = 0x54(Неизвестный тип)
            if (polygon_str[ind][prm].key == "Type" && polygon_str[ind][prm].value == "0x54") {
                All_Polygon_0x54_Type++;
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

                    //if(0x54/Land region = земельный участок)
                    if (key_3_1 && !key_3_3 && !key_3_4 && value_3_1) {
                        if (!key_label) {
                            string value = "Land region";
                            vector_add_KeyLabel_and_Value(polygon_str, ind, value);
                        }
                        polygon_str[ind][prm].value = "0x0002";//TODO: Населений пункт < 200К, возможно нужно земельный участок.
                        key_3_1 = false;
                        value_3_1 = false;
                        Polygon_0x54_true++;
                        continue;
                    }
                    //if(0x54/Land region = Какой то земельный участок)
                    if (key_3_1 && key_3_3 && value_3_1) {
                        string value;
                        bool lowlands = buffer_3_3.find("(lowlands)") != string::npos;
                        bool marsh = buffer_3_3.find("(marsh)") != string::npos; //болото
                        bool swamp = buffer_3_3.find("(swamp)") != string::npos; //болото
                        bool fen = buffer_3_3.find("(fen)") != string::npos; //болото
                        if (!key_label) {
                            if (lowlands) {
                                value = "Land region(" + buffer_3_3 + ")";
                                vector_add_KeyLabel_and_Value(polygon_str, ind, value);
                                polygon_str[ind][prm].value = "0x0002"; //TODO: Населений пункт < 200К, нужно пересмотреть.
                                Polygon_0x54_true++;
                            }
                            else if (marsh || swamp || fen) {
                                value = buffer_3_3; //Болото
                                vector_add_KeyLabel_and_Value(polygon_str, ind, value);
                                polygon_str[ind][prm].value = "0x0051";//Болото
                                Polygon_0x54_true++;
                            }
                        }
                        else if (key_label) {
                            polygon_str[ind][prm].value = "0x0002"; //TODO: Населений пункт < 200К, нужно земельный участок.
                            Polygon_0x54_true++;
                        }
                        key_3_1 = false;
                        key_3_3 = false;
                        value_3_1 = false;
                        continue;
                    }
                    //if(0x54/Land region = Какой то земельный участок)
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
                    //if(0x54/Land area = Площадь земельного участка)
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
            }//Конце Переобразование полигонов типов = 0x54(Неизвестный тип)


            //4.Переобразование полигонов типов = 0x00(Неизвестный тип)
            if (polygon_str[ind][prm].key == "Type" && polygon_str[ind][prm].value == "0x00") {
                All_Polygon_0x00_Type++;
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


                    //if(0x54/Traffic Separation Scheme Roundabout = Схема развязки дорожного движения)
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
                    //if(0x00/Traffic Separation Scheme Lane part = Часть переулка Схема разделения движения)
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
                    //if(0x00/Traffic Separation Scheme Lane part = Часть переулка, Схема разделения движения)
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
                    //if(0x00/Fairway = Судовой ход)
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
                    //if(0x00/Anchorage area = Якорная зона)
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
        }
    }
    InfoOfTypesData(AllUnkAreaType, UnkAreaType_true, "полигонов типа Unknown Area Type");
    InfoOfTypesData(All_MarineInfoArea_Type, MarineInfoArea_true, "полигонов типа Marine Info Area");
    InfoOfTypesData(All_Polygon_0x54_Type, Polygon_0x54_true, "полигонов типа 0x54");
    InfoOfTypesData(All_Polygon_0x00_Type, Polygon_0x00_true, "полигонов типа 0x00");
}