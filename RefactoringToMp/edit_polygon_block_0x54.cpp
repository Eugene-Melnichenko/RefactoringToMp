#include "include.h"
#include "functions.h"

//��������������� ��������� ����� = 0x54(����������� ���)
void edit_polygon_0x54_blocks(vector<vector<MyStruct>>& polygon_str, int ind, int prm, int& Polygon_0x54_true)
{
    int ind_label;
    bool key_label = false;
    string buffer_label;

    bool key_3_1 = false;  string buffer_3_1; //FEATURE_DESCRIPTION
    bool key_3_3 = false;  string buffer_3_3; //CATLND - Category of land region(��������� ���������� �������)
    bool key_3_4 = false;  string buffer_3_4; //NATSUR - Nature of surface(������� �����������)

    bool value_3_1 = false; //F_D=Land region(��������� �������)
    bool value_3_2 = false; //F_D=Land area(������� ���������� �������)

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

        //1. if(0x54/Land region = ��������� �������)
        if (key_3_1 && !key_3_3 && !key_3_4 && value_3_1) {
            if (!key_label) {
                string value = "Land region";
                vector_add_KeyLabel_and_Value(polygon_str, ind, value);
            }
            polygon_str[ind][prm].value = "0x0002";//��������� ����� < 200�
            key_3_1 = false;
            value_3_1 = false;
            Polygon_0x54_true++;
            continue;
        }
        //2. if(0x54/Land region = ����� �� ��������� �������)
        if (key_3_1 && key_3_3 && value_3_1) {
            string value;
            bool lowlands = buffer_3_3.find("(lowlands)") != string::npos;//������, �������
            bool marsh = buffer_3_3.find("(marsh)") != string::npos; //������
            bool swamp = buffer_3_3.find("(swamp)") != string::npos; //������
            bool fen = buffer_3_3.find("(fen)") != string::npos; //������
            if (!key_label) {
                if (lowlands) {
                    value = "Land region(" + buffer_3_3 + ")";
                    vector_add_KeyLabel_and_Value(polygon_str, ind, value);
                    polygon_str[ind][prm].value = "0x004f"; //������� ����
                    Polygon_0x54_true++;
                }
                else if (marsh || swamp || fen) {
                    value = buffer_3_3; //������
                    vector_add_KeyLabel_and_Value(polygon_str, ind, value);
                    polygon_str[ind][prm].value = "0x0051";//������
                    Polygon_0x54_true++;
                }
                else
                {
                    value = "Land region";
                    vector_add_KeyLabel_and_Value(polygon_str, ind, value);
                    polygon_str[ind][prm].value = "0x0002"; //��������� ����� < 200�
                    Polygon_0x54_true++;
                }
            }
            else if (key_label) {
                polygon_str[ind][prm].value = "0x0002"; //��������� ����� < 200�
                Polygon_0x54_true++;
            }
            key_3_1 = false;
            key_3_3 = false;
            value_3_1 = false;
            continue;
        }
        //3. if(0x54/Land region = ����� �� ��������� �������)
        if (!key_label && key_3_1 && !key_3_3 && key_3_4 && value_3_1) {
            string value;
            bool sand = buffer_3_4.find("(sand)") != string::npos;//�����
            bool stone = buffer_3_4.find("(stone)") != string::npos;//������
            bool sand_and_stone = (buffer_3_4.find("(sand)") != string::npos) && (buffer_3_4.find("(stone)") != string::npos); //����� � ������
            bool pebbles = buffer_3_4.find("(pebbles)") != string::npos; //���������, �������

            if (sand_and_stone) {
                value = "Land region(" + buffer_3_4 + ")"; //����� � ������
                vector_add_KeyLabel_and_Value(polygon_str, ind, value);
                polygon_str[ind][prm].value = "0x0003";//TODO: ��������� ��������� ����, �� ����� ����� � ������.
                Polygon_0x54_true++;
            }
            else if (sand && !stone) { //�����
                value = "Land region(" + buffer_3_4 + ")";
                vector_add_KeyLabel_and_Value(polygon_str, ind, value);
                polygon_str[ind][prm].value = "0x0003";//TODO: ��������� ��������� ����, �� ����� �����.
                Polygon_0x54_true++;
            }
            else if (stone && !sand) { //������
                value = "Land region(" + buffer_3_4 + ")";
                vector_add_KeyLabel_and_Value(polygon_str, ind, value);
                polygon_str[ind][prm].value = "0x0003";//TODO: ��������� ��������� ����, �� ����� ������.
                Polygon_0x54_true++;
            }
            else if (pebbles) { //���������, �������
                value = "Land region(" + buffer_3_4 + ")";
                vector_add_KeyLabel_and_Value(polygon_str, ind, value);
                polygon_str[ind][prm].value = "0x0003";//TODO: ��������� ��������� ����, �� ������ ���������, �������.
                Polygon_0x54_true++;
            }

            key_3_1 = false;
            key_3_4 = false;
            value_3_1 = false;
            continue;
        }
        //4. if(0x54/Land area = ������� ���������� �������)
        if (key_3_1 && value_3_2 && !key_3_3 && !key_3_4) {
            if (!key_label)
                polygon_str[ind][prm].value = "0x004a"; //������� ��������� �����
            else if (key_label)
                polygon_str[ind][prm].value = "0x0002"; //��������� ����� < 200�
            key_3_1 = false;
            value_3_2 = false;
            key_label = false;
            Polygon_0x54_true++;
            continue;
        }
    }
}