//=============================================================================
//
// テクスチャ処理 [texture.cpp]
// Author : takahashi shota
//
//=============================================================================

//=============================================================================
//インクルード読み込み
//=============================================================================
#include "texture.h"
#include "manager.h"

//=============================================================================
// コンストラクタ
//=============================================================================
CTexture::CTexture(int nPriority)
{

}

//=============================================================================
// デストラクタ
//=============================================================================
CTexture::~CTexture()
{

}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CTexture::Init(D3DXVECTOR3 pos, float fSizeX, float fSizeY)
{
	return E_NOTIMPL;
}

//=============================================================================
// 終了処理
//=============================================================================
void CTexture::Uninit(void)
{
}

//=============================================================================
// 更新処理
//=============================================================================
void CTexture::Update(void)
{

}

//=============================================================================
// 描画処理
//=============================================================================
void CTexture::Draw(void)
{

}

//=============================================================================
// テクスチャの読み込み
//=============================================================================
HRESULT CTexture::Load(void)
{
	// デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();
	
	//メモリの確保
	m_pTexture = (LPDIRECT3DTEXTURE9) new LPDIRECT3DTEXTURE9[TEX_MAX];

	for (int nCnt = 0; nCnt < TEX_MAX; nCnt++)
	{
		// テクスチャの読み込み
		D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/meshfield.jpg", (LPDIRECT3DTEXTURE9*)&m_pTexture[TEX_MESHFILD]);
	}

	return S_OK;
}

//=============================================================================
// テクスチャの破棄
//=============================================================================
void CTexture::Unload(void)
{
	//メモリの破棄
	for (int nCnt = 0; nCnt < TEX_MAX; nCnt++)
	{
		// テクスチャの破棄
		//本体
		(*(LPDIRECT3DTEXTURE9*)&m_pTexture[nCnt])->Release();
		*(LPDIRECT3DTEXTURE9*)&m_pTexture[nCnt] = NULL;
	}

	//メモリの破棄
	delete[] m_pTexture;
	m_pTexture = NULL;
}

//=============================================================================
// アドレス情報の受け渡し
//=============================================================================
LPDIRECT3DTEXTURE9 CTexture::GetAddress(int nIdx)
{
	//本体
	return (*(LPDIRECT3DTEXTURE9*)&m_pTexture[nIdx]);
}
