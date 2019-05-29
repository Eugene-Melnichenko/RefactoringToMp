#include "include.h"

void edit_POLYGON_blocks(vector<vector<MyStruct>>& polygon_str)
{
/*	В объектах полигонов, может быть:
		-Type=Unknown Area Type(Неизвестный тип области);
		-Type=Marine Info Area(Морская информационная зона);
		-0x54(Неизвестный тип)
	эти параметры заменяются на нужний тип, откалкиваяся от других параметров объекта

*/

	
	for(int ind = 0; ind < polygon_str.size(); ind++){
		for(int prm = 0; prm < polygon_str[ind].size(); prm++){

		//1.Переобразование полигонов типов = Unknown Area Type(Неизвестный тип области)
			if (polygon_str[ind][prm].key == "Type" && polygon_str[ind][prm].value == "Unknown Area Type")
			{
				bool key_1_1   = false; //FEATURE_DESCRIPTION(Описание особенности)
				bool key_1_2   = false; //NATION - Nationality(НАЦИЯ - Национальность)
				bool key_1_3   = false; //CATSLC - Category of shoreline construction(Береговая линия)

				bool value_1_1 = false; //Administration area (Named)(Администрация области)
				bool value_1_2 = false; //Sloping ground(Земля, Пляж, Полигон)
				bool value_1_3 = false; //Shoreline Construction(Береговая линия, Пристань)
				bool value_1_4 = false; //Nautical publication information(используем для лучшей визуализации карти)

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

					//if(Unknown Area Type,NATION-Nationality,Administration area) = 0x0001(Населений пункт > 200К)
					if (key_1_1 && key_1_2 && value_1_1)
					{
						polygon_str[ind][prm].value = "0x0001";
						key_1_2 = false;
						key_1_1 = false;
						value_1_1 = false;
						continue;
					}
					//if(U.A.T,Sloping ground) = 0x0002(Населений пункт < 200К)
					if (key_1_1 && value_1_2)
					{
						polygon_str[ind][prm].value = "0x0002";
						key_1_1 = false;
						value_1_2 = false;
						continue;
					}
					//if(U.A.T,Category of shoreline construction,Shoreline Construction = 0x0009(Пристань)
					if (key_1_1 && key_1_3 && value_1_3)//true
					{
						polygon_str[ind][prm].value = "0x0009";
						key_1_1 = false;
						key_1_3 = false;
						value_1_3 = false;
						continue;
					}
					//if(U.A.T,Nautical publication information)=0x0002(Населений пункт < 200К),Для лучшей визуализации карти
					if (key_1_1 && value_1_4)//true
					{
						polygon_str[ind][prm].value = "0x0002";
						key_1_1 = false;
						value_1_4 = false;
						continue;
					}
					//if(Unknown Area Type) = 0x004a(Область выделения карты)
					if (!key_1_1 && !key_1_2 && !key_1_3 && !value_1_1 && !value_1_2 && !value_1_3)
					{
						polygon_str[ind][prm].value = "0x004a";
						continue;
					}

				}
			}


		//2.Переобразование полигонов типов = Marine Info Area(Морская информационная зона)
			//if (unknown_key == "Type" && unknown_value == "Marine Info Area")


		//3.Переобразование полигонов типов = 0x54(Неизвестный тип)
			if (polygon_str[ind][prm].key == "Type" && polygon_str[ind][prm].value == "0x54")
			{
				bool key_3_1   = false; //FEATURE_DESCRIPTION
				bool key_3_2   = false; //Label
				bool key_3_3   = false; //CATLND - Category of land region(Категория земельного участка)
				bool key_3_4   = false; //NATSUR - Nature of surface(Природа поверхности)
				
				bool value_3_1 = false; //Land region(Земельный участок)
				bool value_3_2 = false; //Land area(Площадь земельного участка)
				bool value_3_3 = false; //fen(Болото)
				bool value_3_4 = false; //sand(Песок)

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

					//if(0x54,Category of land region,Land region,fen) = 0x51(Болото)
					if(key_3_1 == true && key_3_3 == true && value_3_1 == true && value_3_3 == true)
					{
						polygon_str[ind][prm].value = "0x51";
						key_3_1 = false;
						key_3_3 = false;
						value_3_1 = false;
						value_3_3 = false;
						continue;
					}
					//if(0x54,Land region,Sand) = 0x0003(Застройка сельского типа), но нужен песок!
					if(key_3_1 == true && key_3_4 == true && value_3_1 == true && value_3_4 == true)
					{
						polygon_str[ind][prm].value = "0x0003";
						key_3_1 = false;
						key_3_4 = false;
						value_3_1 = false;
						value_3_4 = false;
						continue;
					}
					//if(Land region) = 0x0002(Населений пункт < 200К)
					if(key_3_1 && key_3_2 && value_3_1)
					{
						polygon_str[ind][prm].value = "0x0002";
						key_3_1 = false;
						key_3_2 = false;
						value_3_2 = false;
						continue;
					}
					//if(Если только есть: Land area) = 0x004a(Область выделения карты)
					if(key_3_1 && value_3_2)
					{
						polygon_str[ind][prm].value = "0x004a";
						key_3_1 = false;
						value_3_2 = false;
						continue;
					}
				}
			}//Конец переобразование полигонов
		}
	}
}