#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setControl();
}

Widget::~Widget()
{
    delete ui;
}


void Widget::changeMoney(int coin)
{
    money += coin;
    ui->lcdNumber->display(money);
    setControl();
}

void Widget::setControl()
{
    ui->pbCoffee->setEnabled(money > 200);
    ui->pbTea->setEnabled(money > 150);
    ui->pbMilk->setEnabled(money > 100);
}

void Widget::on_pbCoin500_clicked()
{
    changeMoney(500);
}


void Widget::on_pbCoin100_clicked()
{
    changeMoney(100);
}


void Widget::on_pbCoin50_clicked()
{
    changeMoney(50);
}


void Widget::on_pbCoin10_clicked()
{
    changeMoney(10);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-200);
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}


void Widget::on_pbMilk_clicked()
{
    changeMoney(-100);
}


void Widget::on_pbReset_clicked()
{
    x = money;
    int y500 = 0, y100 = 0, y50 = 0, y10 = 0;
    y500 = x / 500; x = x % 500;
    y100 = x / 100; x %= 100;
    y50 = x / 50; x %= 50;
    y10 = x / 10; x %= 10;

    QString a, b, c, d;
    a = a.setNum(y500);
    b = b.setNum(y100);
    c = c.setNum(y50);
    d = d.setNum(y10);

    MsgBox.information(this, "yejun", "500:" + a + "\t" + "100:" + b + "\t" + "50:" + c + "\t" + "10:" +d);
    MsgBox.setStandardButtons(QMessageBox::Ok |QMessageBox::Cancel);
    MsgBox.setDefaultButton(QMessageBox::Ok);

        money=0;
        ui->lcdNumber->display(money);
        setControl();
}
