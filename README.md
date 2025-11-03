# cube3d

Projet "cube3d" — petit moteur 3D/raycasting développé par Polo et Antoine.

## Description

Ce dépôt contient le travail sur un projet de rendu 3D simple. L'objectif est d'avoir un parser
qui lit des fichiers de définition de niveau (ex : `map.cub`) puis un exécutable qui charge les données
parsées et lance le rendu/jeu.

## Rôles

- Paul : parsing — développement et tests du parser (conversion des fichiers source en format consommable).
- Antoine : exécution — intégration et lancement du moteur/jeu à partir des données parsées.

## TODO (parsing)

Liste minimaliste des tâches à faire pour la partie parsing :

- Parser les identifiants obligatoires : `NO`, `SO`, `WE`, `EA`, `F`, `C` (vérifier doublons/absents).
- Vérifier l'existence des fichiers de textures fournis (paths valides).
- Lire la map (tout ce qui suit les identifiants) en conservant les espaces et les longueurs de ligne.
- Valider les caractères de la map (`0`, `1`, `N`, `S`, `E`, `W`, et espace).
- S'assurer qu'il n'y a qu'une position de joueur (N/S/E/W) et récupérer sa position + orientation.
- Vérifier que la map est fermée (pas de fuite vers l'extérieur) — méthode recommandée : contrôles locaux + floodfill si nécessaire.
- Produire des messages d'erreur clairs en affichant `Error\n` suivi d'un message explicite.
- Écrire des exemples `.cub` de tests (valide / invalide) dans `examples/`.

Checklist rapide :

- [ ] Identifiants parsés
- [ ] Map lue et stockée (tableau de lignes)
- [ ] Validation (caractères, joueur unique)
- [ ] Vérification fermeture map
- [ ] Tests `.cub` créés

