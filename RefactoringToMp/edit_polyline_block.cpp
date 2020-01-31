#include "include.h"
#include "functions.h"

void edit_POLYLINE_blocks(vector<vector<MyStruct>>& polyline_str)
{
    int AllUnkLineType = 0; //��������� ���������� ��������� ��������� ����(Unknown Line Type)
    int UnkLineType_true = 0; //���������� ����������� ��������� ����(Unknown Line Type)
    int UnkALineType_false = 0; //���������� �� ����������� ��������� ����(Unknown Line Type)				

    for (int ind = 0; ind < polyline_str.size(); ind++) {
        for (int prm = 0; prm < polyline_str[ind].size(); prm++) {

            //1.��������������� ��������� ����� = Unknown Line Type(����������� ��� �����)
            if (polyline_str[ind][prm].key == "Type" && polyline_str[ind][prm].value == "Unknown Line Type") {
                AllUnkLineType++;
                int ind_label;
                bool key_label = false;
                string buffer_label;

                bool key_1_1 = false; string buffer_1_1; //FEATURE_DESCRIPTION(�������� �����������) 
                bool key_1_2 = false; string buffer_1_2; //Status
                bool key_1_3 = false; string buffer_1_3; //Category of shoreline construction(��������� ������������� ��������� �����)
                bool key_1_4 = false; string buffer_1_4; //Water level effect(������ ������ ����)
                bool key_1_5 = false; string buffer_1_5; //Category of Traffic Separation Scheme(��������� ����� ���������� ��������)
                bool key_1_6 = false; string buffer_1_6; //Nationality(��������������)
                bool key_1_7 = false; string buffer_1_7; //Source date(���� ���������)
                bool key_1_8 = false; string buffer_1_8; //Source indication(��������� ���������)
                bool key_1_9 = false; string buffer_1_9; //Category of fishing  facility(��������� ������� �������)

                bool value_1_1 = false; //F_D=Shoreline Construction(������������� ��������� �����)
                bool value_1_2 = false; //F_D=Traffic Separation Scheme Boundary(������� ����� ���������� ��������)
                bool value_1_3 = false; //F_D=Straight territorial sea baseline(������ ��������������� ����� ����)
                bool value_1_4 = false; //F_D=Traffic Separation Line(����� ���������� �������)
                bool value_1_5 = false; //F_D=Land area(������� ���������� �������)
                bool value_1_6 = false; //F_D=Dyke(�����)
                bool value_1_7 = false; //F_D=Slope topline(��������� �����, �������� ������)
                bool value_1_8 = false; //F_D=Radar line(�������� �����)
                bool value_1_9 = false; //F_D=Fishing facility(���������� ���������)
                bool value_1_10 = false;//F_D=Causeway(�����)

                for (int x_1 = 0; x_1 < polyline_str[ind].size(); x_1++) {
                    //buffer_label
                    if (polyline_str[ind][x_1].key == "Label") {
                        ind_label = x_1;
                        key_label = true;
                        buffer_label = polyline_str[ind][x_1].value;
                    }
                    //key = trye, false?
                    if (polyline_str[ind][x_1].key == "FEATURE_DESCRIPTION") {
                        buffer_1_1 = polyline_str[ind][x_1].value;
                        key_1_1 = true;
                    }
                    if (polyline_str[ind][x_1].key == "STATUS - Status") {
                        buffer_1_2 = polyline_str[ind][x_1].value;
                        key_1_2 = true;
                    }
                    if (polyline_str[ind][x_1].key == "CATSLC - Category of shoreline construction") {
                        buffer_1_3 = polyline_str[ind][x_1].value;
                        key_1_3 = true;
                    }

                    if (polyline_str[ind][x_1].key == "WATLEV - Water level effect") {
                        buffer_1_4 = polyline_str[ind][x_1].value;
                        key_1_4 = true;
                    }
                    if (polyline_str[ind][x_1].key == "CATTSS - Category of Traffic Separation Scheme") {
                        buffer_1_5 = polyline_str[ind][x_1].value;
                        key_1_5 = true;
                    }

                    if (polyline_str[ind][x_1].key == "NATION - Nationality") {
                        buffer_1_6 = polyline_str[ind][x_1].value;
                        key_1_6 = true;
                    }
                    if (polyline_str[ind][x_1].key == "SORDAT - Source date") {
                        buffer_1_7 = polyline_str[ind][x_1].value;
                        key_1_7 = true;
                    }
                    if (polyline_str[ind][x_1].key == "SORIND - Source indication") {
                        buffer_1_8 = polyline_str[ind][x_1].value;
                        key_1_8 = true;
                    }
                    if (polyline_str[ind][x_1].key == "CATFIF - Category of fishing  facility") {
                        buffer_1_9 = polyline_str[ind][x_1].value;
                        key_1_9 = true;
                    }
                    //value = trye, false?
                    if (polyline_str[ind][x_1].value == "Shoreline Construction")
                        value_1_1 = true;
                    if (polyline_str[ind][x_1].value == "Traffic Separation Scheme Boundary")
                        value_1_2 = true;
                    if (polyline_str[ind][x_1].value == "Straight territorial sea baseline")
                        value_1_3 = true;
                    if (polyline_str[ind][x_1].value == "Traffic Separation Line")
                        value_1_4 = true;
                    if (polyline_str[ind][x_1].value == "Land area")
                        value_1_5 = true;
                    if (polyline_str[ind][x_1].value == "Dyke")
                        value_1_6 = true;
                    if (polyline_str[ind][x_1].value == "Slope topline")
                        value_1_7 = true;
                    if (polyline_str[ind][x_1].value == "Radar line")
                        value_1_8 = true;
                    if (polyline_str[ind][x_1].value == "Fishing facility")
                        value_1_9 = true;
                    if (polyline_str[ind][x_1].value == "Causeway")
                        value_1_10 = true;

                    //1. if(Unknown Line Type/Shoreline Construction = ��������� �����)
                    if (key_label && key_1_1 && value_1_1) {
                        string value;
                        if (key_1_2 && key_1_3 && key_1_4)
                            polyline_str[ind][ind_label].value = "Shoreline Construction(" + buffer_label + ";Status:" + buffer_1_2 + ";Category:" + buffer_1_3 + ";Water level:" + buffer_1_4 + ")";
                        if (!key_1_2 && key_1_3 && key_1_4)
                            polyline_str[ind][ind_label].value = "Shoreline Construction(" + buffer_label + ";Category:" + buffer_1_3 + ";Water level:" + buffer_1_4 + ")";
                        if (!key_1_2 && key_1_3 && !key_1_4)
                            polyline_str[ind][ind_label].value = "Shoreline Construction(" + buffer_label + ";Category:" + buffer_1_3 + ")";
                        if (!key_1_2 && !key_1_3 && !key_1_4)
                            polyline_str[ind][ind_label].value = "Shoreline Construction(" + buffer_label + ")";
                        polyline_str[ind][prm].value = "0x0015";//��������� �����
                        key_1_1 = false;
                        key_1_2 = false;
                        key_1_3 = false;
                        key_1_4 = false;
                        value_1_1 = false;
                        UnkLineType_true++;
                        continue;
                    }
                    //2. if(U.L.T./Shoreline Construction = ��������� �����)
                    if (!key_label && key_1_1 && value_1_1) {
                        string value;
                        if (key_1_2 && key_1_3 && key_1_4)
                            value = "Shoreline Construction(Status:" + buffer_1_2 + ";Category:" + buffer_1_3 + ";Water level:" + buffer_1_4 + ")";
                        if (!key_1_2 && key_1_3 && key_1_4)
                            value = "Shoreline Construction(Category:" + buffer_1_3 + ";Water level:" + buffer_1_4 + ")";
                        if (!key_1_2 && key_1_3 && !key_1_4)
                            value = "Shoreline Construction(Category:" + buffer_1_3 + ")";
                        if (!key_1_2 && !key_1_3 && !key_1_4)
                            value = "Shoreline Construction";
                        vector_add_KeyLabel_and_Value(polyline_str, ind, value);
                        polyline_str[ind][prm].value = "0x0015";//��������� �����
                        key_1_1 = false;
                        key_1_2 = false;
                        key_1_3 = false;
                        key_1_4 = false;
                        value_1_1 = false;
                        UnkLineType_true++;
                        continue;
                    }
                    //3. if(U.L.T./Traffic Separation Scheme Boundary = ������� ����� ���������� ��������)
                    if (key_1_1 && key_1_5 && value_1_2) {
                        string value;
                        if (key_label)
                            polyline_str[ind][ind_label].value = "Traffic Separation Scheme Boundary(" + buffer_label + ";Category:" + buffer_1_5 + ")";
                        else if (!key_label) {
                            if (!key_1_2)
                                value = "Traffic Separation Scheme Boundary(Category:" + buffer_1_5 + ")";
                            else if (key_1_2)
                                value = "Traffic Separation Scheme Boundary(Status:" + buffer_1_2 + ";Category:" + buffer_1_5 + ")";
                            vector_add_KeyLabel_and_Value(polyline_str, ind, value);
                        }
                        polyline_str[ind][prm].value = "0x001d";//����� �������
                        key_1_1 = false;
                        key_1_2 = false;
                        key_1_5 = false;
                        value_1_2 = false;
                        UnkLineType_true++;
                        continue;
                    }
                    //4. if(U.L.T./Traffic Separation Scheme Boundary = ������� ����� ���������� ��������)
                    if (key_1_1 && !key_1_5 && value_1_2) {
                        string value;
                        if (key_label)
                            polyline_str[ind][ind_label].value = "Traffic Separation Scheme Boundary(" + buffer_label + ")";
                        else if (!key_label) {
                            value = "Traffic Separation Scheme Boundary)";
                            vector_add_KeyLabel_and_Value(polyline_str, ind, value);
                        }
                        polyline_str[ind][prm].value = "0x001d";//����� �������
                        key_1_1 = false;
                        value_1_2 = false;
                        UnkLineType_true++;
                        continue;
                    }
                    //5. if(U.L.T/Straight territorial sea baseline = ������ ��������������� ����� ����))
                    if (key_1_1 && value_1_3) {
                        string value;
                        if (!key_label) {
                            if (key_1_6)
                                value = "Straight territorial sea baseline(Nationality:" + buffer_1_6 + ")";
                            else if (!key_1_6)
                                value = "Straight territorial sea baseline";
                            vector_add_KeyLabel_and_Value(polyline_str, ind, value);
                        }
                        polyline_str[ind][prm].value = "0x001d";//����� �������
                        key_1_1 = false;
                        value_1_3 = false;
                        UnkLineType_true++;
                        continue;
                    }
                    //6. if(U.L.T./Traffic Separation Line = ����� ���������� �������)
                    if (key_1_1 && key_1_5 && value_1_4) {
                        string value;
                        if (!key_label) {
                            if (!key_1_2)
                                value = "Traffic Separation Line(Category:" + buffer_1_5 + ")";
                            else if (key_1_2)
                                value = "Traffic Separation Line(Status:" + buffer_1_2 + ";Category:" + buffer_1_5 + ")";
                            vector_add_KeyLabel_and_Value(polyline_str, ind, value);
                        }
                        polyline_str[ind][prm].value = "0x001d";//����� �������
                        key_1_1 = false;
                        key_1_2 = false;
                        key_1_5 = false;
                        value_1_4 = false;
                        UnkLineType_true++;
                        continue;
                    }
                    //7. if(U.L.T./Land area = ������� ���������� �������)
                    if (key_1_1 && value_1_5) {
                        string value;
                        if (key_label && key_1_2)
                            polyline_str[ind][ind_label].value = "Land area(" + buffer_label + ";Status:" + buffer_1_2 + ")";
                        else if (key_label && !key_1_2)
                            polyline_str[ind][ind_label].value = "Land area(" + buffer_label + ")";
                        else if (!key_label) {
                            if (key_1_2)
                                value = "Land area(Status:" + buffer_1_2 + ")";
                            else if (!key_1_2)
                                value = "Land area";
                            vector_add_KeyLabel_and_Value(polyline_str, ind, value);
                        }
                        polyline_str[ind][prm].value = "0x0709";//��������� ���������������� ����� �����, ���(�����)
                        key_1_1 = false;
                        key_1_2 = false;
                        value_1_5 = false;
                        UnkLineType_true++;
                        continue;
                    }
                    //8. if(U.L.T./Dyke = �����)
                    if (key_1_1 && value_1_6) {
                        if (key_label)
                            polyline_str[ind][ind_label].value = "Dyke(" + buffer_label + ")";
                        else if (!key_label) {
                            string value = "Dyke";
                            vector_add_KeyLabel_and_Value(polyline_str, ind, value);
                        }
                        polyline_str[ind][prm].value = "0x040c";//����� � ������������ ����
                        key_1_1 = false;
                        value_1_6 = false;
                        UnkLineType_true++;
                        continue;
                    }
                    //9. if(U.L.T./Slope topline = ��������� �����, �������� �����)
                    if (key_1_1 && value_1_7) {
                        if (key_label)
                            polyline_str[ind][ind_label].value = "Slope topline(" + buffer_label + ")";
                        else if (!key_label) {
                            string value = "Slope topline";
                            vector_add_KeyLabel_and_Value(polyline_str, ind, value);
                        }
                        polyline_str[ind][prm].value = "0x0308";//�������� �����
                        key_1_1 = false;
                        value_1_7 = false;
                        UnkLineType_true++;
                        continue;
                    }
                    //10. if(U.L.T./Radar line = �������� �����)
                    if (key_1_1 && value_1_8) {
                        if (key_label) {
                            if (key_1_7 && key_1_8)
                                polyline_str[ind][ind_label].value = "Radar line(" + buffer_label + ";Source date:" + buffer_1_7 + ";Source indication:" + buffer_1_8 + ")";
                            if (key_1_7 && !key_1_8)
                                polyline_str[ind][ind_label].value = "Radar line(" + buffer_label + ";Source date:" + buffer_1_7 + ")";
                            if (!key_1_7 && key_1_8)
                                polyline_str[ind][ind_label].value = "Radar line(" + buffer_label + ";Source indication:" + buffer_1_8 + ")";
                            if (!key_1_7 && !key_1_8)
                                polyline_str[ind][ind_label].value = "Radar line(" + buffer_label + ")";
                        }
                        else if (!key_label) {
                            string value;
                            if (key_1_7 && key_1_8)
                                value = "Radar line(Source date:" + buffer_1_7 + ";Source indication:" + buffer_1_8 + ")";
                            if (key_1_7 && !key_1_8)
                                value = "Radar line(Source date:" + buffer_1_7 + ")";
                            if (!key_1_7 && key_1_8)
                                value = "Radar line(Source indication:" + buffer_1_8 + ")";
                            if (!key_1_7 && !key_1_8)
                                value = "Radar line";
                            vector_add_KeyLabel_and_Value(polyline_str, ind, value);
                        }
                        polyline_str[ind][prm].value = "0x002a";///TODO: ������� �������, �������� ����� �������� �����
                        key_1_1 = false;
                        key_1_7 = false;
                        key_1_8 = false;
                        value_1_8 = false;
                        UnkLineType_true++;
                        continue;
                    }
                    //11. if(U.L.T./Fishing stake = ���������� ���������)
                    if (key_1_1 && value_1_9) {
                        if (key_label) {
                            if (key_1_2 && key_1_9)
                                polyline_str[ind][ind_label].value = "Fishing stake(" + buffer_label + ";Status:" + buffer_1_2 + ";Category:" + buffer_1_9 + ")";
                            if (key_1_2 && !key_1_9)
                                polyline_str[ind][ind_label].value = "Fishing stake(" + buffer_label + ";Status:" + buffer_1_2 + ")";
                            if (!key_1_2 && key_1_9)
                                polyline_str[ind][ind_label].value = "Fishing stake(" + buffer_label + ";Category:" + buffer_1_9 + ")";
                            if (!key_1_2 && !key_1_9)
                                polyline_str[ind][ind_label].value = "Fishing stake(" + buffer_label + ")";
                        }
                        else if (!key_label) {
                            string value;
                            if (key_1_2 && key_1_9)
                                value = "Fishing stake(Status:" + buffer_1_2 + ";Category:" + buffer_1_9 + ")";
                            if (key_1_2 && !key_1_9)
                                value = "Fishing stake(Status:" + buffer_1_2 + ")";
                            if (!key_1_2 && key_1_9)
                                value = "Fishing stake(Category:" + buffer_1_9 + ")";
                            if (!key_1_2 && !key_1_9)
                                value = "Fishing stake";
                            vector_add_KeyLabel_and_Value(polyline_str, ind, value);
                        }
                        polyline_str[ind][prm].value = "0x040c";//����, �������, �����
                        key_1_1 = false;
                        key_1_2 = false;
                        key_1_9 = false;
                        value_1_9 = false;
                        UnkLineType_true++;
                        continue;
                    }
                    //12. if(U.L.T./Causeway = �����)
                    if (key_1_1 && value_1_10) {
                        string value;
                        if (key_label && key_1_2)
                            polyline_str[ind][ind_label].value = "Causeway(" + buffer_label + ";Status:" + buffer_1_2 + ")";
                        else if (key_label && !key_1_2)
                            polyline_str[ind][ind_label].value = "Causeway(" + buffer_label + ")";
                        else if (!key_label) {
                            if (key_1_2)
                                value = "Causeway(Status:" + buffer_1_2 + ")";
                            else if (!key_1_2)
                                value = "Causeway";
                            vector_add_KeyLabel_and_Value(polyline_str, ind, value);
                        }
                        polyline_str[ind][prm].value = "0x040c";//����� � ������������ ����
                        key_1_1 = false;
                        key_1_2 = false;
                        value_1_10 = false;
                        UnkLineType_true++;
                        continue;
                    }
                }
            }
            //����� ��������������� ���������
        }
    }
    InfoOfTypesData(AllUnkLineType, UnkLineType_true, "����� ���� Unknown Line Type");
}