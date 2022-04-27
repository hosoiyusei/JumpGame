/*
�v���C�V�[��
*/
#pragma once

#include "../IScene.h"

class Player;
class ObjectManager;
class SaveData;

class PlayScene : public IScene
{
private:

	Player* mpPlayer;

	ObjectManager* mpObjectManager;

	SaveData* mpSaveData;

public:

	// �R���X�g���N�^
	PlayScene();

	// �f�X�g���N�^
	~PlayScene();

	// ������
	void Initialize() override;

	// �X�V
	GAME_SCENE Update() override;

	// �`��
	void Draw() override;

	// �I������
	void Finalize() override;
};