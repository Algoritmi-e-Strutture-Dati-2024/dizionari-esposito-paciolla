#include <iostream>
#include <string>

template <typename T>
class DizionarioEsteso {
private:
    static const int TABLE_SIZE = 10;
    struct Entry {
        std::string key;
        T value;
        bool isOccupied = false;
    };

    Entry table[TABLE_SIZE];

    int hashFunction(const std::string& key) const {
        int hash = 0;
        for (char ch : key) {
            hash += static_cast<int>(ch);
        }
        return hash % TABLE_SIZE;
    }

    int findSlot(int index) const {
        int i = index;
        while (table[i].isOccupied) {
            i = (i + 1) % TABLE_SIZE;
        }
        return i;
    }

public:
    void inserisci(const std::string& key, const T& value) {
        int index = hashFunction(key);

        if (table[index].isOccupied) {
            index = findSlot(index);
        }

        table[index].key = key;
        table[index].value = value;
        table[index].isOccupied = true;
        std::cout << "Inserito " << key << " => " << value << " all'indice " << index << "\n";
    }

    T recupera(const std::string& key) const {
        int index = hashFunction(key);

        while (table[index].isOccupied) {
            if (table[index].key == key) {
                return table[index].value;
            }
            index = (index + 1) % TABLE_SIZE;
        }

        return "Chiave non trovata!";
    }

    void cancella(const std::string& key) {
        int index = hashFunction(key);

        while (table[index].isOccupied) {
            if (table[index].key == key) {
                table[index].isOccupied = false;
                std::cout << "Chiave " << key << " eliminata all'indice " << index << "\n";
                return;
            }
            index = (index + 1) % TABLE_SIZE;
        }

        std::cerr << "La chiave " << key << " non è stata trovata per l'eliminazione.\n";
    }

    bool appartiene(const std::string& key) const {
        int index = hashFunction(key);

        while (table[index].isOccupied) {
            if (table[index].key == key) {
                return true;
            }
            index = (index + 1) % TABLE_SIZE;
        }
        return false;
    }

    void stampa() const {
        std::cout << "Contenuto attuale del dizionario:\n";
        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (table[i].isOccupied) {
                std::cout << "Indice " << i << ": " << table[i].key << " => " << table[i].value << "\n";
            }
        }
    }
};
