#ifndef PBENTRY_H
#define PBENTRY_H

#include <string>

class PbEntry {
private:
    std::string phoneNumber;
    std::string name;
    std::string address;

public:
    PbEntry(const std::string& phoneNumber, const std::string& name, const std::string& address)
            : phoneNumber(phoneNumber), name(name), address(address) {}

    std::string getPhoneNumber() const {
        return phoneNumber;
    }

    std::string getName() const {
        return name;
    }

    std::string getAddress() const {
        return address;
    }

    std::string toString() const {
        return "Phone: " + phoneNumber + ", Name: " + name + ", Address: " + address;
    }
};

#endif // PBENTRY_H
