# Exercise 7: Networked Chat Application

## Objective
Create a simple client-server chat application using sockets.

## Requirements
1. Implement a TCP server that handles multiple clients
2. Implement client programs that can connect and chat
3. Support:
   - Public chat rooms
   - Private messaging
   - User registration/authentication
4. Handle client disconnections gracefully
5. Implement basic message buffering

## Concepts to Practice
- Sockets and network programming
- Client-server architecture
- Concurrency (threads or select/poll)
- Protocol design
- Error handling in network applications

## Suggested Approach
1. Start with a simple echo server to understand socket basics
2. Implement a multithreaded server (or use select/poll for I/O multiplexing)
3. Design a simple chat protocol (text-based with commands)
4. Implement client-side connection and messaging
5. Add user management (registration, authentication, tracking)
6. Implement chat room functionality
7. Add private messaging capabilities
8. Handle edge cases (disconnections, malformed messages, etc.)

## Extension Ideas
- Implement SSL/TLS encryption for secure communication
- Add file transfer capabilities
- Create a graphical user interface for clients
- Implement message persistence/logging
- Add admin/moderator controls
- Support multiple chat channels/rooms