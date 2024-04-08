#include <cstring>
#include <iostream>
#include <ostream>

using namespace std;

class MyString {
private:
  char *data_;
  int *ref_count_;

public:
  MyString(const char *str = "") {
    data_ = new char[strlen(str) + 1];
    strcpy(data_, str);
    ref_count_ = new int(1);
  }

  ~MyString() {
    (*ref_count_)--;
    if (*ref_count_ == 0) {
      delete[] data_;
      delete[] ref_count_;
    }
  }

  // 赋值运算
  MyString &operator=(const MyString &other) {
    if (this != &other) {
      (*ref_count_)--;
      if (*ref_count_ == 0) {
        delete[] data_;
        delete[] ref_count_;
      }

      // 新的数据
      this->data_ = other.data_;
      this->ref_count_ = other.ref_count_;
      (*this->ref_count_)++;
    }
    return *this;
  }

  // 拷贝构造
  MyString(const MyString &other) {
    data_ = other.data_;
    ref_count_ = other.ref_count_;
    (*this->ref_count_)++;
  }

  void print() {
    cout << "data: " << data_ << endl;
    cout << "refcount: " << *ref_count_ << endl;
  }
};

int main() {
  // 构造函数
  MyString s1("hello");
  s1.print();

  cout << "" << endl;
  MyString s2(s1);
  s1.print();
  s2.print();
  cout << "" << endl;

  MyString s3 = s1;
  s1.print();
  s2.print();
  s3.print();
}
