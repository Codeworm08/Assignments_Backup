import re
phone=input("Enter a phone number")
if re.match("^(\+\d{2}|\+)?[\d]{10}$",phone):
    print("Valid number")
else:
    print("Invalid number")