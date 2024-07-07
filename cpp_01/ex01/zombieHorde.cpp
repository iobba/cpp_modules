# include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    Zombie  *n_zombies;
    int     i;

    if (N < 0)
        return (nullptr);
    n_zombies = new Zombie[N];
    i = 0;
    while (i < N)
    {
        n_zombies[i] = Zombie(name);
        i++;
    }
    return (n_zombies);
}