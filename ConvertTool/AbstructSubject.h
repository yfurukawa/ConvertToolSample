/*!-----------------------------------------------------------------------------
@file       AbstructSubject.h
@brief      Observer�p�^�[����Subject�N���X
@attention  �Ȃ�
------------------------------------------------------------------------------*/
#pragma once

// �C���N���[�h�t�@�C�� ======================================================
#include <list>

// �N���X�̑O���錾 =======================================================
class Observer;

// �}�N���̐錾 ================================================================

// �^�̐錾 ==================================================================


// �N���X��` ==================================================================
class AbstructSubject
{
public:
    AbstructSubject(void);
    virtual ~AbstructSubject(void);
    void subscribe(Observer* observer);
    void unsubscribe(Observer* observer);
    virtual CString getData() = 0;

protected:
    std::list<Observer*> observers_;
    std::list<Observer*>::iterator itr_;
};

