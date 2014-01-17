# network-patricia

An implementation of a Patricia Trie geared specifically for storing
IP addresses with a CIDR-style prefix.

The Patricia Trie and its close relative, the Radix Trie are space-
optimized data structures well-suited for storing network addresses.

Nodes with only one child are merged with their child. Though this yields
higher average access costs, it's a very convenient property when dealing
with overlapping ranges and potentially duplicate addresses.


## libpatricia

Functions for inserting nodes, removing nodes, and searching in a Patricia
trie designed for IP addresses and netmasks. A head node must be created
with `(key,mask) = (0,0)`.


## ptest

This executable serves as an example of how to use the Patricia Trie
library for doing longest-prefix matching.

We begin by adding a default node as the head of the Patricia trie. This
will become an initialization function (`pat_init`). We then read in a set
of IPv4 addresses and network masks from a data file (given in `argv[1]`)
and insert them into the trie.


## Implementation Notes

The fact that we keep multiple masks per node makes this more complicated
and computationally expensive then a standard trie. We do this because we
need to do longest prefix matching, which is useful for computer networks,
but not as useful in other applications.


## Performance

Traversing is an O(k) operation (where "k" is the length of the key).


## Authors

- Matthew Smart <mcsmart@eecs.umich.edu>
- [The LLVM Project](http://llvm.org)
- J. Brandt Buckley <brandt@runlevel1.com>


## License

Licensed under the GNU LGPL 2.1.

Copyright (c) 2000 The Regents of the University of Michigan
Copyright (c) 2014 J. Brandt Buckley
