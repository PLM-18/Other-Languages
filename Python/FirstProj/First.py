
def newFunction(Age):
    if(Age == 18): print("Wow")
    elif(Age < 0): print("Invalid age")
    else: print("You are: ",Age)

def Main():
    print("This is a student")
    newVar = int(input("Enter your Age: "))
    newFunction(newVar)

if(__name__ == "__main__"): Main()