/*!-----------------------------------------------------------------------------
@file       StringHelper.cpp
@brief      
@attention  なし
------------------------------------------------------------------------------*/
#include "StdAfx.h"
#include "StringHelper.h"

/*!-----------------------------------------------------------------------------
@brief      デフォルトコンストラクタ
@note       クラスを構築する。
@param[in]  なし
@return     なし
@attention  なし
------------------------------------------------------------------------------*/
StringHelper::StringHelper(void)
{
}

/*!-----------------------------------------------------------------------------
@brief      デストラクタ
@note       クラスを破棄する。
@param      なし
@return     なし
@attention  なし
------------------------------------------------------------------------------*/
StringHelper::~StringHelper(void)
{
}

/*!-----------------------------------------------------------------------------
@brief      
@note       
@param      
@return     なし
@attention  なし
------------------------------------------------------------------------------*/


// FullPath -> ファイル名(拡張子付)
CString StringHelper::GetFileName( CString strPath )
{
	// ファイル名の分割用
	TCHAR szDrv[ 1024 + 1 ] = _T("");
	TCHAR szDir[ 1024 + 1 ] = _T("");
	TCHAR szFile[ 1024 + 1 ] = _T("");
	TCHAR szType[ 1024 + 1 ] = _T("");
	TCHAR szAppPath[1024+1] = _T("");

	// パスを分割する。
	#if 1400 <= _MSC_VER
		::_tsplitpath_s( strPath, szDrv, 1024, szDir, 1024, szFile, 1024, szType, 1024 );
	#else
		::_tsplitpath( strPath, szDrv, szDir, szFile, szType );
	#endif

	// 絶対パスに変換
	TCHAR* pszName = NULL;
	CString strFileName;
	strFileName.Format( _T("%s%s"), szFile, szType );
	return strFileName;
}

/*!-----------------------------------------------------------------------------
@brief      
@note       
@param      
@return     なし
@attention  なし
------------------------------------------------------------------------------*/
void StringHelper::Split(CStringArray* pstrArray,LPCTSTR szTarget,LPCTSTR szDelimiter)
{
    if(!szTarget)
        return;
    if(!szDelimiter)
        return;
    if(!pstrArray)
        return;

    pstrArray->RemoveAll();

    CString strTarget(szTarget);
    size_t intDelimiterLen=0;
    size_t intStart=0;
    int intEnd=0;

    strTarget += szDelimiter;
    intDelimiterLen = _tcslen(szDelimiter);
    intStart = 0;
    while (intEnd = strTarget.Find(szDelimiter, intStart), intEnd >= 0)
    {
        pstrArray->Add(strTarget.Mid(intStart, intEnd - intStart));
        intStart = intEnd + intDelimiterLen;
    }
    return;
}

void StringHelper::GetRootPath( CString* const pstrPath )
{
	// ファイル名の分割用
	TCHAR szDrv[ 1024 + 1 ] = _T("");
	TCHAR szDir[ 1024 + 1 ] = _T("");
	TCHAR szFile[ 1024 + 1 ] = _T("");
	TCHAR szType[ 1024 + 1 ] = _T("");
	TCHAR szAppPath[1024+1] = _T("");

	// モジュールのパスを取得する。
	::GetModuleFileName( NULL, szAppPath, sizeof(szAppPath) );

	// パスを分割する。
	#if 1400 <= _MSC_VER
		::_tsplitpath_s( szAppPath, szDrv, 1024, szDir, 1024, szFile, 1024, szType, 1024 );
	#else
		::_tsplitpath( szAppPath, szDrv, szDir, szFile, szType );
	#endif

	// ルートパスを決定
	TCHAR szPath[1024+1] = _T("");
	#ifdef _DEBUG
	wsprintf( szAppPath, _T("%s%s"), szDrv, szDir );
	#else
	wsprintf( szAppPath, _T("%s%s"), szDrv, szDir );
	#endif

	// 絶対パスに変換
	TCHAR* pszName = NULL;
	::GetFullPathName( szAppPath, 1024, szPath, &pszName );
	pstrPath->Format( szPath );
}

