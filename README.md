teensy-4_nxp_iMXRT1062
=============================

<p align="center">
    <a href="https://github.com/Embedded-System-Lovers/teensy-4_nxp_iMXRT1062/actions">
        <img src="https://github.com/Embedded-System-Lovers/teensy-4_nxp_iMXRT1062/actions/workflows/teensy-4_nxp_iMXRT1062.yml/badge.svg" alt="Build Status"></a>
    <a href="https://github.com/Embedded-System-Lovers/teensy-4_nxp_iMXRT1062/issues?q=is%3Aissue+is%3Aopen+sort%3Aupdated-desc">
        <img src="https://custom-icon-badges.herokuapp.com/github/issues-raw/Embedded-System-Lovers/teensy-4_nxp_iMXRT1062?logo=github" alt="Issues" /></a>
    <a href="https://github.com/Embedded-System-Lovers/teensy-4_nxp_iMXRT1062/blob/master/LICENSE_1_0.txt">
        <img src="https://img.shields.io/badge/license-BSL%201.0-blue.svg" alt="Boost Software License 1.0"></a>
    <a href="https://github.com/Embedded-System-Lovers/teensy-4_nxp_iMXRT1062" alt="GitHub code size in bytes">
        <img src="https://img.shields.io/github/languages/code-size/Embedded-System-Lovers/teensy-4_nxp_iMXRT1062" /></a>
</p>

This repository implements an entirely manually-written, pure
_bare_ _metal_ Blinky Project for the NXP ARM Cortex-M7 iMXRT1062
(on the Teensy 4.0 board).

Features include:
  - boot through the board's standard bootloader,
  - PLL frequency increased to 600 MHz,
  - timebase derived from `SysTick`,
  - blinky LED show with adjustable frequency,
  - implementation in C++20/C11 (and beyond) with absolute minimal use of assembly.

A clear and easy-to-understand build system based on GNUmake
completes this fun and educational project.

This repository provides keen insight on starting up
a _bare_ _metal_ Teensy board.

## Details on the Application

The application boots from the board's standard bootloader.
Necessary inputs/user-adaptions for this boot are provided in
the file [bootdata.c](./Src/startup/bootdata.c).

Following the bootloader's low-level chip initialization,
the program jumps to our own self-written startup stub
called `__my_startup()` in [crt0.cpp](./Src/startup/crt0.cpp).

After a few more initializations in `__my_startup()`, control is transfered to
[`main()`](https://github.com/Embedded-System-Lovers/teensy-4_nxp_iMXRT1062/blob/d83a96c04f952991e91b0569b6c69bc3e3dad5e0/Src/Appli/Appli.cpp#L26).
Here the simple LED blinky show is executed.

The adjustable LED-phase (its half-period) can be tuned
to provide a rudimentary, visible blinky LED show.
The timebase for blinky is based on the standard `SysTick`
interrupt handler.

## Building the Application

The _home_ directory of the build system (whether on `Win*` of `*nix*`)
is located in the directory [`Build/VS`](./Build/VS).
Several paths used in the build(s) are defined relative to this
home directory.

### Build on `*nix*`

Build on `*nix*` is easy using an installed `gcc-arm-none-eabi`

```sh
cd teensy-4_nxp_iMXRT1062/Build/VS
../build.sh all
```

If `gcc-arm-none-eabi` is not present, then it can be installed (if needed).

```sh
sudo apt install gcc-arm-none-eabi
```

### Build on `Win*` in MSVC

**Important:** When building with MSVC, it is necessary to
first unpack the gcc-arm-none-eabi toolchain. This is done by
going to `Build/tools/gcc` in Windows-Explorer
and simply double-clicking on the self-extracting archive
file `gcc-11.2.0-arm-none-eabi.exe`. Answer yes to
the query in the pop-up window launched from the extractor.

We will now build the `target` configuration in MSVC.
(This is the configuration that runs on the Teensy board.)

Navigate to the directory [`Build/VS`](./Build/VS).
Find there the MSVC solution file `teensy-4_nxp_iMXRT1062.sln`
and open it. Select the solution configuration `target`
and rebuild the solution.

The build results including ELF-file, HEX-mask, symbol-file
and assembly list file are created in the output directory
`Build\Bin\target_x64`.

There are additional _host_ configurations available.

Simulated Windows (host) project configurations
`Debug` and `Release` can be used for trouble-shooting the code if
needed. These run on the host system with simulated LED blinky show.

## Continuous Integration

CI runs on pushes and pull-requests with simple
build(s) including result verification on both
`windows-latest` as well as `ubuntu-latest`
using GitHub Actions.

## Hardware Setup

The Teensy 4.0 is used with no modifications whatsoever
straight out-of-the-box. The hardware setup in action
is pictured in the image below.

![](./images/teensy_blinky.jpg)

## Licensing

This software project is licensed under [BSL 1.0](./LICENSE_1_0.txt).
