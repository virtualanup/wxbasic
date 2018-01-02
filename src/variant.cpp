#include "variant.h"
namespace wxbasic {

Variant::Variant(bool numeric, VariantType v_type)
    : is_numeric(numeric), type(v_type) {}

Variant::~Variant() {}
//void Variant::reference() {}
//void Variant::dereference() {}

//void Variant::copy(std::shared_ptr<Variant> source) {}
//std::shared_ptr<Variant> Variant::clone() {}

//void Variant::from_number(Number) {}
//Number Variant::to_number() {}

//void Variant::from_string(const std::string &) {}
//std::string Variant::to_string() {}

//int Variant::compare(const std::shared_ptr<Variant> object) {}
//int Variant::equal(const std::shared_ptr<Variant> object) {}

//bool Variant::is_true() {}
//int Variant::count() {}

//std::shared_ptr<Variant> Variant::index(size_t ind) {}

//void Variant::insert(std::shared_ptr<Variant> key,
//                     std::shared_ptr<Variant> value) {}
//std::shared_ptr<Variant> Variant::find(std::shared_ptr<Variant> key) {}

//void Variant::remove(std::shared_ptr<Variant> key) {}

//void Variant::append(std::shared_ptr<Variant> obj) {}
//void Variant::prepend(std::shared_ptr<Variant> obj) {}

//std::shared_ptr<Variant> Variant::slice(int start, int end, int skip) {}
//int Variant::iterate(std::shared_ptr<Variant> index,
//                     std::shared_ptr<Variant> arg1,
//                     std::shared_ptr<Variant> arg2) {}

} // namespace wxbasic
