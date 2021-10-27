/*
 *
 * Evo 4D Math Engine
 * E4DMatrix.cpp
 * Author	Daniel Rill
 * Date		14.05.2021
 * Version	1.0
 */
 
 #include "E4DMatrix.h"
 #include "Constants.h"
 
 namespace E4DEngine {
 
 //#pragma mark-constructor
 
 	E4DMatrix::E4DMatrix() {
 	
 		// 3x3 matrix
 		// 	0	3	6
 		//	1	4	7
 		//	2	5	8
 		
 		for (int i=0; i < 9; i++)
 			matrixData[i] = 0.0f;
 			
 		matrixData[0]=matrixData[4]=matrixData[8]=1.0f;
 		
 	}
 	
 	E4DMatrix::E4DMatrix(float m0, float m3, float m6, float m1, float m4, float m7, float m2, float m5, float m8) {
 	
 		//3x3 Matrix
 		 // 	0	3	6
 		//	1	4	7
 		//	2	5	8
 		
 		matrixData[0] = m0;
 		matrixData[3] = m3;
 		matrixData[6] = m6;
 		
 		matrixData[1] = m1;
 		matrixData[4] = m4;
 		matrixData[7] = m7;
 		
 		matrixData[2] = m2;
 		matrixData[5] = m5;
 		matrixData[8] = m8;
 		
 	}
 	
 //#pragma mark-copy constructor
 
 	E4DMatrix& E4DMatrix::operator=(const E4DMatrix& value) {
 	
 		for (int i=0; i<9; i++) 
 			matrixData[i] = value.matrixData[i];
 			
 		return *this;
 		
 	}
 	
 	E4DMatrix::E4DMatrix (const E4DMatrix& value) {
 	
  		for (int i=0; i<9; i++) 
 			matrixData[i] = value.matrixData[i];	
 	}
 	
 //#pragma mark-destructor
 
 	E4DMatrix::~E4DMatrix() {}
 	
 //#pragma mark-matrix addition
 
 	void E4DMatrix::operator+=(const E4DMatrix &m) {
 	
 		matrixData[0]+=m.matrixData[0];
 		matrixData[3]+=m.matrixData[3];
 		matrixData[6]+=m.matrixData[6];
 		
 		matrixData[1]+=m.matrixData[1];
 		matrixData[4]+=m.matrixData[4];
 		matrixData[7]+=m.matrixData[7];
 		
 		matrixData[2]+=m.matrixData[2];
 		matrixData[5]+=m.matrixData[5];
 		matrixData[8]+=m.matrixData[8];
 	}
 	
 	E4DMatrix E4DMatrix::operator+(const E4DMatrix &m) const {
 	
 		E4DMatrix n;
 		
 		n.matrixData[0]=matrixData[0]+m.matrixData[0];
 		n.matrixData[3]=matrixData[3]+m.matrixData[3];
  		n.matrixData[6]=matrixData[6]+m.matrixData[6];
  		
  		n.matrixData[1]=matrixData[1]+m.matrixData[1];
  		n.matrixData[4]=matrixData[4]+m.matrixData[4];
   		n.matrixData[7]=matrixData[7]+m.matrixData[7];
   		
   		n.matrixData[2]=matrixData[2]+m.matrixData[2];
    		n.matrixData[5]=matrixData[5]+m.matrixData[5];
     		n.matrixData[8]=matrixData[8]+m.matrixData[8];
     		
     		return n;
     	}
     	
//#pragma mark-matrix scalar multiplication

	void E4DMatrix::operator*=(const float s) {
	
 		matrixData[0] *= s;
 		matrixData[3] *= s;
 		matrixData[6] *= s;
 		
 		matrixData[1] *= s;
 		matrixData[4] *= s;
 		matrixData[7] *= s;
 		
 		matrixData[2] *= s;
 		matrixData[5] *= s;
 		matrixData[8] *= s;
 		
 	}
 	
 	E4DMatrix E4DMatrix::operator*(const float s) const {
 	
 		E4DMatrix n;
 		
 		n.matrixData[0] = matrixData[0]*s;
 		n.matrixData[3] = matrixData[3]*s;
 		n.matrixData[6] = matrixData[6]*s;
 		
 		n.matrixData[1] = matrixData[1]*s;
 		n.matrixData[4] = matrixData[4]*s;
 		n.matrixData[7] = matrixData[7]*s;
 		
 		n.matrixData[2] = matrixData[2]*s;
 		n.matrixData[5] = matrixData[5]*s;
 		n.matrixData[8] = matrixData[8]*s;
 		
 		return n;
 	}
 		
//#pragma mark-vector transformation

	E4DVector E4DMatrix::operator*(const E4DVector& v) const {
	
		return E4DVector(matrixData[0]*v.x+matrixData[3]*v.y+matrixData[6]*v.z,
						   matrixData[1]*v.x+matrixData[4]*v.y+matrixData[7]*v.z,
						   matrixData[2]*v.x+matrixData[5]*v.y+matrixData[8]*v.z);
		
	}
	
	E4DVector E4DMatrix::transformVectorByMatrix(const E4DVector& v) const {
	
		return (*this)*v;
	}
	
//#pragma mark-matrix multiplication

	E4DMatrix E4DMatrix::operator*(const E4DMatrix& m) const {
	
	 	// 3x3 matrix	*	// 3x3 matrix
 		// 	0	3	6		// 	0	3	6
 		//	1	4	7		//	1	4	7
 		//	2	5	8		//	2	5	8
	
		return E4DMatrix(matrixData[0]*m.matrixData[0] + matrixData[3]*m.matrixData[1] + matrixData[6]*m.matrixData[2],
						   matrixData[0]*m.matrixData[3] + matrixData[3]*m.matrixData[4] + matrixData[6]*m.matrixData[5],
						   matrixData[0]*m.matrixData[6] + matrixData[3]*m.matrixData[7] + matrixData[6]*m.matrixData[8],
		
						   matrixData[1]*m.matrixData[0] + matrixData[4]*m.matrixData[1] + matrixData[7]*m.matrixData[2],
						   matrixData[1]*m.matrixData[3] + matrixData[4]*m.matrixData[4] + matrixData[7]*m.matrixData[5],
						   matrixData[1]*m.matrixData[6] + matrixData[4]*m.matrixData[7] + matrixData[7]*m.matrixData[8],
						   
						   matrixData[2]*m.matrixData[0] + matrixData[5]*m.matrixData[1] + matrixData[8]*m.matrixData[2],
						   matrixData[2]*m.matrixData[3] + matrixData[5]*m.matrixData[4] + matrixData[8]*m.matrixData[5],
						   matrixData[2]*m.matrixData[6] + matrixData[5]*m.matrixData[7] + matrixData[8]*m.matrixData[8]);						   						   						  						   					    
	}
		
	void E4DMatrix::operator*=(const E4DMatrix& m) {
		
		float t1;
		float t2;
		float t3;
			
		t1 = matrixData[0]*m.matrixData[0] + matrixData[3]*m.matrixData[1] + matrixData[6]*m.matrixData[2];
		t2 = matrixData[0]*m.matrixData[3] + matrixData[3]*m.matrixData[4] + matrixData[6]*m.matrixData[5];	
		t3 = matrixData[0]*m.matrixData[6] + matrixData[3]*m.matrixData[7] + matrixData[6]*m.matrixData[8];
			
		matrixData[0] = t1;
		matrixData[3] = t2;
		matrixData[6] = t3;
		
		t1 = matrixData[1]*m.matrixData[0] + matrixData[4]*m.matrixData[1] + matrixData[7]*m.matrixData[2];
		t2 = matrixData[1]*m.matrixData[3] + matrixData[4]*m.matrixData[4] + matrixData[7]*m.matrixData[5];
		t3 = matrixData[1]*m.matrixData[6] + matrixData[4]*m.matrixData[7] + matrixData[7]*m.matrixData[8];	
			
		matrixData[1] = t1;
		matrixData[4] = t2;
		matrixData[7] = t3;	

		t1 = matrixData[2]*m.matrixData[0] + matrixData[5]*m.matrixData[1] + matrixData[8]*m.matrixData[2];
		t2 = matrixData[2]*m.matrixData[3] + matrixData[5]*m.matrixData[4] + matrixData[8]*m.matrixData[5];
		t3 = matrixData[2]*m.matrixData[6] + matrixData[5]*m.matrixData[7] + matrixData[8]*m.matrixData[8];
		
		matrixData[2] = t1;
		matrixData[5] = t2;
		matrixData[8] = t3;	
	}
		
//#pragma mark-matrix identity 

	void E4DMatrix::setMatrixAsIdentityMatrix(){
		
		for (int i = 0; i < 9; i++) {
			matrixData[i]=0.0f;
		}
			
		matrixData[0]=matrixData[4]=matrixData[8]=1.0f;
			
	}
		
//#pragma mark-matrix inverse
 		
 		//3x3 Matrix
 		 // 	0	3	6
 		//	1	4	7
 		//	2	5	8

	void E4DMatrix::setMatrixAsInverseOfGivenMatrix(const E4DMatrix& m) {
		
		float t1 = m.matrixData[0]*m.matrixData[4];
		float t2 = m.matrixData[0]*m.matrixData[7];
		float t3 = m.matrixData[3]*m.matrixData[1];
		float t4 = m.matrixData[6]*m.matrixData[1];
		float t5 = m.matrixData[3]*m.matrixData[2];
		float t6 = m.matrixData[6]*m.matrixData[2];
		
		// ermittle die Determinante
		
		float det = (t1*m.matrixData[8] - t2*m.matrixData[5] - t3*m.matrixData[8] + t4*m.matrixData[5] + t5*m.matrixData[7] - t6*m.matrixData[4]);
		
		// sichergehen det != 0
		if (det == 0.0) return;
		
		float invd = 1.0f/det;
		
		float m0 = (m.matrixData[4]*m.matrixData[8] - m.matrixData[7] * m.matrixData[5]) * invd;
		
		float m3 = (m.matrixData[3]*m.matrixData[8] - m.matrixData[6] * m.matrixData[5]) * invd;
		
		float m6 = (m.matrixData[3]*m.matrixData[7] - m.matrixData[6] * m.matrixData[4]) * invd;
		
		float m1 = (m.matrixData[1]*m.matrixData[8] - m.matrixData[7] * m.matrixData[2]) * invd;
		
		float m4 = (m.matrixData[0]*m.matrixData[8] - t6) * invd;
			
		float m7 = -(t2-t4) * invd;
		
		float m2 = (m.matrixData[1]*m.matrixData[5] - m.matrixData[4] * m.matrixData[2]) * invd;
		
		float m5 = (m.matrixData[0]*m.matrixData[5] - t5) * invd;
		
		float m8 = (t1-t3) * invd;
		
		
		matrixData[0] = m0;
		matrixData[3] = m3;
		matrixData[6] = m6;
		
		matrixData[1] = m1;
		matrixData[4] = m4;
		matrixData[7] = m7;
		
		matrixData[2] = m2;
		matrixData[5] = m5;
		matrixData[8] = m8;
	}
		
		
	E4DMatrix E4DMatrix::getInverseOfMatrix() const{
			
		E4DMatrix result;
		result.setMatrixAsInverseOfGivenMatrix(*this);
		return result;
	}
	
	void E4DMatrix::invertMatrix() {
		
		setMatrixAsInverseOfGivenMatrix(*this);
	}
		
//#pragma mark-matrix determinant
	
	float E4DMatrix::getMatrixDeterminant() const {
	
	 	//3x3 Matrix
 		 // 	0	3	6
 		//	1	4	7
 		//	2	5	8
	
		float t1 = matrixData[0]*matrixData[4];
		float t2 = matrixData[0]*matrixData[7];
		float t3 = matrixData[3]*matrixData[1];
		float t4 = matrixData[6]*matrixData[1];
		float t5 = matrixData[3]*matrixData[2];	
		float t6 = matrixData[6]*matrixData[2];	
		
		//ermittle die Determinante
		
		float det = (t1*matrixData[8] - t2*matrixData[5] - t3*matrixData[8] + t4*matrixData[5] + t5*matrixData[7] - t6*matrixData[4]);
		
		return det;
	}	

//#pragma mark-matrix transponse

	void E4DMatrix::setMatrixAsTransponseOfGivenMatrix(const E4DMatrix& m) {
		 //3x3 Matrix
 		 // 	0	3	6
 		//	1	4	7
 		//	2	5	8
 		
 		//3x3 transponiert
 		 // 	0	1	2
 		//	3	4	5
 		//	6	7	8
 		
 		matrixData[0] = m.matrixData[0];
  		matrixData[3] = m.matrixData[1];
   		matrixData[6] = m.matrixData[2];
   		
    		matrixData[1] = m.matrixData[3];
     		matrixData[4] = m.matrixData[4];
      	matrixData[7] = m.matrixData[5];
      		
       	matrixData[2] = m.matrixData[6];
 		matrixData[5] = m.matrixData[7];
 		matrixData[8] = m.matrixData[8];
       		
	}
	
	E4DMatrix E4DMatrix::getTransponseOfMatrix() const {
		
		E4DMatrix result;
		result.setMatrixAsTransponseOfGivenMatrix(*this);
		return result;

	}
	
//#pragma mark-invert and transponse matrix

	void E4DMatrix::invertAndTransponseMatrix() {
		//3x3 Matrix
 		 // 	0	3	6
 		//	1	4	7
 		//	2	5	8
 		
 		//3x3 transponiert
 		 // 	0	1	2
 		//	3	4	5
 		//	6	7	8
 		
 		//ermittle Determinante
 		
 		float det = matrixData[0]*(matrixData[4]*matrixData[8] - matrixData[5]*matrixData[7]) 
 				   - matrixData[3]*(matrixData[1]*matrixData[8] - matrixData[2]*matrixData[7])
 				  + matrixData[6]*(matrixData[1]*matrixData[5] - matrixData[2]*matrixData[4]);
 				  
 		//transponiere OriginalMatrix
 		E4DMatrix transponse;
 		
 		transponse.matrixData[0] = matrixData[0];
  		transponse.matrixData[1] = matrixData[3]; 
   		transponse.matrixData[2] = matrixData[6]; 
   		
    		transponse.matrixData[3] = matrixData[1]; 
     		transponse.matrixData[4] = matrixData[4]; 
      	transponse.matrixData[5] = matrixData[7]; 
      	 
 		transponse.matrixData[6] = matrixData[2]; 
  		transponse.matrixData[7] = matrixData[5]; 
   		transponse.matrixData[8] = matrixData[8]; 
	
		//ermittle die adjungierte Matrix und Teile diese mit det(M)
		
		float m11, m12, m13, m21, m22, m23, m31, m32, m33;
		
		m11 =+(transponse.matrixData[4] * transponse.matrixData[8] - transponse.matrixData[5] * transponse.matrixData[7]) / det;
		m12 =+(transponse.matrixData[1] * transponse.matrixData[8] - transponse.matrixData[2] * transponse.matrixData[7]) / det;
		m13 =+(transponse.matrixData[1] * transponse.matrixData[5] - transponse.matrixData[2] * transponse.matrixData[4]) / det;
		
		m21 =+(transponse.matrixData[3] * transponse.matrixData[8] - transponse.matrixData[5] * transponse.matrixData[6]) / det;
		m22 =+(transponse.matrixData[0] * transponse.matrixData[8] - transponse.matrixData[2] * transponse.matrixData[6]) / det;
		m23 =+(transponse.matrixData[0] * transponse.matrixData[5] - transponse.matrixData[2] * transponse.matrixData[3]) / det;
		
		m31 =+(transponse.matrixData[3] * transponse.matrixData[7] - transponse.matrixData[4] * transponse.matrixData[6]) / det;
		m32 =+(transponse.matrixData[0] * transponse.matrixData[7] - transponse.matrixData[1] * transponse.matrixData[6]) / det;
		m33 =+(transponse.matrixData[0] * transponse.matrixData[4] - transponse.matrixData[1] * transponse.matrixData[3]) / det;
		
		E4DMatrix preResult;
		
		preResult.matrixData[0] = m11;
		preResult.matrixData[1] = m21;
		preResult.matrixData[2] = m31;
		
		preResult.matrixData[3] = m12;
		preResult.matrixData[4] = m22;
		preResult.matrixData[5] = m32;
		
		preResult.matrixData[6] = m13;
		preResult.matrixData[7] = m23;
		preResult.matrixData[8] = m33;
		
		//3x3 Matrix
 		 // 	0	3	6
 		//	1	4	7
 		//	2	5	8
 		
 		//3x3 transponiert
 		 // 	0	1	2
 		//	3	4	5
 		//	6	7	8
 		
 		//transponiere die Matrix
 		
 		matrixData[0] = preResult.matrixData[0];
  		matrixData[1] = preResult.matrixData[3];
   		matrixData[2] = preResult.matrixData[6];
   		
    		matrixData[3] = preResult.matrixData[1];
     		matrixData[4] = preResult.matrixData[4];
     		matrixData[5] = preResult.matrixData[7];
    
 		matrixData[6] = preResult.matrixData[2];
  		matrixData[7] = preResult.matrixData[5];
   		matrixData[8] = preResult.matrixData[8];  		
	}
	
//#pragma mark-transform matrix about axis

	void E4DMatrix::makeRotationMatrixAboutXAxisByAngle(float uAngle) {
	
		uAngle = DegreesToRad(uAngle);
		
		(*this).setMatrixAsIdentityMatrix();
		
		E4DMatrix m(1.0, 0.0, 0.0,
					  0.0, cos(uAngle), -sin(uAngle),
					  0.0, sin(uAngle), cos(uAngle));
					  
		*this = m*(*this);
		
	}
	
	void E4DMatrix::makeRotationMatrixAboutYAxisByAngle(float uAngle) {
	
		uAngle = DegreesToRad(uAngle);
		
		(*this).setMatrixAsIdentityMatrix();
		
		E4DMatrix m(cos(uAngle), 0.0, sin(uAngle),
					  0.0, 1.0, 0.0, 
					  -sin(uAngle), 0.0, cos(uAngle));
					  
		*this = m*(*this);
		
	}
	
	void E4DMatrix::makeRotationMatrixAboutZAxisByAngle(float uAngle) {
	
		uAngle = DegreesToRad(uAngle);
		
		(*this).setMatrixAsIdentityMatrix();
		
		E4DMatrix m(cos(uAngle), -sin(uAngle), 0.0, 
					  sin(uAngle), cos(uAngle), 0.0, 
					  0.0, 0.0, 1.0);
					  
		*this = m*(*this);
		
	}
	
//#pragma mark-transform matrix by axis

	void E4DMatrix::transformMatrixAboutXAxisByAngle(float uAngle) {

		uAngle = DegreesToRad(uAngle);
		
		E4DMatrix m(1.0, 0.0, 0.0,
					  0.0, cos(uAngle), -sin(uAngle),
					  0.0, sin(uAngle), cos(uAngle));
					  
		*this = m*(*this);	
		
	}
	
	void E4DMatrix::transformMatrixAboutYAxisByAngle(float uAngle) {

		uAngle = DegreesToRad(uAngle);
		
		E4DMatrix m(cos(uAngle), 0.0, sin(uAngle),
					  0.0, 1.0, 0.0, 
					  -sin(uAngle), 0.0, cos(uAngle));
					  
		*this = m*(*this);	
		
	}
	
	void E4DMatrix::transformMatrixAboutZAxisByAngle(float uAngle) {

		uAngle = DegreesToRad(uAngle);
		
		E4DMatrix m(cos(uAngle), -sin(uAngle), 0.0, 
					  sin(uAngle), cos(uAngle), 0.0, 
					  0.0, 0.0, 1.0);
		*this = m*(*this);	
		
	}
	
//#pragma mark-debug

	void E4DMatrix::show() {
	
		std::cout<<"["<<matrixData[0]<<","<<matrixData[3]<<","<<matrixData[6]<<","<<std::endl;
		std::cout<<matrixData[1]<<","<<matrixData[4]<<","<<matrixData[7]<<","<<std::endl;
		std::cout<<matrixData[2]<<","<<matrixData[5]<<","<<matrixData[8]<<"]"<<std::endl;
	}

}
