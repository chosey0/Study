let item = document.querySelectorAll(".autoplay-item");

let translateValue = 0;
// item.forEach((element, i) => {
//   console.log(item[i]);
//   setInterval(() => {
//     translateValue -= 100;
//     item[i].setAttribute("style", `transform:translateX(${translateValue}%)`);
//     translateValue = -100;
//   }, 2000);
// });

for (i = 0; i < 3; i++) {}

// setInterval(() => {
//   if (translateValue == 200) translateValue = 100;
//   else translateValue -= 100;
//   i = 0;
//   item
//     .item(i)
//     .setAttribute("style", `transform:translateX(${translateValue}%)`);
//   if (translateValue == -300) {
//     translateValue += 500;
//     item
//       .item(i)
//       .setAttribute(
//         "style",
//         `transform:translateX(${translateValue}%); display:hidden; transition:0;`
//       );
//   }
// }, 2000);
function valueFunc() {
  setInterval(() => {
    translateValue -= 100;
  }, 2000);
}
valueFunc();
item.forEach((element, index) => {
  setInterval(() => {
    if (translateValue == -500) translateValue = 0;
    translateValue;
    element.setAttribute("style", `transform:translateX(${translateValue}%)`);
  }, 2000);
});

slickAutoplay();

function slickAutoplay() {
  item[0];
}

function slickDrag() {}

function slickBtn() {}
