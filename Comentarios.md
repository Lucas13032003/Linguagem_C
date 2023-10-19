# Estrutura de dados

## Como debugar um código:

    - gcc o- <Nome para o código> + <Nome do arquivo.c>
        - <Nome do arquivo.c>

- \n -----> significa quebra de linha
- %d -----> Números inteiros
- %f -----> Números com virgula(Deve usar o ponto)
- %.3f ---> Números com virgula e tmabém determina a quantidades de casas que irão aparecer.

| Digito | Descrição                                 |
|:------:|------------------------------------------|
|   d/x  | Números inteiros na base DECIMAL ou HEXADECIMAL |
|   x    | Números inteiros na base HEXADECIMAL    |
|   f    | Números em ponto Flutuante (com casas decimais) |
|   e    | Números em notação científica (com casas decimais) |
|   c    | Caracteres alfanuméricos (texto)         |
|   s    | Sequência de caracteres alfanuméricos (texto) |
| [^chars] | Lê todos os dados digitados, exceto os especificados em "chars" |

</br>

-  Scanf ---> é utilizado para realizar interações no terminal.
    - Sintaxe: scanf ("%f", &varivel).

# Variáveis

- {tipo} {nome}
    - Não pode número 1ª posição
    - Não pode carcteres especiais
    - Não pode ter espaço

## Tipo

| Tipo de Variável | Número de Bits | Faixa de Representação               |
|------------------|-----------------|-------------------------------------|
| `char`           | 8 bits          | -128 a 127 |
| `short`          | 16 bits         | -32,768 a 32,767
| `int`            | 32 bits         | -2,147,483,648 a 2,147,483,647 |
| `long`           | 64 bits         | -9,223,372,036,854,775,808 a 9,223,372,036,854,775,807 |
| `float`          | 32 bits         | Aproximadamente ±3.4 x 10^38  |
| `double`         | 64 bits         | Aproximadamente ±1.7 x 10^308 |
| `long double`    | Pode variar      | Geralmente maior que `double`, mais de 80 bits e maior precisão |

## Constante
- "#"define
    - Sintaxe: "#"define {nome} {valor}

## Operadores
- Soma ---> +
- Subtração ---> -
- Multiplicação ---> *
- Divisão ----> /
- Resto de divisão inteira ---> %

## Atribuições aritméticas

- Inclemento em 1 unidade: ++
- Decremento em 1 unidade: --
- Incremento genérico: +=
- Decremento genérico: -=
- Atribuição com multiblicação: *=
- Areibuição com divisão: /=

# if

**Definição:**
    - Se a condição for verdadeira execute-a, caso contrário inginore.

**Sintxe:**
    
    if ({condição}){   
        bloco de comoandos
    }

**Operadores Relacionais**

| Operador | Descrição                 | Exemplo            |
|----------|---------------------------|--------------------|
| ==       | Igual a                   | `5 == 5` é verdadeiro |
| !=       | Diferente de              | `3 != 8` é verdadeiro |
| <        | Menor que                 | `4 < 7` é verdadeiro  |
| >        | Maior que                 | `9 > 2` é verdadeiro  |
| <=       | Menor ou igual a          | `5 <= 5` é verdadeiro |
| >=       | Maior ou igual a          | `8 >= 8` é verdadeiro |

**Observação:**

    - Utilizamos == só mente para comparações.

**switch**

    switch (Var){

    case (V1)
        bloco de códigos_1
    break;

    case (V2)
        bloco de códigos_2
    break;

    case (VN)
        bloco de códigos_N
    break;
    
    default:
        Bloco de código padrão
    break;
    }

**While**
- Sempre devemos iniciar a variavel
- Definição de uma condição de parada;
    - Enquanto o bloco de comando for verdadeiro ele irá repitir até el ser falso.


    while (/* condition */){

        /* code */
    
    }

**do-While**
    
    do{

        /* code */

    } while (/* condition */);

**For**

    for (inicialização; condição; atualização(incremento ou decremento)) {
        // Corpo do loop
    }   

**break**

    - Realiza a parada da condição.

**Continue**

    - Inginora somente a condição estabelecida.

# Vetores:

    - <tipo> <nome> [<tamanho>];

**Acesso a uma pocição**

    - Não é possivel acessar um vetor todo.

**Sintaxe de acesso**

    <nome> [<indice>]

**Lista mde incialização:** preenche uma vetor todo de uma vez só.

    <tipo> <nome> [<tamanho>] = {<v1>, <v2>, ... , <vn>};

# String
\0 --> ecerra a string/texto

Para um texto de 10 caractere iremos utilizar 11.

**scanf**
- Limatações: sintaxe rebuscada
- Especificador de formato: %s
- Sintaxe geral:
    - scanf("%s", <str>);
- Sintaxe aprimorada:
    - scanf("%<tam.-1>[^\n]s", <str>); 


