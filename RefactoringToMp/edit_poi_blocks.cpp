#include "include.h"
#include "functions.h"
void edit_POI_blocks(vector<vector<MyStruct>>& poi_str)
{
	for(int ind = 0; ind < poi_str.size(); ind++){
		for(int prm = 0; prm < poi_str[ind].size(); prm++){
		
		//1.Переобразование точок типов = Unknown Point Feature(Неизвестная точка)
			if (poi_str[ind][prm].key == "Type" && poi_str[ind][prm].value == "Unknown Point Feature")
			{
				int ind_label;
				bool key_label = false;
				string buffer_label;
				string buffer_1_1;
				string buffer_1_2;

				bool key_1_1    = false; //FEATURE_DESCRIPTION(Описание особенности)
				bool key_1_2    = false; //Scale minimum(Минимальный масштаб)
				bool key_1_3    = false; //Water level effect(Эффект уровня воды)
				bool key_1_4    = false; //Object name
				bool key_1_5    = false; //Category of slope(Категория склона)
				bool key_1_6    = false; //Category of landmark(Категория ориентира)
				bool key_1_7    = false; //Function
				bool key_1_8    = false; //Reference year for magnetic variation(Базовый год для магнитных вариаций)
				bool key_1_9    = false; //Value of annual change in magnetic variation(Значение годового изменения магнитного отклонения)
				bool key_1_10   = false; //Value of magnetic variation(Значение магнитного отклонения)
				bool key_1_11   = false; //Category of offshore platform(Категория морской платформы)
				bool key_1_12   = false; //Category of silo/tank(Категория бункер/бак)
				bool key_1_13   = false; //Topmark/daymark shape(Верхняя отметка/daymark shape)
				bool key_1_14   = false; //Category of pilot boarding place(Категория места посадки пилота)
				bool key_1_15   = false; //Category of mooring/warping facility(Категория причала)
				bool key_1_16   = false; //Status
				bool key_1_17   = false; //Category of fog signal(Категория туманного сигнала)
				bool key_1_18   = false; //Value of local magnetic anomaly(Значение локальной магнитной аномалии)
				bool key_1_19   = false; //Information(Информация)
				bool key_1_20   = false; //Category of dumping ground(Категория свалки)

				bool value_1_1  = false; //F_D=Land region(Земельный участок)
				bool value_1_2  = false; //F_D=Land area(Площадь земельного участка)
				bool value_1_3  = false; //F_D=Sloping ground(Наклонная площадь)
				bool value_1_4  = false; //hill(холм)
				bool value_1_5  = false; //F_D=Landmark(ориентир)
				bool value_1_6  = false; //tower(башня)
				bool value_1_7  = false; //mast(мачта)
				bool value_1_8  = false; //F_D=Magnetic variation(магнитная вариация)
				bool value_1_9  = false; //F_D=Offshore platform(морская платформа)
				bool value_1_10 = false; //F_D=Silo / tank(бункер/бак)				
				bool value_1_11 = false; //F_D=Obstruction(непроходимость)
				bool value_1_12 = false; //always under water/submerged(всегда под водой / погруженный)
				bool value_1_13 = false; //F_D=Top mark(Верхняя отметка)
				bool value_1_14 = false; //F_D=Pilot boarding place(Место посадки пилота)
				bool value_1_15 = false; //F_D=Mooring/warping facility(Причал / деформирование)
				bool value_1_16 = false; //F_D=Fog signal(Туманный сигнал)
				bool value_1_17 = false; //F_D=Weed/Kelp(Водоросли)
				bool value_1_18 = false; //F_D=Pile
				bool value_1_19 = false; //F_D=Signal station, warning(Сигнальная станция, предупреждение)
				bool value_1_20 = false; //F_D=Signal station, traffic(Сигнальная станция, трафик)
				bool value_1_21 = false; //F_D=Local magnetic anomaly(Местная магнитная аномалия)
				bool value_1_22 = false; //F_D=The Dumping ground(Свалка)


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

					////if(Unknown Point Feature,Label,Object name,Land region) = 0x0400(Город)
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
					////if(U.P.F,S,land area) = 0x6614(Скала)
					if(!key_label && key_1_1 && key_1_2 && value_1_2)
					{
						string value = "Land area(Rock)";//Площадь земельного участка(скала)
						vector_add_KeyLabel_and_Value(poi_str,ind,value);
						poi_str[ind][prm].value = "0x6614";//Скала
						key_1_1    = false;
						key_1_2    = false;
						value_1_2  = false;
						continue;		
					}
					////if(U.P.F,Sloping ground,hill) = 0x6614(Скала), но нужно(холм)
					if(!key_label && key_1_1 && key_1_2 && key_1_5 && value_1_3 && value_1_4)
					{
						string value = "Sloping ground(hill)";//Наклонная площадь(холм)
						vector_add_KeyLabel_and_Value(poi_str,ind,value);
						poi_str[ind][prm].value = "0x6614";//Скала
						key_1_1   = false;
						key_1_2   = false;
						key_1_5   = false;
						value_1_3 = false;
						value_1_4 = false;
						continue;
					}
					////if(U.P.F,Category of landmark,Landmark,tower) = 0x6411(Башня) или 0x6400(Искусственное сооружение)
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
							poi_str[ind][prm].value = "0x6411";//Башня, вышка
						}
						else if(!key_1_7)
						{
							value = "Landmark("+buffer_1_2+")";
							vector_add_KeyLabel_and_Value(poi_str,ind,value);
							poi_str[ind][prm].value = "0x6400";//Искусственное сооружение
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
					//if(U.P.F,Magnetic variation) = 0x6500(Объект гидрографии), но нужно(Магнитная вариация)
					if(!key_label && key_1_1 && key_1_2 && key_1_8 && key_1_9 && key_1_10 && value_1_8)
					{
						string value = "Magnetic variation(" + buffer_1_1 + ")";//Магнитная вариация
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
					//if(U.P.F,Offshore platform) = 0x6400(Искусственное сооружение), но нужно(морская платформа)
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
					//if(U.P.F,Category of silo/tank) = 0x6400(Искусственное сооружение), но нужно(Бункер/бак)
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
					////if(U.P.F,S,Obstruction) = 0x1c07(препятствие, ниже уровня воды)
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
					//if(U.P.F,Top mark) = 0x6500(Объект гидрографии), но нужно(Верхняя отметка)
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
					//if(U.P.F,Pilot boarding place) = 0x2800(Надпись), но нужно(Место посадки пилота)
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
					//if(U.P.F,Category of mooring/warping facility) = 0x6500(Объект гидрографии), но нужно(Категория причала)
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
					//if(U.P.F,Category of fog signal) = 0x1802(Радио маяк), но нужно(сигнал)
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
					//if(U.P.F,Weed/Kelp) = 0x1с06(Преграда на уровне воды), но нужно(водоросли)
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
					//if(U.P.F,Weed/Kelp) = 0x2800(Надпись), но нужно(Pile)
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
					//if(U.P.F,Signal station, warning||traffic) = 0x6411(Башня), но нужно(Сигнальная станция, предупреждение или трафик)
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
					//if(U.P.F,Local magnetic anomaly) = 0x6500(Объект гидрографии), но нужно(Местная магнитная аномалияile)
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
					//if(U.P.F,the dumping ground) = 0x6400(Искусственное сооружение), но нужно(свалка)
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

		//2.Переобразование точок типов = 0x00(Тип не опредёлен)
			if (poi_str[ind][prm].key == "Type" && poi_str[ind][prm].value == "0x00")
			{	
				int ind_label;
				bool key_label = false;
				string buffer_label;
				string buffer_2_1;
				string buffer_2_2;

				bool key_2_1   = false; //FEATURE_DESCRIPTION(Описание особенности)
				bool key_2_2   = false; //NATSUR - Nature of surface(Природа поверхности)
				bool key_2_3   = false; //SCAMIN - Scale minimum(Минимальный масштаб)
				bool key_2_4   = false; //INFORM - Information(Информация)

				bool value_2_1 = false; //Seabed area(Площадь морского дна)
				bool value_2_2 = false; //Anchor berth(Якорный причал)
				
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

					//if(0x00,Nature of surface,Information,Seabed area) = 0x1c07(препятствие, ниже уровня воды)
					if(!key_label && key_2_1 && key_2_2 && key_2_3 && key_2_4 && value_2_1)
					{
						string value = "Seabed area("+buffer_2_1+")";
						vector_add_KeyLabel_and_Value(poi_str,ind,value);
						poi_str[ind][prm].value = "0x1c07";//препятствие, ниже уровня воды
						key_2_1   = false;
						key_2_2   = false;
						key_2_3   = false;
						key_2_4   = false;
						value_2_1 = false;
						continue;
					}
					////if(0x00,Nature of surface,Seabed area) = 0x1c07(препятствие, ниже уровня воды)
					if(!key_label && key_2_1 && key_2_2 && key_2_3 && value_2_1 && !key_2_4)
					{
						string value = "Seabed area("+buffer_2_1+")";
						vector_add_KeyLabel_and_Value(poi_str,ind,value);
						poi_str[ind][prm].value = "0x1c07";//препятствие, ниже уровня воды
						key_2_1   = false;
						key_2_2   = false;
						key_2_3   = false;
						value_2_1 = false;
						continue;
					}
					//if(0x00,Information,Seabed area) = 0x1c07(препятствие, ниже уровня воды)
					if(!key_label && key_2_1 && key_2_3 && key_2_4 && value_2_1 && !key_2_2)
					{
						string value = "Seabed area("+buffer_2_2+")";
						vector_add_KeyLabel_and_Value(poi_str,ind,value);
						poi_str[ind][prm].value = "0x1c07";//препятствие, ниже уровня воды
						key_2_1   = false;
						key_2_3   = false;
						key_2_4   = false;
						value_2_1 = false;
						continue;
					}
					//if(0x00,Category of anchorage,Anchor berth) = 0x1200(Пристань с инфраструктурой)
					if(key_label && key_2_1 && key_2_3 && value_2_2)
					{
						poi_str[ind][ind_label].value = buffer_label;
						poi_str[ind][prm].value = "0x1200";//Пристань с инфраструктурой
						key_label = false;
						key_2_1   = false;
						key_2_3   = false;
						value_2_2 = false;
						continue;
					}
				}
			}
		//Конец переобразование полилиний
		}
	}
}