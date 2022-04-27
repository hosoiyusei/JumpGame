#include"SaveData.h"

SaveData::SaveData()
	:mData{}
{

}

SaveData::~SaveData()
{

}

void SaveData::Save(int x, int y, int stage)
{
	mSave = fopen("RESOURCES/SaveData/SaveData.txt", "w");
	fprintf(mSave, "%d\n", x);
	fprintf(mSave, "%d\n", y);
	fprintf(mSave, "%d", stage);

	fclose(mSave);
}

int SaveData::Road(int i)
{
	mRoad = fopen("RESOURCES/SaveData/SaveData.txt", "r");

	for (int i = 0; i < 3; i++)
	{
		fgets(line, 256, mRoad);
		sscanf(line, "%d", &mData[i]);
	}
	
	if (i == 1)
	{
		return mData[0];
	}
	else if (i == 2)
	{
		return mData[1];
	}
	else if (i == 3)
	{
		return mData[2];
	}

	fclose(mRoad);
}