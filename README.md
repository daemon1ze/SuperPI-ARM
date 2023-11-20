# SuperPI-ARM

SuperPI-ARM is an efficient implementation of the SuperPI application, specifically optimized for the Apple ARM architecture. This project utilizes the Gauss-Legendre algorithm for calculating π (Pi) to an arbitrary degree of precision. 

## Features

- **Native compilation for Apple ARM**: Tailored to leverage the ARM architecture of Apple's M chips for enhanced performance.
- **High Precision Calculations**: Utilizes the Gauss-Legendre algorithm for accurate Pi computations.
- **Multithreading Support**: Employs multithreading to take full advantage of the M1's multi-core processor.
- **GNU Multiple Precision (GMP) Library**: Incorporates GMP for high-precision arithmetic operations.

## Prerequisites

To compile and run SuperPI-ARM, you need to have the following installed:

- An Apple ARM device
- G++ compiler
- GMP library

You can install GMP using Homebrew:

```bash
brew install gmp
```

## Compilation

The project includes a Makefile for easy compilation. Simply run:

```bash
make
```

This command will generate an executable named `superpi`.

To clean up the compiled files, run:

```bash
make clean
```

## Usage

To run the program, execute the compiled binary with the desired precision level:

```bash
./superpi [precision]
```

Replace `[precision]` with the number of iterations for the Gauss-Legendre algorithm.

