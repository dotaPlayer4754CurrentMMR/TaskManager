#include "task.h"

QDateTime parse_date_from_string(const char* _date_string) {
    QString w_val(_date_string);
    QList trimmed_sections = w_val.split(" ");
    if(trimmed_sections.length() != 2) {
        throw std::runtime_error("Wrong string type");
        return QDateTime();
    }

    QList date_format = trimmed_sections[0].split("-");
    QList time_format = trimmed_sections[1].split(":");
    if (date_format.length() != 3 || time_format.length() != 3){
        throw std::runtime_error("Wrong string type");
        return QDateTime();
    }
    QDate n_date(date_format[0].toInt(), date_format[1].toInt(), date_format[2].toInt());
    QTime n_time(time_format[0].toInt(),time_format[1].toInt(),time_format[2].toInt());
    return QDateTime(n_date, n_time);
}

Task::Task(QObject *parent)
    : QObject{parent}
{}

Task::Task(QObject *parent, const char* _name, const char* _deadline, int _priority) :
    QObject(parent),
    name(_name),
    deadline(parse_date_from_string(_deadline)),
    priority(_priority)
{

}

int Task::get_priority()
{
    return priority;
}

bool Task::operator<(const Task* other)
{
    return priority < other->priority;
}

void Task::print()
{
    qInfo() << "Name: " << name << " Deadline: " << deadline << " Priority: " << priority;
}
