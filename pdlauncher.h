#ifndef PDLAUNCHER_H
#define PDLAUNCHER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class PDLauncher; }
QT_END_NAMESPACE

class PDLauncher : public QMainWindow
{
    Q_OBJECT

public:
    PDLauncher(QWidget *parent = nullptr);
    ~PDLauncher();

private slots:
    void on_other_clicked(bool checked);

    void on_quit_clicked();

    void on_start_clicked();

    void on_windows10_clicked(bool checked);

    void on_windows11_clicked(bool checked);

    void on_ubuntu_clicked(bool checked);

private:
    Ui::PDLauncher *ui;
};
#endif // PDLAUNCHER_H
