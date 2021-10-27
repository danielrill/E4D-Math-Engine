/*
 *
 * Evo 4D Math Engine
 * E4DVector.h
 * Author	Daniel Rill
 * Date		10.05.2021
 * Version	1.0
 * TODO: Kreuzprodukt und Rotation hinzufügen
 */

#ifndef E4DVECTOR_H
#define E4DVECTOR_H

#include <stdio.h>
#include <cmath>
#include <iostream>
 
namespace E4DEngine {
	class E4DVector {
	
	
	private:
	
	public:
	
		//x, y und z Dim = 3
		float x;
		float y;
		float z;


//#pragma mark-constructors
		//Konstruktoren
		/**
		 * Konstruktor um einen 3D Vektor mit null-Vektor komponenten zu erstellen
		 */
		E4DVector();

		/**
		 * Konstruktor um einen 3D Vektor mit x,y,z komponenten zu erstellen
		 * @param uX x-Komponente
		 * @param uY y-Komponente
		 * @param uZ z-Komponente
		 */
		E4DVector(float uX, float uY, float yZ);

//#pragma mark-destructors
		
		// 3D Vektor Destruktor
		~E4DVector();
		
//#pragma mark-copy constructors

		//Copy-Konstruktoren
		/**
		 * @param ein zu kopierender 3D Vektor 
		 * 
		 * @return WertKopie des Vektors
		 */
		E4DVector(const E4DVector& v);
		/**
		 * @param ein zu kopierender 3D Vektor 
		 * 
		 * @return WertKopie des Vektors
		 */
		E4DVector& operator=(const E4DVector& v);
		
//#pragma mark-add

		// Vektor-Addition
		/**
		 * Addiert zwei Vektoren
		 *
		 * @param v aufzuaddierender 3D Vektor
		 *
		 * @return AdditionsErgebnis zweier Vektoren
		 */
		 void operator+=(const E4DVector& v); 

		/**
		 * Addiert zwei Vektoren
		 *
		 * @param v aufzuaddierender 3D Vektor
		 *
		 * @return ein dritter ErgebnisVektor
		 */
		 E4DVector operator+(const E4DVector& v)const;
		 
//#pragma mark-subtract	

		//Vektor-Subtraktion
		/**
		 * Subtrahiert zwei Vektoren
		 *
		 * @param v zu subtrahierender 3D Vektor
		 *
		 * @return SubtraktionsErgebnis zweier Vektoren
		 */
		 void operator-=(const E4DVector& v);
		/**
		 * Subtrahiert zwei Vektoren
		 *
		 * @param v zu subtrahierender 3D Vektor
		 *
		 * @return ein dritter ErgebisVektor
		 */
		 E4DVector operator-(const E4DVector& v)const;
		 
//#pragma mark-multiply

		//Skalar Multiplikation
		/**
		 * Multipliziert Vektor mit einem Skalar
		 *
		 * @param s Skalar
		 *
		 * @return Produkt der Multiplikation
		 */
		 void operator*=(const float s);

		/**
		 * Multipliziert Vektor mit einem Skalar
		 *
		 * @param s Skalar
		 *
		 * @return Vektor als Ergebnis 
		 */		 
		 E4DVector operator*(const float s)const;

//#pragma mark-division
		// Skalar Division
		/**
		 * Dividiert Vektor mit einem Skalar
		 *
		 * @param s Skalar
		 *
		 * @return Quotient der Division 
		 */	
		void operator/=(const float s);
		/**
		 * Dividiert Vektor mit einem Skalar
		 *
		 * @param s Skalar
		 *
		 * @return Vektor als Ergebnis 
		 */
		E4DVector operator/(const float s)const;
		
		
	};
}
#endif
