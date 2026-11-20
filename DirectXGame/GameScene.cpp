
#include "GameScene.h"

using namespace KamataEngine;

// 初期化
void GameScene::Initialize() {
  // テクスチャ読み込み
  textureHandleStage_ = TextureManager::Load("stage.png");
  textureHandleGraph_ = TextureManager::Load("white1x1.png");
  textureHandleNumber_ = TextureManager::Load("number.png");

  // 3Dモデル生成
  modelPlayer_.reset(Model::CreateFromOBJ("player"));

  // カメラ初期化
  camera_.translation_ = {0, 0, -20};
  camera_.Initialize();

  // Stage生成
  stage_ = std::make_unique<Stage>();
  stage_->Initialize(textureHandleStage_);

  // Player生成
  player_ = std::make_unique<Player>();
  player_->Initialize(modelPlayer_.get());

  // GraphBar生成
  graphBar_ = std::make_unique<GraphBar>();
  graphBar_->Initialize(textureHandleGraph_);

  // DrawNumber生成
  drawNumber_ = std::make_unique<DrawNumber>();
  drawNumber_->Initialize(textureHandleNumber_);
}

// 更新
void GameScene::Update() {
  // HP減少
  hp_--;

  if (hp_ < 0) {
    hp_ = 200;
  }

  // スコア加算
  gameScore_++;

  // 各クラスの更新
  stage_->Update();
  player_->Update();
  graphBar_->Update(static_cast<uint32_t>(hp_));
  drawNumber_->Update(static_cast<uint32_t>(gameScore_));
}

// 描画
void GameScene::Draw() {
  DirectXCommon *dxCommon = DirectXCommon::GetInstance();

  // スプライト描画前処理
  Sprite::PreDraw(dxCommon->GetCommandList());

  // ステージ描画
  stage_->Draw();

  // スプライト描画後処理
  Sprite::PostDraw();

  // 深度バッファクリア
  dxCommon->ClearDepthBuffer();

  // 3Dモデル描画前処理
  Model::PreDraw();

  // プレイヤー描画
  player_->Draw(camera_);

  // 3Dモデル描画後処理
  Model::PostDraw();

  // スプライト描画前処理
  Sprite::PreDraw(dxCommon->GetCommandList());

  // HPとスコア描画
  graphBar_->Draw();
  drawNumber_->Draw();

  // スプライト描画後処理
  Sprite::PostDraw();
}
