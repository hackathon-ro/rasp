<?php
$adresa_db = "localhost:3306";
$utilizator_db = "root";
$parola_db = "hackathon";
$db = mysql_connect($adresa_db, $utilizator_db, $parola_db) or die("Database unavailable!");
mysql_select_db("hackathon", $db);

$temp=" SELECT a.speed AS speed, a.UTC AS UTC, l.lat AS lat, l.lon AS lon
		FROM anemometru a, location l
		WHERE a.location_id=l.id
		ORDER BY a.utc DESC
		LIMIT 20";
		$query = mysql_query($temp);
		if (!$query) {
			$message  = 'Database error. Please try again.';
			die($message);
			exit;
		}
echo "<TABLE><TR><B><TD>Speed</TD><TD>Location</TD><TD>UTC</TD></B></TR>";	
while ($row = mysql_fetch_assoc($query)) 
	{
		echo "<TR><TD>$row[speed]</TD><TD>$row[lat] $row[lon]</TD><TD>$row[UTC]</TD></TR>";	
	}
echo "</TABLE>";	

mysql_free_result($query);

?>