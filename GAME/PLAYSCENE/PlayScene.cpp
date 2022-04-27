/*
プレイシーン
*/
#include "PlayScene.h"

#include "../GameMain.h"
#include"Player/Player.h"
#include"ObjectManager/ObjectManager.h"
#include"SaveData/SaveData.h"

/*--------------------------------------------------
コンストラクタ
--------------------------------------------------*/
PlayScene::PlayScene()
	:mpPlayer(nullptr)
	,mpObjectManager(nullptr)
	,mpSaveData(nullptr)
{
}

/*--------------------------------------------------
デストラクタ
--------------------------------------------------*/
PlayScene::~PlayScene()
{
}

/*--------------------------------------------------
初期化
--------------------------------------------------*/
void PlayScene::Initialize()
{
	mpPlayer = new Player();
	mpObjectManager = new ObjectManager();
	mpSaveData = new SaveData();

	mpObjectManager->Initialize(mpPlayer,mpSaveData);
	mpPlayer->Initialize(mpObjectManager, mpSaveData);
}

/*--------------------------------------------------
更新
戻り値	:次のシーン番号
--------------------------------------------------*/
GAME_SCENE PlayScene::Update()
{
	if (mpPlayer != nullptr)
		mpPlayer->Update();
	if (mpObjectManager != nullptr)
		mpObjectManager->Update();

	if (IsButtonPressed(PAD_INPUT_1))
	{
		return GAME_SCENE::RESULT;
	}

	return GAME_SCENE::NONE;
}

/*--------------------------------------------------
描画
--------------------------------------------------*/
void PlayScene::Draw()
{
	if (mpPlayer != nullptr)
		mpPlayer->Draw();
	if (mpObjectManager != nullptr)
		mpObjectManager->Draw();

	//DrawString(0, 0, "PlayScene", GetColor(100, 255, 100));
	//DrawString(0, 20, "Input ZKey", GetColor(0, 255, 0));
}

/*--------------------------------------------------
終了処理
--------------------------------------------------*/
void PlayScene::Finalize()
{
	

	if (mpObjectManager != nullptr)
		mpObjectManager->Finalize();
	delete mpObjectManager;
	mpObjectManager = nullptr;

	if (mpPlayer != nullptr)
		mpPlayer->Finalize();
	delete mpPlayer;
	mpPlayer = nullptr;

	if (mpSaveData != nullptr)
	delete mpSaveData;
	mpSaveData = nullptr;


	
}
