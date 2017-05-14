// Lab 6.5.2 by Jeongseop Yi
#include  <iostream>
#include  <string>

using namespace std;

// Engine ///////////////////////////////////////////
class Engine
{
	float liters;
public:
	Engine() {};
	Engine(float liters);
	void print();
};

Engine::Engine(float liters)
{
	this->liters = liters;
}

void Engine::print()
{
	cout << "Engine: " << this->liters << endl;
}


// Wheels ///////////////////////////////////////////
class Wheels
{
	int inches;
public:
	Wheels() {};
	Wheels(int inches);
	void print();
};

Wheels::Wheels(int inches)
{
	this->inches = inches;
}

void Wheels::print()
{
	cout << "Wheel: " << this->inches << "inches" << endl;
}


// Chassis //////////////////////////////////////////
class Chassis
{
	bool status;
public:
	Chassis() {};
	Chassis(bool status);
	void print();
};

Chassis::Chassis(bool status)
{
	this->status = status;
}

void Chassis::print()
{
	cout << "Chassis: ";
	if (this->status) cout << "Normal" << endl;
	else cout << "Faulty" << endl;
}

// Light //////////////////////////////////////////
class Light
{
	int type;
public:
	Light() {};
	Light(int type);
	void print();
};

Light::Light(int type)
{
	this->type = type;
}

void Light::print()
{
	cout << "Light: Type " << type << endl;
}

// Body ///////////////////////////////////////////
class Body
{
	string color;
public:
	Body() {};
	Body(string color);
	void print();
};

Body::Body(string color)
{
	this->color = color;
}

void Body::print()
{
	cout << "Body: " << color << endl;
}

// Car ////////////////////////////////////////////
class Car
{
private:
	Engine* engine;
	Wheels* wheels[4];
	Chassis* chassis;
	Light* light[10];
	Body* body;
public:
	Car(float liters, int inches, string color);
	void print();
};

Car::Car(float liters, int inches, string color)
{
	this->engine = new Engine(liters);
	for (int i = 0; i < 4; i++)
	{
		this->wheels[i] = new Wheels(inches);
	}
	for (int i = 0; i < 10; i++)
	{
		this->light[i] = new Light(i / 2);
	}
	this->chassis = new Chassis(true);
	this->body = new Body(color);
}

void Car::print()
{
	this->engine->print();
	for (int i = 0; i < 4; i++)
	{
		this->wheels[i]->print();
	}
	this->chassis->print();
	for (int i = 0; i < 10; i++)
	{
		this->light[i]->print();
	}
	this->body->print();
}

int main()
{
	Car car(1.0, 16, "black");
	car.print();
}
