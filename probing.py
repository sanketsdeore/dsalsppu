class TelephoneBook:
    def __init__(self, size):
        self.size = size
        self.table = [None] * size

    def hash_function(self, key):
        return key % self.size

    def linear_probe_insert(self, key, value):
        index = self.hash_function(key)
        while self.table[index] is not None:
            index = (index + 1) % self.size
        self.table[index] = (key, value)

    def linear_probe_search(self, key):
        index = self.hash_function(key)
        while self.table[index] is not None:
            if self.table[index][0] == key:
                return self.table[index][1]
            index = (index + 1) % self.size
        return None

    def quadratic_probe_insert(self, key, value):
        index = self.hash_function(key)
        i = 1
        while self.table[index] is not None:
            index = (index + i**2) % self.size
            i += 1
        self.table[index] = (key, value)

    def quadratic_probe_search(self, key):
        index = self.hash_function(key)
        i = 1
        while self.table[index] is not None:
            if self.table[index][0] == key:
                return self.table[index][1]
            index = (index + i**2) % self.size
            i += 1
        return None

# Example usage:
phone_book_linear = TelephoneBook(10)
phone_book_quadratic = TelephoneBook(10)

phone_book_linear.linear_probe_insert(123, "John")
phone_book_linear.linear_probe_insert(456, "Alice")
phone_book_linear.linear_probe_insert(789, "Bob")

phone_book_quadratic.quadratic_probe_insert(123, "John")
phone_book_quadratic.quadratic_probe_insert(456, "Alice")
phone_book_quadratic.quadratic_probe_insert(789, "Bob")

print("Linear Probing:")
print(phone_book_linear.linear_probe_search(123))  # Output: John
print(phone_book_linear.linear_probe_search(456))  # Output: Alice
print(phone_book_linear.linear_probe_search(789))  # Output: Bob

print("Quadratic Probing:")
print(phone_book_quadratic.quadratic_probe_search(123))  # Output: John
print(phone_book_quadratic.quadratic_probe_search(456))  # Output: Alice
print(phone_book_quadratic.quadratic_probe_search(789))  # Output: Bob

