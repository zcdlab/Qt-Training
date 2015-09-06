#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void createEvent();


private slots:
    void openFile();

private:
    Ui::MainWindow *ui;
    QString imagePath;
};

#endif // MAINWINDOW_H
