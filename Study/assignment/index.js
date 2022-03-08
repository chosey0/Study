const introduce = document.getElementById("introduce");

function supportTemplate() {
  return "content" in document.createElement("template");
}
if (supportTemplate()) {
  console.log("Good to go");
  // 템플릿이 들어갈 element
  var main_cont = document.getElementById("main");

  // 렌더링 할 템플릿
  var intro_temp = document.getElementById("content_template");
  var clone = document.importNode(intro_temp.content, true);
  main.appendChild(clone);
  console.log("add template");
} else {
  console.log("use old templating techniques or libraries.");
}

// 메뉴에 따라 다른 템플릿 보여주기
