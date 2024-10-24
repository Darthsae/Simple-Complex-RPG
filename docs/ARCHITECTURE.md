# Project Architecture Overview

This document provides an overview of the software architecture for this project. It outlines the main components, their interactions, and the design decisions behind the current implementation.

## 1. **High-Level Overview**
The project is structured around a modular architecture where different systems (e.g., rendering, physics, networking) are decoupled and managed via an **Entity-Component-System (ECS)** framework. This enables flexible, scalable management of entities in the game world. Granted this isn't well implemented at the moment.

### Main Components:
- **Entity-Component-System (ECS)**: Manages game entities and their components using EnTT.
- **Rendering System**: Responsible for drawing the game to the screen using SDL2.
- **Physics System**: Handles physics simulations using Box2D.
- **Networking System**: Uses Boost.Asio for multiplayer communication with custom packet struct.
- **Input Handling**: Manages player input from keyboard/mouse or controllers.
- **UI System**: Uses ImGui for rendering debug interfaces and menus.

## 2. **Component Breakdown**

### 2.1 Entity-Component-System (ECS)
The ECS is at the core of the project, managing game entities and their behavior through components and systems. Entities are composed of multiple components, and each system operates on a specific type of component.

- **Entities**: Lightweight identifiers that represent objects in the game world (e.g., players, enemies, projectiles).
- **Components**: Attach to entities to define specific attributes or behaviors (e.g., Position, Velocity, Health).
- **Systems**: Process components in bulk to execute game logic (e.g., MovementSystem, RenderSystem, PhysicsSystem).

> **Design Decision**: ECS allows for easy addition and removal of components from entities, enabling dynamic behavior at runtime.

### 2.2 Rendering System
- **Library**: SDL2
- **Responsibility**: The rendering system draws game objects to the screen. It interacts with the ECS to query entities that have a `Drawable` and renders them accordingly.
  
  This system uses SDL2 to:
  - Load textures.
  - Draw sprites on the screen. (Planned)
  - Handle windowing and display.

> **Design Decision**: SDL2 was chosen for its simplicity and cross-platform support for 2D rendering.

### 2.3 Physics System
- **Library**: Box2D
- **Responsibility**: The physics system updates the physical state of entities using Box2D. It processes entities with physics-related components like `RigidBody2f` and `ColliderComponent`.

- **Box2D** handles:
  - Collision detection.
  - Rigid body dynamics (e.g., gravity, forces).
  - Contact resolution between entities.

> **Design Decision**: Box2D was chosen for its efficient 2D physics simulation, making it ideal for game development. (And because I couldn't get Edyn to work.)

### 2.4 Networking System
- **Library**: Boost.Asio
- **Responsibility**: The networking system handles multiplayer functionality. It communicates with the server/client using Boost.Asio for asynchronous I/O operations.

The system is responsible for:
  - Sending and receiving packets.
  - Managing network connections.
  - Synchronizing game state between clients and the server.

> **Design Decision**: Boost.Asio provides a robust and efficient networking library, enabling asynchronous, non-blocking operations essential for real-time games. (No idea if that is true, it was just the only networking library I could find.)

### 2.5 Input Handling
- **Library**: SDL2
- **Responsibility**: The input system processes user input, such as keyboard, mouse, or game controller events. It updates the relevant components in the ECS based on input (e.g., updating a `VelocityComponent` in response to player movement).

> **Design Decision**: SDL2's input handling is simple and well-suited for cross-platform development.

### 2.6 UI System
- **Library**: ImGui
- **Responsibility**: The UI system handles debug interfaces and other in-game menus using ImGui. It’s mostly used for rendering overlays, such as debugging windows and HUD elements.

> **Design Decision**: ImGui provides a highly flexible and easy-to-use UI framework, perfect for in-game development tools and debugging. It is also simpler than making ui from scratch.

## 3. **Flow of Execution**

1. **Initialization**:
   - The game initializes subsystems (SDL2, Box2D, ImGui, etc.).
   - The ECS manager is created, along with the main game loop.

2. **Game Loop**:
   The game follows the traditional game loop pattern:
   - **Input Processing**: Captures user input (e.g., key presses, mouse movements) via SDL2 and updates the appropriate components in the ECS.
   - **Physics Update**: The Physics System, powered by Box2D, simulates the physics for all entities with physical properties.
   - **Game Logic Update**: Systems like AI, movement, and other gameplay mechanics run based on the ECS architecture.
   - **Rendering**: The Rendering System draws the game world based on updated entity states.
   - **Networking**: The Networking System synchronizes the game state between the client and server using Boost.Asio.

3. **Shutdown**:
   - Once the game loop ends, the engine shuts down all subsystems and cleans up resources.

## 4. **Directory Structure (REWORKING)**

```plaintext
project/
│
├── src/                  # Source code
│   ├── ecs/              # Entity-Component-System code
│   ├── rendering/        # Rendering system (SDL2)
│   ├── physics/          # Physics system (Box2D)
│   ├── networking/       # Networking system (Boost.Asio)
│   └── ui/               # UI system (ImGui)
│
├── assets/               # Game assets (sprites, sounds, etc.)
├── include/              # Header files
├── build/                # Build artifacts
├── tests/                # Unit and integration tests
└── CMakeLists.txt        # CMake configuration
```

## 5. **Future Plans**
The current architecture is designed to be modular and scalable. Some future improvements include:
- **Multithreading**: Introducing multithreaded systems for physics and networking to enhance performance.
- **Modularization**: Splitting core systems (e.g., rendering, physics) into separate modules to improve maintainability.
- **Code Clean Up**: Making the core code actually up to standard and decoupling systems effectively.
