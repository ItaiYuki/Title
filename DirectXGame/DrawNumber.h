
#pragma once

#include "KamataEngine.h"

class DrawNumber {
public:
  // デストラクタ
  ~DrawNumber();

  // 初期化
  void Initialize(uint32_t textureHandle);

  // 更新
  void Update(uint32_t number);

  // 描画
  void Draw();

private:
  // テクスチャ
  uint32_t textureHandle_ = 0;

  // スプライト
  KamataEngine::Sprite *sprite_[5] = {};

  // 数字のサイズ
  KamataEngine::Vector2 size_ = {32.0f, 64.0f};
};
