
// #define R_NO_REMAP
#include <R.h>
#include <Rinternals.h>

extern SEXP parse_from_str_ (SEXP str_     , SEXP parse_opts_);
extern SEXP parse_from_file_(SEXP filename_, SEXP parse_opts_);
extern SEXP parse_from_raw_ (SEXP filename_, SEXP parse_opts_);

extern SEXP serialize_to_str_ (SEXP x_,                 SEXP serialize_opts_);
extern SEXP serialize_to_file_(SEXP x_, SEXP filename_, SEXP serialize_opts_);

extern SEXP parse_ndjson_file_as_df_  (SEXP filename_, SEXP nread_, SEXP nskip_, SEXP nprobe_, SEXP parse_opts_);
extern SEXP parse_ndjson_file_as_list_(SEXP filename_, SEXP nread_, SEXP nskip_,               SEXP parse_opts_);

static const R_CallMethodDef CEntries[] = {
  {"serialize_to_str_" , (DL_FUNC) &serialize_to_str_ , 2},
  {"serialize_to_file_", (DL_FUNC) &serialize_to_file_, 3},
  
  {"parse_from_str_"  , (DL_FUNC) &parse_from_str_ , 2},
  {"parse_from_file_" , (DL_FUNC) &parse_from_file_, 2},
  {"parse_from_raw_"  , (DL_FUNC) &parse_from_raw_ , 2},
  
  {"parse_ndjson_file_as_df_"  , (DL_FUNC) &parse_ndjson_file_as_df_  , 5},
  {"parse_ndjson_file_as_list_", (DL_FUNC) &parse_ndjson_file_as_list_, 4},
  
  {NULL , NULL, 0}
};


void R_init_yyjsonr(DllInfo *info) {
  R_registerRoutines(
    info,      // DllInfo
    NULL,      // .C
    CEntries,  // .Call
    NULL,      // Fortran
    NULL       // External
  );
  R_useDynamicSymbols(info, FALSE);
}


