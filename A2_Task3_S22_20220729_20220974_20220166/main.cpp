#include <bits/stdc++.h>
#include <fstream>
#include <stdexcept>
#include <memory>
using namespace std;

class Component
{
public:
    virtual ~Component() = default;
};
class Register : public Component
{
private:
    int value;

public:
    void setValue(int newValue)
    {
        value = newValue;
    }
    int getValue() const
    {
        return value;
    }
};
class Memory : public Component
{
private:
    vector<int> data;

public:
    Memory(int size) : data(size, 0) {}

    int read(int address) const
    {
        if (address < 0 || address >= data.size())
        {
            throw out_of_range("Memory read out of bounds");
        }
        return data[address];
    }

    void write(int address, int value)
    {
        if (address < 0 || address >= data.size())
        {
            throw out_of_range("Memory write out of bounds");
        }
        data[address] = value;
    }

    void display() const
    {
        cout << "\nMemory:" << endl;
        for (int i = 0; i < data.size(); i++)
        {
            cout << hex << data[i] << " ";

            if ((i + 1) % 20 == 0)
            {
                cout << endl;
            }
        }
        cout << endl;
    }
};

class Instruction : public Component
{
private:
    int opcode;
    int operand1;
    int operand2;

public:
    Instruction(int op, int op1, int op2) : opcode(op), operand1(op1), operand2(op2) {}

    int getOpcode() const
    {
        return opcode;
    }

    int getOperand1() const
    {
        return operand1;
    }

    int getOperand2() const
    {
        return operand2;
    }
};

class Machine
{
private:
    vector<unique_ptr<Component>> components;
    vector<Register *> registers;
    Memory *memory;
    vector<Instruction *> programMemory;
    int pc;
    bool halted;

public:
    Machine(int numRegisters, int memorySize)
        : pc(0), halted(false)
    {
        // Initialize components
        memory = new Memory(memorySize);
        components.push_back(unique_ptr<Component>(memory));

        for (int i = 0; i < numRegisters; i++)
        {
            Register *reg = new Register();
            registers.push_back(reg);
            components.push_back(unique_ptr<Component>(reg));
        }
    }

    ~Machine()
    {
        // Clean up components
        for (auto &component : components)
        {
            delete component.release();
        }
    }

    void loadProgram(string filename)
    {
        ifstream infile(filename);
        if (!infile.is_open())
        {
            throw runtime_error("Error opening file " + filename);
        }

        int opcode, operand1, operand2;
        while (infile >> hex >> opcode >> hex >> operand1 >> hex >> operand2)
        {
            programMemory.push_back(new Instruction(opcode, operand1, operand2));
            components.push_back(unique_ptr<Component>(programMemory.back()));
        }

        infile.close();
    }

    void executeInstruction()
    {
        if (pc >= programMemory.size())
        {
            halted = true;
            return;
        }

        const Instruction &currentInstruction = *programMemory[pc];
        int opcode = currentInstruction.getOpcode();
        int operand1 = currentInstruction.getOperand1();
        int operand2 = currentInstruction.getOperand2();

        switch (opcode)
        {
        case 1: // LOAD register with memory
            registers[operand1]->setValue(memory->read(operand2));
            break;
        case 2: // LOAD register with immediate
            registers[operand1]->setValue(operand2);
            break;
        case 3: // STORE
            memory->write(operand2, registers[operand1]->getValue());
            break;
        case 4: // MOVE
            registers[operand1]->setValue(registers[operand2]->getValue());
            break;
        case 5: // ADD INTEGER
            registers[operand1]->setValue(registers[operand1]->getValue() + registers[operand2]->getValue());
            break;
        case 0x6: // RST ADD for Floating-Point
        {
            int intValue1 = registers[operand1]->getValue();
            int intValue2 = registers[operand2]->getValue();

            float floatValue1 = *reinterpret_cast<float *>(&intValue1);
            float floatValue2 = *reinterpret_cast<float *>(&intValue2);

            float sum = floatValue1 + floatValue2;

            // Storing the result as an integer back in the register
            registers[operand1]->setValue(*reinterpret_cast<int *>(&sum));
        }
        break;
        case 0xB: // JUMP IF EQUAL
            if (registers[operand1]->getValue() == registers[0]->getValue())
            {
                pc = operand2;
                return;
            }
            break;
        case 0xC: // HALT
            halted = true;
            return;
        default:
            throw invalid_argument("Unknown opcode: " + to_string(opcode));
        }

        displayStatus();
        pc++;
    }

    void displayStatus() const
    {
        cout << "PC: " << pc << endl;
        cout << "Registers:" << endl;
        for (size_t i = 0; i < registers.size(); i++)
        {
            cout << hex << registers[i]->getValue() << " ";

            if ((i + 1) % 4 == 0)
            {
                cout << endl;
            }
        }

        memory->display();
    }

    bool isHalted() const
    {
        return halted;
    }
};

int main()
{
    int numRegisters, memorySize;
    cout << "Enter the number of registers: ";
    cin >> numRegisters;
    cout << "Enter the size of memory: ";
    cin >> memorySize;
    try
    {
        Machine machine(numRegisters, memorySize);
        machine.displayStatus();

        string filename;
        cout << "Enter the filename of the program to load: ";
        cin >> filename;

        machine.loadProgram(filename);

        while (!machine.isHalted())
        {
            machine.executeInstruction();
        }

        cout << "Program execution completed." << endl;
    }
    catch (const exception &e)
    {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
}
