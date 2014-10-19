#include <QCoreApplication>
#include <QDebug>
#include <iostream>

#include "parsetransactions.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    parseTransactions p;
    QList<transaction*> list = p.getList();

    int idx = list.length() - 1;
    transaction * trans = list.at(idx);
    while(idx--)
    {
        trans->show();

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

        trans = list.at(idx);
    };

    a.exit(0);
    exit(0);
}
