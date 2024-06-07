#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "pbEntry.h"
#include <vector>
#include <list>
#include <string>
#include <iostream>

class HashTable {
private:
    std::vector<std::list<PbEntry*> > table;
    int (*hashFunction)(const std::string&);

    static int defaultHashFunction(const std::string& key) {
        int hash = 0;
        for (char c : key) {
            hash += c;
        }
        return hash;
    }

    static int mod17HashFunction(const std::string& key) {
        int hash = 0;
        for (char c : key) {
            hash += c;
        }
        return hash % 17;
    }

public:
    // 1. Erstellen Sie eine Hash-Tabelle mit einer Hash-Funktion
    HashTable(int size = 17) : table(size), hashFunction(defaultHashFunction) {}

    // 2. Fügen Sie 5 Einträge in die Tabelle ein
    void insert(PbEntry* entry) {
        int index = hashFunction(entry->getPhoneNumber()) % table.size();
        table[index].push_back(entry);
    }

    // 8. Löschen Sie ein Element in der Tabelle
    bool deleteItem(const std::string& key) {
        int index = hashFunction(key) % table.size();
        auto& entries = table[index];
        for (auto it = entries.begin(); it != entries.end(); ++it) {
            if ((*it)->getPhoneNumber() == key) {
                entries.erase(it);
                return true;
            }
        }
        return false;
    }

    // 7. Suchen Sie nach einem bestimmten Element in der Tabelle
    const PbEntry* search(const std::string& key) const {
        int index = hashFunction(key) % table.size();
        const auto& entries = table[index];
        for (const auto& entry : entries) {
            if (entry->getPhoneNumber() == key) {
                return entry;
            }
        }
        return nullptr;
    }

    // 4. Erstellen Sie eine weitere Hash-Tabelle mit einer anderen Hash-Funktion
    void setHashFunction(const std::string& functionName) {
        if (functionName == "mod17") {
            hashFunction = mod17HashFunction;
        } else {
            hashFunction = defaultHashFunction;
        }
    }

    // 3. und 6. Drucken Sie die Tabelle aus (sowohl Schlüssel als auch Werte)
    void print() const {
        for (int i = 0; i < table.size(); ++i) {
            std::cout << "Index " << i << ": ";
            for (const auto& entry : table[i]) {
                std::cout << "[" << entry->toString() << "] ";
            }
            std::cout << "\n";
        }
    }
};

#endif // HASHTABLE_H
