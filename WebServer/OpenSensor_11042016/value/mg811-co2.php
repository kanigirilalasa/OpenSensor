<?php
	include('../connection.php');

	$result = mysqli_query($conn, "SELECT TIME, GAS, VALUE, UNIT FROM sensorvalue WHERE SENSORMODEL = 'MG811' ORDER BY TIME DESC LIMIT 1");
	if($result->num_rows > 0){
		while($row = mysqli_fetch_array($result)){
			echo "<td>".$row['TIME']."</td>".
				    "<td>".$row['GAS']."</td>".
				    "<td>".$row['VALUE']."</td>".
				    "<td>".$row['UNIT']."</td>";
		}
	}
?>