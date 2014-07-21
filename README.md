cppunit.nuget
=============

Build a CppUnit nuget package

Usage
=====

1. Create a VS2013 C++ console application. Make sure it is empty. No precompiled headers, etc.
2. Add source files that contain test cases.
3. Add this nuget package to the project.
4. Make sure a single source file includes the line:
	#include <TestPolicy/CppUnit_testdriver.cxx>
5. Build and run. You'll have a command line runner for this. It is no frills, but...

Building a new nuget package
========

These instructions assume you have installed locally:
- VS 2013
- VS 2012

1. Check out this package
2. Download a source code snapshot of cppunit from source forge repo. Unpack it so that the cppunit directory is at the same level as cppunit.nuget (you'll get packing errors when you try to build the package if you don't do this). See http://sourceforge.net/p/cppunit/code/HEAD/tree/trunk/cppunit/
3. In the root directory there is a Build2010 solution file. Open it, and allow it to convert. It may not be able to convert the MSI file - that is ok.
4. Build both the Release and the Debug configurations of the cppunit project (that is the only one required).
5. at the same level as teh cppunit.nuget directory, create a cppunit/vc11 and cppunit/vc12 directory. Copy the debug and non-debug cppunit libraries in there.
6. Repeate for both versions of VS. Easiest is to open with 2013, and then select the downlevel tools to build.
7. Update the description in the autopkg file to match the date of the last check in.

