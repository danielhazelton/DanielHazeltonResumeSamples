//Start-up functions run when page is loaded.
//1. Include the HTML snippets:
includeHTML();
//2. Define global vars and function bindings
//Set up UI state
var menuOpen = false; //Boolean variable to capture the state of the side menu.
var mode = "loginMode"; //Variable captures current UI mode

//Associative array maps modes to page titles
var modeToTitle = {
    //TO DO: Fill in
};

//Bind bottomBarBtnClick function to all elements of class bottomBarBtn
var bottomBtns = document.getElementsByClassName("bottomBarBtn");
for (var i = 0; i < bottomBtns.length; ++i) {
    bottomBtns[i].addEventListener("click",bottomBarBtnClick);
}
//Execute function to set start state of app
startUp();