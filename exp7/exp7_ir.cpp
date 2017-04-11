decl IMP_main : () -> int<4>;
decl _ins_omp_parallel_1 : (ref<int<4>,f,f,plain>) -> unit;
def _ins_omp_parallel_1 = function (v0 : ref<ref<int<4>,f,f,plain>,f,f,plain>) -> unit {
    var ref<int<4>,f,f,plain> v1 = 0;
    {
        for( int<4> v2 = 0 .. 100 : 1) {
            comp_assign_add(v1, v2);
        }
    }
    {
        lock_acquire(global_omp_critical_lock_reduce_2);
        {
            *v0 = **v0+*v1;
        }
        lock_release(global_omp_critical_lock_reduce_2);
    }
    merge_all();
};
// Inspire Program
int<4> function IMP_main (){
    lock_init(global_omp_critical_lock_reduce_2);
    var ref<int<4>,f,f,plain> v26 = 4;
    {
        merge(parallel(job[1ul...] => _ins_omp_parallel_1(v26)));
    }
    return 0;
}