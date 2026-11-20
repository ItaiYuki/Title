
#include "TitleScene.h"

using namespace KamataEngine;

// デストラクタ
TitleScene::~TitleScene() {
  delete sprite_;
  delete spriteFont_;
  delete spriteHit_;

  sprite_ = nullptr;
  spriteFont_ = nullptr;
  spriteHit_ = nullptr;
}

// タイトル終了判定
bool TitleScene::IsFinished() const { return isFinished_; }

// 初期化
void TitleScene::Initialize() {
  // テクスチャ読み込み
  textureHandle_ = TextureManager::Load("titlebg.png");
  textureHandleFont_ = TextureManager::Load("titlefont.png");
  textureHandleHit_ = TextureManager::Load("hitenter.png");

  // スプライト生成
  sprite_ = Sprite::Create(textureHandle_, {0, 0});
  spriteFont_ = Sprite::Create(textureHandleFont_, {50, -300});
  spriteHit_ = Sprite::Create(textureHandleHit_, {400, 550});
}

// 更新
void TitleScene::Update() {
  // タイマー加算
  timer_++;

  // タイトル文字を移動
  if (spriteFont_) {
    Vector2 position = spriteFont_->GetPosition();

    if (position.y < 100) {
      position.y += 2;
    }

    spriteFont_->SetPosition(position);
  }

  // Enterキーでゲーム開始
  if (Input::GetInstance()->TriggerKey(DIK_RETURN)) {
    isFinished_ = true;
  }
}

// 描画
void TitleScene::Draw() {
  DirectXCommon *dxCommon = DirectXCommon::GetInstance();

  // スプライト描画前処理
  Sprite::PreDraw(dxCommon->GetCommandList());

  if (sprite_) {
    sprite_->Draw();
  }

  if (spriteFont_) {
    spriteFont_->Draw();
  }

  // 30フレームごとに表示・非表示
  if (timer_ % 60 >= 30) {
    if (spriteHit_) {
      spriteHit_->Draw();
    }
  }

  // スプライト描画後処理
  Sprite::PostDraw();
}
