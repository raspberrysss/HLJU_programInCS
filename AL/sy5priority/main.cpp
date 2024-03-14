#include <iostream>
#include"Priority00.h"

using namespace std;

int main(void)
{
    Priority_s p1;
    p1.set_graph();
    p1.find_shortpath();
    p1.show_every();
    return 0;
}
