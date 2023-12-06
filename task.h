#ifndef TASK_H
#define TASK_H

#include <QObject>
#include <QDateTime>

class Task : public QObject
{
    Q_OBJECT
public:
    explicit Task(QObject *parent = nullptr);

    explicit Task(QObject *parent = nullptr, const char* _name = nullptr, const char* _deadline = nullptr, int _priority = 0);

    int get_priority();

    bool operator<(const Task* other);

    void print();

signals:

public slots:

private:
    QString name;
    QDateTime deadline;
    int priority;
};

#endif // TASK_H
