ORDERED SET - 
find_by_order() and order_of_key(). The first returns an iterator to the k-th largest element (counting from zero), the second — the number of items in a set that are strictly smaller than our item.


BINARY SEARCH -

VECTORS - 
lower_bound(all(vector_name), value) - returns an iterator pointing to the first element which has a value not less than ‘val’.
upper_bound(all(vector_name, value)) - returns an iterator pointing to the first element which has a value greater than ‘val’.

SETS - 
 
set.lower_bound(value) - iterator pointing to the element in the container which is equivalent to k passed in the parameter.In case k is not present in the set container, the function returns an iterator pointing to the immediate next element which is just greater than k.

set.upper_bound(value) - The function returns an iterator pointing to the immediate next element which is just greater than value.

MAPS -

map.upper_bound(value) - returns an iterator pointing to the immediate next element just greater than value.

map.lower_bound(value) - iterator pointing to the key in the map container which is equivalent to value passed in the parameter. In case k is not present in the map container, the function returns an iterator pointing to the immediate next element which is just greater than value,

