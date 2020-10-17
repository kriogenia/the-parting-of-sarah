#pragma once

#include "Background.h"
#include "Layer.h"

class LevelLayer :
    public Layer {
public:
	LevelLayer(Game* game);
	~LevelLayer();

	void init() override;
	void update() override;
	void draw() override;

	Background* background;
};

