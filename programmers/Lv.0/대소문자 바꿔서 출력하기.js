const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let input = [];
let answer = "";

rl.on('line', function (line) {
    input = [line];
}).on('close',function(){
    str = input[0];
    
    for(let i = 0; i < str.length; i++) {
        if(str[i] === str[i].toLowerCase()) {
            answer += str[i].toUpperCase();
        } else {
            answer += str[i].toLowerCase();
        }
    }
    
    console.log(answer);
});