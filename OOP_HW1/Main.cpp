#include <iostream>
#include <string>
#include <vector>

class People {
public:
	People() :name_("FIO"), age_(0) {}
	People(std::string name,int age):name_(name), age_(age) {}
	~People() {}

	void PeopleInfo(){
		std::cout << "ФИО: " << name_ << std::endl;
		std::cout << "Возраст: " << age_ << std::endl;
		std::cout << std::endl;
	}

private:
	std::string name_;
	int age_;
};

class Flat {
public:
	Flat():Number_(0),RoomNum_(0) {}
	Flat(int Number, int RoomNum):Number_(Number),RoomNum_(RoomNum) {}
	~Flat(){}

	void addPeople(People* obj) {
		LiveP_.push_back(obj); 
	}
	void PrintFlat() {
		std::cout << "Квартира № " << Number_ << std::endl;
		std::cout << "В этой квартире " << RoomNum_ << " комнат(ы)\n\n";
		std::cout << "В этой квартире проживают:\n";
		for (int i = 0; i < LiveP_.size(); i++) {
			LiveP_[i]->PeopleInfo();
		}
	}
	


private:
	std::vector <People*> LiveP_;
	int Number_;
	int RoomNum_;
};

class House {
public:
	House() :HouseNum_(0), FlatCount_(0) {};
	House(int houseN, int FlatCo) :HouseNum_(houseN), FlatCount_(FlatCo) {};
	~House() {};

	void AddFlat(Flat* obj) {
		FlatNumber_.push_back(obj);
		LiveF_++;
	}

	void PrintHouse() {
		std::cout << "Дом №" << HouseNum_ << std::endl;
		std::cout << "В этом доме " << FlatCount_ << " квартир" << std::endl;
		std::cout << "Заселено " << LiveF_ << "\n\n";
		for (int i = 0; i < FlatNumber_.size(); i++) {
			FlatNumber_[i]->PrintFlat();
		}
	}


private:
	int LiveF_ = 0;
	int HouseNum_;
	int FlatCount_;
	std::vector <Flat*> FlatNumber_;
};




int main() {
	setlocale(0, "");

	// Люди
	People P1("Анна А.Б", 21);
	People P2("Александр Б.Х", 25);
	People P3("Николай М.З", 33);
	People P4("Анастасия А.В", 29);
	
	//Квартиры
	Flat F1(112, 3);
	Flat F2(113, 2);
	F1.addPeople(&P1);
	F1.addPeople(&P2);
	F2.addPeople(&P3);
	F2.addPeople(&P4);

	// Дом
	House H1(38, 25);
	H1.AddFlat(&F1);
	H1.AddFlat(&F2);
	H1.PrintHouse();

	return 0;
}