// SpaceStationProject.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include "SpaceStation.hpp"
#include "Robot.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	std::vector<std::shared_ptr<SpaceStation>> spaceStationsFromFile;
	std::ifstream spaceStationFile("SpaceStationSetting.txt");
	std::string readLine;
	while (std::getline(spaceStationFile, readLine))
	{
		std::istringstream iss(readLine);
		float readX = NULL, readY = NULL, readZ = NULL;
		int readSize = NULL;
		
		iss >> readX >> readY >> readZ >> readSize;
		if (iss.eof())
		{
			if (readX != NULL && readY != NULL && readZ != NULL)
			{
				spaceStationsFromFile.push_back(std::make_shared<SpaceStation>(readX, readY, readZ));
				if (readSize != NULL)
				{
					spaceStationsFromFile.at(spaceStationsFromFile.size() - 1)->init(readSize);
				}
				else
				{
					spaceStationsFromFile.at(spaceStationsFromFile.size() - 1)->init();
				}
			}
		}
	}
	spaceStationFile.close();

	std::shared_ptr<SpaceStation> spaceStation = std::make_shared<SpaceStation>();
	spaceStation->init();
	//std::shared_ptr<SpaceStation> spaceStation = spaceStationsFromFile.at(0);

	std::cout << "0. ";
	spaceStation->printStatus();
	{
		// Use copy constructor
		//std::shared_ptr<SpaceStation> spaceStation1 = std::make_shared<SpaceStation>(spaceStation);

		// Use operator overloading
		std::shared_ptr<SpaceStation> spaceStation1 = std::make_shared<SpaceStation>();
		spaceStation1->operator= (spaceStation);

		spaceStation1->init(20);

		// Test that they are copy or not
		/*for (int i = 0; i < spaceStation1->getAllRbots(); i++) {
			auto aRobot = spaceStation1->getRobot(i);
			if (!aRobot.expired())
			{
				aRobot.lock()->checkSpaceStation();
			}
		}*/

		//Use operator from standard library
		//std::shared_ptr<SpaceStation> spaceStation2 = spaceStation;
		std::shared_ptr<SpaceStation> spaceStation2 = std::make_shared<SpaceStation>();
		spaceStation2 = spaceStation;
		//spaceStation2->init(10);
		//spaceStation2->addRobot(10);
	}

	for (int i = 0 ; i < spaceStationsFromFile.size() ; i++)
	{
		auto spaceStationVec = spaceStationsFromFile.at(i);
		for (int j = 0; j < spaceStationVec->getAllRbots(); j++) {
			auto aRobot = spaceStationVec->getRobot(j);
			if (!aRobot.expired())
			{
				std::cout << j + 1 << ". ";
				aRobot.lock()->checkSpaceStation();
			}
		}
	}
}