#include <QString>
#include <QStringList>
#include <QStack>
#include <QRegularExpression>
#include <QRegExp>
#include <string>
#include <qstring.h>
#include "arithmetic.h"
#include "calculator.h"

QString getFinResult( QString &expression_ )
{
    QStack<QChar> operator_box ;
    QString postfix_exp ;
    QString expression = expression_ ;
    expression.insert(0 , "(") ;
    expression += ")"  ;

    for ( int i = 0 ; i < expression.length() ; i++ )
    {

        if ( expression[i] == '(' && expression[i+1] == '-' )
        {
            expression[i+1] = '~' ;
        }

    }

    for ( int i = 0 ; i < expression.length() ; i++ )
    {

        if ( expression[i] == '(' )
        {
            operator_box.push( expression[i] ) ;
        }

        if ( expression[i] == ')' )
        {

            while ( operator_box.top() != '(' && !operator_box.isEmpty() )
            {
                postfix_exp += '|' ;
                postfix_exp += operator_box.top() ;
                operator_box.pop() ;
            }

            if ( operator_box.isEmpty() )
            {
                return "" ;
            }

            operator_box.pop() ;
        }

        if ( expression[i] == '+' ||
             expression[i] == '-' ||
             expression[i] == '*' ||
             expression[i] == '/' )
        {
            postfix_exp += '|' ;

            if ( operator_box.isEmpty() )
            {
                operator_box.push( expression[i] ) ;
            }

            else if ( isHigher( expression[i] , operator_box.top() ) )
            {
                operator_box.push( expression[i] ) ;
            }

            else
            {

                if ( operator_box.isEmpty() )
                {
                    return "" ;
                }

                postfix_exp += operator_box.top() ;
                postfix_exp += '|' ;
                operator_box.pop() ;
                operator_box.push( expression[i] ) ;
            }

        }

        if ( (expression[i] >= '0' && expression[i] <= '9') ||
             expression[i] == '~' || expression[i] == '.' )
        {
            postfix_exp += expression[i] ;
        }


    }


    while ( !operator_box.isEmpty() )
    {
       postfix_exp += '|' ;
       postfix_exp += operator_box.top() ;
       operator_box.pop() ;
    }

    operator_box.clear();

    /*后面开始计算后缀表达式*/

    QStringList num_box = postfix_exp.split( '|' ) ;
    QStack<QString> calculator_box ;
    QString fore , back , result(num_box[0]) ;

    for ( int i = 0 ; i < num_box.count() && !result.isEmpty()  ; i++ )
    {

        if ( !num_box.isEmpty() && ((num_box[i][0]>='0' && num_box[i][0]<='9') ||
             num_box[i][0] == '~' ))
        {
            num_box[i] += "/1" ;
            calculator_box.push( num_box[i].toLocal8Bit().data() ) ;
            continue ;
        }

        else
        {

            if ( calculator_box.isEmpty() )
            {
                return "" ;
            }

            back = calculator_box.top() ;
            calculator_box.pop() ;

            if ( calculator_box.isEmpty() )
            {
                return "" ;
            }

            fore = calculator_box.top() ;
            calculator_box.pop() ;

            if ( num_box.isEmpty() )
            {
                return "" ;
            }

            switch ( num_box[i][0].toLatin1() )
            {
            case '+' :
                result = add( fore , back ) ;
                break ;
            case '-' :
                result = minus( fore , back ) ;
                break ;
            case '*' :
                result = multi( fore , back ) ;
                break ;
            case '/' :
                result = devide( fore , back ) ;
                break ;

            default :
                return "" ;
            }

            calculator_box.push( result ) ;
        }

    }

    if ( !result.isEmpty() )
    {
        double d_result = 0.0 ;

        if ( calculator_box.isEmpty() )
        {
            return "" ;
        }

        result = calculator_box.top() ;

        if ( result[0] == '~' )
        {
            result[0] = '-' ;
        }

        num_box.clear() ;
        num_box = result.split('/') ;
        d_result = num_box[0].toDouble() / num_box[1].toDouble() ;
        result = QString("%0").arg(d_result) ;
    }

    calculator_box.clear() ;
    num_box.clear() ;

    return result ;

}

bool isHigher( QChar op_1 , QChar op_2 )
{
    if ( ( op_1 == '+' || op_1 == '-' ) && op_2 != '(' )
    {
        return false ;
    }

    if ( op_2 == '*' || op_2 == '/' )
    {
        return false ;
    }

    return true ;

}















