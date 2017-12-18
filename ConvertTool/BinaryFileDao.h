/*!-----------------------------------------------------------------------------
@file       BinaryFileDao.h
@brief		�o�C�i���t�@�C���ւ̃A�N�Z�X��񋟂���
@attention  �Ȃ�
------------------------------------------------------------------------------*/
#pragma once
// �C���N���[�h�t�@�C�� ======================================================
#include "IFileDao.h"

// �N���X�̑O���錾 =======================================================

// �}�N���̐錾 ================================================================

// �^�̐錾 ==================================================================


// �N���X��` ==================================================================
/*!-----------------------------------------------------------------------------
@class      BinaryFileDao�N���X
@brief      �o�C�i���t�@�C���ւ̃A�N�Z�X��񋟂���
@note       �Ȃ�
@attention  �Ȃ�
@see        �Ȃ�
------------------------------------------------------------------------------*/
class BinaryFileDao : public IFileDao
{
public:
    BinaryFileDao(void);
    ~BinaryFileDao(void);
	virtual bool openReadOnly(FileName* fileName);
    void close();
    bool readData(void* readBuffer, int readSize);
    ULONGLONG getPosition();
    ULONGLONG getFileSize();

private:
    CFile binFile_;  //!< �ΏۂƂ���o�C�i���t�@�C���̃t�@�C���n���h��
    CFileException fileException_;  //!< �t�@�C���A�N�Z�X�̍ۂɔ���������O
    char synchWord_[4];  //!< DDR�f�[�^�̊J�n��\���V���N���[�h�@TODO FileDao���V���N���[�h��m���Ă���̂͂��������̂ŗv���t�@�N�^�����O

};

