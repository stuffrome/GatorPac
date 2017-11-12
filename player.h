#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsItem>
#include <QPainter>

class Player : public QGraphicsItem
{
public:
    Player(int,int);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    QPixmap forward;

    // Position in pixels
    int posx, posy;
    // Image dimension in pixels
    const int charW, charH;

};

#endif // PLAYER_H
