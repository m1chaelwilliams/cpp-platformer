#include "scenes/startscene.h"

StartScene::StartScene() :
    BaseScene(SceneIDs::START)
{
    ui_msgs = std::map<UIButtonIDs, TextButton> {
        {
            UIButtonIDs::OPTIONS, 
            TextButton("Start")
        }
    };

    player = std::make_unique<Player>();
}


void StartScene::update() {

    Vector2 mouse_delta = GetMouseDelta();
    bool mouse_clicked = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
    bool mouse_released = IsMouseButtonReleased(MOUSE_BUTTON_LEFT);
    bool mouse_held = IsMouseButtonDown(MOUSE_BUTTON_LEFT);

    if (mouse_clicked || mouse_released || mouse_delta.x || mouse_delta.y) {

        Vector2 mouse_pos = GetMousePosition();

        for (auto& btn : ui_msgs) {
            btn.second.update(mouse_pos, mouse_clicked, mouse_held);
        }

    }

}

void StartScene::draw() {

    ClearBackground(BLACK);

    for (const auto& btn : ui_msgs) {

        btn.second.draw();

    }

}

void StartScene::enter(int sender_uid) {

}