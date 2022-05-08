#ifndef STRINGMANIPULATIONCORE_H
#define STRINGMANIPULATIONCORE_H

#include <QObject>

class StringManipulationCore : public QObject
{
    Q_OBJECT
public:
    explicit StringManipulationCore(QObject *parent = nullptr);

public slots:
    void selectedStringToCharArray();
    void stripSpaceInSelectedString();
    void addBreakPoint();
    void sortDeclarationByLength();
    void pasteDiff();
    void searchInGoogle();
};

#endif // STRINGMANIPULATIONCORE_H
