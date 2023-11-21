#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    connect(ui->pushButton_plus_minus, SIGNAL(clicked()),this, SLOT(operations()));
    connect(ui->pushButton_vidsotok, SIGNAL(clicked()),this, SLOT(operations()));
    connect(ui->pushButton_stepin, SIGNAL(clicked()),this, SLOT(operations()));

   connect(ui->pushButton_plus, SIGNAL(clicked()),this, SLOT(math_operations()));
    connect(ui->pushButton_minus, SIGNAL(clicked()),this, SLOT(math_operations()));
    connect(ui->pushButton_mno, SIGNAL(clicked()),this, SLOT(math_operations()));
    connect(ui->pushButton_diff, SIGNAL(clicked()),this, SLOT(math_operations()));

    ui->pushButton_diff->setCheckable(true);
    ui->pushButton_mno->setCheckable(true);
    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numbers(){
    QPushButton *button = (QPushButton *)sender();
    double all_numbers;
    QString new_label;
    all_numbers = (ui->result_show->text()+button->text()).toDouble();
    new_label=QString::number(all_numbers, 'g', 15);
    ui ->result_show->setText(new_label);
}

void MainWindow::operations(){
    QPushButton *button = (QPushButton *)sender();
    double all_numbers;
    QString new_label;

    if(button->text()=="+/-"){
        all_numbers = (ui->result_show->text()).toDouble();
        all_numbers = all_numbers * -1;

    new_label=QString::number(all_numbers, 'g', 15);

    ui ->result_show->setText(new_label);
    }
    else if(button->text() == "%"){
    all_numbers = (ui->result_show->text()).toDouble();
    all_numbers = all_numbers * 0.01;

    new_label=QString::number(all_numbers, 'g', 15);

    ui ->result_show->setText(new_label);
    }
    else if(button->text() == "^"){
        all_numbers = (ui->result_show->text()).toDouble();
        all_numbers = all_numbers * all_numbers;

        new_label=QString::number(all_numbers, 'g', 15);

        ui ->result_show->setText(new_label);
}
}

void MainWindow::math_operations()
{
    QPushButton *button = (QPushButton *)sender();

    num_first=ui->result_show->text().toDouble();
    ui->result_show->setText("");
    button->setChecked(true);
}

void MainWindow::on_pushButton_result_clicked()
{
double labelNumber, num_second;
QString new_label;
num_second= (ui->result_show->text()).toDouble();

if(ui->pushButton_plus->isChecked()){
    labelNumber=num_first + num_second;
    new_label=QString::number(labelNumber, 'g', 15);

    ui ->result_show->setText(new_label);
    ui->pushButton_plus->setChecked(false);

}
else if(ui->pushButton_minus->isChecked()){
    labelNumber=num_first - num_second;
    new_label=QString::number(labelNumber, 'g', 15);

    ui ->result_show->setText(new_label);
    ui->pushButton_minus->setChecked(false);
}
else if(ui->pushButton_mno->isChecked()){
    labelNumber=num_first * num_second;
    new_label=QString::number(labelNumber, 'g', 15);

    ui ->result_show->setText(new_label);
    ui->pushButton_mno->setChecked(false);
}
else if(ui->pushButton_diff->isChecked()){
    labelNumber=num_first / num_second;
    new_label=QString::number(labelNumber, 'g', 15);

    ui ->result_show->setText(new_label);
    ui->pushButton_diff->setChecked(false);
}
}



void MainWindow::on_pushButton_clear_clicked()
{
ui->pushButton_diff->setChecked(false);
ui->pushButton_mno->setChecked(false);
ui->pushButton_plus->setChecked(false);
ui->pushButton_minus->setChecked(false);

ui->result_show->setText("0");

}




