#ifndef PASSWORD_H
#define PASSWORD_H

#include <QDialog>

namespace Ui {
class password;
}

class password : public QDialog
{
    Q_OBJECT

public:
    explicit password(QWidget *parent = 0);
    ~password();

private slots:
    void on_pushButton_passWord_clicked();

private:
    Ui::password *ui;


public:
    QString passWord;
};

#endif // PASSWORD_H
