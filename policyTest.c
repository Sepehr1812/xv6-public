#include "types.h"
#include "user.h"

int main(int argc, char const *argv[])
{
    int a = atoi(argv[1]);
    changePolicy(a);
    exit();
}
