/**
 * 
 */


	var n1;
	var n2;
	
	function myFunction() {
		n1 = document.getElementById("num1").value;
		n2 = document.getElementById("num2").value;
		var result = parseInt(n1) + parseInt(n2);
		document.getElementById("sumVal").value = result;
	}