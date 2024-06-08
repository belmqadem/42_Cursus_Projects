# <div align="center">Philosophers</div>

## Introduction To The Dining Philosophers Problem
The Dining Philosophers problem is a classic synchronization and concurrency challenge in computer science. It was originally formulated by Edsger Dijkstra in 1965 to illustrate the complexities and potential pitfalls of concurrent programming. The problem involves five philosophers sitting around a circular table, each alternating between thinking and eating. Between each pair of philosophers is a single fork, and a philosopher must have both forks to eat. The challenge is to design a solution that ensures no philosopher will starve (wait indefinitely to eat) while avoiding deadlock and ensuring that all philosophers can eventually eat.

## Overview 📜
This project simulates the classic "Dining Philosophers" problem. The problem consists of philosophers who alternate between eating, thinking, and sleeping. They sit around a table with a bowl of spaghetti in the middle, and each philosopher needs two forks to eat. The goal is to ensure that philosophers do not starve while adhering to specific constraints and rules.

## Simulation Rules
- 🍽️ Philosopher States: Philosophers can eat, think, or sleep.
- 🍴 Forks: There are as many forks as there are philosophers, with each philosopher having one fork on their left and one on their right.
- 🍝 Eating: A philosopher needs both forks to eat. After eating, they release the forks and begin sleeping.
- 💤 Sleeping: After sleeping, philosophers start thinking.
- 💭 Thinking: After thinking, philosophers attempt to take both forks to eat again.
- ☠️ Death: The simulation stops if a philosopher dies from starvation.

## Implementation Details
- 🔄 Ensure that each philosopher alternates between the states correctly.
- 🔐 Properly manage the mutexes to avoid deadlocks.
- ⚠️ Implement starvation detection to handle philosopher death accurately.
- 📝 Log all state changes in the required format.

## Contributing ✍
Contributions are welcome! Please fork the repository and submit a pull request.
