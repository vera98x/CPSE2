#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <string>
#include "ball.hpp"
#include "rectangle.hpp"
#include "drawable.hpp"
#include "line.hpp"
#include "picture.hpp"


class unknown_color : public std::exception {
public:
	unknown_color(const std::string & name) :
		s{ std::string{ "unknown color [" } +name + "]" }
	{}
	unknown_color() :
		s("unknown color[]")
	{}
	const char * what() const override {
		return s.c_str();
	}
private:
	std::string s;
};

class end_of_file : public std::exception {
};

class falseFilename : public std::exception {
};

class unknown_shape : public std::exception {
public:
	unknown_shape(const std::string & name) :
		s (std::string{ "unknown shape [" } + name + "]" )
	{}

	unknown_shape() :
		s ( "unknown shape []" )
	{}

	const char * what() const override {
		return s.c_str();
	}
private:
	std::string s;
};

class invalid_position : public std::exception {
public:
	invalid_position(const char & c) :
		s{ std::string{ "unknown position [" } + c + "]" }
	{}
	const char * what() const override {
		return s.c_str();
	}
private:
	std::string s;
};

std::ifstream & operator>>(std::ifstream & input, sf::Color & rhs) {
	std::string s;
	input >> s;
	const struct { const char * name; sf::Color color; } colors[]{
		{ "yellow", sf::Color::Yellow },
		{ "red",    sf::Color::Red },
		{ "blue", sf::Color::Blue},
		{ "black", sf::Color::Black},
		{ "green", sf::Color::Green },
		{ "white", sf::Color::White},
		{ "magenta", sf::Color::Magenta },
		{ "cyan", sf::Color::Cyan }
	};
	for (auto const & color : colors) {
		if (color.name == s) {
			rhs = color.color;
			return input;
		}
	}
	if (s == "") {
		throw end_of_file();
	}
	throw unknown_color(s);
}


std::ifstream & operator>>(std::ifstream & input, sf::Vector2f & rhs) {
	char c;
	if (!(input >> c)) { throw end_of_file(); }
	if (c != '(') { throw invalid_position(c); }

	if (!(input >> rhs.x)) { throw invalid_position(c); }

	if (!(input >> c)) { throw invalid_position(c); }

	if (!(input >> rhs.y)) { throw invalid_position(c); }

	if (!(input >> c)) { throw invalid_position(c); }
	if (c != ')') { throw invalid_position(c); }

	return input;
}

std::ofstream & operator<<(std::ofstream & input, const sf::Vector2f & rhs) {
	
	input << '(' << int(rhs.x) << ',' << int(rhs.y) << ')';
	return input;
}

std::ofstream & operator<<(std::ofstream & input, const sf::Color & rhs) {

	const struct { const char * name; sf::Color color; } colors[]{
		{ "yellow", sf::Color::Yellow },
		{ "red",    sf::Color::Red },
		{ "blue", sf::Color::Blue },
		{ "black", sf::Color::Black },
		{ "green", sf::Color::Green },
		{ "white", sf::Color::White },
		{ "magenta", sf::Color::Magenta },
		{ "cyan", sf::Color::Cyan }
	};
	for (auto const & color : colors) {
		if (color.color == rhs) {
			input << color.name << " ";
			return input;
		}
	}
	throw unknown_color();
}


drawable * drawable_read(std::ifstream & input) {
	sf::Vector2f position;
	std::string name;
	input >> position >> name;

	if (name == "CIRCLE") {
		sf::Color color;
		float size;
		input >> color >> size;
		
		return new ball(position, { 0,0 }, color, size);

	}
	else if (name == "RECTANGLE") {
		sf::Color color;
		sf::Vector2f size;
		input >> color >> size;
		return new rectangle(position, color);

	}

	else if (name == "LINE") {
		sf::Color color;
		sf::Vector2f size;
		input >> color >> size;
		return new line(position, color);

	}

	else if (name == "PICTURE") {
		sf::Texture t;
		std::string filename;
		input >> filename;
		if (!t.loadFromFile(filename)) {
			throw falseFilename();
		}
		
		return new picture(position, t, filename);

	}
	else if (name == "") {
		throw end_of_file();
	}

	throw unknown_shape(name);
}

sf::Vector2f Vector2f_from_Vector2i(const sf::Vector2i & rhs) {
	return sf::Vector2f(
		static_cast< float >(rhs.x),
		static_cast< float >(rhs.y)
	);
}




int main( int argc, char *argv[] ){
	std::cout << "Starting application 01-02 static ball\n";

	sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "SFML window" };
	
	std::vector<drawable *> screen_objects;

	std::ifstream input("objects.txt");
	try {
		for (;;) {
			screen_objects.push_back(drawable_read(input));
		}
		input.close();
	}
	catch (end_of_file) {
		input.close();
	}
	catch (std::exception & problem) {
		std::cout << problem.what();
		input.close();
	}

	window.clear();
	for (unsigned int i = 0; i < screen_objects.size(); i++) {
		screen_objects[i]->draw(window);
	}
	window.display();

	while (window.isOpen()) {


		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				
				std::ofstream output("tempObjects.txt");
				for (unsigned int i = 0; i < screen_objects.size(); i++) {
					screen_objects[i]->getPosition();
					output << (screen_objects[i]->getPosition());
					if (dynamic_cast<ball*>(screen_objects[i])) {
						output << " CIRCLE ";
						output << (screen_objects[i]->getColor());
						output << (screen_objects[i]->getSize().x);
					}
					else if (dynamic_cast<rectangle*>(screen_objects[i])) {
						output << " RECTANGLE ";
						output << (screen_objects[i]->getColor());
						output << (screen_objects[i]->getSize());
					} 
					else if (dynamic_cast<line*>(screen_objects[i])) {
						output << " LINE ";
						output << (screen_objects[i]->getColor());
						output << (screen_objects[i]->getSize());
					}
					else if (dynamic_cast<line*>(screen_objects[i])) {
						output << " LINE ";
						output << (screen_objects[i]->getColor());
						output << (screen_objects[i]->getSize());
					}
					else if (dynamic_cast<picture*>(screen_objects[i])) {
						output << " PICTURE ";
						output << (screen_objects[i]->getFilename());
					}
					else {
						throw unknown_shape();
					}
					output << "\n";
								
				}
				
				output.close();
				std::string lines;
				std::ifstream in("tempObjects.txt");
				std::ofstream out("objects.txt");
				while (getline(in, lines)) {
					out << lines << "\n";
				}
				in.close();
				out << lines;
				out.close();


				
				window.close();
			}
			if (event.type == sf::Event::MouseButtonPressed) {
				for (unsigned int i = 0; i < screen_objects.size(); i++) {
					sf::Vector2f pos = Vector2f_from_Vector2i(sf::Mouse::getPosition(window));
					if (screen_objects[i]->getGlobalBounds().contains(pos)) {
						while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
							sf::Vector2f pos = Vector2f_from_Vector2i(sf::Mouse::getPosition(window));
							screen_objects[i]->jump(pos);
							window.clear();
							for (unsigned int i = 0; i < screen_objects.size(); i++) {
								screen_objects[i]->draw(window);
							}
							window.display();
						}
						break;
					}
				}
				
			}
			

		}
		sf::sleep(sf::milliseconds(20));
	}
	std::cout << "Terminating application\n";
	return 0;
}

