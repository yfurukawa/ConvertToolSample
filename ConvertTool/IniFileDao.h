/*!-----------------------------------------------------------------------------
@file       IniFileDao.h
@brief      Iniファイルデータアクセスオブジェクトクラスの定義ファイル
@attention  なし
------------------------------------------------------------------------------*/
#if !defined(EA_38F79A87_8AF8_4b0c_957A_93296DBA6790__INCLUDED_)
#define EA_38F79A87_8AF8_4b0c_957A_93296DBA6790__INCLUDED_

// インクルードファイル ======================================================
#include "StringHelper.h"

// クラスの前方宣言 =======================================================

// マクロの宣言 ================================================================

// 型の宣言 ==================================================================


// クラス定義 ==================================================================
/*!-----------------------------------------------------------------------------
@class      IniFailDaoクラス
@brief      Iniファイルデータアクセスオブジェクトを保持する。
@note       なし
@attention  なし
@see        なし
------------------------------------------------------------------------------*/
class IniFileDao
{

public:
	IniFileDao();
	virtual ~IniFileDao();

	IniFileDao(CString fileName);
	CString readValue(const CString& key);
	void selectSection(const CString sectionName);
	bool writeValue(const CString& key, const CString& value);

protected:
    CString iniFileName_;
	CString sectionName_;
    StringHelper helper_;
};
#endif // !defined(EA_38F79A87_8AF8_4b0c_957A_93296DBA6790__INCLUDED_)
