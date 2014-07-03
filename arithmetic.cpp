#include <QString>
#include <QStringList>
#include "arithmetic.h"

QString add_v1( QString &fore_ , QString &back_ )
{

    if (fore_.isEmpty() || back_.isEmpty())
    {
        return "";
    }

    if ( fore_[0] == '~' )
    {
        fore_[0] = '-' ;
    }

    if ( back_[0] == '~' )
    {
        back_[0] = '-' ;
    }

    double fore = fore_.toDouble() ;
    double back = back_.toDouble() ;
    double d_result = fore + back ;
    QString result = QString( "%1" ).arg(d_result) ;

    return result ;

}

QString minus_v1( QString &fore_ , QString &back_ )
{

    if ( fore_[0] == '~' )
    {
        fore_[0] = '-' ;
    }

    if ( back_[0] == '~' )
    {
        back_[0] = '-' ;
    }

    double fore = fore_.toDouble() ;
    double back = back_.toDouble() ;
    double d_result = fore - back ;
    QString result = QString( "%1" ).arg(d_result) ;

    return result ;

}

QString multi_v1( QString &fore_ , QString &back_ )
{

    if ( fore_[0] == '~' )
    {
        fore_[0] = '-' ;
    }

    if ( back_[0] == '~' )
    {
        back_[0] = '-' ;
    }

    double fore = fore_.toDouble() ;
    double back = back_.toDouble() ;
    double d_result = fore * back ;
    QString result = QString( "%1" ).arg(d_result) ;

    return result ;

}

QString devide_v1( QString &fore_ , QString &back_ )
{

    if ( fore_[0] == '~' )
    {
        fore_[0] = '-' ;
    }

    if ( back_[0] == '~' )
    {
        back_[0] = '-' ;
    }

    if ( back_ == QString("0") )
    {
        return "" ;
    }

    double fore = fore_.toDouble() ;
    double back = back_.toDouble() ;
    double d_result = fore / back ;
    QString result = QString( "%1" ).arg(d_result) ;

    return result ;

}

QString add( QString &fore_ , QString &back_ )
{

    if ( fore_[0] == '~' )
    {
        fore_[0] = '-' ;
    }

    if ( back_[0] == '~' )
    {
        back_[0] = '-' ;
    }

    QStringList fore_exp = fore_.split('/') ;
    QStringList back_exp = back_.split('/') ;
    double temp_result = fore_exp[0].toDouble()*back_exp[1].toDouble() + fore_exp[1].toDouble()*back_exp[0].toDouble() ;
    QString result = QString("%1").arg(temp_result) ;
    result += '/' ;
    temp_result = fore_exp[1].toDouble() * back_exp[1].toDouble() ;
    result += QString("%1").arg(temp_result) ;

    return result ;

}

QString minus( QString &fore_ , QString &back_ )
{

    if ( fore_[0] == '~' )
    {
        fore_[0] = '-' ;
    }

    if ( back_[0] == '~' )
    {
        back_[0] = '-' ;
    }

    QStringList fore_exp = fore_.split('/') ;
    QStringList back_exp = back_.split('/') ;
    double temp_result = fore_exp[0].toDouble()*back_exp[1].toDouble() - fore_exp[1].toDouble()*back_exp[0].toDouble() ;
    QString result = QString("%1").arg(temp_result) ;
    result += '/' ;
    temp_result = fore_exp[1].toDouble() * back_exp[1].toDouble() ;
    result += QString("%1").arg(temp_result) ;

    return result ;

}

QString multi( QString &fore_ , QString &back_ )
{

    if ( fore_[0] == '~' )
    {
        fore_[0] = '-' ;
    }

    if ( back_[0] == '~' )
    {
        back_[0] = '-' ;
    }

    QStringList fore_exp = fore_.split('/') ;
    QStringList back_exp = back_.split('/') ;
    double temp_result = fore_exp[0].toDouble()*back_exp[0].toDouble() ;
    QString result = QString("%1").arg(temp_result) ;
    result += '/' ;
    temp_result = fore_exp[1].toDouble()*back_exp[1].toDouble()  ;
    result += QString("%1").arg(temp_result) ;

    return result ;

}

QString devide( QString &fore_ , QString &back_ )
{

    if ( fore_[0] == '~' )
    {
        fore_[0] = '-' ;
    }

    if ( back_[0] == '~' )
    {
        back_[0] = '-' ;
    }

    QStringList fore_exp = fore_.split('/') ;
    QStringList back_exp = back_.split('/') ;

    if ( back_exp[0] == "0" )
    {

        return "" ;

    }

    double temp_result = fore_exp[0].toDouble()*back_exp[1].toDouble() ;
    QString result = QString("%1").arg(temp_result) ;
    result += '/' ;
    temp_result = fore_exp[1].toDouble()*back_exp[0].toDouble()  ;
    result += QString("%1").arg(temp_result) ;

    return result ;

}




