# 3-Uzduotis-1
3 Uzduotis. Vector konteinerio kūrimas

### Funkcijų pavyzdžiai

#### • `rbegin()` ir `rend()`

    •`rbegin()`: "Returns a reverseiterator pointing to the last element in the vector (i.e. its reverse beginning).
    •`rend()` : Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector (which is          considered its reverse end).
    
```ruby
vector <int> v(10);
	int i=0;
	for (vector<int>::reverse_iterator rit=v.rbegin(); rit!=v.rend(); ++rit)
        *rit=++i;
    std::cout << "Vector susideda is siu elementu: ";
    for (vector<int>::reverse_iterator it=v.rbegin(); it!=v.rend(); ++it)
std::cout<< *it<< " ";
std::cout << "\n";
```

Bus išvedama:

`Vector susideda iš siu elementu: 1 2 3 4 5 6 7 8 9 10`

#### • `front()` ir `back`:
  • `front()` : Returns a reference to the first element in the vector
  • `back()`: Returns a reference to the last element in the vector.
  
  ```ruby
  
vector<int> vec;
vec.push_back(78);
vec.push_back(16);

vec.front()-=vec.back();
std::cout << "vec.front() lygus: " << vec.front()<< "\n";
```

Bus išvedama: 

`vec.front() lygus: 62`

##### • `reverse()` : Reverses the order of the elements in the range [first,last)

```ruby

vector<int> vector1;
  sz1 = vector1.capacity();
  std::cout << "making vector1 grow:\n";
  for (int i=0; i<100; ++i) {
    vector1.push_back(i);
    if (sz1!=vector1.capacity()) {
      sz1 = vector1.capacity();
      std::cout << "capacity changed: " << sz1 << '\n';
    }
  }

  vector<int> vector2;
  sz1 = vector2.capacity();
  vector2.reserve(100);   // this is the only difference with vector1 above
  std::cout << "making vector2 grow:\n";
  for (int i=0; i<100; ++i) {
    vector2.push_back(i);
    if (sz1!=vector2.capacity()) {
      sz1= vector2.capacity();
      std::cout << "capacity changed: " << sz1 << '\n';
    }
  }
```

Bus išvedama:

```making vector1 grow:

capacity changed: 1

capacity changed: 2

capacity changed: 3

capacity changed: 4

capacity changed: 6

capacity changed: 9

capacity changed: 13

capacity changed: 19

capacity changed: 28

capacity changed: 42

capacity changed: 63

capacity changed: 94

capacity changed: 141

making vector2 grow:

capacity changed: 100
```

### Spartos analizė

|              |10000| 100000 | 1000000 | 10000000 | 100000000|
|--------------|-----|--------|---------|----------|----------| 
|std::vector   |  0  |3.313 ms|12.8 ms  |160.036 ms|1450.99 ms|
|custom_vector |  0  |3.122 ms|16.987 ms|225.194 ms|3066.80 ms|

### Palyginta capacity() == size()

|            |100000000|
|------------|---------|
std::vector  |27 kartus|
Custom_vector|46 kartus|

### Custom vektoriaus veikimas ankstesnėje užduotyje

Deja, mano sukurtas vektorius turi neatitikimų, tad vykdant programą susiduriama su klaida. Tad rekomenduojama naudoti jau patvirtintą std::vector vektorių.


