#include "include.h"
#include "functions.h"
void edit_POI_blocks(vector<vector<MyStruct>>& poi_str)
{
	for(int ind = 0; ind < poi_str.size(); ind++){
		for(int prm = 0; prm < poi_str[ind].size(); prm++){
		
		//1.��������������� ����� ����� = Unknown Point Feature(����������� �����)
			if (poi_str[ind][prm].key == "Type" && poi_str[ind][prm].value == "Unknown Point Feature")
			{
				int ind_label;
				bool key_label = false;
				string buffer_label;
				string buffer_1_1;
				string buffer_1_2;

				bool key_1_1    = false; //FEATURE_DESCRIPTION(�������� �����������)
				bool key_1_2    = false; //Scale minimum(����������� �������)
				bool key_1_3    = false; //Water level effect(������ ������ ����)
				bool key_1_4    = false; //Object name
				bool key_1_5    = false; //Category of slope(��������� ������)
				bool key_1_6    = false; //Category of landmark(��������� ���������)
				bool key_1_7    = false; //Function
				bool key_1_8    = false; //Reference year for magnetic variation(������� ��� ��� ��������� ��������)
				bool key_1_9    = false; //Value of annual change in magnetic variation(�������� �������� ��������� ���������� ����������)
				bool key_1_10   = false; //Value of magnetic variation(�������� ���������� ����������)
				bool key_1_11   = false; //Category of offshore platform(��������� ������� ���������)
				bool key_1_12   = false; //Category of silo/tank(��������� ������/���)
				bool key_1_13   = false; //Topmark/daymark shape(������� �������/daymark shape)
				bool key_1_14   = false; //Category of pilot boarding place(��������� ����� ������� ������)
				bool key_1_15   = false; //Category of mooring/warping facility(��������� �������)
				bool key_1_16   = false; //Status
				bool key_1_17   = false; //Category of fog signal(��������� ��������� �������)
				bool key_1_18   = false; //Value of local magnetic anomaly(�������� ��������� ��������� ��������)
				bool key_1_19   = false; //Information(����������)
				bool key_1_20   = false; //Category of dumping ground(��������� ������)

				bool value_1_1  = false; //F_D=Land region(��������� �������)
				bool value_1_2  = false; //F_D=Land area(������� ���������� �������)
				bool value_1_3  = false; //F_D=Sloping ground(��������� �������)
				bool value_1_4  = false; //hill(����)
				bool value_1_5  = false; //F_D=Landmark(��������)
				bool value_1_6  = false; //tower(�����)
				bool value_1_7  = false; //mast(�����)
				bool value_1_8  = false; //F_D=Magnetic variation(��������� ��������)
				bool value_1_9  = false; //F_D=Offshore platform(������� ���������)
				bool value_1_10 = false; //F_D=Silo / tank(������/���)				
				bool value_1_11 = false; //F_D=Obstruction(��������������)
				bool value_1_12 = false; //always under water/submerged(������ ��� ����� / �����������)
				bool value_1_13 = false; //F_D=Top mark(������� �������)
				bool value_1_14 = false; //F_D=Pilot boarding place(����� ������� ������)
				bool value_1_15 = false; //F_D=Mooring/warping facility(������ / ��������������)
				bool value_1_16 = false; //F_D=Fog signal(�������� ������)
				bool value_1_17 = false; //F_D=Weed/Kelp(���������)
				bool value_1_18 = false; //F_D=Pile
				bool value_1_19 = false; //F_D=Signal station, warning(���������� �������, ��������������)
				bool value_1_20 = false; //F_D=Signal station, traffic(���������� �������, ������)
				bool value_1_21 = false; //F_D=Local magnetic anomaly(������� ��������� ��������)
				bool value_1_22 = false; //F_D=The Dumping ground(������)


				for (int x_1 = 0; x_1 < poi_str[ind].size(); x_1++){
					//buffer_label
					if (poi_str[ind][x_1].key == "Label")
					{
						ind_label = x_1;
						key_label = true;
						buffer_label = poi_str[ind][x_1].value;
					}

					//key = trye, false?
					if (poi_str[ind][x_1].key == "FEATURE_DESCRIPTION")			
						key_1_1 = true;

					if (poi_str[ind][x_1].key == "SCAMIN - Scale minimum")			
						key_1_2 = true;

					if (poi_str[ind][x_1].key == "WATLEV - Water level effect")	
						key_1_3 = true;

					if (poi_str[ind][x_1].key == "OBJNAM - Object name")			
						key_1_4 = true;

					if (poi_str[ind][x_1].key == "CATSLO - Category of slope")			
						key_1_5 = true;

					if (poi_str[ind][x_1].key == "CATLMK - Category of landmark")
					{
						buffer_1_2 = poi_str[ind][x_1].value;
						key_1_6 = true;
					}

					if (poi_str[ind][x_1].key == "FUNCTN - Function")
					{
						buffer_1_1 = poi_str[ind][x_1].value;
						key_1_7 = true;
					}

					if (poi_str[ind][x_1].key == "RYRMGV - Reference year for magnetic variation")
					{
						key_1_8 = true;
						buffer_1_1 += "year:"+poi_str[ind][x_1].value;
					}

					if (poi_str[ind][x_1].key == "VALACM - Value of annual change in magnetic variation")
						key_1_9 = true;

					if (poi_str[ind][x_1].key == "VALMAG - Value of magnetic variation")		
					{
						buffer_1_1 += ",value:"+poi_str[ind][x_1].value;
						key_1_10 = true;
					}

					if (poi_str[ind][x_1].key == "CATOFP - Category of offshore platform")		
					{
						buffer_1_1 = poi_str[ind][x_1].value;
						key_1_11 = true;
					}

					if (poi_str[ind][x_1].key == "CATSIL - Category of silo/tank")		
					{
						buffer_1_1 = poi_str[ind][x_1].value;
						key_1_12 = true;
					}

					if (poi_str[ind][x_1].key == "TOPSHP - Topmark/daymark shape")		
					{
						buffer_1_1 = poi_str[ind][x_1].value;
						key_1_13 = true;
					}

					if (poi_str[ind][x_1].key == "CATPIL - Category of pilot boarding place")		
					{
						buffer_1_1 = poi_str[ind][x_1].value;
						key_1_14 = true;
					}

					if (poi_str[ind][x_1].key == "CATMOR - Category of mooring/warping facility")		
					{
						buffer_1_1 = poi_str[ind][x_1].value;
						key_1_15 = true;
					}

					if (poi_str[ind][x_1].key == "STATUS - Status")		
						key_1_16 = true;

					if (poi_str[ind][x_1].key == "CATFOG - Category of fog signal")
					{
						buffer_1_1 = poi_str[ind][x_1].value;
						key_1_17 = true;
					}

					if (poi_str[ind][x_1].key == "VALLMA - Value of local magnetic anomaly")
					{
						buffer_1_1 = poi_str[ind][x_1].value;
						key_1_18 = true;
					}

					if (poi_str[ind][x_1].key == "INFORM - Information")
					{
						buffer_1_2 = poi_str[ind][x_1].value;
						key_1_19 = true;
					}

					if (poi_str[ind][x_1].key == "CATDPG - Category of dumping ground")
					{
						buffer_1_1 = poi_str[ind][x_1].value;
						key_1_20 = true;
					}

					//value = trye, false?
					if (poi_str[ind][x_1].value == "Land region") 
						value_1_1 = true;

					if (poi_str[ind][x_1].value == "Land area") 
						value_1_2 = true;

					if (poi_str[ind][x_1].value == "Sloping ground") 
						value_1_3 = true;

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

					////if(Unknown Point Feature,Label,Object name,Land region) = 0x0400(�����)
					if(key_label && key_1_1 && key_1_2 && key_1_4 && value_1_1 && !value_1_2)
					{
						key_label = false;
						poi_str[ind][prm].value = "0x0400";
						key_1_1   = false;
						key_1_2   = false;
						key_1_4   = false;
						value_1_1 = false;
						continue;
					}
					////if(U.P.F,S,land area) = 0x6614(�����)
					if(!key_label && key_1_1 && key_1_2 && value_1_2)
					{
						string value = "Land area(Rock)";//������� ���������� �������(�����)
						vector_add_KeyLabel_and_Value(poi_str,ind,value);
						poi_str[ind][prm].value = "0x6614";//�����
						key_1_1    = false;
						key_1_2    = false;
						value_1_2  = false;
						continue;		
					}
					////if(U.P.F,Sloping ground,hill) = 0x6614(�����), �� �����(����)
					if(!key_label && key_1_1 && key_1_2 && key_1_5 && value_1_3 && value_1_4)
					{
						string value = "Sloping ground(hill)";//��������� �������(����)
						vector_add_KeyLabel_and_Value(poi_str,ind,value);
						poi_str[ind][prm].value = "0x6614";//�����
						key_1_1   = false;
						key_1_2   = false;
						key_1_5   = false;
						value_1_3 = false;
						value_1_4 = false;
						continue;
					}
					////if(U.P.F,Category of landmark,Landmark,tower) = 0x6411(�����) ��� 0x6400(������������� ����������)
					if(key_1_1 && key_1_2 && key_1_6 && value_1_5)
					{
						string value;
						if(key_1_7)
						{
							if(key_label && key_1_4 && value_1_6)
								poi_str[ind][ind_label].value = "Tower, "+ buffer_label;
							else if(!key_label && !key_1_4 && value_1_6)
							{
								value = "Tower";
								vector_add_KeyLabel_and_Value(poi_str,ind,value);
							}
							else if(key_label &&  key_1_4 && value_1_7)
								poi_str[ind][ind_label].value = "Mast, "+ buffer_label;
							else if(!key_label && !key_1_4 && value_1_7)
							{
								value = "Mast";
								vector_add_KeyLabel_and_Value(poi_str,ind,value);
							}
							poi_str[ind][prm].value = "0x6411";//�����, �����
						}
						else if(!key_1_7)
						{
							value = "Landmark("+buffer_1_2+")";
							vector_add_KeyLabel_and_Value(poi_str,ind,value);
							poi_str[ind][prm].value = "0x6400";//������������� ����������
						}
						key_label = false;
						key_1_1   = false;
						key_1_2   = false;
						key_1_4   = false;
						key_1_6   = false;
						value_1_5 = false;
						value_1_6 = false;
						value_1_7 = false;
						continue;
					}
					//if(U.P.F,Magnetic variation) = 0x6500(������ �����������), �� �����(��������� ��������)
					if(!key_label && key_1_1 && key_1_2 && key_1_8 && key_1_9 && key_1_10 && value_1_8)
					{
						string value = "Magnetic variation(" + buffer_1_1 + ")";//��������� ��������
						vector_add_KeyLabel_and_Value(poi_str,ind,value);
						poi_str[ind][prm].value = "0x6500";
						key_1_1   = false;
						key_1_2   = false;
						key_1_8   = false;
						key_1_9   = false;
						key_1_10  = false;
						value_1_8 = false;
						continue;
					}
					//if(U.P.F,Offshore platform) = 0x6400(������������� ����������), �� �����(������� ���������)
					if(key_1_1 && key_1_2 && key_1_11 && value_1_9)
					{
						if(key_label)
							poi_str[ind][ind_label].value = buffer_label + "(" + buffer_1_1 + ")";
						if(!key_label)
						{
							string value = "Offshore platform(" + buffer_1_1 + ")";
							vector_add_KeyLabel_and_Value(poi_str,ind,value);
						}
						poi_str[ind][prm].value = "0x6411";

						key_label = false;
						key_1_1   = false;
						key_1_2   = false;
						key_1_4   = false;
						key_1_11  = false;
						value_1_9 = false;
						continue;				
					}
					//if(U.P.F,Category of silo/tank) = 0x6400(������������� ����������), �� �����(������/���)
					if(!key_label && key_1_1 && key_1_2 && key_1_12 && value_1_10)
					{
						string value = "Silo/tank. Category="+buffer_1_1;
						vector_add_KeyLabel_and_Value(poi_str,ind,value);
						poi_str[ind][prm].value = "0x6600";
						key_1_1    = false;
						key_1_2    = false;
						key_1_12   = false;
						value_1_10 = false;
						continue;						
					}
					////if(U.P.F,S,Obstruction) = 0x1c07(�����������, ���� ������ ����)
					if(!key_label && key_1_1 && key_1_2 && key_1_3 && value_1_11)
					{	
						string value;
						if(value_1_12)
						{
							value = "Obstruction(always under water/submerged)";
							vector_add_KeyLabel_and_Value(poi_str,ind,value);
							poi_str[ind][prm].value = "0x1c07";
						}
						key_1_1    = false;
						key_1_2    = false;
						key_1_3    = false;
						value_1_11 = false;
						value_1_12 = false;
						continue;		
					}
					//if(U.P.F,Top mark) = 0x6500(������ �����������), �� �����(������� �������)
					if(!key_label && key_1_1 && key_1_2 && key_1_13 && value_1_13)
					{
						//string value = "Top mark("+buffer_1_1+")";
						string value = "Top mark";
						vector_add_KeyLabel_and_Value(poi_str,ind,value);
						poi_str[ind][prm].value = "0x6500";
						key_1_1    = false;
						key_1_2    = false;
						key_1_13   = false;
						value_1_13 = false;
						continue;						
					}
					//if(U.P.F,Pilot boarding place) = 0x2800(�������), �� �����(����� ������� ������)
					if(!key_label && key_1_1 && key_1_2 && key_1_14 && value_1_14)
					{
						string value = buffer_1_1;
						vector_add_KeyLabel_and_Value(poi_str,ind,value);
						poi_str[ind][prm].value = "0x2800";
						key_1_1    = false;
						key_1_2    = false;
						key_1_14   = false;
						value_1_14 = false;
						continue;	
					}
					//if(U.P.F,Category of mooring/warping facility) = 0x6500(������ �����������), �� �����(��������� �������)
					if(!key_label && key_1_1 && key_1_2 && key_1_15 && key_1_16 && value_1_15)
					{
						string value = buffer_1_1;
						vector_add_KeyLabel_and_Value(poi_str,ind,value);
						poi_str[ind][prm].value = "0x6500";
						key_1_1    = false;
						key_1_2    = false;
						key_1_15   = false;
						key_1_16   = false;
						value_1_15 = false;
						continue;
					}
					//if(U.P.F,Category of fog signal) = 0x1802(����� ����), �� �����(������)
					if(!key_label && key_1_1 && key_1_2 && key_1_17 && value_1_16)
					{
						string value = "Fog signal("+buffer_1_1+")";
						vector_add_KeyLabel_and_Value(poi_str,ind,value);
						poi_str[ind][prm].value = "0x1802";
						key_1_1    = false;
						key_1_2    = false;
						key_1_17   = false;
						value_1_16 = false;
						continue;
					}
					//if(U.P.F,Weed/Kelp) = 0x1�06(�������� �� ������ ����), �� �����(���������)
					if(!key_label && key_1_1 && key_1_2 && value_1_17)
					{
						string value = "Weed/Kelp";
						vector_add_KeyLabel_and_Value(poi_str,ind,value);
						poi_str[ind][prm].value = "0x1c06";
						key_1_1    = false;
						key_1_2    = false;
						value_1_17 = false;
						continue;
					}
					//if(U.P.F,Weed/Kelp) = 0x2800(�������), �� �����(Pile)
					if(!key_label && key_1_1 && key_1_2 && value_1_18)
					{
						string value = "Pile";
						vector_add_KeyLabel_and_Value(poi_str,ind,value);
						poi_str[ind][prm].value = "0x2800";
						key_1_1    = false;
						key_1_2    = false;
						value_1_18 = false;
						continue;
					}
					//if(U.P.F,Signal station, warning||traffic) = 0x6411(�����), �� �����(���������� �������, �������������� ��� ������)
					if(!key_label && key_1_1 && key_1_2 && (value_1_19 || value_1_20))
					{
						string value;
						if(value_1_19)
							value = "Signal station, warning";
						else if(value_1_20)
							value = "Signal station, traffic";

						vector_add_KeyLabel_and_Value(poi_str,ind,value);
						poi_str[ind][prm].value = "0x6411";
						key_1_1    = false;
						key_1_2    = false;
						value_1_19 = false;
						value_1_20 = false;
						continue;
					}
					//if(U.P.F,Local magnetic anomaly) = 0x6500(������ �����������), �� �����(������� ��������� ��������ile)
					if(!key_label && key_1_1 && key_1_2 && key_1_18 && key_1_19 && value_1_21)
					{
						string value = "Local magnetic anomaly(value:"+buffer_1_1+";inform:"+buffer_1_2+";)";
						vector_add_KeyLabel_and_Value(poi_str,ind,value);
						poi_str[ind][prm].value = "0x6500";
						key_1_1    = false;
						key_1_2    = false;
						key_1_18   = false;
						key_1_19   = false;
						value_1_21 = false;
						continue;
					}
					//if(U.P.F,the dumping ground) = 0x6400(������������� ����������), �� �����(������)
					if(!key_label && key_1_1 && key_1_2 && key_1_16 && key_1_19 && key_1_20 && value_1_22)
					{
						string value = "The dumping ground("+buffer_1_1+")";
						vector_add_KeyLabel_and_Value(poi_str,ind,value);
						poi_str[ind][prm].value = "0x6400";
						key_1_1    = false;
						key_1_2    = false;
						key_1_16   = false;
						key_1_19   = false;
						key_1_20   = false;
						value_1_22 = false;
						continue;
					}

				}
			}

		//2.��������������� ����� ����� = 0x00(��� �� ��������)
			if (poi_str[ind][prm].key == "Type" && poi_str[ind][prm].value == "0x00")
			{	
				int ind_label;
				bool key_label = false;
				string buffer_label;
				string buffer_2_1;
				string buffer_2_2;

				bool key_2_1   = false; //FEATURE_DESCRIPTION(�������� �����������)
				bool key_2_2   = false; //NATSUR - Nature of surface(������� �����������)
				bool key_2_3   = false; //SCAMIN - Scale minimum(����������� �������)
				bool key_2_4   = false; //INFORM - Information(����������)

				bool value_2_1 = false; //Seabed area(������� �������� ���)
				bool value_2_2 = false; //Anchor berth(������� ������)
				
				for (int x_2 = 0; x_2 < poi_str[ind].size(); x_2++){
					//buffer_label
					if (poi_str[ind][x_2].key == "Label")
					{
						ind_label = x_2;
						key_label = true;
						buffer_label = poi_str[ind][x_2].value;
					}
					//key = trye, false?
					if (poi_str[ind][x_2].key == "FEATURE_DESCRIPTION")			
						key_2_1 = true;

					if (poi_str[ind][x_2].key == "NATSUR - Nature of surface")
					{
						key_2_2 = true;
						buffer_2_1 = poi_str[ind][x_2].value;
					}

					if (poi_str[ind][x_2].key == "SCAMIN - Scale minimum")			
						key_2_3 = true;

					if (poi_str[ind][x_2].key == "INFORM - Information")
					{
						key_2_4 = true;
						buffer_2_2 = poi_str[ind][x_2].value;
					}

					//value = trye, false?
					if (poi_str[ind][x_2].value == "Seabed area")
						value_2_1 = true;

					if (poi_str[ind][x_2].value == "Anchor berth")
					{
						value_2_2 = true;
						buffer_label += " Anchor berth";
					}

					//if(0x00,Nature of surface,Information,Seabed area) = 0x1c07(�����������, ���� ������ ����)
					if(!key_label && key_2_1 && key_2_2 && key_2_3 && key_2_4 && value_2_1)
					{
						string value = "Seabed area("+buffer_2_1+")";
						vector_add_KeyLabel_and_Value(poi_str,ind,value);
						poi_str[ind][prm].value = "0x1c07";//�����������, ���� ������ ����
						key_2_1   = false;
						key_2_2   = false;
						key_2_3   = false;
						key_2_4   = false;
						value_2_1 = false;
						continue;
					}
					////if(0x00,Nature of surface,Seabed area) = 0x1c07(�����������, ���� ������ ����)
					if(!key_label && key_2_1 && key_2_2 && key_2_3 && value_2_1 && !key_2_4)
					{
						string value = "Seabed area("+buffer_2_1+")";
						vector_add_KeyLabel_and_Value(poi_str,ind,value);
						poi_str[ind][prm].value = "0x1c07";//�����������, ���� ������ ����
						key_2_1   = false;
						key_2_2   = false;
						key_2_3   = false;
						value_2_1 = false;
						continue;
					}
					//if(0x00,Information,Seabed area) = 0x1c07(�����������, ���� ������ ����)
					if(!key_label && key_2_1 && key_2_3 && key_2_4 && value_2_1 && !key_2_2)
					{
						string value = "Seabed area("+buffer_2_2+")";
						vector_add_KeyLabel_and_Value(poi_str,ind,value);
						poi_str[ind][prm].value = "0x1c07";//�����������, ���� ������ ����
						key_2_1   = false;
						key_2_3   = false;
						key_2_4   = false;
						value_2_1 = false;
						continue;
					}
					//if(0x00,Category of anchorage,Anchor berth) = 0x1200(�������� � ���������������)
					if(key_label && key_2_1 && key_2_3 && value_2_2)
					{
						poi_str[ind][ind_label].value = buffer_label;
						poi_str[ind][prm].value = "0x1200";//�������� � ���������������
						key_label = false;
						key_2_1   = false;
						key_2_3   = false;
						value_2_2 = false;
						continue;
					}
				}
			}
		//����� ��������������� ���������
		}
	}
}