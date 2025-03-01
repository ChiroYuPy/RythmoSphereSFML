#include "Renderer.h"
#include "TextureManager.h"
#include <SFML/Graphics.hpp>

void Renderer::drawHitObject(sf::RenderWindow& window, const HitObject& hitCircle) {
    // Appel des méthodes pour dessiner les deux parties de l'objet
    drawHitCircle(window, hitCircle);

    // Ici, on passe une couleur spécifique pour l'overlay, par exemple, rouge
    drawHitCircleOverlay(window, hitCircle, sf::Color::Red);  // Ou toute autre couleur
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
