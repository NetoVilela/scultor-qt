#ifndef COLOR_PICKER_H
#define COLOR_PICKER_H

#include <QWidget>
/**
 * @brief The ColorDraw class is responsible for the color swatch in the lower left corner of the window;
 */
class ColorPicker : public QWidget
{
    Q_OBJECT
private:
    /**
     * @brief r stores the value of r for sampling;
     */
    int r;
    /**
     * @brief g stores the value of g for sampling;
     */
    int g;
    /**
     * @brief b stores the value of g for sampling;
     */
    int b;
    /**
     * @brief a stores the value of g for sampling;
     */
    int a;
public:
    explicit ColorPicker(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
signals:

public slots:
    /// Changes the value of r to the value chosen by the user;
    void set_r(int _r);
    /// Changes the value of g to the value chosen by the user;
    void set_g(int _g);
    /// Changes the value of g to the value chosen by the user;
    void set_b(int _b);
    /// Changes the value of g to the value chosen by the user;
    void set_a(int _a);
};

#endif // COLOR_PICKER_H
