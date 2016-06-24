#include <stdio.h>
#include <stdlib.h>
// 0 Falso e 1 Verdadeiro
int q1, q2, q3, q4, q5, r = 0;
int main () {

    printf("Responda com 1 para Sim e 0 para Não\n", );
    printf("Telefonou pra vítima?\n", );
    scanf("%d\n", &q1 );
    if (q1!= 0 || q1 != 1) {
      printf("Responda apenas com 0 ou 1, fdp\n", );
    }
    printf("Esteve no local do crime?\n", );
    scanf("%d\n", &q2 );
    if (q2!= 0 || q2 != 1) {
      printf("Responda apenas com 0 ou 1, fdp\n", );
    }
    printf("Mora perto da vítima?\n", );
    scanf("%d\n", &q3 );
    if (q3!= 0 || q3 != 1) {
      printf("Responda apenas com 0 ou 1, fdp\n", );
    }
    printf("Devia para a vítima?\n", );
    scanf("%d\n", &q4 );
    if (q4!= 0 || q4 != 1) {
      printf("Responda apenas com 0 ou 1, fdp\n", );
    }
    printf("Já trabalhou com a vítima?\n", );
    scanf("%d\n", &q5 );
    if (q5!= 0 || q5 != 1) {
      printf("Responda apenas com 0 ou 1, fdp\n", );
    }
    r = q1 + q2 + q3 + q4 + q5;
    if (r == 2) {
      printf("Suspeito!!!\n", );
    }if (r == 3 || r == 4) {
      printf("Cúmplice!\n", );
    }if (r == 5) {
      printf("MÃO NA CABEÇA!!!\n", );
    }else {
      printf("Inocente :)\n", );
    }

}
