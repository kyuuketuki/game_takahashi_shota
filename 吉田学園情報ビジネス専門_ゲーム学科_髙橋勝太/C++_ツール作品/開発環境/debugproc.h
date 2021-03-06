//=============================================================================
//
// デバック表示処理[debugproc.h]
// Author; takahashi syota
//
//=============================================================================

#ifndef _DEBUGPROC_H_
#define _DEBUGPROC_H_

//=============================================================================
//インクルード読み込み
//=============================================================================
#include "main.h"

//=============================================================================
//デバック表示の定義
//=============================================================================
class CDebugProc
{
public:
	CDebugProc();												//コンストラクタ
	~CDebugProc();												//デストラクタ
															  
	void Init(void);											//初期化処理
	void Uninit(void);											 //終了処理
															  
	static void Print(int nCnt2, const char *fmt, ...);			//生成処理
	static void Draw(void);										//描画処理

private:
	static LPD3DXFONT m_pFont;					//フォントへのポインタ
	static char m_aStr[7][1024];				//文字列を格納するバッファ
};
#endif

