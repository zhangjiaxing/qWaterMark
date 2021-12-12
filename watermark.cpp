#include "watermark.h"

#include <QtWidgets>

WaterMarkWidget::WaterMarkWidget(QString text, QWidget *parent)
    : QWidget(parent)
{
        setAttribute(Qt::WA_TransparentForMouseEvents,true);
        setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::Tool);
        setAttribute(Qt::WA_TranslucentBackground);

        QGridLayout *gbox = new QGridLayout(this);
        gbox->setSpacing(0);
        gbox->setMargin(0);
        this->setLayout(gbox);

        QPalette pa;
        pa.setColor(QPalette::WindowText, Qt::gray);

        QFont font;
        font.setPointSize(30);

        for(int row=0; row<6; row++){
            for(int column=0; column<5; column++){
                QLabel *label = new QLabel(text);
                label->setPalette(pa);
                label->setFont(font);
                label->setAttribute(Qt::WA_TranslucentBackground);

                QPixmap pixmap = label->grab();
                QMatrix matrix;
                matrix.rotate(30);
                pixmap = pixmap.transformed(matrix, Qt::SmoothTransformation);
                label->setPixmap(pixmap);

                gbox->addWidget(label, row, column);
            }
        }
        QSize size = QGuiApplication::primaryScreen()->size();
        this->setMinimumSize(size);
        this->setWindowOpacity(0.15);
}

WaterMarkWidget::~WaterMarkWidget()
{
}

