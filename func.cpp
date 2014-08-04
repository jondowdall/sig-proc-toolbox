#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <vector>

using namespace std;

namespace Functions {

/* Base class for functions
 */
class Unary {
    static string title;
public:
    virtual double execute(double input) = 0;
    virtual string name() const {
        return "Unary Function";
    }
};

class Sin : public Unary {
    double execute(double input) {
        return sin(input);
    }
    virtual string name() const {
        return "Sin";
    }
};

class Cos : public Unary {
    double execute(double input) {
        return cos(input);
    }
    virtual string name() const {
        return "Cos";
    }
};

class Tan : public Unary {
    double execute(double input) {
        return tan(input);
    }
    virtual string name() const {
        return "Tan";
    }
};

typedef vector<Unary *>Sequence;

/*
 * Convert a string into a sequence of functions.
 */
Sequence parse(string definition) {
    Sequence actions;
    for (unsigned int i = 0; i < definition.size(); ++i) {
        switch (definition[i]) {
            case 'c':
                actions.push_back(new Functions::Cos);
                break;
            case 's':
                actions.push_back(new Functions::Sin);
                break;
            case 't':
                actions.push_back(new Functions::Tan);
                break;
        }
    }
    return actions;
}

}

namespace Datatypes {

class Number {
    double _value;
public:
    Number(double initial_value) {
        _value = initial_value;
    }
    Number() {
        _value = 0.0;
    }
    double get() {
        return _value;
    }
    void set(double value) {
        _value = value;
    }
    string name() {
        return "Double";
    }
};

}

typedef vector<Datatypes::Number*>Arguments;

namespace Processes {

class Base {
    Arguments _inputs;
    Arguments _outputs;

public:
    Arguments &inputs() {
        return _inputs;
    }

    Arguments &outputs() {
        return _outputs;
    }
    virtual void execute() = 0;
};

class Unary: public Base {
    Functions::Unary &_function;
public:
    Unary(Functions::Unary &function)
      : _function(function) {
          inputs().push_back(new Datatypes::Number);
          outputs().push_back(new Datatypes::Number);
    }
    void execute() {
        Datatypes::Number &_input = *(inputs()[0]);
        Datatypes::Number &_output = *(outputs()[0]);
        _output.set(_function.execute(_input.get()));
    }
};

}

int main(int argc, char* argv[]) {
    vector<Functions::Unary *>actions;

    double value = M_PIl / 2.0;
    if (argc > 1) {
        value = atof(argv[1]);
    }

    if (argc > 2) {
        actions = Functions::parse(argv[2]);
    } else {
        actions.push_back(new Functions::Sin);
        actions.push_back(new Functions::Cos);
        actions.push_back(new Functions::Cos);
        actions.push_back(new Functions::Cos);
        actions.push_back(new Functions::Cos);
    }

    for (unsigned int i = 0; i < actions.size(); ++i) {
        cout << i << ": " << actions[i]->name() << "(" << value << ")";
        value = actions[i]->execute(value);
        cout << " = " << value << endl;
    }

    Functions::Sin sin_function;
    Processes::Unary test = Processes::Unary(sin_function);

    if (argc > 1) {
       test.inputs()[0]->set(atof(argv[1]));
    } else {
        test.inputs()[0]->set(M_PIl / 2.0);
    }
    test.execute();
    cout << "Process: " << test.inputs()[0]->get();
    cout << " -> " << test.outputs()[0]->get() << endl;

    cout << "Hello World!" << endl;
}
