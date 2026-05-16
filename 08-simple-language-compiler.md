# Exercise 8: Compiler for a Simple Language

## Objective
Build a compiler for a tiny programming language.

## Requirements
1. Define a simple language with:
   - Arithmetic expressions
   - Variable assignments
   - If-else statements
   - While loops
   - Print statements
2. Implement:
   - Lexical analyzer (tokenizer)
   - Syntax analyzer (parser)
   - Semantic analyzer
   - Intermediate code generation
   - Simple code generation (to assembly or virtual machine code)
3. Optionally implement an optimizer

## Concepts to Practice
- Lexical analysis and parsing
- Syntax trees and ASTs
- Semantic analysis
- Code generation techniques
- Compiler construction principles

## Suggested Approach
1. Define your simple language grammar (e.g., a subset of C or BASIC-like)
2. Implement a lexical analyzer using flex-style patterns or manual tokenization
3. Create a recursive descent parser or use parser generator concepts
4. Build an abstract syntax tree (AST) representation
5. Add semantic analysis (type checking, scope resolution)
6. Generate intermediate code (three-address code or bytecode)
7. Optionally implement simple optimizations (constant folding, dead code elimination)
8. Generate target code (simple assembly or execute via virtual machine)

## Extension Ideas
- Add support for functions and procedures
- Implement data types (integers, floats, strings, arrays)
- Add standard library functions
- Implement a garbage collector for your VM
- Add debugging capabilities (breakpoints, step-through)