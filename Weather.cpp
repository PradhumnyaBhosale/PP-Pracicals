#include <iostream>
#include <cstring>

class Personnel {
private:
    char* name;
    char* dateOfBirth;
    char* bloodGroup;
    float height;
    float weight;
    long insurancePolicyNumber;
    char* contactAddress;
    long telephoneNumber;
    long drivingLicenseNumber;

    static int objectCount;  

public:
   
    Personnel() : name(nullptr), dateOfBirth(nullptr), bloodGroup(nullptr), height(0), weight(0),
                  insurancePolicyNumber(0), contactAddress(nullptr), telephoneNumber(0), drivingLicenseNumber(0) {
        objectCount++;
    }

    Personnel(const char* name, const char* dob, const char* bloodGroup, float height,
              float weight, long insurancePolicy, const char* address, long phone, long license)
        : Personnel() {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);

        this->dateOfBirth = new char[strlen(dob) + 1];
        strcpy(this->dateOfBirth, dob);

        this->bloodGroup = new char[strlen(bloodGroup) + 1];
        strcpy(this->bloodGroup, bloodGroup);

        this->height = height;
        this->weight = weight;
        this->insurancePolicyNumber = insurancePolicy;

        this->contactAddress = new char[strlen(address) + 1];
        strcpy(this->contactAddress, address);

        this->telephoneNumber = phone;
        this->drivingLicenseNumber = license;
    }

    
    ~Personnel() {
        delete[] name;
        delete[] dateOfBirth;
        delete[] bloodGroup;
        delete[] contactAddress;

        objectCount--;
    }

    
    Personnel(const Personnel& other) : Personnel() {
       
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);

        dateOfBirth = new char[strlen(other.dateOfBirth) + 1];
        strcpy(dateOfBirth, other.dateOfBirth);

        bloodGroup = new char[strlen(other.bloodGroup) + 1];
        strcpy(bloodGroup, other.bloodGroup);

        height = other.height;
        weight = other.weight;
        insurancePolicyNumber = other.insurancePolicyNumber;

        contactAddress = new char[strlen(other.contactAddress) + 1];
        strcpy(contactAddress, other.contactAddress);

        telephoneNumber = other.telephoneNumber;
        drivingLicenseNumber = other.drivingLicenseNumber;
    }

   
    static int getObjectCount() {
        return objectCount;
    }

    
    friend class PersonnelInfoPrinter;

    
    void displayInfo() const {
        std::cout << "Name: " << name << "\nDate of Birth: " << dateOfBirth << "\nBlood Group: " << bloodGroup
                  << "\nHeight: " << height << " cm\nWeight: " << weight << " kg\nInsurance Policy No.: "
                  << insurancePolicyNumber << "\nContact Address: " << contactAddress << "\nTelephone No.: "
                  << telephoneNumber << "\nDriving License No.: " << drivingLicenseNumber << std::endl;
    }
};

int Personnel::objectCount = 0;  // Initializing the static member


class PersonnelInfoPrinter {
public:
    static void printInfo(const Personnel& person) {
        std::cout << "Printing Personnel Information using Friend Class:\n";
        std::cout << "Name: " << person.name << "\nDate of Birth: " << person.dateOfBirth
                  << "\nBlood Group: " << person.bloodGroup << "\nHeight: " << person.height << " cm\nWeight: "
                  << person.weight << " kg\nInsurance Policy No.: " << person.insurancePolicyNumber
                  << "\nContact Address: " << person.contactAddress << "\nTelephone No.: " << person.telephoneNumber
                  << "\nDriving License No.: " << person.drivingLicenseNumber << std::endl;
    }
};

int main() {
    
    Personnel person1("John Doe", "01-01-1990", "A+", 175.5, 70.0, 123456, "123 Main St", 5551234567, 987654);
    person1.displayInfo();

   
    PersonnelInfoPrinter::printInfo(person1);

    function
    std::cout << "Object Count: " << Personnel::getObjectCount() << std::endl;

    return 0;
}
