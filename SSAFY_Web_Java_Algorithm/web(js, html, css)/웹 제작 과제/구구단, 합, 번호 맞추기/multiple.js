/**
 * 
 */


function multipleFunc(nums){
	
	var table1 = document.getElementById("table1");
	var result = " ";
	for(var num = 2 ; num < 10; num++){
		result += nums + "*" + num + "=" + parseInt(nums)*parseInt(num) + "<br>";
	}
	
	table1.rows[1].cells[0].innerHTML = result;
	table1.rows[0].cells[0].innerHTML = nums+"단";
}