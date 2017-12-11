/*!-----------------------------------------------------------------------------
@file       InitializeDataHolder.cpp
@brief      
@attention  なし
------------------------------------------------------------------------------*/
#include "StdAfx.h"
#include "InitializeDataHolder.h"
#include "IniFileDao.h"

/*!-----------------------------------------------------------------------------
@brief      デフォルトコンストラクタ
@note       クラスを構築する。
@param[in]  なし
@return     なし
@attention  なし
------------------------------------------------------------------------------*/
InitializeDataHolder::InitializeDataHolder() :
synchWord_(_T("DEADBEEF")), revision_(_T("01")), outputDir_(_T("c:\\")), iniFileDao_(NULL), statusWordCheck_(_T(""))
{
    iniFileDao_ = new IniFileDao(_T("DDRDataConverter.ini"));
    this->readIniFile();
}

/*!-----------------------------------------------------------------------------
@brief      デストラクタ
@note       クラスを破棄する。
@param      なし
@return     なし
@attention  なし
------------------------------------------------------------------------------*/
InitializeDataHolder::~InitializeDataHolder(){
    delete iniFileDao_;
    iniFileDao_ = NULL;
}

/*!-----------------------------------------------------------------------------
@brief      
@note       
@param      
@return     なし
@attention  なし
------------------------------------------------------------------------------*/
InitializeDataHolder* InitializeDataHolder::getInstance()
{
    static InitializeDataHolder instance;
    return &instance;
}

/*!-----------------------------------------------------------------------------
@brief      SynchWord取得
@note       SynchWordを取得する
@param      なし
@return     SynchWord
@attention  なし
------------------------------------------------------------------------------*/
CString InitializeDataHolder::getSynchWord()
{
    return synchWord_;
}

/*!-----------------------------------------------------------------------------
@brief      InitializeDataHolder改訂
@note       InitializeDataHolderを改訂する
@param      なし
@return     なし
@attention  なし
------------------------------------------------------------------------------*/
CString InitializeDataHolder::getRevision()
{
    return revision_;
}

/*!-----------------------------------------------------------------------------
@brief      
@note       
@param      
@return     なし
@attention  なし
------------------------------------------------------------------------------*/

void InitializeDataHolder::readIniFile()
{
    iniFileDao_->selectSection(_T("common"));
    synchWord_ = iniFileDao_->readValue(_T("SynchWord"));
    revision_ = iniFileDao_->readValue(_T("Revision"));
    outputDir_ = iniFileDao_->readValue(_T("OutputDirectory"));
    statusWordCheck_ = iniFileDao_->readValue(_T("StatusWordCheck"));
}

CString InitializeDataHolder::getOutputDir()
{
    return outputDir_;
}

void InitializeDataHolder::writeOutputDir(CString outputDir)
{
    iniFileDao_->writeValue(_T("OutputDirectory"), outputDir);
}

CString InitializeDataHolder::getStatusWordCheck()
{
    return statusWordCheck_;
}