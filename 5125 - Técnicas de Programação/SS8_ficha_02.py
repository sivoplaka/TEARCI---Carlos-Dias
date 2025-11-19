def par(x):
    #exercicio 1
    if x % 2 == 0:
        print("Número par")
    else:
        print("Número ímpar")
        
def semaforo(cor):
    #exercicio 2
    if cor.lower() == "vermelho":
        print("Passagem proibida!")
    elif cor.lower() == "amarelo":
        print("Transição para vermelho")
    elif cor.lower() == "verde":
        print("Passagem autorizada")
    else:
        print("Côr inválida.")

def fact_w(n):
    #exercicio 3
    contar=n
    total=1
    while contar > 1:
        total = total * contar
        contar -= 1
        print(total)

def fact_f(n):
    #exercicio 4
    total=1
    for i in range (1,n+1,1):
        total = total * i
        print(total)

def fact_r (n):
    #exercicio 5
    if n == 0 or n == 1:
        return 1
    return(n*fact_r(n-1))

def lista ():
    #exercicio 6
    lista = list([1,2,3,4,5,6,7,8,9])
    soma=0
    contagem=0
    for i in lista:
        soma += i
        contagem += 1
    media = soma/contagem
    print(f"Contagem: {contagem}")
    print(f"Soma: {soma}")
    print(f"Média: {media}")

def validar_nif(n):
    if not len(n) == 9:
        print("Obrigatório 9 dígitos.")
    if not n.isdigit():
        print("Apenas dígitos.")
        
    soma = 0
    multiplicador = 9
    for i in n:
        soma = soma + int(i) * multiplicador
        print(i, multiplicador, soma)
        multiplicador -= 1
    
    if soma % 11 < 2:
        print("Válido")
    else:
        print("Inválido")
