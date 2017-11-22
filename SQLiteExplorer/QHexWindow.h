#ifndef QHEXWINDOW_H
#define QHEXWINDOW_H

#include <QWidget>
#include <QHexEdit/qhexedit.h>

#include "SQLite3DB.h"

#include <vector>
using namespace std;

namespace Ui {
class QHexWindow;
}

class MainWindow;
class QHexWindow : public QWidget
{
    Q_OBJECT

public:
    explicit QHexWindow(QWidget *parent = 0);
    ~QHexWindow();

    void SetPageIds(const vector<int>& pgids);

public slots:
    void onPageIdSelect(int pgno);
    void onComboxChanged(const QString& item);
    void onPrevBtnClicked();
    void onNextBtnClicked();

private:
    Ui::QHexWindow *ui;

    QHexEdit* m_pHexEdit;
    MainWindow* m_pParent;
    CSQLite3DB* m_pCurSQLite3DB;
};

#endif // QHEXWINDOW_H