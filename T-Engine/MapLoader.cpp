//#pragma once
//#include "Map.hpp"
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <array>
//#include <vector>
//using namespace std;
//
//class MapLoader {
//public:
//	Map PopulateMaps(std::vector<Map> &maps) {
//		ifstream myfile("/Assets/Resources/maps.txt");
//
//		if (myfile.is_open())
//		{
//			int mapIndex = 0;
//			string line; 
//
//			while (getline(myfile, line))
//			{
//				if (line == "START_MAP") {
//					maps.push_back(Map());
//					continue;
//				}
//
//				maps.back().layout->push_back(line);
//			}
//
//			myfile.close();
//		}
//	}
//};