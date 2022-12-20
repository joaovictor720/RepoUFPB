//const input = require('prompt-sync')()

var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');

function preencherDict(){
    let dict = {}
    let entrada = lines.shift().split(' ')
    for (let i = 0; i < nElementos; i++){
        //let temp = prompt('LENDO TEMP: ')
        let temp = parseInt(entrada.shift())
        if (dict[temp] === undefined){
            dict[temp] = []
        }
        dict[temp].push(i+1)
    }
    return dict
}

function consultarDict(dicio, nOcorrencia, busca){
    //DEBUG('DENTRO DE CONSULTAR')
    //DEBUG('dicio = ' + dicio)
    //DEBUG('nOcorrencia = ' + nOcorrencia)
    //DEBUG('busca = ' + busca)
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
    var entrada = lines.shift()
    if (entrada === undefined){
        break;
    }
    entrada = entrada.split(' ')
    nElementos = parseInt(entrada.shift())
    nConsultas = parseInt(entrada.shift())
    //DEBUG('nElementos = ' + nElementos)
    //DEBUG('nConsultas = ' + nConsultas)
    var dicionario = preencherDict()

    for (let i = 0; i < nConsultas; i++){
        entrada = lines.shift().split(' ')
        nOcorrencia = parseInt(entrada.shift())
        busca = parseInt(entrada.shift())
        //DEBUG('dicionario = ' + dicionario)
        //DEBUG('nOcorrencia = ' + nOcorrencia)
        //DEBUG('busca = ' + busca)
        let consulta =  consultarDict(dicionario, nOcorrencia, busca)

        if (consulta !== -1){
            console.log(consulta)
        }else{
            console.log(0)
        }
    }
}
