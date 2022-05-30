# decodage-huffman
Projet étudiant de décompression de données par décodage de Huffman.

## Compilation

Le projet est compilé à l'aide de CMake.
Pour générer les fichiers cmake il est préférable de créer un nouveau dossier pour accueillir les fichiers générés par
CMake.

```
mkdir build-huffman
cd build-huffman
cmake ../CMakeLists.txt
```

On peut ensuite compiler le projet.
```
cmake --build .
```

## Exécution du programme

Pour lancer le programme il faut appeler `decodage_huffman` avec en argument les chemins vers les fichiers de fréquence et binaire.

Exemple :

```
./decodage_huffman ../texts/textesimple_freq.txt ../texts/textesimple_comp.bin
```

## Convention de nommage des branches

Ajout de fonctionnalité :

feature-XXXXXXX

Refactorisation du code :

rework-XXXXXXX


Résolution de bugs ou de problèmes :

fix-XXXXXXX

Annulation de modifications :

rollback-XXXXXXX
