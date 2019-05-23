#pragma once

#include <memory>
#include <vector>

class Robot;

// the class must interit "enable_shared_from_this"
// to be able to use shared_from_this function.
class SpaceStation final : public std::enable_shared_from_this <SpaceStation>
{
public:
	SpaceStation();
	SpaceStation(float t_x, float t_y, float t_z);
	SpaceStation(const std::shared_ptr<SpaceStation> t_station);
	virtual ~SpaceStation();

	std::shared_ptr<SpaceStation> operator = (const std::shared_ptr<SpaceStation> t_station);

	void init();
	void init(int t_size);

	void addRobot(int t_number);
	void printStatus() const;
	std::weak_ptr<Robot> getRobot(int t_index) const;

	int getAllRbots() const;

private:
	float m_x;
	float m_y;
	float m_z;
	std::vector<std::shared_ptr<Robot>> m_robots;
};