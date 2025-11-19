print("#" * 20, "Cálculo da Páscoa", "#" * 20)
ano=int(input("Introduza o Ano: \n"))
x=24
y=5
a=ano%19
b=ano%4
c=ano%7
d=((19*a)+x)%30
e=((2*b)+(4*c)+(6*d)+y)%7
#calculos
if (d+e)<10:
    dia=(d+e+22)
    print(f"{dia} de Março")
else:   
   dia=(d+e-9)
   print(f"{dia} de Abril")