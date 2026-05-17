# Warehouse Order Dispatch Simulation (v1)

## Overview
This project is a C++ simulation of a warehouse order processing system. It demonstrates how orders are generated, queued, processed, and dispatched using fundamental data structures such as queues and stacks.

The system simulates three order types:
- Small (S)
- Medium (M)
- Bulk (B)

Each order goes through a queue-based processing system and is eventually grouped into trucks for dispatch.

---

## Key Concepts Used
- FIFO queues for order processing
- Stack for dispatched trucks (LIFO behavior)
- Structs for modeling orders and trucks
- Random generation for simulation input
- Time-step based simulation loop

---

## How the Simulation Works

At each time step:
1. A random number of new orders (0–3) are generated.
2. Each order is assigned:
   - A type (S, M, or B)
   - A processing time (1–4 units)
3. Orders are placed into their respective queues.
4. The front order in each queue is processed:
   - Its processing time is reduced
   - When it reaches 0, it is marked as completed
5. Completed orders contribute toward truck dispatch:
   - Every 5 completed orders of a type creates a truck
   - Trucks are pushed onto a stack

---

## Output
The program displays:
- New orders per time step
- Current queue sizes for S, M, and B
- Stack of dispatched trucks (LIFO order)
- Final log of all generated orders

---

## Limitations (v1)
- Single-threaded simulation (one step at a time)
- Simplified truck model (no stored cargo details)
- No persistence or file storage
- No UI (console-based output only)

---

## Future Improvements
- Store actual orders inside trucks
- Improve reporting and analytics
- Add visualization of queue evolution
- Modularize code into separate files
- Add configurable simulation parameters

---

## Purpose
This project was built as a learning exercise for:
- Data structures (queues and stacks)
- Simulation design
- Basic system modeling in C++