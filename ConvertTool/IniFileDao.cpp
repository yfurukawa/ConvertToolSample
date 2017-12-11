/*!-----------------------------------------------------------------------------
@file       IniFileDao.cpp
@brief      Ini�t�@�C���f�[�^�A�N�Z�X�I�u�W�F�N�g�N���X�̒�`�t�@�C��
@attention  �Ȃ�
------------------------------------------------------------------------------*/
#include "stdafx.h"
#include "IniFileDao.h"

/*!-----------------------------------------------------------------------------
@brief      �f�t�H���g�R���X�g���N�^
@note       �N���X���\�z����B
@param[in]  �Ȃ�
@return     �Ȃ�
@attention  �Ȃ�
------------------------------------------------------------------------------*/
IniFileDao::IniFileDao(){

}



/*!-----------------------------------------------------------------------------
@brief      �f�X�g���N�^
@note       �N���X��j������B
@param      �Ȃ�
@return     �Ȃ�
@attention  �Ȃ�
------------------------------------------------------------------------------*/
IniFileDao::~IniFileDao(){

}


/*!-----------------------------------------------------------------------------
@brief      IniFileDao�N���X�ւ̃����N�ݒ�
@note       IniFileDao�N���X�̃C���X�^���X��ݒ肵�A�����N���m������B
@param[in]  CString fileName�N���X�̃C���X�^���X�A�h���X 
@return     �Ȃ�
@attention  �Ȃ�
------------------------------------------------------------------------------*/
IniFileDao::IniFileDao(CString fileName)
{
    CString currentDirectory(_T(""));
    helper_.GetRootPath(&currentDirectory);

    iniFileName_ = currentDirectory + fileName;

}


/*!-----------------------------------------------------------------------------
@brief      �Ǎ�
@note       buffer��255�o�C�g�ɐݒ�AsectionName_,key,buffer,sizeof(buffer),iniFileName_�̒l��ǂ݂ɂ����B
@param      �Ȃ�
@return     buffer�̒l��Ԃ�
@attention  �Ȃ�
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
@brief      ini�t�@�C���̃Z�N�V������I������
@note       �l����`����Ă���Z�N�V������ێ�����
@param[in]	sectionName�@�Z�N�V������	(-)[-]
@return     �Ȃ�
@attention  �Ȃ�
------------------------------------------------------------------------------*/
void IniFileDao::selectSection(const CString sectionName)
{
	sectionName_ = sectionName;

}


/*!-----------------------------------------------------------------------------
@brief      ������
@note       sectionName_,key,buffer,sizeof(buffer),iniFileName_�̒l��������
@param      �Ȃ�
@return     �Ȃ�
@attention  �Ȃ�
------------------------------------------------------------------------------*/
bool IniFileDao::writeValue(const CString& key, const CString& value)
{
	::WritePrivateProfileString(sectionName_,
								key,
								value,
								iniFileName_);
	return true;
}