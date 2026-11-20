
#include <Windows.h>
#include <memory>

#include "GameScene.h"
#include "KamataEngine.h"
#include "TitleScene.h"

using namespace KamataEngine;

// エントリーポイント
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {
  // エンジン初期化
  KamataEngine::Initialize(L"１");

  // DirectXCommon取得
  DirectXCommon *dxCommon = DirectXCommon::GetInstance();

  // シーン生成
  std::unique_ptr<GameScene> gameScene = std::make_unique<GameScene>();

  std::unique_ptr<TitleScene> titleScene = std::make_unique<TitleScene>();

  // 初期化
  gameScene->Initialize();
  titleScene->Initialize();

  // シーン管理
  enum Scene {
    TITLE,
    GAME,
  };

  Scene scene = TITLE;

  // メインループ
  while (true) {
    // エンジン更新
    if (KamataEngine::Update()) {
      break;
    }

    // シーン更新
    if (scene == TITLE) {
      titleScene->Update();

      // タイトル終了ならゲームへ
      if (titleScene->IsFinished()) {
        scene = GAME;
      }
    } else if (scene == GAME) {
      gameScene->Update();
    }

    // 描画開始
    dxCommon->PreDraw();

    // シーン描画
    if (scene == TITLE) {
      titleScene->Draw();
    } else if (scene == GAME) {
      gameScene->Draw();
    }

    // 描画終了
    dxCommon->PostDraw();
  }

  // シーンの解放
  gameScene.reset();
  titleScene.reset();

  // エンジン終了
  KamataEngine::Finalize();

  return 0;
}
