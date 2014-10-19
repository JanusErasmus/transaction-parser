#include <QDebug>

#include "transaction.h"

transaction::transaction()
{

}

transaction::transaction(int year, int month, int day, QString desc, double amount, double bank)
{
    mDate = QDate(year, month, day);
    mDesc = desc;
    mAmount = amount;
    mBank = bank;
}

void transaction::show()
{
    qDebug() << "Transaction :";
    qDebug() << "  Date  : " << mDate;
    qDebug() << "  Desc  : " << mDesc;
    qDebug() << "  Amount:" << mAmount;
    qDebug() << "  Bank  :" << mBank;
    qDebug() << "\n";
}
