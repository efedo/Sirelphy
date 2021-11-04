// Copyright 2018-19 Eric Fedosejevs

#pragma once

#include "Sirelphy/source/core/precomp.h"
#include "Sirelphy/source/core/unitlib/helpers/macro_debugging.h"
#include "Sirelphy/source/core/unitlib/helpers/si_prefixes.h"

using namespace si;

#define UNIT_ADD_BASE(NAME, NAME_PLURAL, RATIO) __NL__ \
constexpr double units_per_##NAME = RATIO; __NL__ \
constexpr double NAME_PLURAL##_per_unit = 1.0 / units_per_##NAME; __NL__

#define UNIT_ADD_RELATIVE(NAME, NAME_PLURAL, BASE, RATIO) __NL__ \
constexpr double units_per_##NAME = units_per_##BASE * RATIO; __NL__ \
constexpr double NAME_PLURAL##_per_unit = 1.0 / units_per_##NAME; __NL__ \

#define UNIT_ADD_RELATIVE_SHIFTED(NAME, NAME_PLURAL, BASE, SHIFT, RATIO) __NL__ \
constexpr double units_per_##NAME = units_per_##BASE * RATIO; __NL__ \
constexpr double NAME_PLURAL##_per_unit = 1.0 / units_per_##NAME; __NL__ \

