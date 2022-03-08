// 예제 입력 1
// 1 2
// 예제 출력 1
// 3

// 터미널 상에서 입출력을 받아서 출력하는 것

// 두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램
// 첫째 줄에 A와 B가 주어짐 (0 < A, B < 10)

var fs = require("fs");
var input = fs.readFileSync("/dev/stdin").toString().split(" ");
var a = parseInt(input[0]);
var b = parseInt(input[1]);
console.log(a + b);
