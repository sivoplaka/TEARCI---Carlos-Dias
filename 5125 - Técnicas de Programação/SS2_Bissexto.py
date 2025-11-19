ano=int(input("Introduza um ano: \n"))

if ano%400 == 0:
   print(f"{ano} é bissexto.")
elif ano%100 == 0:
   print(f"{ano} não é bissexto.")
elif ano%4==0:
   print(f"{ano} é bissexto.")
else:
   print(f"{ano} não é bissexto.")