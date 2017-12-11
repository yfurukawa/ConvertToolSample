/*!-----------------------------------------------------------------------------
@file       TimeUtility.cpp
@brief      ���ԗL���t�@�C��
@attention  �Ȃ�
------------------------------------------------------------------------------*/
#include "StdAfx.h"
#include "TimeUtility.h"

/*!-----------------------------------------------------------------------------
@brief      �f�t�H���g�R���X�g���N�^
@note       �N���X���\�z����B
@param[in]  �Ȃ�
@return     �Ȃ�
@attention  �Ȃ�
------------------------------------------------------------------------------*/
TimeUtility::TimeUtility(void)
{
}


/*!-----------------------------------------------------------------------------
@brief      �f�X�g���N�^
@note       �N���X��j������B
@param      �Ȃ�
@return     �Ȃ�
@attention  �Ȃ�
------------------------------------------------------------------------------*/
TimeUtility::~TimeUtility(void)
{
}

/*!-----------------------------------------------------------------------------
@brief      �����擾
@note       ���ݎ������擾�B"HH:MM:SS"�`���̎���������ɒu�����B
@param      �Ȃ�
@return     str
@attention  �Ȃ�
------------------------------------------------------------------------------*/
CString TimeUtility::getCurrentTime()
{
    CTime    cTime;
	CString  str;

	cTime = CTime::GetCurrentTime();           // ���ݎ���
	
	str = cTime.Format(_T("%H:%M:%S"));   // "HH:MM:SS"�`���̎�����������擾

	return str;
}

/*!-----------------------------------------------------------------------------
@brief      �����擾
@note       ���ݎ������擾�B"YYYY.mm.dd"�`���̎���������ɒu�����B
@param      �Ȃ�
@return     str
@attention  �Ȃ�
------------------------------------------------------------------------------*/
CString TimeUtility::getCurrentDate()
{
    CTime    cTime;
	CString  str;

	cTime = CTime::GetCurrentTime();           // ���ݎ���
	
	str = cTime.Format(_T("%Y.%m.%d"));   // "YYYY.mm.dd"�`���̎�����������擾

	return str;
}