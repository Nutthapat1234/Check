#ifndef ADMINMENU_H
#define ADMINMENU_H

#include <QWidget>

namespace Ui {
class AdminMenu;
}

class AdminMenu : public QWidget
{
    Q_OBJECT

public:
    explicit AdminMenu(QWidget *parent = 0);
    ~AdminMenu();
signals:
    void backWard();
    void addProductClick();
    void addNewAdminClick();
private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AdminMenu *ui;
};

#endif // ADMINMENU_H
