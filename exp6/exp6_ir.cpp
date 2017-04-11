decl IMP_main : () -> int<4>;
decl _ins_omp_parallel_1 : (ref<int<4>,f,f,plain>) -> unit;
def _ins_omp_parallel_1 = function (v0 : ref<ref<int<4>,f,f,plain>,f,f,plain>) -> unit {
    {
        for( int<4> v1 = 0 .. 100 : 1) {
            comp_assign_add(*v0, v1);
        }
    }
    merge_all();
};
// Inspire Program
int<4> function IMP_main (){
    var ref<int<4>,f,f,plain> v25 = 4;
    {
        merge(parallel(job[1ul...] => _ins_omp_parallel_1(v25)));
    }
    return 0;
}