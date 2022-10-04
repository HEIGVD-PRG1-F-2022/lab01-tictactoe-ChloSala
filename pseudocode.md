# TicTacToe Pseudocode

# Pseudocode trouver le gagnant
## Entrées
- table: list de 9 valeurs (0;1)

## Sorties
- gagnant: le gagnant de la partie (1, 2, 3)

## Algorithmes
1. constante `solutions`: Tableau des 8 solutions (1 solution contient les 2 numéros des cases gagnantes d'une combinaison)
1. Pour chaque `solution` dans `solutions`
1. `nbr_match` = 0
   1. Pour i = 1 à 3
      1. SI `table` à l'index donné dans `solution` à l'index `i`, égal à 0
         1. `nbr_match` = `nbr_match` + 1
   1. SI `nbr_match` est égal à 3
      1. `gagnant` est 0
   1. SINON SI `nbr_match` est égal à 0
      1. `gagnant` est 1
1. Afficher `gagnant`

# Pseudocode TicTacToe
## Entrées
- `coord`: coordonnée (1 à 9) d'une case à marquer pour le joueur actuel

## Sorties
- gagnant: le gagnant de la partie (1, 2, 3)

## Algorithmes
1. Définir `table` comme vide
1. `iteration` = 0
1. Tant qu'il n'y a pas de gagnant (pseudocode "trouver le gagnant")
   1. incrémenter l'`iteration` 
   1. Afficher la grille
   1. Afficher "Player"
   1. SI `iteration` est pair
      1. Afficher "1: "
   1. SINON
      1. Afficher "2: "
   1. Faire
      1. Prendre la valeur donnée par le joueur 1 et stocker dans `coord`
      1. Si `coord` > 9 ou < 1 :
         1. Afficher une erreur de case invalide.
      1. SINON SI
         1. Table à l'index coord - 1 n'est pas égal à zéro:
            1. Afficher une erreur de case déjà prise
   1. Tant que la valeur n'est pas entre 1 et 9 inclus OU que `table` à l'index `coord - 1` n'est pas 0
   1. `coord` = `coord` - 1 (pour passer de 1 à 9, à 0 à 8)
   1. SI `iteration` est pair
      1. Changer `table` à l'index `coord` à 1
   1. SINON
      1. Changer `table` à l'index `coord` à 2
   