#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <QString>
#include <QFileDialog>
#include <QImage>
#include <QPixmap>
#include <QRegularExpression>
#include <QMessageBox>
#include <QTextStream>
#include <QFile>
#include <QTabBar>
MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent)
, ui(new Ui::MainWindow)
{
ui->setupUi(this);
bitsPerComponent = 8;
this->setWindowTitle("Steganography");
this->setFixedSize(850, 600);
QIcon icon("C:/Users/User/Stego_1/Stego/ресурсы/stego-logo.png");
   setWindowIcon(icon);
   QString styleSheet = "QTabBar::tab { width: 430px; height: 40px; }";
     ui->tabWidget->tabBar()->setStyleSheet(styleSheet);

}

MainWindow::~MainWindow()
{
delete ui;
}

void MainWindow::on_pushButton_clicked()
{
QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("Image Files (*.bmp)"));
if (!fileName.isEmpty()) {
QImage image;
bool valid = image.load(fileName);
    if (valid) {
        ui->label->setPixmap(QPixmap::fromImage(image));
    }
    QPixmap pixmap = QPixmap::fromImage(image).scaled(ui->label->size(), Qt::KeepAspectRatio);
               ui->label->setPixmap(pixmap);

}
}

void MainWindow::on_encodeButton_clicked()
{
QString message = ui->lineEdit->text();


if (message.isEmpty()) {
    QMessageBox::warning(this, "Ошибка", "Введите сообщение для кодирования");
    return;
}

QImage image = ui->label->pixmap().toImage();

if (image.isNull()) {
    QMessageBox::warning(this, "Ошибка", "Загрузите изображение");
    return;
}

QImage encodedImage = encodeMessage(image, message);
ui->label_2->setPixmap(QPixmap::fromImage(encodedImage));
}

void MainWindow::on_decodeButton_clicked()
{
QImage image = ui->label_3->pixmap().toImage();


if (image.isNull()) {
    QMessageBox::warning(this, "Ошибка", "Загрузите изображение");
    return;
}

QString decodedMessage = decodeMessage(image);
ui->lineEdit_2->setText(decodedMessage);
}

void MainWindow::on_saveButton_clicked()
{
QString fileName = QFileDialog::getSaveFileName(this, tr("Save Image"), "", tr("Image Files (*.bmp)"));



if (!fileName.isEmpty()) {
    QImage image = ui->label_2->pixmap().toImage();

    if (image.isNull()) {
        QMessageBox::warning(this, "Ошибка", "Загрузите изображение");
        return;
    }

    bool saved = image.save(fileName, "BMP");

    if (!saved) {
        QMessageBox::warning(this, "Ошибка", "Не удалось сохранить изображение");
    }
}
}


QImage MainWindow::encodeMessage(const QImage& image, const QString& message)
{
    QImage encodedImage = image.copy();
    QString binaryMessage = messageToBinary(message) + QString("00000000");

    int binaryIndex = 0;//для отслеживания текущей позиции в двоичном сообщении.

    for (int y = 0; y < encodedImage.height() && binaryIndex < binaryMessage.length(); ++y) {
        for (int x = 0; x < encodedImage.width() && binaryIndex < binaryMessage.length(); ++x) {
            QColor pixelColor = encodedImage.pixelColor(x, y);//извлекаем
            int red = pixelColor.red();
            int green = pixelColor.green();
            int blue = pixelColor.blue();

            if (binaryIndex < binaryMessage.length()) {
                red = (red & 0xFE) | binaryMessage[binaryIndex].digitValue();//замена мл. бита расного цвета пикселя на бит бин. сообщение
                ++binaryIndex;
            }

            if (binaryIndex < binaryMessage.length()) {
                green = (green & 0xFE) | binaryMessage[binaryIndex].digitValue();
                ++binaryIndex;
            }

            if (binaryIndex < binaryMessage.length()) {
                blue = (blue & 0xFE) | binaryMessage[binaryIndex].digitValue();
                ++binaryIndex;
            }

            pixelColor.setRed(red);
            pixelColor.setGreen(green);
            pixelColor.setBlue(blue);
            encodedImage.setPixelColor(x, y, pixelColor);
        }
    }

    if (binaryIndex < binaryMessage.length()) {
        QMessageBox::warning(this, "Ошибка", "Сообщение слишком большое для данного изображения");
        return image;
    }

    return encodedImage;
}
QString MainWindow::decodeMessage(const QImage& image)
{
QString binaryText;

    for (int y = 0; y < image.height(); ++y) {
        for (int x = 0; x < image.width(); ++x) {
            QColor pixelColor = image.pixelColor(x, y);
            binaryText += QString::number(pixelColor.red() & 1);
            binaryText += QString::number(pixelColor.green() & 1);
            binaryText += QString::number(pixelColor.blue() & 1);
        }
    }

    QString decodedMessage;
    QString binaryChar;

    for (int i = 0; i < binaryText.length(); i += 8) {
        binaryChar = binaryText.mid(i, 8);

        if (binaryChar == "00000000") {
            break;
        }

        bool test;
        int tenchar = binaryChar.toInt(&test, 2);
        if (test) {
            QChar ch(tenchar);
            decodedMessage.append(ch);
        }
    }

    return decodedMessage;
qDebug() << "Encoded Message: " << binaryText;
qDebug() << "Decoded Message: " << decodedMessage;
return decodedMessage;
}

QString MainWindow::binaryToMessage(const QString& binaryText)
{
QString message;
QString binaryChar;// хранит 8-битные символы бинарного текста.
for (int i = 0; i < binaryText.length(); i += 8) {
    binaryChar = binaryText.mid(i, 8);//извлечение 8-битного символа бинарного текста
    bool test;
    int tenchar = binaryChar.toInt(&test, 2);
    if (test) {
        QChar ch(tenchar);
        message.append(ch);
    }
}

return message;
}

QString MainWindow::messageToBinary(const QString& message)
{
QString binaryText;


for (int i = 0; i < message.length(); i++) {
    QChar chextraction = message.at(i);//извлечение каждого символа из строки
    QString binaryChar = QString::number(chextraction.unicode(), 2).rightJustified(8, '0');
    binaryText += binaryChar;
}

return binaryText;
}


void MainWindow::on_pushButton_4_clicked()
{
QString filename = QFileDialog::getOpenFileName(this, tr("Выберите изображение"), "", tr("Изображение(*.bmp)"));
if (!filename.isEmpty())
{
QImage image;
bool valid = image.load(filename);
if (valid)
{
   ui->label_3->setPixmap(QPixmap::fromImage(image));

}
}
}
