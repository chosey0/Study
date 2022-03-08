// 두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램
// 첫째 줄에 A와 B가 주어짐 (0 < A, B < 10)

// CommonJS modules
const fs = require("fs");

// ES Modules
// import fs from "fs";

// ? fs.readFile(filename, [options], callback)
// * 파일을 option의 방식으로 읽은 후 callback으로 전달된 함수를 호출함 ( 비동기적 )

// ? readFileSync(filename, [options])
// * 파일을 option의 방식으로 읽은 후 문자열을 반환함 ( 동기적 )

// ? toString()
// * 문자열을 반환하는 오브젝트의 대표적 방법

// ? split(separator, limit)
// * String 객체를 separator를 기준으로 여러 개의 문자열로 나눔 / limit : 최대 분할 개수, 초과된 문자열은 반환하지않음

// todo input = fs.동기적으로 파일 읽고.toString 방법으로.문자열을 공백 한칸 기준으로 분할하여 반환;
const input = fs.readFileSync("/dev/stdin").toString().split(" ");

// ? parseInt(string, radix)
var a = parseInt(input[0]);
var b = parseInt(input[1]);
console.log(a + b);

// fs module [Async / Sync]
