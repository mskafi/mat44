#ifndef MATH_H
#define MATH_H

#include <cmath>

namespace glutil { namespace math{
	typedef float real;

	const real PI = 3.1415926535897932384626433832795f;

	struct vec3;
	struct vec4;
	struct mat3;
	struct mat4;

	vec3 operator *(mat3 const &, vec3 const &);
	vec4 operator *(mat4 const &, vec4 const &);

	struct vec3 {
		real x, y, z;

		vec3() : x(0), y(0), z(0)
		{}

		vec3(real a, real b, real c) :
		x(a), y(b), z(c)
		{}

		vec3(vec3 const & other) :
		x(other.x), y(other.y), z(other.z)
		{}

		vec3& operator +=(vec3 const & other){
			x += other.x;
			y += other.y;
			z += other.z;

			return *this;
		}

		vec3& operator *=(real s){
			x *= s;
			y *= s;
			z *= s;

			return *this;
		}

		vec3& operator /=(real s){
			return ((*this)*=(1/s));
		}

		vec3& operator *=(vec3 const & other){
			x *= other.x;
			y *= other.y;
			z *= other.z;

			return *this;
		}

		vec3 operator +() const{
			return vec3(+x, +y, +z);
		}

		vec3 operator -() const{
			return vec3(-x, -y, -z);
		}

		vec3& operator -=(vec3 const & other){
			return ((*this) += -other);
		}

		vec3 operator +(vec3 const & other) const{
			return (vec3(*this)+=other);
		}

		vec3 operator -(vec3 const & other) const{
			return (vec3(*this)-=other);
		}

		vec3 operator *(real s) const{
			return vec3(*this) *= s;
		}

		vec3 operator *(vec3 const & other) const{
			return vec3(*this) *= other;
		}

		vec3 operator /(real s) const{
			return vec3(*this) /= s;
		}

		real lengthSq() const{
			return x*x + y*y + z*z;
		}

		real length() const{
			return std::sqrt(lengthSq());
		}
	};

	struct vec4 {
		real x, y, z, w;

		vec4() : x(0), y(0), z(0), w(0)
		{}

		vec4(real _x, real _y, real _z, real _w) :
		x(_x), y(_y), z(_z), w(_w)
		{}

		vec4(vec3 const & other, real _w) :
		x(other.x), y(other.y), z(other.z), w(_w)
		{}

		vec4(vec4 const & other) :
		x(other.x), y(other.y), z(other.z), w(other.w)
		{}

		vec4& operator +=(vec4 const & other){
			x += other.x;
			y += other.y;
			z += other.z;
			w += other.w;

			return *this;
		}

		vec4& operator *=(real s){
			x *= s;
			y *= s;
			z *= s;
			w *= s;

			return *this;
		}

		vec4& operator /=(real s){
			return ((*this)*=(1/s));
		}

		vec4& operator *=(vec4 const & other){
			x *= other.x;
			y *= other.y;
			z *= other.z;
			w *= other.w;

			return *this;
		}

		vec4 operator +() const{
			return vec4(+x, +y, +z, +w);
		}

		vec4 operator -() const{
			return vec4(-x, -y, -z, -w);
		}

		vec4& operator -=(vec4 const & other){
			return ((*this) += -other);
		}

		vec4 operator +(vec4 const & other) const{
			return (vec4(*this)+=other);
		}

		vec4 operator -(vec4 const & other) const{
			return (vec4(*this)-=other);
		}

		vec4 operator *(real s) const{
			return vec4(*this) *= s;
		}

		vec4 operator *(vec4 const & other) const{
			return vec4(*this) *= other;
		}

		vec4 operator /(real s) const{
			return vec4(*this) /= s;
		}

		real lengthSq() const{
			return x*x + y*y + z*z;
		}

		real length() const{
			return std::sqrt(lengthSq());
		}
	};

	struct mat3{
		vec3 x, y, z;

		mat3(real s = 1) : x(s, 0, 0), y(0, s, 0), z(0, 0, s)
		{}

		mat3(vec3 const & _x, vec3 const & _y, vec3 const & _z) :
		x(_x), y(_y), z(_z)
		{}

		mat3(mat3 const & other) :
		x(other.x), y(other.y), z(other.z)
		{}

		mat3 & operator +=(mat3 const & other){
			x += other.x;
			y += other.y;
			z += other.z;

			return (*this);
		}

		mat3 operator *=(real s){
			x *= s;
			y *= s;
			z *= s;

			return (*this);
		}

		mat3 operator /=(real s){
			return ((*this)*=(1/s));
		}

