const express = require("express");
const http = require("http");
const https = require("https");
const app = express();

// 경로 정의
app.get("/", function (req, res) {
  res.send("Hello World");
});

//  포트 번호 3000번이 반환되어 서버가 실행되고
app.listen(3000, function () {
  //  연결 확인 콘솔이 콜백됨
  console.log("Example app listening on port 3000!");
});

http.createServer(app).listen(80, () => {
  console.log("Example app listening on port 3000!");
});

// https.createServer(app).listen(443, () => {
//   console.log("Example app listening on port 3000!");
// });
