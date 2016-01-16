#include "triggerevent.h"

const QEvent::Type TriggerEvent::TriggerUpdate =
    static_cast<QEvent::Type>(QEvent::registerEventType());

const QEvent::Type TriggerEvent::TriggerActivate =
    static_cast<QEvent::Type>(QEvent::registerEventType());

TriggerEvent::TriggerEvent(QEvent::Type type) : QEvent(type)
{
}

TriggerEvent::~TriggerEvent()
{
}

