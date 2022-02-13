# jsonlite2

> Good things in life are free...

[![Release version](https://img.shields.io/github/v/release/makuke1234/jsonlite2?display_name=release&include_prereleases)](https://github.com/makuke1234/femto/releases/latest)
[![Total downloads](https://img.shields.io/github/downloads/makuke1234/jsonlite2/total)](https://github.com/makuke1234/jsonlite2/releases)
![C version](https://img.shields.io/badge/version-C99-blue.svg)

A light-weight C JSON library, relying on KISS (Keep It Stupid Simple)
convention (similar to my other json library [jsonlite](https://github.com/makuke1234/jsonlite)).
This time I decided to make the C version first, translating it to C++ afterwards seemed easier to me.

Yes, this library is designed to aim for fast compilation times, simplicity,
ease of use and full compliancy with JSON standard.


# Overview

Both 32-bit and 64-bit Windows binaries of this library can be obtained [here](https://github.com/makuke1234/jsonlite2/releases). The library has been compiled with MinGW GCC and should also be compatible
with Microsoft's Visual C++ compiler and the others, since MinGW uses the same format for
C libraries.

If you want you can compile the library yourself, just use the `makefile` provided in the `c` subdirectory.


# Changelog - C version

* 1.3
	* Skip NULL values when dumping object
* 1.2
	* Make error code UTF-8 instead of UTF-16
* 1.1
	* Minor optimisation in value type, use uint8_t instead of enum type itself
* 1.0
	* Initial release


# Changelog - C++ version

* Planned


# A C++ version

Also, a sophisticated single-include C++ version of this library is being planned...


# About testing

Although light testing has been done with the library, feel free to report any bugs
that you may find under **[Issues](https://github.com/makuke1234/jsonlite2/issues)**.


# Licensing

This project is under the MIT license.
