#pragma once
#include <string>    // useful for reading and writing

class SaveData
{
private:

	int mData[5];

	char line[256];

	FILE* mRoad;
	FILE* mSave;

public:

	SaveData();
	~SaveData();

	void Save(int x, int y, int stage);

	int Road(int i);
};