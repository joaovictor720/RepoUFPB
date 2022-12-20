//const input = require('prompt-sync')()

var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');
var numeros = []
for (let i = 0, line = []; i < lines.length; i++){
    line = lines[i].split(' ')
    for (let numero of line){
        numeros.push(numero)
    }
}

function preencherDict(){
    let dict = {}
    for (let i = 0; i < nElementos; i++){
        //let temp = prompt('LENDO TEMP: ')
        let temp = parseInt(numeros.shift())
        if (dict[temp] === undefined){
            dict[temp] = []
        }
        dict[temp].push(i+1)
    }
    return dict
}

function consultarDict(dicio, nOcorrencia, busca){
    if ((dicio[busca])[nOcorrencia-1] !== undefined){
        return (dicio[busca])[nOcorrencia-1]
    }else{
        return -1
    }
}

function DEBUG(){
    console.log(arguments[0])
}

var nElementos, nConsultas, nOcorrencia, busca

while(true){
    nElementos = parseInt(numeros.shift())
    if (nElementos === undefined){
        break;
    }
    nConsultas = parseInt(numeros.shift())
    let dicionario = preencherDict()

    for (let i = 0; i < nConsultas; i++){
        nOcorrencia = parseInt(numeros.shift())
        busca = parseInt(numeros.shift())
        let consulta =  consultarDict(dicionario, nOcorrencia, busca)

        if (consulta !== -1){
            console.log(consulta)
        }else{
            console.log(0)
        }
    }
}