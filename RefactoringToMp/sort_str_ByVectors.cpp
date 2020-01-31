#include "include.h"
#include "functions.h"

void sort_str_ByVectors(vector<string>& strings,
                        vector<vector<MyStruct>>& img_str,
                        vector<vector<MyStruct>>& poi_str,
                        vector<vector<MyStruct>>& polyline_str,
                        vector<vector<MyStruct>>& polygon_str
)
{

    bool save_ImgId = false;
    bool save_POI = false;
    bool save_POLYLINE = false;
    bool save_POLYGON = false;

    string buffer;
    vector<MyStruct> strOneBlock;//��������� ������ �����, �� ����������

    //���� ���������� ������ ������ � ������������ �� ��������
    for (int str = 0; str < strings.size(); str++) {

        buffer.clear();
        buffer = strings[str];

        //������ �����[IMG ID], ������ ���������� �������� � ������ "img_str"
        if (buffer == "[IMG ID]") { save_ImgId = true; strOneBlock.clear(); continue; }
        if (save_ImgId == true) {
            if (buffer == "[END-IMG ID]") {
                save_ImgId = false;
                img_str.push_back(strOneBlock);
                continue;
            }
            //� "strOneBlock".��������(sortKeyValue(������� ��������� ������, ��������� �� key,value));
            strOneBlock.push_back(sortKeyValue(buffer));
        }

        //������ �����[POI], ������ ���������� �������� � ������ "poi_str"
        if (buffer == "[POI]") { save_POI = true; strOneBlock.clear(); continue; }
        if (save_POI == true) {
            if (buffer == "[END]") {
                save_POI = false;
                poi_str.push_back(strOneBlock);
                continue;
            }
            strOneBlock.push_back(sortKeyValue(buffer));
        }

        //������ �����[POLYLINE], ������ ���������� �������� � ������ "polyline_str"
        if (buffer == "[POLYLINE]") { save_POLYLINE = true; strOneBlock.clear(); continue; }
        if (save_POLYLINE == true) {
            if (buffer == "[END]") {
                save_POLYLINE = false;
                polyline_str.push_back(strOneBlock);
                continue;
            }
            strOneBlock.push_back(sortKeyValue(buffer));
        }

        //������ �����[POLYGON], ������ ���������� �������� � ������ "polygon_str"
        if (buffer == "[POLYGON]") { save_POLYGON = true; strOneBlock.clear(); continue; }
        if (save_POLYGON == true) {
            if (buffer == "[END]") {
                save_POLYGON = false;
                polygon_str.push_back(strOneBlock);
                continue;
            }
            strOneBlock.push_back(sortKeyValue(buffer));
        }
    }

    cout << "................................................................................" << endl;
}