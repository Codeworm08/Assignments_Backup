import random
discounts={}
def generate_coupon_code(discount_rate,day):
    """Generate a coupon code with a given discount rate."""
    code = ""
    characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"

    for _ in range(8):
        code += random.choice(characters)

    if day not in discounts.keys():
        discounts[day]=[]
    discounts[day].append([code,discount_rate])

while True:
    d=set(["monday","tuesday","wednesday","thursday","friday","saturday","sunday"])
    day=input("Enter day: ")
    if day not in d:
        print("Enter valid day.")
        continue
    rate=input("Enter rate: ")
    generate_coupon_code(rate,day)
    q=input("Enter q to quit.")
    if q=="q":
        break
while True:
    day=input("Enter day:")
    if day in discounts.keys():
        print("Available codes and rates: ")
        i=0
        for c,r in discounts[day]:
            print(c,":",r,"index: ",i)
            i+=1
        coupon=int(input("Choose the index: "))
        if coupon>=0 and coupon<len(discounts[day]):
            print("Coupon: ",discounts[day][coupon][0],"Rate: ",discounts[day][coupon][1])
        else:
            print("Invalid index")
    else:
        print("No coupon available on ",day)
    x=input("q->quit.enter->continue")
    if x=="q":
        break
         
