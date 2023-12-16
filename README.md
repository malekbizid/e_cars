E-Cars : Gestionnaire de Location de Voitures
E-Cars est une application de gestion de location de voitures écrite en langage C. Elle permet aux utilisateurs de consulter, de louer des voitures, de gérer les retours et les réclamations dans une agence de location.

Contenu du Projet
main.c: Fichier source contenant le code de l'application.
main.exe: Fichier exécutable prêt à l'emploi pour lancer l'application.
louer_voiture.txt: Fichier de stockage des voitures louées.
Aperçu du Code
Le code est structuré autour de différentes fonctionnalités pour gérer les locations de voitures. Voici quelques points clés :

Structures de Données Utilisées:

struct date: Représente une date avec des champs pour le jour, le mois et l'année.
struct voiture: Contient les détails d'une voiture, tels que le nom du client, l'identifiant client, le modèle, la marque, les dates de location, l'état, etc.
Principales Fonctionnalités Implémentées
Catalogue des Voitures
La fonctionnalité de catalogue des voitures permet aux utilisateurs de visualiser toutes les voitures disponibles à la location au sein de l'agence. Cette fonction affiche les détails essentiels de chaque voiture tels que la marque, le modèle et le coût de location par jour. Les utilisateurs peuvent ainsi parcourir et choisir une voiture qui correspond à leurs besoins avant de procéder à la location.

Location de Voiture
La fonctionnalité de location de voiture permet aux clients de louer une voiture en fournissant des informations spécifiques telles que la marque, le modèle et les dates de location. Avant d'enregistrer la location, le système vérifie la disponibilité de la voiture demandée pour les dates spécifiées. Une fois la voiture réservée, les détails du client et les informations de location sont enregistrés, permettant ainsi une gestion facile et précise des locations en cours.

Retour de Voiture
Cette fonctionnalité est dédiée à la gestion des retours de voiture par les clients. Elle permet aux utilisateurs de signaler la fin de leur période de location en fournissant les détails requis tels que l'identifiant client et les dates de retour. Le système calcule alors le montant final à payer en fonction de la période de location réelle et peut appliquer des frais supplémentaires pour les retours tardifs ou des situations spécifiques.

Réclamations
La fonctionnalité de réclamations permet aux clients de signaler tout problème rencontré avec une voiture louée. Cela peut inclure des problèmes mécaniques, des dommages ou d'autres préoccupations. Les clients peuvent demander un remboursement ou choisir une autre voiture en cas de problème. Cette fonctionnalité vise à garantir la satisfaction du client et à résoudre rapidement toute situation inconfortable rencontrée lors de la location d'une voiture.

Utilisation
Ces fonctionnalités sont accessibles à partir de l'interface en ligne de commande de l'application. Suivez les instructions affichées à chaque étape pour naviguer à travers ces fonctionnalités et effectuer les opérations souhaitées.

Cette expansion détaillée décrit comment chaque fonctionnalité est implémentée dans l'application, mettant en avant leur utilité et leur manière d'être utilisées par les clients pour interagir avec le système de location de voitures.

Pour exécuter l'application :
Exécution Précompilée:

Utilisez le fichier exécutable main.exe pour lancer l'application sur votre terminal.
Suivez les instructions affichées pour louer une voiture, gérer les retours ou faire une réclamation.
Compilation et Exécution Manuelle:

Compilez le fichier source main.c pour générer un exécutable à l'aide d'un compilateur C.
Lancez l'exécutable généré pour accéder aux fonctionnalités de l'application.
Fichiers de Données
louer_voiture.txt : Ce fichier stocke les informations sur les voitures louées. Il est crucial pour la persistance des données entre différentes exécutions du programme.
Installation
Pour utiliser l'application, vous pouvez exécuter le fichier exécutable main.exe fourni. Si nécessaire, compilez le fichier source main.c pour générer un exécutable personnalisé.

Contribution
Si vous souhaitez contribuer à ce projet :

Ouvrez des issues pour signaler des problèmes ou proposer des fonctionnalités.
Soumettez des suggestions ou des améliorations via des pull requests.

