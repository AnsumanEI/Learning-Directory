#include <SFML/Graphics.hpp>
#include <unistd.h>

sf::RenderWindow window(sf::VideoMode(960, 600), "Sorter");
int n = 80;
float recHs[80];
unsigned int microsecond = 1000000;
bool sorted = false;

void dispSort(int index)
{
    window.clear();
    for (int i = 0; i < n; i++)
    {
        sf::RectangleShape block(sf::Vector2f(10, recHs[i]));
        block.setPosition(i * 12, 600 - recHs[i]);
        block.setFillColor(sorted || i == index ? sf::Color::Green : sf::Color::White);
        window.draw(block);
    }
    window.display();
}

void insertionSort()
{
    usleep(microsecond * 5);
    int i, key, j;
    for (i = 0; i < n; i++)
    {
        key = recHs[i];
        j = i - 1;

        while (j >= 0 && recHs[j] > key)
        {
            recHs[j + 1] = recHs[j];
            j = j - 1;
            dispSort(j);
        }
        recHs[j + 1] = key;
    }

    sorted = true;

    dispSort(i);
}

int main()
{

    for (int i = 0; i < n; i++)
    {
        recHs[i] = (rand() % 500);
    }
    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            switch (event.type)
            {

            case sf::Event::Closed:
                window.close();
            }
        }
        if (!sorted)
        {
            dispSort(0);
            insertionSort();
        }
    }
}