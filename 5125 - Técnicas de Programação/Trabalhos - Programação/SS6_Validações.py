def validar_nome(nome):
    for i in nome:
        if i>='0' and i<='9':
            print("NOKNOME-NUMEROS")
            return False
    
    if len(nome) < 6:
        print("NOKNOME-LENGHT")
        return False
    elif ' ' not in nome:
        print("NOKNOME-ESPAÇO")
        return False
    else:
        print('OKNOME')
        return True
        
def validar_email (email):
    ind=email.find('@formacao.iefp.pt')
    if ind == -1:
        print("NOKEMAIL-FORMATO@")
        return False
    elif email[0:email.index('@')].isdigit():
        print('OKEMAIL')
        return True
    else:
        print('NOKEMAIL-LETRAS@')
        return False

def validar_numero (numero):
    for i in numero:
        if i < 9 or i > 9:
            print("NOKNUMERO-LENGHT")

    if not numero.index(0) == 9 or numero.index(0) == 2:
        print("NOKNUMERO-9OR2")
    else:
        print("OKNUMERO")

def validar_codigopostal(codigopostal):
    invalido = 0

    if not len(codigopostal) == 8:
        print('NOKCOD-COMP')
        return False

    if not codigopostal[:4].isdigit():
        print('NOKCOD-4NUM')
        return False
    
    if codigopostal[4] != '-':
        print('NOKCOD-ESPAÇO')
        return False
    
    if not codigopostal[5:].isdigit():
        print('NOKCOD-EXTENSAO')
        return False
    
    print('OKCOD')
    invalido = 1
    return False
   
nome = input("Digite o nome completo: \n")
email = input("Digite o email: \n")
numero = input("Digite o seu número: \n")
codigopostal = input("Digite o seu código postal: \n")

validar_nome(nome)
validar_email(email)
validar_numero(numero)
validar_codigopostal(codigopostal)
