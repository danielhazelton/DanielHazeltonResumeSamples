//Start-up functions run when page is loaded.
//1. Include the HTML snippets:
//includeHTML();

//Hide all pages except for Activity Feed, which is the start page.
document.getElementById("schoolInfoDiv").style.display = "none";
document.getElementById("funInfoDiv").style.display = "none";

document.getElementById("hobbiesModeDiv").style.display = "none";
document.getElementById("chillDiv").style.display = "none";
document.getElementById("outdoorDiv").style.display = "none";

document.getElementById("familyModeDiv").style.display = "none";
document.getElementById("parentsDiv").style.display = "none";
document.getElementById("brotherDiv").style.display = "none";






//2. Set up UI state
var menuOpen = false; //Boolean variable to capture the state of the side menu.


//Associative array maps modes to page titles
var modeToTitle = {"aboutMode": "Activity Feed",
                   "hobbiesMode": "My Hobbies",
                   "familyMode": "My Family"};

//On startup, set current app mode to "aboutMode"
var mode = "aboutMode"; //Variable captures current UI mode
var page = "aboutModeDiv";//keeps track of current page

//Bind bottomBarBtnClick function to all elements of class bottomBarBtn
var bottomBtns = document.getElementsByClassName("bottomBarBtn");
for (var i = 0; i < bottomBtns.length; ++i) {
    bottomBtns[i].addEventListener("click",bottomBarBtnClick);
}

//Bind menuItemBtnClick function to all elements of class menuItem
var menuItemBtns = document.getElementsByClassName("menuItem");
for (var i = 0; i < menuItemBtns.length; ++i) {
    menuItemBtns[i].addEventListener("click",menuItemBtnClick);
}

document.getElementById(mode).classList.add("menuItemSelected");

//Change title bar to Activity Feed
document.getElementById("topBarTitle").textContent = "About";
//Show only the feed mode menu items
var menuItems = document.getElementsByClassName("menuItem");
for (var i = 0; i < menuItems.length; ++i) {
  menuItems[i].style.display = "none";
}
var feedItems = document.getElementsByClassName("aboutModeItem");
for (var i = 0; i < feedItems.length; ++i) {
  feedItems[i].style.display = "block";
}
document.getElementById("aboutModeDiv").style.display = "block";


