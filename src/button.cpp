#include "shared_font.hpp"
#include "button.hpp"

namespace UI {
namespace Controls {

Button::Button()
{
	base.setCornersRadius(2.f);
	base.setCornerPointCount(4);
	base.setFillColor(sf::Color::White);

	text.setFont(::SharedFont::getInstance().font);
	text.setFillColor(sf::Color::Red);
	update();
}

void Button::setString(const sf::String& str)
{
	text.setString(str);
	update();
}

void Button::setPosition(sf::Vector2f pos)
{
    Control::setPosition(pos);
    setMouseCatchOffset(pos);
}

void Button::setPosition(float x, float y)
{
    setPosition(sf::Vector2f(x, y));
}

void Button::setSize(sf::Vector2f size)
{
    Control::setSize(size);
    setMouseCatchSize(size);
}

void Button::setSize(float x, float y)
{
    setSize(sf::Vector2f(x, y));
}

void Button::update()
{
	base.setSize( m_size );
	base.setCornersRadius( m_size.y*2/50.f );

	sf::FloatRect textBounds = text.getLocalBounds();
	float textCharacterSize = m_size.y*0.48f;
	text.setCharacterSize( textCharacterSize );
	text.setPosition(m_size.x/2.f - textBounds.width/2.f, m_size.y/2.f - (textCharacterSize/2.f + m_size.y*3/50) );
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform = getTransform();
	target.draw( base, states );
	target.draw( text, states );
}

void Button::onMouseClick()
{
    base.setFillColor(sf::Color::Red);
}

}
}
