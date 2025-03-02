#include "Renderer.h"

#include <iostream>

#include "TextureManager.h"
#include <SFML/Graphics.hpp>

void Renderer::drawHitObject(sf::RenderWindow& window, const HitObject& hitCircle) {

    drawHitCircle(window, hitCircle);
    drawHitCircleOverlay(window, hitCircle, sf::Color::Red);
    drawComboOverlay(window, hitCircle, sf::Color::White);
}

void Renderer::drawHitCircle(sf::RenderWindow& window, const HitObject& hitCircle) {
    GameManager& gameManager = GameManager::getInstance();

    // Créer et configurer le sprite pour le hitCircle
    sf::Sprite hitCircleSprite;
    hitCircleSprite.setTexture(TextureManager::getTexture("hitCircle"));

    float radius = gameManager.GetHitObjectSize() * gameManager.getPlayground().getZoom();
    sf::FloatRect hitCircleBounds = hitCircleSprite.getLocalBounds();

    // Calculer l'échelle et appliquer la mise à l'échelle
    float doubleRadius = radius * 2;
    hitCircleSprite.setScale(doubleRadius / hitCircleBounds.width, doubleRadius / hitCircleBounds.height);

    // Positionner le sprite du hitCircle
    float x = static_cast<float>(hitCircle.data.x);
    float y = static_cast<float>(hitCircle.data.y);
    sf::Vector2f windowPos = gameManager.getPlayground().convertPlaygroundToWindowPosition(sf::Vector2f(x, y));
    hitCircleSprite.setPosition(windowPos.x - radius, windowPos.y - radius);

    // Calculer l'alpha en fonction de l'avancement
    float alpha = static_cast<int>(255 * (1 - hitCircle.getAdvance()));
    sf::Color currentColor = hitCircleSprite.getColor();
    currentColor.a = static_cast<sf::Uint8>(alpha);
    hitCircleSprite.setColor(currentColor);

    // Dessiner le hitCircle
    window.draw(hitCircleSprite);
}

void Renderer::drawHitCircleOverlay(sf::RenderWindow& window, const HitObject& hitCircle, const sf::Color& overlayColor) {
    GameManager& gameManager = GameManager::getInstance();

    // Créer et configurer le sprite pour le hitCircleOverlay
    sf::Sprite hitCircleOverlaySprite;
    hitCircleOverlaySprite.setTexture(TextureManager::getTexture("hitCircleOverlay"));

    float radius = gameManager.GetHitObjectSize() * gameManager.getPlayground().getZoom();
    sf::FloatRect hitCircleOverlayBounds = hitCircleOverlaySprite.getLocalBounds();

    // Calculer l'échelle et appliquer la mise à l'échelle
    float doubleRadius = radius * 2;
    hitCircleOverlaySprite.setScale(doubleRadius / hitCircleOverlayBounds.width, doubleRadius / hitCircleOverlayBounds.height);

    // Positionner le sprite du hitCircleOverlay
    float x = static_cast<float>(hitCircle.data.x);
    float y = static_cast<float>(hitCircle.data.y);
    sf::Vector2f windowPos = gameManager.getPlayground().convertPlaygroundToWindowPosition(sf::Vector2f(x, y));
    hitCircleOverlaySprite.setPosition(windowPos.x - radius, windowPos.y - radius);

    // Calculer l'alpha en fonction de l'avancement
    float alpha = static_cast<int>(255 * (1 - hitCircle.getAdvance()));
    sf::Color overlayCurrentColor = overlayColor;
    overlayCurrentColor.a = static_cast<sf::Uint8>(alpha);  // Appliquer l'alpha à la couleur
    hitCircleOverlaySprite.setColor(overlayCurrentColor);

    // Dessiner le hitCircleOverlay
    window.draw(hitCircleOverlaySprite);
}

void Renderer::drawComboOverlay(sf::RenderWindow& window, const HitObject& hitCircle, const sf::Color& overlayColor) {
    GameManager& gameManager = GameManager::getInstance();

    int combo = hitCircle.data.comboNumber;
    std::string comboStr = std::to_string(combo);

    // Position du centre du hitCircle
    float x = static_cast<float>(hitCircle.data.x);
    float y = static_cast<float>(hitCircle.data.y);
    sf::Vector2f windowPos = gameManager.getPlayground().convertPlaygroundToWindowPosition(sf::Vector2f(x, y));

    // Calculer le rayon du hitCircle
    float radius = gameManager.GetHitObjectSize() * gameManager.getPlayground().getZoom();

    std::vector<sf::Sprite> digitSprites;

    // Créer les sprites des chiffres et calculer la largeur totale
    for (char c : comboStr) {
        std::string textureName = std::to_string(c - '0');
        sf::Sprite digitSprite;
        digitSprite.setTexture(TextureManager::getTexture(textureName));

        // Ajuster la taille des chiffres pour qu'ils aient la hauteur égale à celle du radius
        float scale = radius * 2.0f / digitSprite.getLocalBounds().height;
        digitSprite.setScale(scale, scale);

        digitSprites.push_back(digitSprite);
    }

    int numDigit = comboStr.size();

    // Calculer l'offset X pour centrer les chiffres
    float spaceFactor = 0.25f;
    float offsetX = -(radius * (numDigit - 1) * spaceFactor);

    // Dessiner les chiffres un par un
    for (sf::Sprite& digitSprite : digitSprites) {
        digitSprite.setPosition(windowPos.x - radius + offsetX, windowPos.y - radius);

        // Appliquer la couleur et dessiner le sprite
        digitSprite.setColor(overlayColor);
        window.draw(digitSprite);

        // Mettre à jour l'offset pour le prochain chiffre
        offsetX += digitSprite.getLocalBounds().width * digitSprite.getScale().x * spaceFactor; // utiliser l'échelle pour la largeur
    }
}
