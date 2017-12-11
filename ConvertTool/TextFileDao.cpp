/*!-----------------------------------------------------------------------------
@file       TextFileDao.cpp
@brief      �e�L�X�g�t�@�C���f�[�^�A�N�Z�X�I�u�W�F�N�g�̒�`�t�@�C��
@attention  �Ȃ�
------------------------------------------------------------------------------*/
#include "StdAfx.h"
#include "atlsimpstr.h"
#include <locale.h>

#include "TextFileDao.h"

/*!-----------------------------------------------------------------------------
@brief      �f�t�H���g�R���X�g���N�^
@note       �N���X���\�z����B
@param[in]  �Ȃ�
@return     �Ȃ�
@attention  �Ȃ�
------------------------------------------------------------------------------*/
TextFileDao::TextFileDao(void)
{
}

/*!-----------------------------------------------------------------------------
@brief      �f�X�g���N�^
@note       �N���X��j������B
@param      �Ȃ�
@return     �Ȃ�
@attention  �Ȃ�
------------------------------------------------------------------------------*/
TextFileDao::~TextFileDao(void)
{
}

/*!-----------------------------------------------------------------------------
@brief      �t�@�C�����J��
@note       �w�肳�ꂽ�t�@�C�����Ńe�L�X�g�t�@�C����ǂݏ����ł���悤�ɊJ��
@param[in]  fileName    �t�@�C����   (-) [-]
@return     �t�@�C���I�[�v���̐��ہitrue �F �����Afalse �F ���s�j
@attention  �Ȃ�
------------------------------------------------------------------------------*/
BOOL TextFileDao::open(CString fileName)
{
    errno_t err;

    // ���������{��Ɍ��肷��B
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
@brief      ��������
@note       �t�@�C���Ƀe�L�X�g�f�[�^����������
@param[in]  message�@�������ރe�L�X�g�f�[�^ (-) [-]
@return     �Ȃ�
@attention  �Ȃ�
------------------------------------------------------------------------------*/
void TextFileDao::write(const CString& message)
{
	_ftprintf_s(file, message.GetString());
}

/*!-----------------------------------------------------------------------------
@brief      �t�@�C�����N���[�Y����
@note       �I�[�v������Ă���t�@�C�������
@param      �Ȃ�
@return     �Ȃ�
@attention  �Ȃ�
------------------------------------------------------------------------------*/
void TextFileDao::close()
{
	fclose(file);
}
