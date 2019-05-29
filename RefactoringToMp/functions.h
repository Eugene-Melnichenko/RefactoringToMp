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

//mini functions
MyStruct sortKeyValue(string buffer);
void deleteSpacesInString(string& string);
void vector_add_KeyLabel_and_Value(vector<vector<MyStruct>>& my_vector, int index, string my_value);
