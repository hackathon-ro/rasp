<?php
$adresa_db = "localhost:3306";
$utilizator_db = "root";
$parola_db = "hackathon";
$db = mysql_connect($adresa_db, $utilizator_db, $parola_db) or die("Database unavailable!");
mysql_select_db("hackathon", $db);

$temp=" SELECT l.lat, l.lon, l.id
		FROM location l
		ORDER BY utc DESC
		LIMIT 1";
		$query = mysql_query($temp);
		if (!$query) {
			$message  = 'Database error. Please try again.';
			die($message);
			exit;
		}
while ($row = mysql_fetch_assoc($query)) 
	{
		$lat=$row["lat"];
		$lon=$row["lon"];	
		$id=$row["id"];
	}
mysql_free_result($query);

$temp=" SELECT a.UTC, a.speed
		FROM anemometru a
		WHERE a.location_id=$id
		ORDER BY a.UTC DESC
		LIMIT 1";
		$query = mysql_query($temp);
		if (!$query) {
			$message  = 'Database error. Please try again.';
			die($message);
			exit;
		}
while ($row = mysql_fetch_assoc($query)) 
	{
		$utc=$row["UTC"];
		$speed=$row["speed"];	
	}
mysql_free_result($query);



$temp=" SELECT d.UTC, sum(d.dez) as dez
		FROM dez d
		WHERE d.location_id=$id 
		AND TIMEDIFF(NOW(),d.UTC) < '00:05:00'
		ORDER BY d.UTC DESC
		LIMIT 1";
		$query = mysql_query($temp);
		if (!$query) {
			$message  = 'Database error. Please try again.';
			die($message);
			exit;
		}
while ($row = mysql_fetch_assoc($query)) 
	{
		$utcd=$row["UTC"];
		$dez=$row["dez"]/120;	
	}
mysql_free_result($query);

?>



<!DOCTYPE html>
<html>
  <head>
    <meta name="viewport" content="initial-scale=1.0, user-scalable=no">
    <meta charset="utf-8">
    <title>R.A.S.P.</title>
    <link href="https://developers.google.com/maps/documentation/javascript/examples/default.css" rel="stylesheet">
    <script src="https://maps.googleapis.com/maps/api/js?v=3.exp&sensor=false"></script>
    <script>
function initialize() {
  var myLatlng = new google.maps.LatLng(<?echo "$lat,$lon";?>);
  var mapOptions = {
    zoom: 15,
    center: myLatlng,
    mapTypeId: google.maps.MapTypeId.ROADMAP
  }

  var map = new google.maps.Map(document.getElementById('map-canvas'), mapOptions);

  var contentString = '<div id="content">'+
      '<div id="siteNotice">'+
      '</div>'+
     <?// '<h1 id="firstHeading" class="firstHeading">Location information</h1>'+?>
      '<div id="bodyContent">'+
      '<p>Wind speed at <?echo "$utc";?> was <?echo "$speed";?>m/s<BR>'+
	  'Radiation level at <?echo "$utcd";?> was <?echo "$dez";?>uSv/hr</p>'+
      '</div>'+
      '</div>';
	  		
  var infowindow = new google.maps.InfoWindow({
      content: contentString
  });

  var marker = new google.maps.Marker({
      position: myLatlng,
      map: map,
      title: 'Hackathon'
  });
  google.maps.event.addListener(marker, 'click', function() {
    infowindow.open(map,marker);
  });
}

google.maps.event.addDomListener(window, 'load', initialize);

    </script>
  </head>
  <body>
    <div id="map-canvas"></div>
  </body>
</html>


