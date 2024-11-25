#pragma once

#include <stdlib.h>
#include "picosystem.hpp"
#include "./Player.cpp"
#include "./Message.cpp"

using namespace picosystem;

class NPCs {
    public:
        NPCs(Player* p, Message* m, Vector& camera);
        ~NPCs();

        void update(uint32_t tick);
        void draw(uint32_t tick);

    private:
        Player* player;
        Message* message;
        Vector& cam;
        std::vector<NPC> npcs;
};

NPCs::NPCs(Player* p, Message* m, Vector& camera) : cam(camera)  {
    player = p;
    message = m;

    //square
    npcs.push_back({{428, 172}, 10, DIR_DOWN, "Jill: Boo!\nI'm a ghost!\nYou: very scary!"});
    npcs.push_back({{428, 172}, 2, DIR_DOWN, "You: I'm looking\nfor the missing\nkids.\n\nMayor Ashford:\nMissing?\nNonsense. They're\nprobably playing a\nprank. Nothing to\nworry about.\nYou: This isn't a\nprank. I'm going\nto find out what's\ngoing on. \nMayor Ashford:\n(Lowers his voice)\nBe careful...\nThere are things\nyou don't\nunderstand. The\ndisappearances…\nthey've happened\nbefore.\n\n(Hmmm so the\ndisappearances are\na repeating\noccurrence)"});
    npcs.push_back({{444, 284}, 7, DIR_LEFT, "Austin: I love\nhalloween!\nYou: Have you\nheard about the\nmissing kids?\n\nAustin: Nope! But\nthe Library might\nbe a good start."});
    npcs.push_back({{348, 236}, 8, DIR_RIGHT, "Zoe: This town is\nlovely!\nYou: Have you\nheard about the\nmissing kids?\n\nZoe: Nope! But the\nLibrary might\nbe a good start."});
    npcs.push_back({{380, 268}, 9, DIR_DOWN, "Tim: Tick or Treat!\nYou: what a great\ncostume!"});
    npcs.push_back({{444, 204}, 10, DIR_UP, "Jake: Boo!\nI'm a ghost!\nYou: very scary!"});

    // manor
    npcs.push_back({{668, 44}, 5, DIR_DOWN, "Butler: Ashford\nManor is\nclosed tonight.\nThe mayor is busy\nwith the festival.\nI can't let you in\nwithout a reason."});
    npcs.push_back({{1052, 492}, 2, DIR_DOWN, "You: I've found\nyour contract!\nI know you're\nresponsible for\nthe missing\nchildren!\nMayor Ashford: Oh?\nyou're too late!\nCedric already\nbrought the\nkids to the\nalter. He's just\nwaiting for me\nto give him the\ncode word.\nwhich i've ripped up!"});
    

    // graveyard
    npcs.push_back({{252, 620}, 3, DIR_LEFT, "Cedric: Sorry\nthe graveyard\nis closed."});
    
    //town
    npcs.push_back({{156, 572}, 0, DIR_UP, "The Library"});
    npcs.push_back({{540, 156}, 0, DIR_UP, "Cedric's House"});
    npcs.push_back({{556, 364}, 0, DIR_UP, "Eleanor's House"});
    npcs.push_back({{268, 316}, 0, DIR_UP, "Zoe's House"});
    npcs.push_back({{172, 92}, 0, DIR_UP, "Ashford Manor"});

    // library
    npcs.push_back({{1340, 220}, 4, DIR_DOWN, "Miss Elanor: How\ncan I help you?\nYou: I'm\ninvestigating\nthe missing\nkids. Have you\nseen them?\n\nMiss Elanor: No\nBut maybe\nyou can find\nsome helpful info\non the shelves.\n\nYou: thanks!"});
    npcs.push_back({{1276, 220}, 0, DIR_UP, "Lots of books\nbut nothing to\nhelp with my\ninvestigation."});
    npcs.push_back({{1292, 220}, 0, DIR_UP, "Lots of books\nbut nothing to\nhelp with my\ninvestigation."});
    npcs.push_back({{1308, 220}, 0, DIR_UP, "Lots of books\nbut nothing to\nhelp with my\ninvestigation."});
    npcs.push_back({{1324, 220}, 0, DIR_UP, "Lots of books\nbut nothing to\nhelp with my\ninvestigation."});

    npcs.push_back({{1372, 220}, 0, DIR_UP, "Lots of books\nbut nothing to\nhelp with my\ninvestigation."});
    npcs.push_back({{1388, 220}, 0, DIR_UP, "Lots of books\nbut nothing to\nhelp with my\ninvestigation."});
    npcs.push_back({{1420, 220}, 0, DIR_UP, "Lots of books\nbut nothing to\nhelp with my\ninvestigation."});

    npcs.push_back({{1276, 268}, 0, DIR_UP, "Lots of books\nbut nothing to\nhelp with my\ninvestigation."});
    npcs.push_back({{1292, 268}, 0, DIR_UP, "Lots of books\nbut nothing to\nhelp with my\ninvestigation."});
    npcs.push_back({{1308, 268}, 0, DIR_UP, "Lots of books\nbut nothing to\nhelp with my\ninvestigation."});
    npcs.push_back({{1324, 268}, 0, DIR_UP, "Lots of books\nbut nothing to\nhelp with my\ninvestigation."});

    npcs.push_back({{1372, 268}, 0, DIR_UP, "Lots of books\nbut nothing to\nhelp with my\ninvestigation."});
    npcs.push_back({{1388, 268}, 0, DIR_UP, "Lots of books\nbut nothing to\nhelp with my\ninvestigation."});
    npcs.push_back({{1404, 268}, 0, DIR_UP, "Lots of books\nbut nothing to\nhelp with my\ninvestigation."});
    npcs.push_back({{1420, 268}, 0, DIR_UP, "Lots of books\nbut nothing to\nhelp with my\ninvestigation."});

    npcs.push_back({{1404, 220}, 0, DIR_UP, "These are town\nrecords!\nand it looks like\nthere's a photo\non the back.\nBut it's been\nripped up.\nlet me try\nand fix it."});

    //graveyard tomb
    npcs.push_back({{1420, 428}, 0, DIR_DOWN, "You: It's a mask.\nI can feel it's\ndemonic power.\nThis must be\nwhat gives mayor\nAshford\nimmortality!\n\n*You SMASH the mask*\n\nIn the distance\nthe mayor screams."});

    //extras
    npcs.push_back({{1084, 60}, 0, DIR_UP, "The secret lives\nof mormon wives\nis playing."});
    npcs.push_back({{1100, 60}, 0, DIR_UP, "The secret lives\nof mormon wives\nis playing."});
    npcs.push_back({{1100, 76}, 4, DIR_UP, "Kate: I love\nthis show!"});

    npcs.push_back({{1276, 28}, 0, DIR_UP, "Malcolm in\nthe middle\nis playing."});
    npcs.push_back({{1292, 28}, 0, DIR_UP, "Malcolm in\nthe middle\nis playing."});
    npcs.push_back({{1372, 60}, 7, DIR_UP, "Jared: Hello!"});

    npcs.push_back({{1100, 220}, 0, DIR_UP, "Lost\nis playing."});
    npcs.push_back({{1116, 220}, 0, DIR_UP, "Lost\nis playing."});

    npcs.push_back({{972, 492}, 0, DIR_UP, "the 4400\nis playing."});
    npcs.push_back({{988, 492}, 0, DIR_UP, "the 4400\nis playing."});


    npcs.push_back({{540, 540}, 0, DIR_UP, "a grave."});
    npcs.push_back({{540, 572}, 0, DIR_UP, "a grave."});
    npcs.push_back({{540, 604}, 0, DIR_UP, "a grave."});
    npcs.push_back({{540, 636}, 0, DIR_UP, "a grave."});
    npcs.push_back({{540, 668}, 0, DIR_UP, "a grave."});

    npcs.push_back({{572, 604}, 0, DIR_UP, "a grave."});
    npcs.push_back({{572, 636}, 0, DIR_UP, "a grave."});
    npcs.push_back({{572, 668}, 0, DIR_UP, "a grave."});

    npcs.push_back({{604, 604}, 0, DIR_UP, "a grave."});
    npcs.push_back({{604, 636}, 0, DIR_UP, "a grave."});
    npcs.push_back({{604, 668}, 0, DIR_UP, "a grave."});

    npcs.push_back({{636, 604}, 0, DIR_UP, "a grave."});
    npcs.push_back({{636, 636}, 0, DIR_UP, "a grave."});
    npcs.push_back({{636, 668}, 0, DIR_UP, "a grave."});

    npcs.push_back({{668, 540}, 0, DIR_UP, "a grave."});
    npcs.push_back({{668, 572}, 0, DIR_UP, "a grave."});
    npcs.push_back({{668, 604}, 0, DIR_UP, "a grave."});
    npcs.push_back({{668, 636}, 0, DIR_UP, "a grave."});
    npcs.push_back({{668, 668}, 0, DIR_UP, "a grave."});





    npcs.push_back({{1356, 604}, 0, DIR_UP, "a child's grave."});
    npcs.push_back({{1388, 604}, 0, DIR_UP, "a child's grave."});
    npcs.push_back({{1420, 604}, 0, DIR_UP, "a child's grave."});
    npcs.push_back({{1356, 636}, 0, DIR_UP, "a child's grave."});
    npcs.push_back({{1388, 636}, 0, DIR_UP, "a child's grave."});
    npcs.push_back({{1420, 636}, 0, DIR_UP, "a child's grave."});


    npcs.push_back({{1404, 444}, 7, DIR_RIGHT, "Help us!\nDestroy the mask!"});
    npcs.push_back({{1436, 444}, 8, DIR_LEFT, "Help us!\nDestroy the mask!"});
}

