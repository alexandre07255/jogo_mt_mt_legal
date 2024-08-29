#pragma once
#include "Scene.h"
#include "ScoreSave.h"
#include "TextContainer.h"
namespace Scenes {
    class FinalScreen : public Scene
    {
    private:
        ScoreSave* save;
        Entities::TextContainer* text;
        int score;
    public:
        FinalScreen(int _score,bool death);
        void execute();
        void escResolver();
    };
}

