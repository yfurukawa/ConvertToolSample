/*!-----------------------------------------------------------------------------
@file       TimeUtility.cpp
@brief      時間有効ファイル
@attention  なし
------------------------------------------------------------------------------*/
#include "StdAfx.h"
#include "TimeUtility.h"

/*!-----------------------------------------------------------------------------
@brief      デフォルトコンストラクタ
@note       クラスを構築する。
@param[in]  なし
@return     なし
@attention  なし
------------------------------------------------------------------------------*/
TimeUtility::TimeUtility(void)
{
}


/*!-----------------------------------------------------------------------------
@brief      デストラクタ
@note       クラスを破棄する。
@param      なし
@return     なし
@attention  なし
------------------------------------------------------------------------------*/
TimeUtility::~TimeUtility(void)
{
}

/*!-----------------------------------------------------------------------------
@brief      時刻取得
@note       現在時刻を取得。"HH:MM:SS"形式の時刻文字列に置換え。
@param      なし
@return     str
@attention  なし
------------------------------------------------------------------------------*/
CString TimeUtility::getCurrentTime()
{
    CTime    cTime;
	CString  str;

	cTime = CTime::GetCurrentTime();           // 現在時刻
	
	str = cTime.Format(_T("%H:%M:%S"));   // "HH:MM:SS"形式の時刻文字列を取得

	return str;
}

/*!-----------------------------------------------------------------------------
@brief      時刻取得
@note       現在時刻を取得。"YYYY.mm.dd"形式の時刻文字列に置換え。
@param      なし
@return     str
@attention  なし
------------------------------------------------------------------------------*/
CString TimeUtility::getCurrentDate()
{
    CTime    cTime;
	CString  str;

	cTime = CTime::GetCurrentTime();           // 現在時刻
	
	str = cTime.Format(_T("%Y.%m.%d"));   // "YYYY.mm.dd"形式の時刻文字列を取得

	return str;
}