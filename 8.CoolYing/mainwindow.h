#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>

namespace Ui {
class MainWindow;
}

class QAction;
class QMenu;
class QMediaPlayer;
class QMediaPlaylist;
class QSystemTrayIcon;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void positionChanged(qint64);
    void durationChanged(qint64);
    void playTo(int, int);
    void updateSongList(int);

    void showOrHideSongList();
    void importSongs();
    void playLast();
    void playOrPause();
    void playNext();

    void plusSound();
    void reduceSound();

    void setPlaybackMode1();
    void setPlaybackMode2();
    void setPlaybackMode3();
    void setPlaybackMode4();

    void support();
    void aboutUs();

    void setPosition(int);

    void iconActivated(QSystemTrayIcon::ActivationReason reason);

protected:
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void closeEvent(QCloseEvent *);
    
private:
    void createContextMenu();
    void createSystemTrayIcon();

    Ui::MainWindow *ui;

    QPoint dragPos;
    int volume;

    QAction *restoreAction;
    QAction *quitAction;
    QAction *seperatorAction1;
    QAction *seperatorAction2;
    QAction *seperatorAction3;
    QAction *seperatorAction4;
    QAction *seperatorAction5;

    QMenu *trayContextMenu;

    QMediaPlayer *player;
    QMediaPlaylist *playList;
    QSystemTrayIcon *trayIcon;
};

#endif // MAINWINDOW_H
