/*!-----------------------------------------------------------------------------
@file       AbstructSubject.cpp
@brief      Observer�p�^�[����Subject�N���X
@attention  �Ȃ�
------------------------------------------------------------------------------*/
#include "StdAfx.h"
#include "AbstructSubject.h"
#include "Observer.h"

AbstructSubject::AbstructSubject(void)
{
    observers_.clear();
}


AbstructSubject::~AbstructSubject(void)
{
}

void AbstructSubject::subscribe(Observer* observer)
{
    observers_.push_back(observer);
}
