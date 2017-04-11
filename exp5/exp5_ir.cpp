decl IMP_main : () -> int<4>;
decl _ins_omp_parallel_2 : (ref<int<4>,t,f,plain>, ref<array<real<8>,100>,f,f,plain>) -> unit;
decl _ins_omp_parallel_3 : (ref<int<4>,t,f,plain>, ref<array<real<8>,100>,f,f,plain>, ref<int<4>,f,f,plain>, ref<int<4>,f,f,plain>, ref<int<4>,f,f,plain>, ref<int<4>,f,f,plain>) -> unit;
def _ins_omp_parallel_2 = function (v0 : ref<ref<int<4>,t,f,plain>,f,f,plain>, v1 : ref<ref<array<real<8>,100>,f,f,plain>,f,f,plain>) -> unit {
    {
        {
            for( int<4> v2 = 0 .. **v0 : 1) {
                ptr_subscript(ptr_from_array(*v1), v2) = num_cast(num_cast(get_thread_id(0u), type_lit(int<4>)), type_lit(real<8>));
            }
        }
    }
    merge_all();
};
def _ins_omp_parallel_3 = function (v0 : ref<ref<int<4>,t,f,plain>,f,f,plain>, v1 : ref<ref<array<real<8>,100>,f,f,plain>,f,f,plain>, v2 : ref<ref<int<4>,f,f,plain>,f,f,plain>, v3 : ref<ref<int<4>,f,f,plain>,f,f,plain>, v4 : ref<ref<int<4>,f,f,plain>,f,f,plain>, v5 : ref<ref<int<4>,f,f,plain>,f,f,plain>) -> unit {
    {
        {
            for( int<4> v6 = 0 .. **v0 : 1) {
                if(*ptr_subscript(ptr_from_array(*v1), v6)==num_cast(0, type_lit(real<8>))) {
                    atomic_fetch_and_add(*v2, 1);
                } else {
                    if(*ptr_subscript(ptr_from_array(*v1), v6)==num_cast(1, type_lit(real<8>))) {
                        atomic_fetch_and_add(*v3, 1);
                    } else {
                        if(*ptr_subscript(ptr_from_array(*v1), v6)==num_cast(2, type_lit(real<8>))) {
                            atomic_fetch_and_add(*v4, 1);
                        } else {
                            if(*ptr_subscript(ptr_from_array(*v1), v6)==num_cast(3, type_lit(real<8>))) {
                                atomic_fetch_and_add(*v5, 1);
                            }
                        }
                    }
                }
            }
        }
    }
    merge_all();
};
// Inspire Program
int<4> function IMP_main (){
    var ref<int<4>,t,f,plain> v65 = 100;
    var ref<array<real<8>,100>,f,f,plain> v66 = ref_decl(type_lit(ref<array<real<8>,100>,f,f,plain>));
    {
        merge(parallel(job[num_cast(4, type_lit(uint<8>))..num_cast(4, type_lit(uint<8>))] => _ins_omp_parallel_2(v65, v66)));
    }
    var ref<int<4>,f,f,plain> v69 = 0;
    var ref<int<4>,f,f,plain> v70 = 0;
    var ref<int<4>,f,f,plain> v71 = 0;
    var ref<int<4>,f,f,plain> v72 = 0;
    {
        merge(parallel(job[1ul...] => _ins_omp_parallel_3(v65, v66, v69, v70, v71, v72)));
    }
    return 0;
}