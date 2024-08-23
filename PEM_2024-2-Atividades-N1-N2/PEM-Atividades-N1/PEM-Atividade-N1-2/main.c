#include <stdio.h>
#include <stdlib.h>

float calcularNotaFinal(int N, float notas[]) {
    float soma = 0.0;
    float maior = notas[0], menor = notas[0];
    int i;

    for (i = 1; i < N; i++) {
        if (notas[i] > maior) {
            maior = notas[i];
        }
        if (notas[i] < menor) {
            menor = notas[i];
        }
    }

    for (i = 0; i < N; i++) {
        if (notas[i] != maior && notas[i] != menor) {
            soma += notas[i];
        }
    }

    int contMaior = 0, contMenor = 0;
    for (i = 0; i < N; i++) {
        if (notas[i] == maior) contMaior++;
        if (notas[i] == menor) contMenor++;
    }

    if (contMaior > 1) soma += (contMaior - 1) * maior;
    if (contMenor > 1) soma += (contMenor - 1) * menor;

    return soma;
}

int main() {
    int i, j;
    int N;
    float notaFinal = 0.0;
    char* nomeTeste[] = {
        "Raciocinio logico",
        "conceitos de gerenciamento de projetos",
        "lingua inglesa",
        "conceitos de metodologia agil",
        "linguagem javascript"
    };
    int numTestes = sizeof(nomeTeste) / sizeof(nomeTeste[0]);
    float notasFinais[numTestes];


    for (i = 0; i < numTestes; i++) {
        printf("Informe o numero de notas para o teste %s: \n", nomeTeste[i]);
        scanf("%d", &N);

        float notas[N];
        printf("Informe as notas para o teste %s separadas por espaco: \n", nomeTeste[i]);
        for (j = 0; j < N; j++) {
            scanf("%f", &notas[j]);
        }

        notasFinais[i] = calcularNotaFinal(N, notas);
        notaFinal += notasFinais[i];
    }


    for (i = 0; i < numTestes; i++) {
        printf("Nota %s = %.0f\n\n\n", nomeTeste[i], notasFinais[i]);
    }

    printf("Nota final do candidato = %.0f\n\n\n", notaFinal);

    return 0;
}
