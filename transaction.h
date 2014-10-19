#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <QDate>

class transaction
{
    QDate mDate;
    QString mDesc;
    double mAmount;
    double mBank;

public:
    transaction();
    transaction(int year, int month, int day, QString desc, double amount, double bank);
    void show();
};

#endif // TRANSACTION_H
