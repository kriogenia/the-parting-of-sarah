#pragma once

#include "Actor.h"

class State
{
public:
	virtual ~State() {}
	virtual void update(Actor& actor) {}
};

