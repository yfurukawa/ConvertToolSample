/*!-----------------------------------------------------------------------------
@file       AbstructSubject.cpp
@brief      ObserverパターンのSubjectクラス
@attention  なし
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
