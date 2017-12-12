/*!-----------------------------------------------------------------------------
@file       LogDisplayObserver.h
@brief      ログデータをダイアログに表示するオブザーバ
@attention  なし
------------------------------------------------------------------------------*/
#pragma once
// インクルードファイル ======================================================

// クラスの前方宣言 =======================================================
class AbstructSubject;

// マクロの宣言 ================================================================

// 型の宣言 ==================================================================


// クラス定義 ==================================================================
/*!-----------------------------------------------------------------------------
@class      LogDisplayObserver
@brief      ログをダイアログに通知する
@note       なし
@attention  なし
@see        なし
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

