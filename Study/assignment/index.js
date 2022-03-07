let product = document.querySelector(".product");
const expand_header = document.querySelector("header");
const header_bottom = document.getElementById("expand_header");

expand_header.addEventListener("mouseover", () => {
  header_bottom.classList.toggle("show");
});
