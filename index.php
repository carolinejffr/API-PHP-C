<!DOCTYPE HTML>
<html>
<body>
	<form method="post">
		<label for="commande">Entrez ici la commande à exécuter ou help pour la liste des commandes :</label><br />
		<input type="text" id="commande" name="commande">
		<input type="submit" value="Envoyer">
	</form>
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
