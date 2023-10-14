#include "application.h"
#include "../ConnectionClass/common.h"
#include "matrix.h"

TApplication::TApplication(int argc, char *argv[])
            : QCoreApplication(argc,argv)
{
    TCommParams pars = { QHostAddress("127.0.0.1"), 10000,
                         QHostAddress("127.0.0.1"), 10001};
    comm = new TCommunicator(pars, this);

    connect(comm,SIGNAL(recieved(QByteArray)),this,SLOT(recieve(QByteArray)));
}

void TApplication::recieve(QByteArray msg)
{
    QString answer;
    QString req = QString(msg);
    char ch_class = req[req.length()-1].toLatin1();
    int cl = ch_class -'0';
    msg.chop(1);
    req.chop(1);
    //qDebug() << msg;

    //qDebug() << "created";
    char ch_req = req[req.length()-1].toLatin1();
    int t = ch_req - '0';

    switch (cl)
    {
    case R_MODE:
    {
        STMatrix<Trational> mat(msg);
        switch (t)
        {
            case DET_REQUEST:
             {
                mat.GaussElim();

                answer << (mat.GetDet());;
                answer += ' ';
                answer += QString().setNum(DET_ANSWER);
                //qDebug() << answer;
                break;
             }

            case RANK_REQUEST:
            {
                mat.GaussElim();

                answer << QString::number(mat.GetRank());
                answer += ' ';
                answer += QString().setNum(RANK_ANSWER);
                //qDebug() << answer;
                break;
            }

            case TRANSPOSE_REQUEST:
            {
                mat.transpose();
                answer<<mat;
                answer += ' ';
                answer += QString().setNum(TRANSPOSE_ANSWER);
                //qDebug() << answer;
                break;

            }
            default: return;
            }
        break;
    }

    case C_MODE:
    {
        STMatrix<Tcomplex> mat(msg);
        switch (t)
        {
            case DET_REQUEST:
             {
                mat.GaussElim();

                answer << (mat.GetDet());
                answer += ' ';
                answer += QString().setNum(DET_ANSWER);
                //qDebug() << answer;
                break;
             }

            case RANK_REQUEST:
            {
                mat.GaussElim();
                answer += QString::number(mat.GetRank());
                answer += ' ';
                answer += QString().setNum(RANK_ANSWER);
                //qDebug() << answer;
                break;
            }

            case TRANSPOSE_REQUEST:
            {
                mat.transpose();
                answer<<mat;
                answer += ' ';
                answer += QString().setNum(TRANSPOSE_ANSWER);
                //qDebug() << answer;
                break;

            }
            default: return;
            }
        break;
    }
        default: return;
    }


    comm->send(answer.toUtf8());
}
