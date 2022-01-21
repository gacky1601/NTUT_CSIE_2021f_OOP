### Homework 03

### Due: 11:59 p.m., 12 November 2021

**In HW03, put all your source code in src/cat.h and test code in test/ut_cat.h. You can keep files of HW02. But remember to update ut_main.cpp to include ut_dog.h**

**Content of HW03**

The goal of this homework is to practice implement basic constructor, destructor and member functions  (getters/setters).

You are going to write a simple program to help cats to track their own toys. In this simple program, a cat have its *name* and *weight*, and can have some *toys* that he/she can choose to bite.

Then, you have to write a class named ***Cat***, having the above properties as its data member and functions.

To test your program, you are required to write **8** test cases in total according to following requirement.

Test the following situations:

- `Cat::getName` (15%)
  - return the name of Cat
- `Cat::getWeight` (15%)
  - return the weight of Cat
- `Cat::addNewToy` (20%)
  - _toyCollections is a data member of Cat, it's a string array that contains all toys this very Cat has. \
  New toy will be added from the behind.
  - _toyAmount records how many toys there are in the _toyCollections. Use it to help you implement the function.
- `Cat::getToy` (15%)
  - get toy by index in sequential order. Index start from 0.

You shuold also implement the constructor `Cat::Cat() ` and the destructor `Cat::~Cat()`.

Pass TA's test cases to get 35%

**Watch out!** Lose 10 points if memory leaks.

**Note**
1. Use [nullptr](https://en.cppreference.com/w/cpp/language/nullptr) if you want to have a null pointer, which is a special pointer that doesn't point to anything.
2. Use `ASSERT_EQ` to test integer, `ASSERT_NEAR` to test floating-point number, `ASSERT_THROW` to test exception.
3. Please implement your test cases reasonably, otherwise you will get no point for that sub-problem.
4. You shuold eiter not add bin foler to your git, or add a file with the name of '.gitignore' in bin folder (see our class repo). You will lost 10% if you bin folder contains compiled ut_all in git repo.
5. If you see segmentation fault, you can use `gdb` cmd to help debug. [Link](https://codertw.com/%E7%A8%8B%E5%BC%8F%E8%AA%9E%E8%A8%80/551505/)
