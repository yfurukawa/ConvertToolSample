/*!-----------------------------------------------------------------------------
@file       AbstructSubject.h
@brief      ObserverパターンのSubjectクラス
@attention  なし
------------------------------------------------------------------------------*/
#pragma once

// インクルードファイル ======================================================
#include <list>

// クラスの前方宣言 =======================================================
class Observer;

// マクロの宣言 ================================================================

// 型の宣言 ==================================================================


// クラス定義 ==================================================================
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

