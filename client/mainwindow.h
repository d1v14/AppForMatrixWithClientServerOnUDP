#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QComboBox>
#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QFormLayout>
#include <QLineEdit>
#include <QRadioButton>
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    //QGridLayout *lay;
    QLabel *n_l, *output_l;
    QLineEdit *n_v;
    QPushButton *tempBut, *readBut, *detBut, *rankBut,  *transBut;
    QLabel *output;
    QList<QList<QLineEdit*>> value_list;
    QFormLayout *form;
    QComboBox *comboBox;
    QRadioButton  *rat, *doub, *comp;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString QListToQString();
public slots:
    void chooseClass(QString);
    void makeTemplate();
    void answer(QString);
    void printTemplate();
private slots:
    void formRequest();
signals:
    void request(QString);
};
#endif // MAINWINDOW_H
