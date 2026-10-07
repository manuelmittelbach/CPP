#include "Serializer.hpp"

/* Orthodox Canonical Form (kept private, never used). */
Serializer::Serializer() {}
Serializer::Serializer(const Serializer &other) { (void)other; }
Serializer &Serializer::operator=(const Serializer &other)
{
	(void)other;
	return *this;
}
Serializer::~Serializer() {}

/*
** Turn a pointer into its raw integer address. reinterpret_cast is the
** right cast here: it reinterprets the bit pattern of the pointer as an
** integer of type uintptr_t (an unsigned integer guaranteed to be large
** enough to hold any pointer value).
*/
uintptr_t Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

/*
** Turn a raw integer address back into a pointer to Data. This is the
** exact inverse of serialize().
*/
Data *Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}
