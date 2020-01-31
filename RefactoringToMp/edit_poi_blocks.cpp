#include "include.h"
#include "functions.h"
void edit_POI_blocks(vector<vector<MyStruct>>& poi_str)
{

    int AllUnkPoint = 0;   //��������� ���������� ��������� ����� ����(Unknown Point Feature)
    int UnkPoint_true = 0; //���������� ����������� ����� ����(Unknown Point Feature)
    int UnkPoint_false;    //���������� �� ����������� ����� ����(Unknown Point Feature)

    int All0x00_point = 0; //��������� ���������� ��������� ����� ����(0x00(��� �� ��������))
    int P_0x00_true = 0;   //���������� ����������� ����� ����(0x00(��� �� ��������))
    int P_0x00_false;      //���������� �� ����������� ����� ����(0x00(��� �� ��������))

    for (int ind = 0; ind < poi_str.size(); ind++) {
        for (int prm = 0; prm < poi_str[ind].size(); prm++) {

            //1.��������������� ����� ����� = Unknown Point Feature(����������� �����)
            if (poi_str[ind][prm].key == "Type" && poi_str[ind][prm].value == "Unknown Point Feature") {
                AllUnkPoint++;
                int ind_label;
                bool key_label = false;
                string buffer_label;

                bool key_1_1 = false;                      //FEATURE_DESCRIPTION(�������� �����������)
                bool key_1_3 = false;                      //Water level effect(������ ������ ����)
                bool key_1_4 = false;                      //Object name
                bool key_1_5 = false; string buffer_1_5;   //Category of slope(��������� ������)
                bool key_1_6 = false; string buffer_1_6;   //Category of landmark(��������� ���������)
                bool key_1_7 = false; string buffer_1_7;   //Function
                bool key_1_8 = false; string buffer_1_8;   //Reference year for magnetic variation(������� ��� ��� ��������� ��������)
                bool key_1_9 = false;                      //Value of annual change in magnetic variation(�������� �������� ��������� ���������� ����������)
                bool key_1_10 = false; string buffer_1_10; //Value of magnetic variation(�������� ���������� ����������)
                bool key_1_11 = false; string buffer_1_11; //Category of offshore platform(��������� ������� ���������)
                bool key_1_12 = false; string buffer_1_12; //Category of silo/tank(��������� ������/���)
                bool key_1_13 = false; string buffer_1_13; //Topmark/daymark shape(������� �������/daymark shape)
                bool key_1_14 = false; string buffer_1_14; //Category of pilot boarding place(��������� ����� ������� ������)
                bool key_1_15 = false; string buffer_1_15; //Category of mooring/warping facility(��������� �������)
                bool key_1_16 = false;                     //Status
                bool key_1_17 = false; string buffer_1_17; //Category of fog signal(��������� ��������� �������)
                bool key_1_18 = false; string buffer_1_18; //Value of local magnetic anomaly(�������� ��������� ��������� ��������)
                bool key_1_19 = false; string buffer_1_19; //Information(����������)
                bool key_1_20 = false; string buffer_1_20; //Category of dumping ground(��������� ������)
                bool key_1_21 = false;                     //Source indication(��������� ���������)
                bool key_1_22 = false;                     //Source date(���� ���������) 
                bool key_1_23 = false; string buffer_1_23; //Orientation(����������)
                bool key_1_24 = false; string buffer_1_24; //Traffic flow(������������ �����)
                bool key_1_25 = false; string buffer_1_25; //Elevation(������)

                bool value_1_1 = false; //F_D=Land region(��������� �������)
                bool value_1_2 = false; //F_D=Land area(������� ���������� �������)
                bool value_1_3 = false; //F_D=Sloping ground(��������� �������)
                bool value_1_4 = false; //hill(����)
                bool value_1_5 = false; //F_D=Landmark(��������)
                bool value_1_6 = false; //tower(�����)
                bool value_1_7 = false; //mast(�����)
                bool value_1_8 = false; //F_D=Magnetic variation(��������� ��������)
                bool value_1_9 = false; //F_D=Offshore platform(������� ���������)
                bool value_1_10 = false; //F_D=Silo / tank(������/���)				
                bool value_1_11 = false; //F_D=Obstruction(��������������)
                bool value_1_12 = false; //always under water/submerged(������ ��� ����� / �����������)
                bool value_1_13 = false; //F_D=Top mark(������� �������)
                bool value_1_14 = false; //F_D=Pilot boarding place(����� ������� ������)
                bool value_1_15 = false; //F_D=Mooring/warping facility(������ / ��������������)
                bool value_1_16 = false; //F_D=Fog signal(�������� ������)
                bool value_1_17 = false; //F_D=Weed/Kelp(���������)
                bool value_1_18 = false; //F_D=Pile(�����)
                bool value_1_19 = false; //F_D=Signal station, warning(���������� �������, ��������������)
                bool value_1_20 = false; //F_D=Signal station, traffic(���������� �������, ������)
                bool value_1_21 = false; //F_D=Local magnetic anomaly(������� ��������� ��������)
                bool value_1_22 = false; //F_D=The Dumping ground(������)
                bool value_1_23 = false; //F_D=Radio calling-in point(����� ����������)
                bool value_1_24 = false; //F_D=Control point(����������� �����)
                bool value_1_25 = false; //F_D=Sea area/named water area(������� ���� / ��������� ���������)
                bool value_1_26 = false; //F_D=Rescue station(������������ �������)
                bool value_1_27 = false; //F_D=Caution area(������� ���������������)

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

                    //1. if(Unknown Point Feature/Label,Land region = ��������� �������)
                    if (key_label && key_1_1 && key_1_4 && value_1_1 && !value_1_2) {
                        poi_str[ind][prm].value = "0x0400";//����� 
                        key_label = false;
                        key_1_1 = false;
                        key_1_4 = false;
                        value_1_1 = false;
                        UnkPoint_true++;
                        continue;
                    }
                    //2. if(U.P.F./land area = ������� ���������� �������)
                    if (key_1_1 && value_1_2) {
                        if (key_label)
                            poi_str[ind][ind_label].value = "Land area(" + buffer_label + ")";
                        else if (!key_label) {
                            string value = "Land area(Rock)";//������� ���������� �������(�����)
                            vector_add_KeyLabel_and_Value(poi_str, ind, value);
                        }
                        poi_str[ind][prm].value = "0x6614";//�����
                        key_label = false;
                        key_1_1 = false;
                        value_1_2 = false;
                        UnkPoint_true++;
                        continue;
                    }
                    //3. if(U.P.F./Sloping ground,hill = ����)
                    if (key_1_1 && key_1_5 && value_1_3 && value_1_4) {
                        if (key_label)
                            poi_str[ind][ind_label].value = "Hill, " + buffer_label;//��������� �������(����)
                        else if (!key_label) {
                            string value = "Sloping ground(hill)";//��������� �������(����)
                            vector_add_KeyLabel_and_Value(poi_str, ind, value);
                        }
                        poi_str[ind][prm].value = "0x6616";//����
                        key_label = false;
                        key_1_1 = false;
                        key_1_5 = false;
                        value_1_3 = false;
                        value_1_4 = false;
                        UnkPoint_true++;
                        continue;
                    }
                    //4. if(U.P.F./Category of landmark,Landmark = ��������)
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
                            poi_str[ind][prm].value = "0x6411";//�����, �����
                        }
                        else if (!key_1_7) {
                            value = "Landmark(" + buffer_1_6 + ")";
                            vector_add_KeyLabel_and_Value(poi_str, ind, value);
                            poi_str[ind][prm].value = "0x160E";//�����
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
                    //5. if(U.P.F./Magnetic variation = ��������� ��������)
                    if (key_1_1 && key_1_8 && key_1_9 && key_1_10 && value_1_8) {
                        string value;
                        if (!key_label) {
                            value = "Magnetic variation(" + buffer_1_8 + "," + buffer_1_10 + ")";
                            vector_add_KeyLabel_and_Value(poi_str, ind, value);
                        }
                        else if (key_label)
                            poi_str[ind][ind_label].value = buffer_label + "(" + buffer_1_8 + "," + buffer_1_10 + ")";

                        poi_str[ind][prm].value = "0x6500"; //TODO: ������ �����������, �� ����� ��������� ��������
                        key_label = false;
                        key_1_1 = false;
                        key_1_8 = false;
                        key_1_9 = false;
                        key_1_10 = false;
                        value_1_8 = false;
                        UnkPoint_true++;
                        continue;
                    }
                    //6. if(U.P.F./Offshore platform = ������� ���������)
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
                        poi_str[ind][prm].value = "0x6400";//������������� ����������
                        key_label = false;
                        key_1_1 = false;
                        key_1_11 = false;
                        value_1_9 = false;
                        UnkPoint_true++;
                        continue;
                    }
                    //7. if(U.P.F./Category of silo/tank = ������/���)
                    if (key_1_1 && key_1_12 && value_1_10) {
                        if (!key_label) {
                            string value = "Silo/tank. Category=" + buffer_1_12;
                            vector_add_KeyLabel_and_Value(poi_str, ind, value);
                        }
                        if (key_label) {
                            poi_str[ind][ind_label].value = "Silo/tank(" + buffer_label + ")";
                        }
                        poi_str[ind][prm].value = "0x4400";//��������� ��������
                        key_label = false;
                        key_1_1 = false;
                        key_1_12 = false;
                        value_1_10 = false;
                        UnkPoint_true++;
                        continue;
                    }
                    //8. if(U.P.F./Obstruction = ��������������)
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
                            poi_str[ind][prm].value = "0x1c07";//�����������, ���� ������ ����
                        }
                        else {
                            if (key_label)
                                poi_str[ind][ind_label].value = "Obstruction(" + buffer_label + ")";
                            else if (!key_label) {
                                value = "Obstruction";
                                vector_add_KeyLabel_and_Value(poi_str, ind, value);
                            }
                            poi_str[ind][prm].value = "0x1c06";//����������� �� ������ ����
                        }
                        key_label = false;
                        key_1_1 = false;
                        key_1_3 = false;
                        value_1_11 = false;
                        value_1_12 = false;
                        UnkPoint_true++;
                        continue;
                    }
                    //9. if(U.P.F./Top mark = ������� �������)
                    if (key_1_1 && key_1_13 && value_1_13) {
                        if (!key_label) {
                            string value = "Top mark";
                            vector_add_KeyLabel_and_Value(poi_str, ind, value);
                        }
                        poi_str[ind][prm].value = "0x6300";//������� �����
                        key_label = false;
                        key_1_1 = false;
                        key_1_13 = false;
                        value_1_13 = false;
                        UnkPoint_true++;
                        continue;
                    }
                    //10. if(U.P.F./Pilot boarding place = ����� ������� ������)
                    if (key_1_1 && value_1_14) {
                        string value;//���������
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
                        poi_str[ind][prm].value = "0x2800";//TODO: �������, �� ����� ����� ������� ������
                        key_label = false;
                        key_1_1 = false;
                        key_1_14 = false;
                        value_1_14 = false;
                        UnkPoint_true++;
                        continue;
                    }
                    //11. if(U.P.F./Category of mooring/warping facility = �������,��������� �������)
                    if (key_1_1 && key_1_15 && value_1_15) {
                        if (!key_label) {
                            string value = "Mooring(" + buffer_1_15 + ")";
                            vector_add_KeyLabel_and_Value(poi_str, ind, value);
                        }
                        else if (key_label) {
                            poi_str[ind][ind_label].value = "Mooring(" + buffer_label + ")";
                        }
                        poi_str[ind][prm].value = "0x4700";//������� ������� � ��������
                        key_label = false;
                        key_1_1 = false;
                        key_1_15 = false;
                        value_1_15 = false;
                        UnkPoint_true++;
                        continue;
                    }
                    //12. if(U.P.F./Category of fog signal = ������)
                    if (key_1_1 && key_1_17 && value_1_16) {
                        if (key_label) {
                            poi_str[ind][ind_label].value = "Fog signal(" + buffer_label + ")";
                        }
                        else if (!key_label) {
                            string value = "Fog signal(" + buffer_1_17 + ")";
                            vector_add_KeyLabel_and_Value(poi_str, ind, value);
                        }
                        poi_str[ind][prm].value = "0xF304";//����������,������������� � ������������� �����
                        key_label = false;
                        key_1_1 = false;
                        key_1_17 = false;
                        value_1_16 = false;
                        UnkPoint_true++;
                        continue;
                    }
                    //13. if(U.P.F./Weed/Kelp = ���������)
                    if (!key_label && key_1_1 && value_1_17) {
                        string value = "Weed/Kelp";
                        vector_add_KeyLabel_and_Value(poi_str, ind, value);
                        poi_str[ind][prm].value = "0x6513";//�������������
                        key_1_1 = false;
                        value_1_17 = false;
                        UnkPoint_true++;
                        continue;
                    }
                    //14. if(U.P.F./Pile = �����)
                    if (key_1_1 && value_1_18) {
                        if (key_label)
                            poi_str[ind][ind_label].value = "Pile(" + buffer_label + ")";
                        else if (!key_label) {
                            string value = "Pile";
                            vector_add_KeyLabel_and_Value(poi_str, ind, value);
                        }
                        poi_str[ind][prm].value = "0xF30a";//��������� ������
                        key_label = false;
                        key_1_1 = false;
                        value_1_18 = false;
                        UnkPoint_true++;
                        continue;
                    }
                    //15. if(U.P.F,Signal station, warning||traffi = ���������� ������� �������������� || ������)
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
                        poi_str[ind][prm].value = "0xF304";//����������,������������� � ������������� �����
                        key_label = false;
                        key_1_1 = false;
                        value_1_19 = false;
                        value_1_20 = false;
                        UnkPoint_true++;
                        continue;
                    }
                    //16. if(U.P.F./Local magnetic anomaly = ������� ��������� ��������)
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

                        poi_str[ind][prm].value = "0x6500";//TODO: ������ �����������, �� ����� ������� ��������� ��������
                        key_label = false;
                        key_1_1 = false;
                        key_1_18 = false;
                        key_1_19 = false;
                        value_1_21 = false;
                        UnkPoint_true++;
                        continue;
                    }
                    //17. if(U.P.F./The dumping ground = ������)
                    if (key_1_1 && key_1_20 && value_1_22) {
                        if (!key_label) {
                            string value = "The dumping ground(" + buffer_1_20 + ")";
                            vector_add_KeyLabel_and_Value(poi_str, ind, value);
                        }
                        else if (key_label) {
                            poi_str[ind][ind_label].value = "The dumping ground(" + buffer_label + ")";
                        }
                        poi_str[ind][prm].value = "0x6500";//����������
                        key_label = false;
                        key_1_1 = false;
                        key_1_20 = false;
                        value_1_22 = false;
                        UnkPoint_true++;
                        continue;
                    }
                    //18. if(U.P.F./Land area(����� �� "������� ���������� �������")
                    if (!key_label && !key_1_4 && !key_1_7 && !key_1_16 && !key_1_19 &&
                        key_1_1 && value_1_2) {
                        string value;
                        if (key_1_21 && key_1_22)
                            value = "Land area";
                        else if (!key_1_21 && !key_1_22)
                            value = "Land area";
                        vector_add_KeyLabel_and_Value(poi_str, ind, value);
                        poi_str[ind][prm].value = "0x1100";//�������(����� 100)
                        key_1_1 = false;
                        key_1_21 = false;
                        key_1_22 = false;
                        value_1_2 = false;
                        UnkPoint_true++;
                        continue;
                    }
                    //19. if(U.P.F./Radio calling-in poin = ����� ����������)
                    if (key_1_1 && value_1_23) {
                        if (!key_label && key_1_23 && key_1_24) {
                            string value = "Radio calling-in point(" + buffer_1_23 + "," + buffer_1_24 + ")";
                            vector_add_KeyLabel_and_Value(poi_str, ind, value);
                        }
                        else if (key_label) {
                            poi_str[ind][ind_label].value = "Radio calling-in point(" + buffer_label + ")";
                        }
                        poi_str[ind][prm].value = "0xF304";//����������,������������� � ������������� �����
                        key_label = false;
                        key_1_1 = false;
                        key_1_23 = false;
                        key_1_24 = false;
                        value_1_23 = false;
                        UnkPoint_true++;
                        continue;
                    }
                    //20. if(U.P.F./Control point = ����������� �����)
                    if (key_1_1 && value_1_24) {
                        string value;
                        if (key_label && key_1_25)
                            poi_str[ind][ind_label].value = buffer_label + "(" + buffer_1_25 + ")";
                        else if (!key_label && key_1_25) {
                            value = "Control point (" + buffer_1_25 + ")";
                            vector_add_KeyLabel_and_Value(poi_str, ind, value);
                        }
                        else if (key_label && !key_1_25) {/*������ ��������� label;*/
                        }
                        else if (!key_label && !key_1_25) {
                            value = "Control point";
                            vector_add_KeyLabel_and_Value(poi_str, ind, value);
                        }
                        poi_str[ind][prm].value = "0x6300";//������� ������
                        key_label = false;
                        key_1_1 = false;
                        key_1_25 = false;
                        value_1_24 = false;
                        UnkPoint_true++;
                        continue;
                    }
                    //21. if(U.P.F./Sea area/named water area = ������� ����/��������� ���������)
                    if (key_1_1 && value_1_25) {
                        if (!key_label) {
                            string value = "Sea area/named water area";
                            vector_add_KeyLabel_and_Value(poi_str, ind, value);
                        }
                        else if (key_label) {
                            poi_str[ind][ind_label].value = "Sea area/named water area(" + buffer_label + ")";
                        }
                        poi_str[ind][prm].value = "0x650b";//������
                        key_label = false;
                        key_1_1 = false;
                        value_1_25 = false;
                        UnkPoint_true++;
                        continue;
                    }
                    //22. if(U.P.F./Rescue station = ������������ �������)
                    if (key_1_1 && value_1_26) {
                        if (key_label)
                            poi_str[ind][ind_label].value = "Rescue station(" + buffer_label + ")";
                        else if (!key_label) {
                            string value = "Rescue station";
                            vector_add_KeyLabel_and_Value(poi_str, ind, value);
                        }
                        poi_str[ind][prm].value = "0x6408";//��������
                        key_label = false;
                        key_1_1 = false;
                        value_1_26 = false;
                        UnkPoint_true++;
                        continue;
                    }
                    //23. if(U.P.F,Caution area = �������� ���������������)
                    if (key_1_1 && value_1_27) {
                        if (key_label)
                            poi_str[ind][ind_label].value = "Caution area(" + buffer_label + ")";
                        else if (!key_label) {
                            string value = "Caution area";
                            vector_add_KeyLabel_and_Value(poi_str, ind, value);
                        }
                        poi_str[ind][prm].value = "0x2800";//TODO: �������, �� �������� ����� ������� ��������������
                        key_label = false;
                        key_1_1 = false;
                        value_1_27 = false;
                        UnkPoint_true++;
                        continue;
                    }

                }
            }


            //2.��������������� ����� ����� = 0x00(��� �� ���������)
            if (poi_str[ind][prm].key == "Type" && poi_str[ind][prm].value == "0x00") {
                All0x00_point++;
                int ind_label;
                bool key_label = false;
                string buffer_label;

                bool key_2_1 = false;                    //FEATURE_DESCRIPTION(�������� �����������)
                bool key_2_2 = false; string buffer_2_2; //Nature of surface(������� �����������)
                bool key_2_3 = false;                    //Scale minimum(����������� �������)
                bool key_2_4 = false; string buffer_2_4; //Information(����������)
                bool key_2_5 = false; string buffer_2_5; //Water level effect(������ ������ ����)

                bool value_2_1 = false; //F_D=Seabed area(������� �������� ���)
                bool value_2_2 = false; //F_D=Anchor berth(������� ������)
                bool value_2_3 = false; //F_D=Anchorage area(������� ����)

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
                        buffer_2_5 = poi_str[ind][x_2].value;//������ ������ ����
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

                    //1. if(0x00/Seabed area = ������� �������� ���)
                    if (!key_label && key_2_1 && value_2_1 && (key_2_2 || key_2_4)) {
                        string value;
                        if (key_2_2)
                            value = "Seabed area(" + buffer_2_2 + ")";
                        else if (key_2_4)
                            value = "Seabed area(" + buffer_2_4 + ")";
                        vector_add_KeyLabel_and_Value(poi_str, ind, value);
                        poi_str[ind][prm].value = "0x1c07";//�����������, ���� ������ ����
                        key_2_1 = false;
                        key_2_2 = false;
                        key_2_4 = false;
                        value_2_1 = false;
                        P_0x00_true++;
                        continue;
                    }
                    //2. if(0x00/Seabed area = ������� �������� ���)
                    if (!key_label && key_2_1 && key_2_2 && key_2_5 && value_2_1) {
                        string value = "Seabed area(" + buffer_2_5 + ")";
                        vector_add_KeyLabel_and_Value(poi_str, ind, value);
                        poi_str[ind][prm].value = "0x1c07";//�����������, ���� ������ ����
                        key_2_1 = false;
                        key_2_2 = false;
                        key_2_5 = false;
                        value_2_1 = false;
                        P_0x00_true++;
                        continue;
                    }
                    //3. if(0x00/Category of anchorage,Anchor berth = ������� ������)
                    if (key_2_1 && key_2_3 && value_2_2) {
                        if (key_label)
                            poi_str[ind][ind_label].value = buffer_label;
                        else if (!key_label) {
                            string value = "Anchor berth";
                            vector_add_KeyLabel_and_Value(poi_str, ind, value);
                        }
                        poi_str[ind][prm].value = "0x4700";//������� ������� � ��������
                        key_label = false;
                        key_2_1 = false;
                        key_2_3 = false;
                        value_2_2 = false;
                        P_0x00_true++;
                        continue;
                    }
                    //4. if(0x00/Anchorage area = ������� ����)
                    if (key_2_1 && value_2_3) {
                        if (key_label)
                            poi_str[ind][ind_label].value = "Anchorage area(" + (buffer_label)+")";
                        if (!key_label) {
                            string value = "Anchorage area";
                            vector_add_KeyLabel_and_Value(poi_str, ind, value);
                        }
                        poi_str[ind][prm].value = "0x4700";//������� ������� � ��������
                        key_label = false;
                        key_2_1 = false;
                        value_2_3 = false;
                        P_0x00_true++;
                        continue;
                    }

                }
            }
            //����� ��������������� �����
        }
    }
    InfoOfTypesData(AllUnkPoint, UnkPoint_true, "����� ���� Unknown Point Feature");
    InfoOfTypesData(All0x00_point, P_0x00_true, "����� ���� 0x00");
}