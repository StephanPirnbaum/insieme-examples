decl IMP_printf : (ptr<char,t,f>, var_list) -> int<4>;
decl IMP_main : () -> int<4>;
decl _ins_omp_parallel_1 : () -> unit;
def _ins_omp_parallel_1 = function () -> unit {
    {
        IMP_printf(ptr_from_array("Thread: #(%d)"), varlist_pack((num_cast(get_thread_id(0u), type_lit(int<4>)))));
    }
    merge_all();
};
// Inspire Program
int<4> function IMP_main (){
    {
        merge(parallel(job[num_cast(4, type_lit(uint<8>))..num_cast(4, type_lit(uint<8>))] => _ins_omp_parallel_1()));
    }
    return 0;
}