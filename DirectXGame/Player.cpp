
#include "Player.h"

using namespace KamataEngine;
using namespace MathUtility;

// 初期化
void Player::Initialize(Model *model) {
  model_ = model;

  worldTransform_.Initialize();

  // 初期回転
  worldTransform_.rotation_.y = std::numbers::pi_v<float> / 2.0f;

  // 初期位置
  worldTransform_.translation_ = {-12.0f, -5.0f, 0};
}

// 更新
void Player::Update() {
  // 右移動
  if (Input::GetInstance()->PushKey(DIK_RIGHT)) {
    worldTransform_.translation_.x += 0.1f;
  }

  // 左移動
  if (Input::GetInstance()->PushKey(DIK_LEFT)) {
    worldTransform_.translation_.x -= 0.1f;
  }

  // 上移動
  if (Input::GetInstance()->PushKey(DIK_UP)) {
    worldTransform_.translation_.y += 0.1f;
  }

  // 下移動
  if (Input::GetInstance()->PushKey(DIK_DOWN)) {
    worldTransform_.translation_.y -= 0.1f;
  }

  // 移動範囲制限
  if (worldTransform_.translation_.x > 8.0f) {
    worldTransform_.translation_.x = 8.0f;
  }

  if (worldTransform_.translation_.x < -14.0f) {
    worldTransform_.translation_.x = -14.0f;
  }

  if (worldTransform_.translation_.y > 8.0f) {
    worldTransform_.translation_.y = 8.0f;
  }

  if (worldTransform_.translation_.y < -8.0f) {
    worldTransform_.translation_.y = -8.0f;
  }

  // 行列更新
  worldTransform_.UpdateMatrix();
}

// 描画
void Player::Draw(Camera &camera) {
  if (model_) {
    model_->Draw(worldTransform_, camera);
  }
}
