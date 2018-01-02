#ifndef WXBASIC_VARIANT_H
#define WXBASIC_VARIANT_H

#include "common.h"
#include <memory>
#include <string>

namespace wxbasic {

enum class VariantType {
    BASE,
    NOTHING,
    STRING,
    INTEGER,
    FLOAT,
    OBJECT,
    ARRAY,
    TABLE,
    LIST,
    VARPTR,
    ROUTINE,
    TIME
};

// Abstract base class for variants
class Variant {
public:
    bool is_numeric;
    VariantType type; // type of data
    VariantType cast; // expected type of data

    Variant(bool is_numeric, VariantType type);
    virtual ~Variant() = 0;

    // reference or dereference the variant for garbage collection
    virtual void reference();
    virtual void dereference();

    virtual void copy(std::shared_ptr<Variant> source);
    virtual std::shared_ptr<Variant> clone();

    virtual void from_number(Number);
    virtual Number to_number();

    virtual void from_string(const std::string &);
    virtual std::string to_string();

    virtual int compare(const std::shared_ptr<Variant> object);
    virtual int equal(const std::shared_ptr<Variant> object);

    virtual bool is_true();
    virtual int count();

    virtual std::shared_ptr<Variant> index(size_t ind);

    virtual void insert(std::shared_ptr<Variant> key,
                        std::shared_ptr<Variant> value);
    virtual std::shared_ptr<Variant> find(std::shared_ptr<Variant> key);

    virtual void remove(std::shared_ptr<Variant> key);

    virtual void append(std::shared_ptr<Variant> obj);
    virtual void prepend(std::shared_ptr<Variant> obj);

    virtual std::shared_ptr<Variant> slice(int start, int end, int skip);
    virtual int iterate(std::shared_ptr<Variant> index,
                        std::shared_ptr<Variant> arg1,
                        std::shared_ptr<Variant> arg2);
};

} // namespace wxbasic

#endif // WXBASIC_VARIANT_H
