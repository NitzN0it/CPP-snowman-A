<div dir="rtl" lang="he">

# אנשי השלג

תוצאת ריצה:

--- 0 seconds


### Cleaning old files ###
rm -f *.o demo test
rm -f Test2.cpp


### Check 0: our demo program should compile with your class
! timeout 10 make -f Makefile demo
clang++-9  -std=c++2a -Werror --compile Demo.cpp -o Demo.o
clang++-9  -std=c++2a -Werror --compile snowman.cpp -o snowman.o
clang++-9  -std=c++2a -Werror Demo.o snowman.o -o demo
--- 1 seconds
### Score 0: 100


### Check 1: our demo program should run without errors
! timeout 10 ./demo
Do you want to build a snowman?
Do you want to build a snowman?
Do you want to build a snowman?
--- 1 seconds
### Score 1: 100


### Check 2: your test should compile 
! timeout 10 make -f Makefile test
clang++-9  -std=c++2a -Werror --compile TestCounter.cpp -o TestCounter.o
clang++-9  -std=c++2a -Werror --compile Test.cpp -o Test.o
clang++-9  -std=c++2a -Werror TestCounter.o Test.o snowman.o -o test
--- 3 seconds
### Score 2: 100


### Check 3: you should write some new tests
! timeout 10 ./test
[doctest] doctest version is "2.3.7"
[doctest] run with "--help" for options
===============================================================================
Test.cpp:26:
TEST CASE:  Input is too short

Test.cpp:28: ERROR: CHECK_THROWS( snowman(1) ) did NOT throw at all!

Test.cpp:29: ERROR: CHECK_THROWS( snowman(12) ) did NOT throw at all!

Test.cpp:30: ERROR: CHECK_THROWS( snowman(123) ) did NOT throw at all!

Test.cpp:31: ERROR: CHECK_THROWS( snowman(1234) ) did NOT throw at all!

Test.cpp:32: ERROR: CHECK_THROWS( snowman(12341) ) did NOT throw at all!

Test.cpp:33: ERROR: CHECK_THROWS( snowman(123412) ) did NOT throw at all!

Test.cpp:34: ERROR: CHECK_THROWS( snowman(1234123) ) did NOT throw at all!

===============================================================================
Test.cpp:36:
TEST CASE:  Input is too short and should throw an Invalid argument exception

Test.cpp:38: ERROR: CHECK_THROWS_AS( snowman(1), std::invalid_argument ) did NOT throw at all!

Test.cpp:39: ERROR: CHECK_THROWS_AS( snowman(12), std::invalid_argument ) did NOT throw at all!

Test.cpp:40: ERROR: CHECK_THROWS_AS( snowman(123), std::invalid_argument ) did NOT throw at all!

Test.cpp:41: ERROR: CHECK_THROWS_AS( snowman(1234), std::invalid_argument ) did NOT throw at all!

Test.cpp:42: ERROR: CHECK_THROWS_AS( snowman(12341), std::invalid_argument ) did NOT throw at all!

Test.cpp:43: ERROR: CHECK_THROWS_AS( snowman(123412), std::invalid_argument ) did NOT throw at all!

Test.cpp:44: ERROR: CHECK_THROWS_AS( snowman(1234123), std::invalid_argument ) did NOT throw at all!

===============================================================================
Test.cpp:46:
TEST CASE:  Input is too long

Test.cpp:48: ERROR: CHECK_THROWS( snowman(123412341) ) did NOT throw at all!

Test.cpp:49: ERROR: CHECK_THROWS( snowman(1234123412) ) did NOT throw at all!

===============================================================================
Test.cpp:51:
TEST CASE:  Input is too long and should throw an Length error exception

Test.cpp:53: ERROR: CHECK_THROWS_AS( snowman(123412341), std::length_error ) did NOT throw at all!

Test.cpp:54: ERROR: CHECK_THROWS_AS( snowman(1234123412), std::length_error ) did NOT throw at all!

===============================================================================
Test.cpp:56:
TEST CASE:  Negative input

