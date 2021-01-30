#pragma once


class GameObject_Fighter {
protected:
	int x_;
	int y_;
public:
	virtual ~GameObject_Fighter() {}

	virtual void move_up(int y) = 0;
	virtual void move_down(int y) = 0;
	virtual void move_left(int x) = 0;
	virtual void move_right(int x) = 0;

	virtual void attack() = 0;
	virtual void taunt() = 0;

	virtual void reset_position() = 0;


	int Get_Y_Pos() {
		return y_;
	}

	int Get_X_Pos() {
		return x_;
	}


};