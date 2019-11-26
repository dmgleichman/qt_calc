#ifndef APPLAYOUT_H
#define APPLAYOUT_H

#include <QWidget>
#include <QDialog>


QT_BEGIN_NAMESPACE
class QAction;
class QDialogButtonBox;
class QGroupBox;
class QLabel;
class QLineEdit;
class QMenu;
class QMenuBar;
class QPushButton;
class QTextEdit;
QT_END_NAMESPACE

class AppLayout : public QWidget
{
    Q_OBJECT
public:
    explicit AppLayout(QWidget *parent = nullptr);

signals:

public slots:
       void handleFileExit();
        void handleNewAction();
private:
        void createMenu();
        void createHorizontalGroupBox();
        void createGridGroupBox();
        void createFormGroupBox();



        enum { NumGridRows = 3, NumButtons = 4 };

        QMenuBar *menuBar;
        QGroupBox *horizontalGroupBox;
        QGroupBox *gridGroupBox;
        QGroupBox *formGroupBox;
        QTextEdit *smallEditor;
        QTextEdit *bigEditor;
        QLabel *labels[NumGridRows];
        QLineEdit *lineEdits[NumGridRows];
        QPushButton *buttons[NumButtons];
        QDialogButtonBox *buttonBox;

        QMenu *fileMenu;
        QAction *newAction;
        QAction *exitAction;

        QMenu *editMenu;
        QAction *cutAction;
        QAction *pasteAction;

};

#endif // APPLAYOUT_H
