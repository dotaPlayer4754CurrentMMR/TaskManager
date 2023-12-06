#ifndef TASK_QUEUE_H
#define TASK_QUEUE_H

#include <QObject>
#include "task.h"

class task_queue : public QObject
{
    Q_OBJECT
public:
    explicit task_queue(QObject *parent = nullptr);

    void push(QSharedPointer<Task> n_task);

    QSharedPointer<Task> pop();

    bool is_empty();

    void print();

signals:

private:
    QList<QSharedPointer<Task>> tasks;
};

#endif // TASK_QUEUE_H
