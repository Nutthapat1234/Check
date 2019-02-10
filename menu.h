#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <QScopedPointer>
#include "camera_ui.h"
#include "productadd.h"
#include "login.h"
#include "adminmenu.h"
#include "addadmin.h"

namespace Ui {
class Menu;
}

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = 0);
    ~Menu();
private slots:
    void on_guest_clicked();
    void on_admin_clicked();
    void setMenuAdmin();
    void setLoginActive();
    void setBackActive();
    void setAddProductActive();
    void setAddAdminActive();
    void on_back_clicked();

private:
    Ui::Menu *ui;
    camera_ui *cameraUi;
    login *loginUi;
    void closeEvent (QCloseEvent *event);

};

#endif // MENU_H
