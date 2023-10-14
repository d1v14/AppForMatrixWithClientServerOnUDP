#include "mainwindow.h"
#include "../ConnectionClass/common.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(800, 400);

    form = new QFormLayout(parent);

    comboBox = new QComboBox;
    comboBox->addItem(tr("Complex"));
    comboBox->addItem(tr("Rational"));
    comboBox->addItem(tr("Double"));

    n_l = new QLabel("Введите размер матрицы: ", this);
    n_l->setGeometry(300,20,150,25);
    n_v = new QLineEdit("1", this);
    n_v->setGeometry(460,25,50,20);

    tempBut = new QPushButton("Сформировать матрицу", this);
    readBut = new QPushButton("Вывод матрицы", this);
    detBut = new QPushButton("Детерминант", this);
    rankBut = new QPushButton("Ранг", this);
    transBut = new QPushButton("Транспонировать", this);

    readBut->setGeometry(170, 100, 150, 30);
    tempBut->setGeometry(10, 100, 150, 30);
    detBut->setGeometry(330, 100, 150, 30);
    rankBut->setGeometry(490, 100, 150, 30);
    transBut->setGeometry(650, 100, 150, 30);

    output_l = new QLabel("Вывод:", this);
    QFont font = output_l->font();
    font.setPixelSize(15);
    font.setBold(1);
    output_l->setFont(font);
    output_l->setGeometry(300,300,70,25);
    output = new QLabel(this);
    font.setPixelSize(15);
    font.setBold(1);
    output->setFont(font);
    output ->setGeometry(300, 310, 100, 100);

    doub = new QRadioButton("Вещественные", this);
    doub ->setGeometry(200, 280, 130, 25);
    rat = new QRadioButton("Рациональные", this);
    rat ->setGeometry(350, 280, 130, 25);
    comp = new QRadioButton("Комплексные", this);
    comp ->setGeometry(500, 280, 130, 25);
    rat->setChecked(true);

    connect(tempBut, SIGNAL(pressed()), this, SLOT(makeTemplate()));
    connect(readBut, SIGNAL(pressed()), this, SLOT(printTemplate()));
    connect(detBut, SIGNAL(pressed()), this, SLOT(formRequest()));
    connect(rankBut, SIGNAL(pressed()), this, SLOT(formRequest()));
    connect(transBut, SIGNAL(pressed()), this, SLOT(formRequest()));

}

MainWindow::~MainWindow()
{
}

void MainWindow::chooseClass(QString str)
{

}

void MainWindow::makeTemplate()
{
    n_v->setEnabled(0);
    tempBut->setEnabled(0);
    int n = n_v->text().toInt();
    for(int i = 0; i < n; i++)
    {
        QList<QLineEdit*> row;
        for(int j = 0; j < n; j++)
        {
            QLineEdit* temp = new QLineEdit("0", this);
            temp->setGeometry(300 + 70*j, 150 + 30*i, 70, 30);
            row.append(temp);
            form->addRow(temp);
            temp->show();
        }
        value_list.append(row);
    }
}

QString MainWindow::QListToQString()
{
    int n = n_v->text().toInt();
    QString result;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            result += (value_list[i][j]->text() + ' ');
        }
        result += ';';
    }
    return result;
}

void MainWindow::printTemplate()
{
    QString msg = QListToQString();
    for (int i = 0; i < msg.length(); i++)
        if (msg[i] == ';')
            msg[i] = '\n';
    output->setText(msg);
}

void MainWindow::formRequest()
{
    QString msg = QListToQString();
    QString classChooser{};
    if (doub->isChecked())
        classChooser= QString().setNum(C_MODE);
    else
        if (comp->isChecked())
            classChooser= QString().setNum(C_MODE);
        else
            classChooser= QString().setNum(R_MODE);


    QPushButton *btn = (QPushButton*)sender();
    if (btn == readBut)
        msg += QString().setNum(READ_REQUEST);

    if (btn == detBut)
        msg += QString().setNum(DET_REQUEST);

    if (btn == rankBut)
        msg += QString().setNum(RANK_REQUEST);

    if (btn == transBut)
        msg += QString().setNum(TRANSPOSE_REQUEST);
    msg += classChooser;

    emit request(msg);
}

void MainWindow::answer(QString msg)
{
    char ch = (msg[msg.length() - 1]).toLatin1();
    int t = ch - '0';
    msg.chop(1);
    switch (t)
    {
        case DET_ANSWER:
            output->setText(msg);
            break;
        case RANK_ANSWER:
            output->setText(msg);
            break;
        case TRANSPOSE_ANSWER:
            output->setText(msg);
            break;
        default: break;
    }
}