		mat3 operator *=(mat3 const & other){
			return (*this) = 
				mat3(
				(*this)*other.x,
				(*this)*other.y,
				(*this)*other.z);
		}

		mat3 operator +() const{
			return mat3(+x, +y, +z);
		}

		mat3 operator -() const{
			return mat3(-x, -y, -z);
		}

		mat3 operator -=(mat3 const & other){
			return ((*this) += -other);
		}

		mat3 operator +(mat3 const & other) const {
			return (mat3(*this)+=other);
		}

		mat3 operator -(mat3 const & other) const {
			return (mat3(*this)-=other);
		}

		mat3 operator *(real s) const{
			return (mat3(*this)*=s);
		}

		mat3 operator /(real s) const{
			return (mat3(*this)/=s);
		}

		mat3 operator *(mat3 const & other) const{
			return (mat3(*this)*=other);
		}
	};

	struct mat4{
		vec4 x, y, z, w;

		mat4(real s = 1) :
		x(vec4(s, 0, 0, 0)),
			y(vec4(0, s, 0, 0)),
			z(vec4(0, 0, s, 0)),
			w(vec4(0, 0, 0, 1))
		{}

		mat4(vec4 const & _x, vec4 const & _y, vec4 const & _z, vec4 const & _w) :
		x(_x), y(_y), z(_z), w(_w)
		{}

		mat4(mat3 const & other) :
		x(other.x, 0), y(other.y, 0), z(other.z, 0), w(0, 0, 0, 1)
		{}

		mat4(mat4 const & other) :
		x(other.x), y(other.y), z(other.z), w(other.w)
		{}

		mat4 & operator +=(mat4 const & other){
			x += other.x;
			y += other.y;
			z += other.z;
			w += other.w;

			return (*this);
		}

		mat4 operator *=(real s){
			x *= s;
			y *= s;
			z *= s;
			w *= s;

			return (*this);
		}

		mat4 operator /=(real s){
			return ((*this)*=(1/s));
		}

		mat4 operator *=(mat4 const & other){
			return (*this) =
				mat4(
				(*this)*other.x,
				(*this)*other.y,
				(*this)*other.z,
				(*this)*other.w);
		}

		mat4 operator +() const{
			return mat4(+x, +y, +z, +w);
		}

		mat4 operator -() const{
			return mat4(-x, -y, -z, -w);
		}

		mat4 operator -=(mat4 const & other){
			return ((*this) += -other);
		}

		mat4 operator +(mat4 const & other) const {
			return (mat4(*this)+=other);
		}

		mat4 operator -(mat4 const & other) const {
			return (mat4(*this)-=other);
		}

		mat4 operator *(real s) const{
			return (mat4(*this)*=s);
		}

		mat4 operator /(real s) const{
			return (mat4(*this)/=s);
		}

		mat4 operator *(mat4 const & other) const{
			return (mat4(*this)*=other);
		}
	};

	inline vec3 operator *(real s, vec3 const & v){
		return v * s;
	}

	inline vec3 cross(vec3 const & a, vec3 const & b){
		return vec3(
			a.y * b.z - b.y * a.z,
			a.z * b.x - b.z * a.x,
			a.x * b.y - b.x * a.y);
	}

	inline real dot(vec3 const & a, vec3 const & b){
		return a.x * b.x + a.y * b.y + a.z * b.z;
	}

	inline vec3 operator *(mat3 const & m, vec3 const & v){
		return m.x * v.x + m.y * v.y + m.z * v.z;
	}

	inline vec4 operator *(real s, vec4 const & v){
		return v * s;
	}

	inline vec4 operator *(mat4 const & m, vec4 const & v){
		return m.x * v.x + m.y * v.y + m.z * v.z + m.w * v.w;
	}

	inline real det(mat3 const & m){
		return dot(m.x, cross(m.y, m.z));
	}

	inline vec4 wedge(vec4 const & a, vec4 const & b, vec4 const & c){
		mat3 mx(
			vec3(a.y, a.z, a.w),
			vec3(b.y, b.z, b.w),
			vec3(c.y, c.z, c.w));

		mat3 my(
			vec3(a.x, a.z, a.w),
			vec3(b.x, b.z, b.w),
			vec3(c.x, c.z, c.w));

		mat3 mz(
			vec3(a.x, a.y, a.w),
			vec3(b.x, b.y, b.w),
			vec3(c.x, c.y, c.w));

		mat3 mw(
			vec3(a.x, a.y, a.z),
			vec3(b.x, b.y, b.z),
			vec3(c.x, c.y, c.z));

		return vec4(
			+det(mx),
			-det(my),
			+det(mz),
			-det(mw));
	}

