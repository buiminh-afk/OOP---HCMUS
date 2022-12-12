## Chương trình trên in ra màn hình :

B text
A default

## Trình tự gọi trong hàm main() :

"B obj1("text")"

- call A constructor method with 1 parameter
- call B constructor method with 1 parameter

"A \*obj2 = new B(obj1)"

- call A default constructor (0 parameter constructor)
- call B copy constructor

"foo(&obj1, \*obj2)"

- call obj1 display method
- call obj2s display method

## Chương trình gặp vấn đề về bộ nhớ

- A default constructor using 'strdup' that create a new memory block, but A default destructor have not free the memory block so it may causes "memory leak"

## sửa lại cho đúng

- Add A destructor
  ~A() {
  delete[] m_s;
  ms_s = nullptr;
  }
- Add "delete[] obj2" when it is done

## operator >> A

- friend istream&operator>> (istream&inDev, A & a ) {
  a.m_s = new char [100];
  inDev.get(a.m_s,100);
  return inDev;
  }
