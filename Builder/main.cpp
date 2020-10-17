// Builder Design Pattern
// Creates constructed class objects of custom truck instances (that I had a little too much fun making :)

#include <iostream>
using namespace std;

// CustomTruck end class instance
class CustomTruck
{
	string _name;
	string _description;
	string _engine;
	string _wheels;
	string _suspension;
	string _drive;

public:

	CustomTruck(string _sname)
	{
		_name = _sname;
	}

	void SetDescription(string _sdescription)
	{
		_description = _sdescription;
	}

	void SetEngine(string _sengine)
	{
		_engine = _sengine;
	}
	
	void SetWheels(string _swheels)
	{
		_wheels = _swheels;
	}

	void SetSuspension(string _ssuspension)
	{
		_suspension = _ssuspension;
	}

	void SetDrive(string _sdrive)
	{
		_drive = _sdrive;
	}

	void display()
	{
		cout << "************" << endl;
		cout << "Name:\t\t" << _name << endl;
		cout << "Description:\t" << _description << endl;
		cout << "Engine:\t\t" << _engine << endl;
		cout << "Wheels:\t\t" << _wheels << endl;
		cout << "Suspension:\t" << _suspension << endl;
		cout << "Drive:\t\t" << _drive << endl;
	}
};

// CustomTruckBuilder Abstract Class: all builders contain these methods
class CustomTruckBuilder
{
protected:
	CustomTruck* _customtruck;
public:
	virtual void BuildName() = 0;
	virtual void BuildDescription() = 0;
	virtual void BuildEngine() = 0;
	virtual void BuildWheels() = 0;
	virtual void BuildSuspension() = 0;
	virtual void BuildDrive() = 0;

	CustomTruck* GetCustomTruck()
	{
		return _customtruck;
	}
};

// Concrete classes for building each CustomTruck type

class BackWoodsBuilder : public CustomTruckBuilder
{

public:
	void BuildName() override
	{
		_customtruck = new CustomTruck("Backwoods Buster");
	}
	
	void BuildDescription() override
	{
		_customtruck->SetDescription(
			"A backwoods bustin' quad cab with dual smokestacks and twin flag holders good for\n"
			"\t\t\tbringing 'tears to the eyes' of those against your environmental and political beliefs.");
	}

	void BuildEngine() override
	{
		_customtruck->SetEngine("V12 7.2L Twin Turbo Diesel 1000hp");
	}

	void BuildWheels() override
	{
		_customtruck->SetWheels("22 in. Chrome with 40 in. Monster Mudders");
	}

	void BuildSuspension() override
	{
		_customtruck->SetSuspension("20 in. Lift Kit");
	}

	void BuildDrive() override
	{
		_customtruck->SetDrive("4WD");
	}
};

class PavementScraperBuilder : public CustomTruckBuilder
{
public:
	void BuildName() override
	{
		_customtruck = new CustomTruck("Pavement Scraper");
	}
	
	void BuildDescription() override
	{
		_customtruck->SetDescription(
			"A street pavement scrapin' extended cab that's dropped for urban cruising and\n"
			"\t\t\tavoiding speed bumps. Complete with a 5000 watt bass system to let everyone know\n"
			"\t\t\tyour coming from 10 miles away.");
	}

	void BuildEngine() override
	{
		_customtruck->SetEngine("V8 6.0L Gasoline 300hp Naturally Aspirated");
	}

	void BuildWheels() override
	{
		_customtruck->SetWheels("24 in. Alloy with Low Profile Tires");
	}

	void BuildSuspension() override
	{
		_customtruck->SetSuspension("Drop Kit");
	}

	void BuildDrive() override
	{
		_customtruck->SetDrive("2WD");
	}
};

class UrbanHotrodBuilder : public CustomTruckBuilder
{
public:
	void BuildName() override
	{
		_customtruck = new CustomTruck("Urban Hotrod");
	}
	
	void BuildDescription() override
	{
		_customtruck->SetDescription(
			"A city hotroddin' very fast single cab good for sucking points off your license\n"
			"\t\t\tfaster than that Vette you schooled back at that stop light.");
	}

	void BuildEngine() override
	{
		_customtruck->SetEngine("V8 6.0L Gasoline Supercharged 900hp");
	}

	void BuildWheels() override
	{
		_customtruck->SetWheels("18 in. Alloy with \"Street Legal\" Slicks");
	}

	void BuildSuspension() override
	{
		_customtruck->SetSuspension("Lowered and Tubbed Kit");
	}

	void BuildDrive() override
	{
		_customtruck->SetDrive("2WD");
	}
};

class StockOpinionatorBuilder : public CustomTruckBuilder
{
public:
	void BuildName() override
	{
		_customtruck = new CustomTruck("Stock Opinionator");
	}
	
	void BuildDescription() override
	{
		_customtruck->SetDescription(
			"A single cab special for that person who enjoys expressing their views to everyone.\n"
			"\t\t\tComplete with an extra sized camper shell, tailgate and bumpers for covering with\n"
			"\t\t\tdecals that express your multitudes of opinions and beliefs. Extra underpowered and slow\n"
			"\t\t\tso whomever's stuck behind you in traffic has ample time to read your conspiracies.");
	}

	void BuildEngine() override
	{
		_customtruck->SetEngine("V4 2.3L Diesel 90hp");
	}

	void BuildWheels() override
	{
		_customtruck->SetWheels("16 in. Steel with Stock tires");
	}

	void BuildSuspension() override
	{
		_customtruck->SetSuspension("Extra Heavy Duty Suspension");
	}

	void BuildDrive() override
	{
		_customtruck->SetDrive("4WD");
	}
};

// Director class controls order of steps performed per instance
class Director
{
	CustomTruckBuilder* builder;

public:

	CustomTruck* CreateCustomTruck(CustomTruckBuilder* builder)
	{
		builder->BuildName();
		builder->BuildDescription();
		builder->BuildEngine();
		builder->BuildWheels();
		builder->BuildSuspension();
		builder->BuildDrive();
		return builder->GetCustomTruck();
	}
};

int main()
{
	Director dir;
	
	BackWoodsBuilder bwb;
	CustomTruck* backwoods = dir.CreateCustomTruck(&bwb);
	backwoods->display();
	delete backwoods;

	PavementScraperBuilder csb;
	CustomTruck* pavementscraper = dir.CreateCustomTruck(&csb);
	pavementscraper->display();
	delete pavementscraper;

	UrbanHotrodBuilder uhb;
	CustomTruck* urbanhotrod = dir.CreateCustomTruck(&uhb);
	urbanhotrod->display();
	delete urbanhotrod;

	StockOpinionatorBuilder sob;
	CustomTruck* stockopinionatorbuilder = dir.CreateCustomTruck(&sob);
	stockopinionatorbuilder->display();
	delete stockopinionatorbuilder;
	
	return 0;
}
