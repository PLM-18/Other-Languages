#Base Class
class FarmUnit:
    def get_description(self):
        raise NotImplementedError("Subclasses should implement this method.")
    
    def get_storage_capacity(self):
        raise NotImplementedError("Subclasses should implement this method.")
    
    def get_stored_amount(self):
        raise NotImplementedError("Subclasses should implement this method.")
    
    def fertilize_soil(self):
        raise NotImplementedError("Subclasses should implement this method.")
    
    def get_soil_state(self):
        raise NotImplementedError("Subclasses should implement this method.")

#Concrete Classes
class Barn(FarmUnit):
    def __init__(self, capacity):
        self.capacity = capacity

    def get_description(self):
        return "Barn"

    def get_storage_capacity(self):
        return self.capacity

    def get_stored_amount(self):
        return 0  # Barns don't store crops directly

    def fertilize_soil(self):
        pass  # Barns don't affect soil

    def get_soil_state(self):
        return None  # Barns don't affect soil

#Decorator
class CropField(FarmUnit):
    def __init__(self, crop_type):
        self.crop_type = crop_type
        self.total_storage_capacity = 0
        self.current_stored_amount = 0
        self.soil_state = "neutral"
        self.barns = []

    def get_description(self):
        return f"CropField growing {self.crop_type}"

    def get_storage_capacity(self):
        return self.total_storage_capacity

    def get_stored_amount(self):
        return self.current_stored_amount

    def fertilize_soil(self):
        self.soil_state = "fertilized"
    
    def get_soil_state(self):
        return self.soil_state

    def add_barn(self, barn):
        if isinstance(barn, Barn):
            self.barns.append(barn)
            self.total_storage_capacity += barn.get_storage_capacity()

#Concrete Decorators
class StorageDecorator(FarmUnit):
    def __init__(self, crop_field):
        self.crop_field = crop_field
    
    def get_description(self):
        return self.crop_field.get_description()
    
    def get_storage_capacity(self):
        return self.crop_field.get_storage_capacity()
    
    def get_stored_amount(self):
        return self.crop_field.get_stored_amount()
    
    def fertilize_soil(self):
        self.crop_field.fertilize_soil()
    
    def get_soil_state(self):
        return self.crop_field.get_soil_state()
    
    def add_barn(self, barn):
        self.crop_field.add_barn(barn)

class FertilizerDecorator(FarmUnit):
    def __init__(self, crop_field):
        self.crop_field = crop_field
    
    def get_description(self):
        return self.crop_field.get_description()
    
    def get_storage_capacity(self):
        return self.crop_field.get_storage_capacity()
    
    def get_stored_amount(self):
        return self.crop_field.get_stored_amount()
    
    def fertilize_soil(self):
        self.crop_field.fertilize_soil()
    
    def get_soil_state(self):
        return self.crop_field.get_soil_state()
    
    def add_barn(self, barn):
        self.crop_field.add_barn(barn)

# Create a basic crop field
corn_field = CropField("corn")

# Create barns and add them to the crop field
barn1 = Barn(100)
barn2 = Barn(50)
corn_field.add_barn(barn1)
corn_field.add_barn(barn2)

# Decorate the crop field with additional storage capabilities if needed
decorated_field = StorageDecorator(corn_field)

# Fertilize the soil and check its state
decorated_field.fertilize_soil()
print(decorated_field.get_soil_state())  # Output: "fertilized"
