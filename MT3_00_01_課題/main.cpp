#include <Novice.h>
#include "Calculation.h"
const char kWindowTitle[] = "GC1D_ワタナベ＿リョウイチ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };
	Calculation* calc = new Calculation;
	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		calc->VectorScreenPrintf(0, 0, calc->resultAdd(), ":Add\n");
		calc->VectorScreenPrintf(0, kColumWidth, calc->resultSubtract(), ":Subtract\n");
		calc->VectorScreenPrintf(0, kColumWidth * 2, calc->resultMultiply(), ":Multiply\n");
		Novice::ScreenPrintf(0, kColumWidth * 3, "%f:Dot", calc->resultDot());
		Novice::ScreenPrintf(0, kColumWidth * 4, "%f:Lenght", calc->resultLength());
		calc->VectorScreenPrintf(0, kColumWidth * 5, calc->resultNormalize(), ":Normalize");
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
