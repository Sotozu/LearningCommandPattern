#pragma once


class GameObject_Fighter {

public:
	virtual ~GameObject_Fighter() {}

	virtual void jump() = 0;
	virtual void attack() = 0;
	virtual void taunt() = 0;

};