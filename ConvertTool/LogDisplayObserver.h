/*!-----------------------------------------------------------------------------
@file       LogDisplayObserver.h
@brief      ���O�f�[�^���_�C�A���O�ɕ\������I�u�U�[�o
@attention  �Ȃ�
------------------------------------------------------------------------------*/
#pragma once
// �C���N���[�h�t�@�C�� ======================================================

// �N���X�̑O���錾 =======================================================
class AbstructSubject;

// �}�N���̐錾 ================================================================

// �^�̐錾 ==================================================================


// �N���X��` ==================================================================
/*!-----------------------------------------------------------------------------
@class      LogDisplayObserver
@brief      ���O���_�C�A���O�ɒʒm����
@note       �Ȃ�
@attention  �Ȃ�
@see        �Ȃ�
------------------------------------------------------------------------------*/
#include "observer.h"
class LogDisplayObserver :
    public Observer
{
public:
    LogDisplayObserver(void);
    virtual ~LogDisplayObserver(void);
    virtual void notify(AbstructSubject* subject);
    void subscribe(AbstructSubject* subject);
    void unsubscribe(AbstructSubject* subject);

private:
    
};

