#include "StdAfx.h"
#include "LogDisplayObserver.h"
#include "AbstructSubject.h"

LogDisplayObserver::LogDisplayObserver(void)
{
}


LogDisplayObserver::~LogDisplayObserver(void)
{
}

void LogDisplayObserver::notify(AbstructSubject* subject)
{
    subject->getData();
}

void LogDisplayObserver::subscribe(AbstructSubject* subject)
{
    subject->subscribe(this);
}

void LogDisplayObserver::unsubscribe(AbstructSubject* subject)
{
    subject->unsubscribe(this);
}