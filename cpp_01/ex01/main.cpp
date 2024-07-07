# include "Zombie.hpp"

int main()
{
    Zombie *n_zombies;
    int     i;
    int     N;

    N = 3;
    n_zombies = zombieHorde(N, "foo");
    i = 0;
    while (i < N)
    {
        n_zombies[i].announce();
        i++;
    }
    if (n_zombies != nullptr)
        delete[] n_zombies;
    return (0);
}