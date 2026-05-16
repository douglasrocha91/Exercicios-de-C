# Exercise 6: Finite State Machine Compiler

## Objective
Create a tool that compiles finite state machine descriptions into C code.

## Requirements
1. Define a simple FSM description language
2. Parse FSM descriptions (states, transitions, actions)
3. Generate C code that implements the FSM
4. Include support for:
   - Entry/exit actions for states
   - Transition guards/conditions
   - Hierarchical states (optional)
5. Generate both the state transition table and action functions

## Concepts to Practice
- Parsing and lexical analysis
- Code generation techniques
- State machines and automata theory
- Macros and metaprogramming

## Suggested Approach
1. Design a simple FSM description language (text-based or XML-like)
2. Implement a lexer to tokenize the FSM description
3. Create a parser to build an internal representation of the FSM
4. Implement code generation to produce C header and source files
5. Generate:
   - State enumeration
   - Transition table (2D array or structured format)
   - Function prototypes for actions
   - Main FSM execution function
6. Test with various FSM examples (traffic light, vending machine, protocol handler)

## Extension Ideas
- Add support for hierarchical states (statecharts)
- Implement optimization of the state transition table
- Generate code for different target environments (embedded, hosted)
- Add simulation capabilities to test FSMs without compiling
- Implement FSM minimization algorithms