#include <SFML/Graphics.hpp>

#include "TenStamps.hpp"
#include "Icon.hpp"

std::string generate_counting_string(unsigned int counter, std::size_t width)
{
    auto string = std::to_string(counter);

    while (string.size() < width)
    {
        string = "0" + string;
    }

    return string;
}

int main()
{
    sf::RenderWindow window{ {310, 120}, "Space Killer", sf::Style::Close | sf::Style::Titlebar };
    window.setFramerateLimit(30);

    sf::Image icon;
    icon.loadFromMemory(icon_png->data(), icon_png->size());
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    auto counter = 0u;
    auto started = false;
    auto finished = false;

    sf::Clock timer;

    sf::Font font;
    font.loadFromMemory(ten_stamps.data(), ten_stamps.size());

    sf::Text timer_text{ "SPACE", font, 50 };
    timer_text.setPosition({ 45.f, 0.f });
    timer_text.setFillColor(sf::Color::Red);

    sf::Text counter_text{ "KILLER", font, 50 };
    counter_text.setPosition({ 20.f, 50.f });

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::Space && !finished)
                {
                    ++counter;

                    if (!started)
                    {
                        started = true;
                        timer_text.setPosition({ 115.f, 0.f });
                        counter_text.setPosition({ 20.f, 50.f });
                        timer.restart();
                    }
                }
                else if (event.key.code == sf::Keyboard::Escape)
                {
                    timer_text.setString("SPACE");
                    timer_text.setPosition({ 45.f, 0.f });
                    timer_text.setFillColor(sf::Color::Red);

                    counter_text.setString("KILLER");
                    counter_text.setPosition({ 20.f, 50.f });

                    started = false;
                    finished = false;

                    counter = 0u;
                }
            }
        }

        if (started)
        {
            counter_text.setString(generate_counting_string(counter, 6));
            const auto remaining = 30 - static_cast<int>(timer.getElapsedTime().asSeconds());

            if (remaining > 0)
            {
                timer_text.setString(generate_counting_string(remaining, 2));
            }
            else
            {
                finished = true;
                timer_text.setString((generate_counting_string(0, 2)));
            }
        }

        window.clear();
        window.draw(counter_text);
        window.draw(timer_text);
        window.display();
    }
}
