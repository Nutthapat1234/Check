#ifndef ADDADMIN_H
#define ADDADMIN_H

#include <QWidget>

namespace Ui {
class AddAdmin;
}

class AddAdmin : public QWidget
{
    Q_OBJECT

public:
    explicit AddAdmin(QWidget *parent = 0);
    ~AddAdmin();
signals:
    void backWard();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::AddAdmin *ui;
    int time_click = 0;
};

#endif // ADDADMIN_H
