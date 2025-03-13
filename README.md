# RthmoSphere

**RthmoSphere** is a C++ framework specialized in rhythm game development. It uses **SFML** for graphics handling and other game functionalities. This framework provides powerful tools to manage drawable objects, organize them into groups or containers, handle animations, and apply transformations through the parent-child hierarchy.

## Features

- **Drawable Object Management**: RthmoSphere allows easy management of graphical objects such as sprites, text, etc.

- **Groups and Containers**: Objects can be organized into groups or containers, making it easier to manage them and apply transformations based on their hierarchy.

- **Animation**: The framework includes animation mechanisms to create dynamic and interactive visual effects suitable for rhythm games.

- **Parent-Based Transformations**: Objects can inherit transformations applied to their parent, simplifying the management of movement, rotation, and scaling in complex scenes.

## Exemple
```cpp
const auto playField = std::make_shared<Container>();
    
const auto label = std::make_shared<Label>("GameScene", font, 32);
playField->addChild(label);

const auto boxButton = std::make_shared<BoxButton>(64, 64);
playField->addChild(boxButton);
    
label->setColor(sf::Color::Blue);
label->rotateTo(0, 360, 4096.f, 1024.f, Easing::EaseInOutQuad);
    
boxButton->setColor(sf::Color::Green);
boxButton->setOnClick([this] { onClickButton(); });
boxButton->moveTo({0, 0}, {0, 128}, 1024.f, 512.f, Easing::EaseInOutQuad);
boxButton->scaleTo({1, 1}, {0.5, 1.5}, 1024.f, 512.f, Easing::EaseInOutQuad);

playField->rotateTo(0, 40, 1024.f, 1024.f, Easing::EaseInOutQuad);

addObject(playField); // scene method that allow you to add drawable to a draw surface
```

## Installation

### Prerequisites

- **C++20** or a more recent version  
- **SFML 2.6+** (Graphics and multimedia library for C++)

### Cloning the Project

To clone the project, use the following command:

```bash
git clone https://github.com/your-username/RthmoSphere.git
