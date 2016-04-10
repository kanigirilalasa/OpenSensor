<!DOCTYPE html>
<html>
<head>
	<title></title>
	<link rel="stylesheet" href="css/css/bootstrap.min.css">
	
</head>
<body>

<!-- <div class="container">
	<div class="row" style="background-color: #f1f1f1">
		<h2 style="font-family:'Roboto Condensed', sans-serif; text-align:center" id="title">HỆ THỐNG QUẢN LÝ DỮ LIỆU TRẮC QUAN CẢM BIẾN KHÔNG KHÍ</h2>
	</div>
	<br>

	<div class="row">
		<img class="img-rounded" alt="Responsive image" src="images/pollution-banner1.jpg" width="100%" height="200px">
	</div>

	<div class="row">

		<ul><li><h3><i>Dữ liệu trắc quan của cảm biến MQ2</i></h3></li></ul>
	</div>

</div> -->
<!-- <br> -->
<div class="container">
<div class="row">
<div id="divTableDataHolder">
<!-- table-hover table-bordered table-striped -->
	<table class="table table-hover table-bordered table-striped"> 
			  		<tr>
			  			<th>Thời điểm</th>
			  			<th>Nồng độ</th>
			  			<th>Giá trị</th>
			  			<th>Đơn vị đo</th>
			  		</tr>
	<?php
	include('connection.php');
	$result = mysqli_query($conn, "SELECT TIME, GAS, VALUE, UNIT FROM SENSORVALUE WHERE SENSORMODEL='MQ2' ORDER BY TIME DESC");

	// echo "<table>
	// 	<tr>
	// 		<th>Thời điểm</th>
	// 		<th>Nồng độ</th>
	// 		<th>Giá trị</th>
	// 		<th>Đơn vị đo</th>
	// 	</tr>";

	while($row = mysqli_fetch_array($result))
	{
		$output = "<tr>
			<td>".$row['TIME']."</td>
			<td>".$row['GAS']."</td>
			<td>".$row['VALUE']."</td>
			<td>".$row['UNIT']."</td>
		</tr>";

		echo $output;
	}

	
?>
</table>
</div>
<button id="excel" onclick="myFunction()">Export Table data into Excel</button>
</div>
</div>
</body>
</html>

<script type="text/javascript" src="js/jquery-1.12.2.min.js"></script>
<script type="text/javascript">
function myFunction(){
}
// $(document).ready(function(){
// 	$("#excel").click(function(){
// 		// <?php
// 		//  header("Content-Type: application/xls");   
//   //          header("Content-Disposition: attachment; filename=download.xls");  
//   //          echo $output;
// 		// ?>
// 		aleart
// 	});
// });
</script>