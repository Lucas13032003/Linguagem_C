#include <iostream>
#include <unordered_set>

int main() {
    int N;
    
    // Lê a quantidade de números proibidos
    std::cin >> N;

    // Cria um conjunto para armazenar os números proibidos
    std::unordered_set<int> numerosProibidos;

    // Lê os números proibidos e os adiciona ao conjunto
    for (int i = 0; i < N; i++) {
        int num;
        std::cin >> num;
        numerosProibidos.insert(num);
    }

    int consulta;

    // Processa as consultas
    while (std::cin >> consulta) {
        // Verifica se o número está no conjunto de números proibidos
        if (numerosProibidos.find(consulta) != numerosProibidos.end()) {
            std::cout << "sim" << std::endl;
        } else {
            std::cout << "nao" << std::endl;
        }
    }

    return 0;
}
