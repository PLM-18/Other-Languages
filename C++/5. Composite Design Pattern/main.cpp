#include <iostream>
#include <vector>
#include <string>

// Abstract Leaf class: Unit
class Unit {
public:
    int health;
    int damage;
    int defense;
    std::string unitName;

public:
    Unit(int h, int d, int def, const std::string& name)
        : health(h), damage(d), defense(def), unitName(name) {}

    virtual void displayInfo() const = 0; // Pure virtual function
    virtual ~Unit() {}
};

// Derived Leaf class: Infantry
class Infantry : public Unit {
public:
    Infantry(int h, int d, int def, const std::string& name)
        : Unit(h, d, def, name) {}

    void displayInfo() const override {
        std::cout << "Infantry Unit: " << unitName << "\n"
                  << "Health: " << health << ", Damage: " << damage
                  << ", Defense: " << defense << std::endl;
    }
};

// Derived Leaf class: Artillery
class Artillery : public Unit {
public:
    Artillery(int h, int d, int def, const std::string& name)
        : Unit(h, d, def, name) {}

    void displayInfo() const override {
        std::cout << "Artillery Unit: " << unitName << "\n"
                  << "Health: " << health << ", Damage: " << damage
                  << ", Defense: " << defense << std::endl;
    }
};

// Derived Leaf class: Cavalry
class Cavalry : public Unit {
public:
    Cavalry(int h, int d, int def, const std::string& name)
        : Unit(h, d, def, name) {}

    void displayInfo() const override {
        std::cout << "Cavalry Unit: " << unitName << "\n"
                  << "Health: " << health << ", Damage: " << damage
                  << ", Defense: " << defense << std::endl;
    }
};

// Composite class: CompositeUnit
class CompositeUnit : public Unit {
private:
    std::vector<Unit*> units;

public:
    CompositeUnit(const std::string& name)
        : Unit(0, 0, 0, name) {}

    void add(Unit* unit) {
        units.push_back(unit);
        health += unit->health;    // Aggregate health
        damage += unit->damage;    // Aggregate damage
        defense += unit->defense;  // Aggregate defense
    }

    void remove(Unit* unit) {
        /* units.erase(std::remove_if(units.begin(), units.end(), [unit](Unit* u) { return u == unit; }), units.end()); */
        health -= unit->health;    // Adjust aggregate health
        damage -= unit->damage;    // Adjust aggregate damage
        defense -= unit->defense;  // Adjust aggregate defense
    }

    void displayInfo() const override {
        std::cout << "Composite Unit: " << unitName << "\n"
                  << "Total Health: " << health << ", Total Damage: " << damage
                  << ", Total Defense: " << defense << std::endl;

        for (const auto& unit : units) {
            unit->displayInfo();
        }
    }

    ~CompositeUnit() {
        for (auto& unit : units) {
            delete unit;
        }
    }
};

int main() {
    // Create individual units
    Unit* infantry1 = new Infantry(100, 20, 10, "Infantry1");
    Unit* infantry2 = new Infantry(120, 25, 15, "Infantry2");
    Unit* cavalry1 = new Cavalry(150, 30, 20, "Cavalry1");
    Unit* artillery1 = new Artillery(200, 50, 5, "Artillery1");

    // Create a composite unit (like a battalion)
    CompositeUnit* battalion = new CompositeUnit("Battalion");
    battalion->add(infantry1);
    battalion->add(infantry2);
    battalion->add(cavalry1);

    // Create another composite unit (like a regiment)
    CompositeUnit* regiment = new CompositeUnit("Regiment");
    regiment->add(battalion); // Add the battalion to the regiment
    regiment->add(artillery1); // Add the artillery to the regiment

    // Display the regiment's information
    regiment->displayInfo();

    // Clean up
    delete regiment;

    return 0;
}


