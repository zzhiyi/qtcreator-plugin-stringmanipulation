#ifndef STRINGMANIPULATIONCORE_HPP
#define STRINGMANIPULATIONCORE_HPP

#include <QObject>

class StringManipulationCore : public QObject
{
    Q_OBJECT
public:
    explicit StringManipulationCore(QObject *parent = nullptr);

public slots:
    void stringToCharArray();
};

#endif // STRINGMANIPULATIONCORE_HPP
