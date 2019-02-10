#ifndef PRODUCTSHOW_H
#define PRODUCTSHOW_H

#include <QDialog>
#include "data.h"

namespace Ui {
class productshow;
}

class productshow : public QDialog
{
    Q_OBJECT

public:
    explicit productshow(QWidget *parent = 0);
    ~productshow();
    void showProductdetail(Product* itemtoshow);

private:
    Ui::productshow *ui;
};

#endif // PRODUCTSHOW_H
