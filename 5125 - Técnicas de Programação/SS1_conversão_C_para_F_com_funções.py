def celsius(n):
    f=int(input("Digite graus Fahrenheit: "))
    c=(f-32)/1.8
    print(f"{c}ºC")

    
def fahrenheit(n):
    c=int(input("Digite graus Celsius: "))
    f=(c*1.8)+32
    print(f"{f}ºF")

if __name__ == "__main__":
n=input("C para celsius, F para Fahrenheit: ")
if (n=="C") or (n=="c"):
    celsius(n)
elif (n=="F") or (n=="f"):
    fahrenheit(n)
else:
    print("Nenhum caracter aceitável.")




