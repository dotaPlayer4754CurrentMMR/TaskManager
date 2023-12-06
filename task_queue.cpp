#include "task_queue.h"

task_queue::task_queue(QObject *parent)
    : QObject{parent}
{}

void task_queue::push(QSharedPointer<Task> n_task)
{
    tasks.append(n_task);
    std::sort(  tasks.begin(),
                tasks.end(),
                [](QSharedPointer<Task> l, QSharedPointer<Task> r){
                    return l->get_priority() < r->get_priority();
                }                                                   );
}

QSharedPointer<Task> task_queue::pop()
{
    if (is_empty()) return QSharedPointer<Task>();

    return tasks.takeFirst();
}

bool task_queue::is_empty()
{
    return tasks.empty();
}

void task_queue::print()
{
    for(const auto& it : tasks){
        it->print();
    }
}
