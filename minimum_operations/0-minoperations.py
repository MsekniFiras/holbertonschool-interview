#!/usr/bin/python3

def minOperations(n):

    """
    Calculate the minimum number of operations needed to get n 'H' characters in the file
    """
    
    if n < 2:
        return 0  # If n is less than 2, it's impossible to achieve using operations

    operations = 0
    factor = 2  # Start checking for factors from 2

    # Loop until n becomes 1
    while n > 1:
        # While factor is a divisor of n, keep dividing n by factor and increase operations
        while n % factor == 0:
            operations += factor
            n = n // factor
        factor += 1  # Move to the next factor

    return operations

# Example usage
if __name__ == "__main__":
    n = 4
    print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))

    n = 12
    print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))