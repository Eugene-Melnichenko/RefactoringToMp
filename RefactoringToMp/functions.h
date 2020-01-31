#pragma once
#include "include.h"


void open_file(vector<string>& strings);
void save_file(vector<string>& strings);

void sort_str_ByVectors(vector<string>& strings,
						vector<vector<MyStruct>>& img_str, 
						vector<vector<MyStruct>>& poi_str,
						vector<vector<MyStruct>>& polyline_str,
						vector<vector<MyStruct>>& polygon_str
						);


void sort_vectors_ForFile(vector<string>& strings,
						  vector<vector<MyStruct>>& img_str,
						  vector<vector<MyStruct>>& poi_str,
						  vector<vector<MyStruct>>& polyline_str,
						  vector<vector<MyStruct>>& polygon_str
						  );

void edit_img_block	(vector<vector<MyStruct>>& img_str);
void edit_POI_blocks(vector<vector<MyStruct>>& poi_str);
void edit_POLYLINE_blocks(vector<vector<MyStruct>>& polyline_str);

void edit_POLYGON_blocks(vector<vector<MyStruct>>& polygon_str);
void edit_polygon_U_A_T_blocks(vector<vector<MyStruct>>& polygon_str, int ind, int prm, int& UnkAreaType_true);
void edit_polygon_M_I_A_blocks(vector<vector<MyStruct>>& polygon_str, int ind, int prm, int& MarineInfoArea_true);
void edit_polygon_0x54_blocks( vector<vector<MyStruct>>& polygon_str, int ind, int prm, int& Polygon_0x54_true);
void edit_polygon_0x00_blocks( vector<vector<MyStruct>>& polygon_str, int ind, int prm, int& Polygon_0x00_true);

//mini functions
MyStruct sortKeyValue(string buffer);
void deleteSpacesInString(string& string);
void vector_add_KeyLabel_and_Value(vector<vector<MyStruct>>& my_vector, int index, string my_value);
void InfoOfTypesData(int all_points, int true_points, string type);
void info_message(vector<vector<MyStruct>>& img_str);
