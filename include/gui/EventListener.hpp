#ifndef __EVENTLISTENER_H
#define __EVENTLISTENER_H

namespace Gui
{
    /**
     * @brief Interface for handling mouse click events
     */
    class IClickListener
    {
    public:
        virtual void handleMouseDown(Point pClickPoint) {}
        virtual void handleMouseUp(Point pClickPoint) {}
    };

    /**
     * @brief Interface for handling keyboard and mouse move events
     */
    class IMoveListener
    {
    public:
        virtual void handleMouseMove(bool right) = 0;
        virtual void keyDownLeft() = 0;
        virtual void keyDownRight() = 0;
    };
}

#endif