	inline real dot(vec4 const & a, vec4 const & b){
		return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
	}

	inline mat3 skew(vec3 const & v) {
		return mat3(
			vec3(+0, +v.z, -v.y),
			vec3(-v.z, +0, +v.x),
			vec3(+v.y, -v.x, +0));
	}

	inline mat3 rotation(real angle, vec3 const & _axis)
	{
		real c = cos( angle );
		real s = sin( angle );
		vec3 v(_axis);

		v /= v.length();

		return
			mat3(c) +
			skew(v * s) +
			mat3(
				v.x * v,
				v.y * v,
				v.z * v
			) * (1 - c);
	}

	inline mat3 transpose(mat3 const & m){
		return
			mat3(
			vec3(m.x.x, m.y.x, m.z.x),
			vec3(m.x.y, m.y.y, m.z.y),
			vec3(m.x.z, m.y.z, m.z.z)
			);
	}

	inline mat3 inverse(mat3 const & m){
		return
			transpose(
			mat3(
			cross(m.y, m.z),
			cross(m.z, m.x),
			cross(m.x, m.y)
			)
			) / det(m);
	}

	inline mat4 translation(vec3 const & v){
		mat4 result(1);
		result.w.x = v.x;
		result.w.y = v.y;
		result.w.z = v.z;

		return result;
	}

	inline real det(mat4 const & m){
		return dot(m.x, wedge(m.y, m.z, m.w));
	}

	inline mat4 transpose(mat4 const & m){
		return
			mat4(
			vec4(m.x.x, m.y.x, m.z.x, m.w.x),
			vec4(m.x.y, m.y.y, m.z.y, m.w.y),
			vec4(m.x.z, m.y.z, m.z.z, m.w.z),
			vec4(m.x.w, m.y.w, m.z.w, m.w.w)
			);
	}

	inline mat4 inverse(mat4 const & m){
		return
			transpose(
			mat4(
			+wedge(m.y, m.z, m.w),
			-wedge(m.z, m.w, m.x),
			+wedge(m.w, m.x, m.y),
			-wedge(m.x, m.y, m.z))) / det(m);
	}

	inline mat4 frustum(real left, real right, real bottom, real top, real nearZ, real farZ){
		mat4 frust;
		real deltaX = right - left;
		real deltaY = top - bottom;
		real deltaZ = farZ - nearZ;

		frust.x.x = 2.0f * nearZ / deltaX;
		frust.x.y = frust.x.y = frust.x.w = 0.0f;

		frust.y.y = 2.0f * nearZ / deltaY;
		frust.y.x = frust.y.z = frust.y.w = 0.0f;

		frust.z.x = (right + left) / deltaX;
		frust.z.y = (top + bottom) / deltaY;
		frust.z.z = -(nearZ + farZ) / deltaZ;
		frust.z.w = -1.0f;

		frust.w.z = -2.0f * nearZ * farZ / deltaZ;
		frust.w.x = frust.w.y = frust.w.w = 0.0f;

		return frust;
	}

	inline mat4 perspective (real fovy, real aspect, real nearZ, real farZ){
		mat4 persp;
		real frustumW, frustumH;

		frustumH = std::tan( fovy / 2 ) * nearZ;
		frustumW = frustumH * aspect;

		return frustum(-frustumW, frustumW, -frustumH, frustumH, nearZ, farZ);
	}

	inline mat4 orthogonal (real left, real right, real bottom, real top, real nearZ, real farZ){
		real	deltaX = right - left;
		real	deltaY = top - bottom;
		real	deltaZ = farZ - nearZ;
		mat4	ortho;

		ortho.x.x = 2.0f / deltaX;
		ortho.w.x = -(right + left) / deltaX;
		ortho.y.y = 2.0f / deltaY;
		ortho.z.y = -(top + bottom) / deltaY;
		ortho.z.z = -2.0f / deltaZ;
		ortho.w.z = -(nearZ + farZ) / deltaZ;

		return ortho;
	}

	inline mat4 view (vec3 const & eye, vec3 const & _up, vec3 const & _forward){
		vec3 right(cross(_up, _forward));
		vec3 up(cross(_forward, right));
		vec3 forward(_forward);

		up /= up.length();
		right /= right.length();
		forward /= forward.length();

		return
			transpose(
				mat4(
					vec4(+right,	0),
					vec4(+up,		0),
					vec4(-forward,	0),
					vec4(vec3(),	1)
				)
			) 
			* translation(-eye);
	}
} }

#endif // MATH_H