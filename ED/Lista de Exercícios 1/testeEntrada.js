var input = require('fs').readFileSync('stdin', 'utf8');
var lines = input.split('\n');
var numeros = []
for (let i = 0, line = []; i < lines.length; i++){
    line = lines[i].split(' ')
    for (let numero of line){
        numeros.push(numero)
    }
}

console.log(numeros)

var A = parseInt(numeros.shift())
var B = parseInt(numeros.shift())

var X = A + B

console.log('X = ' + X)