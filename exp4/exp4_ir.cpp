decl IMP_main : () -> int<4>;
decl _ins_omp_parallel_1 : (ref<int<4>,f,f,plain>) -> unit;
def _ins_omp_parallel_1 = function (v0 : ref<ref<int<4>,f,f,plain>,f,f,plain>) -> unit {
    {
        atomic_fetch_and_add(*v0, 1);
    }
    merge_all();
};
// Inspire Program
int<4> function IMP_main (){
    var ref<int<4>,f,f,plain> v26 = 0;
    {
        merge(parallel(job[1ul...] => _ins_omp_parallel_1(v26)));
    }
    return 0;
}