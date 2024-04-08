#ifndef MODEL_H
#define MODEL_H

#include <QObject>

class Model : public QObject
{
public:
    explicit Model(QObject *parent = nullptr);

public slots:
    void textInputEntered(QString text);
};

#endif // MODEL_H
