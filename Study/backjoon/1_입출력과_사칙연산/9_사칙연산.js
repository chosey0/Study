const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().split(" ");

var a = parseInt(input[0]);
var b = parseInt(input[1]);
console.log(a + b);
console.log(a - b);
console.log(a * b);
console.log(Math.floor(a / b));
console.log(a % b);

// todo 나누기에서 몫을 구하기 위해서는 소수점을 없애주어야 함
