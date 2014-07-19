cppunit.nuget
=============

Build a CppUnit nuget package

Usage
=====

1. Create a VS2013 C++ console application. Make sure it is empty. No precompiled headers, etc.
2. Add source files that contain test cases.
3. Add this nuget package to the project.
4. Build and run. You'll have a command line runner for this.

Building
========

These instructions assume you have installed locally:
- VS 2013

1. Check out this package
2. Download a source code snapshot of cppunit from source forge repo. Unpack it at the same level as this repo's directory (cd "ls ../cpunit" from this repo will give a listing.
3. In the root directory there is a Build2010 solution file. Open it, and allow it to convert. It may not be able to convert the MSI file - that is ok.


XX. Update the description in the autopkg file to match the date of the last check in.

