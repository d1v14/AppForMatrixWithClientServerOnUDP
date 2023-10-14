#include "basic_matrix.h"

TBasic_matrix::TBasic_matrix(){}

TBasic_matrix::TBasic_matrix(vector<vector<number>> mas)
{
    column_size = mas.size();
    row_size = mas[0].size();
    for (int i=0; i<column_size; i++)
    {
        vector<number> row;
        for (int j=0; j<row_size; j++)
        {
            row.push_back(mas[i][j]);
        }
        matrix.push_back(row);
    }
}

TBasic_matrix::TBasic_matrix(QByteArray msg)
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
    row_size = (row_counter + 1);
    column_size = row.size() / row_size;
    for (int i = 0; i < row_size; i++)
    {
        vector<number> row_tmp;
        for (int j = 0; j < column_size; j++)
        {
            row_tmp.push_back(number(row[k], column[k]));
            ++k;
        }
        matrix.push_back(row_tmp);
    }
}

void TBasic_matrix::transpose()
{
    vector<vector<number>> mas;

    for(int i = 0; i < column_size; ++i)
    {
        vector<number> row;
        for(int j = 0; j < row_size; ++j)
        {
            row.push_back(matrix[j][i]);
        }
        mas.push_back(row);
    }
    matrix = mas;
    int tmp = row_size;
    row_size = column_size;
    column_size = tmp;
}

int TBasic_matrix::count_underscores(string s, char ch) {
    int count = 0;

    for (int i = 0; i < s.size(); i++)
        if (s[i] == ch) count++;

    return count;
}

ostream& operator<< (ostream& os, TBasic_matrix& m)
{
    cout<<"matrix:"<<endl;
    for (int i=0; i<m.row_size; i++)
    {
        for (int j=0; j<m.column_size; j++)
            cout<<m.matrix[i][j]<<"  ";
        cout<<endl;
    }
    return os;
}

istream& operator>> (istream& is, TBasic_matrix& m)
{
    cout<<"row size = ";
    cin >> m.row_size;
    cout<<"column size = ";
    cin >> m.column_size;
    for (int i=0; i<m.row_size; i++)
    {
        vector<number> row;
        for (int j=0; j<m.column_size; j++)
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

QString& operator<<(QString& os, TBasic_matrix& m)
{
    for (int i=0; i<m.row_size; i++)
    {
        for (int j=0; j<m.column_size; j++)
        {
            os << m.matrix[i][j];
            os += QString::fromStdString(" ");
        }
        os += QString::fromStdString("\n");
    }
    return os;
}
