#include "pch.h"
#include "Robot.hpp"

#include <iostream>
#include "SpaceStation.hpp"

Robot::Robot()
	: m_x(0), m_y(0), m_z(0)
{
}


Robot::~Robot()
{
}


void Robot::talk() const {
	std::cout << "Peep peep my ID is A";
}


void Robot::checkSpaceStation() const
{
	if (!m_station.expired())
	{
		m_station.lock()->printStatus();
	}
}


void Robot::setStation(std::weak_ptr<SpaceStation> t_station)
{
	m_station = t_station;
}