
#include "Stage.h"

using namespace KamataEngine;

// デストラクタ
Stage::~Stage() {
  delete sprite_;
  delete sprite2_;

  sprite_ = nullptr;
  sprite2_ = nullptr;
}

// 初期化
void Stage::Initialize(uint32_t textureHandle) {
  textureHandle_ = textureHandle;

  // スプライト生成
  sprite_ = Sprite::Create(textureHandle_, {0, 0});
  sprite2_ = Sprite::Create(textureHandle_, {1280, 0});
}

// 更新
void Stage::Update() {
  if (!sprite_ || !sprite2_) {
    return;
  }

  // ステージ移動
  Vector2 position = sprite_->GetPosition();

  position.x -= 2.0f;

  // 画面外に出たら戻す
  if (position.x < -1280.0f) {
    position.x += 1280.0f;
  }

  sprite_->SetPosition(position);

  position.x += 1280.0f;
  sprite2_->SetPosition(position);
}

// 描画
void Stage::Draw() {
  if (sprite_) {
    sprite_->Draw();
  }

  if (sprite2_) {
    sprite2_->Draw();
  }
}
