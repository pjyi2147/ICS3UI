// Lab 8.4.5. by Jeongseop Yi
#include <iostream>
#include <cmath>

class FSM {
public:
    void operator<< (int trigger) {
        if(trigger > 5) {
            if(state < 5)
                state++;
        } else if(trigger < 5) {
            if(state > 0)
                state--;
        }
        states[state] = true;
    }
    std::string print() {
        std::string out;
        if(states[0])
            out += "1(Start)";
        for(int i = 1; i <= 4; i++)
            if(states[i]) {
                if(!out.empty()) out += ", ";
                out += std::to_string(i + 1);
            }
        if(states[5]) {
            if(!out.empty()) out += ", ";
            out += "6(Stop)";
        }
        return out;
    }
private:
    int state = 0;
    bool states[6] = {true, false, false, false, false, false};
};

int main() {
    FSM fsm;
    fsm << 3;
    fsm << 6;
    fsm << 4;
    std::cout << fsm.print() << std::endl;
}
