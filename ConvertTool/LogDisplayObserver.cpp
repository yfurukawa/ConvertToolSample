#include "StdAfx.h"
#include "LogDisplayObserver.h"
#include "AbstructSubject.h"

LogDisplayObserver::LogDisplayObserver(void)
{
}


LogDisplayObserver::~LogDisplayObserver(void)
{
}

/*!-----------------------------------------------------------------------------
@brief      CDDRDDataConverterDlgクラスへのリンク設定
@note       CDDRDDataConverterDlgクラスのインスタンスを設定し、リンクを確立する。
@param      dialog CDDRDDataConverterDlgクラスのインスタンスアドレス
@return     なし
@attention  なし
------------------------------------------------------------------------------*/

void LogDisplayObserver::setMainDialog(CDDRDataConverterDlg* dialog)
{
    dialog_ = dialog;
}

void LogDisplayObserver::notify(AbstructSubject* subject)
{
    dialog_->log(subject->getData());
}

void LogDisplayObserver::subscribe(AbstructSubject* subject)
{
    subject->subscribe(this);
}

void LogDisplayObserver::unsubscribe(AbstructSubject* subject)
{
    subject->unsubscribe(this);
}