/*Crie um array contendo os valores Pedra, Papel e Tesoura. Pe ̧ca ao usu ́ario via prompt para
informar o item escolhido. Mostre via console o resultado do jogo. Exemplo: Papel venceu
Pedra. */

var jo = ["pedra", "papel", "tesoura"];

var user = window.prompt("Escolha entre Pedra, Papel ou Tesoura : ");

var cpu = jo[Math.floor(Math.random()*3)];

//Caso usuario informe pedra
if(user == "pedra" && cpu == "tesoura"){
    console.log("Você ganhou!Pedra ganha de tesoura!");
}
else if(user == "pedra" && cpu == "papel"){
    console.log("Você perdeu! Pedra perde de papel");
}
else if(user == "pedra" && cpu == "pedra"){
    console.log("Empate!Pedra empata com Pedra");
}

//Caso usuario informe papel
if(user == "papel" && cpu == "tesoura"){
    console.log("Você perdeu!Papel perde de tesoura");
}
else if(user == "papel" && cpu == "papel"){
    console.log("Empate!Papel empata com papel");
}
else if(user == "papel" && cpu == "pedra"){
    console.log("Você ganhou!Papel ganha de Pedra");
}

//Caso usuario informe tesoura
if(user == "tesoura" && cpu == "tesoura"){
    console.log("Empate!Tesoura empata com tesoura");
}
else if(user == "tesoura" && cpu == "papel"){
    console.log("Você ganhou!Tesoura ganha de papel");
}
else if(user == "tesoura" && cpu == "pedra"){
    console.log("Você perdeu!Tesoura perde pra pedra");
}
