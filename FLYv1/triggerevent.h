#ifndef TRIGGEREVENT_H
#define TRIGGEREVENT_H
#include <QEvent>

class TriggerEvent : public QEvent
{
public:
    static const QEvent::Type TriggerUpdate;
    static const QEvent::Type TriggerActivate;

    explicit TriggerEvent(QEvent::Type type);
    virtual ~TriggerEvent();
};

#endif // TRIGGEREVENT_H
