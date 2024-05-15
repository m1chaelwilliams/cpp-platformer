// simple ui system

#ifndef UI_H
#define UI_H

#include <raylib.h>
#include <memory>
#include <string>

// abstract class for widgets that handles state
class Widget {
    public:

    bool hovered, clicked, held, disabled;
    Rectangle hitbox;

    Widget(
        Rectangle hitbox
    ) :
        hitbox(hitbox),
        hovered(false),
        clicked(false),
        held(false),
        disabled(false)
    {}

    virtual void update(Vector2 mouse_pos, bool mouse_clicked, bool mouse_held) {

        if (disabled) {
            return;
        }

        if (CheckCollisionPointRec(mouse_pos, hitbox)) {
            hovered = true;

            if (mouse_clicked) {
                clicked = true;
            }

            held = mouse_held;

        } else {
            clicked = false;
            held = false;
        }

    }

    virtual void draw() const = 0;

};

class TextButton : public Widget {

    public:

    std::string msg;

    TextButton(const std::string& msg) :
        msg(msg),
        Widget(Rectangle{0,0,(float)MeasureText(msg.c_str(), 20),20})
    {}

    void draw() const override {
        DrawRectangleLinesEx(
            hitbox,
            2,
            RAYWHITE
        );

        DrawText(
            msg.c_str(),
            hitbox.x,
            hitbox.y,
            20,
            RAYWHITE
        );
    }

};

#endif