#define UNIT_ADD_SIPREFIXES(BASE, BASE_PLURAL) __NL__ \
UNIT_ADD_RELATIVE(yocto##BASE, yocto##BASE_PLURAL, BASE, si_yocto) __NL__ \
UNIT_ADD_RELATIVE(zepto##BASE, zepto##BASE_PLURAL, BASE, si_zepto) __NL__ \
UNIT_ADD_RELATIVE(atto##BASE, atto##BASE_PLURAL, BASE, si_atto) __NL__ \
UNIT_ADD_RELATIVE(femto##BASE, femto##BASE_PLURAL, BASE, si_femto) __NL__ \
UNIT_ADD_RELATIVE(pico##BASE, pico##BASE_PLURAL, BASE, si_pico) __NL__ \
UNIT_ADD_RELATIVE(nano##BASE, nano##BASE_PLURAL, BASE, si_nano) __NL__ \
UNIT_ADD_RELATIVE(micro##BASE, micro##BASE_PLURAL, BASE, si_micro) __NL__ \
UNIT_ADD_RELATIVE(milli##BASE, milli##BASE_PLURAL, BASE, si_milli) __NL__ \
UNIT_ADD_RELATIVE(centi##BASE, centi##BASE_PLURAL, BASE, si_centi) __NL__ \
UNIT_ADD_RELATIVE(deci##BASE, deci##BASE_PLURAL, BASE, si_deci) __NL__ \
UNIT_ADD_RELATIVE(deca##BASE, deca##BASE_PLURAL, BASE, si_deca) __NL__ \
UNIT_ADD_RELATIVE(hecto##BASE, hecto##BASE_PLURAL, BASE, si_hecto) __NL__ \
UNIT_ADD_RELATIVE(kilo##BASE, kilo##BASE_PLURAL, BASE, si_kilo) __NL__ \
UNIT_ADD_RELATIVE(mega##BASE, mega##BASE_PLURAL, BASE, si_mega) __NL__ \
UNIT_ADD_RELATIVE(giga##BASE, giga##BASE_PLURAL, BASE, si_giga) __NL__ \
UNIT_ADD_RELATIVE(tera##BASE, tera##BASE_PLURAL, BASE, si_tera) __NL__ \
UNIT_ADD_RELATIVE(peta##BASE, peta##BASE_PLURAL, BASE, si_peta) __NL__ \
UNIT_ADD_RELATIVE(exa##BASE, exa##BASE_PLURAL, BASE, si_exa) __NL__ \
UNIT_ADD_RELATIVE(zetta##BASE, zetta##BASE_PLURAL, BASE, si_zetta) __NL__ \
UNIT_ADD_RELATIVE(yotta##BASE, yotta##BASE_PLURAL, BASE, si_yotta) __NL__

#define GENERATE_MEMBER_FUNCTIONS(NAME, NAME_PLURAL, ABBREV) \
inline void set_##NAME_PLURAL(const double& _val) { val = double(_val * _units_private::units_per_##NAME); } __NL__ \
inline double get_##NAME_PLURAL() { return double(val) * _units_private::NAME_PLURAL##_per_unit; } __NL__ \
//inline void set_##ABBREV(const double& _val) { set_##NAME_PLURAL(_val); } __NL__ \
//inline double get_##ABBREV() { return get_##NAME_PLURAL(); } __NL__

#define GENERATE_MEMBER_FUNCTIONS_SIPREFIXES(NAME, NAME_PLURAL, ABBREV) \
GENERATE_MEMBER_FUNCTIONS(yocto##NAME, yocto##NAME_PLURAL, y##ABBREV) __NL__ \
GENERATE_MEMBER_FUNCTIONS(zepto##NAME, zepto##NAME_PLURAL, z##ABBREV) __NL__ \
GENERATE_MEMBER_FUNCTIONS(atto##NAME, atto##NAME_PLURAL, a##ABBREV) __NL__ \
GENERATE_MEMBER_FUNCTIONS(femto##NAME, femto##NAME_PLURAL, f##ABBREV) __NL__ \
GENERATE_MEMBER_FUNCTIONS(pico##NAME, pico##NAME_PLURAL, p##ABBREV) __NL__ \
GENERATE_MEMBER_FUNCTIONS(nano##NAME, nano##NAME_PLURAL, n##ABBREV) __NL__ \
GENERATE_MEMBER_FUNCTIONS(micro##NAME, micro##NAME_PLURAL, u##ABBREV) __NL__ \
GENERATE_MEMBER_FUNCTIONS(milli##NAME, milli##NAME_PLURAL, m##ABBREV) __NL__ \
GENERATE_MEMBER_FUNCTIONS(centi##NAME, centi##NAME_PLURAL, c##ABBREV) __NL__ \
GENERATE_MEMBER_FUNCTIONS(deci##NAME, deci##NAME_PLURAL, d##ABBREV) __NL__ \
GENERATE_MEMBER_FUNCTIONS(deca##NAME, deca##NAME_PLURAL, da##ABBREV) __NL__ \
GENERATE_MEMBER_FUNCTIONS(hecto##NAME, hecto##NAME_PLURAL, h##ABBREV) __NL__ \
GENERATE_MEMBER_FUNCTIONS(kilo##NAME, kilo##NAME_PLURAL, k##ABBREV) __NL__ \
GENERATE_MEMBER_FUNCTIONS(mega##NAME, mega##NAME_PLURAL, M##ABBREV) __NL__ \
GENERATE_MEMBER_FUNCTIONS(giga##NAME, giga##NAME_PLURAL, G##ABBREV) __NL__ \
GENERATE_MEMBER_FUNCTIONS(tera##NAME, tera##NAME_PLURAL, T##ABBREV) __NL__ \
GENERATE_MEMBER_FUNCTIONS(peta##NAME, peta##NAME_PLURAL, P##ABBREV) __NL__ \
GENERATE_MEMBER_FUNCTIONS(exa##NAME, exa##NAME_PLURAL, E##ABBREV) __NL__ \
GENERATE_MEMBER_FUNCTIONS(zetta##NAME, zetta##NAME_PLURAL, Z##ABBREV) __NL__ \
GENERATE_MEMBER_FUNCTIONS(yotta##NAME, yotta##NAME_PLURAL, Y##ABBREV) __NL__

#define GENERATE_LITERALS(CLASSNAME, NAME, NAME_PLURAL, ABBREV) \
//constexpr inline CLASSNAME operator"" _##NAME_PLURAL(long double _val) { return CLASSNAME(double(_val)); } __NL__ \
//constexpr inline CLASSNAME operator"" _##ABBREV(long double _val) { return CLASSNAME(double(_val)); }

#define GENERATE_LITERALS_SIPREFIXES(CLASSNAME, NAME, NAME_PLURAL, ABBREV) \
GENERATE_LITERALS(CLASSNAME, yocto##NAME, yocto##NAME_PLURAL, y##ABBREV) __NL__ \
GENERATE_LITERALS(CLASSNAME, zepto##NAME, zepto##NAME_PLURAL, z##ABBREV) __NL__ \
GENERATE_LITERALS(CLASSNAME, atto##NAME, atto##NAME_PLURAL, a##ABBREV) __NL__ \
GENERATE_LITERALS(CLASSNAME, femto##NAME, femto##NAME_PLURAL, f##ABBREV) __NL__ \
GENERATE_LITERALS(CLASSNAME, pico##NAME, pico##NAME_PLURAL, p##ABBREV) __NL__ \
GENERATE_LITERALS(CLASSNAME, nano##NAME, nano##NAME_PLURAL, n##ABBREV) __NL__ \
GENERATE_LITERALS(CLASSNAME, micro##NAME, micro##NAME_PLURAL, u##ABBREV) __NL__ \
GENERATE_LITERALS(CLASSNAME, milli##NAME, milli##NAME_PLURAL, m##ABBREV) __NL__ \
GENERATE_LITERALS(CLASSNAME, centi##NAME, centi##NAME_PLURAL, c##ABBREV) __NL__ \
GENERATE_LITERALS(CLASSNAME, deci##NAME, deci##NAME_PLURAL, d##ABBREV) __NL__ \
GENERATE_LITERALS(CLASSNAME, deca##NAME, deca##NAME_PLURAL, da##ABBREV) __NL__ \
GENERATE_LITERALS(CLASSNAME, hecto##NAME, hecto##NAME_PLURAL, h##ABBREV) __NL__ \
GENERATE_LITERALS(CLASSNAME, kilo##NAME, kilo##NAME_PLURAL, k##ABBREV) __NL__ \
GENERATE_LITERALS(CLASSNAME, mega##NAME, mega##NAME_PLURAL, M##ABBREV) __NL__ \
GENERATE_LITERALS(CLASSNAME, giga##NAME, giga##NAME_PLURAL, G##ABBREV) __NL__ \
GENERATE_LITERALS(CLASSNAME, tera##NAME, tera##NAME_PLURAL, T##ABBREV) __NL__ \
GENERATE_LITERALS(CLASSNAME, peta##NAME, peta##NAME_PLURAL, P##ABBREV) __NL__ \
GENERATE_LITERALS(CLASSNAME, exa##NAME, exa##NAME_PLURAL, E##ABBREV) __NL__ \
GENERATE_LITERALS(CLASSNAME, zetta##NAME, zetta##NAME_PLURAL, Z##ABBREV) __NL__ \
GENERATE_LITERALS(CLASSNAME, yotta##NAME, yotta##NAME_PLURAL, Y##ABBREV) __NL__