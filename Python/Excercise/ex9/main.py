principle = 0
rate = 0
time = 0

while principle <= 0:
    principle = float(input("Please enter principle amount: "))
    if principle <= 0:
        print("Principle cannot be less than or equal to zero")

while rate <= 0:
    rate = float(input("Please enter the interest rate: "))
    if rate <= 0:
        print("Interest rate cannot be less than or equal to zero")

while time <= 0:
    time = int(input("Please enter the time: "))
    if time <= 0:
        print("Time cannot be less than or equal to zero")

total = principle * pow((1 + rate / 100), time)
print(f"Balance after {time} year/s: ${total:,.2f}")
