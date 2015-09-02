#ifndef FIELD_ITERATOR_TEST_H
#define FIELD_ITERATOR_TEST_H

class FieldIteratorTest {
public:
  static FieldIteratorTest *instance();

  int regressionTest();

private:
  int fail();
  int normalCase();
  int emptyString();
  int noDelimiter();

  FieldIteratorTest();
  ~FieldIteratorTest();
};

#endif
