#include <QCoreApplication>
#include <QDebug>

/*在类中实现事件*/
class CLoad;
typedef void (*TEvent)(CLoad* e);
typedef void (*Tevent)(CLoad* e);
class CLoad
{
private:
    char filename[10];

public:
    TEvent OnLoad;
    Tevent OffLoad;
    void Load(char* FileName)
    {
        strcpy(filename,FileName);
        qDebug()<<"insider"<<endl;
        if(OnLoad!=NULL)
            OnLoad(this);
        if(OffLoad!=NULL)
            OffLoad(this);
    }

    char* GetFileName()
    {
        return filename;
    }

};
void OnLoad(CLoad* e)
{
    qDebug()<<"OutSider OnLoad!"<<e->GetFileName()<<endl;
}
void OffLoad(CLoad* e)
{
    qDebug()<<"OutSider OffLoad!"<<e->GetFileName()<<"For different!"<<endl;
}





namespace ns1
{
const int Up=1;
const int Down=2;
const int Left=3;
const int Right=4;
}
namespace ns2
{
const char* Up="上";
const char* Down="下";
const char* Left="左";
const char* Right="右";
}

namespace ns3
{
const char* Up="↑";
const char* Down="↓";
const char* Left="←";
const char* Right="→";
}



using namespace ns3;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    /*在类中实现事件->bug
    CLoad cl;
    cl.OnLoad=OnLoad;
    cl.OffLoad=OffLoad;

    cl.Load("c:\\123.txt");
    */
    qDebug()<<Up<<" "<<Down<<" "<<Left<<" "<<Right<<" "<<endl;
    qDebug()<<ns1::Up<<" "<<ns2::Down<<" "<<ns3::Left<<" "<<Right<<" "<<endl;


    return a.exec();
}
