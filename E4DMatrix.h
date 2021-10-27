/*
 *
 * Evo 4D Math Engine
 * E4DMatrix.h
 * Author	Daniel Rill
 * Date		14.05.2021
 * Version	1.0
 */
 
 #ifndef E4DMATRIX_H
 #define E4DMATRIX_H
 
 #include <stdio.h>
 #include <iostream>
 #include "E4DVector.h"
 #include "E4DMatrix.h"
 
 namespace E4DEngine {
 	
 	class E4DMatrix {
 	
 	private:
 	
 	
 	public:
 	
 	/**
 	 * Matrix Elemente
 	 */
 	 float matrixData[9] = {0.0};
 	 
 //#pragma mark-constructors
 
 	/**
 	 * Konstruktoren
 	 */
 	 
 	 E4DMatrix();
 	 
 	 E4DMatrix(float m0, float m3, float m6, float m1, float m4, float m7, float m2, float m5, float m8);
 	 
 //#pragma mark-copy constructors
 
 	E4DMatrix& operator=(const E4DMatrix& value);
 	
 	E4DMatrix (const E4DMatrix& value);
 	
 //#pragma mark-destructor
 	
 	~E4DMatrix();
 	

 

 	
 //#pragma mark-matrix addition
 	/**
 	 * Addiere Matrizen miteinander
 	 * 
 	 * @param m matrix
 	 *
 	 * @return neue Matrix
 	 */
 	 
 	 void operator+=(const E4DMatrix &m);
 	/**
 	 * Addiere Matrizen miteinander
 	 * 
 	 * @param m matrix
 	 *
 	 * @return neue Matrix
 	 */
 	 
 	 E4DMatrix operator+(const E4DMatrix &m) const;
 	 
 //#pragma mark-matrix scalar multiplication
 
 	/**
 	 * multipliziere Matrix mit einem Skalar
 	 *
 	 * @param s scalar
 	 *
 	 * @return matrix product
 	 */
 	 void operator*=(const float s);
 	 /**
 	 * multipliziere Matrix mit einem Skalar
 	 *
 	 * @param s scalar
 	 *
 	 * @return matrix product
 	 */
 	 E4DMatrix operator*(const float s) const;
 	 
//#pragma mark-vector transformation
	
	/**
	* transformiere gegebenen Vektor 
	*
	* @param v Vektor
	*
	* @return neuer transformierter Vektor
	*/
	E4DVector operator*(const E4DVector& v) const;
	/**
	* transformiere gegebenen Vektor 
	*
	* @param v Vektor
	*
	* @return neuer transformierter Vektor
	*/
	E4DVector transformVectorByMatrix(const E4DVector& v) const;
 	 
 //#pragma mark-matrix multiplication
 	
 	/**
 	* multipliziere matrix
 	*
 	* @param m matrix
 	*
 	* @return matrix produkt
 	*/
 	E4DMatrix operator*(const E4DMatrix& m) const;
 	 /**
 	* multipliziere matrix
 	*
 	* @param m matrix
 	*/
 	void operator*=(const E4DMatrix& m);
 	
 //#pragma mark-matrix identity
 
 	/**
 	* @brief gewählte matrix als IdentitätsMatrix
 	*/
 	void setMatrixAsIdentityMatrix();
 	
 //#pragma mark-matrix inverse
 
 	/**
 	* stelle die Matrix als inverse der gegebenen Matrix dar
 	*
 	* @param m matrix
 	*/
 	void setMatrixAsInverseOfGivenMatrix(const E4DMatrix& m);
 	
 	/**
 	* returned eine neue inverse Matrix
 	*
 	* @return inverse Matrix
 	*/
 	E4DMatrix getInverseOfMatrix() const;
 	
 	/**
 	* invertiere Matrix
 	*/
 	void invertMatrix();
 	
 //#pragma mark-matrix determinant
 
 	/**
 	* ermittelt die Determinante
 	*
 	* @return Determinante einer Matrix
 	*/
 	float getMatrixDeterminant() const;
 	
 //#pragma mark-matrix transponse
 
 	/**
 	* stelle die Matrix als transponierte der gegebenen Matrix dar
 	*
 	* @return m matrix
 	*/
 	void setMatrixAsTransponseOfGivenMatrix(const E4DMatrix& m);
 	
 	/**
 	* transponiere eine Matrix
 	*
 	* @return transponierte Matrix
 	*/
 	E4DMatrix getTransponseOfMatrix() const;
 	
 //#pragma mark-invert and transponse matrix
 
 	/**
 	* invertiert und transponiert eine Matrix
 	*/
 	void invertAndTransponseMatrix();
 	
 //#pragma mark-make rotation matrix about axis
 
 	/**
 	* @brief rotiere Matrix um X-Achse
 	*
 	* @param uAngle RotationsGrad
 	*/
 	void makeRotationMatrixAboutXAxisByAngle(float uAngle);
 	
  	/**
 	* @brief rotiere Matrix um Y-Achse
 	*
 	* @param uAngle RotationsGrad
 	*/
 	 void makeRotationMatrixAboutYAxisByAngle(float uAngle);
 	 
   	/**
 	* @brief rotiere Matrix um Z-Achse
 	*
 	* @param uAngle RotationsGrad
 	*/
 	 void makeRotationMatrixAboutZAxisByAngle(float uAngle);
 	 
//#pragma mark-transform matrix by axis

	/**
	* @brief transoformiere matrix über die X-Achse
	*
	* @param uAngle RotationsGrad
	*/
	void transformMatrixAboutXAxisByAngle(float uAngle);
	
	/**
	* @brief transoformiere matrix über die Y-Achse
	*
	* @param uAngle RotationsGrad
	*/
	void transformMatrixAboutYAxisByAngle(float uAngle);
	
	/**
	* @brief transoformiere matrix über die Z-Achse
	*
	* @param uAngle RotationsGrad
	*/
	void transformMatrixAboutZAxisByAngle(float uAngle);
	
//#pragma mark-debug
	
	/**
	* Debug, bilde Matrix auf Konsole ab
	*/
	void show();
 	 
 	 };
 
 }
 
 #endif 
 
