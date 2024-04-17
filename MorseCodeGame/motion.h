#ifndef MOTION_H
#define MOTION_H

#include<Box2D/Box2D.h>
#include <QTimer>
#include <QObject>


class Motion : public QObject
{
    Q_OBJECT
public:
    Motion();

    ~Motion();

public slots:
    void updateWorld();

signals:
    void newCaptainHeight(int yPosition);

private:
    b2World* world;
    b2Body* body;
    QTimer* timer;
    float32 timeStep = 1.0f / 60.0f;
    int32 velocityIterations = 6;
    int32 positionIterations = 2;
};

#endif // MOTION_H
