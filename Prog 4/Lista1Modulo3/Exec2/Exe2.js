/*Crie um array contendo trˆes valores. Crie um segundo array de trˆes posi ̧c ̃oes e adicione em cada
posi ̧c ̃ao o primeiro array criado. Mostre no console, para cada array interno, a posi ̧c ̃ao correspon-
dente do array externo.*/

var A = new Array();

A[0] = 1;
A[1] = 2;
A[2] = 3;

var B = new Array();

B[0] = 4;
B[1] = 5;
B[2] = 6;


var C = new Array();

C[0] = 7;
C[1] = 8;
C[2] = 9;

var D = [A, B, C];
for (var i = 0; i < D.length; i++ ){
    console.log(D[i]);
    
    

}