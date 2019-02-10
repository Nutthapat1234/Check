#ifndef PRODUCTADD_H
#define PRODUCTADD_H

#include <QWidget>
#include "data.h"
#include "database_mange.h"
#include <QScopedPointer>


namespace Ui {
class productAdd;
}

class productAdd : public QWidget
{
    Q_OBJECT

public:
    explicit productAdd(QWidget *parent = 0);
    ~productAdd();

signals:
    void backWard();

private slots:
    void on_fileip_clicked();
    void on_back_clicked();

    void on_cofirm_clicked();

    void on_codeip_clicked();

private:
    Ui::productAdd *ui;
    QString filename;
    QString code ;
};

#endif // PRODUCTADD_H
