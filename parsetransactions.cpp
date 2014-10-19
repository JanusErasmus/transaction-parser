#include <QFile>
#include <QDebug>
#include <QRegExp>
#include <QStringList>

#include "parsetransactions.h"

parseTransactions::parseTransactions()
{
    QFile f("transactionHistory.csv");
    if(!f.exists())
    {
        qDebug() << "File does not exist";
        return;
    }

    if(!f.open(QFile::ReadOnly))
    {
        qDebug() << "Could not open file";
        return;
    }

    while(!f.atEnd())
    {
        QString line = f.readLine();
        //qDebug() << line;

        QRegExp rx("(\\d{4})(\\d{2})(\\d{2}),(.+),(-?\\d+.\\d+),(-?\\d+.\\d+)");
        rx.indexIn(line);

        int year, month, day;
        QString desc;
        double amount;
        double bank;

        QStringList lst = rx.capturedTexts();
        if(lst.length())
        {
            int idx = 0;
            QString str;
            foreach (str, lst)
            {
                switch(idx++)
                {
                case 1:
                {
                    year = str.toInt();
                }
                 break;

                case 2:
                {
                    month = str.toInt();
                }
                    break;

                case 3:
                {
                    day = str.toInt();
                }
                    break;

                case 4:
                {
                    desc = str;
                }
                    break;

                case 5:
                {
                    amount = str.toDouble();
                }
                    break;

                case 6:
                {
                    bank = str.toDouble();
                }
                    break;


                default:
                    break;
                }


            }

            transaction * trans = new transaction(year, month, day, desc, amount, bank);
            mTransactions.append(trans);
        }
    }

    f.close();
}

void parseTransactions::show()
{
    int length = mTransactions.length();
    if(length)
    {
        for(int k = (length - 1); k >= 0; k--)
        {
            mTransactions.at(k)->show();
        }
    }
}
