#ifndef TMatrix_H
#define TMatrix_H

#include <iostream>
#include <math.h>
//#include <number.h>
#include "rational.h"
#include "complex.h"
#include <ostream>
#include <vector>
#include <string.h>

template <class number>
class TMatrix
{
protected:
    vector<vector<number>> matrix;
    int sizex = 1;
    int sizey = 1;
public:
    TMatrix();
    TMatrix(vector<vector<number>>);
    TMatrix(QByteArray);
    void transpose();
    int count_underscores(string s, char ch);
    template<class T>
    friend ostream& operator<<(ostream&, TMatrix<T>&);
    template<class T>
    friend istream& operator>>(istream&, TMatrix<T>&);
    template<class T>
    friend QString& operator<<(QString&, TMatrix<T>&);
};

template <class number>
TMatrix<number>::TMatrix(){}
template <class number>
TMatrix<number>::TMatrix(vector<vector<number>> mas)
{
    sizey = mas.size();
    sizex = mas[0].size();
    for (int i=0; i<sizey; i++)
    {
        vector<number> row;
        for (int j=0; j<sizex; j++)
        {
            row.push_back(mas[i][j]);
        }
        matrix.push_back(row);
    }
}
template <>
TMatrix<Trational>::TMatrix(QByteArray msg)
{
    vector<int> row;
    vector<int> column;
    QString var_ = QString(msg);
    std::string var = var_.toStdString();
    int row_counter = 0;

    for (size_t i = 0; i < var.length() - 2; i++)
    {
        if (var[i] == ';')
            ++row_counter;
        if (var[i] == ' ' || var[i] == ';')
            continue;
        string tmp{};

        while (var[i] != ' ')
        {
            tmp += var[i];
            ++i;
        }
        if (count_underscores(tmp, '/') > 0)
        {
            //cout << tmp << endl;
            string num_ = "";
            string denom_ = "";
            int k = tmp.find('/');
            //std::cout<<endl<<k<<endl;
            for (int j = 0; j < k; ++j)
            {
                num_ += tmp[j];
                //std::cout<<endl<<num_;
            }
            for (int j = k+1; j < (int(tmp.length())); ++j)
            {
                //std::cout<<endl<<tmp[j];
                char ch = tmp[j];
                //std::cout<<ch<<endl;
                denom_ += ch;
                //std::cout<<endl<<"denom_";
            }
            row.push_back(stoi(num_));
            column.push_back(stoi(denom_));
            //std::cout << "c";
        }
        else
        {
            cout << tmp;
            if (stoi(tmp) == 0)
            {
                row.push_back(0);
                column.push_back(1);
                //std::cout << "a";
            }
            else
            {
                row.push_back(stoi(tmp));
                column.push_back(1);
                //std::cout << "b";
            }

        }

    }

    int k = 0;
    sizex = (row_counter + 1);
    sizey = row.size() / sizex;
    for (int i = 0; i < sizex; i++)
    {
        vector<Trational> row_tmp;
        for (int j = 0; j < sizey; j++)
        {
            row_tmp.push_back(Trational(row[k], column[k]));
            ++k;
        }
        matrix.push_back(row_tmp);
    }
}

template <>
TMatrix<Tcomplex>::TMatrix(QByteArray msg)
{
    vector<double> row;
    vector<double> column;
    QString var_ = QString(msg);
    std::string var = var_.toStdString();
    int row_counter = 0;

    for (size_t i = 0; i < var.length() - 2; i++)
    {
        if (var[i] == ';')
            ++row_counter;
        if (var[i] == ' ' || var[i] == ';')
            continue;
        string tmp{};

        while (var[i] != ' ')
        {
            tmp += var[i];
            ++i;
        }
        if (count_underscores(tmp, '+') > 0)
        {
            //cout << tmp << endl;
            string num_ = "";
            string denom_ = "";
            int k = tmp.find('+');
            //std::cout<<endl<<k<<endl;
            for (int j = 0; j < k; ++j)
            {

                num_ += tmp[j];
                //std::cout<<endl<<num_;
            }
            for (int j = k+1; j < (int(tmp.length())); ++j)
            {
                //std::cout<<endl<<tmp[j];
                char ch = tmp[j];
                //std::cout<<ch<<endl;
                if (ch != 'i')
                    denom_ += ch;
                //std::cout<<endl<<"denom_";
            }
            row.push_back(stod(num_));
            column.push_back(stod(denom_));
            //std::cout << "c";
        }
        else
        {
            if (count_underscores(tmp, 'i') > 0)
            {
                row.push_back(0);
                tmp.pop_back();
                column.push_back(stod(tmp));
            }
            else
            {
                row.push_back(stod(tmp));
                column.push_back(0);
            }
        }
    }

    int k = 0;
    sizex = (row_counter + 1);
    sizey = row.size() / sizex;
    for (int i = 0; i < sizex; i++)
    {
        vector<Tcomplex> row_tmp;
        for (int j = 0; j < sizey; j++)
        {
            row_tmp.push_back(Tcomplex(row[k], column[k]));
            ++k;
        }
        matrix.push_back(row_tmp);
    }
}



