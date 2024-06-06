#include "SpellGraphics.hpp"
#include "Player.hpp"
#include <cmath>
#include <vector>
#include <algorithm>

//SpellEffects==============================

#define M_PI 3.14159265358979323846

SpellGraphics::SpellGraphics()
{
		fireBallTex.loadFromFile("C:/Users/vampi/source/repos/Casting System Proto/Sprites/Spell Effects/Fireball.png");
		icewallTex.loadFromFile("C:/Users/vampi/source/repos/Casting System Proto/Sprites/Spell Effects/Icewall.png");
}

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

FireballSpellGraphic::FireballSpellGraphic(sf::Vector2f spellTarget, Player& player, sf::Texture& fireballTex)
{
	direction = spellTarget - player.GetSprite().getPosition();

	float magnitude = std::sqrt(direction.x * direction.x + direction.y * direction.y);
	sf::Vector2f normalizedDirection = direction / magnitude;

	velocity.x = normalizedDirection.x * speed;
	velocity.y = normalizedDirection.y * speed;

	fireballSprite.setTexture(fireballTex);

	fireballGraphics().setScale(2, 2);
	fireballGraphics().setOrigin(fireballSprite.getGlobalBounds().width / 2, fireballSprite.getGlobalBounds().height / 2);
	fireballGraphics().setPosition(player.GetSprite().getPosition().x, player.GetSprite().getPosition().y);
}

sf::Sprite& FireballSpellGraphic::fireballGraphics()
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

IcewallSpellGraphic::IcewallSpellGraphic(sf::Vector2f spellTarget, Player& player, sf::Texture& icewallTex)
{
	icewallSprite.setTexture(icewallTex);
	icewallSprite.setOrigin(icewallSprite.getGlobalBounds().width / 2, icewallSprite.getGlobalBounds().height / 2);
	icewallSprite.setPosition(spellTarget);
	icewallSprite.setScale(4, 4);

	float dx = spellTarget.x - player.GetSprite().getPosition().x;
	float dy = spellTarget.y - player.GetSprite().getPosition().y;
	float angle = atan2(dy, dx) * 270 / M_PI; // Convert radians to degrees

	// Set the rotation of the ice block to face the calculated angle
	icewallSprite.setRotation(angle);
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

sf::Sprite& IcewallSpellGraphic::icewallGraphics()
{
	return icewallSprite;
}

//TeleportEffects===========================


