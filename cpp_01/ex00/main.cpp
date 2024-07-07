#include "Zombie.hpp"

int main()
{
    Zombie *zombie;

    zombie = newZombie("foooo");
    zombie->announce();
    randomChump("second");
    delete zombie;
    
    return (0);
}