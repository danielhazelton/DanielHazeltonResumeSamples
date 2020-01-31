//
//eventHandlers.js -- This file defines the JavaScript functions necessary to
//update the app in response to user interaction.
//

//document click: When the user clicks anywhere in the doc and the menu is open
//we need to close it and toggle menu state variable.
document.addEventListener("click",function(e) {
  if (menuOpen) {
    document.getElementById("menuBtnIcon").classList.remove("fa-times"); 
    //Change hamburger to X when menu open
    document.getElementById("menuBtnIcon").classList.add("fa-bars");
    document.getElementById("sideMenu").style.width = "0px"; //close menu
    menuOpen = false;
  }
});
 
//menuBtn click: When the top-left side menu button is clicked and the menu
//is closed, we need to open it and toggle menu state variable.
document.getElementById("menuBtn").addEventListener("click",function(e) {
  if (!menuOpen) {
    document.getElementById("menuBtnIcon").classList.remove("fa-bars"); 
    //Change hamburger to X when menu open
    document.getElementById("menuBtnIcon").classList.add("fa-times");
    document.getElementById("sideMenu").style.width = "250px"; //open up menu
    menuOpen = true;
    //toggleInputDisabled(true);
    e.stopPropagation();
  }
});   

//bottomBarBtnClick -- When a button in the bottom bar is clicked, we potentially
//need to toggle the mode.
var bottomBarBtnClick = function() {
if (mode != this.id) {
  var prevMode = mode;
  mode = this.id;
  //Change mode button:
  document.getElementById(prevMode).classList.remove("menuItemSelected");
  this.classList.add("menuItemSelected");
  //Change page title:
  document.getElementById("topBarTitle").textContent = modeToTitle[mode];
  //Change page content
  document.getElementById(prevMode + "Div").style.display = "none";
  document.getElementById(page).style.display = "none";
  document.getElementById(mode + "Div").style.display = "block";
  page = mode + "Div";
  //Change menu items:
  var oldItems = document.getElementsByClassName(prevMode + "Item");
  var newItems = document.getElementsByClassName(mode + "Item");
  //Uses for loop:
  for (var i = 0; i < oldItems.length; ++i) {
    oldItems[i].style.display = "none";
  }
  for (var i = 0; i < newItems.length; ++i) {
    newItems[i].style.display = "block";
  }
}
}

//menuItemBtnClick -- When a button in the menu bar is clicked
var menuItemBtnClick = function() {
if ("main" == this.id) {
  var prevpage = page;
  page = mode + "Div";
  document.getElementById(prevpage).style.display = "none";
  document.getElementById(page).style.display = "block";
  
}
else{
  var prevpage = page;
  page = this.id + "Div";
  document.getElementById(prevpage).style.display = "none";
  document.getElementById(page).style.display = "block";
}
}






                                                       



   