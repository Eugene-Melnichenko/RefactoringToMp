#include <cstdlib> //��� system
#include "include.h"
#include "functions.h"

int main()
{
    setlocale(0, "");

    vector<string> get_StringsInFile;			//��� ������ ��� ������������ �����
    vector<string> set_StringsInFile;			//��� ������ ��� ������������ �����

    //����<������� �����(������)<key,value>>
    vector<vector<MyStruct>> img_id;			//����  [IMG ID]	key=value 
    vector<vector<MyStruct>> all_POINTS;		//����� [POI]		key=value 
    vector<vector<MyStruct>> all_POLYLINES;		//����� [POLYLINE]	key=value	
    vector<vector<MyStruct>> all_POLYGON;		//����� [POLYGON]	key=value

    open_file(get_StringsInFile);	//������ ���� ����� ����� � get_StringsInFile

    //���������� ���� ����� ������� get_StringsInFile, �� ��������� ��������
    sort_str_ByVectors(get_StringsInFile, img_id, all_POINTS, all_POLYLINES, all_POLYGON);

    //��������� ���������
    edit_img_block(img_id);
    info_message(img_id);
    //��������� �������������� value � ������
    edit_POLYGON_blocks(all_POLYGON);
    edit_POLYLINE_blocks(all_POLYLINES);
    edit_POI_blocks(all_POINTS);

    //������ ����� � set_StringsInFil ��� �����, �� img_id, all_POINTS, all_POLYLINES, all_POLYGON
    sort_vectors_ForFile(set_StringsInFile, img_id, all_POINTS, all_POLYLINES, all_POLYGON);

    save_file(set_StringsInFile);//�� set_StringsInFile ������ � ���� ���� �����

    system("pause");

    return 0;
}