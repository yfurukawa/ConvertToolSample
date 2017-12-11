/*!-----------------------------------------------------------------------------
@file       TextFileDao.cpp
@brief      テキストファイルデータアクセスオブジェクトの定義ファイル
@attention  なし
------------------------------------------------------------------------------*/
#include "StdAfx.h"
#include "atlsimpstr.h"
#include <locale.h>

#include "TextFileDao.h"

/*!-----------------------------------------------------------------------------
@brief      デフォルトコンストラクタ
@note       クラスを構築する。
@param[in]  なし
@return     なし
@attention  なし
------------------------------------------------------------------------------*/
TextFileDao::TextFileDao(void)
{
}

/*!-----------------------------------------------------------------------------
@brief      デストラクタ
@note       クラスを破棄する。
@param      なし
@return     なし
@attention  なし
------------------------------------------------------------------------------*/
TextFileDao::~TextFileDao(void)
{
}

/*!-----------------------------------------------------------------------------
@brief      ファイルを開く
@note       指定されたファイル名でテキストファイルを読み書きできるように開く
@param[in]  fileName    ファイル名   (-) [-]
@return     ファイルオープンの成否（true ： 成功、false ： 失敗）
@attention  なし
------------------------------------------------------------------------------*/
BOOL TextFileDao::open(CString fileName)
{
    errno_t err;

    // 言語環境を日本語に限定する。
	_tsetlocale(LC_ALL, _T("Japanese"));

	err = _tfopen_s(&file, fileName.GetString(), _T("w,ccs=UNICODE"));

	if (err != 0)
	{
		TRACE(_T("File could not be opened %d\n"), err);
		return false;
	}
	else
	{
		return true;
	}
}

/*!-----------------------------------------------------------------------------
@brief      書き込み
@note       ファイルにテキストデータを書き込む
@param[in]  message　書き込むテキストデータ (-) [-]
@return     なし
@attention  なし
------------------------------------------------------------------------------*/
void TextFileDao::write(const CString& message)
{
	_ftprintf_s(file, message.GetString());
}

/*!-----------------------------------------------------------------------------
@brief      ファイルをクローズする
@note       オープンされているファイルを閉じる
@param      なし
@return     なし
@attention  なし
------------------------------------------------------------------------------*/
void TextFileDao::close()
{
	fclose(file);
}
