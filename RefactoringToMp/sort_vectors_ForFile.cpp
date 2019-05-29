#include "include.h"

void sort_vector(string name_block, vector<string>& strings, vector<vector<MyStruct>>& type_vector, string key[]);

void sort_vectors_ForFile( vector<string>& strings,
						   vector<vector<MyStruct>>& img_str,
						   vector<vector<MyStruct>>& poi_str,
						   vector<vector<MyStruct>>& polyline_str,
						   vector<vector<MyStruct>>& polygon_str
						   )
{
		string str;	
		string keys[] = {"Type","Label","Data0"};

		sort_vector("[IMG ID]",	  strings, img_str,      keys);	//������ ��������� ����� [IMG ID]
		sort_vector("[POI]",	  strings, poi_str,		 keys);	//������ �������� [POI], �� ���������� keys[] 
		sort_vector("[POLYLINE]", strings, polyline_str, keys);	//������ �������� [POLYLINE], �� ���������� keys[] 
		sort_vector("[POLYGON]",  strings, polygon_str,  keys);	//������ �������� [POLYGON], �� ���������� keys[] 
		
}

//������� ������ mp ������� �� ������ ��������.
void sort_vector(string name_block, vector<string>& strings, vector<vector<MyStruct>>& type_vector, string key[])
{
		string str;
		for(int plg=0; plg < type_vector.size(); plg++) {
			strings.push_back(name_block);
				for(int plg_prm = 0; plg_prm < type_vector[plg].size(); plg_prm++ ){
					if (name_block == "[IMG ID]")
					{
						//� ����� IMG ID �������� ��� ���������
						str = type_vector[plg][plg_prm].key + "=" + type_vector[plg][plg_prm].value;
						strings.push_back(str);
					}
					else
					{
						//� ��������� ����� �������� ��������� ������� ������� � keys[]
						if (type_vector[plg][plg_prm].key == key[0] || type_vector[plg][plg_prm].key == key[1] || type_vector[plg][plg_prm].key == key[2])
						{
							str = type_vector[plg][plg_prm].key + "=" + type_vector[plg][plg_prm].value;
							strings.push_back(str);
						}
					}
				}

			if (name_block == "[IMG ID]")
				strings.push_back("[END-IMG ID]\n");
			else
				strings.push_back("[END]\n");
		}
}