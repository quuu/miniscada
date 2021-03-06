#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "label.h"
#include "geometry.h"
#include "icon.h"
#include "axis.h"
#include "legend.h"
#include <stdlib.h>
#include <time.h>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*Label l;
    l.setGeometry(Geometry(10, 10));
    l.setOrientation(horizontal);
    l.setText("test comic sansa gghjghjg jhfjj ngb 76p ' '''][].gfd");
    l.setFont(QFont("comic sans ms", 10));
    l.setIcon(Icon(Geometry(0,0,20,20), Qt::green));

    Label l2;
    l2.setGeometry(Geometry(10, 10));
    l2.setOrientation(horizontal);
    l2.setText("test Tajmsa");
    l2.setFont(QFont("times new roman", 20));
    l2.setIcon(Icon(Geometry(0,0,5,5), Qt::red));*/

    /*leg.addLabel(Label("Etykieta 1", Geometry(0, 0, 0, 20), Icon(Qt::red)));
    leg.addLabel(Label("Etykieta 2", Geometry(0, 0, 0, 20), Icon(Qt::yellow)));
    leg.addLabel(Label("Etykieta 3", Geometry(0, 0, 0, 20), Icon(Qt::darkYellow)));
    leg.addLabel(Label("Etykieta 4", Geometry(0, 0, 0, 20), Icon(Qt::darkRed)));
    leg.addLabel(Label("Etykieta 5", Geometry(0, 0, 0, 20), Icon(Qt::cyan)));
    leg.addLabel(Label("Etykieta 6", Geometry(0, 0, 0, 20), Icon(Qt::magenta)));*/
    Axis x;
    x.setFont(QFont("arial", 8));
    x.setTick(20);
    x.setTickDirection(inside);
    x.setTickSize(4);
    x.setMax(100);
    x.setMin(0);
    x.setPosition(bottom);
    x.setUnitVisibility(false);
    x.setGeometry(Geometry(0, 0, 400, 30));

    //Legend leg;
    /*leg.addLabel(Label("Etykieta 1", Geometry(0, 0, 0, 20), Icon(Geometry(0, 0, 20, 20), Qt::red)));
    leg.addLabel(Label("Etykieta 2", Geometry(0, 0, 0, 20), Icon(QColor(255, 150, 0))));
    leg.addLabel(Label("Etykieta 3", Geometry(0, 0, 0, 20), Icon(Qt::darkBlue)));
    leg.addLabel(Label("Etykieta 4", Geometry(0, 0, 0, 20), Icon(Qt::cyan)));*/

    ch.setAxisX(x);
    x.setPosition(bottom);
    x.setGeometry(Geometry(0, 0, 40, 400));
    ch.addAxisY(x);
    ch.setGeometry(Geometry(0, 0, 500, 500));
    //ch.setLegend(leg);

    LineStyle ls;
    ls.setWidth(2);
    ls.setColor(QColor(255, 127, 40));
    ls.setType(Qt::SolidLine);

    s = new Serie;
    s->setLength(20);
    s->setLineStyle(ls);
    s->setAxisId(0);
//    s->setTick(20);
//    s->addPoint(0);
//    s->addPoint(50);
//    s->addPoint(20);
//    s->addPoint(100);
//    s->addPoint(50);
    ch.addSerie(s);

    srand(time(NULL));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete s;
}

void MainWindow::on_pushButton_clicked()
{
    Axis x;
    x.setFont(QFont("arial", 8));
    x.setTick(ui->eTick->text().toDouble());
    if(ui->cKierunek->currentText()=="wewnątrz")
        x.setTickDirection(inside);
    else if(ui->cKierunek->currentText()=="zewnątrz")
        x.setTickDirection(outside);
    else x.setTickDirection(middle);
    x.setTickSize(4);
    x.setMax(ui->eMax->text().toDouble());
    x.setMin(ui->eMin->text().toDouble());
    x.setPosition(left);
    x.setUnitVisibility(ui->cJednostka->isChecked());
    x.setGeometry(Geometry(0, 0, 40, 400));
    x.setUnit(ui->eJednostka->text());
    x.draw();

    ch.removeAxisY(0);
    ch.addAxisY(x);
    ch.drawBackground();
    ui->label->setPixmap(ch.draw());
}

void MainWindow::on_pushButton_2_clicked()
{
    for(int i=0; i<ch.getSeriesCount(); i++)
    {
        ch.getSerie(i)->addPoint((double)rand()/RAND_MAX*(ch.getAxisY(ch.getSerie(i)->getAxisId()).getMax()-ch.getAxisY(ch.getSerie(i)->getAxisId()).getMin())+ch.getAxisY(ch.getSerie(i)->getAxisId()).getMin());
    }
    ui->label->setPixmap(ch.draw());
}

void MainWindow::on_pushButton_3_clicked()
{
    Axis x;
    x.setFont(QFont("verdana", 6));
    x.setTick(ui->eTick->text().toDouble());
    if(ui->cKierunek->currentText()=="wewnątrz")
        x.setTickDirection(inside);
    else if(ui->cKierunek->currentText()=="zewnątrz")
        x.setTickDirection(outside);
    else x.setTickDirection(middle);
    x.setTickSize(4);
    x.setMax(ui->eMax->text().toDouble());
    x.setMin(ui->eMin->text().toDouble());
    if(ui->cStrona->currentText() == "prawa")
        x.setPosition(right);
    else x.setPosition(left);
    x.setUnitVisibility(ui->cJednostka->isChecked());
    x.setGeometry(Geometry(0, 0, 40, 400));
    x.setUnit(ui->eJednostka->text());
    x.setLabel(Label(ui->eTytul->text(), Geometry(0,0,ui->cEtykieta->isChecked()?10:0,10), Icon(Qt::red, Geometry(0,0,0,0)), QFont("Arial", 8), vertical));
    x.draw();

    ch.addAxisY(x);
    ch.drawBackground();
    ui->label->setPixmap(ch.draw());
}

void MainWindow::on_pushButton_5_clicked()
{
    QPixmap px = QPixmap(ui->lKolor->width(), ui->lKolor->height());
    QPainter p;
    p.begin(&px);
    kolor = QColor((float)qrand()/RAND_MAX*255, (float)qrand()/RAND_MAX*255, (float)qrand()/RAND_MAX*255);
    p.fillRect(0, 0, ui->lKolor->width(), ui->lKolor->height(), kolor);

    p.end();
    ui->lKolor->setPixmap(px);
}

void MainWindow::on_pushButton_4_clicked()
{
    Serie *seria = new Serie;
    seria->setAxisId(ui->eOs->text().toInt());
    seria->setLength(20);
    seria->setLineStyle(LineStyle(2, kolor));
    ch.addSerie(seria);
    ch.drawBackground();
    ui->label->setPixmap(ch.draw());
}

void MainWindow::on_pushButton_6_clicked()
{
    ch.setGridAxis(ui->eGridAx->text().toInt());
    ch.drawBackground();
    ui->label->setPixmap(ch.draw());
}
