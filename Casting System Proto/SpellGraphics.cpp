#include "SpellGraphics.hpp"
#include "Player.hpp"
//SpellEffects==============================

//FireballEffects===========================


//IcewallEffects============================

//TeleportEffects===========================

FireballSpellGraphic::FireballSpellGraphic(sf::Vector2f spellTarget, Player& player)
{
	fireballSprite.setRadius(10);
	fireballSprite.setPointCount(10);
	fireballSprite.setFillColor(sf::Color::Yellow);
	fireballSprite.setOutlineColor(sf::Color::Red);
	fireballSprite.setOutlineThickness(.5);
	fireballSprite.setScale(1, 1);
	fireballSprite.setOrigin(fireballSprite.getGlobalBounds().width / 2, fireballSprite.getGlobalBounds().height / 2);
	fireballSprite.setPosition(spellTarget.x, spellTarget.y);
}
