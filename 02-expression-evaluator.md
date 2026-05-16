# Exercise 2: Expression Evaluator with Operator Precedence

## Objective
Create a command-line calculator that properly handles operator precedence and associativity.

## Requirements
1. Parse mathematical expressions with +, -, *, /, %, and parentheses
2. Implement proper operator precedence (as described in chapter 9 of the manual)
3. Handle left-to-right associativity for operators of equal precedence
4. Support both integer and floating-point arithmetic
5. Detect and handle division by zero
6. Implement using the Shunting Yard algorithm or recursive descent parsing

## Concepts to Practice
- Operator precedence and associativity
- Parsing algorithms (Shunting Yard, recursive descent)
- Stack usage
- Error handling
- Expression trees

## Suggested Approach
1. Study the operator precedence rules from chapter 9 of the manual
2. Implement a tokenizer to break input into numbers and operators
3. Choose either Shunting Yard algorithm (to RPN) or recursive descent parsing
4. Implement the evaluation engine
5. Add error handling for malformed expressions and division by zero
6. Extend to support variables and functions if desired

## Extension Ideas
- Add support for unary operators (+, -)
- Add mathematical functions (sin, cos, sqrt, log)
- Add variable assignment and recall
- Implement memory functions (M+, M-, MR, MC)
- Add graphing capabilities for functions