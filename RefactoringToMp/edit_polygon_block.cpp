#include "include.h"

void edit_POLYGON_blocks(vector<vector<MyStruct>>& polygon_str)
{
/*	� �������� ���������, ����� ����:
		-Type=Unknown Area Type(����������� ��� �������);
		-Type=Marine Info Area(������� �������������� ����);
		-0x54(����������� ���)
	��� ��������� ���������� �� ������ ���, ������������ �� ������ ���������� �������

*/

	
	for(int ind = 0; ind < polygon_str.size(); ind++){
		for(int prm = 0; prm < polygon_str[ind].size(); prm++){

		//1.��������������� ��������� ����� = Unknown Area Type(����������� ��� �������)
			if (polygon_str[ind][prm].key == "Type" && polygon_str[ind][prm].value == "Unknown Area Type")
			{
				bool key_1_1   = false; //FEATURE_DESCRIPTION(�������� �����������)
				bool key_1_2   = false; //NATION - Nationality(����� - ��������������)
				bool key_1_3   = false; //CATSLC - Category of shoreline construction(��������� �����)

				bool value_1_1 = false; //Administration area (Named)(������������� �������)
				bool value_1_2 = false; //Sloping ground(�����, ����, �������)
				bool value_1_3 = false; //Shoreline Construction(��������� �����, ��������)
				bool value_1_4 = false; //Nautical publication information(���������� ��� ������ ������������ �����)

				for (int x_1 = 0; x_1 < polygon_str[ind].size(); x_1++){
					//key = trye, false?

					if (polygon_str[ind][x_1].key == "FEATURE_DESCRIPTION")			
						key_1_1 = true;

					if (polygon_str[ind][x_1].key == "NATION - Nationality")			
						key_1_2 = true;

					if (polygon_str[ind][x_1].key == "CATSLC - Category of shoreline construction")			
						key_1_3 = true;
					
					//value = trye, false?
					if (polygon_str[ind][x_1].value == "Administration area (Named)") 
						value_1_1 = true;

					if (polygon_str[ind][x_1].value == "Sloping ground") 
						value_1_2 = true;

					if (polygon_str[ind][x_1].value == "Shoreline Construction") 
						value_1_3 = true;

					if (polygon_str[ind][x_1].value == "Nautical publication information") 
						value_1_4 = true;

					//if(Unknown Area Type,NATION-Nationality,Administration area) = 0x0001(��������� ����� > 200�)
					if (key_1_1 && key_1_2 && value_1_1)
					{
						polygon_str[ind][prm].value = "0x0001";
						key_1_2 = false;
						key_1_1 = false;
						value_1_1 = false;
						continue;
					}
					//if(U.A.T,Sloping ground) = 0x0002(��������� ����� < 200�)
					if (key_1_1 && value_1_2)
					{
						polygon_str[ind][prm].value = "0x0002";
						key_1_1 = false;
						value_1_2 = false;
						continue;
					}
					//if(U.A.T,Category of shoreline construction,Shoreline Construction = 0x0009(��������)
					if (key_1_1 && key_1_3 && value_1_3)//true
					{
						polygon_str[ind][prm].value = "0x0009";
						key_1_1 = false;
						key_1_3 = false;
						value_1_3 = false;
						continue;
					}
					//if(U.A.T,Nautical publication information)=0x0002(��������� ����� < 200�),��� ������ ������������ �����
					if (key_1_1 && value_1_4)//true
					{
						polygon_str[ind][prm].value = "0x0002";
						key_1_1 = false;
						value_1_4 = false;
						continue;
					}
					//if(Unknown Area Type) = 0x004a(������� ��������� �����)
					if (!key_1_1 && !key_1_2 && !key_1_3 && !value_1_1 && !value_1_2 && !value_1_3)
					{
						polygon_str[ind][prm].value = "0x004a";
						continue;
					}

				}
			}


		//2.��������������� ��������� ����� = Marine Info Area(������� �������������� ����)
			//if (unknown_key == "Type" && unknown_value == "Marine Info Area")


		//3.��������������� ��������� ����� = 0x54(����������� ���)
			if (polygon_str[ind][prm].key == "Type" && polygon_str[ind][prm].value == "0x54")
			{
				bool key_3_1   = false; //FEATURE_DESCRIPTION
				bool key_3_2   = false; //Label
				bool key_3_3   = false; //CATLND - Category of land region(��������� ���������� �������)
				bool key_3_4   = false; //NATSUR - Nature of surface(������� �����������)
				
				bool value_3_1 = false; //Land region(��������� �������)
				bool value_3_2 = false; //Land area(������� ���������� �������)
				bool value_3_3 = false; //fen(������)
				bool value_3_4 = false; //sand(�����)

				for (int x_3 = 0; x_3 < polygon_str[ind].size(); x_3++){
					//key = trye, false?
					if (polygon_str[ind][x_3].key == "FEATURE_DESCRIPTION")			
						key_3_1 = true;

					if (polygon_str[ind][x_3].key == "Label")			
						key_3_2 = true;

					if (polygon_str[ind][x_3].key == "CATLND - Category of land region")			
						key_3_3 = true;

					if (polygon_str[ind][x_3].key == "NATSUR - Nature of surface")			
						key_3_4 = true;

					//value = trye, false?
					if (polygon_str[ind][x_3].value == "Land region")			
						value_3_1 = true;

					if (polygon_str[ind][x_3].value == "Land area")			
						value_3_2 = true;

					if (polygon_str[ind][x_3].value.find("(fen)") != string::npos)			
						value_3_3 = true;

					if (polygon_str[ind][x_3].value.find("(sand)") != string::npos)			
						value_3_4 = true;

					//if(0x54,Category of land region,Land region,fen) = 0x51(������)
					if(key_3_1 == true && key_3_3 == true && value_3_1 == true && value_3_3 == true)
					{
						polygon_str[ind][prm].value = "0x51";
						key_3_1 = false;
						key_3_3 = false;
						value_3_1 = false;
						value_3_3 = false;
						continue;
					}
					//if(0x54,Land region,Sand) = 0x0003(��������� ��������� ����), �� ����� �����!
					if(key_3_1 == true && key_3_4 == true && value_3_1 == true && value_3_4 == true)
					{
						polygon_str[ind][prm].value = "0x0003";
						key_3_1 = false;
						key_3_4 = false;
						value_3_1 = false;
						value_3_4 = false;
						continue;
					}
					//if(Land region) = 0x0002(��������� ����� < 200�)
					if(key_3_1 && key_3_2 && value_3_1)
					{
						polygon_str[ind][prm].value = "0x0002";
						key_3_1 = false;
						key_3_2 = false;
						value_3_2 = false;
						continue;
					}
					//if(���� ������ ����: Land area) = 0x004a(������� ��������� �����)
					if(key_3_1 && value_3_2)
					{
						polygon_str[ind][prm].value = "0x004a";
						key_3_1 = false;
						value_3_2 = false;
						continue;
					}
				}
			}//����� ��������������� ���������
		}
	}
}