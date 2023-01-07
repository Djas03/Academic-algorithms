/*Crie trˆes vari ́aveis a, b e c adicionando valores diretamente. Em seguida, some a e b, divida este
valor por c e substitua o valor de c pelo resto de c e b. Imprima os trˆes n ́umeros no console.*/

var a = 6;
var b = 4;
var c = 2;
var soma;
var div;

soma = a + b;
div = soma / c;
c = c%b;

console.log("Soma: " + soma);
console.log("Divisão: " + div);
console.log("Resto: " + c);


