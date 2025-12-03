# README.md — Singly Linked Lists (C)

````text
# Singly Linked Lists - Projet C

## Description
Ce dépôt contient des fonctions utilitaires pour manipuler des listes chaînées simplement liées (singly linked lists) en C, conformément aux consignes fournies.

## Table des matières

- Description
- Quand et pourquoi utiliser une liste chaînée plutôt qu'un tableau
- Comment construire et utiliser ces listes
- Exemples d'utilisation
- Requirements
- Plus d'infos (structure)
- Contribuer
- Licence

---

## Quand et pourquoi utiliser une liste chaînée plutôt qu'un tableau

Les listes chaînées et les tableaux conviennent à des usages différents. Voici un résumé des points à considérer :

- **Insertion / suppression fréquentes**
  - *Liste chaînée* : insertion/suppression en O(1) si l'on connaît le nœud précédent (ou en O(1) en tête). Idéale quand l'ordre change souvent.
  - *Tableau* : insertion/suppression coûteuse (O(n)) car il faut déplacer les éléments.

- **Accès aléatoire (indexation)**
  - *Liste chaînée* : accès en O(n) — il faut parcourir la liste jusqu'à la position désirée.
  - *Tableau* : accès en O(1) via l'indice.

- **Utilisation mémoire / taille dynamique**
  - *Liste chaînée* : allocation dynamique par nœud — flexible, adaptée si la taille n'est pas connue à l'avance.
  - *Tableau* : mémoire contiguë — plus efficace pour la localité de cache, mais nécessite une redéallocation si la taille change.

- **Simplicité**
  - *Tableau* : souvent plus simple et performant pour des données de taille fixe ou quand on veut un accès rapide par indice.
  - *Liste chaînée* : utile pour files d'attente, piles, ou structures où les opérations d'insertion/suppression prédominent.

**Conclusion** : Choisissez une liste chaînée quand vous avez besoin d'une structure de données dynamique avec beaucoup d'insertions/suppressions ; choisissez un tableau pour accès rapide par index et meilleures performances mémoire/cpu quand la taille est connue ou stable.

---

## Comment construire et utiliser ces listes

### Nœud (node)
Chaque élément de la liste est un nœud contenant une chaîne `str`, sa longueur `len`, et un pointeur `next` vers le nœud suivant.

### Opérations courantes
Implémentez (exemples de signatures) :

```c
/* prototypes à mettre dans lists.h */
list_t *add_node(list_t **head, const char *str);
list_t *add_node_end(list_t **head, const char *str);
size_t print_list(const list_t *h);
void free_list(list_t *head);
```

**Description rapide** :
- `add_node` : ajoute un nouveau nœud en tête de liste (crée/duplique `str`).
- `add_node_end` : ajoute un nœud en fin de liste.
- `print_list` : parcourt la liste et affiche (via `_putchar` ou la fonction fournie) les éléments — attention : les fonctions de la stdlib autres que `malloc`, `free`, `exit` sont interdites.
- `free_list` : libère chaque nœud et la chaîne associée.

### Bonnes pratiques
- Ne pas utiliser de variables globales.
- Respecter la limite : maximum 5 fonctions par fichier source.
- Tous les prototypes (y compris `_putchar`) doivent être dans `lists.h`.
- Protéger les headers avec des include guards.
- Gérer correctement les allocations (vérifier `malloc` et libérer proprement pour éviter les fuites).

---

## Exemples d'utilisation

> *Remarque* : les `main.c` fournis ici sont à titre d'exemple seulement. Le correcteur compilera avec ses propres `main.c`.

```c
/* exemple d'utilisation */
#include "lists.h"

int main(void)
{
    list_t *head = NULL;

    add_node(&head, "Hello");
    add_node_end(&head, "World");
    print_list(head);
    free_list(head);
    return (0);
}
```

---

## Requirements

- **Allowed editors**: `vi`, `vim`, `emacs`
- **Compilation**: Ubuntu 20.04 LTS, `gcc` avec les options :
  ```
  -Wall -Werror -Wextra -pedantic -std=gnu89
  ```
- **Fichiers** : tous les fichiers doivent se terminer par une nouvelle ligne.
- **README.md** : obligatoire, à la racine du projet.
- **Style** : respecter la *Betty style* (vérifié par `betty-style.pl` et `betty-doc.pl`).
- **Variables globales** : interdites.
- **Nombre de fonctions** : pas plus de 5 fonctions par fichier source.
- **Fonctions autorisées** : seules `malloc`, `free` et `exit` de la bibliothèque standard sont autorisées.
  - L'utilisation de `printf`, `puts`, `calloc`, `realloc`, etc. est interdite.
- **Autorisé** : l'utilisation de `_putchar` est permise.
  - *Ne pas pousser `_putchar.c`* — le correcteur utilisera son propre fichier pour `_putchar`.
- **Fichiers main** : vous pouvez pousser des `main.c` pour vos tests, mais ils ne seront pas pris en compte par le correcteur.
- **Header** : `lists.h` doit contenir les prototypes de toutes les fonctions et être inclus dans le projet.
- **Include guards** : obligatoires pour tous les headers.

---

## Plus d'infos (structure)

Utilisez la structure de nœud suivante :

```c
/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct list_s
{
    char *str;
    unsigned int len;
    struct list_s *next;
} list_t;
```

Mettez cette définition et les prototypes associés dans `lists.h`.

---

## Contribuer

- Respectez les règles de style et les restrictions indiquées ci-dessus.
- Ouvrez une issue ou proposez une pull request si vous voulez améliorer les exemples ou ajouter des tests.

---

## Licence

Ce dépôt est fourni à titre d'exemple. Ajoutez une licence (par ex. MIT) si vous prévoyez une réutilisation publique.

---

*README généré automatiquement — modifiez-le si vous souhaitez adapter le texte ou ajouter des sections spécifiques au projet.*
````

## Fichier prêt à pousser (instructions Git)

Copie-colle les commandes suivantes dans ton terminal (à partir du dossier du projet) :

```bash
# initialiser un dépôt git si nécessaire
git init

# ajouter tous les fichiers
git add README.md lists.h *.c

# valider
git commit -m "Add README and linked-list project files"

# ajouter remote (remplace <url> par l'URL de ton dépôt distant)
git remote add origin <url>

# pousser sur la branche principale
git push -u origin main
```
