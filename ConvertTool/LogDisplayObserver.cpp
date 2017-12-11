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
@brief      CDDRDDataConverterDlg�N���X�ւ̃����N�ݒ�
@note       CDDRDDataConverterDlg�N���X�̃C���X�^���X��ݒ肵�A�����N���m������B
@param      dialog CDDRDDataConverterDlg�N���X�̃C���X�^���X�A�h���X
@return     �Ȃ�
@attention  �Ȃ�
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