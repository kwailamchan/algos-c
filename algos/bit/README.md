# Bit Manipulation

## Operators

- bitwise operators
- shift operators

### Bitwise operators

- and: ``& / &&``
- or: ``| / ||``
- not: ``~ / !``
- xor: ``^``, whenever the inputs differ

```
   A    B   !A   A&&B   A||B   A^B
   0    0   1      0      0     0
   0    1   1      0      1     1
   1    0   0      0      1     1
   1    1   0      1      1     0
```


### Shift operators

- arithmetic (or signed) right shift: ``>>``
- logical (or unsigned) right shift: ``>>>``
- arithemtic / logical left shift: ``<<``

#### Left shift

```
6 in 32 bits

00000000 00000000 00000000 00000110

after left shift: 6 << 1 = 12

00000000 00000000 00000000 00001100


3,758,096,384 << 1

11100000 00000000 00000000 00000000

3,221,225,472

11000000 00000000 00000000 00000000
```


#### Right shift

```
12 in 32 bits

00000000 00000000 00000000 00001100

after right shift: 12 >>> 1

00000000 00000000 00000000 00000110

-2,147,483,552

10000000 00000000 00000000 01100000

-2,147,483,552 >> 4 = -134,217,722

11111000 00000000 00000000 00000110
```

## Manipulation

```
X * 2 = X << 1
X * 3 = X << 1 + X
X * 2^k = x << k
X * 12 = X * 8 + X * 4 = (X << 3) + (X << 2)
X * 14 = X * 16 - X * 2 = (X << 4) - (X << 1)

X / 2 = X >> 1
X / 2^k = X >> k
```

