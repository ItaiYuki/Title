
#pragma once

#include "DrawNumber.h"
#include "GraphBar.h"
#include "KamataEngine.h"
#include "Player.h"
#include "Stage.h"

#include <memory>

class GameScene {
public:
  // 初期化
  void Initialize();

  // 更新
  void Update();

  // 描画
  void Draw();

private:
  // テクスチャハンドル
  uint32_t textureHandleStage_ = 0;
  uint32_t textureHandleGraph_ = 0;
  uint32_t textureHandleNumber_ = 0;

  // 3Dモデル
  std::unique_ptr<KamataEngine::Model> modelPlayer_;

  // カメラ
  KamataEngine::Camera camera_;

  // 各クラス
  std::unique_ptr<Stage> stage_;
  std::unique_ptr<Player> player_;
  std::unique_ptr<GraphBar> graphBar_;
  std::unique_ptr<DrawNumber> drawNumber_;

  // HP
  int hp_ = 200;

  // スコア
  int gameScore_ = 0;
};
