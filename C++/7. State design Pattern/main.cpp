#include <iostream>
#include <memory>

// Forward declaration of Context
class Context;

// State interface
class State {
public:
    virtual ~State() = default;
    virtual void handle(Context& context) = 0;
};

// Concrete State A
class ConcreteStateA : public State {
public:
    void handle(Context& context) override;
};

// Concrete State B
class ConcreteStateB : public State {
public:
    void handle(Context& context) override;
};

// Context class that changes behavior based on the state
class Context {
private:
    State* state;
public:
    Context(State* initialState) : state(std::move(initialState)) {}

    void setState(State* newState) {
        state = newState;
    }

    void request() {
        state->handle(*this);
    }

    ~Context() {
        delete state;
    }
};

// Implementation of ConcreteStateA's behavior
void ConcreteStateA::handle(Context& context) {
    std::cout << "ConcreteStateA handles the request.\n";
    std::cout << "ConcreteStateA is switching to ConcreteStateB.\n";
    context.setState(new ConcreteStateB());
}

// Implementation of ConcreteStateB's behavior
void ConcreteStateB::handle(Context& context) {
    std::cout << "ConcreteStateB handles the request.\n";
    std::cout << "ConcreteStateB is switching to ConcreteStateA.\n";
    context.setState(new ConcreteStateA());
}

// Client code
int main() {
    Context context(new ConcreteStateA());
    context.request();  // State A handles and switches to State B
    context.request();  // State B handles and switches to State A
    context.request();  // State A handles and switches to State B
    return 0;
}
