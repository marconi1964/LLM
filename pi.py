from decimal import Decimal, getcontext
import math

def calculate_pi(digits):
    # Set the precision
    getcontext().prec = digits + 2  # Extra digits to reduce rounding errors
    C = Decimal(426880) * Decimal(math.sqrt(10005))
    M = Decimal(1)
    L = Decimal(13591409)
    X = Decimal(1)
    K = Decimal(6)
    S = L

    for i in range(1, digits):
        M = (K**3 - 16*K) * M / (i**3)  # Ensure all numbers are Decimal
        L += Decimal(545140134)
        X *= Decimal(-262537412640768000)
        S += Decimal(M * L) / X
        K += Decimal(12)  # Convert to Decimal

    pi = C / S
    return +pi  # The + operator applies the precision to the result

# Calculate π to 100 digits
pi_1000_digits = calculate_pi(1000)
print(f"π to 100 digits:\n{pi_1000_digits}")
