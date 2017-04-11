decl IMP_printf : (ptr<char,t,f>, var_list) -> int<4>;
decl IMP_main : () -> int<4>;
decl _ins_omp_parallel_1 : () -> unit;
decl fun001 : (int<4>, int<4>, int<4>) -> unit;
decl fun001 : (int<4>, int<4>, int<4>) -> unit;
def _ins_omp_parallel_1 = function () -> unit {
    {
        IMP_printf(ptr_from_array("Thread: #(%d)"), varlist_pack((num_cast(get_thread_id(0u), type_lit(int<4>)))));
        barrier(get_thread_group(0u));
        {
            {
                {
                    pfor(get_thread_group(0u), 0, num_cast(get_thread_id(0u), type_lit(int<4>)), 1, (v0 : int<4>, v1 : int<4>, v2 : int<4>) => fun001(v0, v1, v2));
                    barrier(get_thread_group(0u));
                }
            }
        }
        {
            {
                {
                    pfor(get_thread_group(0u), 0, num_cast(get_thread_id(0u), type_lit(int<4>)), 1, (v3 : int<4>, v4 : int<4>, v5 : int<4>) => fun001(v3, v4, v5));
                }
            }
        }
        IMP_printf(ptr_from_array("Done, Thread: #(%d)"), varlist_pack((num_cast(get_thread_id(0u), type_lit(int<4>)))));
    }
    merge_all();
};
def fun001 = function (v0 : ref<int<4>,f,f,plain>, v1 : ref<int<4>,f,f,plain>, v2 : ref<int<4>,f,f,plain>) -> unit {
    for( int<4> v3 = *v0 .. *v1 : *v2) {
        IMP_printf(ptr_from_array("First Loop, Thread: #(%d), Iteration: #(%d)"), varlist_pack((num_cast(get_thread_id(0u), type_lit(int<4>)), v3)));
    }
};
def fun001 = function (v0 : ref<int<4>,f,f,plain>, v1 : ref<int<4>,f,f,plain>, v2 : ref<int<4>,f,f,plain>) -> unit {
    for( int<4> v3 = *v0 .. *v1 : *v2) {
        IMP_printf(ptr_from_array("Second Loop, Thread: #(%d), Iteration: #(%d)"), varlist_pack((num_cast(get_thread_id(0u), type_lit(int<4>)), v3)));
    }
};
// Inspire Program
int<4> function IMP_main (){
    {
        merge(parallel(job[1ul...] => _ins_omp_parallel_1()));
    }
    return 0;
}