//=============================================================================
//
// オブジェクト3D処理 [object3D.h]
// Author : takahashi shota
//
//=============================================================================

#ifndef _OBJECT3D_H_
#define _OBJECT3D_H_
#define FVF_VERTEX_3D (D3DFVF_XYZ|D3DFVF_NORMAL|D3DFVF_DIFFUSE|D3DFVF_TEX1)

//==============================================================================
//インクルード
//==============================================================================
#include "main.h"
#include "scene.h"

//=============================================================================
// オブジェクト3Dクラスの定義
//=============================================================================

//継承先描画クラス
class CObject3D : public CScene
{
public:
	CObject3D(int nPriority = 5, int nType = 0);								//コンストラクタ
	virtual ~CObject3D();														//デストラクタ

	HRESULT Init(D3DXVECTOR3 pos, float fSizeX, float fSizeY);				//初期化処理
	void Uninit(void);														//終了処理
	void Update(void);														//更新処理
	void Draw(void);														//描画処理

	static CObject3D *Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 move, int nType);			//生成処理

	D3DXMATRIX GetMtxWorld(void);

private:
	LPD3DXMESH		m_pMesh;			//メッシュ
	LPD3DXBUFFER	m_pBuffMat;			//バッファ
	DWORD			m_nNumMat;			//マトリックス
	D3DXMATRIX		m_mtxWorld;			//ワールドマトリックス
	D3DXVECTOR3		m_pos;				//位置
	D3DXVECTOR3		m_move;				//位置
	D3DXVECTOR3		m_rot;				//位置
	int				m_nNumVtx;			//頂点数
	float			m_fRot;				//
	static char			*m_pTextName;

	//static char *m_aTextName;
	static D3DXVECTOR3	m_rotStatic;
	static D3DXVECTOR3	m_moveStatic;
	static int m_nType;
};

#endif