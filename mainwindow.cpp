#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::inputRocket() {

    rocket.mass = ui->spin_Rocket_mass->value();                                                              // масса ракеты
    rocket.altitude = ui->spin_Start_altitude->value();                                                       // начальная высота
    rocket.velocity = ui->spin_Start_velocity->value();                                                      // стартовая скорость ракеты
    chute.deployAltitude = ui->spin_Deploy_altitude->value();                                               // высота, на которой должен раскрыться парашют
    chute.drag = ui->spin_Drag_koaf->value();                                                              // коэффициент сопротивления парашюта
    ui->label_current_height->setText("Текущая высота: " + QString::number(rocket.altitude) + "м");       // отображаем тек. высоту на форме
    

    qDebug() << "Масса:" << rocket.mass << "kg";
    qDebug() << "Высота раскрытия:" << chute.deployAltitude << "m";
    qDebug() << "Начальная высота:" <<rocket.altitude<<"m";
    qDebug() << "Начальная скорость:"<<rocket.velocity<<"m/s";
    qDebug() << "Коэффициент сопротивления:"<<chute.drag;
    ui->label_status->setText("Параметры успешно загружены!!!");
    
}


void MainWindow::on_launch_button_clicked() {                     // кнопка запуска 
    inputRocket();

}
