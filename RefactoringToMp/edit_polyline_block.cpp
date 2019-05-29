#include "include.h"

void edit_POLYLINE_blocks(vector<vector<MyStruct>>& polyline_str)
{

/*	В объектах полилиний, может быть:
		-Type=Unknown Line Type(Неизвестный тип линии);
	эти параметры заменяются на нужний тип, откалкиваяся от других параметров объекта*/				

	for(int ind = 0; ind < polyline_str.size(); ind++){
		for(int prm = 0; prm < polyline_str[ind].size(); prm++){

	
		//1.Переобразование полилиний типов = Unknown Line Type(Неизвестный тип линии)
			if (polyline_str[ind][prm].key == "Type" && polyline_str[ind][prm].value == "Unknown Line Type")
			{
				bool key_1_1   = false;	//FEATURE_DESCRIPTION(Описание особенности) 
				bool key_1_2   = false; //STATUS - Status(Статус)
				bool key_1_3   = false; //CATFIF - Category of fishing  facility (Категория объекта рыбалки)
				bool key_1_4   = false; //NATION - Nationality(НАЦИЯ - Национальность)
				bool key_1_5   = false; //CATSLC - Category of shoreline construction(Категория строительства береговой линии)
				bool key_1_6   = false; //CATTSS - Category of Traffic Separation Scheme(Категория схемы разделения движения)

				bool value_1_1  = false; //Fishing facility(Рыболовное хозяйство)
				bool value_1_2  = false; //(permanent)-(Постоянный)
				bool value_1_3  = false; //fishing stake(Рыболовный кол)
				bool value_1_4  = false; //Straight territorial sea baseline(Прямая территориальная линия моря)
				bool value_1_5  = false; //sea wall(морская стена)
				bool value_1_6  = false; //Shoreline Construction(Строительство береговой линии)
				bool value_1_7  = false; //Traffic Separation Scheme Boundary(Граница схемы разделения движения)
				bool value_1_8  = false; //Slope topline(Наклонная линия, возможно дорога)
				bool value_1_9  = false; //mole(Дамба)
				bool value_1_10 = false; //breakwater(волнолом)
				bool value_1_11 = false; //pier(пирс)
				bool value_1_12 = false; //Land area(Площадь земельного участка)
				bool value_1_13 = false; //Dyke(Дамба)
				bool value_1_14 = false; //Traffic Separation Line(Линия разделения трафика)

				for (int x_1 = 0; x_1 < polyline_str[ind].size(); x_1++){
					//key = trye, false?
					if (polyline_str[ind][x_1].key == "FEATURE_DESCRIPTION")			
						key_1_1 = true;

					if (polyline_str[ind][x_1].key == "STATUS - Status")			
						key_1_2 = true;

					if (polyline_str[ind][x_1].key == "CATFIF - Category of fishing  facility")			
						key_1_3 = true;

					if (polyline_str[ind][x_1].key == "NATION - Nationality")			
						key_1_4 = true;

					if (polyline_str[ind][x_1].key == "CATSLC - Category of shoreline construction")			
						key_1_5 = true;

					if (polyline_str[ind][x_1].key == "CATTSS - Category of Traffic Separation Scheme")			
						key_1_6 = true;

					//value = trye, false?
					if (polyline_str[ind][x_1].value == "Fishing facility") 
						value_1_1 = true;

					if (polyline_str[ind][x_1].value.find("(permanent)") != string::npos) 
						value_1_2 = true;

					if (polyline_str[ind][x_1].value.find("(fishing stake)") != string::npos) 
						value_1_3 = true;

					if (polyline_str[ind][x_1].value == "Straight territorial sea baseline")			
						value_1_4 = true;

					if (polyline_str[ind][x_1].value.find("(sea wall)") != string::npos) 
						value_1_5 = true;

					if (polyline_str[ind][x_1].value == "Shoreline Construction")
						value_1_6 = true;

					if (polyline_str[ind][x_1].value == "Traffic Separation Scheme Boundary")
						value_1_7 = true;

					if (polyline_str[ind][x_1].value == "Slope topline")
						value_1_8 = true;

					if (polyline_str[ind][x_1].value.find("(mole)") != string::npos) 
						value_1_9 = true;
					
					if (polyline_str[ind][x_1].value.find("(breakwater)") != string::npos) 
						value_1_10 = true;

					if (polyline_str[ind][x_1].value.find("pier") != string::npos) 
						value_1_11 = true;

					if (polyline_str[ind][x_1].value == "Land area")
						value_1_12 = true;

					if (polyline_str[ind][x_1].value == "Dyke")
						value_1_13 = true;

					if (polyline_str[ind][x_1].value == "Traffic Separation Line")
						value_1_14 = true;

					//if(Unknown Area Type,Category of fishing  facility,fishing stake) = 0x002b(Опасность для плавания), но нужен рыболовный кол!
					if(key_1_1 && key_1_2 && key_1_3 && value_1_1 && value_1_2 && value_1_3)
					{
						polyline_str[ind][prm].value = "0x002b";//Опасность для плавания
						key_1_1 = false;
						key_1_2 = false;
						key_1_3 = false;
						value_1_1 = false;
						value_1_2 = false;
						value_1_3 = false;
						continue;
					}
					//if(U.A.T,NATION,Straight territorial sea baseline) = 0x002a(Морская граница)
					if(key_1_1 && key_1_4 && value_1_4)
					{
						polyline_str[ind][prm].value = "0x002a";//Морская граница
						key_1_1 = false;
						key_1_4 = false;
						value_1_4 = false;
						continue;
					}
					//if(U.A.T,Sea wall,Shoreline Construction = 0x0015(Береговая линия)
					if(key_1_1 && key_1_2 && key_1_5 && value_1_2 && value_1_5 && value_1_6)
					{
						polyline_str[ind][prm].value = "0x0015";//Береговая линия
						key_1_1 = false;
						key_1_2 = false;
						key_1_5 = false;
						value_1_2 = false;
						value_1_5 = false;
						value_1_6 = false;
						continue;
					}
					//if(U.A.T,Traffic Separation Scheme Boundary) = 0x002a(Морская граница)
					if(key_1_1 && key_1_2 && key_1_6 && value_1_2 && value_1_7)
					{
						polyline_str[ind][prm].value = "0x002a";//Морская граница
						key_1_1 = false;
						key_1_2 = false;
						key_1_6 = false;
						value_1_2 = false;
						value_1_7 = false;		
					}
					//if(U.A.T,Slope topline) = 0x0016(Аллея, тропа)
					if(key_1_1 && value_1_8)
					{
						polyline_str[ind][prm].value = "0x0016";//Аллея, тропа 
						key_1_1 = false;
						value_1_8 = false;		
					}
					//if(U.A.T,Shoreline Construction,mole) = 0x002b(Опасность для плавания), но нужна дамба!
					if(key_1_1 && key_1_5 && value_1_6 && value_1_9)
					{
						polyline_str[ind][prm].value = "0x002b";//Опасность для плавания
						key_1_1 = false;
						key_1_5 = false;
						value_1_6 = false;
						value_1_9 = false;
					}
					//if(U.A.T,Shoreline Construction,breakwater) = 0x002b(Опасность для плавания), но нужен волнолом, мол!
					if(key_1_1 && key_1_5 && value_1_6 && value_1_10)
					{
						polyline_str[ind][prm].value = "0x002b";//Опасность для плавания
						key_1_1 = false;
						key_1_5 = false;
						value_1_6 = false;
						value_1_10 = false;
					}
					//if(U.A.T,Shoreline Construction,pier) = 0x002b(Опасность для плавания), но нужен пирс!
					if(key_1_1 && key_1_5 && value_1_6 && value_1_11)
					{
						polyline_str[ind][prm].value = "0x002b";//Опасность для плавания
						key_1_1 = false;
						key_1_5 = false;
						value_1_6 = false;
						value_1_11 = false;
					}
					//if(U.A.T,Land area) = 0x0000(Дорога), но нужена площадь земельного участка!
					if(key_1_1 && value_1_12)
					{
						polyline_str[ind][prm].value = "0x0000";//Дорога
						key_1_1 = false;
						value_1_12 = false;
					}
					//if(U.A.T,Dyke) =  0x002b(Опасность для плавания), но нужена дамба!
					if(key_1_1 && value_1_13)
					{
						polyline_str[ind][prm].value = "0x002b";//Опасность для плавания
						key_1_1 = false;
						value_1_14 = false;
					}
					//if(U.A.T,Traffic SeparationLine) = 0x002a(Морская граница)
					if(key_1_1 && key_1_2 && key_1_6 && value_1_2 && value_1_14)
					{
					polyline_str[ind][prm].value = "0x002a";//Морская граница
						key_1_1 = false;
						key_1_2 = false;
						key_1_6 = false;
						value_1_2 = false;
						value_1_14 = false;
					}
				}
			}
		//Конец переобразование полилиний
		}
	}
}