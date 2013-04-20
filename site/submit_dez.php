<?php

if (!isset($_GET['dez']))
{echo "NOK!";
exit;}

$adresa_db = "localhost:3306";
$utilizator_db = "root";
$parola_db = "hackathon";
$db = mysql_connect($adresa_db, $utilizator_db, $parola_db) or die("Database unavailable!");
mysql_select_db("hackathon", $db);

$temp="INSERT dez
			SET dez=\"$_GET[dez]\", resolution=\"$_GET[res]\";";
		
		$query = mysql_query($temp);
		if (!$query) {
			$message  = 'Database error. Please try again.';
			die($message);
			exit;
		}

echo "OK";

?>