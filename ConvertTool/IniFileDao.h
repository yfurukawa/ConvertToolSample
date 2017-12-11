/*!-----------------------------------------------------------------------------
@file       IniFileDao.h
@brief      Ini�t�@�C���f�[�^�A�N�Z�X�I�u�W�F�N�g�N���X�̒�`�t�@�C��
@attention  �Ȃ�
------------------------------------------------------------------------------*/
#if !defined(EA_38F79A87_8AF8_4b0c_957A_93296DBA6790__INCLUDED_)
#define EA_38F79A87_8AF8_4b0c_957A_93296DBA6790__INCLUDED_

// �C���N���[�h�t�@�C�� ======================================================
#include "StringHelper.h"

// �N���X�̑O���錾 =======================================================

// �}�N���̐錾 ================================================================

// �^�̐錾 ==================================================================


// �N���X��` ==================================================================
/*!-----------------------------------------------------------------------------
@class      IniFailDao�N���X
@brief      Ini�t�@�C���f�[�^�A�N�Z�X�I�u�W�F�N�g��ێ�����B
@note       �Ȃ�
@attention  �Ȃ�
@see        �Ȃ�
------------------------------------------------------------------------------*/
class IniFileDao
{

public:
	IniFileDao();
	virtual ~IniFileDao();

	IniFileDao(CString fileName);
	CString readValue(const CString& key);
	void selectSection(const CString sectionName);
	bool writeValue(const CString& key, const CString& value);

protected:
    CString iniFileName_;
	CString sectionName_;
    StringHelper helper_;
};
#endif // !defined(EA_38F79A87_8AF8_4b0c_957A_93296DBA6790__INCLUDED_)
