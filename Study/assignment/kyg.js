// element의 애니메이션 속성의 transform left값 랜덤

let star_animation = document.querySelectorAll(".star");
// ReferenceError: document is not defined
// ? CSR과 SSR의 동작원리에 대한 차이로 인한 현상
// x값만 다르게 -50 ~ 0 랜덤
// console.log(star_animation);
// if (-50 > Math.floor(Math.random() * 100)) {
// }

// if (random_X < -50) {
//   console.log(random_X);
// } else {
// }

// function shooting_star() {
//   random_value();
// }

// shooting_star();

// * 랜덤으로 값 추출
function random_value(ratio) {
  let coordinate = Math.floor(Math.random() * ratio);
  return coordinate;
}

function value_inspect(n) {
  // * 조건할 숫자 값 대입
  check_value = random_value(n);

  // if (check_value > -100 || check_value === undefined) {
  //   check_value = random_value(n);
  // } else return check_value;
  // for (check_value = false; check_value > -100; check_value = true) {
  //   if (check_value > -100 || check_value === undefined) {
  //     check_value = false;
  //   } else check_value = true;
  // }
  // return check_value;

  do {
    // * 값이 -100보다 크거나 undefined일 때
    if (-100 < check_value || check_value === undefined) {
      check_value = undefined;
      check_value = random_value(n);
    } else if (check_value < -100 || check_value !== undefined) {
      check_value == true;
    } else if (check_value > 0) {
      return 0;
    }
    // * -100보다 작을때까지 반복
  } while (check_value > -100);
  console.log(check_value);
  return check_value;
}
// todo 위의 방법으로는 별똥별 element가 보여지는 공간 외에 차지하는 공간이 생겨서 흰색 빈칸들이 생김

// todo 시간에 따른 좌표값 변화
let time = new Date();
let hour = time.getHours();
let min = time.getMinutes();
let sec = time.getSeconds();
let msec = time.getMilliseconds();
console.log(hour);
let morning;
let afternoon;
let evening;
let night;
let dawn;

// todo 시간에 따른 랜덤 값 추출
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
time_radom_value();

function shooting_star() {
  let star_array = document.querySelectorAll(".star");
  star_array.forEach((element) => {
    element.animate(
      [
        {
          transform: `translate(${value_inspect(
            -300
          )}vw,100vh) rotate(-35deg) scale(1)`,
          // transform: `translate(${-msec / 3}vw,100vh) rotate(-35deg)`,
        },
      ],
      {
        duration: random_value(20000),
        iterations: Infinity,
      }
    );
  });
}

shooting_star();
// star_moving();
