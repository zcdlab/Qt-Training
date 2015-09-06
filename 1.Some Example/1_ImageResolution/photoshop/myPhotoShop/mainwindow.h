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
    
private slots:

    void on_openPicture_triggered();

    void on_drawHistogram_triggered();

    void paintEvent(QPaintEvent *);

    void on_reSize_triggered();

    void on_actionManual_triggered();

    void resizeConfirm(int x, int y, bool a, bool b, bool c);

    QRgb nearest(QImage image, qreal x, qreal y);

    QRgb bilinear(QImage image, qreal x, qreal y);

    QRgb bicubic(QImage image, qreal x, qreal y);

    void matrixConfirm(double a1,double a2,double a3,double b1,double b2,double b3,double c1,double c2,double c3);

    void vertexConfirm(int x1,int x2,int y1,int y2,int r,int g,int b);

    void gaussConfirm(double x, int N);

    void newPicConfirm(int x, int y);

    void grayDilationConfirm(int elements[]);

    void grayErosionConfirm(int elements[]);

    void grayOpenConfirm(int elements[]);

    void grayCloseConfirm(int elements[]);

    void binaryDilationConfirm(int elements[]);

    void binaryErosionConfirm(int elements[]);

    void binaryOpenConfirm(int elements[]);

    void binaryCloseConfirm(int elements[]);

    void paintTwo(int threshold);

    void on_actionOtsu_triggered();

    void updateGrayValue();

    int otsuReturn();

    int entropyReturn();

    void on_actionEntropy_triggered();

    void setMatrix(double a1, double a2, double a3, double b1, double b2, double b3, double c1, double c2, double c3);

    void getGrayPicture(int N);

    void getGrayTable();

    void getGrayTableN(int N);

    void getRGBTable();

    void getRGBTableN(int N);

    void getGrayDilation(int elements[], int N);

    void getDilation(int elements[], int N);

    void getGrayErosion(int elements[], int N);

    void getErosion(int elements[], int N);

    int maxGrayNumber(int element[], int pixel[]);

    int minGrayNumber(int element[], int pixel[]);

    int maxNumber(int element[], int pixel[]);

    int minNumber(int element[], int pixel[]);

    void multiplyGrayTable( bool flag );

    void multiplyRGBTable( bool flag );

    void multiplyRGBTableN( int N, bool flag );

    void paintOverGrayConvolution();

    void paintOverRGBConvolution();

    void on_actionMedian_filter_triggered();

    void makeMedianTable();

    double medianValue(double a1, double a2, double a3, double b1, double b2, double b3, double c1, double c2, double c3);

    void on_matrixBySelf_triggered();

    void on_actionMean_filter_triggered();

    void on_newPicture_triggered();

    void on_action_add_triggered();

    void on_action_minus_triggered();

    void on_action_multiply_triggered();

    void on_action_openPicture2_triggered();

    void on_action_vertex_triggered();

    void on_actionGaussian_filter_triggered();

    void on_Roberts_x_triggered();

    void on_Roberts_y_triggered();

    void on_prewitt_x_triggered();

    void on_prewitt_y_triggered();

    void on_sobel_x_triggered();

    void on_sobel_y_triggered();

    void on_makeDone_clicked();

    void on_Roberts_RGB_x_triggered();

    void on_Roberts_RGB_y_triggered();

    void on_prewitt_RGB_x_triggered();

    void on_prewitt_RGB_y_triggered();

    void on_sobel_RGB_x_triggered();

    void on_sobel_RGB_y_triggered();

    void on_actionTest_triggered();

    void timerUpDate();

    void on_clockwise_triggered();

    void on_anticlockwise_triggered();

    void on_grayDilation_triggered();

    void on_binaryDilation_triggered();

    void on_grayErosion_triggered();

    void on_binaryErosion_triggered();

    void on_grayOpen_triggered();

    void on_binaryOpen_triggered();

    void on_grayClose_triggered();

    void on_binaryClose_triggered();

private:
    Ui::MainWindow *ui;
    bool havePic1;
    bool havePic2;
    int grayValue[256];
    double wValue[256];
    int *rTable;
    int *gTable;
    int *bTable;
    int *grayTable;
    int *resultRTable;
    int *resultGTable;
    int *resultBTable;
    int *resultGrayTable;
    int width;
    int height;
    int totalPixel;
    double matrix[3][3];
    double *matrixTable;
    double testTime;
};

#endif // MAINWINDOW_H
