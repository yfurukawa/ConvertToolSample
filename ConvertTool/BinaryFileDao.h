/*!-----------------------------------------------------------------------------
@file       BinaryFileDao.h
@brief		バイナリファイルへのアクセスを提供する
@attention  なし
------------------------------------------------------------------------------*/
#pragma once
// インクルードファイル ======================================================
#include "IFileDao.h"

// クラスの前方宣言 =======================================================

// マクロの宣言 ================================================================

// 型の宣言 ==================================================================


// クラス定義 ==================================================================
/*!-----------------------------------------------------------------------------
@class      BinaryFileDaoクラス
@brief      バイナリファイルへのアクセスを提供する
@note       なし
@attention  なし
@see        なし
------------------------------------------------------------------------------*/
class BinaryFileDao : public IFileDao
{
public:
    BinaryFileDao(void);
    ~BinaryFileDao(void);
	virtual bool openReadOnly(FileName* fileName);
	virtual bool openReadWrite(FileName* fileName);
    void close();
    bool readData(void* readBuffer, int readSize);
    ULONGLONG getPosition();
    ULONGLONG getFileSize();

private:
    CFile binFile_;  //!< 対象とするバイナリファイルのファイルハンドラ
    CFileException fileException_;  //!< ファイルアクセスの際に発生した例外
    char synchWord_[4];  //!< DDRデータの開始を表すシンクワード　TODO FileDaoがシンクワードを知っているのはおかしいので要リファクタリング

};

