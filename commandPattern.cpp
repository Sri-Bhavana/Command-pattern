class Command {
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
    virtual void undo() = 0;
};

class Light;

class TurnOnCommand : public Command {
public:
    TurnOnCommand(Light* receiver) : receiver(receiver) {}
    void execute() override;
    void undo() override;

private:
    Light* receiver;
};

class TurnOffCommand : public Command {
public:
    TurnOffCommand(Light* receiver) : receiver(receiver) {}
    void execute() override;
    void undo() override;

private:
    Light* receiver;
};

class Light {
public:
    void turnOn() { isOnState = true; }
    void turnOff() { isOnState = false; }
    bool isOn() const { return isOnState; }

private:
    bool isOnState = false;
};

class Invoker {
public:
    void setCommand(Command* command) { this->command = command; }
    void executeCommand() { command->execute(); }

private:
    Command* command = nullptr;
};
void TurnOnCommand::execute() {}

void TurnOnCommand::undo() {}

void TurnOffCommand::execute() {}

void TurnOffCommand::undo() {}

int main() {
    Light light;
    Invoker invoker;

    // Create commands
    auto turnOn = new TurnOnCommand(&light);
    auto turnOff = new TurnOffCommand(&light);

    // Set commands and execute
    invoker.setCommand(turnOn);
    invoker.executeCommand();  // Output: Light is on

    invoker.setCommand(turnOff);
    invoker.executeCommand();  // Output: Light is off

    // Undo the last operation (optional)
    turnOff->undo();  // Output: Light is on

    delete turnOn;
    delete turnOff;
    return 0;
}


