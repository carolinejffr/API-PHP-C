<!DOCTYPE HTML>
<html>
<head>
	<link rel="stylesheet" href="style.css">
</head>
<header>
	<h1>TP API - Caroline Jaffré</h1>
	<a href="https://github.com/carolinejffr/API-PHP-C">Voir sur Github</a>
</header>
<body>
	<form method="post">
		<label for="commande">Entrez ici la commande à exécuter ou help pour la liste des commandes :</label><br />
		<input type="text" id="commande" name="commande">
		<input type="submit" value="Envoyer">
	</form>
	<br />
<?php	
if (isset($_POST["commande"]))
{
	$exec = './api ' . $_POST['commande'];
	exec($exec, $output);
	for ($i = 0; $i < count($output); $i++)
	{
		echo $output[$i];
		echo('<br />');
	}
}
?>
</body>
</html>
