#include <iostream>
#include "Interface.h"

int main(int argc, const char *argv[]) {

  freopen(argv[1],"r",stdin);

    Interface InterfaceXD;
    while (InterfaceXD.condition()) {
        InterfaceXD.run();
    }

}