Test.cpp:58: ERROR: CHECK_THROWS( snowman(-11111111) ) did NOT throw at all!

Test.cpp:59: ERROR: CHECK_THROWS( snowman(-12341234) ) did NOT throw at all!

===============================================================================
Test.cpp:61:
TEST CASE:  Negative input and should throw an Invalid argument exception

Test.cpp:63: ERROR: CHECK_THROWS_AS( snowman(-11111111), std::invalid_argument ) did NOT throw at all!

Test.cpp:64: ERROR: CHECK_THROWS_AS( snowman(-12341234), std::invalid_argument ) did NOT throw at all!

===============================================================================
Test.cpp:66:
TEST CASE:  Unknown body part (not only 1-4 digits)

Test.cpp:68: ERROR: CHECK_THROWS( snowman(55555555) ) did NOT throw at all!

Test.cpp:69: ERROR: CHECK_THROWS( snowman(12345678) ) did NOT throw at all!

Test.cpp:70: ERROR: CHECK_THROWS( snowman(87654321) ) did NOT throw at all!

Test.cpp:71: ERROR: CHECK_THROWS( snowman(12348432) ) did NOT throw at all!

===============================================================================
Test.cpp:73:
TEST CASE:  Unknown body part (not only 1-4 digits) and should throw an out of range exception

Test.cpp:75: ERROR: CHECK_THROWS_AS( snowman(55555555), std::out_of_range ) did NOT throw at all!

Test.cpp:76: ERROR: CHECK_THROWS_AS( snowman(12345678), std::out_of_range ) did NOT throw at all!

Test.cpp:77: ERROR: CHECK_THROWS_AS( snowman(87654321), std::out_of_range ) did NOT throw at all!

Test.cpp:78: ERROR: CHECK_THROWS_AS( snowman(12348432), std::out_of_range ) did NOT throw at all!

===============================================================================
Test.cpp:80:
TEST CASE:  Good snowman code

Test.cpp:81: ERROR: CHECK( nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )") ) is NOT correct!
  values: CHECK( Doyouwanttobuildasnowman? == _===_(.,.)(:)(:) )

Test.cpp:82: ERROR: CHECK( nospaces(snowman(33232124)) == nospaces("   _\n  /_\\\n\\(o_O)\n (] [)>\n (   )") ) is NOT correct!
  values: CHECK( Doyouwanttobuildasnowman? == _/_\\(o_O)(][)>() )

Test.cpp:83: ERROR: CHECK( nospaces(snowman(12222212)) == nospaces(" _===_\n\\(o.o)/\n ( : ) \n (\" \")") ) is NOT correct!
  values: CHECK( Doyouwanttobuildasnowman? == _===_\(o.o)/(:)("") )

Test.cpp:84: ERROR: CHECK( nospaces(snowman(11111111)) == nospaces(" _===_ \n (.,.) \n<( : )>\n ( : )") ) is NOT correct!
  values: CHECK( Doyouwanttobuildasnowman? == _===_(.,.)<(:)>(:) )

Test.cpp:85: ERROR: CHECK( nospaces(snowman(22222222)) == nospaces("  ___  \n ..... \n\\(o.o)/\n (] [) \n (\" \")") ) is NOT correct!
  values: CHECK( Doyouwanttobuildasnowman? == ___.....\(o.o)/(][)("") )

Test.cpp:86: ERROR: CHECK( nospaces(snowman(33333333)) == nospaces("   _   \n  /_\\  \n (O_O) \n/(> <)\\\n (___)") ) is NOT correct!
  values: CHECK( Doyouwanttobuildasnowman? == _/_\(O_O)/(><)\(___) )

Test.cpp:87: ERROR: CHECK( nospaces(snowman(44444444)) == nospaces("  ___  \n (_*_) \n (- -) \n (   ) \n (   )") ) is NOT correct!
  values: CHECK( Doyouwanttobuildasnowman? == ___(_*_)(--)()() )

100
--- 3 seconds
### Score 3: 100


Grade: 100
