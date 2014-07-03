#include "calculator_sim.h"
#include <QString>
#include <QStringList>

QString getFinResult_v1( QString &exp )
{
    /*if ( !isRight(exp))
    {
        return "" ;
    }*/

    QStringList nums ;
    QString fore , back ;
    double f_fore = 1 , f_back = 1 ;
    int oper = '\0' ;
    bool finish = false ;

    if ( exp.contains('('))
    {
        exp.remove('(') ;
        exp.remove(')') ;
    }

    for ( int i = 0 ; i < exp.length() && !finish ; i++ )
    {

        switch (exp[i].toLatin1())
        {
        case '+' :
            oper = '+' ;
            nums = exp.split('+') ;
            fore = nums.at(0).toLocal8Bit().data() ;
            back = nums.at(1).toLocal8Bit().data() ;
            finish = true ;
            break;

        case '-' :
            oper = '-' ;
            nums = exp.split('-') ;
            fore = nums.at(0).toLocal8Bit().data() ;
            back = nums.at(1).toLocal8Bit().data() ;
            finish = true ;
            break;

        case '*' :
            oper = '*' ;
            nums = exp.split('*') ;
            fore = nums.at(0).toLocal8Bit().data() ;
            back = nums.at(1).toLocal8Bit().data() ;
            finish = true ;
            break;

        case '/' :
            oper = '/' ;
            nums = exp.split('/') ;
            fore = nums.at(0).toLocal8Bit().data() ;
            back = nums.at(1).toLocal8Bit().data() ;
            finish = true ;
            break;

        default:
            break;
        }
    }

    f_fore *= fore.toDouble() ;
    f_back *= back.toDouble() ;
    double d_result = 0 ;

    switch (oper)
    {
    case '+':
        d_result = f_fore + f_back ;
        break;

    case '-':
        d_result = f_fore - f_back ;
        break;

    case '*':
        d_result = f_fore * f_back ;
        break;

    case '/':
        d_result = f_fore / f_back ;
        break;

    default:
        break;
    }

    QString result = QString( "%1" ).arg(d_result ) ;

    return result ;
}
















