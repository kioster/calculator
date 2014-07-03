#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QString>

QString getFinResult( QString &expression ) ;
bool isHigher( QChar op_1 , QChar op_2 ) ;
bool isRight( QString &expression ) ;

#endif // CALCULATOR_H
