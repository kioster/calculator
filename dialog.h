#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QString>
#include <QtGui>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    void keyPressEvent( QKeyEvent *key ) ;
    ~Dialog();

private slots:

    void on_pushButton_0_clicked(bool checked);

    void on_pushButton_1_clicked(bool checked);

    void on_pushButton_2_clicked(bool checked);

    void on_pushButton_3_clicked(bool checked);

    void on_pushButton_4_clicked(bool checked);

    void on_pushButton_5_clicked(bool checked);

    void on_pushButton_6_clicked(bool checked);

    void on_pushButton_7_clicked(bool checked);

    void on_pushButton_8_clicked(bool checked);

    void on_pushButton_9_clicked(bool checked);

    void on_pushButton_point_clicked(bool checked);

    void on_pushButton_plus_clicked(bool checked);

    void on_pushButton_minus_clicked(bool checked);

    void on_pushButton_multi_clicked(bool checked);

    void on_pushButton_devide_clicked(bool checked);

    void on_pushButton_left_clicked(bool checked);

    void on_pushButton_right_clicked(bool checked);

    void on_pushButton_AC_clicked(bool checked);

    void on_pushButton_Back_clicked(bool checked);

    void on_pushButton_equal_clicked(bool checked);

private:
    Ui::Dialog *ui;
    QString s_input;
    QString s_output;
    void moveCursur();
    int cursur;
    QString getResult(QString &expression_);
};

#endif // DIALOG_H
