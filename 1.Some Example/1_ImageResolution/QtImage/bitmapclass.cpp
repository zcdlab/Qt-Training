#include "bitmapclass.h"

BitmapClass::BitmapClass(QString File)
{

}

quint32 BitmapClass::DWORDtoQuint32(DWORD n)
{
    quint32 r = 0x00000000, temp = 0x00000000;
    temp = n >> 24; //取出第一个字节
    r = r + temp;
    temp = (n & (0x00ff0000)) >> 8; //取出第二个字节
    r = r + temp;
    temp = (n & (0x0000ff00)) << 8; //取出第三个字节
    r = r + temp;
    temp = (n & (0x000000ff)) << 24; //取出第四个字节
    r = r + temp;
    return r;
}

quint16 BitmapClass::WORDtoQuint16(WORD n)
{
    quint32 r = 0x00000000, temp = 0x00000000;
    temp = n >> 8; //取出第一个字节
    r = r + temp;
    return r;
}

qint32 BitmapClass::LONGtoQint32(LONG n)
{
    qint32 r = 0x00000000, temp = 0x00000000;
    temp = n >> 24; //取出第一个字节
    temp = temp & 0x000000ff; //为了实现逻辑右移
    r = r + temp;
    temp = (n & (0x00ff0000)) >> 8; //取出第二个字节
    temp = temp & 0x00ffffff; //实现右移的逻辑化
    r = r + temp;
    temp = (n & (0x0000ff00)) << 8; //取出第三个字节
    r = r + temp;
    temp = (n & (0x000000ff)) << 24; //取出第四个字节
    r = r + temp;
    return r;
}


QString BitmapClass::ReadBitmapFile(QString filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly))
    {
        return "File can not be opened!";
    }
    else
    {
        QDataStream in(&file); //创建输入流
        in.setVersion(QDataStream::Qt_4_6);

        /*开始读取文件头信息*/
        /*===================================*/
        in >> BitMapFileHeader.bfType; //读取文件类型
        in >> BitMapFileHeader.bfSize; //读取文件大小
        in >> BitMapFileHeader.bfReserved1; //读取两个保留字
        in >> BitMapFileHeader.bfReserved2;
        in >> BitMapFileHeader.bfOffBits; //读取偏移量
        /*===================================*/
        /**文件头信息读取结束*/

        /*开始读取位图信息头*/
        /*====================================*/
        in >> BitMapInfoHeader.biSize;
        in >> BitMapInfoHeader.biWidth;
        in >> BitMapInfoHeader.biHeight;
        in >> BitMapInfoHeader.biPlanes;
        in >> BitMapInfoHeader.biBitCount;
        in >> BitMapInfoHeader.biCompression;
        in >> BitMapInfoHeader.biSizeImage;
        in >> BitMapInfoHeader.biXPelsPerMeter;
        in >> BitMapInfoHeader.biYPelsPerMeter;
        in >> BitMapInfoHeader.biClrUsed;
        in >> BitMapInfoHeader.biClrImportant;
        /*====================================*/
        /*位图信息头读取结束*/

        /*开始读取颜色表*/
        /*====================================*/
        //获得图像的颜色位数
        format = WORDtoQuint16(BitMapInfoHeader.biBitCount);
        if (format == 1) //对于黑白图
        {
            pColorTable = new RGBQUAD[2];
            //读入颜色表
            for (int i = 0; i < 2; i++)
            {
                in >> pColorTable[i].rgbBlue;
                in >> pColorTable[i].rgbGreen;
                in >> pColorTable[i].rgbRed;
                in >> pColorTable[i].rgbReserved;
            }
        }
        if (format == 8) //对于灰度图，共有256种颜色
        {
            pColorTable = new RGBQUAD[256];
            //读入颜色表
            for (int i = 0; i < 256; i++)
            {
                in >> pColorTable[i].rgbBlue;
                in >> pColorTable[i].rgbGreen;
                in >> pColorTable[i].rgbRed;
                in >> pColorTable[i].rgbReserved;
            }
        }
        //24位真彩色图没有颜色表
        /*====================================*/
        /*颜色表读取结束*/

        /*开始读取位图数据*/
        /*====================================*/

        //求得图像数据的字节数
        quint32 length = DWORDtoQuint32(BitMapFileHeader.bfSize)- DWORDtoQuint32(BitMapFileHeader.bfOffBits);
        bmpData = new BYTE[length];
        for (quint32 i = 0; i < length; i++)
        {
            in >> bmpData[i];
        }
        /*====================================*/
        /*位图数据读取结束*/

        fileSize = DWORDtoQuint32(BitMapFileHeader.bfSize);
        bitCount = WORDtoQuint16(BitMapInfoHeader.biBitCount);
        dataSize = DWORDtoQuint32(BitMapFileHeader.bfSize)- DWORDtoQuint32(BitMapFileHeader.bfOffBits);
        width = LONGtoQint32(BitMapInfoHeader.biWidth);
        height = LONGtoQint32(BitMapInfoHeader.biHeight);
        flag = true;

    }
    file.close();
    return "Success";
}
