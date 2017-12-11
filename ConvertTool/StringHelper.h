/*!-----------------------------------------------------------------------------
@file       StringHelper.h
@brief      StringHelperクラスの定義ファイル
@attention  なし
------------------------------------------------------------------------------*/
#pragma once
// インクルードファイル ======================================================
#include <afxcoll.h>

// クラスの前方宣言 =======================================================

// マクロの宣言 ================================================================

// 型の宣言 ==================================================================


// クラス定義 ==================================================================
/*!-----------------------------------------------------------------------------
@class      StringHelperクラス
@brief      CString文字列を指定して、CStringArrayに分割する
@note       なし
@attention  なし
@see        なし
------------------------------------------------------------------------------*/
class StringHelper
{
public:
    StringHelper(void);
    ~StringHelper(void);
    //CString文字列を区切り文字を指定して、CStringArrayに分割する
    void Split(CStringArray* pstrArray,LPCTSTR szTarget,LPCTSTR szDelimiter);
    CString GetFileName( CString strPath );
    void GetRootPath( CString* const pstrPath );
};

