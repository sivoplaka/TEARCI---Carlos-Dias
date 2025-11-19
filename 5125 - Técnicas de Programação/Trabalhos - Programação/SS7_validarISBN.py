def validar_isbn(numero):
    
    if not len(numero) == 13:
        print("NOK-COMP")
        return False
    if not numero.isdigit():
        print("NOK-NUM")
        return False
    
    soma = 0
    for i in range(len(numero)):
        if i % 2 == 0:
            multiplicador = 1
        else:
            multiplicador = 3
        resultado = int(numero[i]) * multiplicador
        print(resultado)
        soma += resultado

    print(f"Total: {soma}")
    
    if soma % 10 == 0:
        print("OK-ISBN")
        return True
    else:
        print("NOK-ISBN")
        return False
