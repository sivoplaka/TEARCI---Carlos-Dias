#Exercício 1
def exercicio1():
    a = 5
    print(a)
    b = 7
    print(b)
    c = a + b
    print(c)
    menu()
#---------------------------------------------------------------    
#Exercício 2
def idade ():
    idade = int(input("Qual é a sua idade? \n"))
    if idade < 18:
        print(f"É menor de idade.")
    else:
        print(f"É maior de idade.")
    menu()
 #---------------------------------------------------------------       
#Exercício 3
def consumo ():
    km = float(input("Indique quantos Km's percurreu: \n"))
    gasto = float(input("Indique o gasto médio do carro (l/100km's): \n"))
    litro = float(input("Indique o preço do combustível: \n"))
    litros_consumidos = (km / 100) * gasto
    custo_total = litros_consumidos * litro
    print(f"O custo total da viagem é: {custo_total:.2f}€ \ngastando {litros_consumidos:.2f} litros.")
    menu()
#---------------------------------------------------------------    
#Exercício 4
def imc():
    peso = float(input("Indique o seu peso: \n"))
    altura = float(input("Indique a sua altura: \n"))
    total = peso/altura**2
    if total < 18.5:
        print(f"Valor: {total:.2f} | Baixo peso.")
    elif total >= 18.5 or total < 25:
        print(f"Valor: {total:.2f} | Peso adequado.")
    elif total >= 25 or total < 30:
        print(f"Valor: {total:.2f} | Sobrepeso.")
    elif total >= 30 or total < 34.9:
        print(f"Valor: {total:.2f} | Obesidade.")
        
    menu()
#---------------------------------------------------------------    
#Exercício 5
def fatorial_while():
    numero = int(input("Indique o número inteiro: \n"))
    total = 1
    n = numero
    while n >= 1:
        total = total * n
        print (f"{total}")
        n -= 1
    menu()   

def fatorial_for():
    numero = int(input("Indique o número: \n"))
    total = 1
    for i in range(numero,0,-1):
        total = i * total
        print (f"{total}")
    menu()
#---------------------------------------------------------------    
#Desafio-1
def inteiro_while():
    inferior = int(input("Insira o número inferior: \n"))
    superior = int(input("Insira o número superior: \n"))
    soma = 0
    i = inferior
    while i <= superior:
        soma += i
        i += 1
        print(soma)
    menu()  
    
def inteiro_for():
    inferior = int(input("Insira o número infeiro: \n"))
    superior = int(input("Insira o número superior. \n"))
    soma = 0
    for i in range(inferior, superior + 1, 1):
        soma += i
        print(soma)
    menu()   
#---------------------------------------------------------------        
#Desafio-2    
def multiplicacao_while():
    um = int(input("Insira um número: \n"))
    dois = int(input("Insira o multiplicador: \n"))
    i = 0
    total = 0
    while i < dois:
        total += um
        i+=1
        print(total)
    menu()
    
    
def multiplicacao_for():
    um = int(input("Insira um número: \n"))
    dois = int(input("Insira o multiplicador: \n"))
    total = 0
    for i in range (1, dois + 1, 1):
        total += um 
        print(total)
    menu()
#---------------------------------------------------------------        
#Menu    
def menu():
    escolha = str(input("O que pretende fazer?: \n"))
    while True:
        if escolha == "for":
            fatorial_for()
            break
        elif escolha == "multiw":
            multiplicacao_while()
            break
        elif escolha == "multif":
            multiplicacao_for()
            break
        elif escolha == "while":
            fatorial_while()
            break
        elif escolha == "inteirow":
            inteiro_while()
            break
        elif escolha == "inteirof":
            inteiro_for()
            break
        elif escolha == "imc":
            imc()
            break
        elif escolha == "consumo":
            consumo()
            break
        elif escolha == "idade":
            idade()
            break
        elif escolha == "exercicio1":
            exercicio1()
            break
        
#---------------------------------------------------------------            
if __name__ == "__main__":
    menu()