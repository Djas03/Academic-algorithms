
#CLASSE CARRO
class CAR :
    def __init__(self, marca, modelo, ano):
        self.marca = marca
        self.modelo = modelo
        self.ano = ano
    
    #SELETORES
    def get_marca (self):
        return self.marca
    def get_modelo (self):
        return self.modelo
    def get_ano (self):
        return self.anoo

    #MODIFICADORES
    def set_marca(self, marca):
        self.marca = marca
    def set_modelo(self, modelo):
        self.modelo = modelo
    def set_ano(self, ano):
        self.ano = ano

    #METODOS
    def mostraDados(self): #mostra os dados
        print('Marca:', self.marca, '\nModelo:', self.modelo, '\nAno:', self.ano )

#FUNCAO PRINCIPAL
def main ():
    '''
    car1 = CAR('Gol', 'Sedan', 2010)
    car1.mostraDados()

    print('Testando o get_marca : ', car1.get_marca())
    '''
    while (1):
        print('*************BEM VINDO AO AUTOCENTER*************')
        print('Digite 1 para CADASTRAR ou 0 para SAIR:')
        val = input()
        match val:
            case '1':
                print('Digite a marca do carro:')
                marca = input()
                print('Digite o modelo do carro:')
                modelo = input()
                print('Digite o ano do carro:')
                ano = input()

                car1 = CAR(marca, modelo, ano)

                print('*************CARRO CADASTRADO COM SUCESSO*************')
                car1.mostraDados()



            case '0':
                print('*************SAINDO*************')
                break

#INSTANCIAR A FUNCAO MAIN
if __name__ == '__main__':
    main()