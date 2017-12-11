/*!-----------------------------------------------------------------------------
@file       StringHelper.h
@brief      StringHelper�N���X�̒�`�t�@�C��
@attention  �Ȃ�
------------------------------------------------------------------------------*/
#pragma once
// �C���N���[�h�t�@�C�� ======================================================
#include <afxcoll.h>

// �N���X�̑O���錾 =======================================================

// �}�N���̐錾 ================================================================

// �^�̐錾 ==================================================================


// �N���X��` ==================================================================
/*!-----------------------------------------------------------------------------
@class      StringHelper�N���X
@brief      CString��������w�肵�āACStringArray�ɕ�������
@note       �Ȃ�
@attention  �Ȃ�
@see        �Ȃ�
------------------------------------------------------------------------------*/
class StringHelper
{
public:
    StringHelper(void);
    ~StringHelper(void);
    //CString���������؂蕶�����w�肵�āACStringArray�ɕ�������
    void Split(CStringArray* pstrArray,LPCTSTR szTarget,LPCTSTR szDelimiter);
    CString GetFileName( CString strPath );
    void GetRootPath( CString* const pstrPath );
};

