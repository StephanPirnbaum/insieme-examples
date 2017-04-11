decl IMP_printf : (ptr<char,t,f>, var_list) -> int<4>;
decl IMP_main : () -> int<4>;
decl _ins_omp_parallel_1 : () -> unit;
decl IMP_printCritical : (int<4>) -> unit;
def _ins_omp_parallel_1 = function () -> unit {
    {
        IMP_printf(ptr_from_array("Concurrent Printing Thread: #(%d)"), varlist_pack((num_cast(get_thread_id(0u), type_lit(int<4>)))));
        lock_acquire(global_omp_critical_lock_default);
        IMP_printCritical(num_cast(get_thread_id(0u), type_lit(int<4>)));
        lock_release(global_omp_critical_lock_default);
    }
    merge_all();
};
def IMP_printCritical = function (v20 : ref<int<4>,f,f,plain>) -> unit {
    IMP_printf(ptr_from_array("Thread: #(%d)"), varlist_pack((*v20)));
};
// Inspire Program
int<4> function IMP_main (){
    lock_init(global_omp_critical_lock_default);
    {
        merge(parallel(job[1ul...] => _ins_omp_parallel_1()));
    }
    return 0;
}