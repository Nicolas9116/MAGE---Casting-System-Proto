#include "SpellGraphics.hpp"
#include "Player.hpp"

//SpellEffects==============================

//FireballEffects===========================


//IcewallEffects============================

//TeleportEffects===========================

FireballSpellGraphic::FireballSpellGraphic(sf::Vector2i spellTarget, Player& player)
{
	fireballgraphics().setRadius(10);
	fireballgraphics().setPointCount(10);
	fireballgraphics().setFillColor(sf::Color::Yellow);
	fireballgraphics().setOutlineColor(sf::Color::Red);
	fireballgraphics().setOutlineThickness(.5);
	fireballgraphics().setScale(1, 1);
	fireballgraphics().setOrigin(fireballSprite.getGlobalBounds().width / 2, fireballSprite.getGlobalBounds().height / 2);
	fireballgraphics().setPosition(spellTarget.x, spellTarget.y);
}

sf::CircleShape& FireballSpellGraphic::fireballgraphics()
{
	return fireballSprite;
}
