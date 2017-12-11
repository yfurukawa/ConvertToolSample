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
synchWord_(_T("DEADBEEF")), revision_(_T("01")), outputDir_(_T("c:\\")), iniFileDao_(NULL), statusWordCheck_(_T(""))
{
    iniFileDao_ = new IniFileDao(_T("DDRDataConverter.ini"));
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
@brief      SynchWord�擾
@note       SynchWord���擾����
@param      �Ȃ�
@return     SynchWord
@attention  �Ȃ�
------------------------------------------------------------------------------*/
CString InitializeDataHolder::getSynchWord()
{
    return synchWord_;
}

/*!-----------------------------------------------------------------------------
@brief      InitializeDataHolder����
@note       InitializeDataHolder����������
@param      �Ȃ�
@return     �Ȃ�
@attention  �Ȃ�
------------------------------------------------------------------------------*/
CString InitializeDataHolder::getRevision()
{
    return revision_;
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