// * 랜덤으로 값 추출
// todo 시간에 따른 좌표값 변화
let time = new Date();
let hour = time.getHours();
let min = time.getMinutes();
let sec = time.getSeconds();
let msec = time.getMilliseconds();
let morning;
let afternoon;
let evening;
let night;
let dawn;

function rand(min, max) {
  let value = Math.floor(Math.random() * (max - min + 1)) + min;

  return value;
}
let coordinate;
let speed;
function shooting_star(min_speed, max_speed, min_coord, max_coord) {
  let star_array = document.querySelectorAll(".star");
  star_array.forEach((element) => {
    coordinate = rand(min_coord, max_coord);
    speed = rand(min_speed, max_speed);
    element.setAttribute("style", `right:${rand(0, 80)}`);
    element.animate(
      [
        {
          transform: `translate(${coordinate}vw,85vh) rotate(-35deg) scale(.5)`,
        },
      ],
      {
        duration: speed,
      }
    );
    console.log(coordinate);
    console.log(speed);
  });
}
setInterval(() => {
  shooting_star(2000, 3000, -100, -10);
}, rand(2000, 2500));

function time_radom_value() {
  let time = new Date();
  let hour = time.getHours();
  let min = time.getMinutes();
  let sec = time.getSeconds();
  let msec = time.getMilliseconds();
  let coordinate = msec * Math.floor(Math.random() * 5);
  console.log(coordinate);
  console.log(-msec / 3);
}
