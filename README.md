# value_bag

Put a value into the bag and take it functionally.

## Usage

See `main.cpp`.

A result of the sample code is as follows:

```
default peek : 100
default take : 100
default take : 0
default set : 200
default take : 200
default take : 0
----
toggle : value1 = 100, value2 = 200
toggle peek : 100
toggle take : 100
toggle take : 200
toggle take : 100
toggle : the value becomes 100.
toggle take : 100
----
once peek : 100
once take : 100
once take : 0
once set : 200
once take : 0
----
```

Here is an example to prevent chattering a switch.

```
auto d = m2d::default_value_bag<int>(LOW, LOW);
...

int pin = digitalRead(10);
if (pin != d.peek() && pin == HIGH) {
	d.set(pin);
}
...

if (d.take() == HIGH) {
// Do something, called once after pin 10 becomes HIGH.
}
```
