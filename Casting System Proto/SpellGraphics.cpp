#include "SpellGraphics.hpp"
#include "Player.hpp"
#include <cmath>
#include <vector>
#include <algorithm>

//SpellEffects==============================

#define M_PI 3.14159265358979323846

void SpellGraphics::UpdateSpellPositions()
{
	// Remove elements marked for deletion using erase-remove idiom
	fireballEffects.erase(std::remove_if(fireballEffects.begin(), fireballEffects.end(),
		[](const FireballSpellGraphic& effect) { return effect.ShouldBeDeleted(); }), fireballEffects.end());

	// Update positions for remaining effects
	for (auto& effect : fireballEffects)
	{
		effect.UpdatePosition();
	}

	icewallEffects.erase(std::remove_if(icewallEffects.begin(), icewallEffects.end(),
		[](const IcewallSpellGraphic& effect) { return effect.ShouldBeDeleted(); }), icewallEffects.end());
	for (auto& effect : icewallEffects)
	{
		effect.UpdatePosition();
	}

}

void SpellGraphics::DrawSpellEffects(sf::RenderWindow& window)
{
	if (fireballEffects.size() > 0)
	{
		for (size_t i = 0; i < fireballEffects.size(); ++i)
		{
			window.draw(fireballEffects[i].fireballGraphics());
		}
	}

	if (icewallEffects.size() > 0)
	{
		for (size_t i = 0; i < icewallEffects.size(); ++i)
		{
			window.draw(icewallEffects[i].icewallGraphics());
		}
	}
}


//FireballEffects===========================

FireballSpellGraphic::FireballSpellGraphic(sf::Vector2f spellTarget, Player& player)
{
	direction = spellTarget - player.GetSprite().getPosition();

	float magnitude = std::sqrt(direction.x * direction.x + direction.y * direction.y);
	sf::Vector2f normalizedDirection = direction / magnitude;

	velocity.x = normalizedDirection.x * speed;
	velocity.y = normalizedDirection.y * speed;

	fireballGraphics().setRadius(15);
	fireballGraphics().setPointCount(8);
	fireballGraphics().setFillColor(sf::Color::Red);
	fireballGraphics().setOutlineColor(sf::Color::Yellow);
	fireballGraphics().setOutlineThickness(1.5);
	fireballGraphics().setScale(1, 1);
	fireballGraphics().setOrigin(fireballSprite.getGlobalBounds().width / 2, fireballSprite.getGlobalBounds().height / 2);
	fireballGraphics().setPosition(player.GetSprite().getPosition().x, player.GetSprite().getPosition().y);

}

sf::CircleShape& FireballSpellGraphic::fireballGraphics()
{
	return fireballSprite;
}

void FireballSpellGraphic::UpdatePosition()
{
	fireballGraphics().move(velocity);

	if (fireballDurationClock.getElapsedTime().asSeconds() > fireballDuration)
	{
		markedForDeletion = true;
	}

}

bool FireballSpellGraphic::ShouldBeDeleted() const
{
	return markedForDeletion;
}

float& FireballSpellGraphic::GetSpellDamage()
{
	return spellDamage;
}

void FireballSpellGraphic::MarkForDeletion()
{
	markedForDeletion = true;
}

//IcewallEffects============================

IcewallSpellGraphic::IcewallSpellGraphic(sf::Vector2f spellTarget, Player& player)
{
	icewallShape.setFillColor(sf::Color::Blue);
	icewallShape.setOutlineColor(sf::Color::White);
	icewallShape.setOutlineThickness(0.5f);
	icewallShape.setSize(sf::Vector2f(50, 75));
	icewallShape.setOrigin(icewallShape.getGlobalBounds().width / 2, icewallShape.getGlobalBounds().height / 2);
	icewallShape.setPosition(spellTarget);

	float dx = spellTarget.x - player.GetSprite().getPosition().x;
	float dy = spellTarget.y - player.GetSprite().getPosition().y;
	float angle = atan2(dy, dx) * 180 / M_PI; // Convert radians to degrees

	// Set the rotation of the ice block to face the calculated angle
	icewallShape.setRotation(angle);
}

void IcewallSpellGraphic::UpdatePosition()
{
	if (icewallDurationClock.getElapsedTime().asSeconds() > icewallDuration)
	{
		markedForDeletion = true;
	}
}

bool IcewallSpellGraphic::ShouldBeDeleted() const
{
	return markedForDeletion;
}

sf::RectangleShape& IcewallSpellGraphic::icewallGraphics()
{
	return icewallShape;
}

//TeleportEffects===========================


