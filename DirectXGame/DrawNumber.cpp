
#include "DrawNumber.h"

using namespace KamataEngine;

// デストラクタ
DrawNumber::~DrawNumber() {
  for (int i = 0; i < 5; i++) {
    delete sprite_[i];
    sprite_[i] = nullptr;
  }
}

// 初期化
void DrawNumber::Initialize(uint32_t textureHandle) {
  textureHandle_ = textureHandle;

  // 5桁分のスプライトを生成
  for (int i = 0; i < 5; i++) {
    sprite_[i] = Sprite::Create(textureHandle_, {500.0f + size_.x * i, 5});
  }
}

// 更新
void DrawNumber::Update(uint32_t number) {
  // 数字の表示設定
  for (int i = 0; i < 5; i++) {
    if (!sprite_[i]) {
      return;
    }

    sprite_[i]->SetSize(size_);
    sprite_[i]->SetTextureRect({0, 0}, size_);
  }

  // 最初に割る数値
  int32_t digit = 10000;

  // 5桁分ループ
  for (int i = 0; i < 5; i++) {
    // 今の桁の数字を取り出す
    int nowNumber = number / digit;

    // 数字の部分を切り出す
    sprite_[i]->SetTextureRect({size_.x * nowNumber, 0}, {size_.x, size_.y});

    // 残りの桁にする
    number %= digit;

    // 桁をずらす
    digit /= 10;
  }
}

// 描画
void DrawNumber::Draw() {
  for (int i = 0; i < 5; i++) {
    if (sprite_[i]) {
      sprite_[i]->Draw();
    }
  }
}