NPCs::~NPCs() {
    std::vector<NPC>().swap(npcs);
}

void NPCs::update(uint32_t tick) {
    if (pressed(A)) {
        for (int32_t i = 0; i < npcs.size(); i++) { 
            if(player->isFacing(npcs[i].pos.x, npcs[i].pos.y)) {
                if (((i != 1 && i != 6) || !manorUnlocked) && (i != 7 && i != 8 || !graveyardUnlocked)) {
                    message->add(npcs[i].message);
                    if (npcs[i].pos.x > cam.x) {
                        npcs[i].dir = DIR_LEFT;
                    }
                    if (npcs[i].pos.x < cam.x) {
                        npcs[i].dir = DIR_RIGHT;
                    }
                    if (npcs[i].pos.y > cam.y) {
                        npcs[i].dir = DIR_UP;
                    }
                    if (npcs[i].pos.y < cam.y) {
                        npcs[i].dir = DIR_DOWN;
                    }
                }
            }
        }
    }
}

void NPCs::draw(uint32_t tick) {
    for (int32_t i = 0; i < npcs.size(); i++) { 
        if(abs(cam.x - npcs[i].pos.x) <= 52 && abs(cam.y - npcs[i].pos.y) <= 52) {
            int32_t frame = 4;
            switch (npcs[i].dir) {
                case DIR_UP:
                    frame = 4;
                    break;
                case DIR_DOWN:
                    frame = 1;
                    break;
                case DIR_LEFT:
                    frame = 7;
                    break;
                case DIR_RIGHT:
                    frame = 10;
                    break;
            }

            if (npcs[i].overworld > 0) {
                if (((i != 1 && i != 6) || !manorUnlocked) && (i != 7 && i != 8 || !graveyardUnlocked)) {
                    buffer_t *sprite = get_overworld(npcs[i].overworld);
                    bblit(sprite, frame * 16, 0, 16, 16, (npcs[i].pos.x - cam.x) + 52, (npcs[i].pos.y - cam.y) + 52);
                    delete sprite;
                }
            }
        }
    }
}