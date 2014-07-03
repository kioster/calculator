#include <QtCore\QString>
#include <string>
#include "dialog.h"
#include "ui_dialog.h"
#include "calculator_sim.h"
#include "calculator.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    //ui->Input->setCursor();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_0_clicked(bool checked)
{

    if (!checked)
    {
        s_input += '0';
        ui->Input->setText(s_input);
        ui->Input->show();
    }

}


void Dialog::on_pushButton_1_clicked(bool checked)
{
    if (!checked)
    {
        s_input += '1';
        ui->Input->setText(s_input);
        ui->Input->show();
    }
}

void Dialog::on_pushButton_2_clicked(bool checked)
{
    if (!checked)
    {
        s_input += '2';
        ui->Input->setText(s_input);
        ui->Input->show();
    }
}

void Dialog::on_pushButton_3_clicked(bool checked)
{
    if (!checked)
    {
        s_input += '3';
        ui->Input->setText(s_input);
        ui->Input->show();
    }
}

void Dialog::on_pushButton_4_clicked(bool checked)
{
    if (!checked)
    {
        s_input += '4';
        ui->Input->setText(s_input);
        ui->Input->show();
    }
}

void Dialog::on_pushButton_5_clicked(bool checked)
{
    if (!checked)
    {
        s_input += '5';
        ui->Input->setText(s_input);
        ui->Input->show();
    }
}

void Dialog::on_pushButton_6_clicked(bool checked)
{
    if (!checked)
    {
        s_input += '6';
        ui->Input->setText(s_input);
        ui->Input->show();
    }
}

void Dialog::on_pushButton_7_clicked(bool checked)
{
    if (!checked)
    {
        s_input += '7';
        ui->Input->setText(s_input);
        ui->Input->show();
    }
}

void Dialog::on_pushButton_8_clicked(bool checked)
{
    if (!checked)
    {
        s_input += '8';
        ui->Input->setText(s_input);
        ui->Input->show();
    }
}

void Dialog::on_pushButton_9_clicked(bool checked)
{
    if (!checked)
    {
        s_input += '9';
        ui->Input->setText(s_input);
        ui->Input->show();
    }
}

void Dialog::on_pushButton_point_clicked(bool checked)
{
    if (!checked)
    {
        s_input += '.';
        ui->Input->setText(s_input);
        ui->Input->show();
    }
}

void Dialog::on_pushButton_plus_clicked(bool checked)
{
    if (!checked)
    {
        s_input += '+';
        ui->Input->setText(s_input);
        ui->Input->show();
    }
}

void Dialog::on_pushButton_minus_clicked(bool checked)
{
    if (!checked)
    {
        s_input += '-';
        ui->Input->setText(s_input);
        ui->Input->show();
    }
}

void Dialog::on_pushButton_multi_clicked(bool checked)
{
    if (!checked)
    {
        s_input += '*';
        ui->Input->setText(s_input);
        ui->Input->show();
    }
}

void Dialog::on_pushButton_devide_clicked(bool checked)
{
    if (!checked)
    {
        s_input += '/';
        ui->Input->setText(s_input);
        ui->Input->show();
    }
}

void Dialog::on_pushButton_left_clicked(bool checked)
{
    if (!checked)
    {
        s_input += '(';
        ui->Input->setText(s_input);
        ui->Input->show();
    }
}

void Dialog::on_pushButton_right_clicked(bool checked)
{
    if (!checked)
    {
        s_input += ')';
        ui->Input->setText(s_input);
        ui->Input->show();
    }
}

void Dialog::on_pushButton_AC_clicked(bool checked)
{
    if (!checked)
    {
        s_input.clear();
        s_output.clear();
        ui->Input->setText(s_input);
        ui->Input->show();
        ui->Output->setText(s_output);
        ui->Output->show();
    }
}

void Dialog::on_pushButton_Back_clicked(bool checked)
{
    if (!checked)
    {
        s_input.chop(1);
        ui->Input->setText(s_input);
        ui->Input->show();
    }

}

void Dialog::on_pushButton_equal_clicked(bool checked)
{
    if (!checked)
    {
        s_output = getResult(s_input) ;

        if (s_output.isEmpty())
        {
            s_input.clear();
            ui->Input->setText(s_input);
            ui->Input->show();
            ui->Output->setText(s_output);
            ui->Output->show();

            return ;

        }

        ui->Output->setText(s_output);
        ui->Output->show();
        ui->Input->setText(s_input);
        ui->Input->show();
        s_input.clear();
    }
}

QString Dialog::getResult(QString &expression_)
{
    QString result = getFinResult(expression_);

    return result ;
}

void Dialog::keyPressEvent( QKeyEvent *key )
{

    if ( key->key() == Qt::Key_0 )
    {
       this->on_pushButton_0_clicked(false);
    }

    if ( key->key() == Qt::Key_1 )
    {
        this->on_pushButton_1_clicked(false);
    }

    if ( key->key() == Qt::Key_2 )
    {
        this->on_pushButton_2_clicked(false);
    }

    if ( key->key() == Qt::Key_3 )
    {
        this->on_pushButton_3_clicked(false);
    }

    if ( key->key() == Qt::Key_4 )
    {
        this->on_pushButton_4_clicked(false);
    }

    if ( key->key() == Qt::Key_5 )
    {
        this->on_pushButton_5_clicked(false);
    }

    if ( key->key() == Qt::Key_6 )
    {
        this->on_pushButton_6_clicked(false);
    }

    if ( key->key() == Qt::Key_7 )
    {
        this->on_pushButton_7_clicked(false);
    }

    if ( key->key() == Qt::Key_8 )
    {
        this->on_pushButton_8_clicked(false);
    }

    if ( key->key() == Qt::Key_9 )
    {
        this->on_pushButton_9_clicked(false);
    }

    if ( key->key() == Qt::Key_Plus )
    {
        this->on_pushButton_plus_clicked(false);
    }

    if ( key->key() == Qt::Key_Minus )
    {
        this->on_pushButton_minus_clicked(false);
    }

    if ( key->key() == Qt::Key_Asterisk )
    {
        this->on_pushButton_multi_clicked(false);
    }

    if ( key->key() == Qt::Key_Slash )
    {
        this->on_pushButton_devide_clicked(false);
    }

    if ( key->key() == Qt::Key_Period )
    {
        this->on_pushButton_point_clicked(false);
    }

    if ( key->key() == Qt::Key_ParenLeft )
    {
        this->on_pushButton_left_clicked(false);
    }

    if ( key->key() == Qt::Key_ParenRight )
    {
        this->on_pushButton_right_clicked(false);
    }

    if ( key->key() == Qt::Key_Backspace )
    {
        this->on_pushButton_Back_clicked(false);
    }

    if ( key->key() == Qt::Key_Equal ||
         key->key() == Qt::Key_Enter ||
         key->key() == Qt::Key_Return )
    {
        this->on_pushButton_equal_clicked(false);
    }

}
