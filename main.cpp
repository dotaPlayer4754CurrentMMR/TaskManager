#include "mainwindow.h"

#include <QApplication>
#include "task_queue.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    task_queue tq(&a);
    for (int i = 0; i < 10; i++) {
        Task* n_task = new Task(&a, "name", "2022-12-02 12:21:02", 10 - i);
        QSharedPointer<Task> ab(n_task);
        tq.push(ab);
    }
    tq.print();
    w.show();
    return a.exec();
}
