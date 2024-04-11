#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Vehicle {
private:
    string id;
    string name;
    double price;
public:
    Vehicle(string id, string name, double price) : id(id), name(name), price(price) {}

    string getId() const { return id; }
    string getName() const { return name; }
    double getPrice() const { return price; }

    void setPrice(double newPrice) { price = newPrice; }

    void display() const {
        cout << "ID: " << id << ", Name: " << name << ", Price: $" << price << endl;
    }
};

class Showroom {
private:
    vector<Vehicle> vehicles;
public:
    void addVehicle(const Vehicle& vehicle) {
        vehicles.push_back(vehicle);
    }

    void showVehicles() const {
        for (const auto& vehicle : vehicles) {
            vehicle.display();
        }
    }

    const Vehicle* getVehicleById(const string& id) const {
     
    }

    const Vehicle* getVehicleByName(const string& name) const {
        for (const auto& vehicle : vehicles) {
            if (vehicle.getName() == name) {
                return &vehicle;
            }
        }
        return nullptr;
    }

    void modifyVehicle(const string& id, double newPrice) {
      
    }

    void removeVehicle(const string& id) {
      
    }

    void showVehiclePrice(const string& id) const {
     
    }

    void saveToFile(const string& filename) const {
      
    }

    void loadFromFile(const string& filename) {
        ifstream file(filename);
        if (file.is_open()) {
            vehicles.clear(); // Clear existing data
            string line;
            while (getline(file, line)) {
                string id, name;
                double price;
                stringstream ss(line);
                getline(ss, id, ',');
                getline(ss, name, ',');
                ss >> price;
                addVehicle(Vehicle(id, name, price));
            }
            cout << "Data loaded from file successfully." << endl;
        } else {
            cout << "Unable to open file for reading. Starting with empty showroom." << endl;
        }
    }
};

int main() {
    Showroom showroom;
    showroom.loadFromFile("vehicles.txt");

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Add Vehicle\n";
        cout << "2. Show Vehicles\n";
        cout << "3. Get Vehicle by ID\n";
        cout << "4. Get Vehicle by Name\n";
        cout << "5. Modify Vehicle\n";
        cout << "6. Remove Vehicle\n";
        cout << "7. Show Vehicle Price\n";
        cout << "8. Save Data to File\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string id, name;
                double price;
                cout << "Enter vehicle ID: ";
                cin >> id;
                cout << "Enter vehicle name: ";
                cin >> name;
                cout << "Enter vehicle price: ";
                cin >> price;
                showroom.addVehicle(Vehicle(id, name, price));
                break;
            }
            case 2:
                showroom.showVehicles();
                break;
            case 3: {
                string id;
                cout << "Enter vehicle ID: ";
                cin >> id;
                const Vehicle* vehicle = showroom.getVehicleById(id);
                if (vehicle) {
                    vehicle->display();
                } else {
                    cout << "Vehicle not found." << endl;
                }
                break;
            }
            case 4: {
                string name;
                cout << "Enter vehicle name: ";
                cin >> name;
                const Vehicle* vehicle = showroom.getVehicleByName(name);
                if (vehicle) {
                    vehicle->display();
                } else {
                    cout << "Vehicle not found." << endl;
                }
                break;
            }
            case 5: {
                string id;
                double newPrice;
                cout << "Enter vehicle ID: ";
                cin >> id;
                cout << "Enter new price: ";
                cin >> newPrice;
                showroom.modifyVehicle(id, newPrice);
                break;
            }
            case 6: {
                string id;
                cout << "Enter vehicle ID: ";
                cin >> id;
                showroom.removeVehicle(id);
                break;
            }
            case 7: {
                string id;
                cout << "Enter vehicle ID: ";
                cin >> id;
                showroom.showVehiclePrice(id);
                break;
            }
            case 8:
                showroom.saveToFile("vehicles.txt");
                break;
            case 9:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 9." << endl;
        }
    } while (choice != 9);

    return 0;
}
