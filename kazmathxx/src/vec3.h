/*
Copyright (c) 2009, Luke Benstead, Carsten Haubold
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice,
      this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright notice,
      this list of conditions and the following disclaimer in the documentation
      and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef _KAZMATHXX_VEC3_H
#define _KAZMATHXX_VEC3_H

#include <kazmath/vec3.h>

namespace km
{
	class vec3 : public kmVec3
	{
		public:
			///< Constructors
			vec3(const kmScalar _x, const kmScalar _y, const kmScalar _z) : x(_x), y(_y), z(_z) {};
			
			///< Returns the length of the vector
			kmScalar length()
			{
				return kmVec3Length(this);
			}
			
			///< Returns the square of the length of the vector
			kmScalar lengthSq()
			{
				return kmVec3LengthSq(this);
			}
			
			
			///< Returns the vector passed in set to unit length
			void normalize()
			{
				kmVec3Normalize(this,this);
			}
			
			///< Transform the Vector
			const vec3 transform(const &kmMat4 mat)
			{
				kmVec3Transform(this, this, &mat);
				return *this;
			}

			///< Transforms a 3D vector by a given matrix, projecting the result back into w = 1.
			const vec3 transformCoord(const &kmMat4 mat)
			{
				kmVec3TransformCoord(this, this, &mat);
				return *this;
			}
			
			///< Transforms the vector ignoring the translation part
			const vec3 transformCoord(const &kmMat4 mat)
			{
				kmVec3TransformNormal(this, this, &mat);
				return *this;
			}
			
			///< The cross product returns a vector perpendicular to this and another vector
			const vec3 cross(const kmVec3& vec)
			{
				vec3 result;
				kmVec3Cross(&result, this, &vec);
				return result;
			}
			
			const vec3 inverseTransform(const &kmMat4 mat)
			{
				kmVec3InverseTransform(this, this, &mat);
				return *this;
			}
			
			const vec3 inverseTransformNormal(const &kmMat4 mat)
			{
				kmVec3InverseTransformNormal(this, this, &mat);
				return *this;
			}
	};
	
	///< Vector addition
	const vec3 operator+(const vec3& lhs, const vec3& rhs)
	{
		vec3 result;
		kmVec3Add(&result, &lhs, &rhs);
		return result;
	};

	///< Vector subtraction
	const vec3 operator-(const vec3& lhs, const vec3& rhs)
	{
		vec3 result;
		kmVec3Subtract(&result, &lhs, &rhs);
		return result;
	};
	
	///< Dot product - which is the cosine of the angle between the two vectors multiplied by their lengths
	const float operator*(const vec3& lhs, const vec3& rhs)
	{
		return kmVec3Dot(&lhs, &rhs);
	};
	
	///< Multiply with scalar
	const vec3 operator*(const kmScalar lhs, const vec3& rhs)
	{
		vec3 result;
		kmVec3Scale(&result, &rhs, lhs);
		return result;
	};

	///< Multiply with scalar	
	const vec3 operator*(const vec3& lhs, const kmScalar rhs)
	{
		vec3 result;
		kmVec3Scale(&result, &lhs, rhs);
		return result;
	};
	
	///< Transform through matrix	
	const vec3 operator*(const kmMat4& lhs, const vec3& rhs)
	{
		vec3 result;
		kmVec3Transform(&result, &rhs, &lhs)
		return result;
	};
	
	///< Checks for equality (with a small threshold epsilon)
	const bool operator==(const vec3& lhs, const vec3& rhs)
	{
		return kmVec3AreEqual(&lhs,&rhs);
	};
} //end of namespace km

#endif
