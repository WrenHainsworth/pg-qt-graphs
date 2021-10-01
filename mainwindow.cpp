#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QBarSet *set0 = new QBarSet("User1");
    QBarSet *set1 = new QBarSet("User2");
    QBarSet *set2 = new QBarSet("User3");
    QBarSet *set3 = new QBarSet("User4");
    QBarSet *set4 = new QBarSet("User5");

    *set0 << 10 << 20 << 30 << 40 << 50 << 60;
    *set1 << 50 << 70 << 40 << 45 << 80 <<70;
    *set2 << 30 << 50 << 80 << 13 << 80 << 50;
    *set3 << 50 << 60 << 70 << 30 << 40 << 25;
    *set4 << 90 << 70 << 50 << 30 << 16 << 42;

    QBarSeries *series = new QBarSeries();
    series -> append(set0);
    series -> append(set1);
    series -> append(set2);
    series -> append(set3);
    series -> append(set4);

    QChart *chart = new QChart();
    chart -> addSeries(series);
    chart -> setTitle("Series title");
    chart -> setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories;
    categories << "Cat1" << "Cat2" << "Cat3" << "Cat4" << "Cat5" << "Cat6";
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();
    chart-> setAxisX(axis, series);

    QChartView *chartView = new QChartView(chart);
    chartView-> setParent(ui->verticalFrame);

}

MainWindow::~MainWindow()
{
    delete ui;
}

