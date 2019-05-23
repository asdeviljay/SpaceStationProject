#include "pch.h"
#include "SpaceStation.hpp"

#include <iostream>
#include "Robot.hpp"

SpaceStation::SpaceStation() :
	m_x(0), m_y(0), m_z(0)
{
}

SpaceStation::SpaceStation(float t_x, float t_y, float t_z) :
	m_x(t_x), m_y(t_y), m_z(t_z)
{
}

SpaceStation::SpaceStation(const std::shared_ptr<SpaceStation> t_station) :
	m_x(t_station->m_x), m_y(t_station->m_y), m_z(t_station->m_z), m_robots(t_station->m_robots)
{
}

SpaceStation::~SpaceStation()
{
}

std::shared_ptr<SpaceStation> SpaceStation::operator = (const std::shared_ptr<SpaceStation> t_station)
{
	m_x = t_station->m_x;
	m_y = t_station->m_y;
	m_z = t_station->m_z;
	m_robots = t_station->m_robots;
	return shared_from_this();
}

void SpaceStation::init()
{
	m_robots.clear();
	m_robots.push_back(std::make_shared<Robot>());
	// shared_from_this requires the object to exist, so
	// it cannot use within intializer.
	m_robots.at(0)->setStation(shared_from_this());
}

void SpaceStation::init(int t_size) 
{
	m_robots.clear();
	for (int i = 0; i < t_size; i++) {
		m_robots.push_back(std::make_shared<Robot>());
	}
	// shared_from_this requires the object to exist, so
	// it cannot use within intializer.
	for (int i = 0; i < m_robots.size(); i++) {
		m_robots.at(i)->setStation(shared_from_this());
	}
}

void SpaceStation::addRobot(int t_number)
{
	for (int i = 0; i < t_number; i++) {
		m_robots.push_back(std::make_shared<Robot>());
	}
	for (int i = 0; i < m_robots.size(); i++) {
		m_robots.at(i)->setStation(shared_from_this());
	}
}

void SpaceStation::printStatus() const
{
	std::cout << "x " << m_x << ", y " << m_y << ", z " << m_z << std::endl;
}

std::weak_ptr<Robot> SpaceStation::getRobot(int t_index) const
{
	return m_robots.at(t_index);
}

int SpaceStation::getAllRbots() const {
	return m_robots.size();
}