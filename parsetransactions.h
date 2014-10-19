#ifndef PARSETRANSACTIONS_H
#define PARSETRANSACTIONS_H
#include <QList>

#include "transaction.h"

class parseTransactions
{
    QList<transaction*> mTransactions;

public:
    parseTransactions();
    void show();

    QList<transaction*> getList(){ return mTransactions; }
};

#endif // PARSETRANSACTIONS_H
