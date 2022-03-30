$("document").ready(function () {
  var trigger = $("#menu-icon"),
    isClosed = true;
  var footer = $("#footer");
  var side_menu = $("#side-menu");
  var main = $("main");
  trigger.click(() => {
    menuTime();
    displayToggle();
  });

  function menuTime() {
    if (isClosed == true) {
      trigger.removeClass("is-open");
      trigger.addClass("is-closed");
      isClosed = false;
    } else {
      trigger.removeClass("is-closed");
      trigger.addClass("is-open");
      isClosed = true;
    }
  }

  function displayToggle() {
    if (isClosed == true) {
      main.hide();
      side_menu.show();
      footer.hide();
    } else {
      main.show();
      side_menu.hide();
      footer.show();
    }
  }
});

$("#scrollTop").click(() => {
  
});
