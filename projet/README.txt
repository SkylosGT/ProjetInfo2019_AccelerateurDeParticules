/*README*/

R�ponses au questions:

	1.ExerciceP14 Meilleurs voisins: 
	La simulation enti�re de l'acc�l�rateur en version text et graphique + extension Maille FODO

	2.Version graphique fonctionnelle biblioth�que Qt version minimale // Qt 5.12.2 // compilateur: MinGW et MSVC 2017

	3.Nous avons pass� 3 heures en moyenne par personne par semaine.


Le rendu est compos� de 3 versions de l'acc�l�rateur de particules, la version finale du projet est ##Update v1.0 :

	Version finale:
	Update v1.0 -- Cette version du projet est la version d�finitive du rendu et comporte
		*Moteur de simulation final avec int�raction des particules et segmentation de l'espace en cases
		*Moteur graphique final avec affichage de l'acc�l�rateur et des faisceaux
		*Tests des classes qui composent le projet

		Compile: ExerciceP14, main_qt_gl, testVecteur, testParticule
		Obsol�te: testAccel1 		

	Version finale bis:
	Update v1.0-bis -- Cette version du projet est la version finale du projet sans l'affichage graphique Qt et comporte
		*Moteur de simulation final avec int�ractions des particules
		*Test des classes qui composent le projet

		Compile: ExerciceP14, testVecteur, testParticule
		Obsol�te: testAccel1 

	Version ancienne:
	Update v0.2-beta -- Cette version du projet date du 17.04.2019 et comporte:
		*Adaptation de l'affichage � diff�rents supports
		*Moteur de simulation et premi�re simulation
		*Tests des classes qui composent le projet

		Compile: ExerciceP9, ExerciceP10, testVecteur, testParticule, testAccel1
		Obsol�te: -

Build & Launch:
	Update v1.0 -- Les makefiles sont g�n�r�s diff�rement en fonction des version de Qt et des compilateurs 
		       ainsi pour �viter des erreurs:
		
		Qt Creators:
			I. Ouvrir programme.pro et executer qmake
			II. Build
			III. Launch l'executable d�sir� depuis l'interface

		Console:
			I. qmake all
			II. make all
			III. launch l'executable d�sir�
 
	Update v1.0-bis -- 

		Console:
			I. make
			II. launch l'executable d�sir�

	Update v0.2-beta -- 

		Console:
			I. make
			II. launch l'executable d�sir�

		
