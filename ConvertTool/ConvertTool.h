
// ConvertTool.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです。
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// CConvertToolApp:
// このクラスの実装については、ConvertTool.cpp を参照してください。
//

class CConvertToolApp : public CWinApp
{
public:
	CConvertToolApp();

// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CConvertToolApp theApp;