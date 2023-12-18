# API-PHP-C
Un exemple d'API simple qui utilise C en backend et PHP pour le frontend
## Organisation du projet  
* Le fichier api est généré depuis main.c et contient l'ensemble de la logique côté serveur. (pour le générer : clang main.c -o api)
* le fichier csv.txt comporte les données. Vu la petite taille du projet j'ai voulu essayer de manipuler un simple csv plutôt qu'une base en SQL.
* le fichier index.php contient la page web, qui est accessible par le client.
## Utilisation
* Cloner les fichiers sur un serveur web, à l'arboresence.
* Accéder à la page index.php.
* Entrer une commande dans le champ et appuyer sur Envoyer.
* La page se recharge avec les informations reçues.
## Commandes
* read : prend en paramètre 1 entier. Affiche le nom et le prénom de l'élève associé.
* readall : affiche tous les élèves de la classe.
* create : prend en paramètre un prénom et un nom. Ajoute un nouvel élève.
