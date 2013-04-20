<?php
$adresa_db = "localhost:3306";
$utilizator_db = "root";
$parola_db = "hackathon";
$db = mysql_connect($adresa_db, $utilizator_db, $parola_db) or die("Database unavailable!");
mysql_select_db("hackathon", $db);

$temp=" SELECT *
		FROM dez
		ORDER BY utc DESC
		LIMIT 20";
		$query = mysql_query($temp);
		if (!$query) {
			$message  = 'Database error. Please try again.';
			die($message);
			exit;
		}
echo "<TABLE><TR><B><TD>Geiger</TD><TD>Resolution</TD><TD>UTC</TD></B></TR>";	
while ($row = mysql_fetch_assoc($query)) 
	{
		echo "<TR><TD>$row[dez]</TD><TD>$row[resolution]</TD><TD>$row[UTC]</TD></TR>";	
	}
echo "</TABLE>";	

mysql_free_result($query);

?>