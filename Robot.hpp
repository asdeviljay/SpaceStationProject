#pragma once

#include <memory>
#include "SpaceStation.hpp"

class Robot
{
public:
	Robot();
	virtual ~Robot();

	void talk() const;
	void checkSpaceStation() const;
	void setStation(std::weak_ptr<SpaceStation> t_station);


private:
	float m_x;
	float m_y;
	float m_z;

	std::weak_ptr<SpaceStation> m_station;
};