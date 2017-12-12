/*!-----------------------------------------------------------------------------
@file       InitializeDataHolder.cpp
@brief      
@attention  �Ȃ�
------------------------------------------------------------------------------*/
#include "StdAfx.h"
#include "InitializeDataHolder.h"
#include "IniFileDao.h"

/*!-----------------------------------------------------------------------------
@brief      �f�t�H���g�R���X�g���N�^
@note       �N���X���\�z����B
@param[in]  �Ȃ�
@return     �Ȃ�
@attention  �Ȃ�
------------------------------------------------------------------------------*/
InitializeDataHolder::InitializeDataHolder() :
key1_(_T("")), key2_(_T("")), outputDir_(_T("c:\\")), iniFileDao_(NULL)
{
    iniFileDao_ = new IniFileDao(_T("ConverterTool.ini"));
    this->readIniFile();
}

/*!-----------------------------------------------------------------------------
@brief      �f�X�g���N�^
@note       �N���X��j������B
@param      �Ȃ�
@return     �Ȃ�
@attention  �Ȃ�
------------------------------------------------------------------------------*/
InitializeDataHolder::~InitializeDataHolder(){
    delete iniFileDao_;
    iniFileDao_ = NULL;
}

/*!-----------------------------------------------------------------------------
@brief      
@note       
@param      
@return     �Ȃ�
@attention  �Ȃ�
------------------------------------------------------------------------------*/
InitializeDataHolder* InitializeDataHolder::getInstance()
{
    static InitializeDataHolder instance;
    return &instance;
}

/*!-----------------------------------------------------------------------------
@brief      Key1�̒l�擾
@note       Key1�̒l���擾����
@param      �Ȃ�
@return     
@attention  �Ȃ�
------------------------------------------------------------------------------*/
CString InitializeDataHolder::getKey1()
{
    return key1_;
}

/*!-----------------------------------------------------------------------------
@brief      Key2�̒l�擾
@note       Key2�̒l���擾����
@param      �Ȃ�
@return     
@attention  �Ȃ�
------------------------------------------------------------------------------*/
CString InitializeDataHolder::getKey2()
{
    return key2_;
}

/*!-----------------------------------------------------------------------------
@brief      
@note       
@param      
@return     �Ȃ�
@attention  �Ȃ�
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
