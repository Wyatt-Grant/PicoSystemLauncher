#pragma once

#include "picosystem.hpp"
#include "../../helpers/Drawing.cpp"
#include "../../globals/Basic.cpp"
#include "./Puzzle1.h"
#include "./Puzzle2.h"
#include "./GameOver.h"

using namespace picosystem;

class Message {
    public:
        std::string content;
        std::string visibleContent;

        Message();
        void update(uint32_t tick);
        void draw(uint32_t tick);
        bool isBusy();
        void add(std::string s);
        void addCallback(void (*cb)());

    private:
        int32_t animatedCursor;
        void calcVisibleContent();
        void calcContent();
        bool loadPuzzleSceneOnend;
        bool loadPuzzle2SceneOnend;
        bool loadGameOverSceneOnend;
};

Message::Message() {
    content = "";
    animatedCursor = 0;
    loadPuzzleSceneOnend = false;
    loadPuzzle2SceneOnend = false;
    loadGameOverSceneOnend = false;
}

void Message::calcVisibleContent() {
    int32_t first = -1;
    int32_t second = content.size();
    for (int i = 0; i < content.size(); i++) {
        if (content[i] == '\n') {
            if (first == -1) {
                first = i;
            } else if (second == content.size()) {
                second = i;
                break;
            }
        }
    }

    visibleContent = content.substr(0, second);
}

void Message::calcContent() {
    int32_t first = -1;
    int32_t second = content.size();
    for (int i = 0; i < content.size(); i++) {
        if (content[i] == '\n') {
            if (first == -1) {
                first = i;
            } else if (second == content.size()) {
                second = i;
                break;
            }
        }
    }

    animatedCursor = 0;
    if (second == content.size()) {
        content = "";
        if (loadPuzzleSceneOnend) {
            nextScene = new Puzzle1();
        }
        if (loadPuzzle2SceneOnend) {
            nextScene = new Puzzle2();
        }
        if (loadGameOverSceneOnend) {
            nextScene = new GameOver();
        }
    } else {
        content = content.substr(second+1, content.size());
    }
}

bool Message::isBusy() {
    return content.size() != 0;
}

void Message::add(std::string s) {
     if (s.find("These are town\nrecords!") != std::string::npos) {
        loadPuzzleSceneOnend = true;
    }
    if (s.find("You: I've found") != std::string::npos) {
        loadPuzzle2SceneOnend = true;
    }
    if (s.find("You: It's a mask.") != std::string::npos) {
        loadGameOverSceneOnend = true;
    }
    content = s;
    animatedCursor = 0;
    calcVisibleContent();
}

void Message::update(uint32_t tick) {
    if ((pressed(A) || pressed(B)) && animatedCursor > 0) {
        if (animatedCursor == visibleContent.size()) {
            calcContent();
            calcVisibleContent();
        } else {
            animatedCursor = visibleContent.size();
        }
    }

    if (animatedCursor < visibleContent.size()) {
        animatedCursor += 1;
    }
}

void Message::draw(uint32_t tick) {
    if (isBusy()) {
        window(0, 97, 120, 23);
        pen(15,15,15);
        text(visibleContent.substr(0, animatedCursor), 6, 101);

        if (animatedCursor == visibleContent.size()) {
            arrow(109, tick % 40 >= 20 ? 112 : 111, D_DOWN);
        }
    }
}