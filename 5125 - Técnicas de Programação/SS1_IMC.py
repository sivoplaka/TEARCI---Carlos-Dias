peso=float(input("Introduza o peso (kg):"))
altura=float(input("Introduza a altura (metros):"))
imc=peso/(altura*altura)
if imc<18.5:
    print(f"O seu índice de {imc:.2f} está abaixo do normal")
elif imc>18.4 or imc<25:
    print(f"O seu índice de {imc:.2f} está normal")
elif imc>24.9 or imc<30:
    print(f"O seu índice de {imc:.2f} indica sobrepeso")
elif imc>29.9 or imc<35:
    print(f"O seu índice de {imc:.2f} indica Obsidade grau I")
elif imc>34.9 or imc<40:
    print(f"O seu índice de {imc:.2f} indica Obsidade grau II")
elif imc>40:
    print(f"O seu índice de {imc:.2f} indica Obsidade grau III")