template <class number>
void TMatrix<number>::transpose()
{
    vector<vector<number>> mas;

    for(int i = 0; i < sizey; ++i)
    {
        vector<number> row;
        for(int j = 0; j < sizex; ++j)
        {
            row.push_back(matrix[j][i]);
        }
        mas.push_back(row);
    }
    matrix = mas;
    int tmp = sizex;
    sizex = sizey;
    sizey = tmp;
}

template <class number>
int TMatrix<number>::count_underscores(string s, char ch) {
    int count = 0;

    for (int i = 0; i < s.size(); i++)
        if (s[i] == ch) count++;

    return count;
}

template <class number>
ostream& operator<< (ostream& os, TMatrix<number>& m)
{
    cout<<"matrix:"<<endl;
    for (int i=0; i<m.sizex; i++)
    {
        for (int j=0; j<m.sizey; j++)
            cout<<m.matrix[i][j]<<"  ";
        cout<<endl;
    }
    return os;
}

template <class number>
istream& operator>> (istream& is, TMatrix<number>& m)
{
    cout<<"row size = ";
    cin >> m.sizex;
    cout<<"column size = ";
    cin >> m.sizey;
    for (int i=0; i<m.sizex; i++)
    {
        vector<number> row;
        for (int j=0; j<m.sizey; j++)
        {
            cout<<"matrix["<<i<<"]["<<j<<"] = ";
            number temp;
            cin >> temp;
            row.push_back(temp);
        }
        m.matrix.push_back(row);
    }
    return is;
}


template <class number>
QString& operator<<(QString& os, TMatrix<number>& m)
{
    for (int i=0; i<m.sizex; i++)
    {
        for (int j=0; j<m.sizey; j++)
        {
            os << m.matrix[i][j];
            os += QString::fromStdString(" ");
        }
        os += QString::fromStdString("\n");
    }
    return os;
}


template <class number>
class STMatrix : public TMatrix<number>
{
public:
    int size = 1;
    int rank = 0;
    number det;

public:
    STMatrix();
    STMatrix(vector<vector<number>>);
    STMatrix(QByteArray);
    number GetDet();
    int GetRank();
    void GaussElim();
    template<class T1>
    friend ostream& operator<<(ostream&, STMatrix<T1>&);
    template<class T1>
    friend istream& operator>>(istream&, STMatrix<T1>&);
    template<class T1>
    friend QString& operator<<(QString&, STMatrix<T1>&);
    friend QString& operator<<(QString& os, STMatrix<double>& m);

};

template <class number>
STMatrix<number>::STMatrix()
{}

template <class number>
STMatrix<number>::STMatrix(vector<vector<number>> mas):
    TMatrix<number>(mas),
    size(TMatrix<number>::sizex){}

template <class number>
STMatrix<number>::STMatrix(QByteArray arr):
    TMatrix<number>(arr),
    size(TMatrix<number>::sizex){}

template <class number>
number STMatrix<number>::GetDet()
{
    return det;
}

template <class number>
int STMatrix<number>::GetRank()
{
    return rank;
}

template <class number>
void STMatrix<number>::GaussElim()
{
    vector<vector<number>> tempMatrix(size, vector<number>(size));
    for (int i=0; i<size; i++)
        for (int j=0; j<size; j++)
            tempMatrix[i][j] = TMatrix<number>::matrix[i][j];
    number temp;
    for (int k = 0; k < size - 1; k++) {
            for (int i = k + 1; i < size; i++) {
                temp = -tempMatrix[i][k] / tempMatrix[k][k];
                for (int j = 0; j < size; j++) {
                    tempMatrix[i][j] += tempMatrix[k][j] * temp;
                }
            }
        }
        det = 1;
        for (int i = 0; i < size; i++) {
            det *= tempMatrix[i][i];
        }
        rank = 0;
        for (int i=0; i<size; i++)
            for (int j=0; j<size; j++)
                if (tempMatrix[i][j] != 0)
                {
                    ++rank;
                    break;
                }

}

template <class number>
ostream& operator<< (ostream& os, STMatrix<number>& m)
{
    cout<<"matrix:"<<endl;
    for (int i=0; i<m.size; i++)
    {
        for (int j=0; j<m.size; j++)
            cout<<m.matrix[i][j]<<"  ";
        cout<<endl;
    }
    return os;
}

template <class number>
istream& operator>> (istream& is, STMatrix<number>& m)
{
    cout<<"size = ";
    cin >> m.size;
    for (int i=0; i<m.size; i++)
    {
        vector<number> row;
        for (int j=0; j<m.size; j++)
        {
            cout<<"matrix["<<i<<"]["<<j<<"] = ";
            number temp;
            cin >> temp;
            row.push_back(temp);
        }
        m.matrix.push_back(row);
    }
    return is;
}

template <class number>
QString& operator<<(QString& os, STMatrix<number>& m)
{
    for (int i=0; i<m.size; i++)
    {
        for (int j=0; j<m.size; j++)
        {
            os << m.matrix[i][j];
            os += QString::fromStdString(" ");
        }
        os += QString::fromStdString("\n");
    }
    return os;
}





#endif // TMatrix_H
