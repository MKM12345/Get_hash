# Get_hash
My [get_hash()](https://github.com/hamdivazim/usefulib/blob/main/usefulib/_usefulibs.py) function in C++.

In python it is this:

```
def get_hash(string):
    if not isinstance(string, str):
        raise TypeError("get_hash() cannot get the hash of a non-string.")
    return hashlib.sha256(string.encode('utf-8')).hexdigest()

```

And this C++ version is a almost accurate translation.
