/**
 * 
 */

var rnum = Math.floor(Math.random()*10)+1;
var cnt = 1;


function checkEnter(){
	
	if(window.event.keyCode == 13){
		correctNum();
	}
}


function correctNum(){
	var userNum = document.getElementById("guessNum").value;
	console.log(rnum);
	if(rnum == userNum){
		alert("정답~" + cnt +"회만에 맞췄네요~");
		rnum = Math.floor(Math.random()*10)+1;
		cnt = 1;
	}
	else{
		alert("오답~!");
		cnt++;
	}
}