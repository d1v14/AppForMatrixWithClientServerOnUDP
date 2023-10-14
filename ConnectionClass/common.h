#ifndef COMMON_H
#define COMMON_H

#include <QString>

enum messages
{
    READ_REQUEST = 1,
    READ_ANSWER = 2,
    DET_REQUEST = 3,
    DET_ANSWER = 4 ,
    RANK_REQUEST  = 5,
    RANK_ANSWER = 6,
    TRANSPOSE_REQUEST = 7,
    TRANSPOSE_ANSWER = 8,
};

enum mode {
    R_MODE = 2,
    C_MODE = 1
};

extern const QChar separator;
QString& operator<< (QString&,const QString&);

#endif // COMMON_H
