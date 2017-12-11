/*!-----------------------------------------------------------------------------
@file       IniFileDao.cpp
@brief      Iniファイルデータアクセスオブジェクトクラスの定義ファイル
@attention  なし
------------------------------------------------------------------------------*/
#include "stdafx.h"
#include "IniFileDao.h"

/*!-----------------------------------------------------------------------------
@brief      デフォルトコンストラクタ
@note       クラスを構築する。
@param[in]  なし
@return     なし
@attention  なし
------------------------------------------------------------------------------*/
IniFileDao::IniFileDao(){

}



/*!-----------------------------------------------------------------------------
@brief      デストラクタ
@note       クラスを破棄する。
@param      なし
@return     なし
@attention  なし
------------------------------------------------------------------------------*/
IniFileDao::~IniFileDao(){

}


/*!-----------------------------------------------------------------------------
@brief      IniFileDaoクラスへのリンク設定
@note       IniFileDaoクラスのインスタンスを設定し、リンクを確立する。
@param[in]  CString fileNameクラスのインスタンスアドレス 
@return     なし
@attention  なし
------------------------------------------------------------------------------*/
IniFileDao::IniFileDao(CString fileName)
{
    CString currentDirectory(_T(""));
    helper_.GetRootPath(&currentDirectory);

    iniFileName_ = currentDirectory + fileName;

}


/*!-----------------------------------------------------------------------------
@brief      読込
@note       bufferを255バイトに設定、sectionName_,key,buffer,sizeof(buffer),iniFileName_の値を読みにいく。
@param      なし
@return     bufferの値を返す
@attention  なし
------------------------------------------------------------------------------*/
CString IniFileDao::readValue(const CString& key)
{
	TCHAR buffer[255];
	GetPrivateProfileString(sectionName_,
							  key,
							  _T("N/A"),
							  buffer,
							  sizeof(buffer),
							  iniFileName_);

	CString str;
    str = buffer;
	return  str;
}


/*!-----------------------------------------------------------------------------
@brief      iniファイルのセクションを選択する
@note       値が定義されているセクションを保持する
@param[in]	sectionName　セクション名	(-)[-]
@return     なし
@attention  なし
------------------------------------------------------------------------------*/
void IniFileDao::selectSection(const CString sectionName)
{
	sectionName_ = sectionName;

}


/*!-----------------------------------------------------------------------------
@brief      書込み
@note       sectionName_,key,buffer,sizeof(buffer),iniFileName_の値を書込む
@param      なし
@return     なし
@attention  なし
------------------------------------------------------------------------------*/
bool IniFileDao::writeValue(const CString& key, const CString& value)
{
	::WritePrivateProfileString(sectionName_,
								key,
								value,
								iniFileName_);
	return true;
}