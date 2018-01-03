#include "variant.h"
namespace wxbasic {

// These are the methods of the base variant class.
// If any of the methods is not implemented, then
// it should throw an error

Variant::Variant(bool numeric, VariantType v_type)
    : is_numeric(numeric), type(v_type) {}

Variant::~Variant() {}
void Variant::reference() {}
void Variant::dereference() {}

void Variant::copy(std::shared_ptr<Variant> source) {}
std::shared_ptr<Variant> Variant::clone() { return NULL; }

void Variant::from_number(Number) {}
Number Variant::to_number() {return 0;}

void Variant::from_string(const std::string &) {}
std::string Variant::to_string() { return ""; }

int Variant::compare(const std::shared_ptr<Variant> object) { return 0; }
int Variant::equal(const std::shared_ptr<Variant> object) { return 0; }

bool Variant::is_true() { return false; }
int Variant::count() { return 0; }

std::shared_ptr<Variant> Variant::index(size_t ind) { return NULL; }

void Variant::insert(std::shared_ptr<Variant> key,
                     std::shared_ptr<Variant> value) {}
std::shared_ptr<Variant> Variant::find(std::shared_ptr<Variant> key) {
    return NULL;
}

void Variant::remove(std::shared_ptr<Variant> key) {}

void Variant::append(std::shared_ptr<Variant> obj) {}
void Variant::prepend(std::shared_ptr<Variant> obj) {}

std::shared_ptr<Variant> Variant::slice(int start, int end, int skip) {
    return NULL;
}
int Variant::iterate(std::shared_ptr<Variant> index,
                     std::shared_ptr<Variant> arg1,
                     std::shared_ptr<Variant> arg2) {
    return 0;
}

} // namespace wxbasic
