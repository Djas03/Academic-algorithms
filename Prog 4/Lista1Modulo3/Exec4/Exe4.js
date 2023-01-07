/*Crie uma fun ̧c ̃ao countdown que receba como parˆametro um inteiro n e mostre no browser (via
alert) a contagem regressiva de n at ́e 0. */



function countDown (n){
    for (var i= n; i >= 0; i--){
        window.alert(i);
    }

}
var n = window.prompt("digite um numero: ");
countDown(n)