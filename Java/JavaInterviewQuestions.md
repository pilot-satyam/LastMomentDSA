Q1. Why is 1 == 1 True but 1000 == 1000 False in Java?

Ans. 

Autoboxing & Integer Caching

In Java, there’s a difference between:

    1.Primitive types → int, boolean, char, etc.

    2.Wrapper classes → Integer, Boolean, Character, etc.

When you write:
Integer a = 1000;
Integer b = 1000;
System.out.println(a == b);
You’re not comparing primitive ints, but rather two Integer objects.
And == compares object references, not values.
Integer Caching Mechanism

Java caches Integer objects for values from -128 to +127.
So:
Integer x = 1;
Integer y = 1;
Both x and y point to the same cached Integer object, hence:
x == y  // true

But for values outside that range, new objects are created:
Integer a = 1000;
Integer b = 1000;

→ Two different Integer objects are created,
so:
a == b  // false

✅ Correct Way to Compare Values

If you want to compare values, not references, use .equals():
Integer a = 1000;
Integer b = 1000;
System.out.println(a.equals(b)); // true

Or unbox to primitive int:
int x = 1000;
int y = 1000;
System.out.println(x == y); // true
