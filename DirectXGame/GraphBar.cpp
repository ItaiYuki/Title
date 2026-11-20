
#include "GraphBar.h"

using namespace KamataEngine;

// デストラクタ
GraphBar::~GraphBar() {
  delete sprite_;
  delete sprite2_;

  sprite_ = nullptr;
  sprite2_ = nullptr;
}

// 初期化
void GraphBar::Initialize(uint32_t textureHandle) {
  textureHandle_ = textureHandle;

  // HP背景
  sprite_ = Sprite::Create(textureHandle_, {100, 20});

  // HPゲージ
  sprite2_ = Sprite::Create(textureHandle_, {100, 20});
}

// 更新
void GraphBar::Update(uint32_t hp) {
  if (!sprite_ || !sprite2_) {
    return;
  }

  // 背景を赤色にする
  sprite_->SetColor({1.0f, 0.0f, 0.0f, 0.5f});
  sprite_->SetSize({200, 30});

  // HPゲージを緑色にする
  sprite2_->SetColor({0.0f, 1.0f, 0.0f, 0.7f});
  sprite2_->SetSize({static_cast<float>(hp), 30});
}

// 描画
void GraphBar::Draw() {
  if (sprite_) {
    sprite_->Draw();
  }

  if (sprite2_) {
    sprite2_->Draw();
  }
}
