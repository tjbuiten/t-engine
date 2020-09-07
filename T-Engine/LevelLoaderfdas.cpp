//#include <iostream>
//#include <vector>
//#include "Level.hpp"
//
//using namespace std;
//
//class LevelLoader {
//public:
//	virtual void loadLevel(std::vector<Level>& levels);
//	virtual LevelLoader getNextStep();
//};
//
//class LoadLevelTextures : public LevelLoader {
//public:
//	void loadLevel(std::vector<Level>& levels) {
//	}
//
//	LevelLoader getNextStep() {
//		return LoadLevelLayout();
//	}
//};
//
//class LoadLevelLayout : public LevelLoader {
//public:
//	void loadLevel(std::vector<Level>& levels) {
//	}
//};