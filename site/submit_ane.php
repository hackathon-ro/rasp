<?php

if (!isset($_GET['spd']))
{echo "NOK!";
exit;}

$adresa_db = "localhost:3306";
$utilizator_db = "root";
$parola_db = "hackathon";
$db = mysql_connect($adresa_db, $utilizator_db, $parola_db) or die("Database unavailable!");
mysql_select_db("hackathon", $db);

$temp="INSERT anemometru
			SET speed=\"$_GET[spd]\", location_id=(SELECT id FROM location ORDER BY id DESC LIMIT 1);";
		
		$query = mysql_query($temp);
		if (!$query) {
			$message  = 'Database error. Please try again.';
			die($message);
			exit;
		}

echo "OK";

?>