#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <time.h>
#include<string>
#include<iostream>
using namespace std;
using namespace sf;

const int M = 20; // Grid Row
const int N = 10; // Grid Column
bool release = true; // Mouse Button Released
int score=0,highscore=0; // Score
// BLocks will be stored in field
int field[M][N] = {0};
float delay,Delay = delay = 0.3;

struct Point
{
    int x,y;

} a[4], b[4];

int figures[7][4] =
{
	1,3,5,7, // I
	2,4,5,7, // Z
	3,5,4,6, // S
	3,5,4,7, // T
	2,3,5,7, // L
	3,5,7,6, // J
	2,3,4,5, // O
};

bool check()
{
   for (int i=0;i<4;i++)
	  if (a[i].x<0 || a[i].x>=N || a[i].y>=M) return 0;
      else if (field[a[i].y][a[i].x]) return 0;

   return 1;
};


int main()
{


    srand(time(0)); // Random initialization

	RenderWindow window(VideoMode(320, 480), "TETRIS ULTIMATE");
	window.setVerticalSyncEnabled(true);




goto main_menu;

	main_menu:{ ///main menu image
	Texture main_menu;
		main_menu.loadFromFile("f.png");
		Sprite menu;
		menu.setTexture(main_menu);
		////////////////////////////////////////////////music
		//sound

		Music dj;
		dj.openFromFile("Intro.ogg");




		//sound
		sf::Font title;
		title.loadFromFile("Dopestyle.ttf");


		sf::Text ttl("Tetris", title, 50);
		ttl.setStyle(sf::Text::Bold);
		ttl.setColor(sf::Color::Green);

		ttl.setPosition(280 / 2 - ttl.getGlobalBounds().width / 2 , 130);
		sf::Mouse::setPosition(sf::Vector2i(10, 100), window);



		sf::Text menu_text[4];

		window.draw(menu);
		window.draw(ttl);

		string str[] = { "new game", "high score","credit", "exit" };
		int k;
		for (k = 0; k < 4; k++)
		{
			menu_text[k].setFont(title);
			menu_text[k].setCharacterSize(20);
			menu_text[k].setString(str[k]);
			menu_text[k].setColor(sf::Color::White);
			menu_text[k].setPosition(100, 200 + k * 60);
			window.draw(menu_text[k]);
		}

		while (window.isOpen())
		{
		    if(dj.getStatus() != Music::Playing)
                dj.play();
			sf::Event event;
			sf::Vector2f mouse(sf::Mouse::getPosition(window));
			while (window.pollEvent(event))
			{
				switch (event.type)
				{
				case sf::Event::Closed:
					window.close();

					break;


				case sf::Event::MouseButtonPressed:

					if (release && (menu_text[0].getGlobalBounds().contains(mouse)))
					  goto level;

					if (release && (menu_text[1].getGlobalBounds().contains(mouse)))
				{

						goto HIGHSCORE;
					}
				if (release && (menu_text[2].getGlobalBounds().contains(mouse))){
						goto credit;

					}
					if (release && (menu_text[3].getGlobalBounds().contains(mouse)))
						exit(0);

					release = false;
					break;

				case sf::Event::MouseButtonReleased:
					release = true;
					break;
				}

			}

			window.draw(menu);
			window.draw(ttl);




			if (menu_text[0].getGlobalBounds().contains(mouse))
			{
				menu_text[0].setColor(sf::Color::White);
				menu_text[0].setCharacterSize(55);
			}
			else
			{
				menu_text[0].setColor(sf::Color::Cyan);
				menu_text[0].setCharacterSize(45);
			}

			if (menu_text[1].getGlobalBounds().contains(mouse))
			{
				menu_text[1].setColor(sf::Color::Cyan);
				menu_text[1].setCharacterSize(55);
			}
			else
			{
				menu_text[1].setColor(sf::Color::Cyan);
				menu_text[1].setCharacterSize(45);
			}

			if (menu_text[2].getGlobalBounds().contains(mouse))
			{
				menu_text[2].setColor(sf::Color::Cyan);
				menu_text[2].setCharacterSize(55);
			}
			else
			{
				menu_text[2].setColor(sf::Color::Cyan);
				menu_text[2].setCharacterSize(45);
			}
			if (menu_text[3].getGlobalBounds().contains(mouse))
			{
				menu_text[3].setColor(sf::Color::Cyan);
				menu_text[3].setCharacterSize(55);
			}
			else
			{
				menu_text[3].setColor(sf::Color::Cyan);
				menu_text[3].setCharacterSize(45);
			}

			window.draw(menu_text[0]);
			window.draw(menu_text[1]);
			window.draw(menu_text[2]);
			window.draw(menu_text[3]);
			window.display();
		}
}



level:
    {

        Texture main_menu;
		main_menu.loadFromFile("f.png");
		Sprite menu;
		menu.setTexture(main_menu);
		////////////////////////////////////////////////music
		//sound

		Music dj;
		dj.openFromFile("DarkKnight.ogg");




		//sound
		sf::Font title;
		title.loadFromFile("t3.ttf");


		sf::Text ttl("Tetris", title, 50);
		ttl.setStyle(sf::Text::Bold);
		ttl.setColor(sf::Color::Green);

		ttl.setPosition(280 / 2 - ttl.getGlobalBounds().width / 2 , 130);
		sf::Mouse::setPosition(sf::Vector2i(10, 100), window);



		sf::Text menu_text[3];

		window.draw(menu);
		window.draw(ttl);

		string str[] = { "EASY", "MEDIUM", "HARD", };
		int k;
		for (k = 0; k < 3; k++)
		{
			menu_text[k].setFont(title);
			menu_text[k].setCharacterSize(10);
			menu_text[k].setString(str[k]);
			menu_text[k].setColor(sf::Color::White);
			menu_text[k].setPosition(100, 200 + k * 70);
			window.draw(menu_text[k]);
		}

		while (window.isOpen())
		{
		    if(dj.getStatus() != sf::Music::Playing)
                dj.play();
			sf::Event event;
			sf::Vector2f mouse(sf::Mouse::getPosition(window));
			while (window.pollEvent(event))
			{
				switch (event.type)
				{
				case sf::Event::Closed:
					window.close();

					break;

				case sf::Event::MouseButtonPressed:

					if (release && (menu_text[0].getGlobalBounds().contains(mouse)))
					  {
					      Delay = 0.3;
					      goto main_game;
					  }

					if (release && (menu_text[1].getGlobalBounds().contains(mouse)))
				{

						Delay=.2;
						goto main_game;
					}
				if (release && (menu_text[2].getGlobalBounds().contains(mouse))){
						Delay=.1;
						goto main_game;
					}


					release = false;
					break;

				case sf::Event::MouseButtonReleased:
					release = true;
					break;
				}

			}

			window.draw(menu);
			window.draw(ttl);




			if (menu_text[0].getGlobalBounds().contains(mouse))
			{
				menu_text[0].setColor(sf::Color::White);
				menu_text[0].setCharacterSize(55);
			}
			else
			{
				menu_text[0].setColor(sf::Color::Red);
				menu_text[0].setCharacterSize(45);
			}

			if (menu_text[1].getGlobalBounds().contains(mouse))
			{
				menu_text[1].setColor(sf::Color::Green);
				menu_text[1].setCharacterSize(55);
			}
			else
			{
				menu_text[1].setColor(sf::Color::Red);
				menu_text[1].setCharacterSize(45);
			}

			if (menu_text[2].getGlobalBounds().contains(mouse))
			{
				menu_text[2].setColor(sf::Color::Cyan);
				menu_text[2].setCharacterSize(55);
			}
			else
			{
				menu_text[2].setColor(sf::Color::Red);
				menu_text[2].setCharacterSize(45);
			}

			window.draw(menu_text[0]);
			window.draw(menu_text[1]);
			window.draw(menu_text[2]);
			window.display();
		}
    }


    HIGHSCORE:
        {
    freopen("HIGHSCORE","r",stdin);
    cin >> highscore;
    cout << highscore;

    Music dj;
		dj.openFromFile("hscore.ogg");

            Font font;
            font.loadFromFile("Dopestyle.ttf");

            sf:: Text high;

            char h[100];
    //sprintf(h,"%d",highscore);
    sf:: Text highScore;
    sf::Font f;
    f.loadFromFile("Dopestyle.ttf");
    highScore.setFont(f);
    highScore.setCharacterSize(45);
    highScore.setString(h);
    highScore.setColor(Color::Black);
    highScore.setPosition(10,80);

            Texture Scoreback;
            Scoreback.loadFromFile("hscore.png");

            Sprite score;
            score.setTexture(Scoreback);

            while(window.isOpen())
            {
                sprintf(h,"High score =%d",highscore);
                highScore.setString(h);
                Event e;

                while(window.pollEvent(e))
                {
                    if(dj.getStatus() != Music::Playing)
            dj.play();
                    if(e.type==Event::Closed)
                        window.close();

                        if(e.type == sf::Event::KeyPressed )
            {
                if(e.key.code == sf::Keyboard::Escape)
                {
                    goto main_game;
                }
            }
                }

                window.draw(score);
                window.draw(highScore);
                window.display();
            }
        }


          /**Credit**/


          credit:
{
    window.clear();
    sf::Texture theEndTexture;
    theEndTexture.loadFromFile("cr.jpg");
    sf::Sprite theEnd(theEndTexture);
    theEnd.setPosition(sf::Vector2f(0,0));

    sf::Font inst2;
    inst2.loadFromFile("t4.ttf");
    sf::Text instruction2("Use arrow keys to move the \nblocks.\nIf the blocks fill up one \nvertical line,they will vanish \nand you will get points.\nIf the stack is full,the game \nwill be over .\n\n This is our first game project..\n developed by Fahim & Tasmia",inst2,25);
    instruction2.setPosition(sf::Vector2f(0,10));
    //instruction2.setStyle(sf::Text::Bold);
    instruction2.setColor(sf::Color::Black);
//
//    sf::RectangleShape RectS;
//    RectS.setSize(sf::Vector2f(100.f,50.f));
//    RectS.setPosition(sf::Vector2f(25.f,YY-350));
//    RectS.setFillColor(sf::Color::Black);

    sf::Font inst1;
    inst1.loadFromFile("Dopestyle.ttf");
    sf::Text instruction1("Press ESc For\n MainMenu",inst1,25);
    instruction1.setPosition(sf::Vector2f(10,420));
    instruction1.setColor(sf::Color(295,188,189));


    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::KeyPressed )
            {
                if(event.key.code == sf::Keyboard::Escape)
                {
                    goto main_game;
                }
            }


        }
        window.draw(theEnd);
        //window.draw(RectS);
        window.draw(instruction2);
        window.draw(instruction1);
        window.display();
    }
}





	main_game:{
	    srand(time(0));

	RenderWindow window(VideoMode(320, 480), "MY TETRIS!");

	Music m;
	m.openFromFile("background.ogg");

    Texture t1,t2,t3;
	t1.loadFromFile("images/tiles.png");
	t2.loadFromFile("images/background.png");
	t3.loadFromFile("images/frame.png");

	Sprite s(t1), background(t2), frame(t3);

    int dx=0; bool rotate=0; int colorNum=1;
	float timer=0;

	Clock clock;

    while (window.isOpen())
    {
        if(m.getStatus() != Music::Playing)
            m.play();

		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer+=time;

        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
                window.close();

			if (e.type == Event::KeyPressed)
			  if (e.key.code==Keyboard::Up) rotate=true;
			  else if (e.key.code==Keyboard::Left) dx=-1;
			  else if (e.key.code==Keyboard::Right) dx=1;
		}

	if (Keyboard::isKeyPressed(Keyboard::Down)) delay=0.05;

	//// <- Move -> ///
	for (int i=0;i<4;i++)  {
    b[i]=a[i];
	a[i].x+=dx;
	}
    if (!check()) for (int i=0;i<4;i++) a[i]=b[i];

	//////Rotate//////
	if (rotate)
	  {
		Point p = a[1]; //center of rotation
		for (int i=0;i<4;i++)
		  {
			int x = a[i].y-p.y;
			int y = a[i].x-p.x;
			a[i].x = p.x - x;
			a[i].y = p.y + y;
	 	  }
   	    if (!check()) for (int i=0;i<4;i++) a[i]=b[i];
	  }

	///////Tick//////
	if (timer>delay)
	  {
	    for (int i=0;i<4;i++) { b[i]=a[i]; a[i].y+=1; }

		if (!check())
		{
		 for (int i=0;i<4;i++) field[b[i].y][b[i].x]=colorNum;

		 colorNum=1+rand()%7;
		 int n=rand()%7;
		 for (int i=0;i<4;i++)
		   {
		    a[i].x = figures[n][i] % 2;
		    a[i].y = figures[n][i] / 2;
		   }
		}

	  	timer=0;
	  }

	///////check lines//////////
    int k=19;

	for (int i=19;i>0;i--)
	{
		int count=0;

		for (int j=0;j<N;j++)
		{
		    if (field[i][j]) count++;
		    field[k][j]=field[i][j];
		}

		if (count<N)
        {
            k--;

        }
        else
            score+=10;
        }

        /**Score**/

    char S[80];
    sprintf(S,"Score : %d",score);
    sf::Text text;
    sf::Font f;
    f.loadFromFile("Dopestyle.ttf");
    text.setFont(f);
    text.setCharacterSize(30);
    text.setPosition(sf::Vector2f(20,420));
    text.setString(S);
    text.setColor(Color::Black);


	/***GAME OVER***/

	for(int j=1;j<10;j++)
    {

        if(field[1][j])
        {
            if(score>highscore)
        highscore=score;
        m.stop();

       goto gameOver;
        }
    }
    ///if(flag)goto gameOver;

    dx=0; rotate=0; delay=Delay;

    /////////draw//////////
    window.clear(Color::White);
    window.draw(background);

	for (int i=0;i<M;i++)
	 for (int j=0;j<N;j++)
	   {
         if (field[i][j]==0) continue;
		 s.setTextureRect(IntRect(field[i][j]*18,0,18,18));
		 s.setPosition(j*18,i*18);
		 s.move(28,31); //offset
		 window.draw(s);
	   }

	for (int i=0;i<4;i++)
	  {
		s.setTextureRect(IntRect(colorNum*18,0,18,18));
		s.setPosition(a[i].x*18,a[i].y*18);
		s.move(28,31); //offset
		window.draw(s);
	  }

	window.draw(frame);
	window.draw(text);
 	window.display();
	}
gameOver:
{
    freopen("HIGHSCORE","w",stdout);
    cout<<highscore<<endl;

    Music dj;
    dj.stop();

		dj.openFromFile("demon.ogg");



    sf::Font font;
    font.loadFromFile("Dopestyle.ttf");
    sf::Text GameOverText("Game Over",font,120);
    GameOverText.setPosition(sf::Vector2f(20,400));
    GameOverText.setStyle(sf::Text::Italic);
    GameOverText.setColor(sf::Color::Red);

    sf::Texture theEndTexture;
    theEndTexture.loadFromFile("images/gam.jpg");
    sf::Sprite theEnd(theEndTexture);
    //theEnd.setPosition(sf::Vector2f(0,200.f));
    while(window.isOpen())
    {

        if(dj.getStatus() != sf::Music::Playing)
                dj.play();

        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();

        }
        window.draw(theEnd);
        //window.draw(GameOverText);
        window.display();
    }
}



	}

	return 0;
}
