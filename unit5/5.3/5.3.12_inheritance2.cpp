// Lab 5.3.12 Inheritance basics: part1
#include <iostream>
#include <string>

using namespace std;

class FarmAnimal
{
public:
	FarmAnimal(double water_consumption);
	double getWaterConsumption();
private:
	double water_consumption;
};

class Sheep : public FarmAnimal
{
public:
	Sheep(double weight);
};

class Cow : public FarmAnimal
{
public:
	Cow(double weight);
};

class Horse : public FarmAnimal
{
public:
	Horse(double weight);
};

// FarmAnimal initializer
FarmAnimal::FarmAnimal(double water_consumption)
{
	this->water_consumption = water_consumption;
}

// FarmAnimal get methods
double FarmAnimal::getWaterConsumption()
{
	return this->water_consumption;
}

// sheep init
Sheep::Sheep(double weight) : FarmAnimal(weight/10*1.1)
{
}

// Cow init
Cow::Cow(double weight) : FarmAnimal(weight/100*8.6)
{
}

// Horse init
Horse::Horse(double weight) : FarmAnimal(weight/100*6.8)
{
}

// ConsumptionAccumulator
class ConsumptionAccumulator
{
public:
	ConsumptionAccumulator();
	double getTotalconsumption();
	void addConsumption(FarmAnimal);
private:
	double total_consumption;
};

ConsumptionAccumulator::ConsumptionAccumulator()
	: total_consumption(0)
{
}

double ConsumptionAccumulator::getTotalconsumption()
{
	return this->total_consumption;
}

void ConsumptionAccumulator::addConsumption(FarmAnimal animal)
{
	this->total_consumption += animal.getWaterConsumption();
}


int main()
{
	ConsumptionAccumulator accumulator;

	string line;
	while (getline(cin, line))
	{
		if (line.empty())
		{
			break;
		}
		if (line.find("cow") != std::string::npos)
		{
			int weight = stoi(line.substr(4));
			Cow cow(weight);
			accumulator.addConsumption(cow);
		}
		else if (line.find("sheep") != std::string::npos)
		{
			int weight = stoi(line.substr(6));
			Sheep sheep(weight);
			accumulator.addConsumption(sheep);
		}
		else if (line.find("horse") != std::string::npos)
		{
			int weight = stoi(line.substr(6));
			Horse horse(weight);
			accumulator.addConsumption(horse);
		}
	}

	cout << "Total water consumption: " << accumulator.getTotalconsumption() << " liters." << endl;
}
