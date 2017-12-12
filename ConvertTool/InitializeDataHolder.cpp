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
key1_(_T("")), key2_(_T("")), outputDir_(_T("c:\\")), iniFileDao_(NULL)
{
    iniFileDao_ = new IniFileDao(_T("ConverterTool.ini"));
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
@brief      Key1の値取得
@note       Key1の値を取得する
@param      なし
@return     
@attention  なし
------------------------------------------------------------------------------*/
CString InitializeDataHolder::getKey1()
{
    return key1_;
}

/*!-----------------------------------------------------------------------------
@brief      Key2の値取得
@note       Key2の値を取得する
@param      なし
@return     
@attention  なし
------------------------------------------------------------------------------*/
CString InitializeDataHolder::getKey2()
{
    return key2_;
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
    key1_ = iniFileDao_->readValue(_T("Key1"));
    key2_ = iniFileDao_->readValue(_T("Key2"));
    outputDir_ = iniFileDao_->readValue(_T("OutputDirectory"));
}

CString InitializeDataHolder::getOutputDir()
{
    return outputDir_;
}

void InitializeDataHolder::writeOutputDir(CString outputDir)
{
    iniFileDao_->writeValue(_T("OutputDirectory"), outputDir);
}
