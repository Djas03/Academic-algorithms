window.onload=function(){
    var select = document.getElementById("produtos");
    newvalor = 0;

    select.addEventListener('change', function(){
        
        opcaoTexto = select.options[select.selectedIndex].text;
        console.log(opcaoTexto);
        opcaoValor = select.options[select.selectedIndex].value;
        valuefloat = parseFloat(opcaoValor)
    })


    var botao = document.getElementById('button');


    botao.onclick = function adicionar(){

        var newel = document.createElement('li');
        var newtext = document.createTextNode(opcaoTexto);
        newel.appendChild(newtext);
        //SELECIONA A POSIÇÃO QUE A NOVA li SERA INSERIDA
        var position = document.getElementsByTagName('ul')[0];
        position.appendChild(newel);

        var total = document.getElementById('result');
        var novotot = total.firstChild.nodeValue;

        newvalor = newvalor +  valuefloat;

        console.log(newvalor);

      
        if (novotot == '0.00') {
            novotot = novotot.replace('0.00', newvalor);
            total.firstChild.nodeValue = novotot;
        }else{
            novotot = novotot.replace(novotot, newvalor.toFixed(2));
            total.firstChild.nodeValue = novotot;
        }


    }
}
