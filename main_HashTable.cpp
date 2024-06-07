#include "hashTable.h"
#include "pbEntry.h"
#include <string>
#include <iostream>

int main() {
    // 2. Fügen Sie 5 Einträge in die Tabelle ein
    PbEntry entry1("3277971", "Norma Noe", "North Lyme Drive 30");
    PbEntry entry2("9928657", "Ashok Kumar", "Lawrence Avenue 24");
    PbEntry entry3("1674792", "Baby Doe", "North Lyme Street 34");
    PbEntry entry4("4991459", "Brett Boe", "North Lyme Road 35 ");
    PbEntry entry5("1990539", "Carla Coe", "Lawrence Road 29");

    // 1. Erstellen Sie eine Hash-Tabelle mit einer Hash-Funktion
    HashTable ht;
    ht.insert(&entry1);
    ht.insert(&entry2);
    ht.insert(&entry3);
    ht.insert(&entry4);
    ht.insert(&entry5);

    // 3. Drucken Sie die Tabelle aus (sowohl Schlüssel als auch Werte)
    ht.print();

    // 4. Erstellen Sie eine weitere Hash-Tabelle mit einer anderen Hash-Funktion
    ht.setHashFunction("mod17");
    ht.insert(&entry1);
    ht.insert(&entry2);
    ht.insert(&entry3);
    ht.insert(&entry4);
    ht.insert(&entry5);

    // 6. Drucken Sie die Tabelle aus (sowohl Schlüssel als auch Werte)
    ht.print();

    // 7. Suchen Sie nach einem bestimmten Element in der Tabelle
    const PbEntry* s1 = ht.search("3277971");
    if (s1) {
        std::cout << s1->toString() << std::endl;
    } else {
        std::cout << "Entry not found." << std::endl;
    }

    // 8. Löschen Sie ein Element in der Tabelle
    bool test = ht.deleteItem("3277971");
    std::cout << "Delete result: " << test << std::endl;

    // 9. Löschen Sie ein weiteres Element in der Tabelle
    bool test2 = ht.deleteItem("3277971");
    std::cout << "Delete result: " << test2 << std::endl;

    return 0;
}
