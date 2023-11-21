#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextStream>

double num_first;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_0, SIGNAL(clicked()),this, SLOT(numbers()));
    connect(ui->pushButton_1, SIGNAL(clicked()),this, SLOT(numbers()));
    connect(ui->pushButton_2, SIGNAL(clicked()),this, SLOT(numbers()));
    connect(ui->pushButton_3, SIGNAL(clicked()),this, SLOT(numbers()));
    connect(ui->pushButton_4, SIGNAL(clicked()),this, SLOT(numbers()));
    connect(ui->pushButton_5, SIGNAL(clicked()),this, SLOT(numbers()));
    connect(ui->pushButton_6, SIGNAL(clicked()),this, SLOT(numbers()));
    connect(ui->pushButton_7, SIGNAL(clicked()),this, SLOT(numbers()));
    connect(ui->pushButton_8, SIGNAL(clicked()),this, SLOT(numbers()));
    connect(ui->pushButton_9, SIGNAL(clicked()),this, SLOT(numbers()));

    connect(ui->pushButton_A, SIGNAL(clicked()),this, SLOT(numbers()));
    connect(ui->pushButton_B, SIGNAL(clicked()),this, SLOT(numbers()));
    connect(ui->pushButton_C, SIGNAL(clicked()),this, SLOT(numbers()));
    connect(ui->pushButton_D, SIGNAL(clicked()),this, SLOT(numbers()));
    connect(ui->pushButton_E, SIGNAL(clicked()),this, SLOT(numbers()));
    connect(ui->pushButton_F, SIGNAL(clicked()),this, SLOT(numbers()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clear_clicked(){

    ui->result_show->setText("0");
    ui->pushButton2_to_10->setEnabled(true);
    ui->pushButton8_to_10->setEnabled(true);
    ui->pushButton_to2->setEnabled(true);
    ui->pushButton_to8->setEnabled(true);
    ui->pushButton_to16->setEnabled(true);
}

void MainWindow::numbers(){

    QPushButton *buttons = qobject_cast<QPushButton*>(sender());
    QString current_text = ui->result_show->text();

    if (current_text == "0") {
        current_text = buttons->text();
        ui->pushButton2_to_10->setEnabled(true);
        ui->pushButton8_to_10->setEnabled(true);
        ui->pushButton_to2->setEnabled(true);
        ui->pushButton_to8->setEnabled(true);
        ui->pushButton_to16->setEnabled(true);

    }
    else {
        current_text += buttons->text();
    }

    if(current_text.contains('9')||current_text.contains('8')){
        ui->pushButton2_to_10->setEnabled(false);
    }
    if(current_text.contains('2') || current_text.contains('3')||current_text.contains('4')||current_text.contains('5')||current_text.contains('6')||current_text.contains('7')){
        ui->pushButton2_to_10->setEnabled(false);
    }
    if(current_text.contains('A')||current_text.contains('B')||current_text.contains('C')||current_text.contains('D')||current_text.contains('E')||current_text.contains('F')){
        ui->pushButton2_to_10->setEnabled(false);
        ui->pushButton8_to_10->setEnabled(false);
        ui->pushButton_to2->setEnabled(false);
        ui->pushButton_to8->setEnabled(false);
        ui->pushButton_to16->setEnabled(false);
    }
    ui->result_show->setText(current_text);


}





void MainWindow::on_pushButton_to2_clicked()
{
    QPushButton *button = (QPushButton *)sender();
    double all_numbers;
    QString new_label;
    all_numbers = (ui->result_show->text()).toDouble();
    int n = (int)all_numbers;
    QString hexString = QString::number(n, 2);
    ui->result_show->setText(hexString);

}


void MainWindow::on_pushButton_to8_clicked()
{
    QPushButton *button = (QPushButton *)sender();
    double all_numbers;
    QString new_label;

    all_numbers = (ui->result_show->text()).toDouble();
    int n = (int)all_numbers;
    QString hexString = QString::number(n, 8);
    ui->result_show->setText(hexString);
}


void MainWindow::on_pushButton_to16_clicked()
{
    QPushButton *button = (QPushButton *)sender();
    double all_numbers;
    QString new_label;

    all_numbers = (ui->result_show->text()).toDouble();
    int n = (int)all_numbers;
    QString hexString = QString::number(n, 16).toUpper();
    ui->result_show->setText(hexString);
}

void MainWindow::on_pushButton2_to_10_clicked()
{
    QPushButton *button = (QPushButton *)sender();
    QString binaryString = ui->result_show->text();

    int decimalNumber = QString(binaryString).toInt(nullptr, 2);

    QString hexString = QString::number(decimalNumber);
    ui->result_show->setText(hexString);
}

void MainWindow::on_pushButton8_to_10_clicked()
{
    QPushButton *button = (QPushButton *)sender();
    QString binaryString = ui->result_show->text();

    int decimalNumber = QString(binaryString).toInt(nullptr, 8);

    QString hexString = QString::number(decimalNumber);
    ui->result_show->setText(hexString);
}


void MainWindow::on_pushButton16_to_10_clicked()
{
    QPushButton *button = (QPushButton *)sender();
    QString hexString = ui->result_show->text();

    int decimalNumber = hexString.toInt(nullptr, 16);
    QString decimalString = QString::number(decimalNumber);
    ui->result_show->setText(decimalString);

}
