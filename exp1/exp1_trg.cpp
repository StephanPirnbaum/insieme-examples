/**
 * ------------------------ Auto-generated Code ------------------------ 
 *           This code was generated by the Insieme Compiler 
 * --------------------------------------------------------------------- 
 */
#include <ir_interface.h>
#include <irt_all_impls.h>
#include <standalone.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#ifdef __cplusplus
#define INS_INIT(...) __VA_ARGS__
#else
#define INS_INIT(...) (__VA_ARGS__)
#endif
#ifdef __cplusplus
#include <new>
#define INS_INPLACE_INIT(Loc,Type) new(Loc) Type
#else
#define INS_INPLACE_INIT(Loc,Type) *(Loc) = (Type)
#endif
#ifdef __cplusplus
				/** Workaround for libstdc++/libc bug.
				 *  There's an inconsistency between libstdc++ and libc regarding whether
				 *  ::gets is declared or not, which is only evident when using certain
				 *  compilers and language settings
				 *  (tested positively with clang 3.9 --std=c++14 and libc 2.17).
				 */
				#include <initializer_list>  // force libstdc++ to include its config
				#undef _GLIBCXX_HAVE_GETS    // correct broken config
#endif

/* ------- Program Code --------- */

struct __insieme_type_13;
typedef struct __insieme_type_13 __insieme_type_13;

struct __insieme_type_13 {
    char data[14];;
};

/* ------- Function Definitions --------- */
void _ins_omp_parallel_1() {
    {
        printf("Thread: #(%d)", (int32_t)irt_wi_get_wg_num(irt_wi_get_current(), 0u));
    };
    irt_wi_join_all(irt_wi_get_current());
}
/* ------- Function Definitions --------- */
void insieme_wi_0_var_0_impl(irt_work_item* var_0) {
    _ins_omp_parallel_1();
}
// --- the meta info table --- 
irt_meta_info_table_entry g_insieme_meta_table[] = {
    {{ false, 0, 0 },{ false, 0, -1, -1, 0, -1, -1, 0, -1, -1, 0, -1, -1, (0x7fffffff * 2U + 1U), (0x7fffffff * 2U + 1U) },{ false, false, (0x7fffffff * 2U + 1U), (0x7fffffff * 2U + 1U) },{ false, {0}, {0}, 0, 0, 0 },{ false, "" }}, /* the no-info-entry */

};

struct __insieme_type_15;
typedef struct __insieme_type_15 __insieme_type_15;

struct __insieme_type_15 {
    irt_type_id c0;;
};

extern irt_wi_implementation g_insieme_impl_table[];
/* ------- Function Definitions --------- */
int32_t IMP_main() {
    {
        irt_merge(irt_parallel(&INS_INIT(irt_parallel_job){1ul, 4294967295ul, 1ul, &g_insieme_impl_table[0], (irt_lw_data_item*)(&INS_INIT(__insieme_type_15){1})}));
    };
    return 0;
}
struct __insieme_type_17;
typedef struct __insieme_type_17 __insieme_type_17;

struct __insieme_type_17 {
    irt_type_id c0;
    int32_t* c1;;
};

/* ------- Function Definitions --------- */
void insieme_wi_1_var_0_impl(irt_work_item* var_0) {
    *(*(__insieme_type_17*)(*var_0).parameters).c1 = IMP_main();
}
// --- work item variants ---
irt_wi_implementation_variant g_insieme_wi_0_variants[] = {
    { &insieme_wi_0_var_0_impl, 0, NULL, 0, NULL,  &(g_insieme_meta_table[0]) },
};
irt_wi_implementation_variant g_insieme_wi_1_variants[] = {
    { &insieme_wi_1_var_0_impl, 0, NULL, 0, NULL,  &(g_insieme_meta_table[0]) },
};
// --- the implementation table --- 
irt_wi_implementation g_insieme_impl_table[] = {
    { 1, 1, g_insieme_wi_0_variants },
    { 2, 1, g_insieme_wi_1_variants },
};

struct __insieme_type_19;
typedef struct __insieme_type_19 __insieme_type_19;

struct __insieme_type_19 {
    irt_type_id c0;
    int32_t c1;
    char** c2;
    int32_t* c3;;
};

// --- components for type table entries ---
irt_type_id g_type_1_components[] = {0};
irt_type_id g_type_4_components[] = {3};
irt_type_id g_type_5_components[] = {2};
irt_type_id g_type_6_components[] = {0,2,4,5};

// --- components_offset for type table entries ---
size_t g_type_1_components_offset[] = {offsetof(__insieme_type_15, c0), };
size_t g_type_6_components_offset[] = {offsetof(__insieme_type_19, c0), offsetof(__insieme_type_19, c1), offsetof(__insieme_type_19, c2), offsetof(__insieme_type_19, c3), };

// --- the type table ---
irt_type g_insieme_type_table[] = {
    {IRT_T_UINT32, sizeof(irt_type_id), 0, 0, 0},
    {IRT_T_STRUCT, sizeof(__insieme_type_15), 1, g_type_1_components, g_type_1_components_offset},
    {IRT_T_INT32, sizeof(int32_t), 0, 0, 0},
    {IRT_T_POINTER, sizeof(char*), 0, 0, 0},
    {IRT_T_POINTER, sizeof(char**), 1, g_type_4_components, 0},
    {IRT_T_POINTER, sizeof(int32_t*), 1, g_type_5_components, 0},
    {IRT_T_STRUCT, sizeof(__insieme_type_19), 4, g_type_6_components, g_type_6_components_offset}
};

void insieme_init_context(irt_context* context) {
    context->type_table_size = 7;
    context->type_table = g_insieme_type_table;
    context->impl_table_size = 2;
    context->impl_table = g_insieme_impl_table;
    context->info_table_size = 1;
    context->info_table = g_insieme_meta_table;
    context->num_regions = 1;
}

void insieme_cleanup_context(irt_context* context) {
}

/* ------- Function Definitions --------- */
int32_t main(int32_t var_0, char** var_1) {
    int32_t var_2 = 0;
    irt_runtime_standalone(irt_get_default_worker_count(), &insieme_init_context, &insieme_cleanup_context, &g_insieme_impl_table[1], (irt_lw_data_item*)(&INS_INIT(__insieme_type_19){6, var_0, var_1, &var_2}));
    return var_2;
}


