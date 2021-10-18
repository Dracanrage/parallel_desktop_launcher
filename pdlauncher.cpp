#include "pdlauncher.h"
#include "ui_pdlauncher.h"
#include <QProcess>
#include <QDebug>
#include <QMessageBox>

PDLauncher::PDLauncher(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PDLauncher)
{
    ui->setupUi(this);
}

PDLauncher::~PDLauncher()
{
    delete ui;
}


void PDLauncher::on_other_clicked(bool checked)
{
    if (checked)
    {
        ui->windows10->setChecked(false);
        ui->windows11->setChecked(false);
        ui->ubuntu->setChecked(false);
        ui->other_le->setEnabled(true);
    }
}


void PDLauncher::on_quit_clicked()
{
    close();
}


void PDLauncher::on_start_clicked()
{
    QProcess process;
    QString command = "/usr/local/bin/prlctl start ";
    if (ui->windows10->isChecked())
    {
        process.start(command+"\"Windows 10\"");
    }
    else if (ui->windows11->isChecked())
    {
        process.start(command+"\"Windows 11\"");
    }
    else if (ui->ubuntu->isChecked())
    {
        process.start(command+"\"Ubuntu Linux\"");
    }
    else
    {
        process.start(command+"\""+ui->other_le->text()+"\"");
    }
    process.waitForFinished();
    QMessageBox msgbox;
    msgbox.setText(process.readAllStandardOutput());
    msgbox.setButtonText(QMessageBox::Ok,"好");
    msgbox.exec();
}


void PDLauncher::on_windows10_clicked(bool checked)
{
    if (checked)
    {
        ui->other->setChecked(false);
        ui->windows11->setChecked(false);
        ui->ubuntu->setChecked(false);
        ui->other_le->setEnabled(false);
    }
}


void PDLauncher::on_windows11_clicked(bool checked)
{
    if (checked)
    {
        ui->other->setChecked(false);
        ui->windows10->setChecked(false);
        ui->ubuntu->setChecked(false);
        ui->other_le->setEnabled(false);
    }
}


void PDLauncher::on_ubuntu_clicked(bool checked)
{
    if (checked)
    {
        ui->windows10->setChecked(false);
        ui->windows11->setChecked(false);
        ui->other->setChecked(false);
        ui->other_le->setEnabled(false);
    }
}

