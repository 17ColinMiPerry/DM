#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream> 
#include <chrono>
#include <thread>

int main()
{
  sf::RenderWindow window(sf::VideoMode(1200, 900), "DM Battle!", sf::Style::Titlebar | sf::Style::Close);

  sf::Texture attackOneTexture, attackTwoTexture, attackThreeTexture, attackFourTexture;
  sf::Texture benchOneTexture, benchTwoTexture, benchThreeTexture, benchFourTexture, benchFiveTexture, benchSixTexture;
  
  if (!attackOneTexture.loadFromFile("resources/UISprites/attack1.png") || !attackTwoTexture.loadFromFile("resources/UISprites/attack2.png") ||
      !attackThreeTexture.loadFromFile("resources/UISprites/attack3.png") || !attackFourTexture.loadFromFile("resources/UISprites/attack4.png") ||
      !benchOneTexture.loadFromFile("resources/UISprites/bench1.png") || !benchTwoTexture.loadFromFile("resources/UISprites/bench2.png") ||
      !benchThreeTexture.loadFromFile("resources/UISprites/bench3.png") || !benchFourTexture.loadFromFile("resources/UISprites/bench4.png") ||
      !benchFiveTexture.loadFromFile("resources/UISprites/bench5.png") || !benchSixTexture.loadFromFile("resources/UISprites/bench6.png"))
  {
    std::cout << "fuck\n";
  }
  
  sf::Sprite attackOneSprite, attackTwoSprite, attackThreeSprite, attackFourSprite;
  sf::Sprite benchOneSprite, benchTwoSprite, benchThreeSprite, benchFourSprite, benchFiveSprite, benchSixSprite;
  
  attackOneSprite.setTexture(attackOneTexture);
  attackOneSprite.setPosition(0, 600);
  attackTwoSprite.setTexture(attackTwoTexture);
  attackTwoSprite.setPosition(400, 600);
  attackThreeSprite.setTexture(attackThreeTexture);
  attackThreeSprite.setPosition(0, 750);
  attackFourSprite.setTexture(attackFourTexture);
  attackFourSprite.setPosition(400, 750);
  
  benchOneSprite.setTexture(benchOneTexture);
  benchOneSprite.setPosition(800, 600);
  benchTwoSprite.setTexture(benchTwoTexture);
  benchTwoSprite.setPosition(1000, 600);
  benchThreeSprite.setTexture(benchThreeTexture);
  benchThreeSprite.setPosition(800, 700);
  benchFourSprite.setTexture(benchFourTexture);
  benchFourSprite.setPosition(1000, 700);
  benchFiveSprite.setTexture(benchFiveTexture);
  benchFiveSprite.setPosition(800, 800);
  benchSixSprite.setTexture(benchSixTexture);
  benchSixSprite.setPosition(1000, 800);
  
  
  sf::Music music;
  if (!music.openFromFile("resources/MusicAndSFX/battle.wav"))
  {
    std::cout << "fuck\n";
  }
  music.play();
  
  while (window.isOpen())
  {
    sf::Event event;
    
    if (window.getSize().x != 1200 || window.getSize().y != 900)
    {
      sf::Vector2u wSize(1200, 900);
      window.setSize(wSize);
    }
    
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
    
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
      std::this_thread::sleep_for(std::chrono::milliseconds(95));
      sf::Vector2i position = sf::Mouse::getPosition(window);
      sf::Vector2f v2f = sf::Vector2f(position);
      
      
      if(attackOneSprite.getGlobalBounds().contains(v2f))
      {
        std::cout << "One\n";
      }
      if(attackTwoSprite.getGlobalBounds().contains(v2f))
      {
        std::cout << "Two\n";
      }
      if(attackThreeSprite.getGlobalBounds().contains(v2f))
      {
        std::cout << "Three\n";
      }
      if(attackFourSprite.getGlobalBounds().contains(v2f))
      {
        std::cout << "Four\n";
      }
    }
    
    
    window.clear();
    window.draw(attackOneSprite);
    window.draw(attackTwoSprite);
    window.draw(attackThreeSprite);
    window.draw(attackFourSprite);
    
    window.draw(benchOneSprite);
    window.draw(benchTwoSprite);
    window.draw(benchThreeSprite);
    window.draw(benchFourSprite);
    window.draw(benchFiveSprite);
    window.draw(benchSixSprite);

    window.display();
  }
  
  return 0;
}