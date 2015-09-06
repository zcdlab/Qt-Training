/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../myPhotoShop/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[115];
    char stringdata[1786];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 24), // "on_openPicture_triggered"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 26), // "on_drawHistogram_triggered"
QT_MOC_LITERAL(4, 64, 10), // "paintEvent"
QT_MOC_LITERAL(5, 75, 12), // "QPaintEvent*"
QT_MOC_LITERAL(6, 88, 19), // "on_reSize_triggered"
QT_MOC_LITERAL(7, 108, 25), // "on_actionManual_triggered"
QT_MOC_LITERAL(8, 134, 13), // "resizeConfirm"
QT_MOC_LITERAL(9, 148, 1), // "x"
QT_MOC_LITERAL(10, 150, 1), // "y"
QT_MOC_LITERAL(11, 152, 1), // "a"
QT_MOC_LITERAL(12, 154, 1), // "b"
QT_MOC_LITERAL(13, 156, 1), // "c"
QT_MOC_LITERAL(14, 158, 7), // "nearest"
QT_MOC_LITERAL(15, 166, 4), // "QRgb"
QT_MOC_LITERAL(16, 171, 5), // "image"
QT_MOC_LITERAL(17, 177, 8), // "bilinear"
QT_MOC_LITERAL(18, 186, 7), // "bicubic"
QT_MOC_LITERAL(19, 194, 13), // "matrixConfirm"
QT_MOC_LITERAL(20, 208, 2), // "a1"
QT_MOC_LITERAL(21, 211, 2), // "a2"
QT_MOC_LITERAL(22, 214, 2), // "a3"
QT_MOC_LITERAL(23, 217, 2), // "b1"
QT_MOC_LITERAL(24, 220, 2), // "b2"
QT_MOC_LITERAL(25, 223, 2), // "b3"
QT_MOC_LITERAL(26, 226, 2), // "c1"
QT_MOC_LITERAL(27, 229, 2), // "c2"
QT_MOC_LITERAL(28, 232, 2), // "c3"
QT_MOC_LITERAL(29, 235, 13), // "vertexConfirm"
QT_MOC_LITERAL(30, 249, 2), // "x1"
QT_MOC_LITERAL(31, 252, 2), // "x2"
QT_MOC_LITERAL(32, 255, 2), // "y1"
QT_MOC_LITERAL(33, 258, 2), // "y2"
QT_MOC_LITERAL(34, 261, 1), // "r"
QT_MOC_LITERAL(35, 263, 1), // "g"
QT_MOC_LITERAL(36, 265, 12), // "gaussConfirm"
QT_MOC_LITERAL(37, 278, 1), // "N"
QT_MOC_LITERAL(38, 280, 13), // "newPicConfirm"
QT_MOC_LITERAL(39, 294, 19), // "grayDilationConfirm"
QT_MOC_LITERAL(40, 314, 5), // "int[]"
QT_MOC_LITERAL(41, 320, 8), // "elements"
QT_MOC_LITERAL(42, 329, 18), // "grayErosionConfirm"
QT_MOC_LITERAL(43, 348, 15), // "grayOpenConfirm"
QT_MOC_LITERAL(44, 364, 16), // "grayCloseConfirm"
QT_MOC_LITERAL(45, 381, 21), // "binaryDilationConfirm"
QT_MOC_LITERAL(46, 403, 20), // "binaryErosionConfirm"
QT_MOC_LITERAL(47, 424, 17), // "binaryOpenConfirm"
QT_MOC_LITERAL(48, 442, 18), // "binaryCloseConfirm"
QT_MOC_LITERAL(49, 461, 8), // "paintTwo"
QT_MOC_LITERAL(50, 470, 9), // "threshold"
QT_MOC_LITERAL(51, 480, 23), // "on_actionOtsu_triggered"
QT_MOC_LITERAL(52, 504, 15), // "updateGrayValue"
QT_MOC_LITERAL(53, 520, 10), // "otsuReturn"
QT_MOC_LITERAL(54, 531, 13), // "entropyReturn"
QT_MOC_LITERAL(55, 545, 26), // "on_actionEntropy_triggered"
QT_MOC_LITERAL(56, 572, 9), // "setMatrix"
QT_MOC_LITERAL(57, 582, 14), // "getGrayPicture"
QT_MOC_LITERAL(58, 597, 12), // "getGrayTable"
QT_MOC_LITERAL(59, 610, 13), // "getGrayTableN"
QT_MOC_LITERAL(60, 624, 11), // "getRGBTable"
QT_MOC_LITERAL(61, 636, 12), // "getRGBTableN"
QT_MOC_LITERAL(62, 649, 15), // "getGrayDilation"
QT_MOC_LITERAL(63, 665, 11), // "getDilation"
QT_MOC_LITERAL(64, 677, 14), // "getGrayErosion"
QT_MOC_LITERAL(65, 692, 10), // "getErosion"
QT_MOC_LITERAL(66, 703, 13), // "maxGrayNumber"
QT_MOC_LITERAL(67, 717, 7), // "element"
QT_MOC_LITERAL(68, 725, 5), // "pixel"
QT_MOC_LITERAL(69, 731, 13), // "minGrayNumber"
QT_MOC_LITERAL(70, 745, 9), // "maxNumber"
QT_MOC_LITERAL(71, 755, 9), // "minNumber"
QT_MOC_LITERAL(72, 765, 17), // "multiplyGrayTable"
QT_MOC_LITERAL(73, 783, 4), // "flag"
QT_MOC_LITERAL(74, 788, 16), // "multiplyRGBTable"
QT_MOC_LITERAL(75, 805, 17), // "multiplyRGBTableN"
QT_MOC_LITERAL(76, 823, 24), // "paintOverGrayConvolution"
QT_MOC_LITERAL(77, 848, 23), // "paintOverRGBConvolution"
QT_MOC_LITERAL(78, 872, 32), // "on_actionMedian_filter_triggered"
QT_MOC_LITERAL(79, 905, 15), // "makeMedianTable"
QT_MOC_LITERAL(80, 921, 11), // "medianValue"
QT_MOC_LITERAL(81, 933, 25), // "on_matrixBySelf_triggered"
QT_MOC_LITERAL(82, 959, 30), // "on_actionMean_filter_triggered"
QT_MOC_LITERAL(83, 990, 23), // "on_newPicture_triggered"
QT_MOC_LITERAL(84, 1014, 23), // "on_action_add_triggered"
QT_MOC_LITERAL(85, 1038, 25), // "on_action_minus_triggered"
QT_MOC_LITERAL(86, 1064, 28), // "on_action_multiply_triggered"
QT_MOC_LITERAL(87, 1093, 32), // "on_action_openPicture2_triggered"
QT_MOC_LITERAL(88, 1126, 26), // "on_action_vertex_triggered"
QT_MOC_LITERAL(89, 1153, 34), // "on_actionGaussian_filter_trig..."
QT_MOC_LITERAL(90, 1188, 22), // "on_Roberts_x_triggered"
QT_MOC_LITERAL(91, 1211, 22), // "on_Roberts_y_triggered"
QT_MOC_LITERAL(92, 1234, 22), // "on_prewitt_x_triggered"
QT_MOC_LITERAL(93, 1257, 22), // "on_prewitt_y_triggered"
QT_MOC_LITERAL(94, 1280, 20), // "on_sobel_x_triggered"
QT_MOC_LITERAL(95, 1301, 20), // "on_sobel_y_triggered"
QT_MOC_LITERAL(96, 1322, 19), // "on_makeDone_clicked"
QT_MOC_LITERAL(97, 1342, 26), // "on_Roberts_RGB_x_triggered"
QT_MOC_LITERAL(98, 1369, 26), // "on_Roberts_RGB_y_triggered"
QT_MOC_LITERAL(99, 1396, 26), // "on_prewitt_RGB_x_triggered"
QT_MOC_LITERAL(100, 1423, 26), // "on_prewitt_RGB_y_triggered"
QT_MOC_LITERAL(101, 1450, 24), // "on_sobel_RGB_x_triggered"
QT_MOC_LITERAL(102, 1475, 24), // "on_sobel_RGB_y_triggered"
QT_MOC_LITERAL(103, 1500, 23), // "on_actionTest_triggered"
QT_MOC_LITERAL(104, 1524, 11), // "timerUpDate"
QT_MOC_LITERAL(105, 1536, 22), // "on_clockwise_triggered"
QT_MOC_LITERAL(106, 1559, 26), // "on_anticlockwise_triggered"
QT_MOC_LITERAL(107, 1586, 25), // "on_grayDilation_triggered"
QT_MOC_LITERAL(108, 1612, 27), // "on_binaryDilation_triggered"
QT_MOC_LITERAL(109, 1640, 24), // "on_grayErosion_triggered"
QT_MOC_LITERAL(110, 1665, 26), // "on_binaryErosion_triggered"
QT_MOC_LITERAL(111, 1692, 21), // "on_grayOpen_triggered"
QT_MOC_LITERAL(112, 1714, 23), // "on_binaryOpen_triggered"
QT_MOC_LITERAL(113, 1738, 22), // "on_grayClose_triggered"
QT_MOC_LITERAL(114, 1761, 24) // "on_binaryClose_triggered"

    },
    "MainWindow\0on_openPicture_triggered\0"
    "\0on_drawHistogram_triggered\0paintEvent\0"
    "QPaintEvent*\0on_reSize_triggered\0"
    "on_actionManual_triggered\0resizeConfirm\0"
    "x\0y\0a\0b\0c\0nearest\0QRgb\0image\0bilinear\0"
    "bicubic\0matrixConfirm\0a1\0a2\0a3\0b1\0b2\0"
    "b3\0c1\0c2\0c3\0vertexConfirm\0x1\0x2\0y1\0"
    "y2\0r\0g\0gaussConfirm\0N\0newPicConfirm\0"
    "grayDilationConfirm\0int[]\0elements\0"
    "grayErosionConfirm\0grayOpenConfirm\0"
    "grayCloseConfirm\0binaryDilationConfirm\0"
    "binaryErosionConfirm\0binaryOpenConfirm\0"
    "binaryCloseConfirm\0paintTwo\0threshold\0"
    "on_actionOtsu_triggered\0updateGrayValue\0"
    "otsuReturn\0entropyReturn\0"
    "on_actionEntropy_triggered\0setMatrix\0"
    "getGrayPicture\0getGrayTable\0getGrayTableN\0"
    "getRGBTable\0getRGBTableN\0getGrayDilation\0"
    "getDilation\0getGrayErosion\0getErosion\0"
    "maxGrayNumber\0element\0pixel\0minGrayNumber\0"
    "maxNumber\0minNumber\0multiplyGrayTable\0"
    "flag\0multiplyRGBTable\0multiplyRGBTableN\0"
    "paintOverGrayConvolution\0"
    "paintOverRGBConvolution\0"
    "on_actionMedian_filter_triggered\0"
    "makeMedianTable\0medianValue\0"
    "on_matrixBySelf_triggered\0"
    "on_actionMean_filter_triggered\0"
    "on_newPicture_triggered\0on_action_add_triggered\0"
    "on_action_minus_triggered\0"
    "on_action_multiply_triggered\0"
    "on_action_openPicture2_triggered\0"
    "on_action_vertex_triggered\0"
    "on_actionGaussian_filter_triggered\0"
    "on_Roberts_x_triggered\0on_Roberts_y_triggered\0"
    "on_prewitt_x_triggered\0on_prewitt_y_triggered\0"
    "on_sobel_x_triggered\0on_sobel_y_triggered\0"
    "on_makeDone_clicked\0on_Roberts_RGB_x_triggered\0"
    "on_Roberts_RGB_y_triggered\0"
    "on_prewitt_RGB_x_triggered\0"
    "on_prewitt_RGB_y_triggered\0"
    "on_sobel_RGB_x_triggered\0"
    "on_sobel_RGB_y_triggered\0"
    "on_actionTest_triggered\0timerUpDate\0"
    "on_clockwise_triggered\0"
    "on_anticlockwise_triggered\0"
    "on_grayDilation_triggered\0"
    "on_binaryDilation_triggered\0"
    "on_grayErosion_triggered\0"
    "on_binaryErosion_triggered\0"
    "on_grayOpen_triggered\0on_binaryOpen_triggered\0"
    "on_grayClose_triggered\0on_binaryClose_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      83,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  429,    2, 0x08 /* Private */,
       3,    0,  430,    2, 0x08 /* Private */,
       4,    1,  431,    2, 0x08 /* Private */,
       6,    0,  434,    2, 0x08 /* Private */,
       7,    0,  435,    2, 0x08 /* Private */,
       8,    5,  436,    2, 0x08 /* Private */,
      14,    3,  447,    2, 0x08 /* Private */,
      17,    3,  454,    2, 0x08 /* Private */,
      18,    3,  461,    2, 0x08 /* Private */,
      19,    9,  468,    2, 0x08 /* Private */,
      29,    7,  487,    2, 0x08 /* Private */,
      36,    2,  502,    2, 0x08 /* Private */,
      38,    2,  507,    2, 0x08 /* Private */,
      39,    1,  512,    2, 0x08 /* Private */,
      42,    1,  515,    2, 0x08 /* Private */,
      43,    1,  518,    2, 0x08 /* Private */,
      44,    1,  521,    2, 0x08 /* Private */,
      45,    1,  524,    2, 0x08 /* Private */,
      46,    1,  527,    2, 0x08 /* Private */,
      47,    1,  530,    2, 0x08 /* Private */,
      48,    1,  533,    2, 0x08 /* Private */,
      49,    1,  536,    2, 0x08 /* Private */,
      51,    0,  539,    2, 0x08 /* Private */,
      52,    0,  540,    2, 0x08 /* Private */,
      53,    0,  541,    2, 0x08 /* Private */,
      54,    0,  542,    2, 0x08 /* Private */,
      55,    0,  543,    2, 0x08 /* Private */,
      56,    9,  544,    2, 0x08 /* Private */,
      57,    1,  563,    2, 0x08 /* Private */,
      58,    0,  566,    2, 0x08 /* Private */,
      59,    1,  567,    2, 0x08 /* Private */,
      60,    0,  570,    2, 0x08 /* Private */,
      61,    1,  571,    2, 0x08 /* Private */,
      62,    2,  574,    2, 0x08 /* Private */,
      63,    2,  579,    2, 0x08 /* Private */,
      64,    2,  584,    2, 0x08 /* Private */,
      65,    2,  589,    2, 0x08 /* Private */,
      66,    2,  594,    2, 0x08 /* Private */,
      69,    2,  599,    2, 0x08 /* Private */,
      70,    2,  604,    2, 0x08 /* Private */,
      71,    2,  609,    2, 0x08 /* Private */,
      72,    1,  614,    2, 0x08 /* Private */,
      74,    1,  617,    2, 0x08 /* Private */,
      75,    2,  620,    2, 0x08 /* Private */,
      76,    0,  625,    2, 0x08 /* Private */,
      77,    0,  626,    2, 0x08 /* Private */,
      78,    0,  627,    2, 0x08 /* Private */,
      79,    0,  628,    2, 0x08 /* Private */,
      80,    9,  629,    2, 0x08 /* Private */,
      81,    0,  648,    2, 0x08 /* Private */,
      82,    0,  649,    2, 0x08 /* Private */,
      83,    0,  650,    2, 0x08 /* Private */,
      84,    0,  651,    2, 0x08 /* Private */,
      85,    0,  652,    2, 0x08 /* Private */,
      86,    0,  653,    2, 0x08 /* Private */,
      87,    0,  654,    2, 0x08 /* Private */,
      88,    0,  655,    2, 0x08 /* Private */,
      89,    0,  656,    2, 0x08 /* Private */,
      90,    0,  657,    2, 0x08 /* Private */,
      91,    0,  658,    2, 0x08 /* Private */,
      92,    0,  659,    2, 0x08 /* Private */,
      93,    0,  660,    2, 0x08 /* Private */,
      94,    0,  661,    2, 0x08 /* Private */,
      95,    0,  662,    2, 0x08 /* Private */,
      96,    0,  663,    2, 0x08 /* Private */,
      97,    0,  664,    2, 0x08 /* Private */,
      98,    0,  665,    2, 0x08 /* Private */,
      99,    0,  666,    2, 0x08 /* Private */,
     100,    0,  667,    2, 0x08 /* Private */,
     101,    0,  668,    2, 0x08 /* Private */,
     102,    0,  669,    2, 0x08 /* Private */,
     103,    0,  670,    2, 0x08 /* Private */,
     104,    0,  671,    2, 0x08 /* Private */,
     105,    0,  672,    2, 0x08 /* Private */,
     106,    0,  673,    2, 0x08 /* Private */,
     107,    0,  674,    2, 0x08 /* Private */,
     108,    0,  675,    2, 0x08 /* Private */,
     109,    0,  676,    2, 0x08 /* Private */,
     110,    0,  677,    2, 0x08 /* Private */,
     111,    0,  678,    2, 0x08 /* Private */,
     112,    0,  679,    2, 0x08 /* Private */,
     113,    0,  680,    2, 0x08 /* Private */,
     114,    0,  681,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool,    9,   10,   11,   12,   13,
    0x80000000 | 15, QMetaType::QImage, QMetaType::QReal, QMetaType::QReal,   16,    9,   10,
    0x80000000 | 15, QMetaType::QImage, QMetaType::QReal, QMetaType::QReal,   16,    9,   10,
    0x80000000 | 15, QMetaType::QImage, QMetaType::QReal, QMetaType::QReal,   16,    9,   10,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double,   20,   21,   22,   23,   24,   25,   26,   27,   28,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   30,   31,   32,   33,   34,   35,   12,
    QMetaType::Void, QMetaType::Double, QMetaType::Int,    9,   37,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    9,   10,
    QMetaType::Void, 0x80000000 | 40,   41,
    QMetaType::Void, 0x80000000 | 40,   41,
    QMetaType::Void, 0x80000000 | 40,   41,
    QMetaType::Void, 0x80000000 | 40,   41,
    QMetaType::Void, 0x80000000 | 40,   41,
    QMetaType::Void, 0x80000000 | 40,   41,
    QMetaType::Void, 0x80000000 | 40,   41,
    QMetaType::Void, 0x80000000 | 40,   41,
    QMetaType::Void, QMetaType::Int,   50,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double,   20,   21,   22,   23,   24,   25,   26,   27,   28,
    QMetaType::Void, QMetaType::Int,   37,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   37,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   37,
    QMetaType::Void, 0x80000000 | 40, QMetaType::Int,   41,   37,
    QMetaType::Void, 0x80000000 | 40, QMetaType::Int,   41,   37,
    QMetaType::Void, 0x80000000 | 40, QMetaType::Int,   41,   37,
    QMetaType::Void, 0x80000000 | 40, QMetaType::Int,   41,   37,
    QMetaType::Int, 0x80000000 | 40, 0x80000000 | 40,   67,   68,
    QMetaType::Int, 0x80000000 | 40, 0x80000000 | 40,   67,   68,
    QMetaType::Int, 0x80000000 | 40, 0x80000000 | 40,   67,   68,
    QMetaType::Int, 0x80000000 | 40, 0x80000000 | 40,   67,   68,
    QMetaType::Void, QMetaType::Bool,   73,
    QMetaType::Void, QMetaType::Bool,   73,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   37,   73,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double,   20,   21,   22,   23,   24,   25,   26,   27,   28,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->on_openPicture_triggered(); break;
        case 1: _t->on_drawHistogram_triggered(); break;
        case 2: _t->paintEvent((*reinterpret_cast< QPaintEvent*(*)>(_a[1]))); break;
        case 3: _t->on_reSize_triggered(); break;
        case 4: _t->on_actionManual_triggered(); break;
        case 5: _t->resizeConfirm((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        case 6: { QRgb _r = _t->nearest((*reinterpret_cast< QImage(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QRgb*>(_a[0]) = _r; }  break;
        case 7: { QRgb _r = _t->bilinear((*reinterpret_cast< QImage(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QRgb*>(_a[0]) = _r; }  break;
        case 8: { QRgb _r = _t->bicubic((*reinterpret_cast< QImage(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QRgb*>(_a[0]) = _r; }  break;
        case 9: _t->matrixConfirm((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< double(*)>(_a[6])),(*reinterpret_cast< double(*)>(_a[7])),(*reinterpret_cast< double(*)>(_a[8])),(*reinterpret_cast< double(*)>(_a[9]))); break;
        case 10: _t->vertexConfirm((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7]))); break;
        case 11: _t->gaussConfirm((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 12: _t->newPicConfirm((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 13: _t->grayDilationConfirm((*reinterpret_cast< int(*)[]>(_a[1]))); break;
        case 14: _t->grayErosionConfirm((*reinterpret_cast< int(*)[]>(_a[1]))); break;
        case 15: _t->grayOpenConfirm((*reinterpret_cast< int(*)[]>(_a[1]))); break;
        case 16: _t->grayCloseConfirm((*reinterpret_cast< int(*)[]>(_a[1]))); break;
        case 17: _t->binaryDilationConfirm((*reinterpret_cast< int(*)[]>(_a[1]))); break;
        case 18: _t->binaryErosionConfirm((*reinterpret_cast< int(*)[]>(_a[1]))); break;
        case 19: _t->binaryOpenConfirm((*reinterpret_cast< int(*)[]>(_a[1]))); break;
        case 20: _t->binaryCloseConfirm((*reinterpret_cast< int(*)[]>(_a[1]))); break;
        case 21: _t->paintTwo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->on_actionOtsu_triggered(); break;
        case 23: _t->updateGrayValue(); break;
        case 24: { int _r = _t->otsuReturn();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 25: { int _r = _t->entropyReturn();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 26: _t->on_actionEntropy_triggered(); break;
        case 27: _t->setMatrix((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< double(*)>(_a[6])),(*reinterpret_cast< double(*)>(_a[7])),(*reinterpret_cast< double(*)>(_a[8])),(*reinterpret_cast< double(*)>(_a[9]))); break;
        case 28: _t->getGrayPicture((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 29: _t->getGrayTable(); break;
        case 30: _t->getGrayTableN((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 31: _t->getRGBTable(); break;
        case 32: _t->getRGBTableN((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 33: _t->getGrayDilation((*reinterpret_cast< int(*)[]>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 34: _t->getDilation((*reinterpret_cast< int(*)[]>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 35: _t->getGrayErosion((*reinterpret_cast< int(*)[]>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 36: _t->getErosion((*reinterpret_cast< int(*)[]>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 37: { int _r = _t->maxGrayNumber((*reinterpret_cast< int(*)[]>(_a[1])),(*reinterpret_cast< int(*)[]>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 38: { int _r = _t->minGrayNumber((*reinterpret_cast< int(*)[]>(_a[1])),(*reinterpret_cast< int(*)[]>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 39: { int _r = _t->maxNumber((*reinterpret_cast< int(*)[]>(_a[1])),(*reinterpret_cast< int(*)[]>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 40: { int _r = _t->minNumber((*reinterpret_cast< int(*)[]>(_a[1])),(*reinterpret_cast< int(*)[]>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 41: _t->multiplyGrayTable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 42: _t->multiplyRGBTable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 43: _t->multiplyRGBTableN((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 44: _t->paintOverGrayConvolution(); break;
        case 45: _t->paintOverRGBConvolution(); break;
        case 46: _t->on_actionMedian_filter_triggered(); break;
        case 47: _t->makeMedianTable(); break;
        case 48: { double _r = _t->medianValue((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< double(*)>(_a[6])),(*reinterpret_cast< double(*)>(_a[7])),(*reinterpret_cast< double(*)>(_a[8])),(*reinterpret_cast< double(*)>(_a[9])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 49: _t->on_matrixBySelf_triggered(); break;
        case 50: _t->on_actionMean_filter_triggered(); break;
        case 51: _t->on_newPicture_triggered(); break;
        case 52: _t->on_action_add_triggered(); break;
        case 53: _t->on_action_minus_triggered(); break;
        case 54: _t->on_action_multiply_triggered(); break;
        case 55: _t->on_action_openPicture2_triggered(); break;
        case 56: _t->on_action_vertex_triggered(); break;
        case 57: _t->on_actionGaussian_filter_triggered(); break;
        case 58: _t->on_Roberts_x_triggered(); break;
        case 59: _t->on_Roberts_y_triggered(); break;
        case 60: _t->on_prewitt_x_triggered(); break;
        case 61: _t->on_prewitt_y_triggered(); break;
        case 62: _t->on_sobel_x_triggered(); break;
        case 63: _t->on_sobel_y_triggered(); break;
        case 64: _t->on_makeDone_clicked(); break;
        case 65: _t->on_Roberts_RGB_x_triggered(); break;
        case 66: _t->on_Roberts_RGB_y_triggered(); break;
        case 67: _t->on_prewitt_RGB_x_triggered(); break;
        case 68: _t->on_prewitt_RGB_y_triggered(); break;
        case 69: _t->on_sobel_RGB_x_triggered(); break;
        case 70: _t->on_sobel_RGB_y_triggered(); break;
        case 71: _t->on_actionTest_triggered(); break;
        case 72: _t->timerUpDate(); break;
        case 73: _t->on_clockwise_triggered(); break;
        case 74: _t->on_anticlockwise_triggered(); break;
        case 75: _t->on_grayDilation_triggered(); break;
        case 76: _t->on_binaryDilation_triggered(); break;
        case 77: _t->on_grayErosion_triggered(); break;
        case 78: _t->on_binaryErosion_triggered(); break;
        case 79: _t->on_grayOpen_triggered(); break;
        case 80: _t->on_binaryOpen_triggered(); break;
        case 81: _t->on_grayClose_triggered(); break;
        case 82: _t->on_binaryClose_triggered(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 83)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 83;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 83)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 83;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
