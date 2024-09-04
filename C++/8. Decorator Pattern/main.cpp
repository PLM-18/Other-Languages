#include <iostream>
#include <string>
#include <vector>
#include <memory>

// Base Class
class FarmUnit {
public:
    virtual std::string getDescription() const = 0;
    virtual int getStorageCapacity() const = 0;
    virtual int getStoredAmount() const = 0;
    virtual void fertilizeSoil() = 0;
    virtual std::string getSoilState() const = 0;
    virtual ~FarmUnit() = default;
};

// Concrete Class
class Barn : public FarmUnit {
private:
    int capacity;

public:
    Barn(int cap) : capacity(cap) {}

    std::string getDescription() const override {
        return "Barn";
    }

    int getStorageCapacity() const override {
        return capacity;
    }

    int getStoredAmount() const override {
        return 0;  // Barns don't store crops directly
    }

    void fertilizeSoil() override {
        // Barns don't affect soil
    }

    std::string getSoilState() const override {
        return "";  // Barns don't affect soil
    }
};

// Concrete Class
class CropField : public FarmUnit {
private:
    std::string cropType;
    int totalStorageCapacity;
    int currentStoredAmount;
    std::string soilState;
    std::vector<std::shared_ptr<Barn>> barns;

public:
    CropField(const std::string& crop) 
        : cropType(crop), totalStorageCapacity(0), currentStoredAmount(0), soilState("neutral") {}

    std::string getDescription() const override {
        return "CropField growing " + cropType;
    }

    int getStorageCapacity() const override {
        return totalStorageCapacity;
    }

    int getStoredAmount() const override {
        return currentStoredAmount;
    }

    void fertilizeSoil() override {
        soilState = "fertilized";
    }

    std::string getSoilState() const override {
        return soilState;
    }

    void addBarn(std::shared_ptr<Barn> barn) {
        if (barn) {
            barns.push_back(barn);
            totalStorageCapacity += barn->getStorageCapacity();
        }
    }
};

// Decorator Base Class
class FarmUnitDecorator : public FarmUnit {
protected:
    std::shared_ptr<FarmUnit> cropField;

public:
    FarmUnitDecorator(std::shared_ptr<FarmUnit> field) : cropField(field) {}

    std::string getDescription() const override {
        return cropField->getDescription();
    }

    int getStorageCapacity() const override {
        return cropField->getStorageCapacity();
    }

    int getStoredAmount() const override {
        return cropField->getStoredAmount();
    }

    void fertilizeSoil() override {
        cropField->fertilizeSoil();
    }

    std::string getSoilState() const override {
        return cropField->getSoilState();
    }

    void addBarn(std::shared_ptr<Barn> barn) {
        auto cropFieldPtr = std::dynamic_pointer_cast<CropField>(cropField);
        if (cropFieldPtr) {
            cropFieldPtr->addBarn(barn);
        }
    }
};

// Concrete Decorator
class StorageDecorator : public FarmUnitDecorator {
public:
    StorageDecorator(std::shared_ptr<FarmUnit> field) : FarmUnitDecorator(field) {}
};

class FertilizerDecorator : public FarmUnitDecorator {
public:
    FertilizerDecorator(std::shared_ptr<FarmUnit> field) : FarmUnitDecorator(field) {}
};

int main() {
    // Create a basic crop field
    auto cornField = std::make_shared<CropField>("corn");

    // Create barns and add them to the crop field
    auto barn1 = std::make_shared<Barn>(100);
    auto barn2 = std::make_shared<Barn>(50);
    cornField->addBarn(barn1);
    cornField->addBarn(barn2);

    // Decorate the crop field with additional storage capabilities if needed
    auto decoratedField = std::make_shared<StorageDecorator>(cornField);

    // Fertilize the soil and check its state
    decoratedField->fertilizeSoil();
    std::cout << decoratedField->getSoilState() << std::endl;  // Output: "fertilized"

    return 0;
}
