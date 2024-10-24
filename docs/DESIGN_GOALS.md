# Design Goals

This document outlines the design goals for the various projects within the SimpleComplexRPG ecosystem. Each project is aimed at creating a robust, enjoyable, and complex multiplayer experience as a hobby.

## Projects Overview

1. **DeiVoluntas**
   - **Description**: An ECS game engine built using Boost, EnTT, SDL2, Box2D, and IMGui.
   - **Goals**:
     - Create a flexible and efficient ECS architecture to manage game entities and their behaviors.
     - Leverage Boost and EnTT for enhanced performance and ease of use in entity management.
     - Integrate SDL2 for cross-platform graphics rendering and user input.
     - Utilize Box2D for 2D physics simulations, enabling realistic interactions between game entities.
     - Provide a customizable user interface using IMGui to facilitate easy debugging and development.

2. **SimpleComplexServer**
   - **Description**: Server executable for the SimpleComplexRPG.
   - **Goals**:
     - Design a robust server architecture that can handle multiple simultaneous connections efficiently. (Or try to.)
     - Implement network protocols that support real-time communication between clients and the server.
     - Ensure data integrity and synchronization across clients to provide a seamless multiplayer experience. (Wouldn't count on this one.)
     - Create logging and monitoring tools to help diagnose issues during development and after deployment.

3. **SimpleComplexCommon**
   - **Description**: A library for common code shared between the client and server of SimpleComplexRPG.
   - **Goals**:
     - Establish a clear and maintainable codebase for shared functionalities, such as data structures and utility functions.
     - Ensure consistency between client and server code to facilitate easier debugging and feature development.
     - Create comprehensive unit tests to validate the common library’s functionality and reliability.

4. **SimpleComplexClient**
   - **Description**: Client executable for the SimpleComplexRPG.
   - **Goals**:
     - Build a user-friendly and engaging client interface that enhances the gaming experience.
     - Implement gameplay mechanics that utilize the ECS architecture from DeiVoluntas for entity management.
     - Support seamless connectivity to the SimpleComplexServer for multiplayer gameplay.
     - Incorporate dynamic visuals and audio to create an immersive gaming environment. (Depending on how good at that I am.)

## General Design Goals

- **Complex Systems**: Embrace complexity in the design to create engaging gameplay mechanics and systems that challenge both players and developers.
- **Modular Architecture**: Promote modularity within the codebase, allowing for easier maintenance, testing, and extensibility of features. (This is kinda a pipe dream.)
- **Performance Optimization**: Continuously profile and optimize the code to ensure smooth gameplay and responsiveness, especially in a multiplayer context.
- **Enjoyment and Learning**: Foster a development environment that prioritizes enjoyment and learning over strict adherence to industry standards, allowing for creativity and experimentation.
- **Documentation and Clarity**: Maintain clear documentation across all projects to ensure that design decisions, code usage, and system architecture are easily understood by contributors and users.
- **Community Engagement**: Encourage community feedback and contributions, making the projects more collaborative and inclusive. (Press X to doubt.)

## Conclusion

These design goals serve as guiding principles for the development of the SimpleComplexRPG ecosystem. By focusing on these objectives, the aim is to create a robust and enjoyable multiplayer experience while also providing a platform for learning and experimentation in game development.
