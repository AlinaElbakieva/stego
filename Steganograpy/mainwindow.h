#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_encodeButton_clicked();
    void on_decodeButton_clicked();
    void on_saveButton_clicked();
    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    int bitsPerComponent;
    QString decodeMessage(const QImage& image);
    QImage encodeMessage(const QImage& image, const QString& message);
    QString binaryToMessage(const QString& binaryText);
    QString messageToBinary(const QString& message);

};

#endif // MAINWINDOW_H
