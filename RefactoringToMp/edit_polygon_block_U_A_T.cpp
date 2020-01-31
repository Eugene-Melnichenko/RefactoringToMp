#include "include.h"
#include "functions.h"

//��������������� ��������� ����� = Unknown Area Type(����������� ��� �������)
void edit_polygon_U_A_T_blocks(vector<vector<MyStruct>>& polygon_str, int ind, int prm, int& UnkAreaType_true)
{
    int ind_label;
    bool key_label = false;
    string buffer_label;

    bool key_1_1 = false; string buffer_1_1;  //FEATURE_DESCRIPTION(�������� �����������)
    bool key_1_2 = false; string buffer_1_2;  //NATION - Nationality(����� - ��������������)
    bool key_1_3 = false; string buffer_1_3;  //Category of shoreline construction(��������� ������������� ��������� �����)
    bool key_1_4 = false; string buffer_1_4;  //Horizontal datum(�������������� ������)
    bool key_1_5 = false; string buffer_1_5;  //Shift parameters(��������� ������)
    bool key_1_6 = false; string buffer_1_6;  //Category of slope(��������� ������)
    bool key_1_7 = false; string buffer_1_7;  //Nature of surface(������� �����������)
    bool key_1_8 = false; string buffer_1_8;  //Value of local magnetic anomaly(�������� ��������� ��������� ��������)
    bool key_1_9 = false; string buffer_1_9;  //Information(����������)
    bool key_1_10 = false; string buffer_1_10; //Water level effect(������ ������ ����)
    bool key_1_11 = false; string buffer_1_11; //Depth range value(�������� ��������� �������)
    bool key_1_12 = false; string buffer_1_12; //Category of road(��������� ������)
    bool key_1_13 = false; string buffer_1_13; //Nature of construction(������� �������������)


    bool value_1_1 = false; //F_D=Coverage(��������)
    bool value_1_2 = false; //F_D=Administration area(������������� �������))
    bool value_1_3 = false; //F_D=Harbour area (administrative) = �������� �����(����������������)
    bool value_1_4 = false; //F_D=Quality of data(�������� ������, �������� ���� ������� �� �����)
    bool value_1_5 = false; //F_D=Navigational system of marks(������������� ������� ������, �������� ���� ������� �� �����)
    bool value_1_6 = false; //F_D=Nautical publication information(���������� � ������� �����������, �������� ���� ������� �� �����)
    bool value_1_7 = false; //F_D=Magnetic variation(��������� ��������, �������� ���� ������� �� �����)
    bool value_1_8 = false; //F_D=Shoreline Construction(��������� �����, ��������)
    bool value_1_9 = false; //F_D=Continental shelf area(��������������� ������� ������)
    bool value_1_10 = false; //F_D=Horizontal datum shift parameters(��������� ��������������� ������)
    bool value_1_11 = false; //F_D=Sloping ground(�������� �������)
    bool value_1_12 = false; //F_D=Local magnetic anomaly(������� ��������� ��������)
    bool value_1_13 = false; //F_D=Exclusive Economic Zone(������������ ������������� ����)
    bool value_1_14 = false; //F_D=Seabed area(������� �������� ���)
    bool value_1_15 = false; //F_D=Dredged area(������������� ������� ,���������������� ������)
    bool value_1_16 = false; //F_D=Dam(�����)
    bool value_1_17 = false; //F_D=Road(������)
    bool value_1_18 = false; //F_D=Territorial sea area(��������������� ������� �����)
    bool value_1_19 = false; //F_D=Causeway(����, �����)
    bool value_1_20 = false; //F_D=Dyke(�����)
    bool value_1_21 = false; //F_D=Vegetation(��������������)


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

        //1. if(Unknown Area Type,Coverage = ��������)
        if (key_1_1 && value_1_1) {
            if (!key_label) {
                string value = buffer_1_1;
                vector_add_KeyLabel_and_Value(polygon_str, ind, value);
            }
            polygon_str[ind][prm].value = "0x0001";//��������� ����� > 200�
            key_1_1 = false;
            value_1_1 = false;
            UnkAreaType_true++;
            continue;
        }
        //2. if(U.A.T./Administration area = ������������� �������)
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
            polygon_str[ind][prm].value = "0x0001";//��������� ����� > 200�
            key_1_1 = false;
            key_1_2 = false;
            key_1_9 = false;
            value_1_2 = false;
            UnkAreaType_true++;
            continue;
        }
        //3. if(U.A.T./Harbour area(administrative) = �������� �����(����������������)
        if (key_1_1 && value_1_3) {
            if (!key_label) {
                string value = "Harbour area (administrative)";
                vector_add_KeyLabel_and_Value(polygon_str, ind, value);
            }
            polygon_str[ind][prm].value = "0x4a";//TODO: ��������� ������� ��������� �����, ���������� �������, ����� ��������� �� �������� �����(����������������)
            key_1_1 = false;
            value_1_3 = false;
            UnkAreaType_true++;
            continue;
        }
        //4. if(U.A.T./Quality of data = �������� ������, �������� ���� ������� �� �����)
        if (key_1_1 && value_1_4) {
            if (!key_label) {
                string value = "Quality of data";
                vector_add_KeyLabel_and_Value(polygon_str, ind, value);
            }
            polygon_str[ind][prm].value = "0x4a";//������� ��������� �����
            key_1_1 = false;
            value_1_4 = false;
            UnkAreaType_true++;
            continue;
        }
        //5. if(U.A.T./Navigational system of marks = ������������� ������� ������)
        if (key_1_1 && value_1_5) {
            if (!key_label) {
                string value = "Navigational system of marks";
                vector_add_KeyLabel_and_Value(polygon_str, ind, value);
            }
            polygon_str[ind][prm].value = "0x4a";//TODO: ������� ��������� �����, ����� ���������.
            key_1_1 = false;
            value_1_5 = false;
            UnkAreaType_true++;
            continue;
        }
        //6. if(U.A.T./Nautical publication information = ���������� � ������� �����������,�������� ���� ������� �� �����)
        if (key_1_1 && value_1_6) {
            if (!key_label) {
                string value = "Nautical publication information";
                vector_add_KeyLabel_and_Value(polygon_str, ind, value);
            }
            polygon_str[ind][prm].value = "0x4a";//������� ��������� �����
            key_1_1 = false;
            value_1_6 = false;
            UnkAreaType_true++;
            continue;
        }
        //7. if(U.A.T/Magnetic variation = ��������� ��������,�������� ���� ������� �� �����)
        if (key_1_1 && value_1_7) {
            if (!key_label) {
                string value = "Magnetic variation";
                vector_add_KeyLabel_and_Value(polygon_str, ind, value);
            }
            polygon_str[ind][prm].value = "0x4a";//TODO: ��������� ������� ��������� �����, ����� ���������.
            key_1_1 = false;
            value_1_7 = false;
            UnkAreaType_true++;
            continue;
        }
        //8. if(U.A.T./Shoreline Construction = ��������� �����, ��������)
        if (key_1_1 && value_1_8) {
            if (!key_label) {
                string value;
                if (key_1_3)
                    value = "Shoreline Construction(" + buffer_1_3 + ")";
                else if (!key_1_3)
                    value = "Shoreline Construction";
                vector_add_KeyLabel_and_Value(polygon_str, ind, value);
            }
            polygon_str[ind][prm].value = "0x0009";//��������
            key_1_1 = false;
            value_1_8 = false;
            UnkAreaType_true++;
            continue;
        }
        //9. if(U.A.T./Continental shelf area = ��������������� ������� ������)
        if (key_1_1 && value_1_9) {
            if (!key_label) {
                string value;
                if (key_1_2)
                    value = "Continental shelf area(" + buffer_1_2 + ")";
                else if (!key_1_2)
                    string value = "Continental shelf area";
                vector_add_KeyLabel_and_Value(polygon_str, ind, value);
            }
            polygon_str[ind][prm].value = "0x4a";//TODO: ������� ��������� �����, ����� ���������.
            key_1_1 = false;
            value_1_9 = false;
            UnkAreaType_true++;
            continue;
        }
        //10. if(U.A.T./Horizontal datum shift parameters = ��������� ��������������� ������)
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
            polygon_str[ind][prm].value = "0x4a";//TODO: ������� ��������� �����, ����� ���������.
            key_1_1 = false;
            key_1_4 = false;
            key_1_5 = false;
            value_1_10 = false;
            UnkAreaType_true++;
            continue;
        }
        //11. if(U.A.T./Sloping ground = �������� �������)
        if (key_1_1 && value_1_11) {
            string value;
            if (!key_label) {
                //(cliff || rock = ���� || ������)
                if (buffer_1_6.find("(cliff)") != string::npos || buffer_1_7.find("(rock)") != string::npos) {
                    value = "Sloping ground(" + buffer_1_6 + " " + buffer_1_7 + ")";
                    vector_add_KeyLabel_and_Value(polygon_str, ind, value);
                    polygon_str[ind][prm].value = "0x0003";//TODO: �������,�� ���������� ���������� � ��������� �������� ���������� ����, �� ����� ���� ��� ������
                    UnkAreaType_true++;
                }
            }
            else if (key_label) {
                polygon_str[ind][prm].value = "0x0003";//��������� ����� < 200�
                UnkAreaType_true++;
            }
            key_1_1 = false;
            key_1_6 = false;
            key_1_7 = false;
            value_1_11 = false;
            continue;
        }
        //12. if(U.A.T./Local magnetic anomaly=������� ��������� ��������)
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
            polygon_str[ind][prm].value = "0x4a";//TODO: ������� ��������� �����, ����������� ����� ���������.
            key_1_1 = false;
            key_1_8 = false;
            key_1_9 = false;
            value_1_12 = false;
            UnkAreaType_true++;
            continue;
        }
        //13. if(U.A.T./Exclusive Economic Zone=������������ ������������� ����)
        if (key_1_1 && value_1_13) {
            if (!key_label) {
                string value;
                if (key_1_9)
                    value = "Exclusive Economic Zone(Information:" + buffer_1_9 + ")";
                else
                    value = "Exclusive Economic Zone";
                vector_add_KeyLabel_and_Value(polygon_str, ind, value);
            }
            polygon_str[ind][prm].value = "0x4a";//TODO: ������� ��������� �����, ����������� ����� ���������.
            key_1_1 = false;
            key_1_9 = false;
            value_1_13 = false;
            UnkAreaType_true++;
            continue;
        }
        //14. if(U.A.T./Seabed area = ������� �������� ���)
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
            polygon_str[ind][prm].value = "0x0053";//TODO: ����������, �������� ����� ������� �������� ���.
            key_1_1 = false;
            key_1_7 = false;
            key_1_10 = false;
            value_1_14 = false;
            UnkAreaType_true++;
            continue;
        }
        //15. if(U.A.T./Dredged area = ������������� �������, ���������������� ������)
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
            polygon_str[ind][prm].value = "0x4a";//TODO: ������� ��������� �����,�������� ����� ������������� �������.
            key_1_1 = false;
            key_1_9 = false;
            key_1_11 = false;
            value_1_15 = false;
            UnkAreaType_true++;
            continue;
        }
        //16. if(U.A.T./Dam = �����)
        if (key_1_1 && value_1_16) {
            if (!key_label) {
                string value = "Dam";
                vector_add_KeyLabel_and_Value(polygon_str, ind, value);
            }
            else
                polygon_str[ind][ind_label].value = "Dam(" + buffer_label + ")";
            polygon_str[ind][prm].value = "0x0013";//TODO: ������, ������������� ����������, ����� �����.
            key_1_1 = false;
            value_1_16 = false;
            UnkAreaType_true++;
            continue;
        }
        //17. if(U.A.T./Road = ������)
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
            polygon_str[ind][prm].value = "0x0003";//TODO: ��������� ��������� ����, ����������� ����� ������.
            key_1_1 = false;
            key_1_12 = false;
            value_1_17 = false;
            UnkAreaType_true++;
            continue;
        }
        //18. if(U.A.T./Territorial sea area = ��������������� ������� �����)
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
            polygon_str[ind][prm].value = "0x4a";//TODO: ������� ��������� �����, ����� ��������������� ������� �����.
            key_1_1 = false;
            key_1_2 = false;
            value_1_18 = false;
            UnkAreaType_true++;
            continue;
        }
        //19. if(U.A.T./Causeway = ���� ��� �����)
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
            polygon_str[ind][prm].value = "0x0013";//TODO: ������, ������������� ����������, ����� ���� ��� �����.
            key_1_1 = false;
            key_1_13 = false;
            value_1_19 = false;
            UnkAreaType_true++;
            continue;
        }
        //20. if(U.A.T./Dyke = �����)
        if (key_1_1 && value_1_20) {
            if (!key_label) {
                string value = "Dyke";
                vector_add_KeyLabel_and_Value(polygon_str, ind, value);
            }
            else
                polygon_str[ind][ind_label].value = "Dyke(" + buffer_label + ")";
            polygon_str[ind][prm].value = "0x0013";//TODO: ������, ������������� ����������, ����� �����.
            key_1_1 = false;
            value_1_20 = false;
            UnkAreaType_true++;
            continue;
        }
        //21. if(U.A.T./Vegetation = ��������������)
        if (key_1_1 && value_1_21) {
            if (!key_label) {
                string value = "Vegetation";
                vector_add_KeyLabel_and_Value(polygon_str, ind, value);
            }
            else
                polygon_str[ind][ind_label].value = "Vegetation(" + buffer_label + ")";
            polygon_str[ind][prm].value = "0x004f";//���������
            key_1_1 = false;
            value_1_21 = false;
            UnkAreaType_true++;
            continue;
        }
    }
}//����� ��������������� ��������� ����� = Unknown Area Type(����������� ��� �������)