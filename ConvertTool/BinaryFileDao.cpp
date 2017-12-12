/*!-----------------------------------------------------------------------------
@file       BinaryFileDao.cpp
@brief      バイナリファイルへのアクセスを提供する
@attention  なし
------------------------------------------------------------------------------*/
#include "StdAfx.h"
#include "BinaryFileDao.h"
#include "FileName.h"

/*!-----------------------------------------------------------------------------
@brief      デフォルトコンストラクタ
@note       クラスを構築する。
@param[in]  なし
@return     なし
@attention  なし
------------------------------------------------------------------------------*/
BinaryFileDao::BinaryFileDao(void)
{
}

/*!-----------------------------------------------------------------------------
@brief      デストラクタ
@note       クラスを破棄する。
@param      なし
@return     なし
@attention  なし
------------------------------------------------------------------------------*/
BinaryFileDao::~BinaryFileDao(void)
{
}

/*!-----------------------------------------------------------------------------
@fn         指定されたファイルをバイナリ形式で読み込み専用でオープンする
@brief      ファイルオープン
@param[in]  fileName　ファイル名
@return     オープン結果（成功：true、失敗：false）
@attention  なし
@detail     引数で渡されたファイルをバイナリ形式で読み込み専用でオープンします。
　　　　　　指定されたファイルが存在しない場合、例外が発生しますが、
      　　　処理は継続されます
------------------------------------------------------------------------------*/
bool BinaryFileDao::open(FileName* fileName)
{
    if(!tmbFile_.Open(fileName->fileNameWithPath(),
        CFile::modeRead /*| CFile::shareExclusive*/ | CFile::typeBinary, &fileException_))
    {
        TRACE( _T("Can't open file %s, error = %u\n"),
            fileName, fileException_.m_cause );
        return false;
    }
    else
    {
        return true;
    }
}

/*!-----------------------------------------------------------------------------
@fn         オープン済みのファイルから、データを読み込む
@brief      データ読み込み
@note       指定ファイルのバッファー読込、範囲判定
@param[out] readBuffer  読み込んだデータの保存先となるバッファへのポインタ
@param[in]  readSize  読み込むバイト数
@return     (同範囲：true　範囲外：false)
@attention  なし
------------------------------------------------------------------------------*/
bool BinaryFileDao::readData(void* readBuffer, int readSize)
{
    if( tmbFile_.Read(readBuffer, readSize) == readSize ){
        return true;
    }
    else
    {
        return false;
    }
}

/*!-----------------------------------------------------------------------------
@fn         オープン済みのファイルをクローズする
@brief      ファイルクローズ
@param      なし
@return     なし
@attention  なし
@detail     オープン済みのファイルをクローズする
------------------------------------------------------------------------------*/
void BinaryFileDao::close()
{
    if( tmbFile_.m_hFile != CFile::hFileNull) tmbFile_.Close();
}

/*!-----------------------------------------------------------------------------
@fn         現在のポインタの位置を返す
@brief      ポインタ位置を返す
@param      なし
@return     ポインタの位置
@attention  なし
@detail     データを読み込む起点となるポインタ位置を返す
------------------------------------------------------------------------------*/
ULONGLONG BinaryFileDao::getPosition()
{
    return tmbFile_.GetPosition();
}

/*!-----------------------------------------------------------------------------
@fn         ファイルサイズを取得する
@param      なし
@return     なし
@attention  ファイルサイズ[byte]
@detail     オープン済みのファイルサイズを取得します
------------------------------------------------------------------------------*/
ULONGLONG BinaryFileDao::getFileSize()
{
    return tmbFile_.GetLength();
}