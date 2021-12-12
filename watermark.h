#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class WaterMarkWidget : public QWidget
{
    Q_OBJECT

public:
    WaterMarkWidget(QString text="我是水印", QWidget *parent = nullptr);
    ~WaterMarkWidget();
};
#endif // WIDGET_H
