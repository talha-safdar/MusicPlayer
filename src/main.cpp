#include <iostream>
#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>

int main()
{
    sf::RenderWindow window{ {400, 600}, "TGUI example - SFML_GRAPHICS backend", sf::Style::None };
    tgui::Gui gui{ window };

    // std::cout << "btn: " << button->getScaleOrigin().x << " " << button->getSize().y << std::endl;

    // labels
    auto emailLabel = tgui::Label::create("Enter email:");
    emailLabel->getRenderer()->setTextColor(sf::Color::Red);
    emailLabel->setOrigin(emailLabel->getScale().x / 2, emailLabel->getScale().y / 2);
    emailLabel->setPosition(window.getSize().x / 2, window.getSize().y / 2 * 0.72);

    auto passLabel = tgui::Label::create("Enter password:");
    passLabel->getRenderer()->setTextColor(sf::Color::Red);
    passLabel->setOrigin(passLabel->getScale().x / 2, passLabel->getScale().y / 2);
    passLabel->setPosition(window.getSize().x / 2, window.getSize().y / 2 * 0.92);

    auto signUpLabel = tgui::Label::create("Sign Up");
    signUpLabel->getRenderer()->setTextColor(sf::Color::Red);
    signUpLabel->setOrigin(signUpLabel->getScale().x / 2, signUpLabel->getScale().y / 2);
    signUpLabel->setPosition(window.getSize().x / 2, window.getSize().y / 2 / 0.73);


    // email text box
    auto emailInput = tgui::EditBox::create();
    emailInput->setOrigin(emailInput->getScale().x / 2, emailInput->getScale().y / 2);
    emailInput->setPosition(window.getSize().x / 2, window.getSize().y / 2 * 0.8);


    // password text box
    auto passInput = tgui::EditBox::create();
    passInput->setOrigin(passInput->getScale().x / 2, passInput->getScale().y / 2);
    passInput->setPosition(window.getSize().x / 2, window.getSize().y / 2 * 1.0);


    // login button
    auto loginButton = tgui::Button::create("Login");
    loginButton->setOrigin(loginButton->getScale().x / 2, loginButton->getScale().y / 2);
    loginButton->setPosition(window.getSize().x / 2, window.getSize().y / 2 / 0.8);
    loginButton->setSize(120, 40);


    // add widgets
    gui.add(emailLabel);
    gui.add(passLabel);
    gui.add(signUpLabel);
    gui.add(emailInput, "emailTextBox");
    gui.add(passInput, "passTextBox");
    gui.add(loginButton);


    tgui::Label::Ptr label = tgui::Label::create("empty");
    label->setPosition(400, 500);
    gui.add(label);

    loginButton->onClick([label]() {
        label->setText("You clicked me");
        });

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            gui.handleEvent(event);

            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

        }

        window.clear(sf::Color::Black);

        gui.draw();

        window.display();
    }
}