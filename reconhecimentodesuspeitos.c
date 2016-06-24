#include <stdio.h>
#include <stdlib.h>
// 0 Falso e 1 Verdadeiro
int q1, q2, q3, q4, q5, r = 0;

int quest1, quest2, quest3, quest4, quest5, resultado;

int main () {

    printf("Responda com 1 para Sim e 0 para Não\n" );
    quest1();


}

int quest1(){
  printf("Telefonou pra vítima?\n" );
  scanf("%d", &q1 );
  if (q1!= 0 || q1 != 1) {
    printf("Responda apenas com 0 ou 1, fdp\n" );
    quest1();
  }else{
    quest2();
  }
}
int quest2(){
  printf("Esteve no local do crime?\n" );
  scanf("%d", &q2 );
  if (q2!= 0 || q2 != 1) {
    printf("Responda apenas com 0 ou 1, fdp\n" );
    quest2();
  }else{
    quest3();
  }
}
int quest3(){
  printf("Mora perto da vítima?\n" );
  scanf("%d\n", &q3 );
  if (q3!= 0 || q3 != 1) {
    printf("Responda apenas com 0 ou 1, fdp\n" );
    quest3();
  }else{
    quest4();
  }
}
int quest4(){
  printf("Devia para a vítima?\n" );
  scanf("%d\n", &q4 );
  if (q4!= 0 || q4 != 1) {
    printf("Responda apenas com 0 ou 1, fdp\n" );
    quest4();
  }else{
    quest5();
  }
}
int quest5(){
  printf("Já trabalhou com a vítima?\n" );
  scanf("%d\n", &q5 );
  if (q5!= 0 || q5 != 1) {
    printf("Responda apenas com 0 ou 1, fdp\n" );
    quest5();
  }else{
    resultado();
  }
}
int resultado(){
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
