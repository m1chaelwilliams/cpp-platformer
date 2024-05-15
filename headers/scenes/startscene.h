#ifndef STARTSCENE_H
#define STARTSCENE_H

#include "scenes/basescene.h"
#include "scenes/sceneids.h"
#include "entities/prelude.h"
#include "ui/ui.h"

#include <memory>
#include <map>
#include <string>
#include <iostream>

class StartScene : public BaseScene {

    public:
    
    enum UIButtonIDs {
        START,
        OPTIONS,
        EXIT
    };

    std::unique_ptr<Player> player;
    std::map<UIButtonIDs, TextButton> ui_msgs; // key: id, value: display msg

    StartScene();
    virtual ~StartScene() override = default;
    
    void update() override;
    void draw() override;
    void enter(int sender_uid) override;

};

#endif