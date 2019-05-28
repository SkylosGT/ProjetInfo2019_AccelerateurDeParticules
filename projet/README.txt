/*README*/

Réponses au questions:

	1.ExerciceP14 Meilleurs voisins: 
	La simulation entière de l'accélérateur en version text et graphique + extension Maille FODO

	2.Version graphique fonctionnelle bibliothèque Qt version minimale // Qt 5.12.2 // compilateur: MinGW et MSVC 2017

	3.Nous avons passé 3 heures en moyenne par personne par semaine.


Le rendu est composé de 3 versions de l'accélérateur de particules, la version finale du projet est ##Update v1.0 :

	Version finale:
	Update v1.0 -- Cette version du projet est la version définitive du rendu et comporte
		*Moteur de simulation final avec intéraction des particules et segmentation de l'espace en cases
		*Moteur graphique final avec affichage de l'accélérateur et des faisceaux
		*Tests des classes qui composent le projet

		Compile: ExerciceP14, main_qt_gl, testVecteur, testParticule
		Obsolète: testAccel1 		

	Version finale bis:
	Update v1.0-bis -- Cette version du projet est la version finale du projet sans l'affichage graphique Qt et comporte
		*Moteur de simulation final avec intéractions des particules
		*Test des classes qui composent le projet

		Compile: ExerciceP14, testVecteur, testParticule
		Obsolète: testAccel1 

	Version ancienne:
	Update v0.2-beta -- Cette version du projet date du 17.04.2019 et comporte:
		*Adaptation de l'affichage à différents supports
		*Moteur de simulation et première simulation
		*Tests des classes qui composent le projet

		Compile: ExerciceP9, ExerciceP10, testVecteur, testParticule, testAccel1
		Obsolète: -

Build & Launch:
	Update v1.0 -- Les makefiles sont générés différement en fonction des version de Qt et des compilateurs 
		       ainsi pour éviter des erreurs:
		
		Qt Creators:
			I. Ouvrir programme.pro et executer qmake
			II. Build
			III. Launch l'executable désiré depuis l'interface

		Console:
			I. qmake all
			II. make all
			III. launch l'executable désiré
 
	Update v1.0-bis -- 

		Console:
			I. make
			II. launch l'executable désiré

	Update v0.2-beta -- 

		Console:
			I. make
			II. launch l'executable désiré

		
