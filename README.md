# krr-read
A simple kernel ring buffer reader in C

### What it does

krr-read is a kernel ring buffer reader written in C. It provides a basic implementation of a ring buffer and a test suite to verify its correctness. This project exists to demonstrate a straightforward approach to kernel ring buffer reading.

### Install

```bash
git clone https://github.com/SamyAlderson/krr-read.git
cd krr-read
make
```

### Usage

To use krr-read, compile it as a kernel module and load it into your kernel. You can then use the `krr_read` function to read from the ring buffer.

```bash
insmod krr_read.o
echo "Hello, world!" > /dev/ring_buffer
```

### Build from source

To build krr-read from source, use the `make` command. This will compile the kernel module and create an `krr_read.o` file.

```bash
make clean
make
```

### Run tests

To run the test suite, use the `make test` command.

```bash
make test
```

### Project structure

* `krr_read.c`: kernel ring buffer reader implementation
* `test_krr_read.c`: test program for krr_read
* `Makefile`: build script
* `test_krr_read.h`: test header file

### License

Copyright (c) 2026 SamyAlderson

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.