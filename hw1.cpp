#include<iostream>
using namespace std;

class Yacht;
class Port{
	private:
	string name, country, ocean;
	double port_registration_fee;
	
	public:
	Port(string _name, string _country){
		name = _name;
		country = _country;
	}
	
	string getname(){
		return name;
	}

    void setfee(double fee){
	    port_registration_fee = fee;
	}

    string getcountry(){
	    return country;
	}

    string getocean(){
	    return ocean;
	}

    void setocean(string o){
    	ocean = o;
	}

    double getfee(){
    	return port_registration_fee; 
	}

    friend double calculateDailyFee(Port p);
    friend class Yacht;
};


class Yacht{
	private:
	string name, owner, destination_ocean;
	double lenght;
	
	public:
	Yacht(string _name, string _owner, string _destination_ocean, double _lenght){
		name = _name;
		owner = _owner;
		destination_ocean = _destination_ocean;
		lenght = _lenght;
	}
	
	string getname(){
		return name;
	}
	
	string getowner(){
		return owner;
	}
	
	double getlenght(){
		return lenght;
	}
	
	string getdestination(){
		return destination_ocean;
	}
};

double calculateDailyFee(Port p) {
    if (p.ocean == "The Pacific Ocean") 
        p.setfee(450.0);
    else if (p.ocean == "The Indian Ocean") 
        p.setfee(570.0);
    else 
        p.setfee(700.0);
    

    double daily_fee = p.port_registration_fee * 24;
    return daily_fee;
}


int main(){
	Port p("Port of Kisarazu", "Japan");
    p.setocean("The Pacific Ocean");
    Yacht y("Freedom", "Roberto Cavalli", "Pacific Ocean", 33.3);
    
    cout << "Port Registration Fee Details:"<< endl;
    cout << "Yacht name: " << y.getname() << endl;
    cout << "Yacht owner: " << y.getowner() << endl;
    cout << "Yacht lenght: " << y.getlenght()<< endl;
    cout << endl;
    cout << "Destination port's name: " << p.getname() << endl;
    cout << "Destination port's country: " << p.getcountry() << endl;
    cout << "Destination port's ocean: " << p.getocean() << endl;
    cout << "Daily registration fee: $" << calculateDailyFee(p) << endl;     
    
    return 0;
}














